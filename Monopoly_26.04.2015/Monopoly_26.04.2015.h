#pragma once
#include "Game.h"
#include "resource.h"

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


typedef unsigned int ui;

enum INIT {
	FIRST_TIMER = 1, SECOND_TIMER, REDUCE = 5,
	HALF = 2, TIME_MOVE = 10, TIME_MOVE2 = 200,
	POSX = 300, POSY = 250, WIDTH = 750, HEIGHT = 500,
	BTN_H_SIZE = 150, BTN_V_SIZE = 25, X_FIRSTBTN_POZ = 10, Y_FIRSTBTN_POZ = 10,
	V_SHIFT = 5, H_SHIFT = 10, STOP_SIZE = 200, EDIT_BOX_V_SIZE = 30, EDIT_BOX_H_SIZE = 250,
	EDIT_BOX_SINGLE_V_SIZE = 30, NAME_SIZE = 100, FEE_SIZE = 8,
	LIST_X = 20, LIST_Y = 20, LIST_H_SIZE = 280, LIST_V_SIZE = 400,
	ONE = 1, TWOHUNDRED = 200
};

//void MoveExitWindow(const HWND& parentWindow, const HWND& replaceWindow);

enum CTRLSNMS {
	BUTTON, EDIT, LISTBOX, COMBOBOX
};

enum IDENT {

	ID_BTN_DOWN = 1000, ID_COMBO_LIST, ID_BTN_ROLL, ID_BTN_START, ID_EDIT_DICE1, ID_EDIT_DICE2

};

int FindCenterDesktopH(void);
int FindCenterDesktopV(void);


void InitGame(HWND hWnd, std::shared_ptr<Game> game);
void RollDices(HWND hWnd, std::shared_ptr<Game> game, std::vector<HWND>myControls);

void ChangePlayerToNext(std::shared_ptr<Game> game);
