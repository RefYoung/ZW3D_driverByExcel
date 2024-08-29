#include "global.h"

//全局变量
QNetworkAccessManager g_networkManager;//全局网络访问管理器
QSettings *g_configSettings;//全局配置文件
QString g_userToken;//用户token
QString g_baseUrl;//基本请求地址
QString g_loginUrl;//登录请求路径
QString g_getUserInfoUrl;//获取用户信息请求路径
QString g_getProductInfoUrl;//获取产品信息请求路径
QString g_getModeTreeUrl;//获取模型树请求路径
QString g_query3DTPGitMapListUrl;//查询3D方案图列表请求路径
QString g_projectCheckInUrl;//项目入库请求路径
QString g_projectCheckOutUrl;//项目检出请求路径
QString g_openModelUrl;//打开模型请求路径
QString g_prtDetailUrl;//获取装配体零件详情请求路径
QString g_engineeringDrawingUrl;//上传工程图请求路径
QString g_3DCopperBarScheme;//上传3D铜排方案请求路径
QString g_batchUploadThumbnail;//批量上传缩略图请求路径
QString g_generateNewScheme;//生成新方案请求路径
QString g_currentWorkDir;//当前工作目录
QString g_configFilePathName;//配置文件名称和路径
QString g_ftpUserName;//ftp服务器账号
QString g_ftpUserPswd;//ftp服务器密码
QString g_ftpBaseUrl;//ftp服务器地址

//仓库路径
QString g_capGitDirPath;//元器件库路径

//用户属性
QString g_materialNo;//物料号
QString g_graphName;//名称
QString g_graphTypeId;//方案图类型ID
QString g_graphId;//方案图ID
QString g_detector;//检出人
QString g_remark;//备注
QString g_isOutputGraph;//是否输出工程图