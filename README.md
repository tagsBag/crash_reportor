# crash_reportor



为了在 release 编译下能够 生成 异常出发处的调用栈,以下编译选项很重要,需要特别 注意 CXX c++编译器编译选项 和 C c编译器选项 之间设置的参数名称区别
QMAKE_CXXFLAGS_RELEASE_WITH_DEBUGINFO 和 QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO 注意区分,否则不提示错误,但是无法在release运行时报告崩溃调用stack

QMAKE_CXXFLAGS_RELEASE_WITH_DEBUGINFO += -Od -MD -Zi                #mid Od 用于 取消编译优化,否则一些 有错误 的语句 会被 优化掉
QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO += /INCREMENTAL:NO /DEBUG

QMAKE_CXXFLAGS_RELEASE += $$QMAKE_CXXFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE += $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO





![alt text](https://github.com/tagsBag/crash_reportor/blob/master/crash_report_non_qt/%E6%8D%95%E8%8E%B7.PNG "GUI Preview")

