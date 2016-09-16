#include "maindialog.h"
#include "ui_maindialog.h"
#include <QMessageBox>

//-----------------------------------------------------------------------------
// Defines, constants, and global variables
//-----------------------------------------------------------------------------
#define SAFE_DELETE(p)  { if(p) { delete (p);     (p)=nullptr; } }
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=nullptr; } }

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(timer()));

    pTimer->start(1000 / 30);
	InitDirectInput();
}

MainDialog::~MainDialog()
{
    delete ui;
}

//-----------------------------------------------------------------------------
// Name: EnumJoysticksCallback()
// Desc: Called once for each enumerated joystick. If we find one, create a
//       device interface on it so we can play with it.
//-----------------------------------------------------------------------------
BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE* pdidInstance,
        VOID* pContext)
{
        auto pEnumContext = reinterpret_cast<DI_ENUM_CONTEXT*>(pContext);
        HRESULT hr;


        // Skip anything other than the perferred joystick device as defined by the control panel.
        // Instead you could store all the enumerated joysticks and let the user pick.
        if (pEnumContext->bPreferredJoyCfgValid &&
                !IsEqualGUID(pdidInstance->guidInstance, pEnumContext->pPreferredJoyCfg->guidInstance))
                return DIENUM_CONTINUE;

        // Obtain an interface to the enumerated joystick.
        hr = pEnumContext->m_pDlg->m_pDI->CreateDevice(pdidInstance->guidInstance, &pEnumContext->m_pDlg->m_pJoystick, nullptr);

        // If it failed, then we can't use this joystick. (Maybe the user unplugged
        // it while we were in the middle of enumerating it.)
        if (FAILED(hr))
                return DIENUM_CONTINUE;

        // Stop enumeration. Note: we're just taking the first joystick we get. You
        // could store all the enumerated joysticks and let the user pick.
        return DIENUM_STOP;
}

//-----------------------------------------------------------------------------
// Name: EnumObjectsCallback()
// Desc: Callback function for enumerating objects (axes, buttons, POVs) on a
//       joystick. This function enables user interface elements for objects
//       that are found to exist, and scales axes min/max values.
//-----------------------------------------------------------------------------
BOOL CALLBACK EnumObjectsCallback(const DIDEVICEOBJECTINSTANCE* pdidoi,
        VOID* pContext)
{
        MainDialog*pDlg = (MainDialog*)pContext;

                                                                  // For axes that are returned, set the DIPROP_RANGE property for the
                                                                  // enumerated axis in order to scale min/max values.
                                                                  // we use a value from -1000 to 1000 for the 4 main axis only

        if (pdidoi->dwType & DIDFT_AXIS
                && (pdidoi->guidType == GUID_XAxis || pdidoi->guidType == GUID_YAxis || pdidoi->guidType == GUID_ZAxis || pdidoi->guidType == GUID_RzAxis)
                )
        {
                DIPROPRANGE diprg;
                diprg.diph.dwSize = sizeof(DIPROPRANGE);
                diprg.diph.dwHeaderSize = sizeof(DIPROPHEADER);
                diprg.diph.dwHow = DIPH_BYID;
                diprg.diph.dwObj = pdidoi->dwType; // Specify the enumerated axis

                diprg.lMin = -32768;   // Codage 16bits
                diprg.lMax = +32768;


                // Set the range for the axis
                if (FAILED(pDlg->m_pJoystick->SetProperty(DIPROP_RANGE, &diprg.diph)))
                        return DIENUM_STOP;

        }

        return DIENUM_CONTINUE;
}


