#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "global.h"
#include <QCloseEvent>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qnetworkreply.h>
#include <qnetworkrequest.h>
#include <QShowEvent>
#include "FunCore.h"
#include <qtimer.h>

namespace Ui {
class LogIn;
}

class LogIn : public QDialog
{
    Q_OBJECT

public:
    
    ~LogIn();

    void setAutoLoginChecked(bool checked);

    static LogIn* getInstance();

signals:
    void postLogInFinished();

private slots:
    void on_editCancel_clicked();

    void on_btnLogIn_clicked();

    void on_editName_textChanged(const QString& arg1);

    void on_editPswd_textChanged(const QString& arg1);

    void on_cheAutoLogin_stateChanged(int arg1);

    void on_cheRemeberPswd_stateChanged(int arg1);

    void onPostLogInFinished();

private:
    //��ֹ�ⲿʵ����
    explicit LogIn(QWidget* parent = nullptr);

    Ui::LogIn *ui;

    //˽�б�������
    static LogIn* m_instance;

    //˽�з�������
    void init();//�����ʼ������,�벻Ҫ�ڴ˷���ǰ�����κ����Զ��巽��
    bool inputOk();//��������Ƿ����,������true,���򷵻�false

protected:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent* event);


};

#endif // LOGIN_H
