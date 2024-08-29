#pragma once

#include <QObject>
#include "global.h"
#include <qmessagebox.h>

class schHit  : public QObject
{
	Q_OBJECT

public:
	static schHit* getInstance();
	void funSchit();
	~schHit();

private:
	schHit(QObject* parent=nullptr);

	static schHit* m_instance;//����ָ��
	int m_schHitFileTotal;//��Ҫ���ص��ļ�����
	int m_schHitFileCount;//�������е��ļ�����

	bool m_schHitFailFlag;//���񷽰��������ش����ʶ
	QJsonDocument m_jsonDoc;//���ڼ�¼��ȡ�ķ�������json�ļ�
	QMap<QNetworkReply*, struct schHitItem> m_schHitMap;//���ڷ������жԵ�ͼ
	QMap<QNetworkReply*, openModelItem> m_omItemsMap;//���ڴ�ģ�͵����ͼ
	int m_schHitUpFtpFileTotal;//���κ���Ҫ�ϴ���ftp���������ļ�����
	int m_schHitUpFtoCount;//���κ��Ѿ��ϴ���ftp���������ļ�����

	void schemeHandle();//�������д���
	void postUpdatePic();//��������ͼƬ����
	void uploadNewJsonFile();//�ϴ��µķ�������json�ļ�

private slots:
	void onGetFtpFileFinished();//���������ļ��������
	void onPostUpdatePicFinished();//��������ͼƬ�������
	void onPostUploadNewJsonFileFinished();//�ϴ��µķ�������json�ļ����
	void onPutFtpFileFinished();//�ϴ��ļ���ftp���������
};
