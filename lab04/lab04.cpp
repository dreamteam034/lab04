// lab04.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "lab04.h"

#include "Figure.h"
#include "FigureList.h"

<<<<<<< HEAD
#include <fstream>
#include <ctype.h>
=======
#include <stdio.h>
#include <commdlg.h>
>>>>>>> master

#define MAX_LOADSTRING 100

float Scale = 1;

using namespace std;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

CHOOSECOLOR cc;
static COLORREF acrCustClr[16];

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
	ZeroMemory(&cc, sizeof(cc));
	cc.lStructSize = sizeof(cc);
	cc.lpCustColors = (LPDWORD)acrCustClr;
	cc.Flags = CC_FULLOPEN | CC_RGBINIT;

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB04, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB04));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
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
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB04));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB04);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
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
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

<<<<<<< HEAD

void processInputFile(char *path) {
	const unsigned int bufferLength = 32, typeLength = 16, valueLength = 8, maxLength = 9;
	char buffer[bufferLength], *bufferPtr = buffer, c, type[typeLength], c_value[valueLength];
	int tmp;
	bool onStart = true; //	Мы только начали считывать информацию о фигуре 
	ifstream in("input.txt");

	while (in.eof()) {
		in >> c;

		
		if (isalpha(c)) {
			if (onStart) {
				*bufferPtr++ = c;
			}
		}
		if (c == '=') {
			*bufferPtr = '\n';
			strcpy_s(type, buffer);
		}
		else if (c == '{') {
			while (in >> c) {
				if (isalpha(c)) {
					*bufferPtr++ = c;
				}
				else if (c == '=') {
					*bufferPtr = '\0';
					bufferPtr = c_value;

					for (int i = 0; i < sizeof(param) / sizeof(char*); i++) {
						if (!strcmp(buffer, param[i])) {
							tmp = i;
						}
					}
				}
				else if (c == ';') {
					*bufferPtr = '\0';
					bufferPtr = buffer;

					inputedParams[tmp] = atoi(c_value); 
					
				}
				else if (c == '}') {
					break;
				}
			}
			bufferPtr = buffer;
		}
	}
}


FigureList list; 
Figure a = Figure({ 50, 60 }, {200, 300}, "circle");

void update(HDC hdc) {
	list = FigureList();
	list.add(a);
	list.add({ { 10, 20 }, { 30, 40 }, "circle" });
	list.add({ { 20, 30 },{ 40, 50 }, "circle" });
	list.add({ { 400, 500 }, { 600, 700 }, "circle" });

	list.drawList(hdc, Scale);
}


=======
>>>>>>> master
char *szToolById[] = {
	"line",
	"circle",
	"rectangle",
	"rectangle_rounded"
};

int iCurrentTool = -1;
bool bDrawTemp = false;
FigureList list;
Point startMousePos = { 0, 0 }, currentMousePos = { 0, 0 };

DWORD rgbBackground = RGB(0, 0, 0);
DWORD rgbBorder = RGB(0, 0, 0);


//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
<<<<<<< HEAD
	POINT oldMousePos = { 0, 0 }, newMousePos = { 0, 0 };
	BOOL LBTisDown = false;
	

	wchar_t buffer[64];
=======

>>>>>>> master

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
			case ID_FILE_OPEN:

				break;
			case ID_FILE_SAVE:

				break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
			case IDM_TOOLS_SELECTION:
				iCurrentTool = -1;
				break;
			case IDM_TOOLS_LINE:
				iCurrentTool = 0;
				break;
			case IDM_TOOLS_CIRCLE:
				iCurrentTool = 1;
				break;
			case IDM_TOOLS_RECTANGLE:
				iCurrentTool = 2;
				break;
			case IDM_TOOLS_ROUNDED_RECTANGLE:
				iCurrentTool = 3;
				break;
			case IDM_COLORS_BACKGROUND:
				cc.hwndOwner = hWnd;
				cc.rgbResult = rgbBackground;
				if (ChooseColor(&cc) == TRUE)
					rgbBackground = cc.rgbResult;

				break;
			case IDM_COLORS_BORDER:
				cc.hwndOwner = hWnd;
				cc.rgbResult = rgbBorder;
				if (ChooseColor(&cc) == TRUE)
					rgbBorder = cc.rgbResult;

				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
		
        break;
    case WM_PAINT:
        {
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
			list.drawList(hdc, 1);

			if (bDrawTemp)
			{
				Figure TempFigure(startMousePos, currentMousePos, szToolById[iCurrentTool]);
				TempFigure.draw(hdc, 1);
			}

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_LBUTTONDOWN:
		{
			LBTisDown = true;
			swprintf(buffer, _countof(buffer), L"%d\n", LBTisDown);
			OutputDebugString(buffer);
			Scale = Scale - 0.02;
			GetCursorPos(&oldMousePos);
			
			RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
			startMousePos = { LOWORD(lParam), HIWORD(lParam) };
			if (iCurrentTool >= 0)
			{
				// Let's start temp drawing
				bDrawTemp = true;
			}
		}
		break;
	case WM_LBUTTONUP:
		{
			Scale = Scale + 0.02;
			RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
			bDrawTemp = false;

			if (iCurrentTool >= 0)
			{
				// Let's create our figure
				list.add({ startMousePos, currentMousePos, szToolById[iCurrentTool] });
				InvalidateRect(hWnd, NULL, TRUE);
			}
			else
			{
				// Let's select figure
				unsigned length = list.getLength();
				for (unsigned i = length; i > 0; i--)
				{
					
				}
			}
		}
		break;
	case WM_MOUSEMOVE:
		{
			currentMousePos = { LOWORD(lParam), HIWORD(lParam) };
			if (bDrawTemp && iCurrentTool >= 0)
			{
				// Let's redraw current figure
				InvalidateRect(hWnd, NULL, TRUE);
			}
		}
		break;
	case WM_RBUTTONDOWN:
		{
			
		}
		break;
	case WM_KEYDOWN:
		{
			switch (wParam)
			{
			case VK_DELETE:
				
				break;
			}
		}
		break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

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
}
