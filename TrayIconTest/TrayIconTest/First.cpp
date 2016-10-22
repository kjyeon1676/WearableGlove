// First.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "First.h"
#include "RegistryDlg.h"
#include "afxdialogex.h"

// CFirst 대화 상자입니다.
IMPLEMENT_DYNAMIC(CFirst, CDialogEx)

CFirst::CFirst(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFirst::IDD, pParent)
{
	m_List_Count = 0;
	m_List_subCount = 1;
	RegFileindex = 0;
	RegAddIndex = 0;
	RegNameList_Count = 0;
	m_Smallimage = new CImageList;
	m_LargeImage = new CImageList;

}

CFirst::~CFirst()
{
}

void CFirst::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_List);
	DDX_Control(pDX, IDC_BUTTON1, m_AddBtn);
	DDX_Control(pDX, IDC_BUTTON2, m_deleteBtn);
}


BEGIN_MESSAGE_MAP(CFirst, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON1, &CFirst::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &CFirst::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_EXPORT, &CFirst::OnBnClickedExport)
	ON_BN_CLICKED(IDC_IMPORT, &CFirst::OnBnClickedImport)
	ON_BN_CLICKED(IDC_Regedit, &CFirst::OnBnClickedRegedit)
	ON_NOTIFY(NM_CLICK, IDC_LIST3, &CFirst::OnNMClickList3)
	ON_BN_CLICKED(IDC_REGCANCLE, &CFirst::OnBnClickedRegcancle)
//	ON_WM_COPYDATA()
END_MESSAGE_MAP()


// CFirst 메시지 처리기입니다.


BOOL CFirst::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 255));
	//return CDialogEx::OnEraseBkgnd(pDC);
	return TRUE;
}


BOOL CFirst::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//SetListControlView();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//ListControl Title 추가 부분..
	m_List.InsertColumn(0, _T("FileName"), LVCFMT_LEFT, 185,-1);
	m_List.InsertColumn(1, _T("extension"), LVCFMT_LEFT, 65,-1);
	m_List.InsertColumn(2, _T("Path"), LVCFMT_LEFT, 205, -1);
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	CreateDir(_T("C:\\MagicGlove\\"));
	RegReadAdd();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
