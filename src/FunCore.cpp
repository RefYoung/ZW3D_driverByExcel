#include "FunCore.h"

//加载全局配置
void initConfig()
{
	//清除全局变量
	g_currentWorkDir.clear();//当前工作目录

	//从注册表获取工作目录
	QSettings settings(g_workDirRegitPath, QSettings::NativeFormat);
	settings.setIniCodec("UTF-8");
	QFile file(QFileInfo(settings.value("LOADER").toString()).canonicalPath() + "/info.ini");
	if (file.exists()) {
		QTextStream stream(&file);
		file.open(QIODevice::ReadOnly);
		for (; !stream.atEnd();) {
			QString arr = stream.readLine();
			if (arr.startsWith("BOMFILEPATH")) {
				QStringList list = arr.split('=', QString::SkipEmptyParts);
				if (list.count() < 2)continue;
				g_currentWorkDir = list.at(1);
				break;
			}
		}
		file.close();
	}

	//设置默认工作目录
	if (g_currentWorkDir.isEmpty())g_currentWorkDir = QDir::currentPath();

	//判断2D插件工作目录是否存在
	if (!g_currentWorkDir.isEmpty() && QDir(g_currentWorkDir).exists()) {
		g_configFilePathName = g_currentWorkDir + "/" + g_configFileName;
	}
	else {
		g_configFilePathName = g_configFileName;
		QMessageBox::warning(0, u8"铜排插件警告", u8"无法同步2D插件工作目录,插件初始化失败.");
		//创建一个全局示例,防止程序崩溃
		g_configSettings = new QSettings("", QSettings::IniFormat, &g_networkManager);
		g_configSettings->setIniCodec("UTF-8");
		return;
	}

	//加载配置文件
	g_configSettings = new QSettings(g_configFilePathName, QSettings::IniFormat, &g_networkManager);
	g_configSettings->setIniCodec("UTF-8");

	//判断配置文件是否存在
	file.setFileName(g_configFilePathName);
	if (!file.exists()) {
		cvxMsgDisp2(QString::fromUtf8(u8"[TGP]配置文件不存在,插件初始化失败,路径:" + QFileInfo(file).absoluteFilePath().toUtf8()).toLocal8Bit(), 4);
		QMessageBox::warning(0, u8"铜排插件警告", u8"配置文件不存在,路径:" + QFileInfo(file).absoluteFilePath());
		return;
	}

	cvxMsgDisp2(QString::fromUtf8(u8"[TGP]配置文件路径:" + g_configSettings->fileName().toUtf8()).toLocal8Bit(), 1);

	//初始化配置信息
	g_loginUrl = g_configSettings->value("url/login").toString();
	g_userToken = g_configSettings->value("user/token").toString();
	g_getUserInfoUrl = g_configSettings->value("url/getUserInfo").toString();
	g_getProductInfoUrl = g_configSettings->value("url/getProductInfo").toString();
	g_getModeTreeUrl = g_configSettings->value("url/getModeTree").toString();
	g_query3DTPGitMapListUrl = g_configSettings->value("url/Query3DTPGitMapList").toString();
	g_projectCheckInUrl = g_configSettings->value("url/projectCheckIn").toString();
	g_projectCheckOutUrl = g_configSettings->value("url/projectCheckOut").toString();
	g_openModelUrl = g_configSettings->value("url/openModel").toString();
	g_prtDetailUrl = g_configSettings->value("url/prtDetail").toString();
	g_engineeringDrawingUrl = g_configSettings->value("url/engineeringDrawing").toString();
	g_3DCopperBarScheme = g_configSettings->value("url/3DCopperBarScheme").toString();
	g_ftpUserName = g_configSettings->value("user/ftpUserName").toString();
	g_ftpUserPswd = g_configSettings->value("user/ftpUserPswd").toString();
	g_ftpBaseUrl = g_configSettings->value("url/ftpUrl").toString();
	g_batchUploadThumbnail = g_configSettings->value("url/batchUploadThumbnail").toString();
	g_generateNewScheme = g_configSettings->value("url/generateNewScheme").toString();

	//初始化仓库路径
	g_capGitDirPath = g_currentWorkDir + "/" + g_projectDirName + u8"/标准件库/元器件库/中压配电产品";

	//初始化用户属性名称
	g_materialNo = QString::fromUtf8(u8"物料号");
	g_graphName = QString::fromUtf8(u8"名称");
	g_graphTypeId = QString::fromUtf8(u8"方案图类型ID");
	g_graphId = QString::fromUtf8(u8"方案图ID");
	g_detector = QString::fromUtf8(u8"检出人");
	g_remark = QString::fromUtf8(u8"备注");
	g_isOutputGraph = QString::fromUtf8(u8"是否输出工程图");

	cvxMsgDisp2("[TGP]TGoodPluginInit!", 1);
}

