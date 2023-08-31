#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
}*front = NULL, *rear = NULL;
int isEmpty()
{
if(front == NULL)
{
return 1;
}
else
{ 
return 0;
}
}
void insert(int item)
{
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
if(temp == NULL)
{
printf("Queue is not Allocated\n");
return;
}
temp->data = item;
temp->link = NULL;
if(front == NULL)
{
front = temp;
}
else
{
rear->link = temp;
}
rear = temp;
}
int delete_node()
{
struct node *temp;
int item;
if(isEmpty())
{
printf("WAITING LIST IS EMPTY\n");
exit(1);
}
temp = front;
item = temp->data;
front = front->link;
free(temp);
return item;
}
int peek()
{
if(isEmpty())
{
printf("WAITING LIST IS EMPTY\n");
exit(1);
}
return front->data;
}
void display()
{
struct node *ptr;
if(isEmpty())
{
printf(" LIST IS EMPTY\n");
return;
}
printf("GROUPS :\n");
for(ptr = front; ptr != NULL; ptr = ptr->link)
{
printf("%d ", ptr->data);
}
printf("\n\n");
}
int main()
{
int option, item;
while(1)
{     
printf("==============================================================\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("--------------------RESTAURENT WAITING LIST------------------------\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("===============================================================\n");
printf("\n");
printf("1. INSERT A GROUP IN THE LIST\n");
printf("2. DELETE A GROUP IN THE LIST\n");
printf("3. DISPLAY THE GROUP AT THE FRONT\n");
printf("4. DISPLAY ALL THE GROUPS\n");
printf("5. EXIT\n"); 
printf("ENTER YOUR OPTION:\t");
scanf("%d", &option);
switch(option)
{
case 1:
printf("ENTER THE GROUP CODE TO ADD:\t");
scanf("%d", &item);
insert(item);
break;
case 2:
printf("THE DELETED GROUP FROM THE LIST:\t%d\n", delete_node());
break;
case 3:
printf("GROUP AT THE FRONT:\t%d\n", peek());
break;
case 4:
display();
break;
case 5:
exit(1);
default:
printf("Wrong option\n");
}
}
return 0;
}

