#pragma once
#include "ProgressDlg.h"
// CUIThread

class CUIThread : public CWinThread
{
	DECLARE_DYNCREATE(CUIThread)

public:
	CUIThread();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CUIThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	CProgressDlg *m_progressWnd;
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual int Run();
};


