@echo off
SetLocal EnableDelayedExpansion
(set QT_VERSION=0.3.0)
(set QT_VER=0.3)
(set QT_VERSION_TAG=030)
(set QT_INSTALL_DOCS=D:/QT/Docs/Qt-5.9.8)
(set BUILDDIR=D:/QT/5.9.8/msvc2017_64/QtXlsxWriter-master/src/xlsx)
D:\QT\5.9.8\msvc2017_64\bin\qdoc.exe %*
EndLocal
