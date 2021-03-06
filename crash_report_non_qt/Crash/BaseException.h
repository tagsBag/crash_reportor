#pragma once
#include "StackWalker.h"
#include <eh.h>

class CBaseException : public CStackWalker
{
public:
	CBaseException(HANDLE hProcess = GetCurrentProcess(), WORD wPID = GetCurrentProcessId(), LPCTSTR lpSymbolPath = NULL, PEXCEPTION_POINTERS pEp = NULL);
	~CBaseException(void);
	virtual void OutputString(LPCTSTR lpszFormat, ...);
	virtual void ShowLoadModules();
	virtual void ShowCallstack(HANDLE hThread = GetCurrentThread(), const CONTEXT* context = NULL);
	virtual void ShowExceptionResoult(DWORD dwExceptionCode);
	virtual BOOL GetLogicalAddress(PVOID addr, PTSTR szModule, DWORD len, DWORD& section, DWORD& offset );
	virtual void ShowRegistorInformation(PCONTEXT pCtx);
	virtual void ShowExceptionInformation();
	static LONG WINAPI UnhandledExceptionFilter(PEXCEPTION_POINTERS pExceptionInfo);
	static void STF(unsigned int ui,  PEXCEPTION_POINTERS pEp);
protected:
	PEXCEPTION_POINTERS m_pEp;
};

#define SET_DEFULTER_HANDLER() SetUnhandledExceptionFilter(CBaseException::UnhandledExceptionFilter)

#define SET_DEFAUL_EXCEPTION() _set_se_translator(CBaseException::STF)