void CFirst::SetListControlView()
{

}
void CFirst::splitRegName()
{
	CString fileName;
	CString fileExtension;
	CString strTok;
	for (int i = 0; i < RegNameList_Count; i++)
	{
		AfxExtractSubString(strTok, RegNameList[i], 0, '.');
		fileExtension = RegNameList[i].Right(3);
		OnGetIcon(RegPathList[i], strTok, fileExtension);
	}
}
void CFirst::RegReadAdd()
{
	HKEY hSubKey = NULL;
	LONG Reg_Ret;
	DWORD dwType = REG_SZ;
	Reg_Ret = RegOpenKeyEx(HKEY_CURRENT_USER, _T("SOFTWARE\\MAGIC_GLOVE"), 0, KEY_ALL_ACCESS, &hSubKey);
	if (Reg_Ret == ERROR_SUCCESS)
	{
		for (int i = 0; Reg_Ret == ERROR_SUCCESS; i++)
		{
			Reg_Ret = RegEnumValue(hSubKey, i, r_str, &Size, NULL, NULL, NULL, NULL);
			if (Reg_Ret == ERROR_SUCCESS)
			{
				DWORD dwType, dwSize = MAX_PATH;
				TCHAR szBuffer[MAX_PATH];
				RegQueryValueEx(hSubKey, r_str, 0, &dwType, (LPBYTE)szBuffer, &dwSize);
				RegNameList[RegNameList_Count] = r_str;
				RegPathList[RegNameList_Count++] = szBuffer;
			}
			Size = MAX_PATH;
		}
		RegCloseKey(hSubKey);
		splitRegName();
	}
	
}
BOOL CFirst::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE))
	{
		pMsg->wParam = NULL;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


HBRUSH CFirst::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	
	switch (nCtlColor){
	case CTLCOLOR_STATIC:
		if (pWnd->GetDlgCtrlID() == IDC_GPBOX){
			pDC->SetBkColor(RGB(255, 255, 255));
			return (HBRUSH)GetStockObject(NULL_BRUSH);
		}
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
void CFirst::OnGetIcon(CString strPathName,CString fileName, CString fileExt)
{
	//아이콘 추가하는 부분..

	::ZeroMemory(&shellinfo, sizeof(shellinfo));
	HIMAGELIST hSysImageSmall = reinterpret_cast<HIMAGELIST>(::SHGetFileInfo(strPathName, 0, &shellinfo, sizeof(shellinfo), SHGFI_SMALLICON | SHGFI_SYSICONINDEX));
	HIMAGELIST hSysImageLarge = reinterpret_cast<HIMAGELIST>(::SHGetFileInfo(strPathName, 0, &shellinfo, sizeof(shellinfo), SHGFI_LARGEICON | SHGFI_SYSICONINDEX));

	ListView_SetImageList(m_List.m_hWnd, hSysImageSmall, LVSIL_SMALL);
	ListView_SetImageList(m_List.m_hWnd, hSysImageLarge, LVSIL_NORMAL);

	LVITEM item = { 0 };
	item.mask = LVIF_TEXT | LVIF_IMAGE;
	item.iItem = m_List_Count;
	item.pszText = (LPWSTR)(LPCWSTR)fileName;
	item.iImage = shellinfo.iIcon;

	//ListControl Row 추가
	m_List.InsertItem(&item);
	//ListControl 확장자 추가 부분..
	m_List.SetItem(m_List_Count, 1, LVIF_TEXT, fileExt, 0, 0, 0, NULL);
	m_List.SetItem(m_List_Count++, 2, LVIF_TEXT, strPathName, 0, 0, 0, NULL);
	//ListIndex 증가
	//m_List_Count++;
	//ImageList 메모리 해제

	//UpdateData(false);
}
//directory 생성
BOOL CFirst::CreateDir(CString dir)
{
	CFileFind file;
	CString strFile = _T("*.*");
	BOOL bResult = file.FindFile(dir + strFile);
	if (!bResult)
	{
		bResult = CreateDirectory(dir, NULL);
	}
	return bResult;
}
void CFirst::OnBnClickedAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL break_flag = FALSE;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("exe (*.exe,*.bat) | *.exe;*.bat;|"));
	if (IDOK == dlg.DoModal())
	{
		fileName = dlg.GetFileTitle();	
		for (int i = 0; i < RegFileindex; i++)
		{
			if (RegFileData[i].Compare(fileName) == 0)
			{
				MessageBox(_T("이미 추가한 목록입니다!"), _T("경고"));
				break_flag = TRUE;
				break;
			}
		}
		if (!break_flag)
		{
			strPathName = dlg.GetPathName();
			fileExt = dlg.GetFileExt();
			RegFileData[RegFileindex++] = fileName;
			if (fileExt == "exe" || fileExt == "bat")
			{
				OnGetIcon(strPathName, fileName, fileExt);
				RegFileData[RegFileindex++] = fileName + _T(".") + fileExt + _T("%") + strPathName;
			}
			else
			{
				MessageBox(_T("file Extension is not run file"));
			}
		}
	}
}
void CFirst::RegWriteReady()
{
	CStdioFile usuallyFile;
	usuallyFile.Open(_T("C:\\MagicGlove\\MagicGlove.txt"), CStdioFile::modeWrite | CStdioFile::typeText);
	for (int i = 0; i < RegFileindex; i++)
	{
		if (RegFileData[i] != _T(""))
		{
			usuallyFile.WriteString(RegFileData[i]);
			usuallyFile.WriteString(_T("\n"));
		}
	}
	RegFileindex = 0;
	memset(RegFileData, 0, sizeof(RegFileData));
}
void CFirst::OnBnClickedDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos;
	CString deleteFileName;
	CString extractFileName;
	int parsingPos = 0;
	int nSelitem = 0;
	while (pos = m_List.GetFirstSelectedItemPosition())
	{
		nSelitem = m_List.GetNextSelectedItem(pos);
		deleteFileName = m_List.GetItemText(m_List_selectIndex, 0);
		m_List.DeleteItem(nSelitem);
	}
	m_List_Count--;
	for (int i = 0; i < RegFileindex; i++)
	{
		parsingPos = RegFileData[i].Find('%');
		extractFileName = RegFileData[i].Left(parsingPos);
		deleteFileName = deleteFileName + _T(".exe");
		if (extractFileName == deleteFileName)
		{
			RegFileData[i] = _T("");
			RegFileindex--;
			break;
		}
	}
	
}


void CFirst::OnBnClickedExport()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strFileName;
	CString strFileExt;
	CString strFilePath;
	//CString savePath = _T("C:\\MagicGlove\\MagicGlove.txt");
	CString saveName;
	CFileDialog ExportDialog(false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("txt(*.txt) | *.txt||"));
	ExportDialog.m_ofn.lpstrTitle = _T("파일을 저장하세요");
	ExportDialog.m_ofn.lpstrInitialDir = _T("C:\\MagicGlove\\");
	if (m_List.GetItemCount() == 0){
		MessageBox(_T("내보낼 목록이 없습니다"));
	}
	else{
		if (IDOK == ExportDialog.DoModal())
		{
			savePath = ExportDialog.GetPathName();
			file.Open(savePath, CStdioFile::modeCreate | CStdioFile::modeWrite | CStdioFile::typeText);
			for (int i = 0; i < m_List.GetItemCount(); i++)
			{
				strFileName = m_List.GetItemText(i, 0);
				strFileExt = m_List.GetItemText(i, 1);
				strFilePath = m_List.GetItemText(i, 2);

				file.WriteString(strFileName + _T(".") + strFileExt + _T("%") + strFilePath);
				file.WriteString(_T("\n"));
			}
			file.Close();
			MessageBox(_T("내보내기 완료"));
		}
	}
}


