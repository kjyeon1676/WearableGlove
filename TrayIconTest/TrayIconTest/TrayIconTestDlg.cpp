
// TrayIconTestDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "TrayIconTestDlg.h"
#include "TrayIconSetting.h"
#include "TrayIconMng.h"
#include "HookTest.h"
#include "mmsystem.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(lib,"winmm.lib")
#define TIMER 1234
#define TIMER_P 30
#define CONNECT_OK 2
#define CONNECT_FAIL 1
#define ATTEMPT_FULL 5
//mouse process Message//
#define MOUSE_MV 100
#define MOUSE_LCK 101
#define MOUSE_RCK 102
#define MOUSE_LDCK 103
#define MOUSE_WCK 104
#define MOUSE_DRAG 105


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

HHOOK m_keyhook = NULL;
HHOOK m_mhook = NULL;
BOOL Working = FALSE;
////////////////////
//--������������--//
////////////////////
int ConnectCheck = 0;
int flag = 0;
//int index = 0;
int m_nTimerID = 0;
int m_SearchPort_flag = 0;
/////////////////////

//����� ���� �Լ�
BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor,
	LPRECT lprcMonitor, LPARAM dwData)
{
	// ������ �����ϱ����ؼ� �ѱ� ����Ʈ�ڽ��� �ּҸ� ��밡���� ���·� ĳ�����Ѵ�.
	CTrayIconTestDlg* pMainDlg = (CTrayIconTestDlg*)::AfxGetMainWnd();
	// ����� ������ ������ ����ü
	MONITORINFOEX mi;
	mi.cbSize = sizeof(MONITORINFOEX);
	// ����� �ڵ��� ����Ͽ� �ش� ����� ������ �����´�.
	GetMonitorInfo(hMonitor, &mi);
	// �ָ���ͷ� ������ ����� ���������� üũ�Ѵ�.
	pMainDlg->Monitors.AddTail(mi);
	// ������ ����� ������ ����Ʈ�ڽ��� �߰��Ѵ�.
	return TRUE;
}
//����� ���� �Լ� ��

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTrayIconTestDlg ��ȭ ����



CTrayIconTestDlg::CTrayIconTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTrayIconTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ReceiveCheck = 0;
	success_flag = 0;
}

void CTrayIconTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTrayIconTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	//Communication Message Handler
	ON_MESSAGE(WM_COMM_READ, OnReceive)

	ON_MESSAGE(WM_TRAYICON, OnTrayIcon)
	ON_COMMAND(WM_APP_EXIT, OnAppExit)
	ON_COMMAND(WM_DIALOG_SHOW, OnDialogShow)
	ON_COMMAND(WM_DIALOG_SETTING, OnDialogSetting)
	ON_COMMAND(WM_DIALOG_START, OnDialogStart)
	ON_COMMAND(WM_PORT_CONNECT, OnConnect)
	ON_COMMAND(WM_EXPLAIN_DIALOG, OnExplainShow)
	ON_WM_CLOSE()

ON_WM_WINDOWPOSCHANGING()
ON_WM_MOUSEMOVE()
ON_WM_INPUT()
ON_WM_NCMOUSEMOVE()
ON_WM_TIMER()
ON_BN_CLICKED(IDOK, &CTrayIconTestDlg::OnBnClickedOk)
ON_WM_COPYDATA()
END_MESSAGE_MAP()


// CTrayIconTestDlg �޽��� ó����

