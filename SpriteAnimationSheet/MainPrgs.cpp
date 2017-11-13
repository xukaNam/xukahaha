//// include the basic windows header files and the Direct3D header file
//#include <windows.h>
//#include <d3dx9.h>
//
//// global declarations
//LPDIRECT3D9 d3d;				// the pointer to our Direct3D interface
//LPDIRECT3DDEVICE9 d3ddev;		// the pointer to the device class
//
//// function prototypes
//void initD3D(HWND hWnd);		// sets up and initializes Direct3D
//void initWindows(HWND& hWnd, HINSTANCE hInstance);
//void render_frame(void);		// renders a single frame
//void cleanD3D(void);			// closes Direct3D and releases memory
//
//#define TITLE_SPRITE_SHEETS L"0.bmp"
//
//// the WindowProc function prototype
//LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//
//
////////////////////////////////////////////////////////////////////////////////////////////
//LPD3DXSPRITE sprite_handler = NULL;
//// create texture to store sprite sheets
//LPDIRECT3DTEXTURE9 texture = NULL;
//
//
///////////////////////////////////////////////////////////////////////////////////////////////
//// the entry point for any Windows program
//int WINAPI WinMain(HINSTANCE hInstance,
//	HINSTANCE hPrevInstance,
//	LPSTR lpCmdLine,
//	int nCmdShow)
//{
//	// the handle for the window, filled by a function
//	HWND hWnd;
//
//	// create windows
//	initWindows(hWnd, hInstance);
//
//	// display the window on the screen
//	ShowWindow(hWnd, nCmdShow);
//
//	// set up and initialize Direct3D
//	initD3D(hWnd);
//
//	//////////////////////////////////////////////////////////////////////////////////////////////////
//	HRESULT result = D3DXCreateSprite(d3ddev, &sprite_handler);
//
//	D3DXIMAGE_INFO info;
//
//	result = D3DXGetImageInfoFromFile(TITLE_SPRITE_SHEETS, &info);
//
//	result = D3DXCreateTextureFromFileEx(
//		d3ddev,
//		TITLE_SPRITE_SHEETS,
//		info.Width,
//		info.Height,
//		1,
//		D3DPOOL_DEFAULT,
//		D3DFMT_UNKNOWN,
//		D3DPOOL_DEFAULT,
//		D3DX_DEFAULT,
//		D3DX_DEFAULT,
//		D3DCOLOR_XRGB(255, 0, 255),
//		&info, // thông tin của ảnh
//		NULL,
//		&texture // texture đã được tạo
//	);
//
//	////////////////////////////////////////////////////////////////////////////////////////////////
//
//	// enter the main loop:
//
//	// this struct holds Windows event messages
//	MSG msg;
//
//	// wait for the next message in the queue, store the result in 'msg'
//	while (TRUE)
//	{
//		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
//		{
//			// translate keystroke messages into the right format
//			TranslateMessage(&msg);
//			// send the message to the WindowProc function
//			DispatchMessage(&msg);
//		}
//
//		if (msg.message == WM_QUIT)
//			break;
//
//		render_frame();
//	}
//
//	// clean up DirectX and COM
//	cleanD3D();
//
//	// return this part of the WM_QUIT message to Windows
//	return msg.wParam;
//}
//
//
//// this is the main message handler for the program
//LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	// sort through and find what code to run for the message given
//	switch (message)
//	{
//		// this message is read when the window is closed
//	case WM_DESTROY:
//	{
//		PostQuitMessage(0);        // close the application entirely
//
//		return 0;
//	} break;
//	}
//	// Handle any messages the switch statement didn't
//	return DefWindowProc(hWnd, message, wParam, lParam);
//}
//
//// this function initializes and prepares Direct3D for use
//void initD3D(HWND hWnd)
//{
//	d3d = Direct3DCreate9(D3D_SDK_VERSION);		// create the Direct3D interface
//
//	D3DPRESENT_PARAMETERS d3dpp;				// create a struct to hold various device information
//
//	ZeroMemory(&d3dpp, sizeof(d3dpp));			// clear out the struct for use // fill null
//	d3dpp.Windowed = TRUE;						// program windowed, not fullscreen
//	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;   // discard old frames
//	d3dpp.hDeviceWindow = hWnd;					// set the window to be used by Direct3D
//
//	// create a device class using this information and the info from the d3dpp stuct
//	d3d->CreateDevice(D3DADAPTER_DEFAULT,
//		D3DDEVTYPE_HAL,
//		hWnd,
//		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
//		&d3dpp,
//		&d3ddev);
//}
//
//void initWindows(HWND& hWnd, HINSTANCE hInstance)
//{
//	WNDCLASSEX wc;
//	ZeroMemory(&wc, sizeof(WNDCLASSEX));
//
//	wc.cbSize = sizeof(WNDCLASSEX);
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.lpfnWndProc = WindowProc;
//	wc.hInstance = hInstance;
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
//	wc.lpszClassName = L"WindowClass";
//
//	RegisterClassEx(&wc);				// register the window class
//
//										// create the window and use the result as the handle
//	hWnd = CreateWindowEx(NULL,
//		L"WindowClass",					// name of the window class
//		L"Our First Direct3D Program",  // title of the window
//		WS_OVERLAPPEDWINDOW,			// window style
//		300, 300,						// x, y - position of the window
//		800, 600,						// width, height of the window
//		NULL,							// we have no parent window, NULL
//		NULL,							// we aren't using menus, NULL
//		hInstance,						// application handle
//		NULL);							// used with multiple windows, NULL
//}
//
//
//// this is the function used to render a single frame
//void render_frame(void)
//{
//	// clear the window to a deep blue
//	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);
//
//	d3ddev->BeginScene();    // begins the 3D scene
//
//							 // do 3D rendering on the back buffer here
//
//							 // fill to surface
//							 //d3ddev->ColorFill(surface, NULL, D3DCOLOR_XRGB(255, 255, 0));
//
//	RECT rect;
//	rect.left = 10;
//	rect.top = 10;
//	rect.right = 400;
//	rect.bottom = 400;
//
//	//////////////////////////////////////////////////////////////////////////////////////////
//	/// vẽ sprite
//	sprite_handler->Begin(D3DXSPRITE_ALPHABLEND);
//
//	D3DXVECTOR3 position(2, 2, 0);
//
//	sprite_handler->Draw(
//		texture,
//		NULL,//&rect,
//		NULL,
//		&position,
//		D3DCOLOR_XRGB(255, 255, 255)
//	);
//
//	sprite_handler->End();
//
//	d3ddev->EndScene();    // ends the 3D scene
//
//	d3ddev->Present(NULL, NULL, NULL, NULL);   // displays the created frame on the screen
//}
//
//
//// this is the function that cleans up Direct3D and COM
//void cleanD3D(void)
//{
//	d3ddev->Release();    // close and release the 3D device
//	d3d->Release();    // close and release Direct3D
//}
