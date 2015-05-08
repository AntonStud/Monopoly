// Monopoly_26.04.2015.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Monopoly.h"

#define MAX_LOADSTRING 100

static WNDPROC OldGroupBoxProc;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name


//static TCHAR WindowNameClass[] = _T("GetName");

//static TCHAR TitleName[] = _T("Print name");



//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;



	static HWND start, hWndGroupBox, hWndOkBtn;
	

	static auto game = std::make_shared<Game>();
	//static std::vector<HWND>myControls;
	//static std::vector<HWND>playFields;
	//static std::vector<HWND>

	switch (message)
	{
	case WM_CREATE:
		start = CreateWindowEx(NULL, "BUTTON", "START", WS_CHILD | WS_VISIBLE,
			500, 200, 300, 200, hWnd, (HMENU)ID_BTN_START, hInst, NULL);

		hWndGroupBox = CreateWindowEx(0, _T("BUTTON"), _T("Это GroupBox"),
			WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
			10, 10, 400, 300,
			hWnd, 0, hInst, 0);

		hWndOkBtn = CreateWindowEx(0, _T("BUTTON"), _T("Это кнопка в GroupBoxе"),
			WS_CHILD | WS_VISIBLE,
			10, 20, 250, 25,
			hWndGroupBox, (HMENU)IDB_BTN_OK, hInst, 0);

		OldGroupBoxProc = (WNDPROC)::GetWindowLongPtr(hWndGroupBox, GWLP_WNDPROC);
		::SetWindowLongPtr(hWndGroupBox, GWLP_WNDPROC, (LONG)GroupBoxProc);

		break;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		switch (wmId)
		{

		

		case IDB_BTN_OK:

			if (wmEvent == BN_CLICKED)
			{

			}

			break;

		case ID_BTN_START:

			if (wmEvent == BN_CLICKED)
			{
				//InitGame(hWnd, game, start);

				InitFields();

				InitChecks();

				InitControls();

				InitSurprize();

				InitNotify();

				InitDices();

				InitPlayers();

				ShowAllGameFields();

				GetCurrentPlayer();

				EnableCurrPlayerControls();

			}// if (wmEvent == BN_CLICKED)

			break;

		case ID_BTN_ROLL:

			if (wmEvent == BN_CLICKED)
			{
				UnsetPropertiesStatusHaveToPayRent();

				DisablePlayerPossibilities();

				RollDices();

				ShowDices();

				if (IsTake())
				{
					GetPlayerTakes();

					ShowMessage("It is your" i " take");
					
					IncreasePlayerTakes();

					UnsetPlayerStatusIsInExchange();

					SetPlayerTurnsInExchangeToZero();

				}
				else{

					SetPlayerTakesToZero();

					if (IsPlayerInExchange())
					{
						IncreasePlayerTurnsInExchange();
					}

				}// if (IsTake()) else

				if (GetPlayerTurnsInExchange == 3)
				{
					SetPlayerStatusIsInExchange(false);
					
					SetPlayerTurnsInExchangeToZero();

					TransactPlayerMoney(-500);

					if (CheckTheBuncrapcy()||CheckTheGameOver())
					{
						break;
					}// if (CheckTheBuncrapcy()||CheckTheGameOver())

				}//if (GetPlayerTurnsInExchange == 3)

				if (GetPlayerTakes() == 3)
				{
					SetPlayerTakesToZero();

					ShowMessage("You have to go to exchange");

					SetPlayerStatusIsInExchange(true);

					break;

				}// if (GetPlayerTakes() == 3)

				curpos = GetPlayerPosition();

				moves = GetNumOfMoves();

				nextPosition = curpos + moves;

				ShowMessage("You have to move in " nextPosition "cells");

				UncheckCheck(curpos);

				numOfFields = GetNumOfFields();

				if (nextPosition >= numOfFields)
				{
					nextPosition -= numOfFields;

					if (!nextPosition)
					{
						ShowMessage("You`ve got money");

							TransactPlayerMoney(STARTMONEY);
					}

					
				}

				if (IsPlayerInExchange())
				{
					nextPosition = exchange;
				}

				EnableCheck(nextPosition, true);

			}//if (wmEvent == BN_CLICKED)

			break;


		case ID_CHECK_START:
		case ID_CHECK_END:

			if (wmEvent == BN_CLICKED)
			{
				currPlayer = GetCurrentPlayer();
				
				curpos = GetPlayerPosition();

				moves = GetNumOfMoves();

				nextPosition = curpos + moves;

				numOfFields = GetNumOfFields();

				if (nextPosition >= numOfFields)
				{
					nextPosition -= numOfFields;

					TransactPlayerMoney(STARTMONEY);
				}

				if (IsPlayerInExchange())
				{
					nextPosition = exchange;
				}

				EnableCheck(nextPosition, false);

				ChangePlayerPos(nextPosition);

				
				FieldAction()
				{
					GetFieldType();

					switch (type)
					{
					case Property:

						CheckPropertyOwner();

						if (owner == bank)
						{
							SellPropertyProcedure()
							{
								ShowMessage("You entered " + name);
								DlgBox("Do you want to buy it")
								{
									if (OK)
									{
										CheckPlayerCapital();

										if (capital >= GetPropertyPrice())
										{
											TransactMoney(-GetPropertyPrice());

											PushPropertyToPlayer();

											ChangePropertyStatusHasOwner();

											ChangePropertyOwnerName();
										
										}else{

											ShowMessage("You have no enough money");

											//AuctionProcedure();
										}

									}
									else{

										//AuctionProcedure();
									}
								
								}//DlgBox("Do you want to buy it")



							}//SellPropertyProcedure()

						}else if(owner == currPlayer.ID){

							ShowMessage("You entered your own property");

						}else if(!IsPropertyInDeposit()){

							SetPropertyStatusHasIntruder(currPlayer);

						}

						break;

					case SpecialField:

						switch (GetSpecialType)
						{
						case GIVE_MONEY:

							TransactMoney(STARTMONEY);

							break;

						case TAKE_MONEY:

							TransactMoney(-STARTMONEY);

							break;

						case SURPRISE:

							EnableSurprise();

							return;

							break;

						case NOTIFICATION:

							EnableNotification();

							return;

							break;

						case MAKLER:

							SetPlayerTakesToZero();

							ShowMessage("You have to go to exchange");

							SetPlayerStatusIsInExchange(true);

							SetPlayerTurnsInExchangeToZero();

							break;

						case START:

							ShowMessage("You are at the start");

							ShowMessage("You`ve got money");

							TransactPlayerMoney(STARTMONEY);

							break;

						case REST:

							SetPlayerOnRest(true);

							SetPlayerTakesToZero();

							break;

						case EXCHANGE:

							if (!GetPlayerStatusIsInExchange())
							{
								ShowMessage("Simple visit of an exchange");
							}

							break;

						}

						break;

					}//switch (type)

				}//FieldAction()


				if (!GetPlayerNumOfTakes())
				{

					int i = ++currPlayer;
					
					for (; i <= players.size(); i++)
					{
						if (i == players.size())
						{
							 i = 0;
						}

						if (IsPlayerOnRest(i))
						{
							SetPlayerOnRest(false);

							ShowMessage("Player" + name + "pass");

						}else{

							break;

						}// if else


					}// for (; i <= players.size(); i++)

					ChangePlayer(i);

				}// if (!GetPlayerNumOfTakes())

				currPlayer = GetCurrentPlayer();

				EnableCurrPlayerControls(currPlayer);

			}//if (wmEvent == BN_CLICKED)

			break;

		/*case ID_BTN_PASS_TURN:

			SetPlayerOnRest(false);

			ChangePlayer();*/



			break;

	/*	case ID_BTN_BUY:

			break;

		case ID_BTN_SELL:

			break;

		case ID_BTN_BAIL:

			break;

		case ID_LST_PROPERTY:

			break;

			case ID_LST_*/

		//}

		//break;

		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
//--------------------------------------------------------------------------------------------------
void InitGame(HWND hWnd, shared_ptr<Game> game, HWND start)
{
	
	ShowWindow(start, SW_HIDE);

	

	// Create controls
	game->CreateControls(hWnd, hInst);

	//ShowWindow(game->GetControl(game->GetControlNumber(2000)), SW_SHOW);
	//
	//int playerNum = 2;//game->GetNumOfPlayers();

	//vector<string> names = {"Vasya", "Petya"};

	//if (!game->IsPlayersVectorEmpty())
	//{
	//	game->PlayersVectorReset();
	//}

	////for (int i = 0; i < playerNum; i++)
	////{
	////	game->InitPlayer(names[i]);

	////}// for (int i = 0; i < playerNum; i++)

	//game->InitDices();


	//

	////MessageBox(hWnd, "Fail", "Add control", NULL);

	// Create fields
	//game->CreateFields(hWnd, hInst);

	// Create places
	//game->CreatePlayerPlaces(hWnd, hInst);

	//game->InitFields();

	//EnableCurrentPlayerActions(game);

}// void InitGame(HWND hWnd, shared_ptr<Game> game)
//--------------------------------------------------------------------------------------------------
void EnableCurrentPlayerActions(std::shared_ptr<Game> game)
{
	game->ChangeCurrentPlayer(game->GetCurrentPlayer());

	//ShowMessage();

}// void EnableCurrentPlayerActions(std::shared_ptr<Game> game)
//--------------------------------------------------------------------------------------------------
void RollDices(std::shared_ptr<Game> game)
{
	game->RollDices();

}// RollDices()
//--------------------------------------------------------------------------------------------------
void ChangePlayerToNext(std::shared_ptr<Game> game)
{
	int currPlayer = game->GetCurrentPlayer();

	if (++currPlayer == game->GetNumOfPlayers())
	{
		currPlayer = 0;

	}// if (++currPlayer == game->GetNumOfPlayers())
	
	EnableCurrentPlayerActions(game);

}// void ChangePlayerToNext(std::shared_ptr<Game> game)
//--------------------------------------------------------------------------------------------------
bool IsTake(std::shared_ptr<Game> game)
{
	bool isTake = false;

	int prevFringe = game->GetSavedFringe(0);

	int numOfDices = game->GetNumOfDices();

	int i;
	
	for ( i = 1; i < numOfDices; i++)
	{
		int nextFringe = game->GetSavedFringe(i);

		if (prevFringe != nextFringe) break;

	}// for (int i = 1; i < numOfDices; i++)

	if (i == numOfDices)
	{
		isTake = true;

	}// if (i == numOfDices)

	return isTake;

}// bool IsTake(std::shared_ptr<Game> game)
//--------------------------------------------------------------------------------------------------

void PlayerGoesToExchange(std::shared_ptr<Game> game)
{
	int currPlayer = game->GetCurrentPlayer();
	
	game->SetNumOfTakes(currPlayer, 0);

	int fieldIndex = game->GetIndexOfField(FIELD_EXCHANGE);

	game->ChangePlayerPosition(currPlayer, fieldIndex);

	//ShowMessage();

	ChangePlayerToNext(game);

}// void PlayerGoesToExchange(std::shared_ptr<Game> game)
//--------------------------------------------------------------------------------------------------
void  ShowDices(std::shared_ptr<Game> game)
{



}//void  ShowDices(std::shared_ptr<Game> game)
//--------------------------------------------------------------------------------------------------
int FindCenterDesktopH(void)
{
	// Получаем хэндл рабочего стола
	HWND hDesktop = GetDesktopWindow();

	// Переменная для хранения координат углов рабочего стола
	RECT rectDesktop;

	// Записываем углы рабочего стола в переменную
	GetWindowRect(hDesktop, &rectDesktop);

	return (rectDesktop.right - rectDesktop.left) / 2;

}// int FindCenterDesktopH(void)
//--------------------------------------------------------------------------------------------------
int FindCenterDesktopV(void)
{
	// Получаем хэндл рабочего стола
	HWND hDesktop = GetDesktopWindow();

	// Переменная для хранения координат углов рабочего стола
	RECT rectDesktop;

	// Записываем углы рабочего стола в переменную
	GetWindowRect(hDesktop, &rectDesktop);

	return (rectDesktop.bottom - rectDesktop.top) / 2;
}// int FindCenterDesktopV(void
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//void GetNamesOfPlayers(vector<string> &names, const int &playerNum)
//{
//	string name = "";
//	
//	for (int i = 0; i < playerNum; i++)
//	{
//		while (!name.size())
//		{
//			//SendMessage
//
//		}//
//		
//		names.emplace_back(name);
//
//		name = "";
//
//	}// for (int i = 0; i < playerNum; i++)
//
//}//void GetNamesOfPlayers(vector<string> &names, const int &playerNum)
//--------------------------------------------------------------------------------------------------

//LRESULT CALLBACK GetName(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	int wmId, wmEvent;
//	PAINTSTRUCT ps;
//	HDC hdc;
//	
//	UNREFERENCED_PARAMETER(lParam);
//
//	static std::vector<HWND> GetNameControls;
//
//	switch (message)
//	{
//	case WM_CREATE:
//
//		GetNameControls.emplace_back(CreateWindowEx(WS_EX_CLIENTEDGE, controlNames[EDIT], "",
//			WS_CHILD | WS_VISIBLE,
//			LIST_X, LIST_Y, LIST_H_SIZE, LIST_V_SIZE, hDlg, (HMENU)ID_GETNAME_EDIT, hInst, NULL));
//
//		GetNameControls.emplace_back(CreateWindowEx(WS_EX_CLIENTEDGE, controlNames[BUTTON], "",
//			WS_CHILD | WS_VISIBLE,
//			LIST_X, LIST_Y, LIST_H_SIZE, LIST_V_SIZE, hDlg, (HMENU)ID_GETNAME_OK, hInst, NULL));
//		
//		break;
//
//	case WM_COMMAND:
//		wmId = LOWORD(wParam);
//		wmEvent = HIWORD(wParam);
//
//		// Parse the menu selections:
//		switch (wmId)
//		{
//		case ID_GETNAME_OK:
//
//			if (wmEvent == BN_CLICKED)
//			{
//				
//
//			}// if (wmEvent == BN_CLICKED)
//			break;
//
//		}
//	}
//	return (INT_PTR)FALSE;
//
//}// LRESULT CALLBACK GetName(HWND, UINT, WPARAM, LPARAM)
////--------------------------------------------------------------------------------------------------
// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}// INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MONOPOLY, szWindowClass, MAX_LOADSTRING);

	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MONOPOLY));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}//while (GetMessage(&msg, NULL, 0, 0))

	return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInst;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MONOPOLY));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_MONOPOLY);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//ATOM MySecondRegisteredClass(HINSTANCE hInstance)