BOOL CTrayIconTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.
	
	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�
	
	m_myTray.m_bHide = m_bHide;
	m_myTray.m_bChecked = m_bChecked;
	m_myTray.AddTrayIcon(GetSafeHwnd());
	
	
	///////////////////////////////////////////////////////////////////////
	
	MakedMotionFragments motionFragments;

	Motion * punchMotion = new Motion(env, glove, motionFragments.punchHand, motionFragments.strightHand);
	Motion * sideMode = new Motion(env, glove, motionFragments.sideMode);
	Motion * inverseMode = new Motion(env, glove, motionFragments.inverseMode);
	
	OffController *offController = new OffController(0, 0, 0, punchMotion);
	OnController *onController = new OnController(0, offController, 0, punchMotion);
	offController->registToggle(onController);
	offController->setMaster();
	onController->setMaster();
	onController->setOffController(offController);
	offController->setOnController(onController);
	motionController = offController;

	airMove = new AirMove(env, glove, motionFragments.normalMode);
	MotionController *airMoveController = new MotionController(onController, offController, airMove, punchMotion);
	onController->registMotion(1, airMoveController);

	MotionController * sideModeController = new MotionController(onController, offController, sideMode, punchMotion);
	onController->registMotion(2, sideModeController);

	MotionController  * inverseModeController = new MotionController(onController, offController, inverseMode, punchMotion);
	onController->registMotion(3, inverseModeController);


	//normalMode
	mouseClick = new MouseClick(env, glove, motionFragments.clickIndex);
	MotionController * mouseClickController = new MotionController(airMoveController, offController, mouseClick, punchMotion);
	airMoveController->registMotion(1, mouseClickController);

	mouseDclick = new MouseDClick(env, glove, motionFragments.clickIndexMiddle);
	MotionController * mouseDClickController = new MotionController(mouseClickController, offController, mouseDclick, punchMotion);
	mouseClickController->registMotion(1, mouseDClickController);

	mouseRClick = new MouseRClick(env, glove, motionFragments.clickMiddle);
	MotionController * mouseRClickController = new MotionController(airMoveController, offController, mouseRClick, punchMotion);
	airMoveController->registMotion(2, mouseRClickController);

	mouseWheel = new MouseWheel(env, glove, motionFragments.clickIndexMiddleRing);
	MotionController *mouseWheelController = new MotionController(airMoveController, offController, mouseWheel, punchMotion);
	airMoveController->registMotion(3, mouseWheelController);

	mouseDrag = new MouseDrag(env, glove, motionFragments.pressIndex);
	MotionController *mouseDragController = new MotionController(airMoveController, offController, mouseDrag, punchMotion);
	airMoveController->registMotion(4, mouseDragController);

	//�߰��Ȱ�
	controlS = new control_sensibility(env, glove, motionFragments.clickMiddleRing);
	MotionController *controlSensibility = new MotionController(airMoveController, offController, controlS, punchMotion);
	airMoveController->registMotion(5, controlSensibility);

	//sideMode
	keyboardWinTab = new KeyboardWinTab(env, glove, motionFragments.clickMiddle);
	MotionController *keyboardWinTabController = new MotionController(sideModeController, offController, keyboardWinTab, punchMotion);
	sideModeController->registMotion(1, keyboardWinTabController);

	keyboardLeftRight = new KeyboardLeftRight(env, glove, motionFragments.pressIndex);
	MotionController *keyboardLeftRightController = new MotionController(sideModeController, offController, keyboardLeftRight, punchMotion);
	sideModeController->registMotion(2, keyboardLeftRightController);


	/*quickBar = new QuickBar(env, glove, motionFragments.clickRing);
	MotionController *quickBarController = new MotionController(sideModeController, offController, quickBar, punchMotion);
	sideModeController->registMotion(3, quickBarController);
*/


	//inverseMode
	exeExplorer = new executeExplorer(env, glove, motionFragments.clickRing);
	MotionController *exeExplorerController = new MotionController(inverseModeController, offController, exeExplorer, punchMotion);
	inverseModeController->registMotion(1, exeExplorerController);

	clearWindow = new ClearWindow(env, glove, motionFragments.clickMiddle);
	MotionController *clearWindowController = new MotionController(inverseModeController, offController, clearWindow, punchMotion);
	inverseModeController->registMotion(2, clearWindowController);

	exeClose = new executeClose(env, glove, motionFragments.clickIndex);
	MotionController *exeCloseController = new MotionController(inverseModeController, offController, exeClose, punchMotion);
	inverseModeController->registMotion(3, exeCloseController);


	//port search
	WatchPort();
	//��Ƽ�� �ʱ� ����
	Monitors.RemoveAll();
	EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, NULL);
	env.setMonitors(&Monitors);
	//����� �ʱ� ���� ��
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}
//�����Ͱ� ���� �ð� �ȵ����� ���������.. -> ���ڽ� �ϳ� ���� ���� ����
void CTrayIconTestDlg::setIndexNum()
{
	m_transferIndex = index;
}
int CTrayIconTestDlg::getIndexNum()
{
	return m_transferIndex;
}
//-----------------Glove���� ���� �޽��� ó�� Thread--------------------------------//
static UINT ProcessGesture(LPVOID pParam)
{
	CTrayIconTestDlg *pClass = (CTrayIconTestDlg*)pParam;
	//��ǥ�� ó��.. ���
	CPoint pos;
	pClass->posX = pos.x;
	pClass->posY = pos.y;//��ǥ�� ����.
	//mouse �̵���
	pClass->Message_Flag = MOUSE_MV;
	//mouse ���� Ŭ����
	pClass->Message_Flag = MOUSE_LCK;
	//mouse ������ Ŭ����
	pClass->Message_Flag = MOUSE_RCK;
	//mouse ���� Ŭ��(����)
	pClass->Message_Flag = MOUSE_LDCK;
	//mouse �� ������
	pClass->Message_Flag = MOUSE_WCK;
	//mouse �巡��
	pClass->Message_Flag = MOUSE_DRAG;
	return pClass->Message_Flag;

}
void CALLBACK timerConnectCheck(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD d2)
{
	TRACE(_T("timer function\n"));
	BYTE temp;
	CTrayIconTestDlg *pDlg = (CTrayIconTestDlg*)dwUser;
	if (pDlg->m_Comm.m_QueueRead.GetSize() > 0)
	{
		pDlg->m_Comm.m_QueueRead.GetByte(&temp);
		if (temp == (BYTE)0xff)
		{
			pDlg->m_Comm.m_QueueRead.GetByte(&temp);
			if (temp == (BYTE)0x7f)
			{
				ConnectCheck = 2;
			}
		}
	}
	else
		ConnectCheck = 1;
}

