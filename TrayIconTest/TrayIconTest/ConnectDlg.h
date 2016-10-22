#pragma once

#include "resource.h"
#include "CommThread.h"
#include "afxwin.h"
// ConnectDlg 대화 상자입니다.

class ConnectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ConnectDlg)

public:
	ConnectDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ConnectDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CONNECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConnectbtn();
	CButton m_ConnectBtn;

	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CComboBox m_combo;
	void getSerialPort();
	afx_msg void OnBnClickedCntcancle();
};
