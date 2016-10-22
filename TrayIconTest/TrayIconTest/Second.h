#pragma once

#include "resource.h"
#include "afxwin.h"
// CSecond 대화 상자입니다.

class CSecond : public CDialogEx
{
	DECLARE_DYNAMIC(CSecond)

public:
	CSecond(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSecond();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SECOND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
