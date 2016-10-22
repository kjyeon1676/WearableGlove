// Second.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "resource.h"
#include "TrayIconTest.h"
#include "TrayIconTestDlg.h"
#include "Second.h"
#include "afxdialogex.h"

// CSecond 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSecond, CDialogEx)

CSecond::CSecond(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSecond::IDD, pParent)
{

}

CSecond::~CSecond()
{
}

void CSecond::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_MOUSELCLICK, m_mouseLClick);
	DDX_Control(pDX, IDC_MOUSEWHEEL, m_mouseWheel);
	DDX_Control(pDX, IDC_KEYBDALTF4, m_keybdAltF4);
	DDX_Control(pDX, IDC_KEYBDWINKEYE, m_keybdWinKeyE);
	DDX_Control(pDX, IDC_KEYBDWINKEYM, m_keybdWinkeyM);
}


BEGIN_MESSAGE_MAP(CSecond, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_CUSTOMOK, &CSecond::OnBnClickedCustomok)
	ON_BN_CLICKED(IDC_CUSTOMCAN, &CSecond::OnBnClickedCustomcan)
END_MESSAGE_MAP()


// CSecond 메시지 처리기입니다.


BOOL CSecond::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 255));
	//return CDialogEx::OnEraseBkgnd(pDC);
	return TRUE;
}

BOOL CSecond::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_mouseLClick.AddString(_T("마우스 우클릭"));

	m_mouseWheel.AddString(_T("마우스 드래그"));

	m_keybdAltF4.AddString(_T("Winkey+E"));
	m_keybdAltF4.AddString(_T("Winkey+M"));

	m_keybdWinKeyE.AddString(_T("Winkey+M"));
	m_keybdWinKeyE.AddString(_T("Alt+F4"));

	m_keybdWinkeyM.AddString(_T("WinKey+E"));
	m_keybdWinkeyM.AddString(_T("Alt+F4"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSecond::OnBnClickedCustomok()
{
	CTrayIconTestDlg *pParent = (CTrayIconTestDlg*)AfxGetMainWnd();

	int mouseLClickIndex = 0;
	int mouseWheelClickIndex = 0;
	int windowKeyIndex = 0;
	int Altf4index = 0;
	int windowKeyPlusE = 0;
	int windowKeyPlusM = 0;

	mouseLClickIndex = m_mouseLClick.GetCurSel();
	mouseWheelClickIndex = m_mouseWheel.GetCurSel();
	Altf4index = m_keybdAltF4.GetCurSel();
	windowKeyPlusE = m_keybdWinKeyE.GetCurSel();
	windowKeyPlusM = m_keybdWinkeyM.GetCurSel();

	//마우스 왼쪽 클릭 해당하는 index
	if (mouseLClickIndex == 0)
	{
		pParent->mouseLClickFlag = 1;
	}
	//마우스 휠 해당하는 index
	if (mouseWheelClickIndex == 0)
	{
		pParent->mouseWheelFlag = 1;
	}
	//windowkey+e 가 winkey+M이면
	if (windowKeyPlusE == 0)
	{
		if (Altf4index != 2)
		{
			if (windowKeyPlusM != 0)
			{
				pParent->windowPlusEFlag = 1; //winkey+M으로
			}
		}
		else
		{
			MessageBox(_T("Alt+F4와 겹치는 부분 발견!"), _T("오류"));
		}
	}
	else if (windowKeyPlusE == 1) //alt+f4이면
	{
		if (Altf4index != 0)
		{
			if (windowKeyPlusM != 2)
			{
				pParent->windowPlusEFlag = 2; //Alt+f4로
			}
		}
	}

	if (windowKeyPlusM == 0) //winkey+e이면
	{
		if (windowKeyPlusE != 0)
		{
			if (Altf4index != 0)
			{
				pParent->windowPlusMFlag = 1; //winKey+E로 보내자
			}
		}
	}
	else if (windowKeyPlusM == 1) //alt+F4이면
	{
		if (windowKeyPlusE != 2)
		{
			if (Altf4index != 1)
			{
				pParent->windowPlusMFlag = 2; //alt+f4로 보내자
			}
		}
	}

	if (Altf4index == 0)//windowkey + E이면
	{
		if (windowKeyPlusE != 2)
		{
			if (windowKeyPlusM != 0)
			{
				pParent->AltPlusF4Flag = 1; //windowKey+e;
			}
		}
	}
	else if (Altf4index == 1)//windowKey+M이면
	{
		if (windowKeyPlusE != 0)
		{
			if (windowKeyPlusM != 2)
			{
				pParent->AltPlusF4Flag = 2; //windowKey+m;
			}
		}
	}
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(_T("적용완료"), _T("정보"));
	pParent->CustomExcute();
}


void CSecond::OnBnClickedCustomcan()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_mouseLClick.ResetContent();
	m_mouseWheel.ResetContent();
	m_keybdAltF4.ResetContent();
	m_keybdWinKeyE.ResetContent();
	m_keybdWinkeyM.ResetContent();
}
