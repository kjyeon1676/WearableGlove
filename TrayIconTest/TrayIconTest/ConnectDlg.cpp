// ConnectDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "ConnectDlg.h"
#include "TrayIconMng.h"
#include "TrayIconTestDlg.h"
#include "afxdialogex.h"
// ConnectDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(ConnectDlg, CDialogEx)

ConnectDlg::ConnectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ConnectDlg::IDD, pParent)
{

}

ConnectDlg::~ConnectDlg()
{
}

void ConnectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	/*DDX_Control(pDX, IDC_PORTBOX, m_PortBox);
	DDX_Control(pDX, IDC_BAUDBOX, m_BaudBox);*/
	DDX_Control(pDX, IDC_CONNECTBTN, m_ConnectBtn);
	DDX_Control(pDX, IDC_PORTBOX, m_combo);
}


BEGIN_MESSAGE_MAP(ConnectDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CONNECTBTN, &ConnectDlg::OnBnClickedConnectbtn)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_CNTCANCLE, &ConnectDlg::OnBnClickedCntcancle)
END_MESSAGE_MAP()


// ConnectDlg �޽��� ó�����Դϴ�.

void ConnectDlg::getSerialPort()
{
	HKEY hKey;
	RegOpenKey(HKEY_LOCAL_MACHINE, _T("HARDWARE\\DEVICEMAP\\SERIALCOMM"), &hKey);
	TCHAR szData[20], szName[100],devName[100];
	DWORD index = 0, dwSize = 100, dwSize2 = 20, dwType = REG_SZ;
	memset(szData, 0, sizeof(szData));
	memset(szName, 0, sizeof(szName));
	memset(devName, 0, sizeof(devName));
	while (ERROR_SUCCESS == RegEnumValue(hKey, index, szName, &dwSize, NULL, NULL, NULL, NULL))
	{
		index++;
		RegQueryValueEx(hKey, szName, NULL, &dwType, (LPBYTE)szData, &dwSize2);
		for (int i = 8; szName[i] != NULL; i++)
			devName[i-8] = szName[i];
		m_combo.AddString(CString(devName) + "-"+CString(szData));
		memset(szData, 0, sizeof(szData));
		memset(szName, 0, sizeof(szName));
		dwSize = 100;
		dwSize2 = 20;
	}
	RegCloseKey(hKey);
}
void ConnectDlg::OnBnClickedConnectbtn()
{
		// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strb,strp;
	CString strTok;
	CTrayIconTestDlg *m_parent = (CTrayIconTestDlg*)AfxGetMainWnd();
	this->m_ConnectBtn.GetWindowText(strb);
	if (strb == _T("����"))
	{
		this->m_combo.GetWindowText(strp);
		if (strp == _T(""))
		{
			MessageBox(_T("��Ʈ�� �����ϼ���"), _T("���"));
			return;
		}
		if (!m_parent->m_Comm.m_bConnected)
		{
			m_parent->strp = strp;
			int nIndex = strp.Find('-');
			strTok = strp.Right(4);
			if (m_parent->OpenPort(strTok))
			{
				//MessageBox(_T("Connect success!"));
				m_parent->m_myTray.m_bChecked = true;
				this->m_ConnectBtn.SetWindowText(_T("����"));
			}
		}
	}
	else
	{
		if (m_parent->m_Comm.m_bConnected) // comport�� �����ϸ�
		{
			m_parent->m_Comm.ClosePort();
			m_parent->m_myTray.m_bChecked = false;
			this->m_ConnectBtn.SetWindowTextW(_T("����"));
		}
	}
	
}
BOOL ConnectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CTrayIconTestDlg *m_parent = (CTrayIconTestDlg*)AfxGetMainWnd();
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	getSerialPort();
	//this->SetWindowPos(NULL, 0, 0, width/2, height/2, SWP_NOSIZE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BOOL ConnectDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 255));
	//return CDialogEx::OnEraseBkgnd(pDC);
	return TRUE;
}


void ConnectDlg::OnBnClickedCntcancle()
{
	this->ShowWindow(SW_HIDE);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
