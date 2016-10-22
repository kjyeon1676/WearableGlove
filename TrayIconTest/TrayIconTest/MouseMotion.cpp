#include "stdafx.h"
#include "MouseMotion.h"


MouseMotion::MouseMotion(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion, MotionFragment* endMotion) :Motion(env, glove, startMotion, endMotion)
{
}
MouseMotion::MouseMotion(EnvironmentStatus& env, GloveStatus& glove, MotionFragment* startMotion) : Motion(env, glove, startMotion)
{
}

MouseMotion::~MouseMotion()
{
}
void MouseMotion::cursorMove(int mx, int my){
	MONITORINFOEX& monitor = getEnv().getMonitor();
	CList<MONITORINFOEX, MONITORINFOEX&>* Monitors = getEnv().getMonitors();
	POSITION pos = Monitors->GetHeadPosition();
	BOOL Mouse_In_Monitor = false;
	int x = getEnv().getX();
	int y = getEnv().getY();

	for (int i = 0; i < Monitors->GetSize(); i++)
	{
		monitor = Monitors->GetNext(pos);
		if (mx <= monitor.rcMonitor.right&&mx >= monitor.rcMonitor.left&&my >= monitor.rcMonitor.top&&my <= monitor.rcMonitor.bottom)
		{
			Mouse_In_Monitor = TRUE;
			getEnv().setCursorMonitor(i);
		}
	}

	if (Mouse_In_Monitor == FALSE)
	{
		monitor = Monitors->GetAt(Monitors->FindIndex(getEnv().getCursorMonitor()));
		if (mx > monitor.rcMonitor.right)
			mx = monitor.rcMonitor.right;
		if (mx < monitor.rcMonitor.left)
			mx = monitor.rcMonitor.left;
		if (my>monitor.rcMonitor.bottom)
			my = monitor.rcMonitor.bottom;
		if (my < monitor.rcMonitor.top)
			my = monitor.rcMonitor.top;
	}

	getEnv().setX(mx);
	getEnv().setY(my);
	SetCursorPos(mx, my);
}
void MouseMotion::leftDown(){
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
}
void MouseMotion::leftUp(){
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
void MouseMotion::init(){
}
void MouseMotion::exit(){
}
void MouseMotion::action(){

}
void MouseMotion::rightDown(){
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
}
void MouseMotion::rightUp(){
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}
void MouseMotion::wheelUp(int amount){
	mouse_event(MOUSEEVENTF_WHEEL, 0, 0, amount, 0);
}
void MouseMotion::wheelDown(int amount){
	mouse_event(MOUSEEVENTF_WHEEL, 0, 0, -amount, 0);
}

void MouseMotion::leftKey(){
	keybd_event(VK_LEFT, 0, 0, 0);
}
void MouseMotion::rightKey(){
	keybd_event(VK_RIGHT, 0, 0, 0);
}
void MouseMotion::upKey(){
	keybd_event(VK_UP, 0, 0, 0);
}
void MouseMotion::downKey(){
	keybd_event(VK_DOWN, 0, 0, 0);
}
void MouseMotion::downWinKey(){
	keybd_event(VK_LWIN, 0, 0, 0);
}
void MouseMotion::upWinKey(){
	keybd_event(VK_LWIN, 0, 2, 0);
}
void MouseMotion::downTabKey(){
	keybd_event(VK_TAB, 0, 0, 0);
}
void MouseMotion::upTabKey(){
	keybd_event(VK_TAB, 0, 2, 0);
}
void MouseMotion::pushAlpabet(char a){
	keybd_event(0x41 + (int)(a - 'a'), 0, 0, 0);
}