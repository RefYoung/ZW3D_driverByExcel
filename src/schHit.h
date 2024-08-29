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

	static schHit* m_instance;//单例指针
	int m_schHitFileTotal;//需要下载的文件总数
	int m_schHitFileCount;//方案命中的文件数量

	bool m_schHitFailFlag;//单柜方案命中下载错误标识
	QJsonDocument m_jsonDoc;//用于记录读取的方案命中json文件
	QMap<QNetworkReply*, struct schHitItem> m_schHitMap;//用于方案命中对的图
	QMap<QNetworkReply*, openModelItem> m_omItemsMap;//用于打开模型的零件图
	int m_schHitUpFtpFileTotal;//变形后需要上传到ftp服务器的文件数量
	int m_schHitUpFtoCount;//变形后已经上传到ftp服务器的文件数量

	void schemeHandle();//方案命中处理
	void postUpdatePic();//方案命中图片更新
	void uploadNewJsonFile();//上传新的方案命中json文件

private slots:
	void onGetFtpFileFinished();//方案命中文件下载完成
	void onPostUpdatePicFinished();//方案命中图片更新完成
	void onPostUploadNewJsonFileFinished();//上传新的方案命中json文件完成
	void onPutFtpFileFinished();//上传文件到ftp服务器完成
};
