#include "shadermanagerclass.h"


ShaderManagerClass::ShaderManagerClass()
{
	m_ColorShader = 0;
	m_FontShader = 0;
	m_LightsHader = 0;
	m_TexturesHader = 0;
	m_MultiTextureShader = 0;
}


ShaderManagerClass::ShaderManagerClass(const ShaderManagerClass& other)
{
}


ShaderManagerClass::~ShaderManagerClass()
{
}


bool ShaderManagerClass::Initialize(ID3D11Device* device, HWND hwnd)
{
	bool result;


	// Create the color shader object.
	m_ColorShader = new ColorShaderClass;
	if(!m_ColorShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_ColorShader->Initialize(device, hwnd);
	if(!result)
	{
		return false;
	}

	// Create the font shader object.
	m_FontShader = new FontShaderClass;
	if(!m_FontShader)
	{
		return false;
	}

	// Initialize the font shader object.
	result = m_FontShader->Initialize(device, hwnd);
	if(!result)
	{
		return false;
	}
	
	// Create the lights shader object.
	m_LightsHader = new LightShaderClass;
	if (!m_LightsHader)
	{
		return false;
	}

	// Initialize the lights shader object.
	result = m_LightsHader->Initialize(device, hwnd);
	if (!result)
	{
		return false;
	}

	// Create the textures shader object.
	m_TexturesHader = new TextureShaderClass;
	if (!m_TexturesHader)
	{
		return false;
	}

	// Initialize the textures shader object.
	result = m_TexturesHader->Initialize(device, hwnd);
	if (!result)
	{
		return false;
	}

	// Create the multi texture shader object.
	m_MultiTextureShader = new MultiTextureShaderClass;
	if (!m_MultiTextureShader)
	{
		return false;
	}

	// Initialize the multi texture shader object.
	result = m_MultiTextureShader->Initialize(device, hwnd);
	if (!result)
	{
		return false;
	}
	return true;
}


void ShaderManagerClass::Shutdown()
{
	// Release the multi texture shader object.
	if (m_MultiTextureShader)
	{
		m_MultiTextureShader->Shutdown();
		delete m_MultiTextureShader;
		m_MultiTextureShader = 0;
	}

	// Release the textures shader object.
	if (m_TexturesHader)
	{
		m_TexturesHader->Shutdown();
		delete m_TexturesHader;
		m_TexturesHader = 0;
	}

	// Release the lights shader object.
	if (m_LightsHader)
	{
		m_LightsHader->Shutdown();
		delete m_LightsHader;
		m_LightsHader = 0;
	}

	// Release the font shader object.
	if(m_FontShader)
	{
		m_FontShader->Shutdown();
		delete m_FontShader;
		m_FontShader = 0;
	}

	// Release the color shader object.
	if(m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = 0;
	}

	return;
}


bool ShaderManagerClass::RenderColorShader(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix,
											D3DXMATRIX projectionMatrix)
{
	return m_ColorShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix);
}


bool ShaderManagerClass::RenderFontShader(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix,
											D3DXMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, D3DXVECTOR4 pixelColor)
{
	return m_FontShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture, pixelColor);
}


bool ShaderManagerClass::RenderLightHader(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix,
						D3DXMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, D3DXVECTOR3 lightDirection, D3DXVECTOR4 ambientColor, D3DXVECTOR4 diffuseColor, D3DXVECTOR3 cameraPosition, D3DXVECTOR4 specularColor, float specularPower)
{
	return m_LightsHader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture, lightDirection, ambientColor, diffuseColor, cameraPosition, specularColor, specularPower);
}


bool ShaderManagerClass::RenderTextureShader(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix,
							D3DXMATRIX projectionMatrix, ID3D11ShaderResourceView* texture)
{
	return m_TexturesHader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture);
}


bool ShaderManagerClass::RenderMultiTextureShader(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix,
													D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix, ID3D11ShaderResourceView** textureArray)
{
	return m_MultiTextureShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, textureArray);
}


