// MalaMan.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "main.h"

import EnginePch;
import EngineTypes;
import Game;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE GInst;
HWND      GHWnd;


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM             MyRegisterClass( HINSTANCE );
BOOL             InitInstance( HINSTANCE, i32 );
LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM );

i32 APIENTRY wWinMain( _In_     HINSTANCE hInstance,
                       _In_opt_ HINSTANCE hPrevInstance,
                       _In_     LPWSTR    lpCmdLine,
                       _In_     i32       nCmdShow )
{
    // 윈도우 창 정보 등록
    ::MyRegisterClass( hInstance );

    // 윈도우 창 생성
    if ( !::InitInstance( hInstance, nCmdShow ) )
    {
        return FALSE;
    }

    auto game = std::make_unique< Game >();
    game->Initialize( GHWnd );

    MSG msg{};
    while ( msg.message != WM_QUIT )
    {
        if ( ::PeekMessage( &msg, nullptr, 0, 0, PM_REMOVE ) )
        {
            ::TranslateMessage( &msg );
            ::DispatchMessage( &msg );
        }
        else
        {
            game->Update();
        }
    }

    return static_cast< i32 >( msg.wParam );
}


/// <summary>
/// 창 클래스를 등록합니다.
/// </summary>
ATOM MyRegisterClass( HINSTANCE hInstance )
{
    WNDCLASSEXW wcex
    {
        .cbSize = sizeof( WNDCLASSEX ),
        .style          = CS_HREDRAW | CS_VREDRAW,
        .lpfnWndProc    = ::WndProc,
        .cbClsExtra     = 0,
        .cbWndExtra     = 0,
        .hInstance      = hInstance,
        .hIcon          = LoadIcon( hInstance, MAKEINTRESOURCE( IDI_MALAMAN ) ),
        .hCursor        = LoadCursor( nullptr, IDC_ARROW ),
        .hbrBackground  = reinterpret_cast< HBRUSH >( COLOR_WINDOW+1 ),
        .lpszMenuName   = MAKEINTRESOURCEW( IDC_MALAMAN ),
        .lpszClassName  = L"MalaMan",
        .hIconSm        = LoadIcon( wcex.hInstance, MAKEINTRESOURCE( IDI_SMALL ) )
    };

    return ::RegisterClassExW( &wcex );
}

/// <summary>
/// 인스턴스 핸들을 저장하고 주 창을 만듭니다.
/// 
/// 이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//  주 프로그램 창을 만든 다음 표시합니다.
/// </summary>
BOOL InitInstance( HINSTANCE hInstance, int nCmdShow )
{
    RECT windowRect{ 0, 0, 800, 600 };
    ::AdjustWindowRect( &windowRect, WS_OVERLAPPEDWINDOW, FALSE );

    GInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
    GHWnd = CreateWindowW( L"MalaMan", 
        L"Title", 
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 
        0, 
        windowRect.right - windowRect.left, 
        windowRect.bottom - windowRect.top, 
        nullptr, 
        nullptr, 
        hInstance, 
        nullptr );

   if ( !GHWnd )
      return FALSE;

   ::ShowWindow( GHWnd, nCmdShow );
   ::UpdateWindow( GHWnd );

   return TRUE;
}

/// <summary>
/// 주 창의 메시지를 처리합니다.
/// </summary>
LRESULT CALLBACK WndProc( HWND GHWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    switch ( message )
    {
    case WM_COMMAND:
        {
            i32 wmId = LOWORD( wParam );
            // 메뉴 선택을 구문 분석합니다:
            switch ( wmId )
            {
            case IDM_EXIT:
                ::DestroyWindow( GHWnd );
                break;
            default:
                return DefWindowProc( GHWnd, message, wParam, lParam );
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = ::BeginPaint( GHWnd, &ps );
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            ::EndPaint( GHWnd, &ps );
        }
        break;
    case WM_DESTROY:
        ::PostQuitMessage( 0 );
        break;
    default:
        return DefWindowProc( GHWnd, message, wParam, lParam );
    }
    return 0;
}
