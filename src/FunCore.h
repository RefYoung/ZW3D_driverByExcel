#pragma once
#include "global.h"
#include <qinputdialog.h>
#include "login.h"
#include "stdgit.h"
#include <QObject>
#include "capGit.h"
#include "proGit.h"
#include "edit.h"
#include <QApplication>
#include <qdesktopwidget.h>
#include "schHit.h"
#include <VxApi.h>
#include <QtXlsx>
#include <QFileDialog>
#include "exceltoprt.h"
#include <qdir.h>

//全局函数部分
//插件注册
extern void showLoginForm();//显示登录窗体	
extern void exitLogIn();//退出登录
extern void changeBaseUrl();//修改基础url
extern void openStdGit();//打开标准git
extern void openCapGit();//打开元器件库
extern void openProGit();//打开项目库
extern void openEditUI();//打开编辑界面
extern void schemeHit();//方案命中事件
extern void initPRTUserData();//初始化用户数据
extern void genPrtByExcel();//生成prt文件
extern void batchInsertion();//批量插入

//程序内部逻辑
extern void initConfig();//初始化配置
extern void releasePlugin();//释放插件资源
extern QString g_getToken();//获取token
extern QString g_getBaseUrl();//获取基础url
