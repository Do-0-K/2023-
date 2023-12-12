#pragma once

#include <time.h>
#include <memory>
#include <utility>

#define BOARDSIZEX  19
#define BOARDSIZEY  19
#define FDSIZE  50
int board_2015182047[BOARDSIZEY][BOARDSIZEX];

//검은돌		-1
//흰돌		1
#define BLACK -1
#define WHITE 1

enum ESTONE
{
    UNKNOWN = -2,
    BLACKSTONE,
    EMPTY,
    WHITESTONE
};

struct NextMove
{
    ESTONE stone;
    ESTONE first;
    ESTONE last;
    int priority;
    int random_priority;
    int empty_cnt;
    int stone_cnt;
    int stone_cnt_together;
    int move_x;
    int move_y;
    bool move_is_first;
};

struct FreeDouble
{
	int x;
	int y;
	int count;
	ESTONE stone;
};

class C2015182047
{
private:
    static bool m_enable;
	static ESTONE	m_stone;
	static int m_blackMap[40][40];

    NextMove m_nm;
    NextMove m_tmp_nm;
    FreeDouble m_freeDouble[FDSIZE];
    int m_freeDouble_LastUsed;
	int m_result;

public:
    C2015182047() : m_nm{}, m_tmp_nm{}, m_freeDouble_LastUsed(-1), m_result(0) {}
    ~C2015182047() {}

public:
    bool GetEnable()
    {
        return m_enable;
    }

	static void SetBlackMap(int _x, int _y)
	{
		m_blackMap[_y + 10][_x + 10] = 1;
	}

	static void SetStone(ESTONE _stone)
	{
		m_stone = _stone;
	}

public:
    void Init();
    void Logic(int* _x, int* _y);

private:
    void MoveClear(NextMove* _m);
    int ComputerPlay(int* _x, int* _y, int _curX, int _curY);
    void MoveCopy_HigherPriority(NextMove* _dest, NextMove* _src);
    ESTONE GetStone(int _x, int _y);
    void AddFreeDouble(int _x, int _y, int _curX, int _curY, ESTONE _stone);
	int PlayBlack(int x, int y);
	int Foul(const std::pair<int, int>& _pos);
	int	Foul33(const std::pair<int, int>& _pos, bool _flag);
	int	Foul44(const std::pair<int, int>& _pos, bool _flag);
	int	Foul66(const std::pair<int, int>& _pos, bool _flag);
};

bool C2015182047::m_enable;
ESTONE C2015182047::m_stone = UNKNOWN;
int C2015182047::m_blackMap[40][40];

void WhiteAttack_2015182047(int* x, int* y)
{
    C2015182047 logicClass_2015182047;

	if (!logicClass_2015182047.GetEnable()) {
		C2015182047::SetStone(ESTONE::WHITESTONE);
		logicClass_2015182047.Init();
	}

    logicClass_2015182047.Logic(x, y);

	board_2015182047[*y][*x] = WHITE;
}
void WhiteDefence_2015182047(int x, int y)
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2015182047[y][x] = BLACK;
}
void BlackAttack_2015182047(int* x, int* y)
{
    C2015182047 logicClass_2015182047;

    if (!logicClass_2015182047.GetEnable()) {
		C2015182047::SetStone(ESTONE::BLACKSTONE);
        logicClass_2015182047.Init();

        *x = BOARDSIZEX / 2;
        *y = BOARDSIZEY / 2;
    }

    else
        logicClass_2015182047.Logic(x, y);

	C2015182047::SetBlackMap(*x, *y);
	board_2015182047[*y][*x] = BLACK;
}
void BlackDefence_2015182047(int x, int y)
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2015182047[y][x] = WHITE;
}

void C2015182047::Init()
{
    if (m_enable)
        return;

    srand((unsigned int)(time(nullptr)));
    int r = rand();

    m_enable = true;
}

