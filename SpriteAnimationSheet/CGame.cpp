#include <windows.h>
#include "CGame.h"

//int flag = 0;

CGame& CGame::GetInstance()
{
	static CGame instance;
	return instance;
}

void CGame::InitConstructor(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate)
{
	_d3d = NULL;
	_d3ddv = NULL;
	_BackBuffer = NULL;
	_Mode = Mode;
	_SetScreenDimension(Mode);
	_Name = Name;
	_IsFullScreen = IsFullScreen;
	_FrameRate = FrameRate;
	_hInstance = hInstance;

	_AspAladdin = NULL;
}

void CGame::_SetScreenDimension(int Mode)
{
	switch (Mode)
	{
	case GAME_SCREEN_RESOLUTION_800_600_24:
		_ScreenWidth = 800;
		_ScreenHeight = 600;
		_BackBufferFormat = D3DFMT_X8R8G8B8;
		break;

	case GAME_SCREEN_RESOLUTION_1024_640_24:
		_ScreenWidth = 1024;
		_ScreenHeight = 640;
		_BackBufferFormat = D3DFMT_X8R8G8B8;
		break;

	default:
		break;
	}
}

void CGame::_InitWindow()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
							 
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = _hInstance;

	wc.lpfnWndProc = (WNDPROC)CGame::_WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _Name;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	DWORD style;
	if (_IsFullScreen)
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	else
		style = WS_OVERLAPPEDWINDOW;

	_hWnd =
		CreateWindow(
			_Name,
			_Name,
			style,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			_ScreenWidth,
			_ScreenHeight,
			NULL,
			NULL,
			_hInstance,
			NULL);

	if (!_hWnd)
	{
		MessageBox(NULL, L"Can't create Windows", L"Error", MB_OK);
	}

	ShowWindow(_hWnd, SW_SHOWNORMAL);
	UpdateWindow(_hWnd);
}

void CGame::_InitDirectX()
{
	_d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = _IsFullScreen ? FALSE : TRUE;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.BackBufferFormat = _BackBufferFormat;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = _ScreenHeight;
	d3dpp.BackBufferWidth = _ScreenWidth;

	_d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&_d3ddv);

	if (_d3ddv == NULL)
	{
		MessageBox(NULL, L"Can't create Direct Device", L"Error", MB_OK);
		return;
	}

	_d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &_BackBuffer);
}

//void CGame::render(float DeltaTime)
void CGame::render()
{
	//_AspAladdin->Render(DeltaTime, 350, 420, 2.5, 50, -1);
	//_AspAladdin->Render(DeltaTime, 2.5, 50, -1);
	_AspAladdin->Render(2.5, 50);
}

void CGame::Init()
{
	_InitWindow();
	_InitDirectX();

	// init animation sprite
	_AspAladdin = new CAnimationSprite(_d3ddv);
	_AspAladdin->Init();
	// load sprite
	if (!_AspAladdin->Load(SPRITE_TITLE_ALADDIN, SPRITE_TITLE_ALADDIN_XML, D3DCOLOR_XRGB(255, 0, 255)))
	{
		PostQuitMessage(WM_QUIT);
	}
}
int check_point = 0;
// Main game message loop
void CGame::Run()
{
	//MSG msg;
	//int done = 0;
	//DWORD frame_start = GetTickCount();;

	//DWORD tick_per_frame = 1000 / _FrameRate;

	//while (!done)
	//{
	//	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	//	{
	//		if (msg.message == WM_QUIT) done = 1;

	//		TranslateMessage(&msg);
	//		DispatchMessage(&msg);
	//	}

	//	DWORD now = GetTickCount();
	//	_DeltaTime = now - frame_start;
	//	if (_DeltaTime >= tick_per_frame)
	//	{
	//		frame_start = now;

	//		if (_d3ddv->BeginScene())
	//		{
	//			// clear the window to a deep blue
	//			_d3ddv->ColorFill(_BackBuffer, NULL, D3DCOLOR_XRGB(0, 40, 100));

	//			// render
	//			this->render(_DeltaTime);

	//			_d3ddv->EndScene();
	//		}

	//		_d3ddv->Present(NULL, NULL, NULL, NULL);
	//	}
	//};
	MSG msg;
	int done = 0;
	//DWORD frame_start = GetTickCount();;

	//DWORD tick_per_frame = 1000 / _FrameRate;*/

	while (!done)
	{
		
			
			
			if (_d3ddv->BeginScene())
			{
				// clear the window to a deep blue
				_d3ddv->ColorFill(_BackBuffer, NULL, D3DCOLOR_XRGB(0, 40, 100));

				
					this->render();
					

				_d3ddv->EndScene();
			

			_d3ddv->Present(NULL, NULL, NULL, NULL);
			
		}
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT) done = 1;

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			
		
	};
}

void CGame::Terminate()
{
	// release all

	if (_d3ddv != NULL) _d3ddv->Release();

	if (_d3d != NULL) _d3d->Release();

	_AspAladdin->Release();
}

CGame::~CGame()
{
	delete _AspAladdin;
}

LRESULT CALLBACK CGame::_WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;									 

	case WM_KEYDOWN:
		//flag = 1;
		//check_point = 0;
		CGame::GetInstance()._AspAladdin->OnKeyDown(wParam);
		//_AspAladdin->OnKeyDown(wParam);
		break;
	default:
		//check_point = 1;
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}