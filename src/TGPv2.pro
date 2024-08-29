QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FunCore.cpp \
    capGit.cpp \
    edit.cpp \
    exceltoprt.cpp \
    login.cpp \
    main.cpp \
    myreply.cpp \
    proGit.cpp \
    stdgit.cpp


HEADERS += \
    FunCore.h \
    capGit.h \
    edit.h \
    exceltoprt.h \
    global.h \
    login.h \
    myreply.h \
    proGit.h \
    stdgit.h


FORMS += \
    capGit.ui \
    edit.ui \
    exceltoprt.ui \
    login.ui \
    progit.ui \
    stdgit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imgs.qrc
