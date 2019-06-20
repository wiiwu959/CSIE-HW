#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h>

struct position
{
    int x, y;
    bool operator==(position other)
    {
        if (x == other.x && y == other.y) return true;
        else return false;
    }
};

// 設定視窗及字體大小
void setConsole(int, int, int);

// 設定全螢幕
void setFullScreen();

// 取得游標位置
position getCursorPosition();

// 設定游標位置
void SetPosition(position);

// 取得游標是否顯示
void setCursorVisable(bool);

// 設定輸出顏色
void SetColor(int = 0x07);

#endif
