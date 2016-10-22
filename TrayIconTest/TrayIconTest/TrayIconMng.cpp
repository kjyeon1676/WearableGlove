#include "stdafx.h"
#include "TrayIconMng.h"
#include "TrayIconTest.h"
void CTrayIconMng::MakePopupMenu(HWND hWnd, int x, int y)
{
	//팝업메뉴를 생성하고 메뉴 구성
	HMENU hMenu = CreatePopupMenu();
	//AppendMenu는 .. nFlags,nIDNEWItem, lpszNewItem인데..
	//1.새 메뉴 항의 상태에 대한 정보를 지정
	//2.새 메뉴 항목의 명령 ID를 지정..
	//새 메뉴 항목의 내용을 지정..
	//if (m_bHide) //다이얼로그가 감춰진 상태라면
	//{
	//	AppendMenu(hMenu, MF_STRING, WM_DIALOG_SHOW, _T("다이얼로그 보이기"));
	//}
	//else
	//	AppendMenu(hMenu, MF_STRING, WM_DIALOG_SHOW, _T("다이얼로그 감추기"));
	//SEPARATOR - 가로 구분선을 그림.. 어차피 나머지 매개 변수는 무시
	//GRAYED - 선택할 수 없도록 함
	//ENABLED - 선택하고 흐리게 표시된 상태에서 복원 할 수 있도록..
	//CHECKED - 체크항목 추가.. 기본 확인란을 선택하도록 함.. 
	//UNCHECKED - 확인 표시를 제거..
	if (m_bChecked) // 시작버튼을 누른 상태라면..
	{
		AppendMenu(hMenu, MF_CHECKED, WM_DIALOG_START, _T("제어종료"));
	}
	else
		AppendMenu(hMenu, MF_UNCHECKED, WM_DIALOG_START, _T("제어시작"));
	AppendMenu(hMenu, MF_STRING, WM_PORT_CONNECT, _T("포트설정"));
	AppendMenu(hMenu, MF_SEPARATOR,WM_DIALOG_SHOW,_T("가로구분선"));
	AppendMenu(hMenu, MF_STRING, WM_EXPLAIN_DIALOG, _T("설명서"));
	AppendMenu(hMenu, MF_STRING, WM_DIALOG_SETTING, _T("설정"));
	AppendMenu(hMenu, MF_STRING, WM_APP_EXIT, _T("종료"));
	SetForegroundWindow(hWnd); //생성된 팝업메뉴 밖을 클릭할 때 팝업닫기
	TrackPopupMenu(hMenu, TPM_LEFTALIGN + TPM_RIGHTBUTTON, x, y, 0, hWnd, NULL); //팝업 메뉴 띄우기
}
void CTrayIconMng::ProcTrayMsg(HWND hWnd, WPARAM wParam, LPARAM IParam)
{
	HMENU hMenu = NULL;
	POINT pos;
	if (IParam == WM_RBUTTONDOWN)
	{
		GetCursorPos(&pos);
		MakePopupMenu(hWnd, pos.x, pos.y); //팝업 메뉴 생성 및 출력
	}
}
BOOL CTrayIconMng::AddTrayIcon(HWND hWnd)
{
	if (m_bAdded) // 이미 트레이아이콘이 있다면 종료
		return FALSE;
	NOTIFYICONDATA nid; //아이콘 구조체 데이터 생성
	ZeroMemory(&nid, sizeof(NOTIFYICONDATA)); 
	nid.cbSize = sizeof(NOTIFYICONDATA); //사이즈 등록
	nid.hWnd = hWnd; //아이콘의 부모가 될 윈도우 핸들 정의
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP; // 트레이 아이콘의 형식 등록
	nid.uCallbackMessage = WM_TRAYICON; //메시지 등록..
	lstrcpy(nid.szTip, L"MagicGlove"); // 툴팁 등록
	//sprintf((char*)nid.szTip, (char*)_T("TrayTest"));
	nid.uID = 0; //아이콘 아이디값 정의
	nid.hIcon = theApp.LoadIconW(IDR_MAINFRAME); // 아이콘 모양 정의

	if (Shell_NotifyIcon(NIM_ADD, &nid) == 0)//트레이 아이콘 표시
		return FALSE;
	m_bAdded = true;
	return TRUE;
}
BOOL CTrayIconMng::DelTrayIcon(HWND hWnd)
{
	NOTIFYICONDATA nid;
	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = hWnd;
	nid.uFlags = NULL;
	if (Shell_NotifyIcon(NIM_DELETE, &nid) == 0) //트레이아이콘 삭제
		return FALSE;
	return TRUE;
}
CTrayIconMng::CTrayIconMng()
{

}


CTrayIconMng::~CTrayIconMng()
{
}