void C2015182047::Logic(int* _x, int* _y)
{
    int x, y, xx, yy;
    int num_x, num_o;
    int result;

    MoveClear(&m_nm);

    /* Lines */
    for (y = 0; y < BOARDSIZEY; ++y) {
        num_x = 0;
        num_o = 0;
        MoveClear(&m_tmp_nm);
        for (x = 0; x < BOARDSIZEX; ++x) {
            result = ComputerPlay(_x, _y, x, y);
        }
        MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
    }
    /* Columns */
    for (x = 0; x < BOARDSIZEX; ++x) {
        num_x = 0;
        num_o = 0;
        MoveClear(&m_tmp_nm);
        for (y = 0; y < BOARDSIZEY; ++y) {
            result = ComputerPlay(_x, _y, x, y);
        }
        MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
    }
    /* Askew left-right */
    for (x = BOARDSIZEX; x > 0; --x) {
        num_x = 0;
        num_o = 0;
        MoveClear(&m_tmp_nm);
        for (xx = x, yy = 0; (xx < BOARDSIZEX) && (yy < BOARDSIZEY); ++xx, ++yy) {
            result = ComputerPlay(_x, _y, xx, yy);
        }
        MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
    }
    for (y = 0; y < BOARDSIZEY; ++y) {
        num_x = 0;
        num_o = 0;
        MoveClear(&m_tmp_nm);
        for (xx = 0, yy = y; (xx < BOARDSIZEX) && (yy < BOARDSIZEY); ++xx, ++yy) {
            result = ComputerPlay(_x, _y, xx, yy);
        }
        MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
    }
    /* Askew right-left */
    for (x = 0; x < BOARDSIZEX; ++x) {
        num_x = 0;
        num_o = 0;
        MoveClear(&m_tmp_nm);
        for (xx = x, yy = 0; (xx >= 0) && (yy < BOARDSIZEY); --xx, ++yy) {
            result = ComputerPlay(_x, _y, xx, yy);
        }
        MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
    }
    for (y = 0; y < BOARDSIZEY; ++y) {
        num_x = 0;
        num_o = 0;
        MoveClear(&m_tmp_nm);
        for (xx = BOARDSIZEX, yy = y; (xx >= 0) && (yy < BOARDSIZEY); --xx, ++yy) {
            result = ComputerPlay(_x, _y, xx, yy);
        }
        MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
    }

    *_x = m_nm.move_x;
    *_y = m_nm.move_y;
}

void C2015182047::MoveClear(NextMove* _m)
{
    _m->stone = UNKNOWN;
    _m->first = UNKNOWN;
    _m->last = UNKNOWN;
    _m->priority = 0;
    _m->random_priority = 0;
    _m->empty_cnt = 0;
    _m->stone_cnt = 0;
    _m->stone_cnt_together = 0;
    _m->move_x = 0;
    _m->move_y = 0;
    _m->move_is_first = true;
}

