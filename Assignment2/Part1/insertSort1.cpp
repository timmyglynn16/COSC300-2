#include <iostream>
#include <chrono>  // for high_resolution_clock
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
    
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    // Portion of code to be timed
    insertSort1(a, sizeof(a)/sizeof(a[0]));
    
    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
    cout << a[i] << " ";
    cout << endl;

    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}

    


