#pragma once
#include "afxwin.h"
#include "resource.h"

// CHookTest ��ȭ �����Դϴ�.

class CHookTest : public CDialogEx
{
	DECLARE_DYNAMIC(CHookTest)

public:
	CHookTest(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHookTest();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HOOKTEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	HICON m_hIcon;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	CStatic CXpos;
	CStatic CYpos;
//	afx_msg void OnPaint();
//	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnRawInput(UINT nInputcode, HRAWINPUT hRawInput);
	afx_msg void OnMouseLeave();
};