int C2015182047::ComputerPlay(int* _x, int* _y, int _curX, int _curY)
{
	m_result = 0;
	ESTONE stone = GetStone(_curX, _curY);

    switch (stone) {
	case ESTONE::EMPTY:
        if ((m_tmp_nm.move_is_first == true) &&
            (((m_tmp_nm.first == ESTONE::EMPTY) && (m_tmp_nm.stone_cnt_together == 2)) || (m_tmp_nm.stone_cnt_together > 2)))
        {
            if (GetStone(m_tmp_nm.move_x, m_tmp_nm.move_y) == ESTONE::EMPTY)
                AddFreeDouble(*_x, *_y, m_tmp_nm.move_x, m_tmp_nm.move_y, m_tmp_nm.stone);
            AddFreeDouble(*_x, *_y, _curX, _curY, m_tmp_nm.stone);
        }

        if (m_tmp_nm.last == ESTONE::EMPTY) {
            MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
            m_tmp_nm.first = ESTONE::EMPTY;
        }

        ++m_tmp_nm.priority;
        ++m_tmp_nm.empty_cnt;

        if ((m_tmp_nm.stone == UNKNOWN) ||
            ((m_tmp_nm.stone != UNKNOWN) && (m_tmp_nm.move_x == 0) && (m_tmp_nm.move_y == 0)) ||
            ((m_tmp_nm.stone != UNKNOWN) && (m_tmp_nm.move_is_first == true))
            ) 
        {
			if (m_result == 0)
			{
				m_tmp_nm.move_x = _curX;
				m_tmp_nm.move_y = _curY;
				m_tmp_nm.move_is_first = m_tmp_nm.stone == UNKNOWN ? true : false;
			}
        }

        m_tmp_nm.last = ESTONE::EMPTY;

        break;
    case ESTONE::WHITESTONE:
        if (m_tmp_nm.stone == ESTONE::BLACKSTONE) {
			NextMove tmp_local;
            tmp_local.last = m_tmp_nm.last;
            tmp_local.move_x = m_tmp_nm.move_x;
            tmp_local.move_y = m_tmp_nm.move_y;
            MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
            if (tmp_local.last == ESTONE::EMPTY) {
                m_tmp_nm.first = ESTONE::EMPTY;
                m_tmp_nm.last = ESTONE::EMPTY;
                m_tmp_nm.empty_cnt = 1;
                m_tmp_nm.move_x = tmp_local.move_x;
                m_tmp_nm.move_y = tmp_local.move_y;
                m_tmp_nm.move_is_first = true;
                ++m_tmp_nm.priority;
            }
        }
        m_tmp_nm.stone = ESTONE::WHITESTONE;
        if (m_tmp_nm.first == ESTONE::UNKNOWN)
            m_tmp_nm.first = ESTONE::WHITESTONE;

        m_tmp_nm.priority += 2;
        m_tmp_nm.stone_cnt += 1;
        if (m_tmp_nm.last == ESTONE::WHITESTONE)
            m_tmp_nm.stone_cnt_together += 1;
        else
            m_tmp_nm.stone_cnt_together = 1;

        m_tmp_nm.last = ESTONE::WHITESTONE;

        break;
    case ESTONE::BLACKSTONE:
        if (m_tmp_nm.stone == ESTONE::WHITESTONE) {
			NextMove tmp_local;
            tmp_local.last = m_tmp_nm.last;
            tmp_local.move_x = m_tmp_nm.move_x;
            tmp_local.move_y = m_tmp_nm.move_y;
            MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
            if (tmp_local.last == ESTONE::EMPTY) {
                m_tmp_nm.first = ESTONE::EMPTY;
                m_tmp_nm.last = ESTONE::EMPTY;
                m_tmp_nm.empty_cnt = 1;
                m_tmp_nm.move_x = tmp_local.move_x;
                m_tmp_nm.move_y = tmp_local.move_y;
                m_tmp_nm.move_is_first = true;
                ++m_tmp_nm.priority;
            }
        }
        m_tmp_nm.stone = ESTONE::BLACKSTONE;
        if (m_tmp_nm.first == ESTONE::UNKNOWN)
            m_tmp_nm.first = ESTONE::BLACKSTONE;

        m_tmp_nm.priority += 2;
        m_tmp_nm.stone_cnt += 1;
        if (m_tmp_nm.last == ESTONE::BLACKSTONE)
            m_tmp_nm.stone_cnt_together++;
        else
            m_tmp_nm.stone_cnt_together = 1;

        m_tmp_nm.last = ESTONE::BLACKSTONE;

        break;
    }

	/* oo.o */
	if ((m_tmp_nm.stone_cnt_together == 2) && (m_tmp_nm.stone_cnt >= 3) && (m_tmp_nm.empty_cnt >= 3)) {
		m_tmp_nm.priority = 91;
		if (m_tmp_nm.stone == ESTONE::WHITESTONE)
			m_tmp_nm.priority += 1;
        MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
	}
    else {
        /* ooo */
        if ((m_tmp_nm.stone_cnt_together == 3) && (m_tmp_nm.empty_cnt >= 2)) {
            m_tmp_nm.priority = 92;
            if (m_tmp_nm.stone == ESTONE::WHITESTONE)
                m_tmp_nm.priority += 1;
            MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
        }
        else {
            /* oooo */
            if ((m_tmp_nm.stone_cnt_together == 4) && (m_tmp_nm.empty_cnt >= 1)) {
                m_tmp_nm.priority = 94;
                if (m_tmp_nm.stone == ESTONE::WHITESTONE)
                    m_tmp_nm.priority += 1;
                MoveCopy_HigherPriority(&m_nm, &m_tmp_nm);
            }
        }
    }

    return 0;
}

