#pragma once

#include "resource.h"
#include "afxcmn.h"
// CProgressDlg ��ȭ �����Դϴ�.

class CProgressDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProgressDlg)

public:
	CProgressDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CProgressDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_ctlProg;

	virtual BOOL OnInitDialog();
};
