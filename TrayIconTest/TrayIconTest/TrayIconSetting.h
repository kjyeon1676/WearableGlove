#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "First.h"
#include "Second.h"
#include "ExplainDlg.h"

// TrayIconSetting 대화 상자입니다.

class TrayIconSetting : public CDialogEx
{
	DECLARE_DYNAMIC(TrayIconSetting)

public:
	TrayIconSetting(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~TrayIconSetting();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TRAYICONSETTING };
	CFirst m_First;
	CSecond m_Second;

	CWnd* m_pwndShow;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void OninitTabControl();

	CTabCtrl m_ctlTab;
	CBrush m_brCheck;

	CImageList *pSysSmall;
	CImageList *pSysLarge;

	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
