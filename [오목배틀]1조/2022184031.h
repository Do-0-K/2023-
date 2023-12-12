#pragma once

#include <stdlib.h>
#include <time.h>

int board_2022184031[18][18];

#define BLACK -1
#define WHITE 1

void WhiteAttack_2022184031(int *x, int *y)
{
    int contiB = 1, num1 = 1, num2 = 16, save = 16;
    bool jump = false;

    srand(time(NULL));

    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (board_2022184031[i][j] == BLACK)
            {
                if (board_2022184031[i][j + 1] == BLACK)
                    contiB++;
                else if (board_2022184031[i][j + 1] == 0 && board_2022184031[i][j + 2] == BLACK)
                {
                    j++;
                    contiB += 2;
                    jump = true;
                }
                else
                {
                    if (contiB >= 3 && !jump)
                    {
                        if (board_2022184031[i][j - contiB] == 0)
                        {
                            *x = i;
                            *y = j - contiB;
                            board_2022184031[*x][*y] = WHITE;
                            return;
                        }
                        else  if (board_2022184031[i][j] == 0)
                        {
                            *x = i;
                            *y = j;
                            board_2022184031[*x][*y] = WHITE;
                            return;
                        }
                    }
                    else if (contiB > 3 && jump)
                    {
                        for (int l = 1; l < contiB + 1; l++)
                        {
                            if (board_2022184031[i][j - contiB + l] == 0)
                            {
                                *x = i;
                                *y = j - contiB + l;
                                board_2022184031[*x][*y] = WHITE;
                                return;
                            }
                        }
                    }
                    contiB = 1;
                    jump = false;
                }
            }
        }
    }

    contiB = 1;
    jump = false;

    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (board_2022184031[j][i] == BLACK)
            {
                if (board_2022184031[j + 1][i] == BLACK)
                    contiB++;
                else if (board_2022184031[j + 1][i] == 0 && board_2022184031[j + 2][i] == BLACK)
                {
                    j++;
                    contiB += 2;
                    jump = true;
                }
                else
                {
                    if (contiB >= 3 && !jump)
                    {
                        if (board_2022184031[j - contiB][i] == 0)
                        {
                            *x = j - contiB;
                            *y = i;
                            board_2022184031[*x][*y] = WHITE;
                            return;
                        }
                        else  if (board_2022184031[j][i] == 0)
                        {
                            *x = j;
                            *y = i;
                            board_2022184031[*x][*y] = WHITE;
                            return;
                        }
                    }
                    else if (contiB > 3 && jump)
                    {
                        for (int l = 1; l < contiB + 1; l++)
                        {
                            if (board_2022184031[j - contiB + l][i] == 0)
                            {
                                *x = j - contiB + l;
                                *y = i;
                                board_2022184031[*x][*y] = WHITE;
                                return;
                            }
                        }
                    }
                    contiB = 1;
                    jump = false;
                }
            }
        }
    }

    contiB = 1;
    jump = false;

    for (int k = 0; k < 33; k++)
    {
        for (int i = 0; i < 18; i++)
        {
            for (int j = 0; j < 18; j++)
            {
                if (i + j == num1)
                {
                    if (board_2022184031[i][j] == BLACK)
                    {
                        if (board_2022184031[i + 1][j - 1] == BLACK)
                            contiB++;
                        else if (board_2022184031[i + 1][j - 1] == 0 && board_2022184031[i + 2][j - 2] == BLACK)
                        {
                            i++;
                            j--;
                            contiB += 2;
                            jump = true;
                        }
                        else
                        {
                            if (contiB >= 3 && !jump)
                            {
                                if (board_2022184031[i - contiB][j + contiB] == 0)
                                {
                                    *x = i - contiB;
                                    *y = j + contiB;
                                    board_2022184031[*x][*y] = WHITE;
                                    return;
                                }
                                else  if (board_2022184031[i][j] == 0)
                                {
                                    *x = i;
                                    *y = j;
                                    board_2022184031[*x][*y] = WHITE;
                                    return;
                                }
                            }
                            else if (contiB > 3 && jump)
                            {
                                for (int l = 1; l < contiB + 1; l++)
                                {
                                    if (board_2022184031[i - contiB + l][j + contiB - l] == 0)
                                    {
                                        *x = i - contiB + l;
                                        *y = j + contiB - l;
                                        board_2022184031[*x][*y] = WHITE;
                                        return;
                                    }
                                }
                            }
                            contiB = 1;
                            jump = false;
                        }
                    }
                }
            }
        }
        num1++;
    }

    contiB = 1;
    jump = false;

    for (int k = 0; k < 33; k++)
    {
        if (k < 17)
        {
            for (int i = 0; i < 18; i++)
            {
                for (int j = 17; j >= 0; j--)
                {
                    if (i + j == num2 && i <= j)
                    {
                        if (board_2022184031[i][j] == BLACK)
                        {
                            if (board_2022184031[i + 1][j + 1] == BLACK)
                                contiB++;
                            else if (board_2022184031[i + 1][j + 1] == 0 && board_2022184031[i + 2][j + 2] == BLACK)
                            {
                                contiB += 2;
                                jump = true;
                            }
                            else
                            {
                                if (contiB >= 3 && !jump)
                                {
                                    if (board_2022184031[i - contiB][j - contiB] == 0)
                                    {
                                        *x = i - contiB;
                                        *y = j - contiB;
                                        board_2022184031[*x][*y] = WHITE;
                                        return;
                                    }
                                    else  if (board_2022184031[i][j] == 0)
                                    {
                                        *x = i;
                                        *y = j;
                                        board_2022184031[*x][*y] = WHITE;
                                        return;
                                    }
                                }
                                else if (contiB > 3 && jump)
                                {
                                    for (int l = 1; l < contiB + 1; l++)
                                    {
                                        if (board_2022184031[i - contiB + l][j - contiB + l] == 0)
                                        {
                                            *x = i - contiB + l;
                                            *y = j - contiB + l;
                                            board_2022184031[*x][*y] = WHITE;
                                            return;
                                        }
                                    }
                                }
                                contiB = 1;
                                jump = false;
                            }
                        }
                    }
                }
                num2 += 2;
            }

            contiB = 1;
            jump = false;
            save--;
            if (k == 16)
                save = 1;
            num2 = save;
        }
        else
        {
            for (int i = num2; i < 18; i++)
            {
                for (int j = 0; j < 18; j++)
                {
                    if (i + j == num2 && i > j)
                    {
                        if (board_2022184031[i][j] == BLACK)
                        {
                            if (board_2022184031[i + 1][j + 1] == BLACK)
                                contiB++;
                            else if (board_2022184031[i + 1][j + 1] == 0 && board_2022184031[i + 2][j + 2] == BLACK)
                            {
                                contiB += 2;
                                jump = true;
                            }
                            else
                            {
                                if (contiB >= 3 && !jump)
                                {
                                    if (board_2022184031[i - contiB][j - contiB] == 0)
                                    {
                                        *x = i - contiB;
                                        *y = j - contiB;
                                        board_2022184031[*x][*y] = WHITE;
                                        return;
                                    }
                                    else  if (board_2022184031[i][j] == 0)
                                    {
                                        *x = i;
                                        *y = j;
                                        board_2022184031[*x][*y] = WHITE;
                                        return;
                                    }
                                }
                                else if (contiB > 3 && jump)
                                {
                                    for (int l = 1; l < contiB + 1; l++)
                                    {
                                        if (board_2022184031[i - contiB + l][j - contiB + l] == 0)
                                        {
                                            *x = i - contiB + l;
                                            *y = j - contiB + l;
                                            board_2022184031[*x][*y] = WHITE;
                                            return;
                                        }
                                    }
                                }
                                contiB = 1;
                                jump = false;
                            }
                        }
                    }
                }
                num2 += 2;
            }

            contiB = 1;
            jump = false;
            save++;
            num2 = save;
        }
    }

    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (board_2022184031[i][j] == WHITE)
            {
                if (board_2022184031[i][j + 1] == 0)
                {
                    *x = i;
                    *y = j + 1;
                    board_2022184031[*x][*y] = WHITE;
                    return;
                }
                else if (board_2022184031[i][j - 1] == 0)
                {
                    *x = i;
                    *y = j - 1;
                    board_2022184031[*x][*y] = WHITE;
                    return;
                }
                else if (board_2022184031[i + 1][j] == 0)
                {
                    *x = i + 1;
                    *y = j;
                    board_2022184031[*x][*y] = WHITE;
                    return;
                }
                else if (board_2022184031[i - 1][j] == 0)
                {
                    *x = i - 1;
                    *y = j;
                    board_2022184031[*x][*y] = WHITE;
                    return;
                }
                else if (board_2022184031[i - 1][j - 1] == 0)
                {
                    *x = i - 1;
                    *y = j - 1;
                    board_2022184031[*x][*y] = WHITE;
                    return;
                }
                else if (board_2022184031[i - 1][j + 1] == 0)
                {
                    *x = i - 1;
                    *y = j + 1;
                    board_2022184031[*x][*y] = WHITE;
                    return;
                }
                else if (board_2022184031[i + 1][j - 1] == 0)
                {
                    *x = i + 1;
                    *y = j - 1;
                    board_2022184031[*x][*y] = WHITE;
                    return;
                }
                else if (board_2022184031[i + 1][j + 1] == 0)
                {
                    *x = i + 1;
                    *y = j + 1;
                    board_2022184031[*x][*y] = WHITE;
                    return;
                }
                else
                    continue;
            }
        }
    }

    while (1)
    {
        *x = rand() % 18;
        *y = rand() % 18;
        if (board_2022184031[*x][*y] == 0)
            break;
    }
    board_2022184031[*x][*y] = WHITE;
}

