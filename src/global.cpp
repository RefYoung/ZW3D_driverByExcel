#include "global.h"

//ȫ�ֱ���
QNetworkAccessManager g_networkManager;//ȫ��������ʹ�����
QSettings *g_configSettings;//ȫ�������ļ�
QString g_userToken;//�û�token
QString g_baseUrl;//���������ַ
QString g_loginUrl;//��¼����·��
QString g_getUserInfoUrl;//��ȡ�û���Ϣ����·��
QString g_getProductInfoUrl;//��ȡ��Ʒ��Ϣ����·��
QString g_getModeTreeUrl;//��ȡģ��������·��
QString g_query3DTPGitMapListUrl;//��ѯ3D����ͼ�б�����·��
QString g_projectCheckInUrl;//��Ŀ�������·��
QString g_projectCheckOutUrl;//��Ŀ�������·��
QString g_openModelUrl;//��ģ������·��
QString g_prtDetailUrl;//��ȡװ���������������·��
QString g_engineeringDrawingUrl;//�ϴ�����ͼ����·��
QString g_3DCopperBarScheme;//�ϴ�3Dͭ�ŷ�������·��
QString g_batchUploadThumbnail;//�����ϴ�����ͼ����·��
QString g_generateNewScheme;//�����·�������·��
QString g_currentWorkDir;//��ǰ����Ŀ¼
QString g_configFilePathName;//�����ļ����ƺ�·��
QString g_ftpUserName;//ftp�������˺�
QString g_ftpUserPswd;//ftp����������
QString g_ftpBaseUrl;//ftp��������ַ

//�ֿ�·��
QString g_capGitDirPath;//Ԫ������·��

//�û�����
QString g_materialNo;//���Ϻ�
QString g_graphName;//����
QString g_graphTypeId;//����ͼ����ID
QString g_graphId;//����ͼID
QString g_detector;//�����
QString g_remark;//��ע
QString g_isOutputGraph;//�Ƿ��������ͼ