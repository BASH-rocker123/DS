#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int ele)
{
    if (top == SIZE - 1)
    {
        printf("Overflow!!!\n");
    }
    else
    {
        stack[++top] = ele;
        printf("%d pushed into stack.\n", ele);
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Underflow!!\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("No elements present!!\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int ele, choice;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &ele);
                push(ele);
                break;

            case 2:
                ele = pop();

                if (ele != -1)
                    printf("Popped element: %d\n", ele);

                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}