void C2015182047::MoveCopy_HigherPriority(NextMove* _dest, NextMove* _src)
{
    _src->random_priority = rand() & 10;

    if ((_src->stone != UNKNOWN) &&
        ((_src->priority > _dest->priority) || ((_src->priority == _dest->priority) && (_src->random_priority > _dest->random_priority))) &&
        !((_src->move_x == 0) && (_src->move_y == 0)))
    {
		m_result = PlayBlack(_src->move_x, _src->move_y);
		if (m_result != 33 && m_result != 44 && m_result != 66)
			memcpy(_dest, _src, sizeof(NextMove));
    }

    MoveClear(_src);
}

ESTONE C2015182047::GetStone(int _x, int _y)
{
    return (ESTONE)board_2015182047[_y][_x];
}

void C2015182047::AddFreeDouble(int _x, int _y, int _curX, int _curY, ESTONE _stone)
{
    FreeDouble* pt = m_freeDouble;

    for (int i = 0; i <= m_freeDouble_LastUsed; ++i) {
        if ((pt[i].x == _curX) && (pt[i].y == _curY) && (pt[i].stone == _stone)) {
            pt[i].count += 1;
            if ((pt[i].stone == ESTONE::WHITESTONE) && (m_nm.priority < 51)) {
                MoveClear(&m_nm);
                m_nm.move_x = pt[i].x;
                m_nm.move_y = pt[i].y;
                m_nm.priority = 51;
            }
            else if ((pt[i].stone == ESTONE::BLACKSTONE) && (m_nm.priority < 50)) {
				m_result = PlayBlack(pt[i].x, pt[i].y);
				if (m_result != 33 && m_result != 44 && m_result != 66)
				{
					MoveClear(&m_nm);
					m_nm.move_x = pt[i].x;
					m_nm.move_y = pt[i].y;
					m_nm.priority = 50;
				}
            }

            return;
        }
    }

    ++m_freeDouble_LastUsed;
    if (m_freeDouble_LastUsed < FDSIZE) {
		m_result = PlayBlack(_curX, _curY);
		if (m_result != 33 && m_result != 44 && m_result != 66)
		{
			pt[m_freeDouble_LastUsed].x = _curX;
			pt[m_freeDouble_LastUsed].y = _curY;
			pt[m_freeDouble_LastUsed].count = 1;
			pt[m_freeDouble_LastUsed].stone = _stone;
		}
    }
}

int C2015182047::PlayBlack(int x, int y)
{
	if (m_stone != ESTONE::BLACKSTONE)
		return 0;

	if (board_2015182047[y][x] != 0)
		return 0;

	if (m_blackMap[y + 10][x + 10] == 0)
	{
		m_blackMap[y + 10][x + 10] = 1;
		std::pair<int, int> pos;
		pos.first = x + 10;
		pos.second = y + 10;

		m_result = Foul(pos);
		m_blackMap[y + 10][x + 10] = 0;
		return m_result;
	}

	return 0;
}

int C2015182047::Foul(const std::pair<int, int>& _pos)
{
	int foul = 0;

	foul = Foul66(_pos, 1);
	if (0 == foul)
		foul = Foul44(_pos, 1);

	if (0 == foul)
		foul = Foul33(_pos, 1);

	return foul;
}

