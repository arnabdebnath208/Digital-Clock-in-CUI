#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int height = 10;
int width = 15;
int colon_width = 3;

char *one = "         888888         888888            888            888            888            888            888            888            888            888";
char *two = "888888888888888888888888888888888         888            888888888888888888888888888888888888            888            888888888888888888888888888888";
char *three = "888888888888888888888888888888            888            888888888888888888888888888888888            888            888888888888888888888888888888888";
char *four = "888         888888         888888         888888         888888888888888888888888888888888            888            888            888            888";
char *five = "888888888888888888888888888888888            888            888888888888888888888888888888            888888         888888888888888888888888888888888";
char *six = "888888888888888888888888888888888            888            888888888888888888888888888888888         888888         888888888888888888888888888888888";
char *seven = "888888888888888888888888888888888         888888         888            888            888            888            888            888            888";
char *eight = "888888888888888888888888888888888         888888         888888888888888888888888888888888888         888888         888888888888888888888888888888888";
char *nine = "888888888888888888888888888888888         888888         888888888888888888888888888888888            888888         888888888888888888888888888888888";
char *zero = "888888888888888888888888888888888         888888         888888         888888         888888         888888         888888888888888888888888888888888";
char *colon = "888888                  888888";

int show_time(int, int, int);
int main()
{
    int h, m, s;
    struct tm tm;
    while (1)
    {
        time_t T = time(NULL);
        tm = *localtime(&T);
        h = tm.tm_hour;
        m = tm.tm_min;
        s = tm.tm_sec;
        show_time(h, m, s);
        sleep(1);
        system("clear");
    }
}
int show_time(int h, int m, int s)
{
    for (int i = 0; i < height; i++)
    {
        int h2 = h % 10, m2 = m % 10, s2 = s % 10;
        int h1 = h / 10, m1 = m / 10, s1 = s / 10;
        for (int j = 0; j < 6; j++)
        {
            int tmp;
            if (j == 2 || j == 4)
            {
                for (int k = 0; k < colon_width; k++)
                {
                    printf("%c", colon[i * colon_width + k]);
                }
                printf("  ");
            }
            switch (j)
            {
            case 0:
                tmp = h1;
                break;
            case 1:
                tmp = h2;
                break;
            case 2:
                tmp = m1;
                break;
            case 3:
                tmp = m2;
                break;
            case 4:
                tmp = s1;
                break;
            case 5:
                tmp = s2;
                break;
            }
            char *cc;
            switch (tmp)
            {
            case 1:
                cc = one;
                break;
            case 2:
                cc = two;
                break;
            case 3:
                cc = three;
                break;
            case 4:
                cc = four;
                break;
            case 5:
                cc = five;
                break;
            case 6:
                cc = six;
                break;
            case 7:
                cc = seven;
                break;
            case 8:
                cc = eight;
                break;
            case 9:
                cc = nine;
                break;
            case 0:
                cc = zero;
                break;
            }
            for (int k = 0; k < width; k++)
            {
                printf("%c", cc[i * width + k]);
            }
            printf("  ");
        }
        printf("\n");
    }
}
