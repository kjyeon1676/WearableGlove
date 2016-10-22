// TrayIconSetting.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "TrayIconSetting.h"
#include "afxdialogex.h"
#include "First.h"
#include "Second.h"

// TrayIconSetting 대화 상자입니다.

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


// TrayIconSetting 메시지 처리기입니다.
void TrayIconSetting::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CDialogEx::OnOK();
	//CDialogEx::DestroyWindow();
}


void TrayIconSetting::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	CDialogEx::DestroyWindow();
}


void TrayIconSetting::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ctlTab.InsertItem(0, _T("기본설정"));
	m_ctlTab.InsertItem(1, _T("모션설정"));

	CRect rect;
	m_ctlTab.GetClientRect(&rect);
	//창 생성,IDD가 없다면 resource.h 확인해볼것
	m_First.Create(IDD_FIRST, &m_ctlTab);
	//윈도우 화면창 설정..
	m_First.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_SHOWWINDOW | SWP_NOZORDER);
	//윈도우 핸들러로 컨트롤 전달
	m_pwndShow = &m_First;

	m_Second.Create(IDD_SECOND, &m_ctlTab);
	m_Second.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);

	//배경이미지 넣기
	CBitmap m_background;
	//m_background.LoadBitmapW();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


HBRUSH TrayIconSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	UINT nID = pWnd->GetDlgCtrlID();
	if (nID == IDC_GPBOX)
	{
		hbr = (HBRUSH)::GetSysColorBrush(COLOR_WINDOW);
		pDC->SetBkColor(RGB(255, 255, 255));
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL TrayIconSetting::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE))
	{
		pMsg->wParam = NULL;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
