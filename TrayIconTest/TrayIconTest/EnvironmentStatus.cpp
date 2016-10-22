#include "stdafx.h"
#include "EnvironmentStatus.h"


EnvironmentStatus::EnvironmentStatus(CList<MONITORINFOEX, MONITORINFOEX&>* Monitors) :Monitors(Monitors)
{
	air_sensibility = 0.01;
	pos = Monitors->GetHeadPosition();
	Mouse_In_Monitor = FALSE;
	Cursor_On_Monitor = 0;

	x = 100;
	y = 100;

	for (int i = 0; i < Monitors->GetSize(); i++)
	{
		monitor = Monitors->GetNext(pos);
		if (x <= monitor.rcMonitor.right&&x >= monitor.rcMonitor.left&&y >= monitor.rcMonitor.top&&y <= monitor.rcMonitor.bottom)
		{
			Mouse_In_Monitor = TRUE;
			Cursor_On_Monitor = i;
		}
	}

	if (Mouse_In_Monitor == FALSE)
	{
		monitor = Monitors->GetAt(Monitors->FindIndex(Cursor_On_Monitor));
		if (x > monitor.rcMonitor.right)
			x = monitor.rcMonitor.right;
		if (x < monitor.rcMonitor.left)
			x = monitor.rcMonitor.left;
		if (y>monitor.rcMonitor.bottom)
			y = monitor.rcMonitor.bottom;
		if (y < monitor.rcMonitor.top)
			y = monitor.rcMonitor.top;
	}

}
EnvironmentStatus::~EnvironmentStatus()
{
}
void EnvironmentStatus::moveCursor(int x, int y){

	/*for (int i = 0; i < Monitors.GetSize(); i++)
	{
	monitor = Monitors.GetNext(pos);
	if (x <= monitor.rcMonitor.right&&x >= monitor.rcMonitor.left&&y >= monitor.rcMonitor.top&&y <= monitor.rcMonitor.bottom)
	{
	Mouse_In_Monitor = TRUE;
	Cursor_On_Monitor = i;
	}
	}

	if (Mouse_In_Monitor == FALSE)
	{
	monitor = Monitors.GetAt(Monitors.FindIndex(Cursor_On_Monitor));
	if (x > monitor.rcMonitor.right)
	x = monitor.rcMonitor.right;
	if (x < monitor.rcMonitor.left)
	x = monitor.rcMonitor.left;
	if (y>monitor.rcMonitor.bottom)
	y = monitor.rcMonitor.bottom;
	if (y < monitor.rcMonitor.top)
	y = monitor.rcMonitor.top;
	}

	SetCursorPos(this->x, this->y);*/

}
