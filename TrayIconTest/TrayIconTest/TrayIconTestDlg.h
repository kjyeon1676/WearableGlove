
// TrayIconTestDlg.h : ��� ����
//

#pragma once
#include "TrayIconMng.h"
#include "TrayIconSetting.h"
#include "HookTest.h"
#include "ConnectDlg.h"
#include "GloveStatus.h"
#include "AirMove.h"
#include "MotionController.h"
#include "UIThread.h"
#include "ProgressDlg.h"
#include "EnvironmentStatus.h"
#include "afxwin.h"
#include "MotionHeader.h"
#include "ExplainDlg.h"

// CTrayIconTestDlg ��ȭ ����
class TrayIconSetting;

class CTrayIconTestDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTrayIconTestDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	
// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TRAYICONTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;
	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//------------Comport ���� ������--------//
	BOOL ConnectBtn;
	LONG Reg_Ret;
	DWORD Size = MAX_PATH;
	TCHAR i_str[MAX_PATH];
	CString save_Port[15];
	CString connectPort;
	HKEY h_CommKey;
	ConnectDlg *m_pConnect;
	CString strp;
	int m_ReceiveTimer;
	int m_ReceiveCheck;
	int m_QueueUse;
	int index;
	BOOL success_flag;
	//----------�޺��ڽ� ����----------//
	CCommThread m_Comm;
	CComboBox m_PortBox;
	CComboBox m_BaudBox;
	//----------Thread ����------------//
	CWinThread* pThread;
	CWinThread* qThread;
	void WatchThreadKill(void);
	int OnMessageProcess(void);
	int WatchPort(void);
	
	//----------Serial Comm �Լ���------------//
	BOOL OpenPort(CString);
	LONG OnReceive(UINT port, LONG lParam);
	//----------TrayIcon ����----------//
	CTrayIconMng m_myTray;
	TrayIconSetting *m_pChildDlg;
	CExplainDlg *m_pExplain;
	bool m_bHide;
	bool m_bChecked;
	bool m_hChecked;
	long OnTrayIcon(WPARAM wParam, LPARAM IParam);
	void OnAppExit(void);
	void OnConnect(void);
	void OnDialogSetting(void);
	void OnDialogShow(void);
	void OnDialogStart(void);
	void OnHookStart(void);
	void OnExplainShow(void);
	//----------hooking-----------------//
	void removeHook(void);
	BOOL InstallHook(void);
	//------------mouse Event---------------//
	int m_dragFlag;
	int Message_Flag;
	int posX, posY;
	int mouse_wheel_flag;
	//------------progress bar---------------//
	CProgressDlg *m_Prog;
	void setIndexNum();
	int getIndexNum();
	CUIThread *m_pThread;
	int m_transferIndex;
	int m_progress_flag;
	CProgressDlg *pProg;
	//-----------Glove ����ó ����-------------//
	MouseClick * mouseClick;
	MouseDClick * mouseDclick;
	MouseRClick  *mouseRClick;
	MouseWheel *mouseWheel;
	MouseDrag * mouseDrag;
	control_sensibility * controlS;

	KeyboardWinTab * keyboardWinTab;
	KeyboardLeftRight *keyboardLeftRight;
	executeExplorer * exeExplorer;
	ClearWindow * clearWindow;
	executeClose * exeClose;
	QuickBar *quickBar;

	EnvironmentStatus env;
	GloveStatus glove;
	MotionController * motionController;
	//MotionController *offController;
	//MotionController *onController;
	AirMove *airMove;
	CHookTest *m_hookTest;
	int mouseLClickFlag;
	int mouseWheelFlag;
	int windowKeyFlag;
	int windowPlusEFlag;
	int windowPlusMFlag;
	int AltPlusF4Flag;
	void CustomExcute();
	void AirCommandEx();
	//-----------------------------------------//

	//����� ���� �ʼ� �Լ� // �� ��������
	CList<MONITORINFOEX, MONITORINFOEX&> Monitors;
	afx_msg LONG OnChangeDisplaySize(WPARAM wParam, LPARAM lParam);
	/*BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor,
	LPRECT lprcMonitor, LPARAM dwData);
	*/

	//����� ���� �Լ� ��



public :
	afx_msg void OnClose();
//	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRawInput(UINT nInputcode, HRAWINPUT hRawInput);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedOk();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
};

void CALLBACK ReceiveEmpty(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD d2);
void CALLBACK timerConnectCheck(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD d2);
LRESULT CALLBACK GetMsgProcm(int nCode, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK GetMsgProck(int nCode, WPARAM wParam, LPARAM lParam);
static UINT SearchPort(LPVOID pParam);
static UINT Timeproc(LPVOID pParam);
static UINT ProcessGesture(LPVOID pParam);