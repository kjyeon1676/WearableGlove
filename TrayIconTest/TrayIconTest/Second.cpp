// Second.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "resource.h"
#include "TrayIconTest.h"
#include "TrayIconTestDlg.h"
#include "Second.h"
#include "afxdialogex.h"

// CSecond ��ȭ �����Դϴ�.

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


// CSecond �޽��� ó�����Դϴ�.


BOOL CSecond::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 255));
	//return CDialogEx::OnEraseBkgnd(pDC);
	return TRUE;
}

BOOL CSecond::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_mouseLClick.AddString(_T("���콺 ��Ŭ��"));

	m_mouseWheel.AddString(_T("���콺 �巡��"));

	m_keybdAltF4.AddString(_T("Winkey+E"));
	m_keybdAltF4.AddString(_T("Winkey+M"));

	m_keybdWinKeyE.AddString(_T("Winkey+M"));
	m_keybdWinKeyE.AddString(_T("Alt+F4"));

	m_keybdWinkeyM.AddString(_T("WinKey+E"));
	m_keybdWinkeyM.AddString(_T("Alt+F4"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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

	//���콺 ���� Ŭ�� �ش��ϴ� index
	if (mouseLClickIndex == 0)
	{
		pParent->mouseLClickFlag = 1;
	}
	//���콺 �� �ش��ϴ� index
	if (mouseWheelClickIndex == 0)
	{
		pParent->mouseWheelFlag = 1;
	}
	//windowkey+e �� winkey+M�̸�
	if (windowKeyPlusE == 0)
	{
		if (Altf4index != 2)
		{
			if (windowKeyPlusM != 0)
			{
				pParent->windowPlusEFlag = 1; //winkey+M����
			}
		}
		else
		{
			MessageBox(_T("Alt+F4�� ��ġ�� �κ� �߰�!"), _T("����"));
		}
	}
	else if (windowKeyPlusE == 1) //alt+f4�̸�
	{
		if (Altf4index != 0)
		{
			if (windowKeyPlusM != 2)
			{
				pParent->windowPlusEFlag = 2; //Alt+f4��
			}
		}
	}

	if (windowKeyPlusM == 0) //winkey+e�̸�
	{
		if (windowKeyPlusE != 0)
		{
			if (Altf4index != 0)
			{
				pParent->windowPlusMFlag = 1; //winKey+E�� ������
			}
		}
	}
	else if (windowKeyPlusM == 1) //alt+F4�̸�
	{
		if (windowKeyPlusE != 2)
		{
			if (Altf4index != 1)
			{
				pParent->windowPlusMFlag = 2; //alt+f4�� ������
			}
		}
	}

	if (Altf4index == 0)//windowkey + E�̸�
	{
		if (windowKeyPlusE != 2)
		{
			if (windowKeyPlusM != 0)
			{
				pParent->AltPlusF4Flag = 1; //windowKey+e;
			}
		}
	}
	else if (Altf4index == 1)//windowKey+M�̸�
	{
		if (windowKeyPlusE != 0)
		{
			if (windowKeyPlusM != 2)
			{
				pParent->AltPlusF4Flag = 2; //windowKey+m;
			}
		}
	}
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	MessageBox(_T("����Ϸ�"), _T("����"));
	pParent->CustomExcute();
}


void CSecond::OnBnClickedCustomcan()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_mouseLClick.ResetContent();
	m_mouseWheel.ResetContent();
	m_keybdAltF4.ResetContent();
	m_keybdWinKeyE.ResetContent();
	m_keybdWinkeyM.ResetContent();
}
