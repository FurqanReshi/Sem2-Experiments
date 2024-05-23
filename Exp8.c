#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node *prv;
  int data;
  struct Node *next;
};

struct Node *head=NULL, *tail=NULL;

struct Node* createNode(){
  struct Node *t=(struct Node*)malloc(sizeof(struct Node));
  printf("Enter Data: ");
  scanf("%d",&t->data);
  t->prv=NULL;
  t->next=NULL;
  return t;
}

void createDoublyLinkedList(){
  int n,i;
  printf("Enter Number of Nodes: ");
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    struct Node *newNode=createNode();
    if(head==NULL){
      head=newNode;
      tail=newNode;
    }
    else{
        tail->next=newNode;
        newNode->prv=tail;
        tail=newNode;
    }
  }
}
void displaylistFromBeg(){
    if(head==NULL)
        printf("List is Empty");
    else{
        struct Node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void displaylistFromEnd(){
    if(tail==NULL)
        printf("List is Empty");
    else{
        struct Node *temp=tail;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->prv;
        }
    }
}
void insertNodeAtBeg(){
    struct Node *newNode=createNode();
    if(head==NULL){
        head=tail=newNode;
    }
    else{
        newNode->next=head;
        head->prv=newNode;
        head=newNode;
    }
}
void insertNodeAtEnd(){
    struct Node *newNode=createNode();
    if(tail==NULL){
        head=tail=newNode;
    }
    else{
        newNode->prv=tail;
        tail->next=newNode;
        tail=newNode;
    }
}
void insertNodeAtAnyPos(){
    if(head==NULL)
        printf("list is empty\n");
    else{
        int pos;
        printf("Enter Position: ");
        scanf("%d",&pos);
        if(pos==1){
            struct Node *newNode=createNode();
            newNode->next=head;
            head->prv=newNode;
            head=newNode;
        }
        else{
            int cnt=1;
            struct Node *temp=head;
            while(temp!=NULL){
                if(cnt==pos)
                    break;
                cnt++;
                temp=temp->next;
            }
            if(temp->next==NULL)
                printf("Invalid Position\n");
            else{
                struct Node *newNode=createNode();
                temp->prv->next=newNode;
                newNode->prv=temp->prv;
                newNode->next=temp;
                temp->prv=newNode;
            }
        }
    }
}
void deleteNodeAtAnyPos(){
    if(head==NULL)
        printf("List is Empty");
    else{
        int pos;
        printf("Enter Position: ");
        scanf("%d",&pos);
        if(pos==1){
            head=head->next;
        }
        else{
            int cnt=1;
            struct Node *temp=head;
            while(temp!=NULL){
                if(cnt==pos)
                    break;
                cnt++;
                temp=temp->next;
            }
            if(temp==NULL)
                printf("Position is Out of Range");
            else{
                temp->prv->next=temp->next;
                if(temp->next!=NULL)
                    temp->next->prv=temp->prv;
            }
        }
    }
}
void searchElement(){
    if(head==NULL)
        printf("List is Empty");
    else{
        int key, pos = 1, found = 0;
        printf("Enter the element to search: ");
        scanf("%d", &key);
        struct Node *temp = head;
        while(temp != NULL){
            if(temp->data == key){
                found = 1;
                break;
            }
            pos++;
            temp = temp->next;
        }
        if(found)
            printf("Element %d found at position %d\n", key, pos);
        else
            printf("Element not found in the list\n");
    }
}
int main(){
    createDoublyLinkedList();
    while(1){
        system("cls");
        printf("1. Insert Node In Begining\n");
        printf("2. Insert Node In End\n");
        printf("3. Insert Node At Any Position\n");
        printf("4. Delete Node From Given Position\n");
        printf("5. Search Node In List\n");
        printf("6. Display List From Beginning\n");
        printf("7. Display List From Ending\n");
        printf("8. Exit\n");
        int choice;
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insertNodeAtBeg();
                break;
            case 2:
                insertNodeAtEnd();
                break;
            case 3:
                insertNodeAtAnyPos();
                break;
            case 4:
                deleteNodeAtAnyPos();
                break;
            case 5:
                searchElement();
                break;
            case 6:
                displaylistFromBeg();
                break;
            case 7:
                displaylistFromEnd();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
        printf("\n\n");
        system("pause");
    }
    return 0;
}