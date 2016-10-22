#include "stdafx.h"
#include "QuickBar.h"


QuickBar::QuickBar(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :MouseMotion(env, glove, startMotion, endMotion)
{
}

QuickBar::QuickBar(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : MouseMotion(env, glove, startMotion)
{
}

QuickBar::~QuickBar()
{
}
void QuickBar::init(){
	StartExcute();
}
void QuickBar::StartExcute()
{
	SHELLEXECUTEINFO ExeInfo;
	ZeroMemory(&ExeInfo, sizeof(ExeInfo));
	ExeInfo.cbSize = sizeof(ExeInfo);
	ExeInfo.lpVerb = _T("open");
	ExeInfo.lpFile = _T("C:\\Users\\mango.DGSSM\\Desktop\\TrayIconTest\\TrayIconTest\\AirCommand.exe");
	ExeInfo.fMask = SEE_MASK_FLAG_NO_UI | SEE_MASK_NOCLOSEPROCESS;
	ExeInfo.nShow = SW_SHOW;
	::ShellExecuteEx(&ExeInfo);
}
