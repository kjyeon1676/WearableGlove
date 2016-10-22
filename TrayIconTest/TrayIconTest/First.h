#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"
#include "First.h"
#include "Second.h"

// CFirst 대화 상자입니다.

class CFirst : public CDialogEx
{
	DECLARE_DYNAMIC(CFirst)

public:
	CFirst(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFirst();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FIRST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	typedef struct tagCOPYDATASTRUCT{
		DWORD dwData;
		DWORD cdData;
		PVOID lpData;
	}COPYDATASTRUCT, *PCOPYDATASTRUCT;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	//icon image 관련
	CImageList *m_Smallimage; //Small 이미지 리스트
	CImageList *m_LargeImage; //Large 이미지 리스트
	HIMAGELIST hSystemSmall; //SMALL 시스템 이미지 리스트
	HIMAGELIST hSystemLarge; //LARGE 시스템 이미지 리스트;
	SHFILEINFO shellinfo;
	/////////////////////////////////////////////////////////
	CListCtrl m_List;
	CButton m_AddBtn;
	CButton m_deleteBtn;
	//file 관련 변수들
	CString strPathName;
	CString fileName;
	CString fileExt;
	CString savePath;
	//file 입출력
	CStdioFile import;
	CStdioFile file;
	CString RegFileData[20];
	void RegWriteReady();
	int RegFileindex;
	///////////////////////////
	//directory 관련//
	void RegReadAdd();
	TCHAR r_str[MAX_PATH];
	DWORD Size = MAX_PATH;
	CString RegNameList[200];
	CString RegPathList[200];
	BOOL CreateDir(CString dir);
	
	int RegNameList_Count;
	int RegSaveNameIndex;
	int m_List_Count;
	int m_List_subCount;
	int m_List_selectIndex;
	void splitRegName();
	virtual BOOL OnInitDialog();
	void OnGetIcon(CString strPathName, CString fileName, CString fileExt);
	void SetListControlView();
	///////////////////////////////////////////////////////
	//Registriation 관련//
	CString RegSaveName[20];
	void RegDelete();
	int RegAddIndex;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	
	
	afx_msg void OnBnClickedExport();
	afx_msg void OnBnClickedImport();
	afx_msg void OnBnClickedRegedit();
	afx_msg void OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRegcancle();
//	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
};
