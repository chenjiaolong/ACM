/** ����ĳ�ʼ�׶ΰ�ģʽ MM_TEXT ��ͼ��
 * �û���������Ըı�ӳ��ģʽ�����������
 * ���� WM_LBUTTONDOWN ����Ϣ��֪ͨӦ�ó���
 * ����ӳ��ģʽΪ ISOTROPIC�������� InvalidateRect
 * ����ˢ���û��������û���������Ҽ�ʱ��
 * ����WM_RBUTTONDOWN ��Ϣ��Ӧ�ó���ӳ��ģʽ
 * ���ó�ANISOTROPIC��ͬʱˢ���û�����
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
    char lpszClassName[] = "ӳ��ģʽ";
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
    ShowWindow(hwnd, nCmdShow); // ��ʾ����
    UpdateWindow(hwnd); // �����û���
    while(GetMessage(& Msg, NULL, 0, 0)) // ��Ϣѭ��
    {
        TranslateMessage( & Msg);
        DispatchMessage(& Msg);
    }
    return Msg.wParam; // ��Ϣѭ������ʱ����Ϣ����ϵͳ
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    HBRUSH hB1, hB2;
    switch(message)
    {
        case WM_LBUTTONDOWN : // ��������������Ϣ
            nMode = MM_ISOTROPIC; // ����ӳ��ģʽΪMM_ISOTROPIC
            InvalidateRect(hwnd, NULL, 1); // ˢ���û���
            break;
        case WM_RBUTTONDOWN : // ��������Ҽ���Ϣ
            nMode = MM_ANISOTROPIC; // ����ӳ��ģʽΪMM_ANISOTROPIC
            InvalidateRect(hwnd, NULL, 1); // ˢ���û���
            break;
        case WM_PAINT :
            hdc = BeginPaint(hwnd, &ps); // ȡ���豸�������
            SetMapMode(hdc, nMode); // ����ӳ��ģʽ
            SetWindowExtEx(hdc, 150, 150, NULL); // ���ô�������
            SetViewportExtEx(hdc, 150, 100, NULL); // �����ӿ�����
            SetViewportOrgEx(hdc, 150, 60, NULL); // �����ӿ�ԭ��
            hB1 = (HBRUSH) GetStockObject(WHITE_BRUSH); // �����ɫ��ˢ
            hB2 = (HBRUSH) GetStockObject(BLACK_BRUSH); // �����ɫ��ˢ
            SelectObject(hdc, hB1); // ���ڰ�ˢѡ���豸����
            RoundRect(hdc, 0, 0, 150, 150, 30, 30); // ����Բ�Ǿ��β����
            SelectObject(hdc, hB2); // ���ĵ�ǰ��ˢΪ��ɫ��ˢ
            Ellipse(hdc, 0, 10, 150, 140); // ������Բ�����
            EndPaint(hwnd, &ps); // �ͷ��豸�������
            DeleteObject(hB1); // ɾ����ˢ���
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
