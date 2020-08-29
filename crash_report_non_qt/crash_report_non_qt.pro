TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

win32{#mid {要紧随其后,否则无效,1)解决界面中文乱码问题.2)解决源码文件 utf-8 编码加载问题
        QMAKE_CXXFLAGS += /utf-8
    }

SOURCES += \
    Crash/BaseException.cpp \
    Crash/StackWalker.cpp \
    main.cpp \

HEADERS += \
    Crash/BaseException.h \
    Crash/StackWalker.h \


#############################################################################
#mid 以下是为 dump 转为 text 的依赖,是 window 系统的自带库,不必指明路径
win32: LIBS += -lVersion
win32: LIBS += -lDbgHelp

#mid 以下目的是Release版也将生成“.pdb”后缀的调试信息文件
#INCREMENTAL:NO 非增量编译
#/DEBUG 生成调试信息
#-Zi 调试信息格式 pdb
#优化选项,O2(优化速度),Od(禁用优化)
#多线程,MD(多线程动态,默认安装的qt用这个模式),MT(多线程静态)

#QMAKE_CXXFLAGS_RELEASE    += -Od -MD -Zi                        #mid c++ compiler 选项,QMAKE_CFLAGS_RELEASE是 c compiler选项
#QMAKE_LFLAGS_RELEASE     += /INCREMENTAL:NO /DEBUG               #mid linker 选项

#mid 注意 CFLAGS 和 CXXFLAGS 的区别,一个用于指定 c compiler 编译选项,一个用于 指定 c++ compiler 选项
#mid QMAKE_CXXFLAGS_RELEASE_WITH_DEBUGINFO 用于设置参数,此参数将用于 QMAKE_CXXFLAGS_RELEASE

QMAKE_CXXFLAGS_RELEASE_WITH_DEBUGINFO += -Od -MD -Zi                #mid Od 用于 取消编译优化,否则一些 有错误 的语句 会被 优化掉
QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO += /INCREMENTAL:NO /DEBUG

QMAKE_CXXFLAGS_RELEASE += $$QMAKE_CXXFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE += $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO
#############################################################################
