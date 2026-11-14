#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define height 15
#define width 60
void gotoxy(int x, int y);
void hide_cursor();
int main()
{
    while (1)
    {
        int dir = 0;
        char want = 'a';
        int speed = 300;
        char direction='q';
        while (want == 'a' || want == 'A')
        {
            srand(time(NULL));
            
            int map[height][width];
            int x[100], y[100];
            int score = 0;
            x[0] = 10, y[0] = 10;
            int a, b;
            int m[100], n[100];
            do
            {
                a = rand() % 13 + 1;
                b = rand() % 58 + 1;
            } while (a == x[0] && b == y[0]);
            hide_cursor();
            
            while (1)
            {

                for (int k = 1; k <= score; k++)
                {

                    if (x[k] == a && y[k] == b)
                    {
                        a = rand() % 13 + 1;
                        b = rand() % 58 + 1;
                    }
                }
                gotoxy(0, 0);
                for (int i = 0; i < height; i++)
                {
                    for (int j = 0; j < width; j++)
                    {

                        if (i == x[0] && j == y[0])
                        {
                            printf("@");
                        }
                        else if (i == a && j == b)
                        {
                            printf("*");
                        }
                        else if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
                        {
                            map[i][j] = 1;
                            printf("#");
                        }

                        else
                        {
                            int body = 0;
                            for (int k = 1; k <= score; k++)
                            {
                                if (i == x[k] && j == y[k])
                                {
                                    body = 1;
                                }
                            }
                            if (body == 1)
                            {
                                printf("O");
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                    }
                    printf("\n");
                }
                printf("score:%d", score);
                Sleep(speed);
                for (int k = score; k >= 0; k--)
                {
                    m[k] = x[k], n[k] = y[k];
                }

                if (_kbhit())
                {
                    direction = _getch();
                }
                int dir_2 = dir;
                if (direction == 'w' || direction == 'W')
                {
                    dir = 1;
                }
                if (direction == 's' || direction == 'S')
                {
                    dir = -1;
                }
                if (direction == 'a' || direction == 'A')
                {
                    dir = 2;
                }
                if (direction == 'd' || direction == 'D')
                {
                    dir = -2;
                }
                if (dir_2 + dir == 0)
                {
                    dir = dir_2;
                }
                switch (dir)
                {
                case 1:
                    x[0]--;
                    break;
                case -1:
                    x[0]++;
                    break;
                case 2:
                    y[0]--;
                    break;
                case -2:
                    y[0]++;
                    break;
                }

                if (x[0] == a && y[0] == b)
                {
                    a = rand() % 13 + 1;
                    b = rand() % 58 + 1;
                    score++;
                }
                for (int k = score; k > 0; k--)
                {
                    x[k] = m[k - 1];
                    y[k] = n[k - 1];
                }
                if (score < 99)
                {
                    int hit = 0;
                    for (int fir = 1; fir <= score; fir++)
                    {
                        if (x[0] == x[fir] && y[0] == y[fir])
                        {
                            hit = 1;
                        }
                    }
                    if (x[0] == height - 1 || x[0] == 0 || y[0] == width - 1 || y[0] == 0 || hit == 1)
                    {
                        printf("\nGAME OVER!\n");
                        want = 'b';
                        break;
                    }
                }
                else
                {
                    printf("YOU ARE SO NB");
                    want = 'b';
                    break;
                }
            }
        }

        printf("if you want faster ,'f',against's',whether 'k'\n");
        char sp;
        scanf(" %c", &sp);
        if ((sp == 'f' || sp == 'F') && speed <= 500)
        {
            speed += 100;
        }
        else if ((sp == 's' || sp == 'S') && speed >= 100)
        {
            speed -= 100;
        }
        else
        {
            speed += 0;
        }
        printf("if you want again,please press A,against B.\n");
        char wantt;
        scanf(" %c",&wantt);
        want=wantt;
        if (want != 'a' && want != 'A')
        {
            break;
        }else{system("cls");}
    }
    system("pause");
    return 0;
}
void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void hide_cursor()
{
    CONSOLE_CURSOR_INFO cursor_into = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_into);
}