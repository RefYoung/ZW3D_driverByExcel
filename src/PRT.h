#pragma once

#include <QMainWindow>
#include "ui_PRT.h"
#include <qstandarditemmodel.h>
#include "standardgittreeitem.h"
#include <QTemporaryFile>
#include "standardGitTableDelegateImg.h"
#include "standardgittabledelegate.h"
#include <qnetworkrequest.h>
#include <qnetworkaccessmanager.h>
#include <qnetworkreply.h>
#include <qmessagebox.h>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include "global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PRTClass; };
QT_END_NAMESPACE

class PRT : public QMainWindow
{
	Q_OBJECT

private slots:
	//私有槽函数部分
	void onGetSerchFinished();//当获取项目方案装配体零件完成时调用此函数
	void onGetFileFinished();//当get请求获取文件信息完成时调用此槽函数
	void on_tvListProjectGit_doubleClicked(const QModelIndex& index);
	//void on_btnOpenModelPrt_clicked();

public:
	PRT( QString assemblyGraphId, QWidget *parent = nullptr);
	~PRT();

private:
	Ui::PRTClass *ui;

	//私有成员部分
	QStandardItemModel* m_standardDataModel;//标准库管理的数据模型
	standardGitTableDelegate m_standardGitTableDelegate;//标准库管理的代理
	standardGitTableDelegateImg m_standardGitTableDelegateImg;//标准库缩略图代理
	QString m_assemblyGraphId;//
	
	//私有成员函数部分
	void getSearch(QString realType);//获取项目方案装配体零件
	void getFile(QUrl url, QMap<QString, QString> head, int row);
};
