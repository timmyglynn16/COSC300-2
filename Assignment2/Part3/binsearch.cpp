#include <stdio.h>
#include <iostream>
using namespace std;

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

int main()
{

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

    // enter the key
    cout << "\nEnter number to search: ";
    cin >> key;
    cout << endl;
    
    // call the function to search for a key in the array
    int *keyFound = binsearch(&arr[0], &arr[n-1], key);
    
    if (keyFound >= &arr[n-1])
        cout << "Key " << key << " not found. ";
    else
        cout << "Key " << key << " is in the array.";
    cout << "\n";
    return 0;

}