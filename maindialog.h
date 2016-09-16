#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QtCore>


#include <dinput.h>

#include <dinputd.h>

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

    HRESULT InitDirectInput();

    QTimer *pTimer;
    LPDIRECTINPUT8          m_pDI = nullptr;
    LPDIRECTINPUTDEVICE8    m_pJoystick = nullptr;
private slots:
        void timer();
private:
    Ui::MainDialog *ui;
};
struct DI_ENUM_CONTEXT
{
        DIJOYCONFIG* pPreferredJoyCfg;
        bool bPreferredJoyCfgValid;
        MainDialog *m_pDlg;
};
#endif // MAINDIALOG_H
