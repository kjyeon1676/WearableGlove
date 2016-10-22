#include "stdafx.h"
#include "RegistryDlg.h"
#include <atlbase.h>
#include <string.h>

#define KEY "Software\\magic_glove"
RegistryDlg::RegistryDlg()
{
	RegNameList_Count = 0;
}


RegistryDlg::~RegistryDlg()
{
}
BOOL RegistryDlg::RegStringWrite(HKEY hKey, LPCTSTR lpSubKey,LPCTSTR lpValueKey,TCHAR lpValue[])
{
	CString strValue = _T("");
	HKEY hSubKey = NULL;
	LONG Key;
	int i = 0;
	//LP : long Pointer
	//C : const
	//STR : string
	//t_char .. 자신의 운영체제 환경에 맞게 char 혹은 multi-byte  환경으로 type casting 시켜줌..
	//W : wide char = unicode
	//LPCTSTR : long Pointer const t_string = const char *
	Key = RegOpenKeyEx(hKey, _T("SOFTWARE\\MAGIC_GLOVE"), 0, KEY_ALL_ACCESS, &hSubKey);
	if (Key == ERROR_SUCCESS)
	{
		//DWORD cbSize = (DWORD)strlen((LPSTR)(LPCTSTR)lpValue) + 1;
		TCHAR pBuf[1028];
		memcpy(pBuf, lpValue, 1028);
		for (i = 0; pBuf[i] != NULL; i++);
		
		RegSetValueEx(hSubKey, lpValueKey, 0, REG_SZ,(LPBYTE)pBuf,DWORD(i+100));
		
		memset(pBuf, 0, sizeof(pBuf));
		RegCloseKey(hSubKey);

		return TRUE;
	}
	return FALSE;

}
BOOL RegistryDlg::RegDWORDWrite(HKEY hKey, LPCTSTR lpSubKey, LPCTSTR lpValueKey, DWORD dwValue)
{
	CString strValue = _T("");
	HKEY hSubKey = NULL;

	if (::RegOpenKeyEx(hKey, lpSubKey, 0, KEY_ALL_ACCESS, &hSubKey) == ERROR_SUCCESS)
	{
		::RegSetValueEx(hSubKey, lpValueKey, NULL, REG_DWORD, (LPBYTE)&dwValue, sizeof(DWORD));

		::RegCloseKey(hSubKey);

		return TRUE;
	}
	return FALSE;
}
BOOL RegistryDlg::RegistryCreate(HKEY hKey, LPCTSTR lpKey, LPCTSTR lpValue, LPCTSTR lpData)
{
	HKEY key;
	if (RegCreateKeyEx(HKEY_CURRENT_USER, _T("SOFTWARE\\MAGIC_GLOVE"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &key, NULL) == ERROR_SUCCESS)
	{
		TRACE(_T("reg make !!!!"));
		RegCloseKey(key);
		return TRUE;
	}
	return FALSE;
}

BOOL RegistryDlg::RegDelValue(HKEY hKey, LPCTSTR lpValue)
{
	HKEY hSubKey = NULL;
	LONG lRet = 0;

	if (RegOpenKeyEx(hKey, _T("SOFTWARE\\MAGIC_GLOVE"), 0, KEY_ALL_ACCESS, &hSubKey) == ERROR_SUCCESS)
	{
		lRet = RegDeleteValue(hSubKey, lpValue);
		if (lRet == ERROR_SUCCESS)
		{
			RegCloseKey(hSubKey);
			return TRUE;
		}
	}
	return FALSE;
}
BOOL RegistryDlg::RegEnumOpenValue()
{
	return FALSE;
}
BOOL RegistryDlg::RegDeleteUseOpen(HKEY hKey, LPCTSTR lpValue)
{
	HKEY hSubKey = NULL;
	LONG Reg_Ret;
	DWORD dwType = REG_SZ;
	Reg_Ret = RegOpenKeyEx(HKEY_CURRENT_USER, _T("SOFTWARE\\MAGIC_GLOVE"), 0, KEY_ALL_ACCESS, &hSubKey);
	if (Reg_Ret==ERROR_SUCCESS)
	{
		for (int i = 0; Reg_Ret == ERROR_SUCCESS; i++)
		{
			Reg_Ret = RegEnumValue(hSubKey, i, i_str, &Size, NULL, NULL, NULL, NULL);
			if (Reg_Ret == ERROR_SUCCESS)
			{
				DWORD dwType, dwSize = MAX_PATH;
				TCHAR szBuffer[MAX_PATH];
				RegQueryValueEx(hSubKey, i_str, 0, &dwType, (LPBYTE)szBuffer, &dwSize);
				RegNameList[RegNameList_Count++] = i_str;
			}
			Size = MAX_PATH;
		}
		RegCloseKey(hSubKey);
		return TRUE;
	}
	return FALSE;
}
