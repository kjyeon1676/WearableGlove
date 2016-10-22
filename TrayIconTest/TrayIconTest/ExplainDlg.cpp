// ExplainDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "ExplainDlg.h"
#include "afxdialogex.h"
#include "resource.h"

// CExplainDlg ��ȭ �����Դϴ�.

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


// CExplainDlg �޽��� ó�����Դϴ�.


void CExplainDlg::OnStnClickedStartsettext()
{
	m_StartExplainBtn.LoadBitmaps(IDB_StartHand3, NULL, NULL, NULL);
	m_StartExplainBtn.SizeToContent();
	m_StartExplainBtn.ShowWindow(SW_SHOW); 
}


BOOL CExplainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_StartExplainBtn.ShowWindow(SW_HIDE);
	LOGFONT log;
	GetFont()->GetLogFont(&log);
	log.lfUnderline = TRUE;
	m_font.CreateFontIndirect(&log);
	GetDlgItem(IDC_STARTSETTEXT)->SetFont(&m_font);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CExplainDlg::OnBnClickedStartexpbtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	m_StartExplainBtn.ShowWindow(SW_HIDE);
}
