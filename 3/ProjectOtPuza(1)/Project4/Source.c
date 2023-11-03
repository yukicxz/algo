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
        printf("������� �����.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void changePriority(Node** head, char* data, int newPriority) {
    if (*head == NULL) {
        printf("������� �����.\n");
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
    printf("������� �� ������.\n");
}

void printQueue(Node* head) {
    if (head == NULL) {
        printf("������� �����.\n");
        return;
    }
    printf("�������� ������������ �������:\n");
    while (head != NULL) {
        printf("���������: %d, ������: %s\n", head->priority, head->data);
        head = head->next;
    }
}

void deleteByPriority(Node** head, int priority) {
    if (*head == NULL) {
        printf("������� �����.\n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->priority == priority) {
        *head = temp->next;
        free(temp);
        printf("������� ������� ������.\n");
        return;
    }
    while (temp != NULL && temp->priority != priority) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("������� � ��������� ����������� �� ������.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("������� ������� ������.\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* head = NULL;
    int choice;
    while (1) {
        printf("\n�������� ��������:\n");
        printf("1. �������� ������� � �����������\n");
        printf("2. �������� ��������� ��������\n");
        printf("3. ������� ������� �� ��������\n");
        printf("4. ������� ������� �� ����������\n");
        printf("5. ������� �������� �������\n");
        printf("6. �����\n");
        scanf("%d", &choice);
        char data[100];
        int priority;
        switch (choice) {
        case 1:
            printf("������� ������ ��������: ");
            scanf("%s", data);
            printf("������� ��������� ��������: ");
            scanf("%d", &priority);
            enqueue(&head, priority, data);
            printf("������� ������� ��������.\n");
            break;
        case 2:
            printf("������� ������ �������� ��� ��������� ����������: ");
            scanf("%s", data);
            printf("������� ����� ��������� ��������: ");
            scanf("%d", &priority);
            changePriority(&head, data, priority);
            break;
        case 3:
            printf("������� ������ �������� ��� ��������: ");
            scanf("%s", data);
            dequeue(&head);
            printf("������� ������� ������.\n");
            break;
        case 4:
            printf("������� ��������� �������� ��� ��������: ");
            scanf("%d", &priority);
            deleteByPriority(&head, priority);
            break;
        case 5:
            printQueue(head);
            break;
        case 6:
            exit(0);
        default:
            printf("�������� �����.\n");
        }
    }
    return 0;
}