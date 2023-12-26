#ifndef all_h
#define all_h
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#define MAX_LINE_LENGTH 100
int menu();
int edmonds(int** A, int n);
int find_path(int root, int* match, int n, int** A, int* p, int* used);
void printLast200Lines();
int zastavka();
int zastavka2();
#endif

