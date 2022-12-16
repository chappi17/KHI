#pragma once

#define RED		 RGB(255,0,0)
#define GREEN	 RGB(0,255,0)
#define BLUE	 RGB(0,0,255)

#define WIN_WIDTH		 1280
#define WIN_HEIGHT		 720
#define CENTER_X		 640
#define CENTER_Y		 360

#define PI				 3.141592

#define DEVICE Device::GetInstance()->GetDevice()
#define DC Device::GetInstance()->GetDeviceContext()

#define KEY_DOWN(k) Keyboard::GetInstance()->Down(k)
#define KEY_UP(k) Keyboard::GetInstance()->Up(k)
#define KEY_PRESS(k) Keyboard::GetInstance()->Press(k)

#define DELTA_TIME Timer::GetInstance()->GetElasedTime()
#define RUN_TIME Timer::GetInstance()->GetRunTime();

#define SAMPLER StateManager::GetInstance()->GetSampler()
#define AlphaBlendState StateManager::GetInstance()->GetAlphaBlend()
#define AdditiveBlendState StateManager::GetInstance()->GetAdditiveBlend()

using Float2 = XMFLOAT2;
