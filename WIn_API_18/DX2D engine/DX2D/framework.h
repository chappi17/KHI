// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <math.h>
#include <memory>
#include <time.h>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <wrl/client.h>
#include <functional>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

using namespace std;
using namespace DirectX;

// DirectX Tex
#include "../DirectXTex/DirectXTex.h"

//FMOD
#include "Library/FMOD/inc/fmod.hpp"
#pragma comment(lib,"Library/FMOD/fmod_vc.lib")

// ImGUI
#include "../ImGUI/imgui.h"
#include "../ImGUI/imgui_impl_win32.h"
#include "../ImGUI/imgui_impl_dx11.h"

#include "Types.h"

// Device
#include "Framework/Device/Device.h"

// Utility
#include "Framework/Utility/Timer.h"
#include "Framework/Utility/Keyboard.h"
#include "Framework/Utility/tinyxml2.h"
#include "Framework/Utility/Audio.h"

// Render
#include "Framework/Render/VertexLayOut.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/Shader.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"
#include "Framework/Render/ShaderManager.h"
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"

// Math
#include "Framework/Math/MathUtility.h"
#include "Framework/Math/Vector2.h"
#include "Framework/Math/Transform.h"
#include "Framework/Math/Collider.h"
#include "Framework/Math/RectCollider.h"
#include "Framework/Math/CircleCollider.h"

// Camera
#include "Framework/Camera/Camera.h"

// Texture
#include "Framework/Texture/SRV.h"
#include "Framework/Texture/SamplerState.h"
#include "Framework/Texture/BlendState.h"
#include "Framework/Texture/StateManager.h"
#include "Framework/Texture/SRVManager.h"

//Animation
#include "Framework/Animation/Action.h"

// BagicObj
#include "Object/GameObj/BasicObj/Quad.h"
#include "Object/GameObj/BasicObj/Sprite.h"
#include "Object/GameObj/BasicObj/Effect.h"
#include "Object/GameObj/BasicObj/EffectManager.h"

// GameObj
#include "Object/GameObj/Planet.h"
#include "Object/GameObj/DunGreed/Player.h"
#include "Object/GameObj/DunGreed/Gun.h"
#include "Object/GameObj/DunGreed/Bullet.h"
#include "Object/GameObj/Dong/D_BackGround.h"
#include "Object/GameObj/Dong/D_Player.h"
#include "Object/GameObj/Dong/Dong.h"
#include "Object/GameObj/Fortress/Cannon.h"
#include "Object/GameObj/Fortress/Barrel.h"
#include "Object/GameObj/Fortress/F_bullet.h"

#include "Object/GameObj/CupHead/Cup_Background.h"
#include "Object/GameObj/CupHead/Cup_bullet.h"
#include "Object/GameObj/CupHead/Cup_player.h"
#include "Object/GameObj/CupHead/Cup_boss.h"

// Scene
#include "Scene/Scene.h"

// Program
#include "Program/Program.h"
extern Vector2 mousePos;