void CALLBACK ReceiveEmpty(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD d2)
{
	TRACE(_T("timer function\n"));
	BYTE temp;
	CTrayIconTestDlg *pDlg = (CTrayIconTestDlg*)dwUser;
	pDlg->m_QueueUse++;
	if (pDlg->m_QueueUse > 10)
	{
		pDlg->m_ReceiveCheck = 2;
	}
	else
	{
		pDlg->m_ReceiveCheck = 1;
	}
}
////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------Class Function------------------------------------///
int CTrayIconTestDlg::OnMessageProcess(void)
{
	while (1)
	{
		qThread = AfxBeginThread(ProcessGesture, this);
		if (qThread == NULL)
		{
			MessageBox(_T("thread not create"));
			break;
		}
		else
		{
			//Thread���� ó���� ����ó Flag���� ���޵�.
			switch(Message_Flag)
			{
				//���콺 �̵���
			case MOUSE_MV:
				mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, posX, posY, 0, 0);
				break;
				//���콺 ���� Ŭ����
			case MOUSE_LCK:
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, posX, posY, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, posX, posY, 0, 0);
				break;
				//���콺 ������ Ŭ����
			case MOUSE_RCK:
				mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_ABSOLUTE, posX, posY, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP | MOUSEEVENTF_ABSOLUTE, posX, posY, 0, 0);
				break;
				//���콺 ���� Ŭ����
			case MOUSE_LDCK:
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, posX, posY, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, posX, posY, 0, 0);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, posX, posY, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, posX, posY, 0, 0);
				break;
				//���콺 �� ����
			case MOUSE_WCK:
				//���� ������ + 120
				//�Ʒ��� ������ -120				
				if (mouse_wheel_flag)//����
					mouse_event(MOUSEEVENTF_WHEEL, 0, 0, 120, 0);
				else
					mouse_event(MOUSEEVENTF_WHEEL, 0, 0, -120, 0);
				break;
			}
		}
	}
	return 1;
}
int CTrayIconTestDlg::WatchPort(void)
{
	m_Comm.hCommWnd = this->m_hWnd;
	Reg_Ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("HARDWARE\\DEVICEMAP\\SERIALCOMM"), 0, KEY_READ | KEY_QUERY_VALUE, &h_CommKey);
	if (Reg_Ret == ERROR_SUCCESS)
	{
		for (int i = 0; Reg_Ret == ERROR_SUCCESS; i++)
		{
			Reg_Ret = RegEnumValue(h_CommKey, i, i_str, &Size, NULL, NULL, NULL, NULL);
			if (Reg_Ret == ERROR_SUCCESS)
			{
				DWORD dwType, dwSize = MAX_PATH;
				TCHAR szBuffer[MAX_PATH];
				RegQueryValueEx(h_CommKey, i_str, 0, &dwType, (LPBYTE)szBuffer, &dwSize);
				//pClass->m_PortBox.AddString(szBuffer);  // ����Ʈ �ڽ��� ������Ʈ�� ���� �߰�(���⼭�� COM PORT)
				save_Port[index++] = szBuffer;
				//���� ������Ʈ�� ���� ���� �� ����.
			}
			Size = MAX_PATH;
		}
		m_SearchPort_flag = 1;
	}
	//������Ʈ��..

	RegCloseKey(h_CommKey);
	return 0;
}
void CTrayIconTestDlg::WatchThreadKill(void)
{
	CloseHandle(pThread->m_hThread);
	pThread->m_hThread = NULL;
}
BOOL CTrayIconTestDlg::OpenPort(CString port)
{
	CString str = port;
	int m_iTimer = 0;
	if (!m_Comm.m_bConnected)
	{
		//���� �ִ� port�� Open�� �Ѵ�.
		if (m_Comm.OpenPort(_T("\\\\.\\") + port, _T("115200"), _T("8"), _T("NO"), _T("NO"), _T("1")))
		{
			ConnectBtn = true;
			index = 0;
		}
		else
		{
			ConnectBtn = false;
			ConnectCheck = 0;
		}
	}
	return ConnectBtn;
}
LONG CTrayIconTestDlg::OnReceive(UINT port, LONG lParam)
{
	short packet[16] = { 0 };//��� ���� ���� ������

	CString str;
	BYTE temp;
	int size = (m_Comm.m_QueueRead).GetSize();
	if (size == 0) return 0;

#ifdef _DEBUG
	str.Format(_T(" Buffer : [%d/8000]\n"), size);
	TRACE(str);
#endif

	while (true)
	{
		if (size < 66)
		{
			return 0;
		}
		for (int i = 0; i < size; i++)
		{
			size--;
			(m_Comm.m_QueueRead).GetByte(&temp);
			if (temp == (BYTE)0xff)
			{
				size--;
				(m_Comm.m_QueueRead).GetByte(&temp);
				if (temp == (BYTE)0x7f)
				{
					break;
				}

			}
		}
		if (size < 32)
		{
			return 0;
		}
		
		m_QueueUse = 0;

		for (int i = 0; i < 32; i++)
		{
			(m_Comm.m_QueueRead).GetByte((BYTE*)(packet)+i);
		}
		if (flag<2)
			flag++;
		if (flag == 2)
		{
			ConnectCheck = 2;
			flag = 0;
		}
		GyroStatus &gyro = glove.getGyro();
		AccStatus &acc = glove.getAcc();
		MagStatus &mag = glove.getMag();
		BEND& bendThumb = glove.getBendThumb();
		BEND& bendFore = glove.getBendFore();
		BEND& bendMiddle = glove.getBendMiddle();
		BEND& bendRing = glove.getBendRing();
		BEND& bendLittle = glove.getBendLittle();
		PRESS& pressFore = glove.getPressFore();
		PRESS& pressMiddle = glove.getPressMiddle();


		gyro.inputData(packet[13], packet[14], packet[15]);
		acc.inputData(packet[10], packet[11], packet[12]);
		mag.inputData(packet[7], packet[8], packet[9]);
		bendLittle.inputData(packet[6]);
		bendRing.inputData(packet[5]);
		bendMiddle.inputData(packet[4]);
		pressMiddle.inputData(packet[3]);
		bendFore.inputData(packet[2]);
		pressFore.inputData(packet[1]);
		bendThumb.inputData(packet[0]);

		motionController = motionController->action(); // 
#ifdef _DEBUG
		CString str;
		str.Format(_T("%d"), motionController);
		TRACE(str);
#endif
		//		checkStatus();
		size -= 32;
	}
	//timeSetEvent()

	return 0;


}
void CTrayIconTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTrayIconTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.

