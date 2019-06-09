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
void setConsole(int = 110, int = 29, int = 18);

// ���o��Ц�m
position getCursorPosition();

// �]�w��Ц�m
void SetPosition(position);

// ���o��ЬO�_���
void setCursorVisable(bool);

// �]�w��X�C��
void SetColor(int = 0x07);

// �ഫ�y��
position cursorToChess(position);
position chessToCursor(position);

#endif // !CONSOLE_H
