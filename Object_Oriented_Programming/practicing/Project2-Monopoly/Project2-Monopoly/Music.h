#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <thread>
using namespace std;

struct note
{
    DWORD frequency;
    double duration;
};

class Music
{
public:
    ~Music();

    // �]�w����
    static void setMusic(unsigned);
	static bool playMusic;

private:
    static bool play;
    static thread* music;

    // ���񭵼�
    static void player(vector<note>, double);
};

#endif