HCURSOR CTrayIconTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//Ʈ���� �������� Ŭ������ ���� �޽��� �ڵ鷯
long CTrayIconTestDlg::OnTrayIcon(WPARAM wParam, LPARAM IParam)
{
	m_myTray.ProcTrayMsg(GetSafeHwnd(), wParam, IParam);
	return 0;
}
//Ʈ���� ������ �˾��޴��� ���� �޴� �޽��� �ڵ鷯
void CTrayIconTestDlg::OnAppExit(void)
{
	m_myTray.DelTrayIcon(GetSafeHwnd());
	CWnd *handle = NULL;
	handle = CWnd::FindWindow(_T("WindowsForms10.Window.8.app.0.2bf8098_r11_ad1"), NULL);
	if (handle == NULL)
	{
		CDialog::OnCancel();
	}
	else
	{
		handle->SendMessage(WM_CLOSE, 0, 0);
		CDialog::OnCancel();
	}
}
//Ʈ���� ������ ���̱�/����� �޴� �޽��� �ڵ鷯
void CTrayIconTestDlg::OnDialogShow(void)
{
	if (!m_bHide) ShowWindow(false); //���̴� ���¶�� �����
	else ShowWindow(true); //������ ���¶�� ���̰�
	m_bHide = !m_bHide;
	m_myTray.m_bHide = m_bHide;
}

