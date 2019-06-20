#include "Block.h"

const vector<string> ROAD_CONE_SIGH = { " �@    �� ",
                                        "   �@��   ",
                                        "   ���@   ",
                                        " ��    �@ " };

// Intent: ��l��
// Pre: ��m�B�W�١B�����B���šB�лx
// Post: ��l�Ƨ���
Block::Block(unsigned newPosition, string newName, int newType, vector<string> newSign, vector<unsigned> newPasserby)
{
	position = newPosition;
	name = newName;
	type = newType;
	sign = newSign;
	passerby = newPasserby;
    roadCone = false;
    output = "            "
        "            "
        "            "
        "            "
        "            "
        "            "
        "            "
        "            "
        "            ";
}

// Intent: ��l��
// Pre: �t�@��Block����
// Post: ��l�Ƨ���
Block::Block(Block& another)
{
	position = another.position;
	name = another.name;
	type = another.type;
	sign = another.sign;
	passerby = another.passerby;
    roadCone = another.roadCone;
}

// Intent: �w�q=
// Pre: �t�@��Block����
// Post: assign����
Block& Block::operator=(Block another)
{
	position = another.position;
	name = another.name;
	type = another.type;
	sign = another.sign;
	passerby = another.passerby;
    roadCone = another.roadCone;

	return (*this);
}

// Intent: ���o����
// Pre: ��l������~�Ӯ�l������
// Post: �^��type
int Block::getType()
{
	return type;
}
void Block::setType(int newType)
{
	type = newType;
}

unsigned Block::getPosition()
{
	return position;
}
void Block::setPosition(unsigned newPosition)
{
	position = newPosition;
}

// Intent: ���o�W��
// Pre: ��l������~�Ӯ�l������
// Post: �^��name
string Block::getName()
{
	return name;
}
void Block::setName(string newName)
{
	name = newName;
}

vector<unsigned> Block::getPasserby()
{
	return passerby;
}
void Block::setPasserby(vector<unsigned> newPasserby)
{
	passerby = newPasserby;
}

// Intent: ���o�лx
// Pre: ��l������~�Ӯ�l������
// Post: �^��sign
vector<string> Block::getSign()
{
	return sign;
}

// Intent: �]�w�лx
// Pre: ��l������~�Ӯ�l������
// Post: �^��sign
void Block::setSign(vector<string> newSign)
{
	sign = newSign;
}

bool Block::getRoadCone()
{
    return roadCone;
}
void Block::setRoadCone(bool newRoadCone)
{
    roadCone = newRoadCone;
}

void Block::setOutput(int playerID)
{
	switch (playerID)
	{
	case -1:
		player1 = ' ';
		player2 = ' ';
		player3 = ' ';
		player4 = ' ';
		break;
	case 1:
		player1 = '1';
		break;
	case 2:
		player2 = '2';
		break;
	case 3:
		player3 = '3';
		break;
	case 4:
		player4 = '4';
		break;
	}

	name = center(name, 10);
    if (roadCone == true)
    {
        output = "____________"
            "|          |"
            "|" + ROAD_CONE_SIGH[0] + "|"
            "|" + ROAD_CONE_SIGH[1] + "|"
            "|" + ROAD_CONE_SIGH[2] + "|"
            "|" + ROAD_CONE_SIGH[3] + "|"
            "|" + name + "|"
            "| " + player1 + "|" + player2 + "|" + player3 + "|" + player4 + "  |"
            "|__________|";
    }
    else
    {
        output = "____________"
            "|          |"
            "|" + sign[0] + "|"
            "|" + sign[1] + "|"
            "|" + sign[2] + "|"
            "|" + sign[3] + "|"
            "|" + name + "|"
            "| " + player1 + "|" + player2 + "|" + player3 + "|" + player4 + "  |"
            "|__________|";
    }
	
}

string Block::center(const string s, const int w)
{
	stringstream ss, spaces;
	int pad = w - s.size();
	for (int i = 0; i < pad / 2; ++i)
	{
		spaces << " ";
	}
	ss << spaces.str() << s << spaces.str();
	if (pad > 0 && pad % 2 != 0)
	{
		ss << " ";
	}
	return ss.str();
}

string Block::getOutput()
{
	return output;
}