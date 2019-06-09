#include "Music.h"

// 音名：頻率（X為休止符）
const DWORD C = 262, Cs = 277, Db = 277, D = 294, Ds = 311, Eb = 311, E = 330, F = 349, Fs = 370,
Gb = 370, G = 392, Gs = 415, Ab = 415, A = 440, As = 466, Bb = 466, B = 494, X = 0;
double DELAY = 60000;

bool Music::play = true;
thread* Music::music = NULL;

// 編輯曲目方法：
// speed = 每分鐘拍子數
// 每顆音符：{音名, 拍子長度}　（例如 {C,1}：Do一拍  {Fs,0.5}：升Fa半拍)
// 如果需要高八度就乘2 （例如C/2是低音Do Db*2*2是高兩個八度的降Re）

const vector<note> BEE = { {G,1},{E,1},{E,2},{F,1},{D,1},{D,2},
                             {C,1},{D,1},{E,1},{F,1},{G,1},{G,1},{G,2},
                             {G,1},{E,1},{E,2},{F,1},{D,1},{D,2},
                             {C,1},{E,1},{G,1},{G,1},{E,4},
                             {D,1},{D,1},{D,1},{D,1},{D,1},{E,1},{F,2},
                             {E,1},{E,1},{E,1},{E,1},{E,1},{F,1},{G,2},
                             {G,1},{E,1},{E,2},{F,1},{D,1},{D,2},
                             {C,1},{E,1},{G,1},{G,1},{C,4} },
    FAMILY_MART = { {E,0.5},{C,0.5},{G / 2,0.5},{C,0.5},{D,0.5},{G,1.5},
              {D,0.5},{E,0.5},{D,0.5},{G / 2,0.5},{C,2},
              {E,0.5},{C,0.5},{G / 2,0.5},{C,0.5},{D,0.5},{G,1.5},
              {D,0.5},{E,0.5},{D,0.5},{G / 2,0.5},{C,2},
              {E,0.5},{C,0.5},{G / 2,0.5},{C,0.5},{D,0.5},{G,1.5},
              {D,0.5},{E,0.5},{D,0.5},{G / 2,0.5},{E,0.5},{C,0.5},{D,0.5},{E,0.5} },
    MAYOI = { {X,3},{E,0.5},{F,0.5},{G,2},{G,2},{C,2},{E,1},{D,1},{C,1},{B/2,1},{C,1},{D,1},{C,4},
                      {E,0.5},{F,0.5},{G,2},{G,2},{C,2},{E,1},{D,1},{C,1},{D,1.5},{G,1.5},{E,4},
                      {E,0.5},{F,0.5},{G,2},{G,2},{C,2},{E,1},{D,1},{C,1},{B / 2,1},{C,1},{D,1},{C,4},
                      {E,0.5},{F,0.5},{G,2},{G,2},{C * 2,2},{G,1},{F,1},{E,1},{D,1},{C,1},{B/2,1},{C,4} };

// Intent: Destruct
// Pre: Music物件
// Post: music被清除
Music::~Music()
{
    if (music != NULL)
    {
        play = false;
        music->join();
        delete music;
    }
}

// Intent: 設定曲目
// Pre: 曲目編號
// Post: 音樂被加入執行緒
void Music::setMusic(unsigned choice)
{
    if (music != NULL)
    {
        play = false;
        music->join();
        delete music;
        music = NULL;
    }
    if (choice != 0)
    {

        play = true;
        switch (choice)
        {
        case 1:
            music = new thread(bind(&player, BEE, 160));
            break;
        case 2:
            music = new thread(bind(&player, FAMILY_MART, 108));
            break;
        case 3:
            music = new thread(bind(&player, MAYOI, 180));
            break;
        }
    }
}

// Intent: 播放音樂
// Pre: 樂譜陣列、播放速度（BPM）
// Post: 音樂被播放
void Music::player(vector<note> song, double speed)
{
    while (play)
    {
        for (note n : song)
        {
            if (play)
            {
                if (n.frequency == 0)
                {
                    Sleep(static_cast<DWORD>(n.duration));
                }
                else
                {
                    Beep(n.frequency, static_cast<DWORD>(n.duration*(DELAY / speed)));
                }
            }
        }
    }
}