#include "Console.h"

// Intent: �]�w�����Φr��j�p
// Pre: �e�B���B�r��j�p
// Post: �]�w����
void setConsole(int width, int height, int fontSize)
{
    // ���ܵ����j�p
    if (width != 1 && height != 1)
    {
        _COORD c;
        c.X = 1;
        c.Y = 1;
        SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
        _SMALL_RECT sr;
        sr.Top = 0;
        sr.Left = 0;
        sr.Right = 1;
        sr.Bottom = 1;
        SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &sr);
    }
    _COORD c;
    c.X = width;
    c.Y = height;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);

    _SMALL_RECT sr;
    sr.Top = 0;
    sr.Left = 0;
    sr.Right = width - 1;
    sr.Bottom = height - 1;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &sr);

    // ���ܦr��j�p
    PCONSOLE_FONT_INFOEX pfi = new CONSOLE_FONT_INFOEX();
    pfi->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, pfi);
    pfi->dwFontSize.X = 0;
    pfi->dwFontSize.Y = fontSize;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, pfi);

    // ���ܼ��D
    SetConsoleTitle("Monopoly");
}

void setFullScreen()
{
    // ���ù�
    DWORD mode;
    GetConsoleDisplayMode(&mode);
    if ((mode&CONSOLE_FULLSCREEN) != CONSOLE_FULLSCREEN)
    {
        keybd_event(VK_MENU, 0x38, 0, 0);
        keybd_event(VK_RETURN, 0x1c, 0, 0);
        keybd_event(VK_MENU, 0xb8, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_RETURN, 0x9c, KEYEVENTF_KEYUP, 0);
    }
}

// Intent: ���o��e��Ц�m
// Pre: �L
// Post: �^��position
position getCursorPosition()
{
    CONSOLE_SCREEN_BUFFER_INFO cSBInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cSBInfo);
    return { cSBInfo.dwCursorPosition.X,cSBInfo.dwCursorPosition.Y };
}

// Intent: �]�w��Ц�m
// Pre: �L
// Post: ��Ц�m�Q����
void SetPosition(position newPosition)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(newPosition.x),static_cast<short>(newPosition.y) });
}

// Intent: �]�w��ЬO�_���
// Pre: �u����
// Post: �����ܩ�����
void setCursorVisable(bool set)
{
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = set;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

// Intent: �]�w�C��
// Pre: �C��s���]0x���r�F0�� 3�� 4�t�� 7�G�� 8�t�� C�G�� D���� F�� ex. 0x07�©��G�Ǧr�^
// Post: ��Ц�m�Q����
void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}