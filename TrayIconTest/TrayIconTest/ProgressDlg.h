#pragma once

#include "resource.h"
#include "afxcmn.h"
// CProgressDlg 대화 상자입니다.

class CProgressDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProgressDlg)

public:
	CProgressDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CProgressDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_ctlProg;

	virtual BOOL OnInitDialog();
};
