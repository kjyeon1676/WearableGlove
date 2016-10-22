#pragma once
class CTrayIconMng
{
public:
	bool m_bAdded; // 트레이아이콘이 생성되었는지 여부 (Ture : 생성)
	bool m_bHide; // 다이얼로그가 감춰진 상태인지 여부
	bool m_bChecked; // 다이얼로그 시작체크버튼 확인 여부..
	bool m_hChecked; //hooking check 여부..
	void MakePopupMenu(HWND hWnd, int x, int y); //팝업 메뉴 생성
	void ProcTrayMsg(HWND hWnd, WPARAM wParam, LPARAM IParam); //팝업 메뉴의 이벤트 발생시 처리함수
	BOOL AddTrayIcon(HWND hWnd); // 트레이아이콘 생성
	BOOL DelTrayIcon(HWND hWnd); //트레이아이콘 제거
	
	CTrayIconMng();
	~CTrayIconMng();
};
