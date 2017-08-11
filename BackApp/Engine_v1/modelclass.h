#pragma once


#ifndef _MODELCLASS_H_
#define _MODELCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <d3dx10math.h>
#include <fstream>

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textureclass.h"
#include "texturearrayclass.h"

using namespace std;



class ModelClass
{
private:
	// The VertexType has replaced the color component with a texture coordinate component.The texture coordinate is now replacing the green color that was used in the previous tutorial.
	struct VertexType
	{
		D3DXVECTOR3 position;
		//D3DXVECTOR4 color;
		D3DXVECTOR2 texture;
		D3DXVECTOR3 normal;
	};
	
	struct ModelType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool Initialize(ID3D11Device*,char*, WCHAR*, WCHAR*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

	// The ModelClass also has a GetTexture function so it can pass its own texture resource to shaders that will draw this model.
	//ID3D11ShaderResourceView* GetTexture();
	ID3D11ShaderResourceView** GetTextureArray();

	private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	// ModelClass has both a private LoadTexture and ReleaseTexture for loading and releasing the texture that will be used to render this model.
	bool LoadTextures(ID3D11Device*, WCHAR*, WCHAR*);
	void ReleaseTextures();

	// Functions to handle loading and unloading the model data from the text file.
	bool LoadModel(char*);
	void ReleaseModel();

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;

	// The m_Texture variable is used for loading, releasing, and accessing the texture resource for this model.
	//TextureClass* m_Texture;
	// The final change is a new private variable called m_model which is going to be an array of the new private structure ModelType.This variable will be used to read in and hold the model data before it is placed in the vertex buffer.
	ModelType* m_model;
	// We now have a TextureArrayClass variable instead of a TextureClass variable.
	TextureArrayClass* m_TextureArray;
};


#endif

