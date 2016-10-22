#pragma once
#include "afxwin.h"
#include "resource.h"

// CHookTest 대화 상자입니다.

class CHookTest : public CDialogEx
{
	DECLARE_DYNAMIC(CHookTest)

public:
	CHookTest(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHookTest();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HOOKTEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
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
