#pragma once


#ifndef _TEXTCLASS_H_
#define _TEXTCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "fontclass.h"
#include "shadermanagerclass.h"


class TextClass
{
private:
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
	};

public:
	TextClass();
	TextClass(const TextClass&);
	~TextClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, int, int, int, bool, FontClass*, char*, int, int, float, float, float);
	void Shutdown();
	void Render(ID3D11DeviceContext*, ShaderManagerClass*, D3DXMATRIX, D3DXMATRIX, D3DXMATRIX, ID3D11ShaderResourceView*);

	bool UpdateSentence(ID3D11DeviceContext*, FontClass*, char*, int, int, float, float, float);

private:
	bool InitializeSentence(ID3D11Device*, ID3D11DeviceContext*, FontClass*, char*, int, int, float, float, float);
	void RenderSentence(ID3D11DeviceContext*, ShaderManagerClass*, D3DXMATRIX, D3DXMATRIX, D3DXMATRIX, ID3D11ShaderResourceView*);

private:	
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer, *m_vertexBuffer2, *m_indexBuffer2;
	int m_screenWidth, m_screenHeight, m_maxLength, m_vertexCount, m_indexCount;
	bool m_shadow;
	D3DXVECTOR4 m_pixelColor;
};


#endif

