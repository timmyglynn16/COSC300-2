
// C program to merge two sorted linked lists 
// in-place. 
#include<bits/stdc++.h> 
using namespace std; 
  
struct Item 
{ 
    int data; 
    struct Item *next; 
}; 
  
// Function to create newItem in a linkedlist 
// HELP FROM: 
Item *newItem(int key) 
{ 
    struct Item *temp = new Item; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function to print linked list 
// HELP FROM: 
void printList(Item *Item) 
{ 
    while (Item != NULL) 
    { 
        printf("%d  ", Item->data); 
        Item = Item->next; 
    } 
} 
  
// Merges two given lists in-place recursively. 
// This function mainly compares head Items and calls mergeUtil() 
Item *merge(Item *head1, Item *head2) 
{ 
    if (!head1) 
        return head2; 
    if (!head2) 
        return head1; 
  
    // start with the linked list 
    // whose head data is the least 
    if (head1->data < head2->data) 
    { 
        head1->next = merge(head1->next, head2); 
        return head1; 
    } 
    else
    { 
        head2->next = merge(head1, head2->next); 
        return head2; 
    } 
} 
  
// Driver program 
int main() 
{ 
    // "take two linked lists, POINTED to by head1 and head2"
    Item *head1 = newItem(1); 
    head1->next = newItem(3); 
    head1->next->next = newItem(5); 
  
    Item *head2 = newItem(0); 
    head2->next = newItem(2); 
    head2->next->next = newItem(4); 
  
    // returns a POINTER to a single list 
    // which contains all of the elements of the two lists in sorted order
    Item *mergedhead = merge(head1, head2); 
  
    printList(mergedhead); 
    return 0; 
} 