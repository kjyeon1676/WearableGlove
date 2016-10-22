// HookTest.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "TrayIconTestDlg.h"
#include "HookTest.h"
#include "afxdialogex.h"


// CHookTest 대화 상자입니다.

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


// CHookTest 메시지 처리기입니다.

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
//	//이 아래부터 마우스 후킹 데이터 입력값들을 정의..
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
//		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
//		int cxIcon = GetSystemMetrics(SM_CXICON);
//		int cyIcon = GetSystemMetrics(SM_CYICON);
//		CRect rect;
//		GetClientRect(&rect);
//		int x = (rect.Width() - cxIcon + 1) / 2;
//		int y = (rect.Height() - cyIcon + 1) / 2;
//
//		// 아이콘을 그립니다.
//		dc.DrawIcon(x, y, m_hIcon);
//	}
//	else
//		CDialogEx::OnPaint();
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
//}


//HCURSOR CHookTest::OnQueryDragIcon()
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	return static_cast<HCURSOR>(m_hIcon);
//}


void CHookTest::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	//m_mhook = SetWindowsHookEx(WH_MOUSE_LL, GetMsgProcm,theApp.m_hInstance , NULL);
	//m_keyhook = SetWindowsHookEx(WH_KEYBOARD_LL, GetMsgProck, theApp.m_hInstance, NULL);
	/*if (m_keyhook == NULL || m_mhook == NULL)
	{
		MessageBox(_T("Hooking Error..."));
	}*/
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CHookTest::OnRawInput(UINT nInputcode, HRAWINPUT hRawInput)
{
	// 이 기능을 사용하려면 Windows XP 이상이 필요합니다.
	// _WIN32_WINNT 기호는 0x0501보다 크거나 같아야 합니다.
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnMouseLeave();
}
