#pragma once

#include "resource.h"
#include "Game.h"

LRESULT CALLBACK GroupBoxProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

enum IDENT {
	
	

	IDB_GROUPBOX = 500, IDB_BTN_OK, IDB_BTN_CANCEL, IDB_BTN_SUBMIT, IDB_BTN_ROLL,
	ID_EDIT_DICE1, ID_EDIT_DICE2, ID_LIST_PROPERTY, ID_LIST_BUYERS,
	IDB_BTN_SELL_PROPERTY, IDB_EDIT_SUM_OF_SELL, IDB_BTN_RENT_PROPERTY,
	IDB_BTN_BAIL_PROPERTY, IDB_BTN_BUYOUT_PROPERTY,
	IDB_BTN_BUY_FILIATION, IDB_BTN_SELL_FILIATION, IDB_BTN_BUY_ENTITY, IDB_BTN_SELL_ENTITY,
	IDB_BTN_STOCK_FREE, IDB_BTN_STOCK_PAY, IDB_LABEL_ENTER_NAME, ID_EDIT_NAME, IDB_BTN_SUBMIT_NAME,
	IDB_LABEL_CAPITAL_TITLE, IDB_EDIT_CAPITAL,
	IDB_TERMINATE_GROUPBOX,


	ID_BTN_START = 1000, ID_PLAYER_LIST_LABEL, ID_PLAYER_LIST, ID_BTN_SURPRISE,
	ID_BTN_NOTIFICATION,
	/*ID_LIST_PLAYERS = 1000, ID_EDIT_NAME, ID_LABEL_NAME, */


	FIELD_START = 2000, FIELD_END = 2039,
	CHECK_START = 3000, CHECK_END = 3039

};


void InitGame(std::shared_ptr<Game> &game, HWND &playersListLabel, HWND &playersList, 
	std::vector<HWND> &groupControls, std::vector<HWND> &fields, 
	std::vector<HWND> &checks, HWND &surprise, HWND &notification);

void EnableCurrPlayerControls(std::shared_ptr<Game> &game, HWND &playersList, 
	std::vector<HWND> &groupControls, std::vector<HWND> &checks);

void GetNames(std::vector<HWND> &group, std::shared_ptr<Game> &game);

void FillPlayersList(const std::shared_ptr<Game> &game, HWND &playersList);

void ShowFields(std::vector<HWND> &fields);

