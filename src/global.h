#ifndef GLOBAL_H
#define GLOBAL_H

#include <qstring.h>
#include <qnetworkreply.h>
#include <qfile.h>
#include <qnetworkaccessmanager.h>
#include <qsettings.h>
#include <qmessagebox.h>
#include <qfileinfo.h>
#include <qdir.h>
#include <VxApi.h>
#include <Zwsdk.h>
#include <ZwSdkBase.h>
#include <ZwSdkDatabase.h>
#include <ZwSdkDisplay.h>
#include "login.h"
#include <qsettings.h>


//全局变量部分
extern QNetworkAccessManager g_networkManager;//全局网络访问管理器
extern QSettings *g_configSettings;//全局配置文件
extern QString g_userToken;//用户token
extern QString g_loginUrl;//登录请求路径
extern QString g_getUserInfoUrl;//获取用户信息请求路径
extern QString g_getProductInfoUrl;//获取产品信息请求路径
extern QString g_getModeTreeUrl;//获取模型树请求路径
extern QString g_query3DTPGitMapListUrl;//查询3D方案图列表请求路径
extern QString g_projectCheckInUrl;//项目入库请求路径
extern QString g_projectCheckOutUrl;//项目检出请求路径
extern QString g_openModelUrl;//打开模型请求路径
extern QString g_prtDetailUrl;//获取装配体零件详情请求路径
extern QString g_engineeringDrawingUrl;//上传工程图请求路径
extern QString g_3DCopperBarScheme;//上传3D铜排方案请求路径
extern QString g_batchUploadThumbnail;//批量上传缩略图请求路径
extern QString g_generateNewScheme;//生成新方案请求路径
extern QString g_currentWorkDir;//当前工作目录,如果2D工作目录不存在,则使用默认工作目录:C:\Users\(你的用户名)\AppData\Roaming\ZWSOFT\ZW3D\ZW3D
extern QString g_configFilePathName;//配置文件名称和路径,当前工作目录下的g_configFileName文件
extern QString g_ftpUserName;//ftp服务器账号
extern QString g_ftpUserPswd;//ftp服务器密码
extern QString g_ftpBaseUrl;//ftp服务器地址

//仓库路径
extern QString g_capGitDirPath;//元器件库路径

//用户属性名称
extern QString g_materialNo;//物料号
extern QString g_graphName;//名称
extern QString g_graphTypeId;//方案图类型ID
extern QString g_graphId;//方案图ID
extern QString g_detector;//检出人
extern QString g_remark;//备注
extern QString g_isOutputGraph;//是否输出工程图

//全局常量部分
#define g_configFileName "config.ini"   //程序配置文件名
//#define g_workDirRegitPath "HKEY_LOCAL_MACHINE\\SOFTWARE\\ZWSOFT\\ZWCAD\\2022\\zh-CN\\Applications\\CKOptional" //2D程序注册表位置,正式环境
#define g_workDirRegitPath "HKEY_LOCAL_MACHINE\\SOFTWARE\\ZWSOFT\\ZWCAD\\2022\\zh-CN\\Applications\\CKOptionalTestEnvironment" //2D程序注册表位置,测试环境
#define g_chemeHitJsonFileName "3DJSON.json"	//方案命中的json文件名,需要配合工作目录一起使用
#define g_projectDirName u8"铜排三维模型"	//方案命中的项目库文件夹名称
#define g_newGenJsonFileName "newGen3DJSON.json"	//新生成的方案json文件名
#define g_genPrtByExcelFileDir u8"生成文件"	//根据excel生成装配体的文件夹名称

//全局结构体部分
struct schHitItem {//用于方案命中的处理项结构体
	QString valDes;//变形规则
	QString graphFile;//文件下载地址
	QFile* file;//下载的文件
	bool variantStatus;//是否需要变形
	QString projectName;//项目名
	QString cabinetName;//柜体名
	QString fileName;//文件名
	QString fileUniqueIdentify;//唯一标识符
	QFile* pic;//缩略图
	QString picPath;//图片url
	QString fileUrl;//上传文件后更新的url
};

struct openModelItem {//用于打开模型的零件结构体
	QString fileName;//文件名,不包含文件路径
	QString graphId;//零件id
	QString graphTypeId;//零件方案图id
	QString graphName;//零件名称
	QString materialNo;//零件物料号
	QString detector;//零件更新人
	QString remark;//零件描述
	QString isOutPutGraph;//是否输出二维图
};


#endif // GLOBAL_H