//-----------------------------------------------------------------------------
// Name: InitDirectInput()
// Desc: Initialize the DirectInput variables.
//-----------------------------------------------------------------------------
HRESULT MainDialog::InitDirectInput()
{
        HRESULT hr;

        // Register with the DirectInput subsystem and get a pointer
        // to a IDirectInput interface we can use.
        // Create a DInput object
        if (FAILED(hr = DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION,
                IID_IDirectInput8, (VOID**)&m_pDI, nullptr)))
                return hr;


        DIJOYCONFIG PreferredJoyCfg = { 0 };
        DI_ENUM_CONTEXT enumContext;
        enumContext.pPreferredJoyCfg = &PreferredJoyCfg;
        enumContext.bPreferredJoyCfgValid = false;
        enumContext.m_pDlg = this;

        IDirectInputJoyConfig8* pJoyConfig = nullptr;
        if (FAILED(hr = m_pDI->QueryInterface(IID_IDirectInputJoyConfig8, (void**)&pJoyConfig)))
                return hr;

        PreferredJoyCfg.dwSize = sizeof(PreferredJoyCfg);
        if (SUCCEEDED(pJoyConfig->GetConfig(0, &PreferredJoyCfg, DIJC_GUIDINSTANCE))) // This function is expected to fail if no joystick is attached
                enumContext.bPreferredJoyCfgValid = true;
        SAFE_RELEASE(pJoyConfig);

        // Look for a simple joystick we can use for this sample program.
        if (FAILED(hr = m_pDI->EnumDevices(DI8DEVCLASS_GAMECTRL,
                EnumJoysticksCallback,
                &enumContext, DIEDFL_ATTACHEDONLY)))
                return hr;


        // Make sure we got a joystick
        if (!m_pJoystick)
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::information(this, "Error", "Joystick not found. The sample will now exit.",
                    QMessageBox::Ok);
            return -1;
        }

        // Set the data format to "simple joystick" - a predefined data format
        //
        // A data format specifies which controls on a device we are interested in,
        // and how they should be reported. This tells DInput that we will be
        // passing a DIJOYSTATE2 structure to IDirectInputDevice::GetDeviceState().
        if (FAILED(hr = m_pJoystick->SetDataFormat(&c_dfDIJoystick2)))
                return hr;

        // Set the cooperative level to let DInput know how this device should
        // interact with the system and with other DInput applications.
        if (FAILED(hr = m_pJoystick->SetCooperativeLevel((HWND)this->winId(), DISCL_EXCLUSIVE |
                DISCL_FOREGROUND)))
                return hr;
        // Enumerate the joystick objects. The callback function enabled user
        // interface elements for objects that are found, and sets the min/max
        // values property for discovered axes.
        if (FAILED(hr = m_pJoystick->EnumObjects(EnumObjectsCallback,
                (VOID*)this, DIDFT_ALL)))
                return hr;


        return S_OK;
}

void MainDialog::timer()
{
	HRESULT hr;
	DIJOYSTATE2 js;           // DInput joystick state 

	if (!m_pJoystick)
		return;

	// Poll the device to read the current state
	hr = m_pJoystick->Poll();


	if (FAILED(hr))
	{
		// DInput is telling us that the input stream has been
		// interrupted. We aren't tracking any state between polls, so
		// we don't have any special reset that needs to be done. We
		// just re-acquire and try again.
		hr = m_pJoystick->Acquire();
		while (hr == DIERR_INPUTLOST)
			hr = m_pJoystick->Acquire();

		// hr may be DIERR_OTHERAPPHASPRIO or other errors.  This
		// may occur when the app is minimized or in the process of 
		// switching, so just try again later 
		return;
	}


	// Get the input's device state
	if (FAILED(hr = m_pJoystick->GetDeviceState(sizeof(DIJOYSTATE2), &js)))
		return; // The device should have been acquired during the Poll()

    // Display joystick state to dialog
	ui->Roll->setText(QString::asprintf("%ld", js.lX));
	ui->Pitch->setText(QString::asprintf("%ld", (js.lY*(-1))));
	ui->UpDown->setText(QString::asprintf("%ld", js.lZ));
	ui->Yaw->setText(QString::asprintf("%ld", js.lRz));

	switch ((js.lRx + 1) >> 12)
	{
	case 1:
		ui->Status->setText("Status : Don't put your Feet !!! Stay still 5s");
		break;
	case 2:
		ui->Status->setText("Status : Initialisation");
		break;
	case 3:
		ui->Status->setText("Status : Please put your feet");
		break;
	case 4:
		ui->Status->setText("Status :  Put your second foot");
		break;
	case 5:
		ui->Status->setText("Status : Stay still");
		break;
	case 6:
		ui->Status->setText("Status : 3DRudder in use");
		break;
	case 7:
		ui->Status->setText("Status : Extended functions activated");
		break;
	}

	ui->Sensor1->setText(QString::asprintf("%ld", js.lRy & 0xFF));
	ui->Sensor2->setText(QString::asprintf("%ld", (js.lRy >> 8) & 0xFF));
	ui->Sensor3->setText(QString::asprintf("%ld", js.rglSlider[1] & 0xFF));
	ui->Sensor4->setText(QString::asprintf("%ld", (js.rglSlider[1] >> 8) & 0xFF));
	ui->Sensor5->setText(QString::asprintf("%ld", js.rglSlider[0] & 0xFF));
	ui->Sensor6->setText(QString::asprintf("%ld", (js.rglSlider[0] >> 8) & 0xFF));


}
