#pragma once

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define GRAVITY 0.098

#define CENTER_X 640
#define CENTER_Y 360

#define RED		 RGB(155,0,0)
#define GREEN	 RGB(0,155,0)
#define BLUE	 RGB(0,0,155)
#define BLACK	 RGB(0,0,0)
#define WHITE	 RGB(255,255,255)
#define CYAN	 RGB(0,255,255)
#define MAZENTA	 RGB(255,0,255)
#define GRAY	 RGB(150,150,150)

#define LERP(s,d,t) (d-s)*t + s

enum Dir
{
	UP,
	LEFT,
	DOWN,
	RIGHT,

	DIRCOUNT = 4
};