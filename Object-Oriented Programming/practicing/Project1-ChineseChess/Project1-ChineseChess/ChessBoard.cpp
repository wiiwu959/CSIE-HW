#include "ChessBoard.h"
const short TOP_BOUND = 2, BOTTOM_BOUND = TOP_BOUND + 23, LEFT_BOUND = 1, RIGHT_BOUND = 106, ROW_ONE = LEFT_BOUND + 27, ROW_TWO = ROW_ONE + 38;
const short BOARD_TOP = TOP_BOUND + 2, BOARD_BOTTOM = BOTTOM_BOUND - 1, BOARD_LEFT = ROW_ONE + 3, BOARD_RIGHT = ROW_TWO - 2;

ChessBoard::ChessBoard()
{
    //開局初始化
    turns = 1;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 9; j++)
            wholePosition[j][i] = NULL;

    //指標賦值
    wholePosition[0][0] = new Chess(4, 0, 0);
    wholePosition[1][0] = new Chess(5, 1, 0);
    wholePosition[2][0] = new Chess(3, 2, 0);
    wholePosition[3][0] = new Chess(2, 3, 0);
    wholePosition[4][0] = new Chess(1, 4, 0);
    wholePosition[5][0] = new Chess(2, 5, 0);
    wholePosition[6][0] = new Chess(3, 6, 0);
    wholePosition[7][0] = new Chess(5, 7, 0);
    wholePosition[8][0] = new Chess(4, 8, 0);
    wholePosition[1][2] = new Chess(6, 1, 2);
    wholePosition[7][2] = new Chess(6, 7, 2);
    wholePosition[0][3] = new Chess(7, 0, 3);
    wholePosition[2][3] = new Chess(7, 2, 3);
    wholePosition[4][3] = new Chess(7, 4, 3);
    wholePosition[6][3] = new Chess(7, 6, 3);
    wholePosition[8][3] = new Chess(7, 8, 3);

    wholePosition[0][9] = new Chess(11, 0, 9);
    wholePosition[1][9] = new Chess(12, 1, 9);
    wholePosition[2][9] = new Chess(10, 2, 9);
    wholePosition[3][9] = new Chess(9, 3, 9);
    wholePosition[4][9] = new Chess(8, 4, 9);
    wholePosition[5][9] = new Chess(9, 5, 9);
    wholePosition[6][9] = new Chess(10, 6, 9);
    wholePosition[7][9] = new Chess(12, 7, 9);
    wholePosition[8][9] = new Chess(11, 8, 9);
    wholePosition[1][7] = new Chess(13, 1, 7);
    wholePosition[7][7] = new Chess(13, 7, 7);
    wholePosition[0][6] = new Chess(14, 0, 6);
    wholePosition[2][6] = new Chess(14, 2, 6);
    wholePosition[4][6] = new Chess(14, 4, 6);
    wholePosition[6][6] = new Chess(14, 6, 6);
    wholePosition[8][6] = new Chess(14, 8, 6);
}

ChessBoard::~ChessBoard()
{
}

ChessBoard::ChessBoard(string fileTxt)
{
    readTheBoard(fileTxt);
}

