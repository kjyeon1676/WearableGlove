#pragma once
#include "afxwin.h"
#include "resource.h"
// CExplainDlg ��ȭ �����Դϴ�.

class CExplainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExplainDlg)

public:
	CExplainDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExplainDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EXPLAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
