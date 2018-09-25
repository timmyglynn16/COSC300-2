#include <stdio.h>
#include <iostream>
using namespace std;




void selection_sort(int *low, int *high) {

    // WRONG!!!! figure it out another day 
    // do i need all these vars? end? size?
    // for loops arent iterating correctly...
    /*
    int temp;
    int *end = NULL;

    int size, *pointer;

    if(size < 2 || pointer == NULL)
        return;

    end = pointer + size - 1;

    for(low = pointer; low < end; low++)
    {
        for(high = low + 1; high <= end; high++)
        {
            if(*high < *low)
            {
                temp = *low;
                *low = *high;
                *high = temp;
            }
        }
    } */

    // good sort
    // needed two pointers for each high/low
    // makes a lot of sense!!! 
    int temp;
    for(int *ptr1 = low; ptr1 < high; ptr1++){
        for(int *ptr2 = low; ptr2 < high; ptr2++){
           if(*high < *low){
               temp = *low;
               *low = *high;
               *high = temp;
           } 
        }
    }

}

int main(){

        // declare the size of the array
    int n, i;
    int key = 0;
    cout << "\nEnter the size of the array: ";
    cin >> n;
    cout << endl;
    
    // enter integers into the array
    int arr[n];
    for(i = 0; i < n; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    selection_sort(&arr[0], &arr[n-1]);

    cout << "\nSorted array: \n";
    for (int i = 0; i<n; i++)
        cout << " " <<  *(arr + i);
        cout << endl;
}



