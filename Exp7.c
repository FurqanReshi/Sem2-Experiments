#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data : ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    return temp;
}  
void createList(){
    int n, i;
    printf("Enter total size of list : ");
    scanf("%d",&n);
    struct Node *temp;
    for(i=1; i<=n; i++){
        struct Node *newNode = createNode();
        if(head==NULL){
            head=newNode;
        }
        else{
            temp->next = newNode;
        }
        temp = newNode;
    }
}
void insertNodeInBeg(){
    struct Node *newNode = createNode();
    newNode->next=head;
    head=newNode;
}
void insertNodeInEnd(){
    struct Node *newNode = createNode();
    if(head==NULL){
        head=newNode;
    }
    else{
        struct Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insertNodeAtAnyPos(){
    if(head==NULL){
        printf("List is empty !!!!\n");
    }
    else{
        int pos;
        printf("Enter Position : ");
        scanf("%d",&pos);
        if(pos==1){
            struct Node *newNode = createNode();
            newNode->next=head;
            head=newNode;
        }
        else{
            int cnt=1;
            struct Node *temp=head;
            while(temp->next!=NULL){
                if(cnt == pos-1){
                    break;
                }
                else{
                    cnt++;
                    temp = temp->next;
                }
            }
            if(temp->next==NULL){
                printf("Invalid Position !!!!\n");
            }
            else{
                struct Node *newNode = createNode();
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
}
void deleteNodeAtAnyPos(){
    if(head==NULL){
        printf("List is empty !!!!\n");
    }
    else{
        int pos;
        printf("Enter Position : ");
        scanf("%d",&pos);
        if(pos==1){
            head = head->next;
        }
        else{
            int cnt=1;
            struct Node *temp = head;
            while(temp->next!=NULL){
                if(cnt==pos-1){
                    break;
                }
                else{
                    cnt++;
                    temp = temp->next;
                }
            }
            if(temp->next==NULL){
                printf("Invalid Position !!!!\n");
            }
            else{
                temp->next = temp->next->next;
                printf("Deleted Sucessfully !!!\n");
            }
        }
    }
}
void searchElement(){
    if(head==NULL){
        printf("List is empty !!!\n");
    }
    else{
        int val;
        printf("Enter searching element : ");
        scanf("%d",&val);
        struct Node *temp = head;
        while(temp!=NULL){
            if(temp->data==val){
                break;
            }
            else{
                temp = temp->next;
            }
        }
        if(temp==NULL){
            printf("Not Found !!!!\n");
        }
        else{
            printf("Found !!!!\n");
        }
    }
}
void display(){
    if(head==NULL){
        printf("List is empty !!!\n");
    }
    else{
        struct Node *temp = head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
int main(){
    createList();
    while(1){
        system("cls");
        printf("1. Insert Node In Begining\n");
        printf("2. Insert Node In End\n");
        printf("3. Insert Node At Any Position\n");
        printf("4. Delete Node From Given Position\n");
        printf("5. Search Node In List\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        int choice;
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insertNodeInBeg();
            break;
            case 2:
            insertNodeInEnd();
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
            display();
            break;
            case 7:
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