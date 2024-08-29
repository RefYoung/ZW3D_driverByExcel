#include "TGoodPlugin.h"

using namespace std;

int TGoodPluginInit(int format, void* data)
{
	initConfig();//初始化配置

	//加载命令
	cvxCmdFunc("login_TGP", (void*)showLoginForm, VX_CODE_GENERAL);//显示登录界面
	cvxCmdFunc("exitLogin_TGP", (void*)exitLogIn, VX_CODE_GENERAL);//退出登录
	cvxCmdFunc("openUrlConfig_TGP", (void*)changeBaseUrl, VX_CODE_GENERAL);//修改接口地址
	cvxCmdFunc("openStdGit_TGP", (void*)openStdGit, VX_CODE_GENERAL);//打开标准git
	cvxCmdFunc("openCapGit_TGP", (void*)openCapGit, VX_CODE_GENERAL);//打开元器件库
	cvxCmdFunc("openProGit_TGP", (void*)openProGit, VX_CODE_GENERAL);//打开项目库
	cvxCmdFunc("openEditUI_TGP", (void*)openEditUI, VX_CODE_GENERAL);//打开编辑界面
	cvxCmdFunc("schemeHit_TGP", (void*)schemeHit, VX_CODE_GENERAL);//方案命中
	

	//新增命令
	cvxCmdFunc("initUserData_TGP", (void*)initPRTUserData, VX_CODE_GENERAL);//方案命中
	cvxCmdFunc("genPrtByExcel_TGP", (void*)genPrtByExcel, VX_CODE_GENERAL);//根据excel生成prt
	cvxCmdFunc("batchInsertion_TGP", (void*)batchInsertion, VX_CODE_GENERAL);
	

	/*cvxCmdFunc("test", (void*)test, VX_CODE_GENERAL);
	cvxCmdFunc("test2", (void*)test2, VX_CODE_GENERAL);*/

	return 0;
}
int TGoodPluginExit()
{
	//卸载命令
	cvxCmdFuncUnload("login_TGP");
	cvxCmdFuncUnload("exitLogin_TGP");
	cvxCmdFuncUnload("openUrlConfig_TGP");
	cvxCmdFuncUnload("openStdGit_TGP");
	cvxCmdFuncUnload("openCapGit_TGP");
	cvxCmdFuncUnload("openProGit_TGP");
	cvxCmdFuncUnload("openEditUI_TGP");
	cvxCmdFuncUnload("schemeHit_TGP");
	cvxCmdFuncUnload("genPrtByExcel_TGP");

	//卸载新增命令
	cvxCmdFuncUnload("initUserData_TGP");
	cvxCmdFuncUnload("batchInsertion_TGP");

	/*cvxCmdFuncUnload("test");
	cvxCmdFuncUnload("test2");*/

	releasePlugin();//释放插件资源
	cvxMsgDisp2("[TGP]TGoodPluginExit!", 1);
	return 0;
}

void test()
{
	cvxSessionClear();
	QString filePath = QString::fromUtf8(u8"D:\\Program Files\\ZWCAD\\testDIr\\铜排三维模型\\铜排测试\\进线柜\\5C.K65.001.0001_柜体-进线柜体.Z3ASM");

	if (cvxFileOpen(filePath.toLocal8Bit()) == ZW_API_NO_ERROR) {
		QXlsx::Document m_doc(QString::fromUtf8(u8"C:\\Users\\86152\\Desktop\\测试表.xlsx"));
		QXlsx::CellRange usedRange = m_doc.dimension();//获取有效数据范围
		int row = usedRange.rowCount();
		int col = usedRange.columnCount();

		QMap<int, QString> _map;

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (i == 0) {
					_map[j] = m_doc.read(i + 1, j + 1).toString();
				}
				else {
					svxVariable var = { 0 };
					strcpy_s(var.Name, _map[j].toLocal8Bit());//变量名
					cvxPartVarGet(&var);

					strcpy_s(var.Expression, m_doc.read(i + 1, j + 1).toString().toLocal8Bit());//通过修改变量的表达式来修改变量值
					cvxPartVarSet(1, &var, TRUE);
				}

			}
		}

		cvxEqRegen(-1);
		cvxCmdSend((char*)"~AsmCall(RegenAllCmp)");
		cvxFileSave3(0, 0, 1);
	}
}

void test2()
{
	


	QStringList fileList = QFileDialog::getOpenFileNames(0, u8"选择插入文件", g_currentWorkDir + "/" + g_projectDirName);

	if (fileList.count() <= 0) return;

	QString tepm = fileList.at(0);
	tepm.replace('/', '\\');

	const char* filePath = tepm.toLocal8Bit();//文件全路径
	QString rootName = QFileInfo(fileList.at(0)).fileName();
	rootName.remove(rootName.lastIndexOf('.'), rootName.length() - rootName.lastIndexOf('.'));
	const char* rootObjName = rootName.toLocal8Bit();//根对象名，只有是.Z3文件时才需要

	cvxMsgDisp(filePath);

	svxCompData component = { 0 };

	cvxCompInsInit(&component);//初始化

	cvxMemZero((void*)&component, sizeof(svxCompData));
	cvxPathDir((char*)filePath, component.Dir);//文件目录
	cvxPathFile((char*)filePath, component.File);//文件名
	strcpy_s(component.Part, rootObjName);//单文件多部件模式下根对象的名称	

	cvxMsgDisp(component.Dir);
	cvxMsgDisp(component.File);
	cvxMsgDisp(component.Part);

	svxMatrix matrix;
	cvxMatInit(&matrix);
	matrix.xt = 100;//放置位置的X坐标
	matrix.yt = 100;//放置位置的Y坐标
	matrix.zt = 100;//放置位置的Z坐标
	component.Frame = matrix;//位置
	component.Anchor = 0;//不固定

	component.SettingsData.InsertToLayer = 0;//插入默认图层（默认）
	component.SettingsData.LayerName;//InsertToLayer = 1时，设置图层名字

	int componentId = 0;//插入后组件的Id
	int errcode = cvxCompIns(&component, &componentId);
	cvxMsgDisp("errCode:" + QString::number(errcode).toLocal8Bit());

}
