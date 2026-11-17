#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;


struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void create(int val) {
    struct Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


void insertLeft(int val) {
    struct Node* newNode = createNode(val);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    printf("Inserted %d at the left\n", val);
}


void deleteAtPos(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position or empty list!\n");
        return;
    }

    struct Node* temp = head;


    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d out of range!\n", pos);
        return;
    }


    if (temp == head) {
        head = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    printf("Deleted %d from position %d\n", temp->data, pos);
    free(temp);
}


void display() {
    struct Node* temp = head;
    printf("List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    create(10);
    create(20);
    create(30);
    display();


    insertLeft(5);
    display();


    deleteAtPos(3);
    display();

    return 0;
}

