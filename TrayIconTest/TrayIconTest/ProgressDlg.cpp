// ProgressDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "ProgressDlg.h"
#include "afxdialogex.h"
#include "TrayIconTestDlg.h"

// CProgressDlg ��ȭ �����Դϴ�.

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


// CProgressDlg �޽��� ó�����Դϴ�.


BOOL CProgressDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CTrayIconTestDlg *pParent = (CTrayIconTestDlg*)AfxGetMainWnd();
	m_ctlProg.SetRange(0, pParent->m_transferIndex);
	m_ctlProg.SetPos(0);
	for (int i = 0; i <= pParent->m_transferIndex; i++)
	{
		::Sleep(50);
		m_ctlProg.SetPos(i);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