void showLoginForm()
{
	LogIn::getInstance()->show();
}

void exitLogIn()
{
	//更新token
	g_userToken = "";

	//更新到文件
	g_configSettings->setValue("user/pswd", "");
	g_configSettings->setValue("user/token", "");
	g_configSettings->setValue("logInConfig/autoLogInChecked", 0);
	g_configSettings->setValue("logInConfig/remeberPswd", 0);
	QMessageBox::information(0, u8"铜排插件提示", u8"退出登录成功!");
	cvxMsgDisp2("[TGP]退出登录.", 1);
}

void changeBaseUrl()
{
	bool ok = false;
	QString baseUrl = QInputDialog::getText(0, u8"铜排插件", u8"请输入新的服务器地址:", QLineEdit::Normal, g_getBaseUrl(), &ok);
	if (ok) {
		g_configSettings->setValue("url/baseUrl", baseUrl);
	}
}

void openStdGit()
{
	stdGit::getInstance()->show();
}

void openCapGit()
{
	capGit::getInstance()->show();
}

void openProGit()
{
	proGit::getInstance()->show();
}

void openEditUI()
{
	edit::getInstance()->show();
}

void schemeHit()
{
	delete schHit::getInstance();
	schHit::getInstance()->funSchit();
}

void initPRTUserData()
{
	//为零件写入用户信息
	int AttCnt = 0;
	svxAttribute* UserAt = NULL;
	cvxPartUserAtGet(nullptr, nullptr, &AttCnt, &UserAt);
	QString _desc;
	bool flag = false;
	bool flag2 = false;
	bool flag3 = false;
	bool flag4 = false;
	bool flag5 = false;
	bool flag6 = false;
	bool flag7 = false;//internationalName

	for (int i = 0; i < AttCnt; ++i) {

		if (QString::fromLocal8Bit(UserAt[i].label) == g_graphTypeId)flag = true;
		else if (QString::fromLocal8Bit(UserAt[i].label) == g_detector)flag2 = true;
		else if (QString::fromLocal8Bit(UserAt[i].label) == g_graphId) flag3 = true;
		else if (QString::fromLocal8Bit(UserAt[i].label) == g_materialNo) flag4 = true;
		else if (QString::fromLocal8Bit(UserAt[i].label) == g_graphName) flag5 = true;
		else if (QString::fromLocal8Bit(UserAt[i].label) == g_remark) flag6 = true;
		else if (QString::fromLocal8Bit(UserAt[i].label) == g_isOutputGraph) flag7 = true;
	}

	if (flag == false) {

		svxAttribute userAttrs[1] = { 0 };
		strcpy_s(userAttrs[0].label, g_graphTypeId.toLocal8Bit());
		userAttrs[0].type = VX_ATTR_STRING;
		cvxPartUserAtSet(0, 0, false, 1, userAttrs);
		//cvxFileSave3(0, 1, 0);
	}

	//��������û��detector����,������detector����
	if (flag2 == false) {

		svxAttribute userAttrs[1] = { 0 };
		strcpy_s(userAttrs[0].label, g_detector.toLocal8Bit());
		userAttrs[0].type = VX_ATTR_STRING;
		cvxPartUserAtSet(0, 0, false, 1, userAttrs);
		//cvxFileSave3(0, 1, 0);
	}

	//��������û��graphId����,������graphId����
	if (flag3 == false) {

		svxAttribute userAttrs[1] = { 0 };
		strcpy_s(userAttrs[0].label, g_graphId.toLocal8Bit());
		userAttrs[0].type = VX_ATTR_STRING;
		cvxPartUserAtSet(0, 0, false, 1, userAttrs);
		//cvxFileSave3(0, 1, 0);
	}

	//��������û��materialNo����,������materialNo����
	if (flag4 == false) {

		svxAttribute userAttrs[1] = { 0 };
		strcpy_s(userAttrs[0].label, g_materialNo.toLocal8Bit());
		userAttrs[0].type = VX_ATTR_STRING;
		cvxPartUserAtSet(0, 0, false, 1, userAttrs);
		//cvxFileSave3(0, 1, 0);
	}

	//��������û��graphName����,������graphName����
	if (flag5 == false) {

		svxAttribute userAttrs[1] = { 0 };
		strcpy_s(userAttrs[0].label, g_graphName.toLocal8Bit());
		userAttrs[0].type = VX_ATTR_STRING;
		cvxPartUserAtSet(0, 0, false, 1, userAttrs);
		//cvxFileSave3(0, 1, 0);
	}

	//��������û��remark����,������remark����
	if (flag6 == false) {

		svxAttribute userAttrs[1] = { 0 };
		strcpy_s(userAttrs[0].label, g_remark.toLocal8Bit());
		userAttrs[0].type = VX_ATTR_STRING;
		cvxPartUserAtSet(0, 0, false, 1, userAttrs);
		//cvxFileSave3(0, 1, 0);
	}

	//��������û��isOutputGraph����,������isOutputGraph����
	if (flag7 == false) {

		svxAttribute userAttrs[1] = { 0 };
		strcpy_s(userAttrs[0].label, g_isOutputGraph.toLocal8Bit());
		userAttrs[0].type = VX_ATTR_STRING;
		cvxPartUserAtSet(0, 0, false, 1, userAttrs);
		//cvxFileSave3(0, 1, 0);
	}

	QMessageBox::information(0, u8"提示", u8"已初始化当前零件用户属性.");
}

