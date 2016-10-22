// UIThread.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "UIThread.h"
#include "TrayIconTestDlg.h"

// CUIThread

IMPLEMENT_DYNCREATE(CUIThread, CWinThread)

CUIThread::CUIThread()
{
	
}

CUIThread::~CUIThread()
{
}

BOOL CUIThread::InitInstance()
{
	// TODO:  여기에서 각 스레드에 대한 초기화를 수행합니다.
	m_progressWnd = new CProgressDlg;
	m_progressWnd->ShowWindow(SW_SHOW);
	m_progressWnd->UpdateWindow();
	//pParent->m_progress_flag = 1;
	//((CTrayIconTestDlg*)AfxGetMainWnd())->m_progress_flag = 1;
	return TRUE;
}

int CUIThread::ExitInstance()
{
	// TODO:  여기에서 각 스레드에 대한 정리를 수행합니다.
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUIThread, CWinThread)
END_MESSAGE_MAP()


// CUIThread 메시지 처리기입니다.


//int CUIThread::Run()
//{
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//	CTrayIconTestApp *pApp = (CTrayIconTestApp*)AfxGetApp();
//	CProgressDlg *pDlg = ((CTrayIconTestDlg*)AfxGetMainWnd())->m_P;
//	pDlg->m_ctlProg.SetRange(0, 10);
//	pDlg->m_ctlProg.SetPos(0);
//	for (int i = 0; i < 10; i++)
//	{
//		pDlg->m_ctlProg.SetPos(i);
//		Sleep(1);
//	}
//	return 0;
//	//return CWinThread::Run();
//}