// Intent: 印出棋盤框架
// Pre: NONE
// Post: NONE
void ChessBoard::printEmptyPlane()
{
    // 設定白底黑字
    SetColor(0xF0);

    for (short i = BOARD_TOP; i <= BOARD_BOTTOM; i++)	// 印白底
    {
        SetPosition({ BOARD_LEFT,i });
        for (unsigned j = BOARD_LEFT; j <= BOARD_RIGHT; j++)
        {
            cout << " ";
        }
    }
    for (short i = BOARD_TOP + 1; i <= BOARD_BOTTOM; i += 2)	// 印橫線
    {
        SetPosition({ BOARD_LEFT + 1,i });
        for (short j = BOARD_LEFT + 1; j <= BOARD_RIGHT - 1; j++)
        {
            cout << "─";
        }
    }
    for (short i = BOARD_TOP; i <= BOARD_BOTTOM; i++)	// 印直線
    {
        SetPosition({ BOARD_LEFT,i });
        cout << "║";
        SetPosition({ BOARD_RIGHT - 1,i });
        cout << "║";
        for (short j = BOARD_LEFT + 4; j <= BOARD_RIGHT - 1 - 4; j += 4)
        {
            SetPosition({ j,i });
            cout << "│";
        }
    }

    SetPosition({ BOARD_LEFT,BOARD_BOTTOM - 1 });
    cout << "╙";
    SetPosition({ BOARD_RIGHT - 1,BOARD_BOTTOM - 1 });
    cout << "╜";
    SetPosition({ BOARD_LEFT,BOARD_TOP + 1 });
    cout << "╓";
    SetPosition({ BOARD_RIGHT - 1,BOARD_TOP + 1 });
    cout << "╖";

    SetPosition({ BOARD_LEFT + 14,BOARD_TOP + 2 });
    cout << "╲";
    SetPosition({ BOARD_LEFT + 18,BOARD_TOP + 4 });
    cout << "╲";
    SetPosition({ BOARD_LEFT + 14,BOARD_TOP + 16 });
    cout << "╲";
    SetPosition({ BOARD_LEFT + 18,BOARD_TOP + 18 });
    cout << "╲";

    SetPosition({ BOARD_LEFT + 18,BOARD_TOP + 2 });
    cout << "╱";
    SetPosition({ BOARD_LEFT + 14,BOARD_TOP + 4 });
    cout << "╱";
    SetPosition({ BOARD_LEFT + 18,BOARD_TOP + 16 });
    cout << "╱";
    SetPosition({ BOARD_LEFT + 14,BOARD_TOP + 18 });
    cout << "╱";

    for (short i = BOARD_LEFT + 4; i <= BOARD_RIGHT - 5; i += 4)
    {
        for (short j = BOARD_TOP + 3; j < BOARD_BOTTOM - 1; j += 2)
        {
            SetPosition({ i,j });
            cout << "┼";
        }
        SetPosition({ i,BOARD_TOP + 11 });
        cout << "┬";
        SetPosition({ i,BOARD_TOP + 1 });
        cout << "┬";
        SetPosition({ i,BOARD_TOP + 9 });
        cout << "┴";
        SetPosition({ i,BOARD_BOTTOM - 1 });
        cout << "┴";

        for (short j = BOARD_TOP + 3; j < BOARD_BOTTOM - 1; j += 2)
        {
            SetPosition({ BOARD_LEFT,j });
            cout << "╟";
            SetPosition({ BOARD_RIGHT - 1,j });
            cout << "╢";
        }
    }

    SetPosition({ BOARD_LEFT + 2,BOARD_TOP + 10 });
    cout << "     楚河            漢界     ";

    SetColor(0xFD);      // 設定亮白底粉字
    SetPosition({ BOARD_LEFT,BOARD_TOP });
    cout << "１  ２  ３  ４  ５  ６  ７  ８  ９";
    SetPosition({ BOARD_LEFT,BOARD_BOTTOM });
    cout << "九  八  七  六  五  四  三  二  一";

    SetColor(0x07);
}

// Intent: 印出棋盤中內容
// Pre: NONE
// Post: NONE
void ChessBoard::printThePlane()
{
    printEmptyPlane();
    for (unsigned i = 0; i < 9; i++)
    {
        for (unsigned j = 0; j < 10; j++)
        {
            if (wholePosition[i][j] != NULL)
            {
                int type = wholePosition[i][j]->getChessType();
                if (type <= 7)
                {
                    SetColor(0x70);                         // 黑棋：灰底黑字
                }
                else if (type >= 8)
                {
                    SetColor(0x7C);                         // 紅棋：灰底紅字
                }
                SetPosition({ static_cast<short>(BOARD_LEFT + i * 4), static_cast<short>(BOARD_TOP + 1 + 2 * j) });
                // 依照不同棋種印出名稱
                switch (type)
                {
                case 1:
                    cout << "將";
                    break;
                case 2:
                    cout << "士";
                    break;
                case 3:
                    cout << "象";
                    break;
                case 4:
                    cout << "車";
                    break;
                case 5:
                    cout << "馬";
                    break;
                case 6:
                    cout << "包";
                    break;
                case 7:
                    cout << "卒";
                    break;
                case 8:
                    cout << "帥";
                    break;
                case 9:
                    cout << "仕";
                    break;
                case 10:
                    cout << "相";
                    break;
                case 11:
                    cout << "車";
                    break;
                case 12:
                    cout << "傌";
                    break;
                case 13:
                    cout << "炮";
                    break;
                case 14:
                    cout << "兵";
                    break;
                }

            }
        }
    }
    printTurn();
}