void genPrtByExcel()
{
	//excelToPrt::getInstance()->show();
	if (g_currentWorkDir.isEmpty()) {
		QMessageBox::warning(0, u8"警告", u8"无法同步工作目录.");
		return;
	}
	cvxSessionClear();
	QString excelPath = QFileDialog::getOpenFileName(nullptr, u8"选择文件", g_currentWorkDir +"/"+ g_projectDirName, u8"Excel Files(*.xlsx *.xls);;all(*.*)");

	if(excelPath.isEmpty())return;

	excelPath.replace("/", "\\");
	QXlsx::Document m_doc(excelPath);
	QXlsx::CellRange usedRange = m_doc.dimension();//获取有效数据范围
	int row = usedRange.rowCount();
	int col = usedRange.columnCount();

	if (row < 4 || col <= 4) {
		QMessageBox::warning(0, u8"警告", u8"Excel文件格式不正确或没有要生成的零件.");
		return;
	}

	//完成状态列标题
    QString finishedTitle = QString::fromUtf8(u8"完成状态");

	//获取列名
	bool flag = false;
	QMap<int, QString> colToTitle;//存储excel中列名
	QMap<QString, int> titleToCol;//存储excel中列名对应的列号
	for (int i = 0; i < col; ++i) {
		colToTitle[i]= m_doc.read(2, i + 1).toString();
		titleToCol[colToTitle[i]] = i;
		if (!flag && colToTitle[i] == finishedTitle)flag = true;
	}
	if (!flag) {
		QMessageBox::warning(0, u8"警告", u8"完成状态列不存在.");
		return;
	}

	//统计需要生成的行
	QList<int> listGenRow;
	for (int i = 3; i < row; ++i) {
		if (m_doc.read(i + 1, titleToCol[finishedTitle] + 1).toString() == QString::fromUtf8(u8"否"))
			listGenRow.append(i);
	}
	
	//复制文件
	QString genDir = QFileInfo(excelPath).absolutePath();
	QString baseName = QFileInfo(excelPath).fileName();
    baseName.remove(baseName.lastIndexOf("."),baseName.length()-baseName.lastIndexOf("."));
	QString filePathName;
	if (QFile::exists(genDir + "\\" + baseName + ".Z3ASM"))filePathName = genDir + "\\" + baseName + ".Z3ASM";
	else if (QFile::exists(genDir + "\\" + baseName + ".Z3PRT"))filePathName = genDir + "\\" + baseName + ".Z3PRT";

	//判断文件是否存在
	if (filePathName.isEmpty()) {
		QMessageBox::warning(0, u8"警告", u8"无法找到基础文件.");
		return;
	}

	//新生成文件名列表,并拷贝
    QList<QString> listNewFilePathName;
	for (int i = 0; i < listGenRow.size(); i++) {
		QString temp = filePathName;
		temp.replace('/', "\\");
		//listNewFilePathName.append(temp.insert(filePathName.lastIndexOf("."), ".00" + QString::number(i + 1)));
		QString targetDir = genDir + "\\" + QString::number(i + 1)+"\\";
		QDir _dir(targetDir);
		if (_dir.exists()) {
			QString( _dir.removeRecursively()).toLocal8Bit();
		}
		_dir.mkpath(targetDir);
		listNewFilePathName.append(temp.insert(temp.lastIndexOf('\\')+1, QString::number(i + 1)+ '\\'));
		
		QFileInfoList fileInfoList =  QDir(genDir).entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
		for (int j = 0; j < fileInfoList.size(); j++) {
			if (fileInfoList.at(j).suffix() == "Z3PRT" || fileInfoList.at(j).suffix() == "Z3ASM") {
				QFile::copy(fileInfoList.at(j).absoluteFilePath(), targetDir + "\\" + fileInfoList.at(j).fileName());
			}
		}
	}
	
	//生成
	int paramStartCol = titleToCol[QString::fromUtf8(u8"物料名称")] + 1;
	int paramEndCol= titleToCol[QString::fromUtf8(u8"图号")] -1;
	for (int i = 0; i < listNewFilePathName.size(); i++) {
		if (cvxFileOpen(listNewFilePathName[i].toLocal8Bit()) == ZW_API_NO_ERROR) {
			for (int j = paramStartCol; j <= paramEndCol; j++) {
				svxVariable var = { 0 };
				strcpy_s(var.Name, colToTitle[j].toLocal8Bit());//变量名
				cvxPartVarGet(&var);

				strcpy_s(var.Expression, m_doc.read(listGenRow[i]+1, j + 1).toString().toLocal8Bit());//通过修改变量的表达式来修改变量值
				cvxPartVarSet(1, &var, TRUE);
			}

			cvxEqRegen(-1);
			cvxCmdSend((char*)"~AsmCall(RegenAllCmp)");
			cvxFileSave3(1, 0, 1);
		}
	}

	QMessageBox::information(0, u8"提示", u8"生成完成.");
	cvxMsgDisp2(QString::fromUtf8(u8"生成完成,路径:" + genDir.toUtf8()).toLocal8Bit(), 1);
}

