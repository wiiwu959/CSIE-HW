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

    // 設定曲目
    static void setMusic(unsigned);
	static bool playMusic;

private:
    static bool play;
    static thread* music;

    // 播放音樂
    static void player(vector<note>, double);
};

#endif


