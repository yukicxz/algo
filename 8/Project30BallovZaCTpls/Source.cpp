#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<queue>
#include<time.h>
#include<iostream>
using namespace std;

typedef struct Node{
int ver;
struct Node* next;
} Node;

// Функция добавления ребра в список
void addver(Node** List, int x, int y) {
    // Созданиеновогоузла
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ver = y;
    newNode->next = NULL;

    // Проверка, существует ли уже ребро в списке
    if (List[x] == NULL) {
        List[x] = newNode;
    }
    else {
        Node* temp = List[x];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return;
}

// Функция отображения списков смежности
void vivod(Node** List, int n) {
    int i;
    for (i = 0; i < n; ++i) {
        Node* temp = List[i];
        printf("Список смежности вершины %d ", i);
        while (temp) {
            printf(" -> %d ", temp->ver);
            temp = temp->next;
        }
        printf("\n");
    }
    return;
}

int BFS(int** A, int* vis, int n, int v) {
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    while (!q.empty()) {
        v = q.front();
        printf("%d ", v);
        q.pop();
        for (int i = 0; i < n; i++) {
            if (A[v][i] == 1 && vis[i] != 1) {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return 0;
}

int BFS2(Node** List, int* vis, int n, int v) {
    queue<int> q;
    q.push(v);
    vis[v] = 1;

    while (!q.empty()) {
        v = q.front();
        printf("%d ", v);
        q.pop();
        Node* temp = List[v]; // обновляем указатель на список смежных вершин

        while (temp != NULL) {
            int i = temp->ver;
            if (vis[i] != 1) {
                q.push(i);
                vis[i] = 1;
            }
            temp = temp->next; // переходим к следующему узлу списка
        }
    }
    return 0;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 0;
    int** A;
    int* vis;
    int* vis1;
    int v = 0;
    // Создание и заполнение матрицы смежности
    printf("Введите НОРМАЛЬНОЕ количество вершин графа: ");
    scanf("%d", &n);
    vis = (int*)calloc(n, sizeof(int));
    srand(time(NULL));
    A = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            A[i][j] = rand() % 2;
            A[j][i] = A[i][j];
            if (i == j) {
                A[i][j] = 0;
            }
        }
    }

    // Выводматрицысмежности
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Введите НОРМАЛЬНУЮ вершину, с которой хотите начать: ");
    scanf("%d", &v);
    time_t start1 = clock();
    BFS(A, vis, n, v);
    time_t stop = clock();
    double time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;//времясортировки
    printf("\nВремя обхода: %5.3f секунд", time2);

    // Создание списка смежности
    Node** list1 = (Node**)malloc(n * sizeof(Node*));
    int i, j;
    for (i = 0; i < n; ++i) {
        list1[i] = NULL;
    }

    // Заполнение списка смежности
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (A[i][j] == 1) {
                addver(list1, i, j);
            }
        }
    }

    // Отображениеспискасмежности
    vis1 = (int*)calloc(n, sizeof(int));
    printf("\n");
    printf("\n");
    vivod(list1, n);
    printf("\n");
    BFS2(list1, vis1, n, v);
    return 0;
}
