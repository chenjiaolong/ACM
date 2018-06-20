/**
 * ��������ʱ����ʼ�׶ΰ�ģʽMM_TEXT ��ͼ
 * ͼ��Ϊһ������ϵ��һ�߼�����ϵ��ԭ�㣬
 * X��Y��ֱ����߼�����ϵ��X��Y�ᡣ���û�
 * ���¡�A�� ����B�� �� ��C�� ��ʱ������WM_CHAR
 * ��Ϣ����ӳ��ģʽ�ֱ�����ΪISOTROPIC
 * ��ANISOTROPIC��LOMETRIC��ͬʱ��ӾInvalidateRect
 * ����ˢ���û���
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
    char lpszClassName[] = "ӳ��ģʽ";
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
    ShowWindow(hwnd, nCmdShow); // ��ʾ����
    UpdateWindow(hwnd); // �����û���
    while(GetMessage(& Msg, NULL, 0, 0)) // ��Ϣѭ��
    {
        TranslateMessage(& Msg);
        DispatchMessage(& Msg);
    }
    return Msg.wParam; // ��Ϣѭ������ʱ����Ϣ����ϵͳ
}

// ���ں���
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
        InvalidateRect(hwnd, NULL, 1); // ˢ���û���
        break;
    case WM_PAINT :
        hdc = BeginPaint(hwnd, &ps); // ȡ���豸�������
        SetMapMode(hdc, nMode); // ����ӳ��ģʽ
        SetWindowExtEx(hdc, 15, 15, NULL); // ���ô�������
        SetViewportExtEx(hdc, 15, 10, NULL); // �����ӿ�������
        SetViewportOrgEx(hdc, 120, 120, NULL); // �����ӿ�ԭ��
        hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // ������ɫ����
        SelectObject(hdc, hPen); // ������ѡ���豸����

        // ������ϵ��ԭ�����ӿ�ԭ��
        LineTo(hdc, 200, 0);
        LineTo(hdc, 195, -5);
        MoveToEx(hdc, 200, 0, NULL);
        LineTo(hdc, 195, 5);
        MoveToEx(hdc, 0, 0, NULL);
        LineTo(hdc, 0, 200);
        LineTo(hdc, -5, 195);
        MoveToEx(hdc, 0, 200, NULL);
        LineTo(hdc, 5, 195);
        DeleteObject(hPen); // ɾ������
        EndPaint(hwnd, &ps); // �ͷ��豸�������
        break;
    case WM_DESTROY :
        PostQuitMessage(0);
        break;
    default :
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
