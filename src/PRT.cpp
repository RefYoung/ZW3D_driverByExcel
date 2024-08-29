#include "PRT.h"

void PRT::onGetFileFinished()
{
	QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

	if(reply==nullptr)return;

	int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

	if (statusCode != 200)return;

	QPixmap pix;
	pix.loadFromData(reply->readAll());
	ui->tvProjectGit_2->model()->setData(ui->tvProjectGit_2->model()->index(reply->property("row").toInt(), 6), QVariant::fromValue(pix));
}

void PRT::on_tvListProjectGit_doubleClicked(const QModelIndex& index)
{
	int row = index.row();
	QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->tvListProjectGit->model());
	QString realType = model->data(model->index(row, 2)).toString();
	getSearch(realType);
}


PRT::PRT(QString assemblyGraphId, QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::PRTClass())
{
	ui->setupUi(this);

	m_assemblyGraphId = assemblyGraphId;
	
	this->setCentralWidget(ui->splitter_5);

	QStandardItemModel* model = new QStandardItemModel(this);
	model->setColumnCount(3);
	model->setRowCount(3);
	model->setHeaderData(0, Qt::Horizontal, "label");
	model->setHeaderData(1, Qt::Horizontal, "id");
	model->setHeaderData(2, Qt::Horizontal, "realType");

	model->setData(model->index(0, 0), u8"方案零部件");
	model->setData(model->index(0, 1), u8"5");
	model->setData(model->index(0, 2), u8"5");

	model->setData(model->index(1, 0), u8"方案元器件");
	model->setData(model->index(1, 1), u8"7");
	model->setData(model->index(1, 2), u8"7");

	model->setData(model->index(2, 0), u8"方案铜排");
	model->setData(model->index(2, 1), u8"8");
	model->setData(model->index(2, 2), u8"8");

	ui->tvListProjectGit->setModel(model);
	ui->tvListProjectGit->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tvProjectGit_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	ui->splitter_5->setStretchFactor(0, 1);
	ui->splitter_5->setStretchFactor(1, 6);

	m_standardDataModel = new QStandardItemModel(this);
	m_standardDataModel->setColumnCount(10);
	m_standardDataModel->setHeaderData(0, Qt::Horizontal, u8"选中状态");
	m_standardDataModel->setHeaderData(0, Qt::Horizontal, u8"选中状态");
	m_standardDataModel->setHeaderData(1, Qt::Horizontal, u8"物料编号");
	m_standardDataModel->setHeaderData(2, Qt::Horizontal, u8"物料名称");
	m_standardDataModel->setHeaderData(3, Qt::Horizontal, u8"描述");
	m_standardDataModel->setHeaderData(4, Qt::Horizontal, u8"检出人");
	m_standardDataModel->setHeaderData(5, Qt::Horizontal, u8"检出状态");
	m_standardDataModel->setHeaderData(6, Qt::Horizontal, u8"缩略图");

	m_standardDataModel->setHeaderData(7, Qt::Horizontal, "id");
	m_standardDataModel->setHeaderData(8, Qt::Horizontal, "graphTypeId");
	m_standardDataModel->setHeaderData(9, Qt::Horizontal, "isOutputGraph");

	ui->tvProjectGit_2->setEditTriggers(QAbstractItemView::AllEditTriggers);
	ui->tvProjectGit_2->setSelectionMode(QAbstractItemView::NoSelection);
	ui->tvProjectGit_2->setModel(m_standardDataModel);
	ui->tvProjectGit_2->hideColumn(0);
	ui->tvProjectGit_2->hideColumn(7);
	ui->tvProjectGit_2->hideColumn(8);
	ui->tvProjectGit_2->hideColumn(9);
	ui->tvProjectGit_2->setItemDelegateForColumn(0, &m_standardGitTableDelegate);
	ui->tvProjectGit_2->setItemDelegateForColumn(6, &m_standardGitTableDelegateImg);

	ui->tvListProjectGit->doubleClicked(ui->tvListProjectGit->indexAt(QPoint(0,0)));
}

PRT::~PRT()
{
	delete ui;
}

