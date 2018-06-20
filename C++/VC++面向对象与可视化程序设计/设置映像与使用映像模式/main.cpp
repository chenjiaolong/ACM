/** 程序的初始阶段按模式 MM_TEXT 绘图，
 * 用户单击鼠标以改变映像模式，单击左键，
 * 产生 WM_LBUTTONDOWN 的消息，通知应用程序
 * 设置映像模式为 ISOTROPIC，并调用 InvalidateRect
 * 函数刷新用户区，在用户单击鼠标右键时，
 * 产生WM_RBUTTONDOWN 消息，应用程序将映像模式
 * 设置成ANISOTROPIC，同时刷新用户区。
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

int nMode;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPreInst,
                   LPSTR lpszCmdLine,
                    int nCmdShow)
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
    wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = lpszClassName;
    if( !RegisterClass(& wndclass))
    {
        MessageBeep(0);
        return FALSE;
    }

    hwnd = CreateWindow
    (
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
        TranslateMessage( & Msg);
        DispatchMessage(& Msg);
    }
    return Msg.wParam; // 消息循环结束时将信息返回系统
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    HBRUSH hB1, hB2;
    switch(message)
    {
        case WM_LBUTTONDOWN : // 单击鼠标左键的消息
            nMode = MM_ISOTROPIC; // 更改映射模式为MM_ISOTROPIC
            InvalidateRect(hwnd, NULL, 1); // 刷新用户区
            break;
        case WM_RBUTTONDOWN : // 单击鼠标右键消息
            nMode = MM_ANISOTROPIC; // 更改映射模式为MM_ANISOTROPIC
            InvalidateRect(hwnd, NULL, 1); // 刷新用户区
            break;
        case WM_PAINT :
            hdc = BeginPaint(hwnd, &ps); // 取得设备环境语句
            SetMapMode(hdc, nMode); // 设置映射模式
            SetWindowExtEx(hdc, 150, 150, NULL); // 设置窗口区域
            SetViewportExtEx(hdc, 150, 100, NULL); // 设置视口区域
            SetViewportOrgEx(hdc, 150, 60, NULL); // 设置视口原点
            hB1 = (HBRUSH) GetStockObject(WHITE_BRUSH); // 定义白色画刷
            hB2 = (HBRUSH) GetStockObject(BLACK_BRUSH); // 定义黑色画刷
            SelectObject(hdc, hB1); // 将黑白刷选入设备环境
            RoundRect(hdc, 0, 0, 150, 150, 30, 30); // 绘制圆角矩形并填充
            SelectObject(hdc, hB2); // 更改当前画刷为黑色画刷
            Ellipse(hdc, 0, 10, 150, 140); // 绘制椭圆并填充
            EndPaint(hwnd, &ps); // 释放设备环境句柄
            DeleteObject(hB1); // 删除画刷句柄
            DeleteObject(hB2);
            break;
        case WM_DESTROY :
            PostQuitMessage(0);
            break;
        default :
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
