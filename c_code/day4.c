#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/** 
 * not necessary but I declared it anyway
 * sue me.
 * */
#define SUCC 0
#define FAIL -1

/* day4 learning c */

typedef struct Node
{
    /* Structure for a doubly linked list of integers */
    int value;
    struct Node *prev;
    struct Node *next;
} node;

void addnode(int value, node *head);
void printList(node *n);
int searchList(int key, node *n);
void deletenode(node *n);

node * getnode(int key, node *head);

int main(void){

    /* initialise new node*/
    node *head = NULL;

    /* do the memory thing? malloc palloc millok pillock */
    head = (node *)malloc(sizeof(node));
    head->value = 1;
    head->next = NULL;
    head->prev = NULL;

    addnode(5,head);
    addnode(10,head);

    addnode(15,head);
    addnode(20,head);
    printList(head);
    
    node *fetch = getnode(15,head);
    deletenode(fetch);
    printList(head);
    
    return SUCC;
}

void printList(node *n){
    /**
     * display contents of list
    */
    while (n !=NULL){
        printf("%d ",n->value);
        n=n->next;
        }
}

void addnode(int val, node *head) {
    /**
     * inserts a node with given value into the end of list
    */

    node * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node *) malloc(sizeof(node));
    current->next->value = val;
    current->next->next = NULL;
    current->next->prev = current;
}

void deletenode(node * n){
    /**
     * deletes a node from a list
    */


    // if node is null
    if(n == NULL) return;

    // if prev node exists ->remap
    if(n->prev !=NULL){
        n->prev->next = n->next;
    }

    // if next node exists -> remap
    if(n->next !=NULL)
        n->next->prev = n->prev;
    
    // free memory
    free(n);
    return;

}

node* getnode(int key, node *head){
    /** 
     * get a node in a chain(list) of nodes:
     * @param key, they key to get the node
     * @param head, pointer to the head of the list
     * @return node*, pointer to the node or NULL if no entry exists */
    
    node *iter_node = head;

    while(iter_node!=NULL){
           
        if(iter_node->value == key){
            return iter_node;
        }
        iter_node=iter_node->next;
    }
    return NULL;
}