int	C2015182047::Foul33(const pair<int, int>& _pos, bool _flag)
{
	int movePoint[8][2] = { { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };
	int tempX, tempY;
	int PretempX, PretempY;
	int PosttempX, PosttempY;
	int foulLine33 = 0;

	bool empty;
	float attackPoint[8] = { 0, };
	pair<int, int> Point[8];
	pair<int, int> emptyPos;
	bool check[8] = { false, };
	float checkWeight[8] = { 0.0f, };

	/* 열린 두개의 삼삼 */
	for (int way = 0; way < 8; ++way)
	{
		tempX = _pos.first;
		tempY = _pos.second;
		empty = true;

		for (int move = 0; move < 6; ++move)
		{

			tempX += movePoint[way][0];
			tempY += movePoint[way][1];

			PosttempX = tempX + movePoint[way][0];
			PosttempY = tempY + movePoint[way][1];

			PretempX = tempX - movePoint[way][0];
			PretempY = tempY - movePoint[way][1];

			if (VirtualMapMin <= tempX && tempX <= VirtualMapMax && VirtualMapMin <= tempY && tempY <= VirtualMapMax)
			{
				/* 현재 자리에 플레이어 돌이 있다면 */
				if (m_blackMap[tempY][tempX] == 1)
				{
					/* 현재 빈칸을 지나오지 않았다면 first의 돌을 증가시킨다.*/
					if (empty)
						Point[way].first++;
					else /* 빈칸을 지나왔다면 second 증가. */
						Point[way].second++;
				}
				/* 현재 자리가 빈칸 이라면 */
				else if (m_blackMap[tempY][tempX] == 0)
				{
					/* 아직 빈칸을 지나오지 않았다면 */
					if (empty)
					{
						/* 빈칸 자리를 저장 */
						emptyPos.first = tempX;
						emptyPos.second = tempY;

						if (_flag)
						{
							/* 이 빈칸이 유효한 자리가 아니라면 숫자를 더 이상 세지 않는다. */
							if (Foul44(make_pair(tempX, tempY), 0) || Foul33(make_pair(tempX, tempY), 0) || Foul66(make_pair(tempX, tempY), 0))
							{
								checkWeight[way] = 1.0f;
								break;
							}
							/* 유효한 자리라면 그냥 빈칸을 지나왔다고 표시하고 */
							/* 다음 자리가 상대 돌 이라면 이전에 돌들이 연속되여 있다는 소리기 때문에 공격 포인트가 된다.*/
							else
							{
								//	if (m_blackMap[PosttempY][PosttempX] != 0 && m_blackMap[PosttempY][PosttempX] != 1)
									/* 다음 자리가 벽이 아니라면 상대 돌이면 */
								if (10 <= PosttempX && PosttempX <= 27 && 10 <= PosttempY && PosttempY <= 27)
								{
									attackPoint[way] = 0.5f;
								}
								else
								{

								}
								empty = false;
							}
						}
						/* 빈자리의 유효성을 확인할때는 빈자리는 그냥 빈자리다. */
						else
							empty = false;
					}
					/* 이미 빈칸을 한번 지나왔다면 */
					else
					{
						/* 빈칸의 다음칸이 다른 플레이어라면 가중치 0.5인 막힘을 표시한다. */
						/* 다음 칸이 빈칸이나 같은 돌이라면 막히지 않았다. */
						if (_flag)
						{
							if (m_blackMap[PosttempY][PosttempX] == 1 && m_blackMap[PretempY][PretempX] == 1)
								m_blackMap[emptyPos.second][emptyPos.first] = 1;
							/*유효하지 않다면 막힘 체크. */
							if (Foul44(make_pair(tempX, tempY), 0) || Foul33(make_pair(tempX, tempY), 0) || Foul66(make_pair(tempX, tempY), 0))
							{
								checkWeight[way] = 1.5f;
							}
							if (m_blackMap[PosttempY][PosttempX] == 1 && m_blackMap[PretempY][PretempX] == 1)
								m_blackMap[emptyPos.second][emptyPos.first] = 0;

							if (m_blackMap[PosttempY][PosttempX] != 0 && m_blackMap[PosttempY][PosttempX] != 1)
							{
								checkWeight[way] = 0.5f;
							}
						}
						break;

					}
				}
				/* 다른 플레이어 돌을 만났다면  */
				else
				{
					/* 이전 돌이 빈칸이라면 */
					if (m_blackMap[PretempY][PretempX] == 0)
					{
						/* 빈칸뒤에 다른 돌인데 앞에 놓은 돌이 하나도 없다면 막기 1.5 */
						if (Point[way].first == 0)
							checkWeight[way] = 1.5f;
						else if (Point[way].first == 1)
							checkWeight[way] = 1.0f;
						else
							checkWeight[way] = 0.5f;
					}
					else
						checkWeight[way] = 1.5f;
					break;
				}
			}
			/* 칸을 넘어감. */
			else
			{
				/* 넘어가기 전 돌이 플레이어돌이라면 막힌것을 표시한다.*/
				if (m_blackMap[PretempY][PretempX] == 1)
					checkWeight[way] = 1.5f;
				else
					checkWeight[way] = 0.5f;

				break;
			}
		}
	}


	//cout << "_flag  " << _flag << "   weight  ";
	for (int i = 0; i < 4; ++i)
	{
		/*	if (_flag)
			{
				cout << checkWeight[i] << " " << checkWeight[i + 4] << " ";
				cout << attackPoint[i] << " " << attackPoint[i + 4] << "     ";
			}*/
		if (checkWeight[i] + checkWeight[i + 4] - attackPoint[i] - attackPoint[i + 4] >= 0.5f)
			check[i] = true;
	}
	/*if (_flag)
		cout << endl;*/

	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int c = 0;

	for (int i = 0; i < 4; ++i)
	{
		/*	if (_flag)
			{
				cout << i << "  " << Point[i].first << "  " << Point[i].second << "  " << check[i] << endl;
				cout << i << "  " << Point[i + 4].first << "  " << Point[i + 4].second << "  " << check[i + 4] << endl;
			}*/
		count = Point[i].first + Point[i + 4].first;
		if (count < 2)
		{
			count1 = Point[i].first + Point[i].second + Point[i + 4].first;
			if (2 == count1)
			{
				count = count1;


			}
			count2 = Point[i + 4].first + Point[i + 4].second + Point[i].first;
			if (2 == count2)
			{
				count = count2;

			}
		}


		if (2 == count)
		{
			if (Point[i].first + Point[i].second + Point[i + 4].first > 2)
				foulLine33--;
			else if (Point[i].first + Point[i + 4].second + Point[i + 4].first > 2)
				foulLine33--;

			foulLine33++;
			if (check[i])
				c++;
			if (check[i + 4])
				c++;
		}
	}

	if (foulLine33 - c <= 1)
		foulLine33 = 0;
	if (1 < foulLine33)
		return 33;
	else
		return 0;
}
int	C2015182047::Foul44(const pair<int, int>& _pos, bool _flag)
{
	int movePoint[8][2] = { { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };
	int tempX, tempY;
	int PretempX, PretempY;
	int PosttempX, PosttempY;
	int foulLine44 = 0;

	bool empty;
	pair<int, int> Point[8];
	pair<int, int> emptyPos;

	int attackPoint[8] = { 0 , };

	bool check[8] = { false, };
	/*닫힌 44도 44다. */
	for (int way = 0; way < 8; ++way)
	{
		tempX = _pos.first;
		tempY = _pos.second;
		empty = true;
		for (int move = 0; move < 6; ++move)
		{
			tempX += movePoint[way][0];
			tempY += movePoint[way][1];

			PosttempX = tempX + movePoint[way][0];
			PosttempY = tempY + movePoint[way][1];

			PretempX = tempX - movePoint[way][0];
			PretempY = tempY - movePoint[way][1];

			if (VirtualMapMin <= tempX && tempX <= VirtualMapMax && VirtualMapMin <= tempY && tempY <= VirtualMapMax)
			{
				/* 현재 자리에 플레이어 돌이 있다면 */
				if (m_blackMap[tempY][tempX] == 1)
				{
					/* 현재 빈칸을 지나오지 않았다면 first의 돌을 증가시킨다.*/
					if (empty)
						Point[way].first++;
					else /* 빈칸을 지나왔다면 second 증가. */
						Point[way].second++;
				}
				/* 현재 자리가 빈칸 이라면 */
				else if (m_blackMap[tempY][tempX] == 0)
				{
					/* 아직 빈칸을 지나오지 않았다면 */
					if (empty)
					{
						/* 빈칸 자리를 저장 */
						emptyPos.first = tempX;
						emptyPos.second = tempY;

						if (_flag)
						{
							/* 이 빈칸이 유효한 자리가 아니라면 숫자를 더 이상 세지 않는다. */
							if (Foul44(make_pair(tempX, tempY), 0) || Foul33(make_pair(tempX, tempY), 0) || Foul66(make_pair(tempX, tempY), 0))
							{
								check[way] = true;
								break;
							}
							else
							{
								empty = false;
								/* 빈칸 다음에 플레이어 돌이 있거나 이전에 플레이어 돌이 있으면 (연속된 돌이 된다면) 공격할수 있는 자리라고 생각한다. */
								/* 두칸 연속 빈칸은 소용 없으므로 &&로 걸른다. */
								if ((m_blackMap[PosttempY][PosttempX] == 1 || m_blackMap[PretempY][PretempX] == 1) && m_blackMap[PosttempY][PosttempX] != 0)
									attackPoint[way]++;
							}
						}
						/* 빈칸이 유효한 자리라면 빈칸을 지나 왔다고 표시한다. */
						else
							empty = false;
					}
					/* 이미 빈칸을 한번 지나왔다면 */
					else
					{
						/* 이미 지나온 돌의 개수가 2개라면 빈칸에 대한 유효 검사를 해야한다. 여기에 놓을수 없게 되면 막힌걸로 친다. */
						if (Point[way].first + Point[way].second == 2)
						{
							/* 만약 두번째 빈칸 다음칸이 플레이어 돌이라면 이전에 빈칸을 플레이어의 돌로 채워 넣은뒤 검사한다. (6목을 검사하기위해) */
							/* 다음칸에 플레이어돌이 없는데 빈칸에 돌을 두고 반대편 6목으로 인해 문제가 발생할수 있음. */
							if (m_blackMap[PosttempY][PosttempX] == 1)
							{
								m_blackMap[emptyPos.second][emptyPos.first] = 1;
							}
							if (_flag)
							{						/*유효하지 않다면 막힘 체크. */
								if (Foul44(make_pair(tempX, tempY), 0) || Foul33(make_pair(tempX, tempY), 0) || Foul66(make_pair(tempX, tempY), 0))
									check[way] = true;
							}
							/* 빈칸에 임시로 넣었던 돌을 다시 빈칸으로 만든다. */
							if (m_blackMap[PosttempY][PosttempX] == 1)
							{
								m_blackMap[emptyPos.second][emptyPos.first] = 0;
							}
						}
						/* 두번째 빈칸까지 지나온 돌이 3개라면 두번째 빈칸은 유효하던 아니던 상관없다. 첫번째 빈칸의 유효 검사가 필요하다. */
						else if (Point[way].first + Point[way].second == 3)
						{
							/* 유효하지 않다면 첫번째 빈칸 뒤에 돌의 숫자는 무의미하다.*/
							if (_flag)
							{
								if (Foul44(make_pair(emptyPos.first, emptyPos.second), 0) || Foul33(make_pair(emptyPos.first, emptyPos.second), 0) || Foul66(make_pair(emptyPos.first, emptyPos.second), 0))
								{
									check[way] = true;
									/* 빈칸 이후의 돌을 0으로 변경. */
									Point[way].second = 0;
								}
							}
						}
						break;
					}
				}
				/* 빈칸도 아니고 내 돌도 아니면 상대방 돌이라는 뜻*/
				else
				{
					check[way] = true;
					break;
				}

			}
			else /* 범위를 넘어간 돌 체크*/
			{
				/*44는 벽에서 한칸 떨어져있으면 굳이 막힘 표시 안해도 될듯함.
				범위를 넘어갔는데 이전에 돌이 플레이어 돌이면 막혔다고 표시한다. */
				if (m_blackMap[PretempY][PretempX] == 1)
					check[way] = true;

				/* 범위가 넘어갔으니 더이상 이동할 필요 없다. */
				break;
			}
		}
	}
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int c = 0;
	for (int i = 0; i < 4; ++i)
	{
		/*	if (_flag)
			{
				cout << i << "  " << Point[i].first << "  " << Point[i].second << "  " << check[i] << endl;
				cout << i << "  " << Point[i + 4].first << "  " << Point[i + 4].second << "  " << check[i + 4] << endl;
			}*/

		count = Point[i].first + Point[i + 4].first;

		if (count < 3)
		{
			count1 = Point[i].first + Point[i].second + Point[i + 4].first;
			if (3 == count1)
			{
				foulLine44++;
				if (check[i])
					c++;
				if (check[i + 4])
					c *= 2;
				if (attackPoint[i])
					c--;
				if (attackPoint[i + 4])
					c--;
			}
			count2 = Point[i + 4].first + Point[i + 4].second + Point[i].first;
			if (3 == count2)
			{
				foulLine44++;
				if (check[i + 4])
					c++;
				if (check[i])
					c *= 2;
				if (attackPoint[i])
					c--;
				if (attackPoint[i + 4])
					c--;
			}
		}
		if (3 == count)
		{
			foulLine44++;
			if (abs((check[i] - attackPoint[i]) > 0) && abs((check[i + 4] - attackPoint[i + 4]) > 0))
			{
				foulLine44--;
			}
			else
			{
				if (check[i])
					c++;
				if (check[i + 4])
					c++;
				if (attackPoint[i])
					c--;
				if (attackPoint[i + 4])
					c--;
			}
		}
	}
	if (c < 0)
		c = 0;
	//if (_flag)
//		cout << "44 : " << foulLine44 << "  " << c << "   " <<   endl;
	if (abs(foulLine44 * 2 - c) <= 1)
	{
		foulLine44 = 0;
	}

	if (1 < foulLine44)
		return 44;
	else
		return 0;
}
int	C2015182047::Foul66(const pair<int, int>& _pos, bool _flag)
{
	int movePoint[8][2] = { { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };
	int tempX, tempY;
	int foulLine66 = 0;

	bool empty;
	pair<int, int> Point[8];
	bool check[8] = { false, };

	for (int way = 0; way < 8; ++way)
	{
		tempX = _pos.first;
		tempY = _pos.second;
		empty = true;
		for (int move = 0; move < 6; ++move)
		{
			tempX += movePoint[way][0];
			tempY += movePoint[way][1];
			if (VirtualMapMin <= tempX && tempX <= VirtualMapMax && VirtualMapMin <= tempY && tempY <= VirtualMapMax)
			{
				if (m_blackMap[tempY][tempX] == 1)
					Point[way].first++;
				else
					break;
			}
			else
			{
				check[way] = true;
				break;
			}
		}
	}

	/* 옆에 다른 돌이 붙어있을때 0으로 만드는 것을 수정해야함. 아니면 승리 검사 함수를 따로 만들던지*/
	int count;

	int c = 0;

	for (int i = 0; i < 4; ++i)
	{
		//if (_flag)
		//{
		//	cout << i << "  " << Point[i].first << "  " << Point[i].second << "  " << check[i] << endl;
		//	cout << i << "  " << Point[i + 4].first << "  " << Point[i + 4].second << "  " << check[i + 4] << endl;
		//}
		count = Point[i].first + Point[i + 4].first;
		if (5 <= count)
			break;
	}
	/*if (_flag)
		cout << "66 : " << foulLine66 << "  " << c << endl;*/


	if (5 <= count)
	{
		if (1 == BlackPlayer)
			return -66;
		if (1 == WhitePlayer)
			return 66;

		return 0;
	}
	else
		return 0;
}