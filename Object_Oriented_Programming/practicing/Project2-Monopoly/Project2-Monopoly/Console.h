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

// �]�w�����Φr��j�p
void setConsole(int, int, int);

// �]�w���ù�
void setFullScreen();

// ���o��Ц�m
position getCursorPosition();

// �]�w��Ц�m
void SetPosition(position);

// ���o��ЬO�_���
void setCursorVisable(bool);

// �]�w��X�C��
void SetColor(int = 0x07);

#endif
