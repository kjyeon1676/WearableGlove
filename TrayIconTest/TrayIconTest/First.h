#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"
#include "First.h"
#include "Second.h"

// CFirst ��ȭ �����Դϴ�.

class CFirst : public CDialogEx
{
	DECLARE_DYNAMIC(CFirst)

public:
	CFirst(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFirst();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FIRST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	typedef struct tagCOPYDATASTRUCT{
		DWORD dwData;
		DWORD cdData;
		PVOID lpData;
	}COPYDATASTRUCT, *PCOPYDATASTRUCT;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	//icon image ����
	CImageList *m_Smallimage; //Small �̹��� ����Ʈ
	CImageList *m_LargeImage; //Large �̹��� ����Ʈ
	HIMAGELIST hSystemSmall; //SMALL �ý��� �̹��� ����Ʈ
	HIMAGELIST hSystemLarge; //LARGE �ý��� �̹��� ����Ʈ;
	SHFILEINFO shellinfo;
	/////////////////////////////////////////////////////////
	CListCtrl m_List;
	CButton m_AddBtn;
	CButton m_deleteBtn;
	//file ���� ������
	CString strPathName;
	CString fileName;
	CString fileExt;
	CString savePath;
	//file �����
	CStdioFile import;
	CStdioFile file;
	CString RegFileData[20];
	void RegWriteReady();
	int RegFileindex;
	///////////////////////////
	//directory ����//
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
	//Registriation ����//
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
