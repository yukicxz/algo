#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
typedef struct Node {
    int priority;
    char data[100];
    struct Node* next;
} Node;

Node* createNode(int priority, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->priority = priority;
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** head, int priority, char* data) {
    Node* newNode = createNode(priority, data);
    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dequeue(Node** head) {
    if (*head == NULL) {
        printf("Очередь пуста.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void changePriority(Node** head, char* data, int newPriority) {
    if (*head == NULL) {
        printf("Очередь пуста.\n");
        return;
    }
    Node* temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->data, data) == 0) {
            temp->priority = newPriority;
            return;
        }
        temp = temp->next;
    }
    printf("Элемент не найден.\n");
}

void printQueue(Node* head) {
    if (head == NULL) {
        printf("Очередь пуста.\n");
        return;
    }
    printf("Элементы приоритетной очереди:\n");
    while (head != NULL) {
        printf("Приоритет: %d, Данные: %s\n", head->priority, head->data);
        head = head->next;
    }
}

void deleteByPriority(Node** head, int priority) {
    if (*head == NULL) {
        printf("Очередь пуста.\n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->priority == priority) {
        *head = temp->next;
        free(temp);
        printf("Элемент успешно удален.\n");
        return;
    }
    while (temp != NULL && temp->priority != priority) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Элемент с указанным приоритетом не найден.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Элемент успешно удален.\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* head = NULL;
    int choice;
    while (1) {
        printf("\nВыберите операцию:\n");
        printf("1. Добавить элемент с приоритетом\n");
        printf("2. Изменить приоритет элемента\n");
        printf("3. Удалить элемент по названию\n");
        printf("4. Удалить элемент по приоритету\n");
        printf("5. Вывести элементы очереди\n");
        printf("6. Выход\n");
        scanf("%d", &choice);
        char data[100];
        int priority;
        switch (choice) {
        case 1:
            printf("Введите данные элемента: ");
            scanf("%s", data);
            printf("Введите приоритет элемента: ");
            scanf("%d", &priority);
            enqueue(&head, priority, data);
            printf("Элемент успешно добавлен.\n");
            break;
        case 2:
            printf("Введите данные элемента для изменения приоритета: ");
            scanf("%s", data);
            printf("Введите новый приоритет элемента: ");
            scanf("%d", &priority);
            changePriority(&head, data, priority);
            break;
        case 3:
            printf("Введите данные элемента для удаления: ");
            scanf("%s", data);
            dequeue(&head);
            printf("Элемент успешно удален.\n");
            break;
        case 4:
            printf("Введите приоритет элемента для удаления: ");
            scanf("%d", &priority);
            deleteByPriority(&head, priority);
            break;
        case 5:
            printQueue(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Неверный выбор.\n");
        }
    }
    return 0;
}