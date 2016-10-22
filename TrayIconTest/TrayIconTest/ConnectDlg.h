#pragma once

#include "resource.h"
#include "CommThread.h"
#include "afxwin.h"
// ConnectDlg ��ȭ �����Դϴ�.

class ConnectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ConnectDlg)

public:
	ConnectDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ConnectDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CONNECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
