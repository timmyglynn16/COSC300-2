#include <iostream>
using namespace std;

void insertSort2(int a[], int num) {
    for(int *p=a+1; p<a+num; p++) {
        int t = *p, *q = p;
        
        while(q > a && *(q-1) > t) {
            *q = *(q-1);
            q--;
            
        }
        *q = t;
    }
}
    
int main(void) {
    int a[] = { 7, 8, 9, 10, 1, 6, 2, 4, 3, 5};
    
    insertSort2(a, sizeof(a)/sizeof(a[0]));
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
    cout << a[i] << " ";
    cout << endl;
     
}