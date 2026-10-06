#include <stdio.h>;
#include <stdlib.h>;

#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;

void enqueue();
void dequeue();
void display();

int main()
{
int choice;
while (1)
{
printf("Enter 1.Insertion \n");
printf("Enter 2.Deletion \n");
printf("Enter 3.Display \n");
printf("Enter 4.Exit\n");
printf("Enter your choice:");

scanf("%d",&choice);

switch (choice)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
exit(1);
default:
printf("Invalid!!");
}
}
return 0;
}

void enqueue()
{
int ele;
if (rear == MAX - 1)
printf("Queue is full!!");
else
{
if (front == -1)

front = 0;
printf("Enter the element:");
scanf("%d",&ele);

rear = rear + 1;
queue_array[rear] = ele;
}
}

void dequeue()
{
if (front == -1 || front > rear)
{
printf("Queue is empty!!");
return;
}
else
{
printf("Dequeued elemnt", queue_array[front]);
front = front + 1;
}
}

void display()
{
int i;
if (front == -1 || front > rear)
printf("Queue is empty \n");
else
{
printf("Queue is: \n");
for (i = front; i <= rear; i++)
printf("%d ", queue_array[i]);
printf("\n");
}
}
