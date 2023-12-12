#include <climits>   // For INT_MIN
#include <cstdlib>   // For rand()
#include <utility>   // For std::pair
#include <vector>    // For std::vector
#include <iostream>

int board_2019180053[19][19];

#define BLACK -1
#define White 1

// 백돌 플레이어의 공격 동작 (가중치 기반)
void WhitePlayerAttack(int* x, int* y)
{
    int maxWeight = INT_MIN;  // 가장 높은 가중치
    std::vector<std::pair<int, int>> maxWeightPositions;  // 가장 높은 가중치를 가지는 위치들을 저장할 벡터

    //const int MapSize = 19;  // 맵의 크기

    // 각 위치의 가중치 계산
    for (int i = 0; i < MapSize; ++i) {
        for (int j = 0; j < MapSize; ++j) {
            if (board_2019180053[i][j] == 0) {
                int weight = 0;

                // 주변 돌의 가중치 계산
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (i + dx >= 0 && i + dx < MapSize && j + dy >= 0 && j + dy < MapSize) {
                            int adjacentStone = board_2019180053[i + dx][j + dy];
                            if (adjacentStone == White) {
                                weight -= 1;  // 백돌 주변 가중치 -1

                                // 백돌이 연달아 3개 있는 경우, 양 옆 가중치를 -50으로 설정
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
                                weight += 1;  // 흑돌 주변 가중치 +1

                                // 흑돌이 연달아 3개 있는 경우, 양 옆 가중치를 -40으로 설정
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

    // 가장 높은 가중치를 가지는 위치들 중 랜덤하게 선택하여 돌을 놓음
    if (maxWeightPositions.empty()) {
        // 맵에 아무런 돌이 없을 때는 최대한 중앙에 돌을 놓음
        *x = MapSize / 2;
        *y = MapSize / 2;
    }
    else {
        // 이미 돌이 놓여진 위치와 백돌이 놓인 위치를 제외하고 선택
        std::vector<std::pair<int, int>> validPositions;
        for (const auto& pos : maxWeightPositions) {
            int posX = pos.first;
            int posY = pos.second;
            if (board_2019180053[posY][posX] == 0 && board_2019180053[posY][posX] != White && board_2019180053[posY][posX] != BLACK) {
                validPositions.push_back(pos);
            }
        }

        if (validPositions.empty()) {
            // 모든 위치가 이미 돌이 놓여져 있으면 최대한 중앙에 돌을 놓음
            *x = MapSize / 2;
            *y = MapSize / 2;
        }
        else {
            // 유효한 위치들 중 랜덤하게 선택
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
// 흑돌 플레이어의 공격 동작 (가중치 기반)
void BlackPlayerAttack(int* x, int* y)
{
    int maxWeight = INT_MIN;  // 가장 높은 가중치
    std::vector<std::pair<int, int>> maxWeightPositions;  // 가장 높은 가중치를 가지는 위치들을 저장할 벡터

    //const int MapSize = 18;  // 맵의 크기

    // 각 위치의 가중치 계산
    for (int i = 0; i < MapSize; ++i) {
        for (int j = 0; j < MapSize; ++j) {
            if (board_2019180053[i][j] == 0) {
                int weight = 0;

                // 주변 돌의 가중치 계산
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (i + dx >= 0 && i + dx < MapSize && j + dy >= 0 && j + dy < MapSize) {
                            int adjacentStone = board_2019180053[i + dx][j + dy];
                            if (adjacentStone == BLACK) {
                                weight -= 1;  // 흑돌 주변 가중치 -1

                                // 흑돌이 연달아 3개 있는 경우, 양 옆 가중치를 -50으로 설정
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
                                weight += 1;  // 백돌 주변 가중치 +1

                                // 백돌이 연달아 3개 있는 경우, 양 옆 가중치를 -40으로 설정
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

    // 가장 높은 가중치를 가지는 위치들 중 랜덤하게 선택하여 돌을 놓음
    if (maxWeightPositions.empty()) {
        // 맵에 아무런 돌이 없을 때는 최대한 중앙에 돌을 놓음
        *x = MapSize / 2;
        *y = MapSize / 2;
    }
    else {
        // 이미 돌이 놓여진 위치와 백돌이 놓인 위치를 제외하고 선택
        std::vector<std::pair<int, int>> validPositions;
        for (const auto& pos : maxWeightPositions) {
            int posX = pos.first;
            int posY = pos.second;
            if (board_2019180053[posY][posX] == 0 && board_2019180053[posY][posX] != White && board_2019180053[posY][posX] != BLACK) {
                validPositions.push_back(pos);
            }
        }

        if (validPositions.empty()) {
            // 모든 위치가 이미 돌이 놓여져 있으면 최대한 중앙에 돌을 놓음
            *x = MapSize / 2;
            *y = MapSize / 2;
        }
        else {
            // 유효한 위치들 중 랜덤하게 선택
            int randomIndex = rand() % validPositions.size();
            *x = validPositions[randomIndex].first;
            *y = validPositions[randomIndex].second;
        }
    }
    
    board_2019180053[*y][*x] = BLACK;
}

// 흑돌 플레이어의 공격 동작 (가중치 기반)

void BlackPlayerDefense(int x, int y)
{

    board_2019180053[y][x] = White;
}
