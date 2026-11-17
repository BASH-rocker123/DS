
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}


struct Node* concat(struct Node* list1, struct Node* list2) {
    if (!list1) return list2;
    struct Node* temp = list1;
    while (temp->next) temp = temp->next;
    temp->next = list2;
    return list1;
}


void sort(struct Node* head) {
    for (struct Node* i = head; i != NULL; i = i->next) {
        for (struct Node* j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


void print(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* list1 = newNode(30);
    list1->next = newNode(10);


    struct Node* list2 = newNode(40);
    list2->next = newNode(20);

    struct Node* result = concat(list1, list2);
    printf("Concatenated: ");
    print(result);

    sort(result);
    printf("Sorted:       ");
    print(result);

    result = reverse(result);
    printf("Reversed:     ");
    print(result);

    return 0;
}
