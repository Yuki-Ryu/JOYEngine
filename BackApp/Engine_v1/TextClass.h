#pragma once


#ifndef _TEXTCLASS_H_
#define _TEXTCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "fontclass.h"
#include "shadermanagerclass.h"	// #include "fontshaderclass.h"


class TextClass
{
private:
	struct SentenceType
	{
		ID3D11Buffer *vertexBuffer, *indexBuffer;
		int vertexCount, indexCount, maxLength;
		float red, green, blue;
	};

	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
	};

public:
	TextClass();
	TextClass(const TextClass&);
	~TextClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, HWND, int, int, D3DXMATRIX);
	void Shutdown();
	bool Render(ID3D11DeviceContext*, ShaderManagerClass*, D3DXMATRIX, D3DXMATRIX);
	
	bool SetVideoCardInfo(char*, int, ID3D11DeviceContext*);
	bool SetMousePosition(int, int, ID3D11DeviceContext*);
	bool SetRenderCount(int, ID3D11DeviceContext*);

	bool SetFps(int, ID3D11DeviceContext*);
	bool SetCpu(int, ID3D11DeviceContext*);
	
	bool SetCameraPosition(float, float, float, ID3D11DeviceContext*);
	bool SetCameraRotation(float, float, float, ID3D11DeviceContext*);

private:
	bool InitializeSentence(SentenceType**, int, ID3D11Device*);
	bool UpdateSentence(SentenceType*, char*, int, int, float, float, float, ID3D11DeviceContext*);
	void ReleaseSentence(SentenceType**);
	bool RenderSentence(SentenceType*, ID3D11DeviceContext*, ShaderManagerClass*, D3DXMATRIX, D3DXMATRIX);

private:
	FontClass* m_Font;
	D3DXMATRIX m_baseViewMatrix;
	FontShaderClass* m_FontShader;
	int m_screenWidth, m_screenHeight;
	

	SentenceType *m_sentence1,	*m_sentence2,	*m_sentence3,	*m_sentence4,	*m_sentence5;
	SentenceType *m_sentence6,	*m_sentence7,	*m_sentence8,	*m_sentence9,	*m_sentence10;
	SentenceType *m_sentence11,	*m_sentence12,	*m_sentence13;
};


#endif

