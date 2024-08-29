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
	//˽�вۺ�������
	void onGetSerchFinished();//����ȡ��Ŀ����װ����������ʱ���ô˺���
	void onGetFileFinished();//��get�����ȡ�ļ���Ϣ���ʱ���ô˲ۺ���
	void on_tvListProjectGit_doubleClicked(const QModelIndex& index);
	//void on_btnOpenModelPrt_clicked();

public:
	PRT( QString assemblyGraphId, QWidget *parent = nullptr);
	~PRT();

private:
	Ui::PRTClass *ui;

	//˽�г�Ա����
	QStandardItemModel* m_standardDataModel;//��׼����������ģ��
	standardGitTableDelegate m_standardGitTableDelegate;//��׼�����Ĵ���
	standardGitTableDelegateImg m_standardGitTableDelegateImg;//��׼������ͼ����
	QString m_assemblyGraphId;//
	
	//˽�г�Ա��������
	void getSearch(QString realType);//��ȡ��Ŀ����װ�������
	void getFile(QUrl url, QMap<QString, QString> head, int row);
};
