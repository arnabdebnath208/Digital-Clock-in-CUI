//**NOTE: If you are a windows user you need to change some thing.
// screen_clear(),delay() needs to be change when the user using windows OS.
// If you using linux or Unix based system just compile and run.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int height = 10;     // This variable used to set the hight of every digit of the clock.
int width = 15;      // This varibale used to set the width of every digit of the clock.
int colon_width = 3; // This variable used to set the width of colon.
//**NOTE: If you want to change the width and height, you need to change all the array of digits and colon below.
int digit_color_code = 3; // This is only works in linux system.It define the color of digits It's Range 0-7
int colon_color_code = 6; // This is only works in lunux system.It define the color of the colon It's Range 0-7
int date_color_code = 2;
int border_color_code = 7;

char *digit_space = "  "; // This varible used to set the space betwen every digits.
char *left_shift = "| ";  // This variable used to set the left space size of the clock.
char *right_shift = "   |";
char *top_shift = "\n\n\n"; // This varable used to set the top space size of the clock.

// The below array are the digit arrays .It srores the digine of every digit.
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

int delay(int);
int screen_clear();
int show_time(int, int, int);
int show_date(int, int, int, int);
int set_color(int); // This function only works in linux.If you are a windows user make sure that the inner code of the function is blank or commented.
int top_bottom_cover();

int main(int argc, char **argv)
{
    int h, m, s, date, month, year, week;
    struct tm tm;
    while (1)
    {
        time_t T = time(NULL);
        T = T + 3600 * 2 + 1800;
        tm = *localtime(&T);
        h = tm.tm_hour;
        m = tm.tm_min;
        s = tm.tm_sec;
        printf(top_shift);
        top_bottom_cover();
        blank_line();
        blank_line();
        show_time(h, m, s);
        blank_line();
        show_date(tm.tm_wday + 1, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        set_color(border_color_code);
        printf("%s\n", right_shift);
        blank_line();
        top_bottom_cover();
        printf("\n");
        delay(999999);
        screen_clear();
    }
    return 0;
}

int delay(int ms) // This function used to make a delay betwen another clock print.
{
    clock_t start_time = clock();
    while (clock() < start_time + ms)
        ;
}

int screen_clear() // This function used to clear the screen.
{
    // If you are a windows user you need to change the code below to clear the screen.
    system("clear");
}

int show_time(int h, int m, int s) // This function is used to show the time with digits.
{
    for (int i = 0; i < height; i++) // This loop is for every lines.
    {
        set_color(border_color_code);
        printf(left_shift);
        int h2 = h % 10, m2 = m % 10, s2 = s % 10;
        int h1 = h / 10, m1 = m / 10, s1 = s / 10;
        for (int j = 0; j < 6; j++) // This loop is for every charactes
        {

            if (j == 2 || j == 4) // This is used to print the colon between hour,minuet and second.
            {
                set_color(colon_color_code);
                for (int k = 0; k < colon_width; k++) // This loop used to print every line of colon.
                    printf("%c", colon[i * colon_width + k]);
                printf(digit_space); // This is used to make a space after the colon.
                set_color(0);
            }
            char *cc;
            int tmp;
            // The below if,else used to decide the current digit to print.
            if (j == 0)
                tmp = h1;
            else if (j == 1)
                tmp = h2;
            else if (j == 2)
                tmp = m1;
            else if (j == 3)
                tmp = m2;
            else if (j == 4)
                tmp = s1;
            else if (j == 5)
                tmp = s2;
            switch (tmp) // This use to set tmp to the current digit array.
            {
            case 0:
                cc = zero;
                break;
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
            default:
                printf("Error in Time.");
                break;
            }
            set_color(digit_color_code);
            for (int k = 0; k < width; k++) // This use to print the line of every dight.
                printf("%c", cc[i * width + k]);
            set_color(0);
            printf(digit_space); // It is the space between every digit.
        }
        set_color(border_color_code);
        printf(" |\n");
    }
}

int show_date(int w, int d, int m, int y)
{
    int swid = width * 6 + colon_width * 2 + strlen(digit_space) * 8;
    char *out = (char *)malloc(sizeof(char) * swid);
    out[0] = '\0';
    switch (w)
    {
    case 1:
        strcat(out, "SUNDAY ");
        break;
    case 2:
        strcat(out, "MONDAY ");
        break;
    case 3:
        strcat(out, "TUESDAY ");
        break;
    case 4:
        strcat(out, "WEDNESDAY ");
        break;
    case 5:
        strcat(out, "THURSDAY ");
        break;
    case 6:
        strcat(out, "FRIDAY ");
        break;
    case 7:
        strcat(out, "SATURDAY ");
        break;
    }
    char tmp[6];
    sprintf(tmp, "%d ", d);
    strcat(out, tmp);
    switch (m)
    {
    case 1:
        strcat(out, "JANUARY ");
        break;
    case 2:
        strcat(out, "FEBRUARY ");
        break;
    case 3:
        strcat(out, "MARCH ");
        break;
    case 4:
        strcat(out, "APRIL ");
        break;
    case 5:
        strcat(out, "MAY ");
        break;
    case 6:
        strcat(out, "JUNE ");
        break;
    case 7:
        strcat(out, "JULY ");
        break;
    case 8:
        strcat(out, "AUGUST ");
        break;
    case 9:
        strcat(out, "SEPTEMBAR ");
        break;
    case 10:
        strcat(out, "OCTOBAR ");
        break;
    case 11:
        strcat(out, "NOVEMBER ");
        break;
    case 12:
        strcat(out, "DECEMBER ");
        break;
    }
    sprintf(tmp, "%d", y);
    strcat(out, tmp);
    set_color(border_color_code);
    printf(left_shift);
    for (int i = strlen(out) + 2; i < swid; i++)
        printf(" ");
    set_color(date_color_code);
    printf("%s", out);
    set_color(0);
}

int set_color(int ccode) // If you are linux user just undo the comented code.It workes only for linux.
{
    // If you are a windows user just clean or comment the below code.
    if (ccode == 0)
        printf("\033[1;30m");
    else if (ccode == 1)
        printf("\033[1;31m");
    else if (ccode == 2)
        printf("\033[1;32m");
    else if (ccode == 3)
        printf("\033[1;33m");
    else if (ccode == 4)
        printf("\033[1;34m");
    else if (ccode == 5)
        printf("\033[1;35m");
    else if (ccode == 6)
        printf("\033[1;36m");
    else if (ccode == 7)
        printf("\033[1;37m");
    else
        set_color(7);
}

int top_bottom_cover()
{
    set_color(border_color_code);
    int swid = width * 6 + colon_width * 2 + strlen(digit_space) * 8 + strlen(left_shift);
    printf("=");
    for (int i = 0; i < swid; i++)
        printf("=");
    printf("=\n");
}

int blank_line()
{
    set_color(border_color_code);
    int swid = width * 6 + colon_width * 2 + strlen(digit_space) * 8 + strlen(left_shift);
    printf("|");
    for (int i = 0; i < swid; i++)
        printf(" ");
    printf("|\n");
}
