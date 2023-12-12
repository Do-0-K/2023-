#include <climits>   // For INT_MIN
#include <cstdlib>   // For rand()
#include <utility>   // For std::pair
#include <vector>    // For std::vector
#include <iostream>

int board_2019180053[19][19];

#define BLACK -1
#define White 1

// �鵹 �÷��̾��� ���� ���� (����ġ ���)
void WhitePlayerAttack(int* x, int* y)
{
    int maxWeight = INT_MIN;  // ���� ���� ����ġ
    std::vector<std::pair<int, int>> maxWeightPositions;  // ���� ���� ����ġ�� ������ ��ġ���� ������ ����

    //const int MapSize = 19;  // ���� ũ��

    // �� ��ġ�� ����ġ ���
    for (int i = 0; i < MapSize; ++i) {
        for (int j = 0; j < MapSize; ++j) {
            if (board_2019180053[i][j] == 0) {
                int weight = 0;

                // �ֺ� ���� ����ġ ���
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (i + dx >= 0 && i + dx < MapSize && j + dy >= 0 && j + dy < MapSize) {
                            int adjacentStone = board_2019180053[i + dx][j + dy];
                            if (adjacentStone == White) {
                                weight -= 1;  // �鵹 �ֺ� ����ġ -1

                                // �鵹�� ���޾� 3�� �ִ� ���, �� �� ����ġ�� -50���� ����
                                if (dx != 0 || dy != 0) {
                                    int nextX = i + 2 * dx;
                                    int nextY = j + 2 * dy;
                                    if (nextX >= 0 && nextX < MapSize && nextY >= 0 && nextY < MapSize) {
                                        int nextStone = board_2019180053[nextX][nextY];
                                        if (nextStone == White) {
                                            weight -= 50;
                                        }
                                    }
                                    nextX = i - dx;
                                    nextY = j - dy;
                                    if (nextX >= 0 && nextX < MapSize && nextY >= 0 && nextY < MapSize) {
                                        int nextStone = board_2019180053[nextX][nextY];
                                        if (nextStone == White) {
                                            weight -= 50;
                                        }
                                    }
                                }
                            }
                            else if (adjacentStone == BLACK) {
                                weight += 1;  // �浹 �ֺ� ����ġ +1

                                // �浹�� ���޾� 3�� �ִ� ���, �� �� ����ġ�� -40���� ����
                                if (dx != 0 || dy != 0) {
                                    int nextX = i + 2 * dx;
                                    int nextY = j + 2 * dy;
                                    if (nextX >= 0 && nextX < MapSize && nextY >= 0 && nextY < MapSize) {
                                        int nextStone = board_2019180053[nextX][nextY];
                                        if (nextStone == BLACK) {
                                            weight -= 40;
                                        }
                                    }
                                    nextX = i - dx;
                                    nextY = j - dy;
                                    if (nextX >= 0 && nextX < MapSize && nextY >= 0 && nextY < MapSize) {
                                        int nextStone = board_2019180053[nextX][nextY];
                                        if (nextStone == BLACK) {
                                            weight -= 40;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                if (weight > maxWeight) {
                    maxWeight = weight;
                    maxWeightPositions.clear();
                }
                if (weight == maxWeight) {
                    maxWeightPositions.push_back(std::make_pair(i, j));
                }
            }
        }
    }

    // ���� ���� ����ġ�� ������ ��ġ�� �� �����ϰ� �����Ͽ� ���� ����
    if (maxWeightPositions.empty()) {
        // �ʿ� �ƹ��� ���� ���� ���� �ִ��� �߾ӿ� ���� ����
        *x = MapSize / 2;
        *y = MapSize / 2;
    }
    else {
        // �̹� ���� ������ ��ġ�� �鵹�� ���� ��ġ�� �����ϰ� ����
        std::vector<std::pair<int, int>> validPositions;
        for (const auto& pos : maxWeightPositions) {
            int posX = pos.first;
            int posY = pos.second;
            if (board_2019180053[posY][posX] == 0 && board_2019180053[posY][posX] != White && board_2019180053[posY][posX] != BLACK) {
                validPositions.push_back(pos);
            }
        }

        if (validPositions.empty()) {
            // ��� ��ġ�� �̹� ���� ������ ������ �ִ��� �߾ӿ� ���� ����
            *x = MapSize / 2;
            *y = MapSize / 2;
        }
        else {
            // ��ȿ�� ��ġ�� �� �����ϰ� ����
            int randomIndex = rand() % validPositions.size();
            *x = validPositions[randomIndex].first;
            *y = validPositions[randomIndex].second;
        }
    }

    board_2019180053[*y][*x] = White;
}
void WhitePlayerDefense(int x, int y)
{
    board_2019180053[y][x] = BLACK;
}
// �浹 �÷��̾��� ���� ���� (����ġ ���)
void BlackPlayerAttack(int* x, int* y)
{
    int maxWeight = INT_MIN;  // ���� ���� ����ġ
    std::vector<std::pair<int, int>> maxWeightPositions;  // ���� ���� ����ġ�� ������ ��ġ���� ������ ����

    //const int MapSize = 18;  // ���� ũ��

    // �� ��ġ�� ����ġ ���
    for (int i = 0; i < MapSize; ++i) {
        for (int j = 0; j < MapSize; ++j) {
            if (board_2019180053[i][j] == 0) {
                int weight = 0;

                // �ֺ� ���� ����ġ ���
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (i + dx >= 0 && i + dx < MapSize && j + dy >= 0 && j + dy < MapSize) {
                            int adjacentStone = board_2019180053[i + dx][j + dy];
                            if (adjacentStone == BLACK) {
                                weight -= 1;  // �浹 �ֺ� ����ġ -1

                                // �浹�� ���޾� 3�� �ִ� ���, �� �� ����ġ�� -50���� ����
                                if (dx != 0 || dy != 0) {
                                    int nextX = i + 2 * dx;
                                    int nextY = j + 2 * dy;
                                    if (nextX >= 0 && nextX < MapSize && nextY >= 0 && nextY < MapSize) {
                                        int nextStone = board_2019180053[nextX][nextY];
                                        if (nextStone == BLACK) {
                                            weight -= 50;
                                        }
                                    }
                                    nextX = i - dx;
                                    nextY = j - dy;
                                    if (nextX >= 0 && nextX < MapSize && nextY >= 0 && nextY < MapSize) {
                                        int nextStone = board_2019180053[nextX][nextY];
                                        if (nextStone == BLACK) {
                                            weight -= 50;
                                        }
                                    }
                                }
                            }
                            else if (adjacentStone == White) {
                                weight += 1;  // �鵹 �ֺ� ����ġ +1

                                // �鵹�� ���޾� 3�� �ִ� ���, �� �� ����ġ�� -40���� ����
                                if (dx != 0 || dy != 0) {
                                    int nextX = i + 2 * dx;
                                    int nextY = j + 2 * dy;
                                    if (nextX >= 0 && nextX < MapSize && nextY >= 0 && nextY < MapSize) {
                                        int nextStone = board_2019180053[nextX][nextY];
                                        if (nextStone == White) {
                                            weight -= 40;
                                        }
                                    }
                                    nextX = i - dx;
                                    nextY = j - dy;
                                    if (nextX >= 0 && nextX < MapSize && nextY >= 0 && nextY < MapSize) {
                                        int nextStone = board_2019180053[nextX][nextY];
                                        if (nextStone == White) {
                                            weight -= 40;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                if (weight > maxWeight) {
                    maxWeight = weight;
                    maxWeightPositions.clear();
                }
                if (weight == maxWeight) {
                    maxWeightPositions.push_back(std::make_pair(i, j));
                }
            }
        }
    }

    // ���� ���� ����ġ�� ������ ��ġ�� �� �����ϰ� �����Ͽ� ���� ����
    if (maxWeightPositions.empty()) {
        // �ʿ� �ƹ��� ���� ���� ���� �ִ��� �߾ӿ� ���� ����
        *x = MapSize / 2;
        *y = MapSize / 2;
    }
    else {
        // �̹� ���� ������ ��ġ�� �鵹�� ���� ��ġ�� �����ϰ� ����
        std::vector<std::pair<int, int>> validPositions;
        for (const auto& pos : maxWeightPositions) {
            int posX = pos.first;
            int posY = pos.second;
            if (board_2019180053[posY][posX] == 0 && board_2019180053[posY][posX] != White && board_2019180053[posY][posX] != BLACK) {
                validPositions.push_back(pos);
            }
        }

        if (validPositions.empty()) {
            // ��� ��ġ�� �̹� ���� ������ ������ �ִ��� �߾ӿ� ���� ����
            *x = MapSize / 2;
            *y = MapSize / 2;
        }
        else {
            // ��ȿ�� ��ġ�� �� �����ϰ� ����
            int randomIndex = rand() % validPositions.size();
            *x = validPositions[randomIndex].first;
            *y = validPositions[randomIndex].second;
        }
    }
    
    board_2019180053[*y][*x] = BLACK;
}

// �浹 �÷��̾��� ���� ���� (����ġ ���)

void BlackPlayerDefense(int x, int y)
{

    board_2019180053[y][x] = White;
}
