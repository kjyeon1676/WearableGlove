#pragma once
#include "ProgressDlg.h"
// CUIThread

class CUIThread : public CWinThread
{
	DECLARE_DYNCREATE(CUIThread)

public:
	CUIThread();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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