// ���̾�α� ���� �޴�
void CTrayIconTestDlg::OnDialogSetting(void) 
{
	if (m_pChildDlg == NULL)
	{
		m_pChildDlg = new TrayIconSetting;
		m_pChildDlg->Create(TrayIconSetting::IDD, this);
		m_pChildDlg->ShowWindow(SW_SHOW);
	}
	else
	{
		m_pChildDlg->ShowWindow(SW_SHOW);
	}
}
void CTrayIconTestDlg::OnHookStart(void)
{
	if (m_hChecked) // üũ �����̸� ����
	{
		m_hChecked = false;
		//UnhookWindowsHookEx(m_mhook);
		m_hookTest->ShowWindow(SW_HIDE);
	}
	else
	{
		if (m_hookTest == NULL)
		{
			m_hookTest = new CHookTest;
			m_hookTest->DoModal();
			//m_hookTest->Create(CHookTest::IDD, this);
			//m_hookTest->ShowWindow(SW_SHOW);
			m_hChecked = true;
			//-------------hook process install---------------//
		}
		else
			m_hookTest->ShowWindow(SW_SHOW);
	}
	m_myTray.m_hChecked = m_hChecked;
}
void CTrayIconTestDlg::OnExplainShow(void)
{
	/*if (m_pExplain == NULL)
	{
		m_pExplain = new CExplainDlg;
		m_pExplain->Create(CExplainDlg::IDD, this);
		m_pExplain->ShowWindow(SW_SHOW);
	}
	else
	{
		m_pExplain->ShowWindow(SW_SHOW);
	}*/
	SHELLEXECUTEINFO ExeInfo;
	ZeroMemory(&ExeInfo, sizeof(ExeInfo));
	ExeInfo.cbSize = sizeof(ExeInfo);
	ExeInfo.lpVerb = _T("open");
	ExeInfo.lpFile = _T("C:\\Users\\mango.DGSSM\\Desktop\\TrayIconTest\\TrayIconTest\\ExplainGlove.exe");
	ExeInfo.fMask = SEE_MASK_FLAG_NO_UI | SEE_MASK_NOCLOSEPROCESS;
	ExeInfo.nShow = SW_SHOW;
	::ShellExecuteEx(&ExeInfo);
}
void CTrayIconTestDlg::OnConnect(void)
{
	if (m_pConnect == NULL)
	{
		m_pConnect = new ConnectDlg;
		m_pConnect->Create(ConnectDlg::IDD, this);
		m_pConnect->ShowWindow(SW_SHOW);
	}
	else
	{
		m_pConnect->ShowWindow(SW_SHOW);
	}
}
//���̾�α� ���۹�ư üũ / üũ���� �޽��� �ڵ鷯
void CTrayIconTestDlg::OnDialogStart(void)
{
	if (m_bChecked) // üũ�����̸� �����
	{
		m_bChecked = false;
		//���� ����� port ���� �� ��������
		if (m_Comm.m_bConnected)
			m_Comm.ClosePort();
		//AfxBeginThread�� �����带 �������� ��� closehandle ���� �ʿ䰡 ����..
		//WatchThreadKill();
		//removeHook();
	}
	else
	{
		//WatchPort();
		
		//int width = GetSystemMetrics(SM_CXSCREEN);
		//int height = GetSystemMetrics(SM_CYSCREEN);
		//m_pConnect->SetWindowPos(NULL,0, 0, width / 2, height / 2,SWP_NOSIZE);
		//���� ����
		//������Ʈ�� �߰��κ�--Thread�� ���� Port ����----------------------//
		//Sleep(2000);
		//m_pThread = new CUIThread();
		//m_pThread->CreateThread();
		//while (m_progress_flag == 0);
		//setIndexNum();
		//WatchPort();
		/*while (1)
		{*/
			//if (!OpenPort(strp)) //���� ���н�
			//{
			//	MessageBox(_T("Connect Fail!"));
			//	m_bChecked = false;
			//}
			//else
			//{
			//	//OnMessageProcess();
			//	MessageBox(_T("Connect Success!!"));
			//	m_bChecked = true;
			//	TRACE(_T("ddddddd"));
			//}

			//	//WatchThreadKill();
			//	m_bChecked = true;
			//	//break;
			//}
		//}
		//while (m_SearchPort_flag == 0);
		
		//m_pThread->PostThreadMessage(WM_QUIT, 0, 0);
	}
	//m_bChecked = !m_bChecked;
	m_myTray.m_bChecked = m_bChecked;
	//env.setTrayStatus(&m_myTray);
}
void CTrayIconTestDlg::AirCommandEx()
{
	SHELLEXECUTEINFO ExeInfo;
	ZeroMemory(&ExeInfo, sizeof(ExeInfo));
	ExeInfo.cbSize = sizeof(ExeInfo);
	ExeInfo.lpVerb = _T("open");
	ExeInfo.lpFile = _T("C:\\Users\\mango.DGSSM\\Desktop\\TrayIconTest\\TrayIconTest\\AirCommand.exe");
	ExeInfo.fMask = SEE_MASK_FLAG_NO_UI | SEE_MASK_NOCLOSEPROCESS;
	ExeInfo.nShow = SW_SHOW;
	::ShellExecuteEx(&ExeInfo);
}
void CTrayIconTestDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	ShowWindow(SW_HIDE);
	//CDialogEx::OnClose();
}
void CTrayIconTestDlg::removeHook()
{
	UnhookWindowsHookEx(m_keyhook);
	UnhookWindowsHookEx(m_mhook);
}

