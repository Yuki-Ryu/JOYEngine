#pragma once


#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "colorshaderclass.h"
#include "d3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "textureshaderclass.h" 
#include "lightshaderclass.h"
#include "lightclass.h"
#include "bitmapclass.h"
#include "textclass.h"
#include "modellistclass.h"
#include "frustumclass.h"
#include "multitextureshaderclass.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN		= false;
const bool VSYNC_ENABLED	= true;
const float SCREEN_DEPTH	= 1000.0f;
const float SCREEN_NEAR		= 0.1f;



class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame(float, int, int, int, int, float);
	bool Render(float);


private:
	D3DClass*					m_D3D;
	CameraClass*				m_Camera;
	ModelClass*					m_Model;
	ColorShaderClass*			m_ColorShader;
	TextureShaderClass*			m_TextureShader;
	LightShaderClass *			m_LightShader;
	LightClass *				m_Light;
	BitmapClass*				m_Bitmap;
	TextClass*					m_Text;
	ModelListClass*				m_ModelList;
	FrustumClass*				m_Frustum;
	MultiTextureShaderClass*	m_MultiTextureShader;
};


#endif

