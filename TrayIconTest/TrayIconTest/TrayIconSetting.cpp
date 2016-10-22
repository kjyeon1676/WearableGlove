// TrayIconSetting.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "TrayIconSetting.h"
#include "afxdialogex.h"
#include "First.h"
#include "Second.h"

// TrayIconSetting ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(TrayIconSetting, CDialogEx)

TrayIconSetting::TrayIconSetting(CWnd* pParent /*=NULL*/)
	: CDialogEx(TrayIconSetting::IDD, pParent)
{
	m_pwndShow = NULL;
	m_brCheck.CreateSolidBrush(RGB(255, 255, 255));
}

TrayIconSetting::~TrayIconSetting()
{
}

void TrayIconSetting::DoDataExchange(CDataExchange* pDX)
{  
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_ctlTab);
}


BEGIN_MESSAGE_MAP(TrayIconSetting, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &TrayIconSetting::OnTcnSelchangeTab1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// TrayIconSetting �޽��� ó�����Դϴ�.
void TrayIconSetting::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CDialogEx::OnOK();
	//CDialogEx::DestroyWindow();
}


void TrayIconSetting::OnCancel()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	
	CDialogEx::DestroyWindow();
}


void TrayIconSetting::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (nID)
	{
	case SC_CLOSE:
		CDialogEx::DestroyWindow();
		break;

	}
	CDialogEx::OnSysCommand(nID, lParam);
}


void TrayIconSetting::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_pwndShow != NULL)
	{
		m_pwndShow->ShowWindow(SW_HIDE);
		m_pwndShow = NULL;
	}
	int nIndex = m_ctlTab.GetCurSel();
	switch (nIndex)
	{
	case 0:
		m_First.ShowWindow(SW_SHOW);
		m_pwndShow = &m_First;
		break;
	case 1:
		m_Second.ShowWindow(SW_SHOW);
		m_pwndShow = &m_Second;
		break;
	}
	*pResult = 0;
}


BOOL TrayIconSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctlTab.InsertItem(0, _T("�⺻����"));
	m_ctlTab.InsertItem(1, _T("��Ǽ���"));

	CRect rect;
	m_ctlTab.GetClientRect(&rect);
	//â ����,IDD�� ���ٸ� resource.h Ȯ���غ���
	m_First.Create(IDD_FIRST, &m_ctlTab);
	//������ ȭ��â ����..
	m_First.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_SHOWWINDOW | SWP_NOZORDER);
	//������ �ڵ鷯�� ��Ʈ�� ����
	m_pwndShow = &m_First;

	m_Second.Create(IDD_SECOND, &m_ctlTab);
	m_Second.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);

	//����̹��� �ֱ�
	CBitmap m_background;
	//m_background.LoadBitmapW();
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


HBRUSH TrayIconSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.
	UINT nID = pWnd->GetDlgCtrlID();
	if (nID == IDC_GPBOX)
	{
		hbr = (HBRUSH)::GetSysColorBrush(COLOR_WINDOW);
		pDC->SetBkColor(RGB(255, 255, 255));
	}
	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}


BOOL TrayIconSetting::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE))
	{
		pMsg->wParam = NULL;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
