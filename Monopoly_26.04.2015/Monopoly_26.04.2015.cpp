// Monopoly_26.04.2015.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Monopoly_26.04.2015.h"

#define MAX_LOADSTRING 100

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

	static auto game = std::make_shared<Game>();
	//static std::vector<HWND>myControls;
	//static std::vector<HWND>playFields;
	//static std::vector<HWND>

	switch (message)
	{
	case WM_CREATE:

		// Create controls
		game->CreateControls(hWnd, hInst);

		// Create fields
		//game->CreateFields(hWnd, hInst);

		// Create places
		//game->CreatePlayerPlaces(hWnd, hInst);

		break;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		
		switch (wmId)
		{

		case ID_BTN_ROLL:

			if (wmEvent == BN_CLICKED)
			{
				//TODO: Discard statuses of other players -> need to pay rent
				//TODO: Disable actions of current player

				RollDices(game);

				int takes = 0;

				int currPlayer = game->GetCurrentPlayer();

				if (IsTake(game))
				{
					takes = game->GetNumOfTakes(currPlayer);

					game->SetNumOfTakes(currPlayer, ++takes);

					//ShowMessage();

				}
				else{

					game->SetNumOfTakes(currPlayer, takes);
				}

				if (takes == 3)
				{

					PlayerGoesToExchange(game);

					break;
				}

				ShowDices(game);

				//ChangePlayerPosition(game);

				//MakeFieldActions(game);

				//if (!GetNumOfTakes(playerNum) && !GameIsOver())
				//{
				//	ChangePlayerToNext(game);
				//}// 


			}// if (wmEvent == BN_CLICKED)

			break;
		case ID_BTN_START:

			if (wmEvent == BN_CLICKED)
			{
				InitGame(hWnd, game);

			}// if (wmEvent == BN_CLICKED)

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

		case IDM_NAMES:
			
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
void InitGame(HWND hWnd, shared_ptr<Game> game)
{
	
	int playerNum = game->GetNumOfPlayers();

	vector<string> names = { "Vasia", "Petya" };

	//GetNamesOfPlayers(names, playerNum);

	if (!game->IsPlayersVectorEmpty())
	{
		game->PlayersVectorReset();
	}

	//for (int i = 0; i < playerNum; i++)
	//{
	//	game->InitPlayer(names[i]);

	//}// for (int i = 0; i < playerNum; i++)

	game->InitDices();

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

	int fieldIndex = game->GetIndexOfField(ID_EXCHANGE_FIELD);

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


	// Получаем центр рабочего стола
	int center = FindCenterDesktopH();

	int xPosWnd = center - WIDTH / 2;

	center = FindCenterDesktopV();

	int yPosWnd = center - HEIGHT / 2;


	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		xPosWnd, yPosWnd, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}