BOOL CTrayIconTestDlg::InstallHook()
{
	bool hCheck = false;
	m_mhook = SetWindowsHookEx(WH_MOUSE_LL, GetMsgProcm, theApp.m_hInstance, NULL);
	m_keyhook = SetWindowsHookEx(WH_KEYBOARD_LL, GetMsgProck, theApp.m_hInstance, NULL);
	if (!m_mhook && !m_keyhook)
	{
		MessageBox(_T("Hook install fail"));
		return false;
	}
	return true;
}
LRESULT CALLBACK GetMsgProck(int nCode, WPARAM wParam, LPARAM lParam)
{
	static int c = 0;
	KBDLLHOOKSTRUCT *pKey = (KBDLLHOOKSTRUCT *)lParam;

	CTrayIconTestDlg* pMainDlg = (CTrayIconTestDlg*)::AfxGetMainWnd();

	if (nCode < 0)
		return CallNextHookEx(m_keyhook, nCode, wParam, lParam);


	CString str;

	return CallNextHookEx(m_keyhook, nCode, wParam, lParam);
}
//Mouse Hooking , lParam�� ��ġ����, wParam�� � �߻�����.. lParam�� Long��
LRESULT CALLBACK GetMsgProcm(int nCode, WPARAM wParam, LPARAM lParam)
{
	static int c = 0;
	KBDLLHOOKSTRUCT *pKey = (KBDLLHOOKSTRUCT *)lParam;

	CTrayIconTestDlg* pMainDlg = (CTrayIconTestDlg*)::AfxGetMainWnd();

	if (nCode < 0)
		return CallNextHookEx(m_mhook, nCode, wParam, lParam);
	//  MOUSEEVENTF_MOVE - mouse move
	//  MOUSEEVENTF_LEFTDOWN - left button down
	//	MOUSEEVENTF_LEFTUP - left button up
	//	MOUSEEVENTF_RIGHTDOWN - right button down
	//	MOUSEEVENTF_RIGHTUP - right button up
	//	MOUSEEVENTF_MIDDLEDOWN - middle button down
	//	MOUSEEVENTF_MIDDLEUP - middle button up
	//	MOUSEEVENTF_WHEEL - wheel button rolled
	//	MOUSEEVENTF_ABSOLUTE - absolute move

	////���콺 Ư�� ��ġ���� �巡��
	//mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	//SetCursorPos(pos.x, pos.y);
	//mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	////���콺 �� ������, 1000��ŭ �����̸� ..
	//mouse_event(MOUSEEVENTF_HWHEEL, 0, 0, 1000, 0);
	return CallNextHookEx(m_mhook, nCode, wParam, lParam);
}

