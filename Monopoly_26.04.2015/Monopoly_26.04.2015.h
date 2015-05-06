#pragma once
#include "Game.h"
#include "resource.h"

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
//ATOM				MySecondRegisteredClass(HINSTANCE hInstance);

BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
//LRESULT CALLBACK	GetName(HWND, UINT, WPARAM, LPARAM);


//void MoveExitWindow(const HWND& parentWindow, const HWND& replaceWindow);



int FindCenterDesktopH(void);
int FindCenterDesktopV(void);


void InitGame(HWND hWnd, std::shared_ptr<Game> game);

void RollDices(std::shared_ptr<Game> game);

void ChangePlayerToNext(std::shared_ptr<Game> game);

void EnableCurrentPlayerActions(std::shared_ptr<Game> game);

bool IsTake(std::shared_ptr<Game> game);

void PlayerGoesToExchange(std::shared_ptr<Game> game);

void ShowDices(std::shared_ptr<Game> game);

void GetNamesOfPlayers(vector<string> &names, const int &playerNum);
