#include <iostream>
using namespace std;

void insertSort1(int a[], int num) {
    for(int j=1; j<num; j++) {
        int t = a[j], i = j;
            
        while(i > 0 && a[i-1] > t) {
            a[i] = a[i-1];
            i--;
                
        }
                
            a[i] = t;
        
    }
}
    
int main(void) {
    int a[] = { 7, 8, 9, 10, 1, 6, 2, 4, 3, 5};
    
    insertSort1(a, sizeof(a)/sizeof(a[0]));
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
    cout << a[i] << " ";
    cout << endl;
     
}

    