void WhiteDefence_2022184031(int x, int y)
{
	board_2022184031[x][y] = BLACK;
}

void BlackAttack_2022184031(int* x, int* y)
{
    int contiW = 1, num1 = 1, num2 = 16, save = 16;
    bool jump = false;

    srand(time(NULL));

    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (board_2022184031[i][j] == WHITE)
            {
                if (board_2022184031[i][j + 1] == WHITE)
                    contiW++;
                else if (board_2022184031[i][j + 1] == 0 && board_2022184031[i][j + 2] == WHITE)
                {
                    j++;
                    contiW += 2;
                    jump = true;
                }
                else
                {
                    if (contiW >= 3 && !jump)
                    {
                        if (board_2022184031[i][j - contiW] == 0)
                        {
                            *x = i;
                            *y = j - contiW;
                            board_2022184031[*x][*y] = BLACK;
                            return;
                        }
                        else  if (board_2022184031[i][j] == 0)
                        {
                            *x = i;
                            *y = j;
                            board_2022184031[*x][*y] = BLACK;
                            return;
                        }
                    }
                    else if (contiW > 3 && jump)
                    {
                        for (int l = 1; l < contiW + 1; l++)
                        {
                            if (board_2022184031[i][j - contiW + l] == 0)
                            {
                                *x = i;
                                *y = j - contiW + l;
                                board_2022184031[*x][*y] = BLACK;
                                return;
                            }
                        }
                    }
                    contiW = 1;
                    jump = false;
                }
            }
        }
    }

    contiW = 1;
    jump = false;

    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (board_2022184031[j][i] == WHITE)
            {
                if (board_2022184031[j + 1][i] == WHITE)
                    contiW++;
                else if (board_2022184031[j + 1][i] == 0 && board_2022184031[j + 2][i] == WHITE)
                {
                    j++;
                    contiW += 2;
                    jump = true;
                }
                else
                {
                    if (contiW >= 3 && !jump)
                    {
                        if (board_2022184031[j - contiW][i] == 0)
                        {
                            *x = j - contiW;
                            *y = i;
                            board_2022184031[*x][*y] = BLACK;
                            return;
                        }
                        else  if (board_2022184031[j][i] == 0)
                        {
                            *x = j;
                            *y = i;
                            board_2022184031[*x][*y] = BLACK;
                            return;
                        }
                    }
                    else if (contiW > 3 && jump)
                    {
                        for (int l = 1; l < contiW + 1; l++)
                        {
                            if (board_2022184031[j - contiW + l][i] == 0)
                            {
                                *x = j - contiW + 1;
                                *y = i;
                                board_2022184031[*x][*y] = BLACK;
                                return;
                            }
                        }
                    }
                    contiW = 1;
                    jump = false;
                }
            }
        }
    }

    contiW = 1;
    jump = false;

    for (int k = 0; k < 33; k++)
    {
        for (int i = 0; i < 18; i++)
        {
            for (int j = 0; j < 18; j++)
            {
                if (i + j == num1)
                {
                    if (board_2022184031[i][j] == WHITE)
                    {
                        if (board_2022184031[i + 1][j - 1] == WHITE)
                            contiW++;
                        else if (board_2022184031[i + 1][j - 1] == 0 && board_2022184031[i + 2][j - 2] == WHITE)
                        {
                            i++;
                            j--;
                            contiW += 2;
                            jump = true;
                        }
                        else
                        {
                            if (contiW >= 3 && !jump)
                            {
                                if (board_2022184031[i - contiW][j + contiW] == 0)
                                {
                                    *x = i - contiW;
                                    *y = j + contiW;
                                    board_2022184031[*x][*y] = BLACK;
                                    return;
                                }
                                else  if (board_2022184031[i][j] == 0)
                                {
                                    *x = i;
                                    *y = j;
                                    board_2022184031[*x][*y] = BLACK;
                                    return;
                                }
                            }
                            else if (contiW > 3 && jump)
                            {
                                for (int l = 1; l < contiW + 1; l++)
                                {
                                    if (board_2022184031[i - contiW + l][j + contiW - l] == 0)
                                    {
                                        *x = i - contiW + 1;
                                        *y = j + contiW - 1;
                                        board_2022184031[*x][*y] = BLACK;
                                        return;
                                    }
                                }
                            }
                            contiW = 1;
                            jump = false;
                        }
                    }
                }
            }
        }
        num1++;
    }

    contiW = 1;
    jump = false;

    for (int k = 0; k < 33; k++)
    {
        if (k < 17)
        {
            for (int i = 0; i < 18; i++)
            {
                for (int j = 17; j >= 0; j--)
                {
                    if (i + j == num2 && i <= j)
                    {
                        if (board_2022184031[i][j] == WHITE)
                        {
                            if (board_2022184031[i + 1][j + 1] == WHITE)
                                contiW++;
                            else if (board_2022184031[i + 1][j + 1] == 0 && board_2022184031[i + 2][j + 2] == WHITE)
                            {
                                contiW += 2;
                                jump = true;
                            }
                            else
                            {
                                if (contiW >= 3 && !jump)
                                {
                                    if (board_2022184031[i - contiW][j - contiW] == 0)
                                    {
                                        *x = i - contiW;
                                        *y = j - contiW;
                                        board_2022184031[*x][*y] = BLACK;
                                        return;
                                    }
                                    else  if (board_2022184031[i][j] == 0)
                                    {
                                        *x = i;
                                        *y = j;
                                        board_2022184031[*x][*y] = BLACK;
                                        return;
                                    }
                                }
                                else if (contiW > 3 && jump)
                                {
                                    for (int l = 1; l < contiW + 1; l++)
                                    {
                                        if (board_2022184031[i - contiW + l][j - contiW + l] == 0)
                                        {
                                            *x = i - contiW + l;
                                            *y = j - contiW + l;
                                            board_2022184031[*x][*y] = BLACK;
                                            return;
                                        }
                                    }
                                }
                                contiW = 1;
                                jump = false;
                            }
                        }
                    }
                }
                num2 += 2;
            }

            contiW = 1;
            jump = false;
            save--;
            if (k == 16)
                save = 1;
            num2 = save;
        }
        else
        {
            for (int i = num2; i < 18; i++)
            {
                for (int j = 0; j < 18; j++)
                {
                    if (i + j == num2 && i > j)
                    {
                        if (board_2022184031[i][j] == WHITE)
                        {
                            if (board_2022184031[i + 1][j + 1] == WHITE)
                                contiW++;
                            else if (board_2022184031[i + 1][j + 1] == 0 && board_2022184031[i + 2][j + 2] == WHITE)
                            {
                                contiW += 2;
                                jump = true;
                            }
                            else
                            {
                                if (contiW >= 3 && !jump)
                                {
                                    if (board_2022184031[i - contiW][j - contiW] == 0)
                                    {
                                        *x = i - contiW;
                                        *y = j - contiW;
                                        board_2022184031[*x][*y] = BLACK;
                                        return;
                                    }
                                    else  if (board_2022184031[i][j] == 0)
                                    {
                                        *x = i;
                                        *y = j;
                                        board_2022184031[*x][*y] = BLACK;
                                        return;
                                    }
                                }
                                else if (contiW > 3 && jump)
                                {
                                    for (int l = 1; l < contiW + 1; l++)
                                    {
                                        if (board_2022184031[i - contiW + l][j - contiW + l] == 0)
                                        {
                                            *x = i - contiW + l;
                                            *y = j - contiW + l;
                                            board_2022184031[*x][*y] = BLACK;
                                            return;
                                        }
                                    }
                                }
                                contiW = 1;
                                jump = false;
                            }
                        }
                    }
                }
                num2 += 2;
            }

            contiW = 1;
            jump = false;
            save++;
            num2 = save;
        }
    }

    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (board_2022184031[i][j] == BLACK)
            {
                if (board_2022184031[i][j + 1] == 0)
                {
                    *x = i;
                    *y = j + 1;
                    board_2022184031[*x][*y] = BLACK;
                    return;
                }
                else if (board_2022184031[i][j - 1] == 0)
                {
                    *x = i;
                    *y = j - 1;
                    board_2022184031[*x][*y] = BLACK;
                    return;
                }
                else if (board_2022184031[i + 1][j] == 0)
                {
                    *x = i+1;
                    *y = j;
                    board_2022184031[*x][*y] = BLACK;
                    return;
                }
                else if (board_2022184031[i - 1][j] == 0)
                {
                    *x = i - 1;
                    *y = j;
                    board_2022184031[*x][*y] = BLACK;
                    return;
                }
                else if (board_2022184031[i - 1][j - 1] == 0)
                {
                    *x = i - 1;
                    *y = j - 1;
                    board_2022184031[*x][*y] = BLACK;
                    return;
                }
                else if (board_2022184031[i - 1][j + 1] == 0)
                {
                    *x = i - 1;
                    *y = j + 1;
                    board_2022184031[*x][*y] = BLACK;
                    return;
                }
                else if (board_2022184031[i + 1][j - 1] == 0)
                {
                    *x = i + 1;
                    *y = j - 1;
                    board_2022184031[*x][*y] = BLACK;
                    return;
                }
                else if (board_2022184031[i + 1][j + 1] == 0)
                {
                    *x = i + 1;
                    *y = j + 1;
                    board_2022184031[*x][*y] = BLACK;
                    return;
                }
                else
                    continue;
            }
        }
    }

    while (1)
    {
        *x = rand() % 18;
        *y = rand() % 18;
        if (board_2022184031[*x][*y] == 0)
            break;
    }
    board_2022184031[*x][*y] = BLACK;
}

void BlackDefence_2022184031(int x, int y)
{
	board_2022184031[x][y] = WHITE;
}