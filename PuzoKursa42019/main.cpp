#define _CRT_SECURE_NO_WARNINGS
#include "all.h"
#include<queue>

using namespace std;

int graph() {
	int n = 0;
	int** A;
	int s, m;
	int err;
	float er;
	float er2;
	FILE* file = fopen("результаты.txt", "a");
	if (file == NULL) {
		printf("Ошибка при открытии файла.\n");
		return graph();
	}
	printf("\033[93m""Введите целое количество вершин графа: ""\033[m");
	err = scanf("%f", &er);
	if ((err == 0) || (er <= 0)) {
		printf("\033[31m""Ошибка: некорректный ввод.\n""\033[m");
		while (getchar() != '\n'); // Очистка буфера ввода
		return graph(); // 
	}
	n = (int)er;
	printf("\n");
	A = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(sizeof(int) * n);
	}
	printf("==================================\n");
	printf("=""\033[33m""   Выберите способ заполнения   ""\033[m""=\n");
	printf("==================================\n");
	printf("|                                |\n");
	printf("|""\033[93m""     1. Автоматически""\033[m""		 |\n");
	printf("|""\033[93m""     2. Вручную""\033[m""   		 |\n");
	printf("|""\033[93m""     3. Чтение из файла ""\033[m"" 	 |\n");
	printf("|                                |\n");
	printf("==================================\n");
	printf("Ваш выбор: ");
	err = scanf("%f", &er2);
	if (err != 1) {
		printf("\033[31m""Ошибка: некорректный ввод. Введите число.\n""\033[m");
		while (getchar() != '\n'); // Очистка буфера ввода
		return graph();
	}
	s = (int)er2;
	srand(time(NULL));
	switch (s) {
	case 1: {
		system("CLS");
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++) {
				A[i][j] = rand() % 2;
				A[j][i] = A[i][j];
				if (i == j) A[i][j] = 0;
			}
		system("CLS");
		printf("\033[93m""Матрица смежности:""\033[m""\n");
		fprintf(file, "\nРезультаты для матрицы смежности размером %d\n\n", n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", A[i][j]);
				fprintf(file, "%d ", A[i][j]);
			}
			fprintf(file, "\n");
			printf("\n");
		}
		printf("\nВсе ребра графа:\n");
		fprintf(file, "\nВсе ребра графа\n");
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (A[i][j] == 1) {
					printf("(%d-%d) ", i, j);
					fprintf(file, "(%d-%d) ", i, j);
				}
			}
		}
		fclose(file);
		edmonds(A, n);
		for (int i = 0; i < n; i++)
			free(A[i]);
		free(A);
		return 0;
	}
	case 2: {
		system("CLS");
		er = 0;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++) {
				if (i == j) A[i][j] = 0;
				if (i != j) {
					printf("Есть ли ребро между вершинами ""\033[93m""%d""\033[m" " и ""\033[93m""%d""\033[m"" (""\033[32m""1 - есть""\033[m"" / ""\033[31m""0 - нет""\033[m"") :\n", i, j);
					err = scanf("%f", &er);
					if (err != 1 || (er != 0 && er != 1)) {
						printf("\033[31m""Ошибка: некорректный ввод. Введите 0 или 1.\n""\033[m");
						while (getchar() != '\n'); // Очистка буфера ввода
						return graph();
					}
					m = (int)er;
					A[i][j] = m;
					A[j][i] = A[i][j];
				}
			}
		system("CLS");
		printf("\033[93m""Матрица смежности:""\033[m""\n");
		fprintf(file, "\nРезультаты для матрицы смежности размером %d\n\n", n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", A[i][j]);
				fprintf(file, "%d ", A[i][j]);
			}
			fprintf(file, "\n");
			printf("\n");
		}
		printf("\nВсе ребра графа:\n");
		fprintf(file, "\nВсе ребра графа\n");
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (A[i][j] == 1) {
					printf("(%d-%d) ", i, j);
					fprintf(file, "(%d-%d) ", i, j);
				}
			}
		}
		fclose(file);
		edmonds(A, n);
		for (int i = 0; i < n; i++)
			free(A[i]);
		free(A);
		return 0;
	}
	case 3: {
		system("CLS");
		FILE* file = fopen("граф.txt", "r");
		if (file == NULL) {
			printf("\033[31m""Ошибка: не удалось открыть файл.\n""\033[m");
			return 0;
		}
		FILE* file1 = fopen("результаты.txt", "a");
		if (file1 == NULL) {
			printf("\033[31m""Ошибка: не удалось открыть файл.\n""\033[m");
			return 0;
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (fscanf(file, "%d", &A[i][j]) != 1) {
					printf("\033[31m""Ошибка: некорректный размер графа.\n""\033[m");
					fclose(file);
					return graph();
				}
				count++;
			}
		}
		fclose(file);
		if (count != n * n) {
			printf("\033[31m""Ошибка: некорректное количество элементов в файле.\n""\033[m");
			return graph();
		}
		system("CLS");
		printf("\033[93m""Матрица смежности:""\033[m""\n");
		fprintf(file1, "\nРезультаты для матрицы смежности размером %d\n\n", n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", A[i][j]);
				fprintf(file1, "%d ", A[i][j]);
			}
			fprintf(file1, "\n");
			printf("\n");
		}
		printf("\nВсе ребра графа:\n");
		fprintf(file1, "\nВсе ребра графа:\n");
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (A[i][j] == 1) {
					printf("(%d-%d) ", i, j);
					fprintf(file1, "(%d-%d) ", i, j);
				}
			}
		}
		fclose(file1);
		edmonds(A, n);
		for (int i = 0; i < n; i++)
			free(A[i]);
		free(A);
		return 0;
	}
	default: {
		system("CLS");
		printf("\033[31m""Ошибка: некорректный выбор.\n""\033[m");
		return graph();
	}
	}
}
int find_path(int root, int* match, int n, int** A, int* p, int* used) {
	int v, to, curb;
	for (int i = 0; i < n; i++)
		p[i] = -1;
	used[root] = 1;
	queue <int> q;
	q.push(root);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if ((A[v][i] == 1) && (used[i] != 1)) {
				to = i;
				if (match[v] == to)  continue;

				else if (p[to] == -1) {
					p[to] = v;
					if (match[to] == -1)
						return to;
					to = match[to];
					used[to] = 1;
					q.push(to);
				}
			}
		}
	}

	return -1;
}


