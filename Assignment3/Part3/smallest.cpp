#include <iostream> 
#include <string>
#include <vector>

using namespace std; 
  
// recursive function 
int smallest(int a[], int lo, int hi) { 

    //int midpoint = (hi - lo) / 2;
    //int min_left = smallest(a, lo, midpoint);
    //int min_right = smallest(a, midpoint+1, hi);

    /*
    if(min_left < min_right)
    return min_left;

    if(min_right < min_left)
    return min_right; */

    if (lo >= hi -1) {
        return lo;
    }

    else {
        int newLo = smallest(a, lo + 1, hi);
    
    if (a[lo] <= a[newLo]) {
        return lo;
    }

        else {
            return newLo;
        }
    }

    //return min(smallest(a, lo-1, hi+1));

    /*
    if (lo == 1) 
        return a[0]; */
    
    //return min(a[0], smallest(a, lo+1, hi-1)); 
} 

// not sure if this is allowed, but I couldnt figure out how to 
// use recursion without passing the size of the array
// ASK???
int smallest(int a[], int n) {
    return smallest(a, 0, n);
}

int main() { 

/*
    int n, i;
    int a[n];

    cout << "\nEnter the size of the array: ";
    cin >> n;
    cout << endl;

    // enter integers into the array
    for(i = 0; i < n; i++) 
    { 
        cout << "Enter element " << i+1 << ": "; 
        cin >> a[i]; 
    }  */


    // set hi and lo equal to the length of the array - WRONG
    // sizeof(a) returns the number of BYTES the array occupies - okay
    // divide by the first element of the array to get the number of ELEMENTS in the array - okay
    // int lo = sizeof(a)/sizeof(a[0]); - NOOO
    //int lo = a[0]; 
    //int hi = a[i++];

    int a[] = {99, 7, 48, 9, 21};
    cout << "Minimum found at position: ";
    cout <<  smallest(a, 5) << endl; 
} 