//{
//	WNDCLASSEX w;
//
//	memset(&w, 0, sizeof(w));
//
//	w.cbSize = sizeof(WNDCLASSEX);
//	w.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | WS_CHILD;
//	w.lpfnWndProc = GetName;
//	w.cbClsExtra = 0;
//	w.cbWndExtra = 0;
//	w.hInstance = hInst;
//	w.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MONOPOLY));
//	w.hCursor = LoadCursor(NULL, IDC_ARROW);
//	w.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	w.lpszMenuName = NULL;
//	w.lpszClassName = WindowNameClass;
//	w.hIconSm = LoadIcon(w.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//	
//	return RegisterClassEx(&w);
//}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable


	//// Получаем центр рабочего стола
	//int center = FindCenterDesktopH();

	//int xPosWnd = center - WIDTH / 2;

	//center = FindCenterDesktopV();

	//int yPosWnd = center - HEIGHT / 2;


	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		0, 0, WIDTH, HEIGHT, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


LRESULT CALLBACK GroupBoxProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		::CallWindowProc(WndProc, GetParent(hWnd), uMsg, wParam, lParam);
		break;
	}

	return ::CallWindowProc(OldGroupBoxProc, hWnd, uMsg, wParam, lParam);
}


EnableCurrPlayerControls(currPlayer)
{

	EnableGroupBox(currPlayerName());
	
	EnableRollDices();


	if (PlayerIsInExchange())
	{
		EnableBtnPayToGoFromExchange();

		if (HasCardToGoFromExchange())
		{
			EnableBtnGoFromExchange();

		}
	}
	
	if (PlayerHasProperty){

		EnablePropertyList()
		{

			if (!IsPropertyInDeposit() && !PropertyHasFilial() && !PropertyHasEntity())
			{
				EnableBtnToDeposit();

				//EnableBtnSellToOtherPlayer();

				//EnableWindowSumOfSell();

				EnableListOfOtherPlayers();

			}

			if (IsPropertyInDeposit() )
			{
				EnableBtnBuyOut();
			}


			if (IsPropertyInGroup())
			{
				if (PropertyHasFilial())
				{

					EnableBtnSellFilial();

				}

				if (GetNumOfFilials() < 3)
				{
					EnableBtnBuyFilial();

				}

				if (GetNumOfFilials() == 3)
				{
					EnableBtnBuyEntity();

				}
			
			}

			if (!PropertyHasEntity())
			{
				EnableBtnSellEntity();

			}

			if (PropertyHasIntruder)
			{
				EnableBtnAskForRent();

			}

		}

	}

}
