#pragma once
#include "global.h"
#include <qinputdialog.h>
#include "login.h"
#include "stdgit.h"
#include <QObject>
#include "capGit.h"
#include "proGit.h"
#include "edit.h"
#include <QApplication>
#include <qdesktopwidget.h>
#include "schHit.h"
#include <VxApi.h>
#include <QtXlsx>
#include <QFileDialog>
#include "exceltoprt.h"
#include <qdir.h>

//ȫ�ֺ�������
//���ע��
extern void showLoginForm();//��ʾ��¼����	
extern void exitLogIn();//�˳���¼
extern void changeBaseUrl();//�޸Ļ���url
extern void openStdGit();//�򿪱�׼git
extern void openCapGit();//��Ԫ������
extern void openProGit();//����Ŀ��
extern void openEditUI();//�򿪱༭����
extern void schemeHit();//���������¼�
extern void initPRTUserData();//��ʼ���û�����
extern void genPrtByExcel();//����prt�ļ�
extern void batchInsertion();//��������

//�����ڲ��߼�
extern void initConfig();//��ʼ������
extern void releasePlugin();//�ͷŲ����Դ
extern QString g_getToken();//��ȡtoken
extern QString g_getBaseUrl();//��ȡ����url
