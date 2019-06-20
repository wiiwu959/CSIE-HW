#include "Console.h"

// Intent: 設定視窗及字體大小
// Pre: 寬、高、字體大小
// Post: 設定完成
void setConsole(int width, int height, int fontSize)
{
    // 改變視窗大小
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

    // 改變字體大小
    PCONSOLE_FONT_INFOEX pfi = new CONSOLE_FONT_INFOEX();
    pfi->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, pfi);
    pfi->dwFontSize.X = 0;
    pfi->dwFontSize.Y = fontSize;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, pfi);

    // 改變標題
    SetConsoleTitle("Monopoly");
}

void setFullScreen()
{
    // 全螢幕
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

// Intent: 取得當前游標位置
// Pre: 無
// Post: 回傳position
position getCursorPosition()
{
    CONSOLE_SCREEN_BUFFER_INFO cSBInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cSBInfo);
    return { cSBInfo.dwCursorPosition.X,cSBInfo.dwCursorPosition.Y };
}

// Intent: 設定游標位置
// Pre: 無
// Post: 游標位置被改變
void SetPosition(position newPosition)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(newPosition.x),static_cast<short>(newPosition.y) });
}

// Intent: 設定游標是否顯示
// Pre: 真假值
// Post: 游標顯示或隱藏
void setCursorVisable(bool set)
{
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = set;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

// Intent: 設定顏色
// Pre: 顏色編號（0x底字；0黑 3綠 4暗紅 7亮灰 8暗灰 C亮紅 D粉紅 F白 ex. 0x07黑底亮灰字）
// Post: 游標位置被改變
void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}