// Intent: 印出選了棋以後的變化(包含legalmove，所以拿出來分開處理了)
// Pre: NONE
// Post: NONE
void ChessBoard::printChosenPlane()
{
    // 把leagalmove的底色改變
    for (short k = 0; k < legalMove.size(); k++)
    {
        short i = legalMove[k].x, j = legalMove[k].y;
        SetPosition({ BOARD_LEFT + i * 4,BOARD_TOP + 1 + j * 2 });

        // 其中可以吃的棋和可以走的步數底色是不同的
        if (wholePosition[i][j] == NULL)
        {
            SetColor(0x70);
            cout << "  ";
        }
        else
        {
            if (wholePosition[i][j]->getChessType() <= 7)
            {
                SetColor(0x30);                         // 黑棋：灰底黑字
            }
            else
            {
                SetColor(0x34);                         // 紅棋：灰底紅字
            }
            switch (wholePosition[i][j]->getChessType())
            {
            case 1:
                cout << "將";
                break;
            case 2:
                cout << "士";
                break;
            case 3:
                cout << "象";
                break;
            case 4:
                cout << "車";
                break;
            case 5:
                cout << "馬";
                break;
            case 6:
                cout << "包";
                break;
            case 7:
                cout << "卒";
                break;
            case 8:
                cout << "帥";
                break;
            case 9:
                cout << "仕";
                break;
            case 10:
                cout << "相";
                break;
            case 11:
                cout << "車";
                break;
            case 12:
                cout << "傌";
                break;
            case 13:
                cout << "炮";
                break;
            case 14:
                cout << "兵";
                break;
            }
        }
    }

}

// Intent: 印出現在下棋方的提示
// Pre: NONE
// Post: NONE
void ChessBoard::printTurn()
{
    SetColor(0x03);
    SetPosition({ ROW_TWO + 9,TOP_BOUND + 5 });
    cout << "現在輪到  ";
    if (turns == 0)
    {
        SetColor(0x70);
        cout << "黑色方";
    }
    else
    {
        SetColor(0x0C);
        cout << "紅色方";
    }
    SetColor(0x03);
    cout << "  下棋";

}

// Intent: 移動棋的函數
// Pre: 參數為移動前位置和移動後位置
// Post: NONE
void ChessBoard::moveTheChess(int fromX, int fromY, int toX, int toY)
{
    if (wholePosition[toX][toY] != NULL)	// 若目標上有棋，就把原本的棋刪掉
    {
        delete wholePosition[toX][toY];
        wholePosition[toX][toY] = wholePosition[fromX][fromY];
        wholePosition[toX][toY]->setCurrentPosition(toX, toY);
        wholePosition[fromX][fromY] = NULL;
    }
    else	// 若目標上沒有棋則單純移動
    {
        wholePosition[toX][toY] = wholePosition[fromX][fromY];
        wholePosition[toX][toY]->setCurrentPosition(toX, toY);
        wholePosition[fromX][fromY] = NULL;
    }
}

// Intent: 換人下棋
// Pre: NONE
// Post: NONE
void ChessBoard::changeTurn()
{
    if (turns == 0)
    {
        turns = 1;
    }
    else
    {
        turns = 0;
    }
}

// Intent: 讀盤
// Pre: 文件名，string
// Post: NONE
bool ChessBoard::readTheBoard(string fileTxt)
{
    //開檔讀取並新建所需的棋子
    fstream file(fileTxt);
    if (file.is_open())
    {
        //丟掉現存的棋盤內容
        /*待補record部分的清除*/
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 9; j++)
                if (wholePosition[j][i] != NULL)
                {
                    delete wholePosition[j][i];
                    wholePosition[j][i] = NULL;
                }
        }

        int tmp;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                file >> tmp;
                if (tmp != 0)wholePosition[j][i] = new Chess(tmp, j, i);
            }
        }
        file >> turns;

        file.close();
        file.clear();
        return true;
    }
    else return false;
}

// Intent: 寫盤
// Pre: 文件名，string
// Post: NONE
bool ChessBoard::saveTheBoard(string fileTxt)
{
    fstream file(fileTxt, ios::out);
    if (file.is_open())
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                wholePosition[j][i] == NULL ? file << '0' : file << wholePosition[j][i]->getChessType();
                file << ' ';
            }
            file << '\n';
        }
        file << turns;

        file.close();
        file.clear();
        return true;
    }
    else return false;
}