void PRT::getSearch(QString realType)
{
	QNetworkRequest request;
	request.setUrl(QUrl(g_getBaseUrl() + g_prtDetailUrl +"?assemblyGraphId=" + m_assemblyGraphId + "&realType=" + realType + "&pageNum=1&pageSize=1000"));
	request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
	request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
	request.setRawHeader("Authorization", g_userToken.toUtf8());
	QNetworkReply* reply = g_networkManager.get(request);
	reply->setParent(this);
	connect(reply, SIGNAL(finished()), this, SLOT(onGetSerchFinished()));
}

void PRT::getFile(QUrl url, QMap<QString, QString> head, int row)
{
	QNetworkRequest request;
	request.setUrl(url);
	request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
	request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
	for (auto i = head.begin(); i != head.end(); ++i) {
		request.setRawHeader(i.key().toUtf8(), i.value().toUtf8());
	}

	QNetworkReply* reply = g_networkManager.get(request);
	reply->setParent(this);
	reply->setProperty("row", row);
	connect(reply, SIGNAL(finished()), this, SLOT(onGetFileFinished()));
}

void PRT::onGetSerchFinished()
{
	QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

	if (reply == nullptr)return;

	int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

	//cvxMsgDisp(QString::number(statusCode).toLocal8Bit());
	if (statusCode != 200 || reply->error() != QNetworkReply::NoError) {
		QMessageBox::warning(this, u8"警告", u8"获取项目方案装配体零件出错, 错误代码: " + QString::number(reply->error()).toUtf8() + u8"错误原因 : " + reply->errorString().toUtf8());
		return;
	}

	QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
	QJsonObject rootObj = doc.object();
	if (rootObj.value("code").toInt() != 200) {
		QMessageBox::warning(this, u8"警告", u8"获取项目方案装配体零件出错, 错误代码: " + QString::number(rootObj.value("code").toInt()).toUtf8() + u8"错误原因 : " + rootObj.value("msg").toString().toUtf8());
		return;
	}

	QStandardItemModel* _model = static_cast<QStandardItemModel*>(ui->tvProjectGit_2->model());
	_model->removeRows(0, _model->rowCount());

	QJsonObject obj = doc.object();
	int count = -1;
	count = obj.value("total").toInt();
	if (count > 0) {
		QJsonArray array = obj.value("rows").toArray();
		for (int i = 0; i < array.count(); ++i) {
			_model->insertRow(_model->rowCount());
			ui->tvProjectGit_2->setRowHeight(_model->rowCount() - 1, 80);

			QJsonObject rowObj = array.at(i).toObject();
			_model->setData(_model->index(_model->rowCount() - 1, 1), rowObj.value("graphCode"));
			_model->setData(_model->index(_model->rowCount() - 1, 2), rowObj.value("graphName"));
			_model->setData(_model->index(_model->rowCount() - 1, 3), rowObj.value("remark"));
			// _model->setData(_model->index(_model->rowCount()-1,4),rowObj.value("graphCode"));
			if (rowObj.value("checkInOutStatus").toString() == "2") {
				_model->setData(_model->index(_model->rowCount() - 1, 4), rowObj.value("updateBy"));
				_model->setData(_model->index(_model->rowCount() - 1, 5), u8"已检出");

			}
			else if (rowObj.value("checkInOutStatus").toString() == "1") {
				_model->setData(_model->index(_model->rowCount() - 1, 5), u8"已检入");
			}

			_model->setData(_model->index(_model->rowCount() - 1, 7), rowObj.value("id"));
			_model->setData(_model->index(_model->rowCount() - 1, 8), rowObj.value("graphTypeId"));
			_model->setData(_model->index(_model->rowCount() - 1, 9), rowObj.value("isOutputGraph"));


			QMap<QString, QString> head;
			head["Authorization"] = g_userToken;
			//cvxMsgDisp("123:" + rowObj.value("graphPicture").toString().toLocal8Bit());
			getFile(QUrl(rowObj.value("graphJpgFile").toString()), head, _model->rowCount() - 1);


			for (int k = 1; k < 6; ++k) {
				QStandardItem* item = _model->item(_model->rowCount() - 1, k);
				if (item != NULL) {
					item->setTextAlignment(Qt::AlignCenter);
					item->setFlags(item->flags() & ~Qt::ItemIsEditable);

				}
			}

		}
	}

	reply->deleteLater();
	reply = nullptr;
}
