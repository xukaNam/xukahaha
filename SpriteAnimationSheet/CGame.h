#pragma once

#define APP_CLASS "SpriteWindow"
#define MAIN_WINDOW_TITLE "Sample_Sprite_Animation"

#include <Windows.h>
#include <d3dx9.h>

#include "CAnimationSprite.h"

// Screen resolution
#define GAME_SCREEN_RESOLUTION_800_600_24   1
#define GAME_SCREEN_RESOLUTION_1024_640_24  3

// Path file resource
#define SPRITE_TITLE_ALADDIN L"resource/spriteSheet_aladdin_walk.bmp"
#define SPRITE_TITLE_ALADDIN_XML "resource/spriteSheet_aladdin_walk.xml"

// singleton
class CGame
{
private:
	LPDIRECT3D9			_d3d;		// The pointer to our Direct3D interface
	LPDIRECT3DDEVICE9	_d3ddv;		// The pointer to the device class
	LPDIRECT3DSURFACE9	_BackBuffer;

	DWORD		_DeltaTime;			// Time between the last frame and current frame
	int			_Mode;				// Screen mode 
	int			_IsFullScreen;		// Is running in fullscreen mode?
	int			_FrameRate;			// Desired frame rate of game

	int			_ScreenWidth;
	int			_ScreenHeight;

	D3DFORMAT	_BackBufferFormat;

	HINSTANCE	_hInstance;			// Handle of the game instance
	HWND		_hWnd;				// Handle of the Game Window

	LPWSTR		_Name;				// Name of game will be used as Window Class Name

	void		_SetScreenDimension(int Mode);

	static LRESULT CALLBACK _WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void _InitWindow();
	void _InitDirectX();

	//void render(float DeltaTime);					// Render something
	void render();

	CAnimationSprite*	_AspAladdin;


private:
	CGame() { }


public:
	CGame(const CGame &) = delete;
	void operator=(const CGame &) = delete;

	static CGame& GetInstance();

	void InitConstructor(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullscreen, int FrameRate);
	~CGame();

	// Initialize the game with set parameters
	void Init();

	// Run game
	void Run();

	// Terminat game
	void Terminate();
    //LRESULT CALLBACK _WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};