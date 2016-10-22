#pragma once
#include "afxwin.h"
#include "resource.h"
// CExplainDlg 대화 상자입니다.

class CExplainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExplainDlg)

public:
	CExplainDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExplainDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EXPLAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	//CBitmap Button
public:
	CStatic m_startText;
	CFont m_font;
	afx_msg void OnStnClickedStartsettext();
	CBitmapButton m_StartExplainBtn;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedStartexpbtn();
};
