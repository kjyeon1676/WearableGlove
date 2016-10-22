// HookTest.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "TrayIconTestDlg.h"
#include "HookTest.h"
#include "afxdialogex.h"


// CHookTest ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHookTest, CDialogEx)
//LRESULT CALLBACK GetMsgProcm(int nCode, WPARAM wParam, LPARAM lParam);
//HHOOK m_keyhook = NULL;
//HHOOK m_mhook = NULL;
HINSTANCE hInstance;
CHookTest::CHookTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHookTest::IDD, pParent)
{
}

CHookTest::~CHookTest()
{
}

void CHookTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VIEWX, CXpos);
	DDX_Control(pDX, IDC_VIEWY, CYpos);
}


BEGIN_MESSAGE_MAP(CHookTest, CDialogEx)
	ON_WM_NCMOUSEMOVE()
//	ON_WM_PAINT()
//	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_INPUT()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()


// CHookTest �޽��� ó�����Դϴ�.

//LRESULT CALLBACK GetMsgProcm(int nCode, WPARAM wParam, LPARAM lParam)
//{
//	static int c = 0;
//	KBDLLHOOKSTRUCT *pKey = (KBDLLHOOKSTRUCT *)lParam;
//
//	CHookTest* pMainDlg =((CTrayIconTestDlg*)AfxGetMainWnd())->m_hookTest;
//
//	if (nCode < 0)
//		return CallNextHookEx(m_mhook, nCode, wParam, lParam);
//
//	//�� �Ʒ����� ���콺 ��ŷ ������ �Է°����� ����..
//	if (wParam == WM_MOUSEMOVE)
//	{
//		CPoint pos; 
//		GetCursorPos(&pos);
//		CString str;
//		str.Format(_T("%d"), pos.x);
//		pMainDlg->CXpos.SetWindowText(str);
//		str.Format(_T("%d"), pos.y);
//		pMainDlg->CYpos.SetWindowText(str);
//		TRACE(_T("mouse moving ... \n"));
//	}
//	return CallNextHookEx(m_mhook, nCode, wParam, lParam);
//}
void CHookTest::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CPoint pos;
	GetCursorPos(&pos);
	CString str;
	str.Format(_T("%d"), pos.x);
	this->CXpos.SetWindowText(str);
	str.Format(_T("%d"), pos.y);
	this->CYpos.SetWindowText(str);

	CDialogEx::OnNcMouseMove(nHitTest, point);
}


//void CHookTest::OnPaint()
//{
//	if ((IsIconic()))
//	{
//		CPaintDC dc(this); // device context for painting
//		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
//
//		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
//		int cxIcon = GetSystemMetrics(SM_CXICON);
//		int cyIcon = GetSystemMetrics(SM_CYICON);
//		CRect rect;
//		GetClientRect(&rect);
//		int x = (rect.Width() - cxIcon + 1) / 2;
//		int y = (rect.Height() - cyIcon + 1) / 2;
//
//		// �������� �׸��ϴ�.
//		dc.DrawIcon(x, y, m_hIcon);
//	}
//	else
//		CDialogEx::OnPaint();
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//	// �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
//}


//HCURSOR CHookTest::OnQueryDragIcon()
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	return static_cast<HCURSOR>(m_hIcon);
//}


void CHookTest::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CPoint pos;
	GetCursorPos(&pos);
	CString str;
	str.Format(_T("%d"), pos.x);
	this->CXpos.SetWindowText(str);
	str.Format(_T("%d"), pos.y);
	this->CYpos.SetWindowText(str);
	CDialogEx::OnMouseMove(nFlags, point);
}


BOOL CHookTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	//m_mhook = SetWindowsHookEx(WH_MOUSE_LL, GetMsgProcm,theApp.m_hInstance , NULL);
	//m_keyhook = SetWindowsHookEx(WH_KEYBOARD_LL, GetMsgProck, theApp.m_hInstance, NULL);
	/*if (m_keyhook == NULL || m_mhook == NULL)
	{
		MessageBox(_T("Hooking Error..."));
	}*/
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CHookTest::OnRawInput(UINT nInputcode, HRAWINPUT hRawInput)
{
	// �� ����� ����Ϸ��� Windows XP �̻��� �ʿ��մϴ�.
	// _WIN32_WINNT ��ȣ�� 0x0501���� ũ�ų� ���ƾ� �մϴ�.
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	/*CPoint pos;
	::GetCursorPos(&pos);
	CString str;
	str.Format(_T("%d"), pos.x);
	this->CXpos.SetWindowText(str);
	str.Format(_T("%d"), pos.y);
	this->CYpos.SetWindowText(str);*/
	CDialogEx::OnRawInput(nInputcode, hRawInput);
}


void CHookTest::OnMouseLeave()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialogEx::OnMouseLeave();
}