int edmonds(int** A, int n) {
	// Запись результатов в файл
	FILE* file = fopen("результаты.txt", "a");
	if (file == NULL) {
		printf("Ошибка при открытии файла.\n");
		return 1;
	}
	int** vis = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		vis[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = -1;
		}
	}
	int* p = (int*)malloc(sizeof(int) * n);
	int* match = (int*)malloc(sizeof(int) * n);
	int* used = (int*)malloc(sizeof(int) * n);
	fprintf(file, "\n");
	int found = 0; // Флаг, указывающий, найдены ли паросочетания
	for (int i = 0; i < n; i++)
		match[i] = -1;
	for (int i = 0; i < n; i++)
		used[i] = 0;
	for (int i = 0; i < n; ++i) {
		if (match[i] == -1) {
			int v = find_path(i, match, n, A, p, used);
			while (v != -1) {
				int pv = p[v], ppv = match[pv];
				match[v] = pv, match[pv] = v;
				v = ppv;
				found = 1; // Паросочетание найдено
			}
		}
	}
	if (!found) {
		printf("Максимальное паросочетание не найдено.\n");
		fprintf(file, "Максимальное паросочетание не найдено.\n");
	}
	else {
		printf("\nМаксимальное паросочетание:\n");
		fprintf(file, "Максимальное паросочетание:\n");
		fprintf(file, "[ ");
		printf("[ ");
		for (int i = 0; i < n; i++) {
			if (match[i] != -1) {
				if (i < match[i]) {
					printf("%d-%d ", i, match[i]);
					fprintf(file, "%d-%d ", i, match[i]);

				}
			}
		}
		printf("]\n");
		fprintf(file, "]\n");
	}

	free(match);
	free(p);
	free(used);
	for (int i = 0; i < n; i++)
		free(vis[i]);
	free(vis);
	fclose(file);
	fprintf(file, "\n");
	printf("\033[32m""Результаты записаны в файл""\033[32m""'результаты.txt'\n""\033[m");
	return 0;
}
void printLast200Lines() {
	system("CLS");
	printf("=================================\n");
	printf("=""\033[93m""Содержимое файла результаты.txt""\033[m""=\n");
	printf("=================================\n");
	printf("...\n");
	FILE* file = fopen("результаты.txt", "r");
	if (file == NULL) {
		printf("Ошибка при открытии файла.\n");
		return;
	}

	char lines[100][MAX_LINE_LENGTH];
	int lineCount = 0;

	while (fgets(lines[lineCount], MAX_LINE_LENGTH, file)) {
		lineCount++;
		if (lineCount >= 100) {
			lineCount = 0;
		}
	}

	for (int i = lineCount; i < 100; i++) {
		printf("%s", lines[i]);
	}
	for (int i = 0; i < lineCount; i++) {
		printf("%s", lines[i]);
	}
	printf("...\n");
	printf("Выведены последние 100 строк, записанных в файл ""\033[93m""результаты.txt""\033[m""\n");
	fclose(file);

}

int menu() {
	int c = 0;
	int err = 0;
	float er;
	while (1) {
		printf("\n");
		printf("==================================\n");
		printf("=""\033[93m""Поиск максимальных паросочетаний""\033[m""=\n");
		printf("==================================\n");
		printf("|				 |\n");
		printf("| ""\033[32m""  1. Запуск алгоритма""\033[m""		 |\n");
		printf("| ""\033[33m""  2. Последние записи в файл""\033[m""	 |\n");
		printf("| ""\033[31m""  3. Выход""\033[m""			 |\n");
		printf("|				 |\n");
		printf("==================================\n");
		printf("Ваш выбор: ");
		err = scanf("%f", &er);
		if (err == 0) {
			system("CLS");
			printf("\033[31m""Ошибка: некорректный ввод.\n""\033[m");
			while (getchar() != '\n'); // Очистка буфера ввода
			return menu(); 
		}
		c = (int)er;
		switch (c) {
		case 1:
			system("CLS");
			graph();
			break;
		case 2:
			printLast200Lines();
			menu();
			break;
		case 3:
			zastavka2();
			exit(0);
			break;
		default:
			system("CLS");
			printf("\033[31m""Неверный выбор.\n""\033[m");
		}
	}
	return 0;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	zastavka();
	menu();
	return 0;
}