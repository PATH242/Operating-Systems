
#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    node* next;
};
node* head;

void insertNode( node* newNode){
    struct node* i = head;
    while(i->next != NULL){
        i= i->next;
    }
    i->next= newNode;
    return;
}
void deleteNode(int x){
    struct node* i = head;
    while(i->next != NULL){
        if(i->value == x)
            break; ///x is at the start of the linked list
        if((i->next)->value == x)
            break;
        i= i->next;
    }
    if(head==i && i->value == x){
        head= i->next;
    }
    else{
        i->next= (i->next)->next;
    }
    return;
}
void createLinkedList(){
    struct node* startingNode;

    head = startingNode;
    struct node* element2;
    struct node* element3;
    startingNode= (struct node *) malloc(sizeof(struct node));
    element2= (struct node *) malloc(sizeof(struct node));
    element3= (struct node *) malloc(sizeof(struct node));
    startingNode->next= NULL;
    element2->next= NULL;
    element3->next= NULL;

    startingNode->value= 34;
    element2->value=35;
    element3->value= 36;
    insertNode(element2);
    insertNode(element3);
    deleteNode(36);
    return;
}
void print_list(){
    struct node* i = head;
    while(i->next != NULL){
        printf("%d ", i->value);
        i= i->next;
    }
    printf("%d\n", i->value);
}
int main(){
    createLinkedList();
    print_list();

    return 0;
}
