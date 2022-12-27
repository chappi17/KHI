#include "framework.h"
#include "ShaderManager.h"

ShaderManager* ShaderManager::_instance = nullptr;

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}


shared_ptr<VertexShader> ShaderManager::AddVS(wstring file)
{
	if (_shaders.count(file) > 0)
	{
		return dynamic_pointer_cast<VertexShader>(_shaders[file]);
	}

	shared_ptr<VertexShader> vs = make_shared<VertexShader>(file);
	_shaders[file] = vs;

	return vs;
}

shared_ptr<PixelShader> ShaderManager::AddPS(wstring file)
{
	if (_shaders.count(file) > 0)
	{
		return dynamic_pointer_cast<PixelShader>(_shaders[file]);
	}

	shared_ptr<PixelShader> ps = make_shared<PixelShader>(file);
	_shaders[file] = ps;

	return ps;
}