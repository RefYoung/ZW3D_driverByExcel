#ifndef STDGIT_H
#define STDGIT_H

#include <QDialog>
#include <QShowEvent>
#include <qstandarditemmodel.h>
#include "standardgittabledelegate.h"
#include "standardgittabledelegateimg.h"
#include <QGuiApplication>
#include <QScreen>
#include <qnetworkrequest.h>
#include <qnetworkreply.h>
#include "global.h"
#include "standardgittreeitem.h"
#include <qjsonarray.h>
#include <QShowEvent>
#include <qmap.h>
#include <QCloseEvent>
#include <QMessageBox>

namespace Ui {
class stdGit;
}

class stdGit : public QDialog
{
    Q_OBJECT

public:
    ~stdGit();

    //���г�Ա����
    static stdGit* getInstance();

private:
    //��ֹ���ⲿʵ����
    explicit stdGit(QWidget* parent = nullptr);

    Ui::stdGit *ui;

    //����ָ��
    static stdGit* m_instance;

    //˽�г�Ա����
    QStandardItemModel* m_standardTreeModel;//��׼���������ṹģ��
    QStandardItemModel* m_standardDataModel;//��׼����������ģ��
    standardGitTableDelegate m_standardGitTableDelegate;//��׼�����Ĵ���
    standardGitTableDelegateImg m_standardGitTableDelegateImg;//��׼������ͼ����
    StandardGitTreeItem* rootItem;//���ڵ�
    StandardGitTreeItem* m_currentTreeItem;//��ǰ��������˫���Ľڵ�
    int m_openModelTotal;//��ģ����Ҫ���ص��������
    int m_openModelCount;//��ģ���Ѿ����ص��������
    QStringList m_openModelFileNames;//��ģ�͵������
    QMap<QNetworkReply*,struct openModelItem> m_omItemsMap;//���ڴ�ģ�͵����ͼ
    QString m_detector;//���һ������ļ��ļ��������

    //˽�з�������
    void getModelTreeRequest();//��ȡģ��������
    void makeStandardGitTree(StandardGitTreeItem* root, QJsonObject jObj);//������׼����
    void assignForItemByJobject(StandardGitTreeItem* item, QJsonObject jObject);//����json����Ϊitem��ֵ
    void getQuery3DTPGitMapList();//��ѯ3Dͭ���б�
    void getFile(QUrl url, int row);//��ȡ�ļ�
    void getOpenModel(QUrl url);//��ģ��
    void getOpenModeFile(QUrl u, QJsonObject obj);//��ȡ��ģ���ļ�
    void postCheckOut(QUrl url);//������

protected:
    void showEvent(QShowEvent* event);
    void closeEvent(QCloseEvent* event);
private slots:
    void on_btnOpenModel_clicked();


    void onGetModelTreeFinished();
    void on_treeViewStandardGit_doubleClicked(const QModelIndex &index);
    void onGetQuery3DTPGitMaplistFinished();
    void onGetFileFinished();
    void onGetOpenModelFinshed();
    void onGetOpenModelFileFinished();
    void onPostCheckOutFinished();
    
};

#endif // STDGIT_H
