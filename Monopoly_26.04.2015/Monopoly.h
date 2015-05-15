#pragma once

#include "Game.h"
#include "resource.h"

#define MAX_LOADSTRING 100

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
//ATOM				MySecondRegisteredClass(HINSTANCE hInstance);

BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	GroupBoxProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow);

ATOM MyRegisterClass(HINSTANCE hInstance);

void EnableCurrPlayerControls();

//void InitGame(HWND hWnd, std::shared_ptr<Game> game, HWND start);
//
//void RollDices(std::shared_ptr<Game> game);
//
//void ChangePlayerToNext(std::shared_ptr<Game> game);
//
//void EnableCurrentPlayerActions(std::shared_ptr<Game> game);
//
//bool IsTake(std::shared_ptr<Game> game);
//
//void PlayerGoesToExchange(std::shared_ptr<Game> game);
//
//void ShowDices(std::shared_ptr<Game> game);
//
//void GetNamesOfPlayers(vector<string> &names, const int &playerNum);
