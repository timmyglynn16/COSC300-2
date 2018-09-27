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

    if(size < 2 || pointer == NULL) // not necessary
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

    // dont overthink, iterate first pointer
    for(int *ptr1 = low; ptr1 < high; ptr1++){

        // iterate second pointer
        for(int *ptr2 = low; ptr2 < high; ptr2++){

            //selection sort algorithm
            if(*high < *low){
                temp = *low;
                *low = *high;
                *high = temp;
            } 
        }
    }

}

int *binsearch(int *low, int *high, int key) {
    
    // TOO MUCH ARRAY INDEXING - WRONG!!!!
    // this worked but it wasnt really using pointers the way i wanted it to
    // come back to it
    
    /*
    int i = 0;
    int j = 0;
     
    while(i <= key) {
        j = (i + key) / 2;
        if(high[j] < low[i])
            i = j+1;
        else
            if(high[j] > low[i])
                key = j - 1;
            else
                return j;
        }
        return -1;
    }*/


    // ONLINE HELP: needed to make these 'references' that represent the *low, *high pointers
    // this way i can do arithmetic when calculating the *mid
    int *ptr1 = low;
    int *ptr2 = high;
    int *mid = (ptr1 + (ptr2 - ptr1) / 2);// calculate the mid value and point to the address of mid
    
    // loop until the program finds the key
    while (ptr1 <= ptr2 && key != *mid)
    {
        // basic binsearch algorithm
        // instead of using *low and *high, use the references from the swap algorithm
        if (key>*mid)
            ptr1 = mid + 1; // lowRef represents *low
        else if (key<*mid)
            ptr2 = mid - 1; // highRef represents *high
        mid = (ptr1 + (ptr2 - ptr1) / 2);
    }
        if (key == *mid)
            return mid;
        else
            // as asked! 
            return high + 1;



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



