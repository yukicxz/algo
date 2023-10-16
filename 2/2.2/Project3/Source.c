#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

void shell(int* items, int count)
{
    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}
int comp(const int* i, const int* j) {
    return *i - *j;
}
int main() {
    int n;
    setlocale(LC_ALL, "RUSSIAN");
    srand(time(NULL));
    printf("Введите размер массива: \n");
    scanf("%d", &n);
    int* b = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n; l++)
            b[i] = l;
    }
    time_t start1 = clock();
    qs(b, 0, n - 1);
    time_t stop = clock();
    double time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    FILE* res = fopen("umn.txt", "a");
    fprintf(res, "Быстрая сортировка возрастающих %d элементов выполнена за %5.3f секунд \n", n, time2);
    for (int j = 0; j < n; j++) {
        for (int l = n; l > 0; l--)
            b[j] = l;
    }
    start1 = clock();
    qs(b, 0, n - 1);
    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Быстрая сортировка убывающих %d элементов выполнена за %5.3f секунд \n", n, time2);

    for (int i = 0; i < n / 2; i++) {
        for (int l = 0; l < n / 2; l++)
            b[i] = l;
    }
    for (int j = n / 2; j < n; j++) {
        for (int l = n / 2 - 1; l > 0; l--)
            b[j] = l;
    }
    start1 = clock();
    qs(b, 0, n - 1);
    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Быстрая сортировка возрастающе-убывающих %d элементов выполнена за %5.3f секунд \n", n, time2);
    for (int j = 0; j < n; j++)
        b[j] = rand() % 100;
    start1 = clock();
    qs(b, 0, n-1);
    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Быстрая сортировка случайных %d элементов выполнена за %5.3f секунд \n", n, time2);
    fprintf(res, "\n");

    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n; l++)
            b[i] = l;
    }
    start1 = clock();
    shell(b, n);
    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Сортировка Шелла возрастающих %d элементов выполнена за %5.3f секунд \n", n, time2);
    for (int j = 0; j < n; j++) {
        for (int l = n; l > 0; l--)
            b[j] = l;
    }
    start1 = clock();
    shell(b, n);
    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Сортировка Шелла убывающих %d элементов выполнена за %5.3f секунд \n", n, time2);

    for (int i = 0; i < n / 2; i++) {
        for (int l = 0; l < n / 2; l++)
            b[i] = l;
    }
    for (int j = n / 2; j < n; j++) {
        for (int l = n / 2 - 1; l > 0; l--)
            b[j] = l;
    }
    start1 = clock();
    shell(b, n);
    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Сортировка Шелла возрастающе-убывающих %d элементов выполнена за %5.3f секунд \n", n, time2);
    for (int j = 0; j < n; j++)
        b[j] = rand() % 100;
    start1 = clock();
    shell(b, n);
    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Сортировка Шелла случайных %d элементов выполнена за %5.3f секунд \n", n, time2);
    fprintf(res, "\n");

    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n; l++)
            b[i] = l;
    }
    start1 = clock();
    qsort(b, n, sizeof(int), (int(*)(const void*, const void*)) comp);

    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Сортировка стандартной функцией qsort возрастающих %d элементов выполнена за %5.3f секунд \n", n, time2);
    for (int j = 0; j < n; j++) {
        for (int l = n; l > 0; l--)
            b[j] = l;
    }
    start1 = clock();
    qsort(b, n, sizeof(int), (int(*)(const void*, const void*)) comp);

    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Сортировка стандартной функцией qsort убывающих %d элементов выполнена за %5.3f секунд \n", n, time2);

    for (int i = 0; i < n / 2; i++) {
        for (int l = 0; l < n / 2; l++)
            b[i] = l;
    }
    for (int j = n / 2; j < n; j++) {
        for (int l = n / 2 - 1; l > 0; l--)
            b[j] = l;
    }
    start1 = clock();
    qsort(b, n, sizeof(int), (int(*)(const void*, const void*)) comp);

    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Сортировка стандартной функцией qsort возрастающе-убывающих %d элементов выполнена за %5.3f секунд \n", n, time2);
    for (int j = 0; j < n; j++)
        b[j] = rand() % 100;
    start1 = clock();
    qsort(b, n, sizeof(int), (int(*)(const void*, const void*)) comp);
    stop = clock();
    time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
    fprintf(res, "Сортировка стандартной функцией qsort случайных %d элементов выполнена за %5.3f секунд \n", n, time2);
    fprintf(res, "\n");
    printf("Сортировка успешно завершена)");

    fclose(res);
    free(b);
}