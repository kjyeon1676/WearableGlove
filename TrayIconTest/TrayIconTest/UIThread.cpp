// UIThread.cpp : ���� �����Դϴ�.
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
	// TODO:  ���⿡�� �� �����忡 ���� �ʱ�ȭ�� �����մϴ�.
	m_progressWnd = new CProgressDlg;
	m_progressWnd->ShowWindow(SW_SHOW);
	m_progressWnd->UpdateWindow();
	//pParent->m_progress_flag = 1;
	//((CTrayIconTestDlg*)AfxGetMainWnd())->m_progress_flag = 1;
	return TRUE;
}

int CUIThread::ExitInstance()
{
	// TODO:  ���⿡�� �� �����忡 ���� ������ �����մϴ�.
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUIThread, CWinThread)
END_MESSAGE_MAP()


// CUIThread �޽��� ó�����Դϴ�.


//int CUIThread::Run()
//{
//	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