// Intent: 寫盤
// Pre: NONE
// Post: NONE
bool ChessBoard::saveTheBoard()
{
    fstream file;
    file.open("file.txt", ios::trunc);
    if (file.is_open())
    {
        file.clear();
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                wholePosition[j][i] == NULL ? file << wholePosition[j][i]->getChessType() : file << '0';
                file << ' ';
            }
            file << '\n';
        }
        file >> turns;

        file.close();
        file.clear();
        return true;
    }
    else return false;
}

// 傳入位置參數，把對於這個棋來說可以走的步(含可以吃的棋)存在vector legalMove裡
// 在每次選擇棋後一定要call這個function
// 在確認是否將軍時也會使用到
void ChessBoard::manageLegalMove(int x, int y)
{
    position temp = wholePosition[x][y]->getCurrentPosition();
    switch (wholePosition[x][y]->getChessType())
    {
    case 1: //黑將
        if (temp.x > 3) //向左
        {
            temp.x--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x < 5) //向右
        {
            temp.x++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.y < 2) //向下
        {
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.y > 0) //向上
        {
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        // 王不見王
        while (temp.y < 9)
        {
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                // 若是中間被擋住就沒事
                if (wholePosition[temp.x][temp.y]->getChessType() != 8)
                {
                    break;
                }
                else
                {
                    legalMove.push_back(temp);
                    break;
                }
            }
        }
        break;

    case 2: //黑士
        if (temp.x > 3 && temp.y > 0) //向左上
        {
            temp.x--;
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x < 5 && temp.y > 0) //向右上
        {
            temp.x++;
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x > 3 && temp.y < 2) //向左下
        {
            temp.x--;
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x < 5 && temp.y < 2) //向右下
        {
            temp.x++;
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        break;

    case 3: //黑象
        if (temp.x - 2 >= 0 && temp.y - 2 >= 0 && (wholePosition[x - 1][y - 1] == NULL)) //向左上
        {
            temp.x -= 2;
            temp.y -= 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 2 <= 8 && temp.y - 2 >= 0 && (wholePosition[x + 1][y - 1] == NULL)) //向右上
        {
            temp.x += 2;
            temp.y -= 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x - 2 >= 0 && temp.y + 2 <= 4 && (wholePosition[x - 1][y + 1] == NULL)) //向左下
        {
            temp.x -= 2;
            temp.y += 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 2 <= 8 && temp.y + 2 <= 4 && (wholePosition[x + 1][y + 1] == NULL)) //向右下
        {
            temp.x += 2;
            temp.y += 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        break;


    case 4:  //黑車
        while (temp.x > 0) //向左
        {
            temp.x--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();
        while (temp.x < 8) //向右
        {
            temp.x++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();
        while (temp.y > 0) //向上
        {
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();
        while (temp.y < 9) //向下
        {
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        break;

    case 5: //黑馬
        if (temp.x - 2 >= 0 && temp.y - 1 >= 0 && wholePosition[temp.x - 1][temp.y] == NULL) //向 10 點鐘方向
        {
            temp.x = temp.x - 2;
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x - 1 >= 0 && temp.y - 2 >= 0 && wholePosition[temp.x][temp.y - 1] == NULL) //向 11 點鐘方向
        {
            temp.x--;
            temp.y = temp.y - 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 1 <= 8 && temp.y - 2 >= 0 && wholePosition[temp.x][temp.y - 1] == NULL) //向 1 點鐘方向
        {
            temp.x++;
            temp.y = temp.y - 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 2 <= 8 && temp.y - 1 >= 0 && wholePosition[temp.x + 1][temp.y] == NULL) //向 2 點鐘方向
        {
            temp.x = temp.x + 2;
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 2 <= 8 && temp.y + 1 <= 9 && wholePosition[temp.x + 1][temp.y] == NULL) //向 4 點鐘方向
        {
            temp.x = temp.x + 2;
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 1 <= 8 && temp.y + 2 <= 9 && wholePosition[temp.x][temp.y + 1] == NULL) //向 5 點鐘方向
        {
            temp.x++;
            temp.y = temp.y + 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x - 1 >= 0 && temp.y + 2 <= 9 && wholePosition[temp.x][temp.y + 1] == NULL) //向 7 點鐘方向
        {
            temp.x--;
            temp.y = temp.y + 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x - 2 >= 0 && temp.y + 1 <= 9 && wholePosition[temp.x - 1][temp.y] == NULL) //向 8 點鐘方向
        {
            temp.x = temp.x - 2;
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        break;

    case 6: //黑包
        while (temp.x > 0) //向左
        {
            temp.x--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                break;
            }
            legalMove.push_back(temp);
        }
        while (temp.x > 0)  // 取得可以吃的那一個
        {
            temp.x--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();

        while (temp.x < 8) //向右
        {
            temp.x++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                break;
            }
            legalMove.push_back(temp);
        }
        while (temp.x < 8)
        {
            temp.x++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();

        while (temp.y > 0) //向上
        {
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                break;
            }
            legalMove.push_back(temp);
        }
        while (temp.y > 0)
        {
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();

        while (temp.y < 9) //向下
        {
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                break;
            }
            legalMove.push_back(temp);
        }
        while (temp.y < 9)
        {
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
        }
        break;

    case 7: //黑卒
        if (temp.y < 5) //在己方範圍，只能向下
        {
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        else //在敵方範圍
        {
            if (temp.x > 0) //向左
            {
                temp.x--;
                if (wholePosition[temp.x][temp.y] != NULL)
                {
                    if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                    {
                        legalMove.push_back(temp);
                    }
                }
                else
                {
                    legalMove.push_back(temp);
                }
                temp = wholePosition[x][y]->getCurrentPosition();
            }
            if (temp.x < 8) //向右
            {
                temp.x++;
                if (wholePosition[temp.x][temp.y] != NULL)
                {
                    if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                    {
                        legalMove.push_back(temp);
                    }
                }
                else
                {
                    legalMove.push_back(temp);
                }
                temp = wholePosition[x][y]->getCurrentPosition();
            }
            if (temp.y < 9) //向下
            {
                temp.y++;
                if (wholePosition[temp.x][temp.y] != NULL)
                {
                    if (wholePosition[temp.x][temp.y]->getChessType() > 7)
                    {
                        legalMove.push_back(temp);
                    }
                }
                else
                {
                    legalMove.push_back(temp);
                }
            }
        }
        break;

    case 8: //紅帥
        if (temp.x > 3) //向左
        {
            temp.x--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x < 5) //向右
        {
            temp.x++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.y > 7) //向上
        {
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.y < 9) //向下
        {
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        // 王不見王
        while (temp.y > 0)
        {
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                // 若是中間被擋住就沒事
                if (wholePosition[temp.x][temp.y]->getChessType() != 1)
                {
                    break;
                }
                else
                {
                    legalMove.push_back(temp);
                    break;
                }
            }
        }
        break;

    case 9: //紅仕
        if (temp.x > 3 && temp.y > 7) //向左上
        {
            temp.x--;
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x < 5 && temp.y > 7) //向右上
        {
            temp.x++;
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x > 3 && temp.y < 9) //向左下
        {
            temp.x--;
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x < 5 && temp.y < 9) //向右下
        {
            temp.x++;
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        break;

    case 10: //紅相
        if (temp.x - 2 >= 0 && temp.y - 2 >= 5 && (wholePosition[x - 1][y - 1] == NULL)) //向左上
        {
            temp.x = temp.x - 2;
            temp.y = temp.y - 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 2 <= 8 && temp.y - 2 >= 5 && (wholePosition[x + 1][y - 1] == NULL)) //向右上
        {
            temp.x = temp.x + 2;
            temp.y = temp.y - 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x - 2 >= 0 && temp.y + 2 <= 9 && (wholePosition[x - 1][y + 1] == NULL)) //向左下
        {
            temp.x = temp.x - 2;
            temp.y = temp.y + 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 2 <= 8 && temp.y + 2 <= 9 && (wholePosition[x + 1][y + 1] == NULL)) //向右下
        {
            temp.x = temp.x + 2;
            temp.y = temp.y + 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        break;

    case 11: //紅車
        while (temp.x > 0) //向左
        {
            temp.x--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();
        while (temp.x < 8) //向右
        {
            temp.x++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();
        while (temp.y > 0) //向上
        {
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();
        while (temp.y < 9) //向下
        {
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        break;

    case 12: //紅傌
        if (temp.x - 2 >= 0 && temp.y - 1 >= 0 && wholePosition[temp.x - 1][temp.y] == NULL) //向 10 點鐘方向
        {
            temp.x = temp.x - 2;
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x - 1 >= 0 && temp.y - 2 >= 0 && wholePosition[temp.x][temp.y - 1] == NULL) //向 11 點鐘方向
        {
            temp.x--;
            temp.y = temp.y - 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 1 <= 8 && temp.y - 2 >= 0 && wholePosition[temp.x][temp.y - 1] == NULL) //向 1 點鐘方向
        {
            temp.x++;
            temp.y = temp.y - 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 2 <= 8 && temp.y - 1 >= 0 && wholePosition[temp.x + 1][temp.y] == NULL) //向 2 點鐘方向
        {
            temp.x = temp.x + 2;
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 2 <= 8 && temp.y + 1 <= 9 && wholePosition[temp.x + 1][temp.y] == NULL) //向 4 點鐘方向
        {
            temp.x = temp.x + 2;
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x + 1 <= 8 && temp.y + 2 <= 9 && wholePosition[temp.x][temp.y + 1] == NULL) //向 5 點鐘方向
        {
            temp.x++;
            temp.y = temp.y + 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x - 1 >= 0 && temp.y + 2 <= 9 && wholePosition[temp.x][temp.y + 1] == NULL) //向 7 點鐘方向
        {
            temp.x--;
            temp.y = temp.y + 2;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
            temp = wholePosition[x][y]->getCurrentPosition();
        }
        if (temp.x - 2 >= 0 && temp.y + 1 <= 9 && wholePosition[temp.x - 1][temp.y] == NULL) //向 8 點鐘方向
        {
            temp.x = temp.x - 2;
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
            }
            else
            {
                legalMove.push_back(temp);
            }
        }
        break;

    case 13: //紅炮
        while (temp.x > 0) //向左
        {
            temp.x--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                break;
            }
            legalMove.push_back(temp);
        }
        while (temp.x > 0)  // 取得可以吃的那一個
        {
            temp.x--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();

        while (temp.x < 8) //向右
        {
            temp.x++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                break;
            }
            legalMove.push_back(temp);
        }
        while (temp.x < 8)
        {
            temp.x++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();

        while (temp.y > 0) //向上
        {
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                break;
            }
            legalMove.push_back(temp);
        }
        while (temp.y > 0)
        {
            temp.y--;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
        }
        temp = wholePosition[x][y]->getCurrentPosition();

        while (temp.y < 9) //向下
        {
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                break;
            }
            legalMove.push_back(temp);
        }
        while (temp.y < 9)
        {
            temp.y++;
            if (wholePosition[temp.x][temp.y] != NULL)
            {
                if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                {
                    legalMove.push_back(temp);
                }
                break;
            }
        }
        break;
    case 14: //紅兵
        if (temp.y > 4) //在己方範圍，只能向上
        {
            temp.y--;
            legalMove.push_back(temp);
        }
        else //在敵方範圍
        {
            if (temp.x > 0) //向左
            {
                temp.x--;
                if (wholePosition[temp.x][temp.y] != NULL)
                {
                    if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                    {
                        legalMove.push_back(temp);
                    }
                }
                else
                {
                    legalMove.push_back(temp);
                }
                temp = wholePosition[x][y]->getCurrentPosition();
            }
            if (temp.x < 8) //向右
            {
                temp.x++;
                if (wholePosition[temp.x][temp.y] != NULL)
                {
                    if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                    {
                        legalMove.push_back(temp);
                    }
                }
                else
                {
                    legalMove.push_back(temp);
                }
                temp = wholePosition[x][y]->getCurrentPosition();
            }
            if (temp.y > 0) //向上
            {
                temp.y--;
                if (wholePosition[temp.x][temp.y] != NULL)
                {
                    if (wholePosition[temp.x][temp.y]->getChessType() <= 7)
                    {
                        legalMove.push_back(temp);
                    }
                }
                else
                {
                    legalMove.push_back(temp);
                }
            }
        }
        break;
    }
}

// Intent: 傳入位置得到該位置上的棋種
// Pre: 位置的結構
// Post: 回傳該位子上，棋子對應的地址
Chess* ChessBoard::getChess(position chessPosition)
{
    return wholePosition[chessPosition.x][chessPosition.y];
}

// Intent:得到當前下棋方是誰
// Pre: NONE
// Post: int 0 or 1
int ChessBoard::getTurn()
{
    return turns;
}

// Intent: 把legalMove vector清掉(重要)，只要有用到manageLegalMove就一定要呼叫
// Pre: NONE
// Post: NONE
void ChessBoard::clearLegalMove()
{
    legalMove.clear();
}

