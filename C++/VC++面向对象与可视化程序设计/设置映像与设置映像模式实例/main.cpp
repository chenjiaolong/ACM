/**
 * 程序运行时，初始阶段按模式MM_TEXT 绘图
 * 图形为一个坐标系，一逻辑坐标系的原点，
 * X、Y轴分别是逻辑坐标系的X、Y轴。单用户
 * 按下“A” 键“B” 键 “C” 键时，产生WM_CHAR
 * 消息，将映像模式分别设置为ISOTROPIC
 * 、ANISOTROPIC或LOMETRIC，同时电泳InvalidateRect
 * 函数刷新用户区
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int nMode = MM_TEXT;

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInst,
                   LPSTR lpszCmd,
                   int nCmdShow
                  )
{
    HWND hwnd;
    MSG Msg;
    WNDCLASS wndclass;
    char lpszClassName[] = "映像模式";
    char lpszTitle[] = "My_Map_Mode";
    wndclass.style = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH ) GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = lpszClassName;

    if(! RegisterClass(& wndclass))
    {
        MessageBeep(0);
        return FALSE;
    }

    hwnd = CreateWindow(
               lpszClassName,
               lpszTitle,
               WS_OVERLAPPEDWINDOW,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               NULL,
               NULL,
               hInstance,
               NULL
           );
    ShowWindow(hwnd, nCmdShow); // 显示窗口
    UpdateWindow(hwnd); // 绘制用户区
    while(GetMessage(& Msg, NULL, 0, 0)) // 消息循环
    {
        TranslateMessage(& Msg);
        DispatchMessage(& Msg);
    }
    return Msg.wParam; // 消息循环结束时将信息返回系统
}

// 窗口函数
LRESULT CALLBACK WndProc(
                         HWND hwnd,
                         UINT message,
                         WPARAM wParam,
                         LPARAM lParam
                         )
{
    HDC hdc;
    PAINTSTRUCT ps;
    HPEN hPen;
    switch(message)
    {
    case WM_CHAR :
        if(wParam == 'a' || wParam == 'A')
            nMode = MM_ISOTROPIC;
        else if(wParam == 'b' || wParam == 'B')
            nMode = MM_ANISOTROPIC;
        else if(wParam == 'c' || wParam == 'C')
            nMode = MM_LOMETRIC;
        else ;
        InvalidateRect(hwnd, NULL, 1); // 刷新用户区
        break;
    case WM_PAINT :
        hdc = BeginPaint(hwnd, &ps); // 取得设备环境句柄
        SetMapMode(hdc, nMode); // 设置映像模式
        SetWindowExtEx(hdc, 15, 15, NULL); // 设置窗口区域
        SetViewportExtEx(hdc, 15, 10, NULL); // 设置视口区区域
        SetViewportOrgEx(hdc, 120, 120, NULL); // 设置视口原点
        hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // 创建红色画笔
        SelectObject(hdc, hPen); // 将画笔选入设备环境

        // 画坐标系，原点在视口原点
        LineTo(hdc, 200, 0);
        LineTo(hdc, 195, -5);
        MoveToEx(hdc, 200, 0, NULL);
        LineTo(hdc, 195, 5);
        MoveToEx(hdc, 0, 0, NULL);
        LineTo(hdc, 0, 200);
        LineTo(hdc, -5, 195);
        MoveToEx(hdc, 0, 200, NULL);
        LineTo(hdc, 5, 195);
        DeleteObject(hPen); // 删除画笔
        EndPaint(hwnd, &ps); // 释放设备环境句柄
        break;
    case WM_DESTROY :
        PostQuitMessage(0);
        break;
    default :
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
