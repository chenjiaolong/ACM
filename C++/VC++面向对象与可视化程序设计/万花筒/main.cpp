#include<math.h>
#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInst,
                   LPSTR lpszCmdLine,
                   int nCmdShow
                  )
{
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    char lpszClassName[] = "万花筒";
    char lpszTitle[] = "万花筒";
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
               0,
               0,
               500,
               400,
               NULL,
               NULL,
               hInstance,
               NULL
           );
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    while(GetMessage(& msg, NULL, 0, 0))
    {
        TranslateMessage(& msg);
        DispatchMessage(& msg);
    }
    return msg.wParam;
}

HPEN hpen[6];
LRESULT CALLBACK WndProc(HWND hwnd,
                         UINT message,
                         WPARAM wParam,
                         LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    switch(message)
    {
    case WM_CREATE :
        hpen[0] = (HPEN ) CreatePen(PS_SOLID, 0, RGB(125, 0, 0));
        hpen[1] = (HPEN ) CreatePen(PS_SOLID, 0, RGB(255, 0, 0));
        hpen[2] = (HPEN ) CreatePen(PS_SOLID, 0, RGB(0, 125, 0));
        hpen[3] = (HPEN ) CreatePen(PS_SOLID, 0, RGB(0, 255, 0));
        hpen[4] = (HPEN ) CreatePen(PS_SOLID, 0, RGB(0, 0, 125));
        hpen[5] = (HPEN ) CreatePen(PS_SOLID, 0, RGB(0, 0, 255));
        break;
    case WM_PAINT :
    {
        double t;
        int x0 = 220, y0 = 200;
        int n = 25, r = 150;
        int x[50], y[50];
        t = 6.28318 / n;

        hdc = BeginPaint(hwnd, &ps);
        for(int i = 0; i < n; i ++)
        {
            x[i] = int (r * cos(i * t) + x0);
            y[i] = int (r * sin(i * t) + y0);
        }
        for(int i = 0; i <= n - 2; i ++)
            for(int j = i + 1; j <= n - 1; j ++)
            {
                SelectObject(hdc, hpen[j % 6]);
                Sleep(50);
                MoveToEx(hdc, x[i], y[i], NULL);
                LineTo(hdc, x[j], y[j]);
            }
        EndPaint(hwnd, &ps);
    }
    break;
    case WM_DESTROY :

        PostQuitMessage(0);
        break;
    default :
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
