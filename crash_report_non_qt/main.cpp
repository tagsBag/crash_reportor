#include <iostream>

using namespace std;

#include <stdio.h>
#include <tchar.h>
#include "Crash/BaseException.h"

void Func5()
{
    CBaseException sw;
    sw.ShowCallstack();
}

void Func4()
{
    Func5();
}
void Func3()
{
    Func4();
}
void Func2()
{
    Func3();
}
void Func1()
{
    Func2();
}

void StackWalkTest()
{
    Func1();
}

void ExceptionTest()
{
    int i = 1;
    int c = i / 0;
}

void TryTest()
{
    try
    {
        SET_DEFAUL_EXCEPTION();
        int *p = NULL;
        *p = 0;
    }
    catch (CBaseException &e)
    {
        e.ShowExceptionInformation();
    }
}

int main()
{
    SET_DEFULTER_HANDLER();

    //CBaseException be;
    //be.ShowLoadModules();     //mid 输出 已加载 的 dll

    //StackWalkTest();          //mid 无异常 输出某个 函数的 调用堆栈

    TryTest();                //mid 捕获 并 输出 奔溃错误信息
    //ExceptionTest();

    return 0;
}
