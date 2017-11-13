#include "CGame.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CGame &game = CGame::GetInstance();
	game.InitConstructor(hInstance, L"Sample Sprite Animation", GAME_SCREEN_RESOLUTION_1024_640_24, 0, 60);

	game.Init();

	game.Run();

	game.Terminate();

	return 0;
}