void batchInsertion()
{
	QStringList fileList = QFileDialog::getOpenFileNames(0, u8"选择插入文件", g_currentWorkDir + "/" + g_projectDirName);

	for (int i = 0; i < fileList.size(); i++) {
		QString tepm = fileList.at(i);
		tepm.replace('/', '\\');

		const char* filePath = tepm.toLocal8Bit();//文件全路径
		QString rootName = QFileInfo(fileList.at(i)).fileName();
		rootName.remove(rootName.lastIndexOf('.'), rootName.length() - rootName.lastIndexOf('.'));
		const char* rootObjName = rootName.toLocal8Bit();//根对象名，只有是.Z3文件时才需要

		svxCompData component = { 0 };

		cvxCompInsInit(&component);//初始化

		cvxMemZero((void*)&component, sizeof(svxCompData));
		cvxPathDir((char*)filePath, component.Dir);//文件目录
		cvxPathFile((char*)filePath, component.File);//文件名
		strcpy_s(component.Part, rootObjName);//单文件多部件模式下根对象的名称	

		svxMatrix matrix;
		cvxMatInit(&matrix);
		matrix.xt = 0;//放置位置的X坐标
		matrix.yt = 0;//放置位置的Y坐标
		matrix.zt = 0;//放置位置的Z坐标
		component.Frame = matrix;//位置
		component.Anchor = 0;//不固定

		component.SettingsData.InsertToLayer = 0;//插入默认图层（默认）
		component.SettingsData.LayerName;//InsertToLayer = 1时，设置图层名字

		int componentId = 0;//插入后组件的Id
		cvxCompIns(&component, &componentId);
	}
}

QString g_getToken()
{
	return g_configSettings->value("user/token").toString();
}


QString g_getBaseUrl()
{
	return g_configSettings->value("url/baseUrl").toString();
}

void releasePlugin() {
	//释放登录界面指针资源
	delete LogIn::getInstance();

	//释放标准库界面指针资源
	delete stdGit::getInstance();

	//释放元器件库界面指针资源
	delete capGit::getInstance();

	//释放项目库界面指针资源
	delete proGit::getInstance();

	//释放编辑界面指针资源
	delete edit::getInstance();

	//释放单柜命中资源
	delete schHit::getInstance();

	//释放excel驱动窗口资源
	delete excelToPrt::getInstance();
}
