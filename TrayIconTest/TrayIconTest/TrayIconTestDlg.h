
// TrayIconTestDlg.h : 헤더 파일
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

// CTrayIconTestDlg 대화 상자
class TrayIconSetting;

class CTrayIconTestDlg : public CDialogEx
{
// 생성입니다.
public:
	CTrayIconTestDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	
// 대화 상자 데이터입니다.
	enum { IDD = IDD_TRAYICONTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//------------Comport 관련 변수들--------//
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
	//----------콤보박스 종류----------//
	CCommThread m_Comm;
	CComboBox m_PortBox;
	CComboBox m_BaudBox;
	//----------Thread 관련------------//
	CWinThread* pThread;
	CWinThread* qThread;
	void WatchThreadKill(void);
	int OnMessageProcess(void);
	int WatchPort(void);
	
	//----------Serial Comm 함수들------------//
	BOOL OpenPort(CString);
	LONG OnReceive(UINT port, LONG lParam);
	//----------TrayIcon 관련----------//
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
	//-----------Glove 제스처 관련-------------//
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

	//모니터 관련 필수 함수 // 꼭 잊지말껏
	CList<MONITORINFOEX, MONITORINFOEX&> Monitors;
	afx_msg LONG OnChangeDisplaySize(WPARAM wParam, LPARAM lParam);
	/*BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor,
	LPRECT lprcMonitor, LPARAM dwData);
	*/

	//모니터 관련 함수 끝



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