// Editor_Window.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Editor_Window.h"

#include "..\\GameEngine_Source\GEApplication.h"

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
    
    Application app = Application ();
    app.Test ();
    //
    //
    //
    // 

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg;

    // GetMessage : 프로세스에서 발생한 메시지를 메시지 큐에서 가져오는 함수
    // 아무것도 없다면, 아무 메시지도 가져오지 않는다.

    // PeekMessage : 메시지 큐에 메시지 유무에 상관없이 함수가 리턴된다.
    // true : 메시지 있음
    // false : 메시지 없음

    // Main message loop:
    while ( true )
    {
        if ( PeekMessage ( &msg , nullptr , 0 , 0 , PM_REMOVE ) )
        {
            if ( msg.message == WM_QUIT )
            {
                break;
            }

            if ( !TranslateAccelerator ( msg.hwnd , hAccelTable , &msg ) )
            {
                TranslateMessage ( &msg );
                DispatchMessage ( &msg );
            }
        }
        else
        {
            // int a = 5;
            // 메시지가 없다면 여기서 처리 -> 게임 로직
        }
    }

    /*while (GetMessage(&msg, nullptr, 0, 0))
    {
        if ( !TranslateAccelerator ( msg.hwnd , hAccelTable , &msg ) )
        {
            TranslateMessage ( &msg );
            DispatchMessage ( &msg );
        }
    }*/

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOW);
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

   // 윈도우 2개도 생성 가능
   // HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // DC : 화면 출력에 필요한 모든 정보를 가지는 데이터 구조체
            // GDI 모듈에 의해 관리
            // 폰트, 선 종류, 면 생상 등
            // 화면 출력에 필요한 모든 경우는 WINAPI에서는 DC를 통해서 작업한다.

            // 파란색 사각형 + 검은 테두리
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);  // 파란색 면 지정, 흰색 면 저장
            Rectangle(hdc, 100, 100, 200, 200);
            DeleteObject(brush);  // 파란색 면 삭제 (brush는 주소일 뿐, 메모리에는 계속 있으니까 지워주어야 함)
            SelectObject(hdc, oldBrush);  // 흰색 면 지정

            // 흰색 원 + 빨간색 테두리
            HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));  // 빨간 펜 생성
            HPEN oldPen = (HPEN)SelectObject(hdc, redPen);  // 빨간 테두리 지정
            Ellipse(hdc, 200, 200, 300, 300);
            DeleteObject(redPen);  // 빨간 펜 메모리 삭제
            SelectObject(hdc, oldPen);  // 검은섹 테두리 지정
            
            // 회색 사각형 + 검은 테두리
            HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);  // 브러쉬를 만들지말고, 기존의 것 사용
            oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);  // 흰색 브러쉬 저장
            Rectangle(hdc, 400, 400, 500, 500);
            SelectObject(hdc, oldBrush);  // 흰색 브러쉬로 되돌리기

            // 흰색 원 + 빨간색 테두리
            HPEN greenPen = CreatePen(PS_DOT, 1, RGB(0, 255, 0));  // 펜 생성
            HBRUSH crossBrush = (HBRUSH)CreateHatchBrush(HS_CROSS, RGB(255, 255, 0));  // 프러쉬 생성
            oldPen = (HPEN)SelectObject(hdc, greenPen);  // 지정
            oldBrush = (HBRUSH)SelectObject(hdc, crossBrush);
            Ellipse(hdc, 500, 500, 600, 600);  // 그리기
            DeleteObject(greenPen);
            DeleteObject(crossBrush);
            SelectObject(hdc, oldPen);
            SelectObject(hdc, oldBrush);

            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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
