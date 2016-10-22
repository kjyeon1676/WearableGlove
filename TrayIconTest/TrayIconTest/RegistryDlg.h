#pragma once
#include <Windows.h>

class RegistryDlg
{
public:
	RegistryDlg();
	~RegistryDlg();
	TCHAR i_str[MAX_PATH];
	DWORD Size = MAX_PATH;
	CString RegNameList[200];
	int RegNameList_Count;
	int RegSaveNameIndex;
	BOOL RegistryCreate(HKEY hKey,LPCTSTR lpKey,LPCTSTR lpValue, LPCTSTR lpData);
	BOOL RegDelValue(HKEY hKey, LPCTSTR lpValue);
	BOOL RegStringWrite(HKEY hKey, LPCTSTR lpSubKey, LPCTSTR lpValueKey,TCHAR lpValue[]);
	BOOL RegDWORDWrite(HKEY hKey, LPCTSTR lpSubKey, LPCTSTR lpValueKey, DWORD dwValue);
	BOOL RegDeleteUseOpen(HKEY hKey, LPCTSTR lpSubKey);
	BOOL RegEnumOpenValue();
};

