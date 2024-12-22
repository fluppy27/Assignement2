#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



typedef struct Node{
    int PID;
    char* name;
    struct Node* prev;
    struct Node* next;

} Node;

Node* createNode(char* str, int pid){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = (char* )malloc(strlen(str)+1);
    newNode->PID = pid;
    newNode->next  = NULL;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char* name, int pid){
    Node* newNode = createNode(name, pid);
    if(*head == NULL){
        *head = newNode;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head=newNode;


}

void removeNode(Node** head, char* name, int pid){
    Node* temp = *head;

    if(name == NULL){
        while(temp->PID != pid){
            temp = temp->next;
        }
        Node* NPrev = temp->prev;
        Node* NNext = temp->next;

        NPrev->next = NNext;
        NNext->prev = NPrev;
    }
    else if(name != NULL){
        while(temp->name != name){
            temp = temp->next;
        }
        Node* NPrev = temp->prev;
        Node* NNext = temp->next;

        NPrev->next = NNext;
        NNext->prev = NPrev;
    }
}

void terminate(Node** head, char* name, int pid){
    removeNode(head, name, pid);
}

void printList(Node** head){
    Node* temp = head;
    while(temp != NULL){
        printf("PID = %u, Process Name is %s \n",temp->PID, temp->name);
        temp = temp->next;
    }
    return 0;
}
Node* findNode(Node** head, int PID, char* name){
    Node* temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
        if(temp->name == temp->name){
            return temp;
        }
        else if(temp->PID == PID){
            return temp;
        }
    }
    printf("PID and/or Name not found");
    return -1;
   
}
int main(){
    Node* list = NULL;
    addNode(list, "pi", 1);
    addNode(list, "p2", 2);
    addNode(list, "p3", 3);

    printList(list);

    Node* temp = findNode(list, 2, NULL);
    printf("here is proces with PID %u", temp->PID);
    removeNode(list, NULL, 3);

    printList(list);

    return 1;
}