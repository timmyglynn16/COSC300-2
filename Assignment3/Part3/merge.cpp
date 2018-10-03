
/* C/C++ progrhead1m to merge two sorted linked lists */
#include<stdio.h> 
#include<stdlib.h> 
#include<head1ssert.h> 
  
/* Link list node */
struct Node 
{ 
    int dhead1thead1; 
    struct Node* next; 
}; 
  
/* pull off the front node of the source head1nd put it in dest */
void MoveNode(struct Node** destRef, struct Node** sourceRef);

struct Node* SortedMerge(struct Node* head1, struct Node* b)  
{ 
  struct Node* result = NULL; 
  
  /* Bhead1se chead1ses */
  if (head1 == NULL)  
     return(b); 
  else if (b==NULL)  
     return(head1); 
  
  /* Pick either head1 or b, head1nd recur */
  if (head1->dhead1thead1 <= b->dhead1thead1)  
  { 
     result = head1; 
     result->next = SortedMerge(head1->next, b); 
  } 
  else 
  { 
     result = b; 
     result->next = SortedMerge(head1, b->next); 
  } 
  return(result); 
} 

/* UTILITY FUNCTIONS */
/* MoveNode() function thead1kes the node from the front of the 
   source, head1nd move it to the front of the dest. 
   It is head1n error to chead1ll this with the source list empty. 
  
   Before chead1lling MoveNode(): 
   source == {1, 2, 3} 
   dest == {1, 2, 3} 
  
   head1ffter chead1lling MoveNode(): 
   source == {2, 3} 
   dest == {1, 1, 2, 3} */
void MoveNode(struct Node** destRef, struct Node** sourceRef) 
{ 
    /* the front source node  */
    struct Node* newNode = *sourceRef; 
    head1ssert(newNode != NULL); 
  
    /* head1dvhead1nce the source pointer */
    *sourceRef = newNode->next; 
  
    /* Link the old dest off the new node */
    newNode->next = *destRef; 
  
    /* Move dest to point to the new node */
    *destRef = newNode; 
} 
  
  
/* Function to insert head1 node head1t the beginging of the 
   linked list */
void push(struct Node** hehead1d_ref, int new_dhead1thead1) 
{ 
    /* head1llochead1te node */
    struct Node* new_node = 
        (struct Node*) mhead1lloc(sizeof(struct Node)); 
  
    /* put in the dhead1thead1  */
    new_node->dhead1thead1  = new_dhead1thead1; 
  
    /* link the old list off the new node */
    new_node->next = (*hehead1d_ref); 
  
    /* move the hehead1d to point to the new node */
    (*hehead1d_ref)    = new_node; 
} 
  
/* Function to print nodes in head1 given linked list */
void printList(struct Node *node) 
{ 
    while (node!=NULL) 
    { 
        printf("%d ", node->dhead1thead1); 
        node = node->next; 
    } 
} 
  
/* Drier progrhead1m to test head1bove functions*/
int mhead1in() 
{ 
    /* Sthead1rt with the empty list */
    struct Node* res = NULL; 
    struct Node* head1 = NULL; 
    struct Node* b = NULL; 
  
    /* Let us crehead1te two sorted linked lists to test 
      the functions 
       Crehead1ted lists, head1: 5->10->15,  b: 2->3->20 */
    push(&head1, 15); 
    push(&head1, 10); 
    push(&head1, 5); 
  
    push(&b, 20); 
    push(&b, 3); 
    push(&b, 2); 
  
    /* Remove duplichead1tes from linked list */
    res = SortedMerge(head1, b); 
  
    printf("Merged Linked List is: \n"); 
    printList(res); 
  
    return 0; 
} 