#include "all.h"

int zastavka()
{
    system("cls");
    setlocale(LC_ALL, "Rus");
    char title[] = "Алгоритм поиска Максимальных Паросочетаний\n";
    char title2[] = "         Выполнил Корнилов Влад\n";
    char title3[] = "               Группа 22ВВП2 ";
    int length = strlen(title);
    int length2 = strlen(title2);
    int length3 = strlen(title3);
    int x, y;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    x = (console_width - length) / 2;
    y = console_height / 2;


    for (int i = 0; i < y; i++)
        printf("\n");
    for (int i = 0; i < x; i++)
        printf(" ");
    for (int j = 0; j < length; j++)
    {
        printf("\033[91m""%c""\033[m", title[j]);
        Sleep(50);
    }
    Sleep(500);

    for (int k = 0; k < x; k++)
        printf(" ");
    for (int m = 0; m < length2; m++)
    {
        printf("%c", title2[m]);
        Sleep(50);
    }
    Sleep(500);
    for (int l = 0; l < y; l++)
        printf("\n");
    for (int l = 0; l < x; l++)
        printf(" ");
    for (int n = 0; n < length3; n++)
    {
        printf("%c", title3[n]);
        Sleep(50);
    }
    Sleep(2000);
    system("cls");
    return 0;
}
int zastavka2()
{
    system("cls");
    setlocale(LC_ALL, "Rus");
    char title[] = "   До скорых встреч!\n";
    char title2[] = "          <3 ";
    int length = strlen(title);
    int length2 = strlen(title2);
    int x, y;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    x = (console_width - length) / 2;
    y = console_height / 2;


    for (int i = 0; i < y; i++)
        printf("\n");
    for (int i = 0; i < x; i++)
        printf(" ");
    for (int j = 0; j < length; j++)
    {
        printf("%c", title[j]);
        Sleep(100);
    }
    Sleep(1000);

    for (int l = 0; l < x; l++)
        printf(" ");
    for (int n = 0; n < length2; n++)
    {
        printf("\033[91m""%c""\033[m", title2[n]);
        Sleep(100);
    }
    Sleep(2000);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    return 0;
}