inline void chgMotion(Motion * a, Motion * b){
	MotionFragment * tmp = a->getStartMotion();
	MotionFragment * tmp2 = b->getStartMotion();
	b->setStartMotion(tmp);
	a->setStartMotion(tmp2);

	tmp = a->getEndMotion();
	tmp2 = b->getEndMotion();

	b->setEndMotion(tmp);
	a->setEndMotion(tmp2);
}
void CTrayIconTestDlg::CustomExcute()
{
	//�ϴ� mouseLclick..
	
	MotionFragment *tempMotion;
	MotionFragment *tempMotion2;
	if (mouseLClickFlag == 1) //���콺 �� Ŭ�� ����
	{
		chgMotion(mouseClick, mouseRClick);
	}
	// mouseWheel 
	if (mouseWheelFlag == 1)
	{
		chgMotion(mouseWheel, mouseDrag);
	}
	//alt + f4
	if (AltPlusF4Flag == 1)//window + E
	{
		chgMotion(exeExplorer, exeClose);
	}
	else if (AltPlusF4Flag == 2) //window + M
	{
		chgMotion(exeClose, clearWindow);
	}
	//windowKey + e
	if (windowPlusEFlag == 1) //window + M
	{
		chgMotion(exeExplorer, clearWindow);
	}
	else if (windowPlusEFlag == 2) //Alt+f4
	{
		chgMotion(exeClose, exeExplorer);
	}

	//window+ M
	if (windowPlusMFlag == 1) //window + E
	{
		chgMotion(clearWindow, exeExplorer);
	}
	else if (windowPlusMFlag == 2) // alt + f4
	{
		chgMotion(exeClose, clearWindow);
	}
}

void CTrayIconTestDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	lpwndpos->flags &= ~SWP_SHOWWINDOW;
	CDialogEx::OnWindowPosChanging(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


//BOOL CTrayIconTestDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	m_pChildDlg->m_Cnt++;
//	UpdateData(false);
//	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
//}

void CTrayIconTestDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CPoint pos;
	::GetCursorPos(&pos); //Ŀ���� ��ġ�� �о���� �Լ�.. pos�� ���� �ְ� ��.. 0�� �ƴ� ���� ����..
	CString str;
	str.Format(_T("%d"), pos.x);
	//CFirst temp;
	//temp.xPos.SetWindowTextW(str);
	//this->tempX.SetWindowText(str);
	CDialogEx::OnMouseMove(nFlags, point);
}


void CTrayIconTestDlg::OnRawInput(UINT nInputcode, HRAWINPUT hRawInput)
{
	// �� ����� ����Ϸ��� Windows XP �̻��� �ʿ��մϴ�.
	// _WIN32_WINNT ��ȣ�� 0x0501���� ũ�ų� ���ƾ� �մϴ�.
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	//::GetCursorPos(&pos);
	//CString str;
	//str.Format(_T("%d"), pos.x);
	////this->tempX.SetWindowText(str);
	//CDialogEx::OnRawInput(nInputcode, hRawInput);
}


void CTrayIconTestDlg::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CPoint pos;
	::GetCursorPos(&pos);
	CString str;
	str.Format(_T("%d"), point.x);
	//this->tempX.SetWindowText(str);

	CDialogEx::OnNcMouseMove(nHitTest, point);
}

void CTrayIconTestDlg::OnTimer(UINT nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CDialogEx::OnTimer(nIDEvent);
}


void CTrayIconTestDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}


BOOL CTrayIconTestDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
}
