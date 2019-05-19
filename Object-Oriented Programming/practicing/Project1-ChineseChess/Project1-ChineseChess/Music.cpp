#include "Music.h"

// ���W�G�W�v�]X�����š^
const DWORD C = 262, Cs = 277, Db = 277, D = 294, Ds = 311, Eb = 311, E = 330, F = 349, Fs = 370,
Gb = 370, G = 392, Gs = 415, Ab = 415, A = 440, As = 466, Bb = 466, B = 494, X = 0;
double DELAY = 60000;

bool Music::play = true;
thread* Music::music = NULL;

// �s�覱�ؤ�k�G
// speed = �C������l��
// �C�����šG{���W, ��l����}�@�]�Ҧp {C,1}�GDo�@��  {Fs,0.5}�G��Fa�b��)
// �p�G�ݭn���K�״N��2 �]�ҦpC/2�O�C��Do Db*2*2�O����ӤK�ת���Re�^

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
// Pre: Music����
// Post: music�Q�M��
Music::~Music()
{
    if (music != NULL)
    {
        play = false;
        music->join();
        delete music;
    }
}

// Intent: �]�w����
// Pre: ���ؽs��
// Post: ���ֳQ�[�J�����
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

// Intent: ���񭵼�
// Pre: ���а}�C�B����t�ס]BPM�^
// Post: ���ֳQ����
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