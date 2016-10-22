// ExplainDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "ExplainDlg.h"
#include "afxdialogex.h"
#include "resource.h"

// CExplainDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CExplainDlg, CDialogEx)

CExplainDlg::CExplainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExplainDlg::IDD, pParent)
{

}

CExplainDlg::~CExplainDlg()
{
}

void CExplainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STARTSETTEXT, m_startText);
	DDX_Control(pDX, IDC_STARTEXPBTN, m_StartExplainBtn);
}


BEGIN_MESSAGE_MAP(CExplainDlg, CDialogEx)
	ON_STN_CLICKED(IDC_STARTSETTEXT, &CExplainDlg::OnStnClickedStartsettext)
	ON_BN_CLICKED(IDC_STARTEXPBTN, &CExplainDlg::OnBnClickedStartexpbtn)
END_MESSAGE_MAP()


// CExplainDlg 메시지 처리기입니다.


void CExplainDlg::OnStnClickedStartsettext()
{
	m_StartExplainBtn.LoadBitmaps(IDB_StartHand3, NULL, NULL, NULL);
	m_StartExplainBtn.SizeToContent();
	m_StartExplainBtn.ShowWindow(SW_SHOW); 
}


BOOL CExplainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_StartExplainBtn.ShowWindow(SW_HIDE);
	LOGFONT log;
	GetFont()->GetLogFont(&log);
	log.lfUnderline = TRUE;
	m_font.CreateFontIndirect(&log);
	GetDlgItem(IDC_STARTSETTEXT)->SetFont(&m_font);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CExplainDlg::OnBnClickedStartexpbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	m_StartExplainBtn.ShowWindow(SW_HIDE);
}
