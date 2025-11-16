// course_work.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "course_work.h"
#include "circ_func.h"
#include "dot.h"
#include "stack.h"
#include <vector>
#include <windowsx.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_COURSEWORK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_COURSEWORK));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_COURSEWORK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_COURSEWORK);
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

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //static Dot d, d2;
    //static ElipseWithText e, фe2;
    static vector<Figure*> figures;
    static Figure* selected = nullptr;


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
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_CREATE:
    {
        //e.Set_Colour(0, 255, 0);
        //e.SetRadius(126);
        //e.SetX(50);    // НАЧАЛЬНАЯ ПОЗИЦИЯ
        //e.SetY(100);   // ОТКУДА НАЧИНАЕТСЯ ДВИЖЕНИЕ
        figures.push_back(new ElipseWithText(L"Hello World!"));
        figures.push_back(new Dot());
        figures.push_back(new Dot());
        figures.push_back(new ElipseWithText(L"Проверка на нормальный перенос текста!"));

        figures[0] -> SetRadius(50);
        figures[0] -> Set_Colour(100,40,70);        
        figures[1] -> SetRadius(130);
        figures[1] -> Set_Colour(59,140,200);
        figures[1] -> SetY(59);        
        figures[2] -> SetRadius(80);
        figures[2] -> Set_Colour(59,40,20);
        figures[2] -> SetY(99);
        figures[2] -> SetX(160);
        figures[3]->SetRadius(130);
        figures[3]->Set_Colour(109, 40, 200);
        figures[3]->SetY(59);
        selected = figures[0];
        break;
    }
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
                        //Одиночный вызов 

            //d.Set_Colour(100,150,253);
            //d.Draw(hdc, 189, 90, 221);
            //d.Erase(hdc);
            //d.SetRadius(4);
            //d.Set_Colour(10, 15, 25);
            //d.Draw (hdc, 289, 190, 21);

            //d2.Draw(hdc, d2.X(), d2.Y(), d2.R()); // рисуем текущую позицию
            //e2.Set_Colour(0, 255, 0);
            //e2.Draw(hdc, 89, 190, 121);
            //e2.Erase(hdc);
            //e.SetText(L"Это пример многострочного текста,который автоматически переносится");
            //e.Draw(hdc, e.X(), e.Y(), e.R()); // рисуем текущую позицию

            for (Figure* f : figures)
                f->Draw(hdc, f->X(), f->Y(), f->R());
           
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_LBUTTONDOWN:
    {
        int mouseX = GET_X_LPARAM(lParam);
        int mouseY = GET_Y_LPARAM(lParam);

        // простая проверка для круга: расстояние до центра меньше радиуса
        for (Figure* f : figures)
        {
            int dx = mouseX - f->X();
            int dy = mouseY - f->Y();
            if (dx * dx + dy * dy <= f->R() * f->R())  // клик внутри круга
            {
                selected = f;
                break;
            }
        }

        InvalidateRect(hWnd, NULL, TRUE); // перерисовать окно
    }
    break;
    case WM_KEYDOWN:
    {
        if (!selected) break;
        switch (wParam)
        {
        case VK_LEFT:  selected->SetX(selected->X() - 5); break;
        case VK_RIGHT: selected->SetX(selected->X() + 5); break;
        case VK_UP:    selected->SetY(selected->Y() - 5); break;
        case VK_DOWN:  selected->SetY(selected->Y() + 5); break;
        }

        InvalidateRect(hWnd, NULL, TRUE);  //  перерисовать окно
    }
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

