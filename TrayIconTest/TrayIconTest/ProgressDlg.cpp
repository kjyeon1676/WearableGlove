// ProgressDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "ProgressDlg.h"
#include "afxdialogex.h"
#include "TrayIconTestDlg.h"

// CProgressDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CProgressDlg, CDialogEx)

CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProgressDlg::IDD, pParent)
{
	Create(IDD_PROG);

}

CProgressDlg::~CProgressDlg()
{
}

void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctlProg);
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialogEx)
END_MESSAGE_MAP()


// CProgressDlg 메시지 처리기입니다.


BOOL CProgressDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CTrayIconTestDlg *pParent = (CTrayIconTestDlg*)AfxGetMainWnd();
	m_ctlProg.SetRange(0, pParent->m_transferIndex);
	m_ctlProg.SetPos(0);
	for (int i = 0; i <= pParent->m_transferIndex; i++)
	{
		::Sleep(50);
		m_ctlProg.SetPos(i);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
