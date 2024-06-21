#include<iostream>
#include<stdio.h>
#include <queue>
#include <stack>

using namespace std;

struct Request {
    int ticketNumber;
    char email[100];
    int phone;
    char chat[100];
     int priority;
    struct Request *next;
};

typedef struct Request Node;

Node *head,*newnode,*temp;

stack<Node> High;
stack<Node> Medium;
stack<Node> Low;

queue<Request> q;



void StackHigh() {
    while (!High.empty()) {
        struct Request top = High.top();
        cout << top.ticketNumber << " " << top.email << " " << top.phone << endl;
        High.pop();
    }
}




int main()
{
    
    head=NULL;
    for (int i=0 ; i<5 ; i++)
    {
    newnode=(Node*)malloc(sizeof(Node));

    newnode->ticketNumber = i;
    printf("Please enter your email:");
    gets(newnode ->email);
    printf("Enter your Phone:");
    scanf("%d",&newnode->phone);
    printf("Enter Priority (1 for highest 3 for lowest):");
    scanf("%d",&newnode->priority);


    //q.push(*newnode);

    if (newnode->priority == 1)
    {
        High .push(*newnode);
    }
    else if (newnode->priority == 2)
    {
        Medium.push(*newnode);
    }
    else
    {
        Low.push(*newnode);
    }

    newnode->next = NULL ;  
    if(head == NULL)
    {
        head=temp=newnode;
    } 
    else
    {
         temp->next=newnode;
         temp=newnode;
    }
    
    }
    temp = head;
    
    while(temp != NULL)
    {
        
        printf("%d %s %d %d",temp->ticketNumber,temp->email,temp->phone,temp->priority);
        temp=temp->next;
        
    }
}