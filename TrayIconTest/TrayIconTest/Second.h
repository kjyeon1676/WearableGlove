#pragma once

#include "resource.h"
#include "afxwin.h"
// CSecond ��ȭ �����Դϴ�.

class CSecond : public CDialogEx
{
	DECLARE_DYNAMIC(CSecond)

public:
	CSecond(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSecond();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SECOND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	void setCustomFlag();
	CComboBox m_mouseLClick;
	CComboBox m_mouseWheel;
	CComboBox m_keybdWinkey;
	CComboBox m_keybdAltF4;
	CComboBox m_keybdWinKeyE;
	CComboBox m_keybdWinkeyM;
	afx_msg void OnBnClickedCustomok();
	afx_msg void OnBnClickedCustomcan();
};
