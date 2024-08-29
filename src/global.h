#ifndef GLOBAL_H
#define GLOBAL_H

#include <qstring.h>
#include <qnetworkreply.h>
#include <qfile.h>
#include <qnetworkaccessmanager.h>
#include <qsettings.h>
#include <qmessagebox.h>
#include <qfileinfo.h>
#include <qdir.h>
#include <VxApi.h>
#include <Zwsdk.h>
#include <ZwSdkBase.h>
#include <ZwSdkDatabase.h>
#include <ZwSdkDisplay.h>
#include "login.h"
#include <qsettings.h>


//ȫ�ֱ�������
extern QNetworkAccessManager g_networkManager;//ȫ��������ʹ�����
extern QSettings *g_configSettings;//ȫ�������ļ�
extern QString g_userToken;//�û�token
extern QString g_loginUrl;//��¼����·��
extern QString g_getUserInfoUrl;//��ȡ�û���Ϣ����·��
extern QString g_getProductInfoUrl;//��ȡ��Ʒ��Ϣ����·��
extern QString g_getModeTreeUrl;//��ȡģ��������·��
extern QString g_query3DTPGitMapListUrl;//��ѯ3D����ͼ�б�����·��
extern QString g_projectCheckInUrl;//��Ŀ�������·��
extern QString g_projectCheckOutUrl;//��Ŀ�������·��
extern QString g_openModelUrl;//��ģ������·��
extern QString g_prtDetailUrl;//��ȡװ���������������·��
extern QString g_engineeringDrawingUrl;//�ϴ�����ͼ����·��
extern QString g_3DCopperBarScheme;//�ϴ�3Dͭ�ŷ�������·��
extern QString g_batchUploadThumbnail;//�����ϴ�����ͼ����·��
extern QString g_generateNewScheme;//�����·�������·��
extern QString g_currentWorkDir;//��ǰ����Ŀ¼,���2D����Ŀ¼������,��ʹ��Ĭ�Ϲ���Ŀ¼:C:\Users\(����û���)\AppData\Roaming\ZWSOFT\ZW3D\ZW3D
extern QString g_configFilePathName;//�����ļ����ƺ�·��,��ǰ����Ŀ¼�µ�g_configFileName�ļ�
extern QString g_ftpUserName;//ftp�������˺�
extern QString g_ftpUserPswd;//ftp����������
extern QString g_ftpBaseUrl;//ftp��������ַ

//�ֿ�·��
extern QString g_capGitDirPath;//Ԫ������·��

//�û���������
extern QString g_materialNo;//���Ϻ�
extern QString g_graphName;//����
extern QString g_graphTypeId;//����ͼ����ID
extern QString g_graphId;//����ͼID
extern QString g_detector;//�����
extern QString g_remark;//��ע
extern QString g_isOutputGraph;//�Ƿ��������ͼ

//ȫ�ֳ�������
#define g_configFileName "config.ini"   //���������ļ���
//#define g_workDirRegitPath "HKEY_LOCAL_MACHINE\\SOFTWARE\\ZWSOFT\\ZWCAD\\2022\\zh-CN\\Applications\\CKOptional" //2D����ע���λ��,��ʽ����
#define g_workDirRegitPath "HKEY_LOCAL_MACHINE\\SOFTWARE\\ZWSOFT\\ZWCAD\\2022\\zh-CN\\Applications\\CKOptionalTestEnvironment" //2D����ע���λ��,���Ի���
#define g_chemeHitJsonFileName "3DJSON.json"	//�������е�json�ļ���,��Ҫ��Ϲ���Ŀ¼һ��ʹ��
#define g_projectDirName u8"ͭ����άģ��"	//�������е���Ŀ���ļ�������
#define g_newGenJsonFileName "newGen3DJSON.json"	//�����ɵķ���json�ļ���
#define g_genPrtByExcelFileDir u8"�����ļ�"	//����excel����װ������ļ�������

//ȫ�ֽṹ�岿��
struct schHitItem {//���ڷ������еĴ�����ṹ��
	QString valDes;//���ι���
	QString graphFile;//�ļ����ص�ַ
	QFile* file;//���ص��ļ�
	bool variantStatus;//�Ƿ���Ҫ����
	QString projectName;//��Ŀ��
	QString cabinetName;//������
	QString fileName;//�ļ���
	QString fileUniqueIdentify;//Ψһ��ʶ��
	QFile* pic;//����ͼ
	QString picPath;//ͼƬurl
	QString fileUrl;//�ϴ��ļ�����µ�url
};

struct openModelItem {//���ڴ�ģ�͵�����ṹ��
	QString fileName;//�ļ���,�������ļ�·��
	QString graphId;//���id
	QString graphTypeId;//�������ͼid
	QString graphName;//�������
	QString materialNo;//������Ϻ�
	QString detector;//���������
	QString remark;//�������
	QString isOutPutGraph;//�Ƿ������άͼ
};


#endif // GLOBAL_H