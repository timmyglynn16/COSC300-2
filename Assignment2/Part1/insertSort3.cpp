#include <iostream>
using namespace std;


void insertSort(int* low, int* high) {
    for(int *p=low; p<=high; p++) {
        int t = *p, *q = p;
        
        while(q > low && *(q-1) > t) {
            *q = *(q-1);
            q--;
        }
        
        *q = t;
    }

}

int main(void) {
    int a[] = { 7, 8, 9, 10, 1, 6, 2, 4, 3, 5};
    int *low = a, *high = a + sizeof(a)/sizeof(a[0]) – 1;
    insertSort(low, high);
    for(int *p=low; p<=high; p++)
        cout << *p << " ";
        cout << endl;
}