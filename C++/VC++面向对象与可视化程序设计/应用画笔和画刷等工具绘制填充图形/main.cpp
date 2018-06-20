#include<stdlib.h>
#include<string.h>
#include<windows.h>

long WINAPI WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam);
BOOL InitWindowsClass(HINSTANCE hInstance);
BOOL InitWindows(HINSTANCE hInstance, int nCmdShow);

// 主函数
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    MSG Message;
    if(! InitWindowsClass(hInstance)) return FALSE;
    if(! InitWindows(hInstance, nCmdShow)) return FALSE;
    while(GetMessage(& Message, 0, 0, 0)) // 消息循环
    {
        TranslateMessage(& Message);
        DispatchMessage(& Message);
    }
    return Message.wParam;
}

long WINAPI WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam)
{
    HDC hDC; // 定义设备环境句柄
    HBRUSH hBrush; // 定义画刷的句柄
    HPEN hPen; // 定义画笔的句柄
    PAINTSTRUCT PtStr; // 定义指向绘图信息的结构体变量
    // 定义一个POINT数组，包括6个点
    POINT points[6] = {{100, 212}, {70, 227}, {70, 250}, {130, 250}, {130, 227}, {100, 212}};
    switch(iMessage) // 处理消息
    {
    case WM_PAINT: // 处理绘图消息
        hDC = BeginPaint(hWnd, &PtStr);
        hPen = (HPEN) GetStockObject(NULL_PEN); // 获取系统定义的空画笔（把笔移到起始位置）
        SelectObject(hDC, hPen); // 选择画笔
        hBrush = (HBRUSH) GetStockObject(BLACK_BRUSH); // 获取系统定义的画刷
        SelectObject(hDC, hBrush); // 选择画刷
        LineTo(hDC, 50, 50); // 画线
        DeleteObject(hPen); // 删除画笔
        hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // 创建画笔
        SelectObject(hDC, hPen); // 选择画笔

        // 画一个三角形
        LineTo(hDC, 150, 50);
        LineTo(hDC, 100, 137);
        LineTo(hDC, 50, 50);

        Polyline(hDC, points, 6); // 画一个五边形
        Arc(hDC, 63, 137, 138, 212, 100, 137, 100, 137); // 画一个圆

        Pie(hDC, 213, 137, 288, 212, 240, 137, 260, 137); // 画一个圆饼
        Rectangle(hDC, 213, 212, 287, 250); // 画一个矩形
        RoundRect(hDC, 213, 100, 287, 137, 20, 20); // 画一个圆角矩形

        DeleteObject(hPen); // 删除画笔
        DeleteObject(hBrush); // 删除画刷
        EndPaint(hWnd, &PtStr); // 结束绘图
        return 0;
    case WM_DESTROY :
        PostQuitMessage(0); // 结束应用程序
        return 0;
    default: // 其他消息处理程序
        return (DefWindowProc(hWnd, iMessage, wParam, lParam));
    }
}
BOOL InitWindows(HINSTANCE hInstance, int nCmdShow) // 初始化窗口
{
    HWND hWnd;
    hWnd = CreateWindow("WinFill", // 生成窗口
                        "填充示例程序",
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,
                        0,
                        CW_USEDEFAULT,
                        0,
                        NULL,
                        NULL,
                        hInstance,
                        NULL
                       );
    if(! hWnd) return FALSE;
    ShowWindow(hWnd, nCmdShow); // 显示窗口
    UpdateWindow(hWnd);
    return TRUE;
}
BOOL InitWindowsClass(HINSTANCE hInstance)
{
    WNDCLASS WndClass;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH) (GetStockObject(WHITE_BRUSH));
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, "END");
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = WndProc;
    WndClass.lpszClassName = "WinFill";
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    return RegisterClass(& WndClass);
}
