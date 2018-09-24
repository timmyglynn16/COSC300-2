#include <iostream>
#include <chrono>  // for high_resolution_clock
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

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    // Portion of code to be timed
    insertSort2(a, sizeof(a)/sizeof(a[0]));
    
    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
    cout << a[i] << " ";
    cout << endl;

    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";    
}