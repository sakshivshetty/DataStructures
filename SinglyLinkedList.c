// SINGLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

typedef struct List
{
    Node* head;
    int number_of_nodes;
} List;

/* initializes a linked list */
List* list_initialize();

/* Inserts a new node with data at the beginning */
void list_insert_beginning(List* list, int data);

/* Removes the last node of the linked list */
void list_delete_rear(List* list);

/* Prints the contents of a list */
void list_print(List* list);

/* Deallocates resources held by the list */
void list_destroy(List* list);

int main() {
    int choice;
    List *list = list_initialize();
    do {
        scanf("%d", &choice);
        switch(choice) {
            int element;
            case 1:
                /* Insert an element at the beginning of the list */
                    scanf("%d", &element);
                    list_insert_beginning(list, element);
                    break;
            case 2:
                /* Remove rear elements */
                    list_delete_rear(list);
                    break;
            case 3:
                /* Print list contents */
                list_print(list);
                break;
            default:
                list_destroy(list);
                break;
        }
    } while(choice >= 1 && choice < 4);
    
    return 0;
}


List* list_initialize()
{
    List *list=(List*)malloc(sizeof(List));
        list->head=NULL;
        list->number_of_nodes=0;
        return list;
}

void list_insert_beginning(List* list, int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->link = list->head;
    temp->data = data;
    list->head = temp;
}

void list_delete_rear(List* list)
{
    if(list->head == NULL)
        return;
    else
    {
        Node *temp = list->head,*prev;
        if(temp->link==NULL)
        {
            list->head=NULL;
        }
        else
        {while(temp->link!=NULL)
        {
            prev=temp;
            temp=temp->link;
        }
        prev->link=NULL;
            
        }
        free(temp);
    }
}

void list_print(List* list)
{
    if(list->head == NULL)
    printf("EMPTY");
    else
    {
        Node *temp = list->head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->link;
        }
    }
    printf("\n");
}

void list_destroy(List* list)
{
    if(list->head==NULL);
    else
    {
        Node *temp = list->head, *ptr;
        while(temp!=NULL)
        {
            ptr=temp;
            temp=temp->link;
            free(ptr);
        }
    }
}


#include<stdio.h>
#include<stdlib.h>

//Node of the linked list
typedef struct Node {
int data;
struct Node *link;
} Node;

//Handle of the list. Its head points to the first node in the list.
typedef struct List {
Node *head;
int number_of_nodes;
} List;

/* initializes a linked list */
List* list_initialize();

/* Inserts data at specified position 0 <= position <= length(list). */
void list_insert_at(List* list, int data, int position);

/*Inserts data at the end of the List*/
void insert_at_end(List *list, int data);

/* Removes the First node of the linked list. No operation if the list was empty */
void list_delete_front(List* list);

/* Prints the entire List as "X1, X2, ..., Xn" where X1 to Xn are the elements of the list,
if list is empty prints "EMPTY" */
void list_print(List* list);

/* Returns the position of the key if present else returns -1*/
int find_key(List* list, int data);

/* deallocates resources held by the list */
void list_destroy(List* list);

int main()
{
int choice;
List* list = list_initialize();
do {
scanf("%d", &choice);
switch(choice) {
int element, index;
case 1:
/*Insert element at the End of the list*/
scanf("%d", &element);
insert_at_end(list, element);
break;

case 2:
/* Print list contents */
list_print(list);
break;

case 3:
/* Remove front element */
list_delete_front(list);
break;

case 4:
/* Insert elements at specified positions */
scanf("%d%d", &element, &index);
list_insert_at(list, element, index);
break;

case 5:
/*Find position of an element*/
scanf("%d", &element);
index = find_key(list, element);
if (index != -1) printf("%d\n", index);
break;

default:
break;
}
} while(choice != 0);
list_destroy(list);
return 0;
}


List* list_initialize()
{
List* list = (List*) malloc(sizeof(List));
list->head = NULL;
list->number_of_nodes = 0;
return list;
}

void insert_at_end(List *list, int data)
{
Node *n=(Node *)malloc(sizeof(Node));
n->data=data;
n->link=NULL;
    Node *temp=list->head;
    if(list->head==NULL){
        list->head=n;
    }
    else{
while(temp->link!=NULL){
   temp=temp->link;
}
temp->link=n;
    }
    list->number_of_nodes++;
}


void list_print(List* list)
{
Node *temp=list->head;
if(list->head==NULL){
   printf("EMPTY\n");
   return;
}
while(temp!=NULL){
   printf("%d ",temp->data);
   temp=temp->link;
}
printf("\n");
}


void list_delete_front(List* list)
{
if(list->head==NULL){
           Return;
}
Node *temp=list->head;
list->head=list->head->link;
free(temp);
list->number_of_nodes--;
}


void list_insert_at (List *list, int data, int position)
{
if(position<0 || position>list->number_of_nodes){
   return;
}
Node *p=list->head;
Node *q=NULL;
Node *temp=(Node *)malloc(sizeof(Node));
temp->data=data;
int i=0;
while(p!=NULL && i!=position){
   q=p;
   p=p->link;
   i+=1;
}
if(q==NULL){
   temp->link=list->head;
   list->head=temp;
   
}
else{
   temp->link=p;
   q->link=temp;
}
list->number_of_nodes++;
}

int find_key(List* list, int key)
{
  Node *temp=list->head;
  int i=0;
  while(temp!=NULL){
     if(key==temp->data){
         return i;
     }
     i+=1;
     temp=temp->link;
  }
  return -1;
}

void list_destroy (List *list)
{
Node *temp=list->head;
Node *q;
while(temp!=NULL){
   q=temp;
   temp=temp->link;
   free(q);
}
}
