#pragma once


#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN	 = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR	 = 0.1f;


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "inputclass.h"
#include "d3dclass.h"
#include "shadermanagerclass.h"
#include "cameraclass.h"
#include "terrainclass.h"
#include "timerclass.h"
#include "userinterfaceclass.h"
#include "positionclass.h"
#include "fpsclass.h"
#include "cpuclass.h"



class ApplicationClass
{
public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass&);
	~ApplicationClass();

	bool Initialize(HINSTANCE, HWND, int, int, float);
	void Shutdown();
	bool Frame();

private:
	bool HandleMovementInput(InputClass*, float);
	bool RenderAppG(D3DClass*, ShaderManagerClass*);
	bool m_displayUI;

private:
	InputClass* m_Input;
	D3DClass* m_Direct3D;
	ShaderManagerClass* m_ShaderManager;
	CameraClass* m_Camera;
	TerrainClass* m_Terrain;
	TimerClass* m_Timer;
	UserInterfaceClass* m_UserInterface;
	PositionClass* m_Position;
	FpsClass* m_Fps;
	CpuClass* m_Cpu;
};

#endif