#pragma once


#ifndef _TEXTURECLASS_H_
#define _TEXTURECLASS_H_


//////////////
// INCLUDES //
//////////////
#include <stdio.h>
#include <d3d11.h>
#include <d3dx11tex.h>


class TextureClass
{
private:
	struct TargaHeader
	{
		unsigned char data1[12];
		unsigned short width;
		unsigned short height;
		unsigned char bpp;
		unsigned char data2;
	};

public:
	TextureClass();
	TextureClass(const TextureClass&);
	~TextureClass();

	//* The first two functions will load a texture from a given file name and unload that texture when it is no longer needed.*//

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, char*);
	void Shutdown();

	//* The GetTexture function returns a pointer to the texture resource so that it can be used for rendering by shaders.*//

	ID3D11ShaderResourceView* GetTexture();

private:
	bool LoadTarga(char*, int&, int&);

private:
	//This is the private texture resource.
	unsigned char* m_targaData;
	ID3D11Texture2D* m_texture;
	ID3D11ShaderResourceView* m_textureView;
};


#endif

