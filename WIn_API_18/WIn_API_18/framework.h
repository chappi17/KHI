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
#include <memory>
#include <tchar.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Pos
{
    int x;
    int y;
};


// Type
#include "Types.h"

// Collider
#include "Collider/RectCollider.h"
#include "Collider/CircleCollider.h"

// Scene
#include "Scene/Scene.h"

// Program
#include "Program/Program.h"

// extern 이거 뭐였지
extern int mousePosX;
extern int mousePosY;
