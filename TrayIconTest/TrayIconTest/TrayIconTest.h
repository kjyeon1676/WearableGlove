
// TrayIconTest.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTrayIconTestApp:
// �� Ŭ������ ������ ���ؼ��� TrayIconTest.cpp�� �����Ͻʽÿ�.
//

class CTrayIconTestApp : public CWinApp
{
public:
	CTrayIconTestApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTrayIconTestApp theApp;