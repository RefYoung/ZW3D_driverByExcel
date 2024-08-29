#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include <qscreen.h>
#include <QGuiApplication>
#include <VxApi.h>
#include <QStandardItemModel>
#include <QShowEvent>
#include <qnetworkreply.h>
#include <qnetworkrequest.h>
#include "global.h"
#include <qcombobox.h>
#include <QHttpMultiPart>
#include <QCloseEvent>

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    static edit* getInstance();//��ȡ����
    ~edit();

private:
    //��ֹ�ⲿʵ����
    explicit edit(QWidget* parent = nullptr);

    Ui::edit *ui;

    //˽�г�Ա����
    static edit* m_instance;//����ָ��
    QStandardItemModel* m_editTreeModel;//�༭��������ṹģ��
    QStandardItemModel* m_editDataModel;//�༭���������ģ��
    StandardGitTreeItem* rootItem;//���ṹ���ڵ�
    int m_2Dtotal;//�ϴ��Ķ�άͼ������
    int m_2Dcount;//�ϴ��Ķ�άͼ����

    //˽�з���
    void getModelTreeRequest();//��ȡģ��������,��׼��
    void getModelTreeRequestCap();//��ȡģ��������,Ԫ������
    void makeStandardGitTree(StandardGitTreeItem* root, QJsonObject jObj);//��json����ת��Ϊ���ṹ
    void assignForItemByJobject(StandardGitTreeItem* item, QJsonObject jObject);//��json����ֵ�����ڵ�
    StandardGitTreeItem* findItemInEditTreeView(StandardGitTreeItem* rootItem, QString targetId);//�ڱ༭��������ṹ�в���ָ��id�Ľڵ�
    void makeCapGitTree(StandardGitTreeItem* root, QJsonArray arr);//����capgit��
    void postCheckIn(QUrl url, QMap<QString, QString> head, QString graphTypeId, QString materialNo, char* filePath, QString desc, QString graphName);//�ύ�������
    void postCheckOut(QUrl url, QMap<QString, QString> head, QString graphId, QString graphTypeId);//���

private slots:

    void on_btnCheckInEdit_clicked();

    void on_btnCheckOutEdit_clicked();

    void on_btnUpdateEdit_clicked();

    void on_btnSaveEdit_clicked();//���༭����ı��水ť����ʱ���ô˲ۺ���

    void on_btnGenDwg_clicked();

    void onGetModelTreeFinished();//��ȡģ�����������ʱ���ô˲ۺ���,��׼��

    void onGetModelTreeFinishedCap();//��ȡģ�����������ʱ���ô˲ۺ���,Ԫ������

    void on_combGitChoiceEdit_currentIndexChanged(int index);

    void onPostCheckInFinished();//�ύ����������ʱ���ô˲ۺ���

    void onPostCheckOutFinished();

    void onPutFtpFileFinished();

    void onPostUpload2DPicFinished();//�ϴ���άͼ���ʱ���ô˲ۺ���

protected:
    void showEvent(QShowEvent* event);
    void closeEvent(QCloseEvent* event);
};

#endif // EDIT_H
