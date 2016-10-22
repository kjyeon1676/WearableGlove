#pragma once
class EnvironmentStatus
{
public:
	EnvironmentStatus(CList<MONITORINFOEX, MONITORINFOEX&>* Monitors);
	EnvironmentStatus(){ air_sensibility = 0.01; };
	~EnvironmentStatus();
	void setX(int x){ this->x = x; }
	void setY(int y){ this->y = y; }
	int getX(){ return x; }
	int getY(){ return y; }
	void moveCursor(int x, int y);
	MONITORINFOEX& getMonitor(){ return monitor; }
	CList<MONITORINFOEX, MONITORINFOEX&>* getMonitors(){ return Monitors; }
	int getCursorMonitor(){ return Cursor_On_Monitor; }
	void setCursorMonitor(int monitor){ Cursor_On_Monitor = monitor; }
	void setMonitors(CList<MONITORINFOEX, MONITORINFOEX&>* Monitors){ this->Monitors = Monitors; };
	double getAirSensibility(){ return air_sensibility; }
	void setAirSensibility(double d){ air_sensibility = d; }
private:
	int x, y;
	double air_sensibility;
	MONITORINFOEX monitor;
	POSITION pos;
	BOOL Mouse_In_Monitor;
	int Cursor_On_Monitor;
	CList<MONITORINFOEX, MONITORINFOEX&>* Monitors;
};

