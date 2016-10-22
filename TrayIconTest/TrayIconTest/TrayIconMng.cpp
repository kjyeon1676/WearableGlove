#include "stdafx.h"
#include "TrayIconMng.h"
#include "TrayIconTest.h"
void CTrayIconMng::MakePopupMenu(HWND hWnd, int x, int y)
{
	//�˾��޴��� �����ϰ� �޴� ����
	HMENU hMenu = CreatePopupMenu();
	//AppendMenu�� .. nFlags,nIDNEWItem, lpszNewItem�ε�..
	//1.�� �޴� ���� ���¿� ���� ������ ����
	//2.�� �޴� �׸��� ��� ID�� ����..
	//�� �޴� �׸��� ������ ����..
	//if (m_bHide) //���̾�αװ� ������ ���¶��
	//{
	//	AppendMenu(hMenu, MF_STRING, WM_DIALOG_SHOW, _T("���̾�α� ���̱�"));
	//}
	//else
	//	AppendMenu(hMenu, MF_STRING, WM_DIALOG_SHOW, _T("���̾�α� ���߱�"));
	//SEPARATOR - ���� ���м��� �׸�.. ������ ������ �Ű� ������ ����
	//GRAYED - ������ �� ������ ��
	//ENABLED - �����ϰ� �帮�� ǥ�õ� ���¿��� ���� �� �� �ֵ���..
	//CHECKED - üũ�׸� �߰�.. �⺻ Ȯ�ζ��� �����ϵ��� ��.. 
	//UNCHECKED - Ȯ�� ǥ�ø� ����..
	if (m_bChecked) // ���۹�ư�� ���� ���¶��..
	{
		AppendMenu(hMenu, MF_CHECKED, WM_DIALOG_START, _T("��������"));
	}
	else
		AppendMenu(hMenu, MF_UNCHECKED, WM_DIALOG_START, _T("�������"));
	AppendMenu(hMenu, MF_STRING, WM_PORT_CONNECT, _T("��Ʈ����"));
	AppendMenu(hMenu, MF_SEPARATOR,WM_DIALOG_SHOW,_T("���α��м�"));
	AppendMenu(hMenu, MF_STRING, WM_EXPLAIN_DIALOG, _T("����"));
	AppendMenu(hMenu, MF_STRING, WM_DIALOG_SETTING, _T("����"));
	AppendMenu(hMenu, MF_STRING, WM_APP_EXIT, _T("����"));
	SetForegroundWindow(hWnd); //������ �˾��޴� ���� Ŭ���� �� �˾��ݱ�
	TrackPopupMenu(hMenu, TPM_LEFTALIGN + TPM_RIGHTBUTTON, x, y, 0, hWnd, NULL); //�˾� �޴� ����
}
void CTrayIconMng::ProcTrayMsg(HWND hWnd, WPARAM wParam, LPARAM IParam)
{
	HMENU hMenu = NULL;
	POINT pos;
	if (IParam == WM_RBUTTONDOWN)
	{
		GetCursorPos(&pos);
		MakePopupMenu(hWnd, pos.x, pos.y); //�˾� �޴� ���� �� ���
	}
}
BOOL CTrayIconMng::AddTrayIcon(HWND hWnd)
{
	if (m_bAdded) // �̹� Ʈ���̾������� �ִٸ� ����
		return FALSE;
	NOTIFYICONDATA nid; //������ ����ü ������ ����
	ZeroMemory(&nid, sizeof(NOTIFYICONDATA)); 
	nid.cbSize = sizeof(NOTIFYICONDATA); //������ ���
	nid.hWnd = hWnd; //�������� �θ� �� ������ �ڵ� ����
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP; // Ʈ���� �������� ���� ���
	nid.uCallbackMessage = WM_TRAYICON; //�޽��� ���..
	lstrcpy(nid.szTip, L"MagicGlove"); // ���� ���
	//sprintf((char*)nid.szTip, (char*)_T("TrayTest"));
	nid.uID = 0; //������ ���̵� ����
	nid.hIcon = theApp.LoadIconW(IDR_MAINFRAME); // ������ ��� ����

	if (Shell_NotifyIcon(NIM_ADD, &nid) == 0)//Ʈ���� ������ ǥ��
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
	if (Shell_NotifyIcon(NIM_DELETE, &nid) == 0) //Ʈ���̾����� ����
		return FALSE;
	return TRUE;
}
CTrayIconMng::CTrayIconMng()
{

}


CTrayIconMng::~CTrayIconMng()
{
}
