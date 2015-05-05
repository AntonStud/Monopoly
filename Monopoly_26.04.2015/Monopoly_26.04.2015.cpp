// Monopoly_26.04.2015.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Monopoly_26.04.2015.h"

#define MAX_LOADSTRING 100

char *controlNames[] = {
	{ "BUTTON" },
	{ "EDIT" },
	{ "LISTBOX" },
	{ "COMBOBOX" }
};

//std::unique_ptr<Game> game(new Game);



// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name


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
	if (!InitInstance (hInstance, nCmdShow))
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
	}

	return (int) msg.wParam;
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

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MONOPOLY));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MONOPOLY);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

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

	static std::shared_ptr<Game> game(new Game);
	static std::vector<HWND>myControls;

	switch (message)
	{
	case WM_CREATE:

		// Create controls

		myControls.push_back(CreateWindowEx(WS_EX_CLIENTEDGE, controlNames[LISTBOX], "",
			WS_CHILD | WS_VISIBLE,
			LIST_X, LIST_Y, LIST_H_SIZE, LIST_V_SIZE, hWnd, (HMENU)ID_COMBO_LIST, hInst, NULL));

		myControls.push_back(CreateWindowEx(NULL, controlNames[BUTTON], "START",
			WS_CHILD | WS_VISIBLE,
			LIST_X * 2 + LIST_H_SIZE, LIST_Y, BTN_H_SIZE, BTN_V_SIZE, hWnd, (HMENU)ID_BTN_START, hInst, NULL));

		myControls.push_back(CreateWindowEx(NULL, controlNames[BUTTON], "ROLL",
			WS_CHILD | WS_VISIBLE,
			LIST_X * 2 + LIST_H_SIZE, LIST_Y * 2 + BTN_V_SIZE, BTN_H_SIZE, BTN_V_SIZE, hWnd, (HMENU)ID_BTN_ROLL, hInst, NULL));

		myControls.push_back(CreateWindowEx(WS_EX_CLIENTEDGE, controlNames[EDIT], "",
			WS_CHILD | WS_VISIBLE | ES_CENTER,
			LIST_X * 2 + LIST_H_SIZE, LIST_Y * 3 + BTN_V_SIZE * 2, BTN_H_SIZE/2, BTN_V_SIZE, hWnd, (HMENU)ID_EDIT_DICE1, hInst, NULL));
		
		myControls.push_back(CreateWindowEx(WS_EX_CLIENTEDGE, controlNames[EDIT], "",
			WS_CHILD | WS_VISIBLE | ES_CENTER,
			LIST_X * 2 + LIST_H_SIZE + BTN_H_SIZE / 2, LIST_Y * 3 + BTN_V_SIZE * 2, BTN_H_SIZE / 2, BTN_V_SIZE, hWnd, (HMENU)ID_EDIT_DICE2, hInst, NULL));


		myControls.push_back(CreateWindowEx(WS_EX_CLIENTEDGE, controlNames[LISTBOX], "",
			WS_CHILD | WS_VISIBLE,
			LIST_X, LIST_Y, LIST_H_SIZE, LIST_V_SIZE, hWnd, (HMENU)ID_COMBO_LIST, hInst, NULL));

		//Create fields

	/*	for (int i = 0; i < game->GetNumOfFields(); i++)
		{



		}
*/
		break;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);


		// Parse the menu selections:
		switch (wmId)
		{

		case ID_BTN_ROLL:

			if (wmEvent == BN_CLICKED)
			{
				
				RollDices(hWnd, game, myControls);
				
				
				//Discard statuses of other players -> need to pay rent



				//TODO: Some needed actions


				ChangePlayerToNext(game);

			}// if (wmEvent == BN_CLICKED)

			break;

		case ID_BTN_START:

			if (wmEvent == BN_CLICKED)
			{
				InitGame(hWnd, game);

			}// if (wmEvent == BN_CLICKED)

			break;

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
//--------------------------------------------------------------------------------------------------

void InitGame(HWND hWnd, shared_ptr<Game> game)
{
	game->InitGame();



}// void InitGame(HWND hWnd, shared_ptr<Game> game)
//--------------------------------------------------------------------------------------------------
void RollDices(HWND hWnd, std::shared_ptr<Game> game, std::vector<HWND>myControls)
{
	int sumOfFringes = 0;

	int prevFringe = -1;

	string fringeText = "";
	string takesText = "";
	string commonTurns = "";

	int curPlayerIndex = game->GetCurrentPlayer();

	int takes = game->GetNumOfTakes(curPlayerIndex);

	// Need to change indexes to enum or something else!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int myControlIndexes = 3;

	for (int i = 0; i < game->GetNumOfDices(); i++)
	{
		int fringe = game->GetRandomFringe(i);
		
		if (prevFringe == fringe)
		{
			game->SetNumOfTakes(curPlayerIndex,++takes);

			takesText = "You threw a take for the " + std::to_string(takes) + " time";

			MessageBox(hWnd, takesText.c_str(), "TAKE", NULL);
		}
		else{

			game->SetNumOfTakes(curPlayerIndex, 0);
		}

		prevFringe = fringe;

		fringeText = std::to_string(fringe);

		SendMessage(myControls[myControlIndexes++], WM_SETTEXT, NULL, (LPARAM)fringeText.c_str());

		sumOfFringes += fringe;

	}// for (int i = 0; i < dices.size(); i++)

	commonTurns = "You need to move your figure into " + std::to_string(sumOfFringes) + " cells";

	MessageBox(hWnd, commonTurns.c_str(), "Number of moves", NULL);

}// RollDices()
//--------------------------------------------------------------------------------------------------
void ChangePlayerToNext(std::shared_ptr<Game> game)
{
	if (!game->GetNumOfTakes(game->GetCurrentPlayer()))
	{
		game->ChangePlayerToNext();

	}// if (!game->GetNumOfTakes())
}// 
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

