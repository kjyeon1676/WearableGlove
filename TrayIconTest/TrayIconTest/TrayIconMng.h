#pragma once
class CTrayIconMng
{
public:
	bool m_bAdded; // Ʈ���̾������� �����Ǿ����� ���� (Ture : ����)
	bool m_bHide; // ���̾�αװ� ������ �������� ����
	bool m_bChecked; // ���̾�α� ����üũ��ư Ȯ�� ����..
	bool m_hChecked; //hooking check ����..
	void MakePopupMenu(HWND hWnd, int x, int y); //�˾� �޴� ����
	void ProcTrayMsg(HWND hWnd, WPARAM wParam, LPARAM IParam); //�˾� �޴��� �̺�Ʈ �߻��� ó���Լ�
	BOOL AddTrayIcon(HWND hWnd); // Ʈ���̾����� ����
	BOOL DelTrayIcon(HWND hWnd); //Ʈ���̾����� ����
	
	CTrayIconMng();
	~CTrayIconMng();
};