void CFirst::OnBnClickedImport()
{
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("txt (*.txt) | *.txt;||"));
	CString strImportFileName;
	CString Content,saveContent;
	CString fileName, fileExt,filePath;
	CString strTok;
	int parsingPos = 0;
	//현재 리스트 정보 초기화
	m_List.DeleteAllItems();
	m_List_Count = 0;
	if (IDOK == dlg.DoModal())
	{
		strImportFileName = dlg.GetPathName();
		if (import.Open(strImportFileName, CStdioFile::modeRead | CStdioFile::typeText))
		{
			while (import.ReadString(Content)){
				saveContent = Content;
				AfxExtractSubString(fileName, saveContent, 0, '.');
				AfxExtractSubString(fileExt, saveContent, 0, '%');
				parsingPos = fileExt.Find('.');
				fileExt = fileExt.Mid(parsingPos+1);
				filePath = saveContent.Mid(fileName.GetLength() + fileExt.GetLength() + 2);
				OnGetIcon(filePath,fileName, fileExt);
			}
			import.Close();
		}
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
//파일 실행시키는 함수는 ShellExecute 함수

void CFirst::RegDelete()
{
	RegistryDlg m_Reg;
	CString ListFileName;
	LONG Reg_Ret;
	//레지스트리 키 값 읽어온 후에 .. 값이 있으면 삭제
	m_Reg.RegDeleteUseOpen(HKEY_CURRENT_USER, _T("SOFTWARE\\MAGIC_GLOVE"));
	if (m_Reg.RegNameList_Count > 0)
	{
		for (int i = 0; i < m_Reg.RegNameList_Count; i++)
		{
			ListFileName = m_Reg.RegNameList[i];
			m_Reg.RegDelValue(HKEY_CURRENT_USER, ListFileName);
		}
	}

}
void CFirst::OnBnClickedRegedit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	RegDelete();
	RegistryDlg m_Reg;
	CString filePath;
	const CString strKey = _T("SOFTWARE\\MAGIC_GLOVE");
	CString fileName;
	CString fileExtension;
	if (m_List_Count > 0)
	{
		if (MessageBox(_T("레지스트리 등록을 원하십니까?"), _T("Magic Glove"), MB_OKCANCEL) == IDOK)
		{
			if (m_Reg.RegistryCreate(HKEY_CURRENT_USER, _T("SOFTWARE\\MAGIC_GLOVE"), _T("Program"), _T("FilePath")))
			{
				for (int i = 0; i < m_List_Count; i++)
				{
					filePath = m_List.GetItemText(i, 2);
					fileName = m_List.GetItemText(i, 0);
					fileExtension = m_List.GetItemText(i, 1);
					if (m_Reg.RegStringWrite(HKEY_CURRENT_USER, (LPCTSTR)strKey, fileName+"."+fileExtension, (TCHAR*)(LPCTSTR)filePath))
					{
						RegSaveName[RegAddIndex++] = fileName;
						continue;
					}
					else
					{
						TRACE(_T("Reg Write Fail!!"));
						MessageBox(_T("등록 실패!"));
					}
				}
				MessageBox(_T("등록에 성공했습니다"));
			}
		}
	}
	else
		MessageBox(_T("프로그램을 등록하세요!"), _T("경고"));
}


void CFirst::OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int selectindex = pNMItemActivate->iItem;
	if (selectindex >= 0 && selectindex < m_List.GetItemCount())
	{
		m_List_selectIndex = selectindex;
	}
	*pResult = 0;
}


void CFirst::OnBnClickedRegcancle()
{
	RegistryDlg m_Reg;
	CString ListFileName;
	LONG Reg_Ret;
	//레지스트리 키 값 읽어온 후에 .. 값이 있으면 삭제
	m_Reg.RegDeleteUseOpen(HKEY_CURRENT_USER, _T("SOFTWARE\\MAGIC_GLOVE"));
	if (m_Reg.RegNameList_Count > 0)
	{
		for (int i = 0; i < m_Reg.RegNameList_Count; i++)
		{
			ListFileName = m_Reg.RegNameList[i];
			m_Reg.RegDelValue(HKEY_CURRENT_USER, ListFileName);
		}
		MessageBox(_T("레지스트리 정보 삭제 완료"), _T("정보"));
	}
	else
		MessageBox(_T("레지스트리에 등록된 정보가 없습니다!"), _T("경고"));

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


//BOOL CFirst::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	
//	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
//}
