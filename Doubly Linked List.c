#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    struct node *next;
    int data;
};
typedef struct node Node;
Node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void delete_beginning();
void delete_end();
void delete_specified();
void search();
void traverse();
void main()
{
    int choice = 0;
    printf("\n---------------------------------------------\n");
    printf("**************Doubly Linked List*****************\n");
    while(choice!=9)
    {
        printf("\nWhat would you like to perform?\n\n1.Insert at beginning\n2.Insert at end\n3.Insert after a specified node\n4.Delete at beginning\n5.Delete at the end\n6.Delete after a specified node\n7.Display\n8.Search\n9.Exit\nEnter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertion_beginning();
            break;
        case 2:
            insertion_last();
            break;
        case 3:
            insertion_specified();
            break;
        case 4:
            delete_beginning();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_specified();
            break;
        case 7:
            traverse();
            break;
        case 8:
            search();
            break;
        case 9:
            break;
        default:
            printf("\nEnter Valid Choice\n");
        }
    }
}
void insertion_beginning()
{
    Node *ptr;
    int item;
    ptr = (Node *)malloc(sizeof(Node));
    if(ptr==NULL)
        printf("\nOVERFLOW\n");
    else
    {
        printf("\nEnter a value : ");
        scanf("%d",&item);
        if(head==NULL)
        {
            ptr->next=NULL;
            ptr->prev=NULL;
            ptr->data=item;
            head=ptr;
        }
        else
        {
            ptr->data=item;
            ptr->prev=NULL;
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
        }
        printf("\nNode inserted\n");
    }
}
void insertion_last()
{
   struct node *ptr,*temp;
   int item;
   ptr = (struct node *) malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\nOVERFLOW");
   }
   else
   {
       printf("\nEnter value : ");
       scanf("%d",&item);
        ptr->data=item;
       if(head == NULL)
       {
           ptr->next = NULL;
           ptr->prev = NULL;
           head = ptr;
       }
       else
       {
          temp = head;
          while(temp->next!=NULL)
          {
              temp = temp->next;
          }
          temp->next = ptr;
          ptr ->prev=temp;
          ptr->next = NULL;
          }

       }
     printf("\nNode inserted\n");
    }
void insertion_specified()
{
    Node *ptr,*temp;
    int loc,i,item;
    ptr=(Node *)malloc(sizeof(Node));
    if(ptr==NULL)
        printf("\nOVERFLOW\n");
    else
    {
        temp=head;
        printf("\nEnter the location after which you want to insert : ");
        scanf("%d",&loc);
        for(i=0;i<loc;i++)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("\nLess numbers than the entered location\n");
                return;
            }
        }
        printf("\nEnter a value : ");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=temp->next;
        ptr->prev=temp;
        temp->next=ptr;
        temp->next->prev=ptr;
        printf("\nNode inserted\n");
    }
}
void delete_beginning()
{
    Node *ptr;
    if(head==NULL)
        printf("\nUNDERFLOW\n");
    else if(head->next == NULL)
    {
        head=NULL;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        ptr=head;
        head=head->next;
        head->prev=NULL;
        free(ptr);
        printf("\nNode Deleted\n");
    }
}
void delete_end()
{
    Node *ptr;
    if(head==NULL)
        printf("\nUNDERFLOW\n");
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        ptr=head;
        if(ptr->next!=NULL)
         {
           ptr=ptr->next;
         }
        ptr->prev->next=NULL;
        free(ptr);
        printf("\nNode Deleted\n");
    }
}
void delete_specified()
{
    Node *ptr, *temp;
    int val;
    printf("\n Enter the data after which the node is to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    while(ptr -> data != val)
    ptr = ptr -> next;
    if(ptr -> next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if(ptr -> next -> next == NULL)
    {
        ptr ->next = NULL;
    }
    else
    {
        temp = ptr -> next;
        ptr -> next = temp -> next;
        temp -> next -> prev = ptr;
        free(temp);
        printf("\nNode deleted\n");
    }
}
void traverse()
{
    Node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
}
void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search : ");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("\nitem found at location %d ",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            printf("\nItem not found\n");
        }
    }
}
