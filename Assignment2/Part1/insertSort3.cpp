#include <iostream>
#include <chrono>  // for high_resolution_clock
using namespace std;


void insertSort3(int* low, int* high) {
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
    int *low = a, *high = a + sizeof(a)/sizeof(a[0]) - 1;

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    // Portion of code to be timed
    insertSort3(low, high);
    
    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    
    for(int *p=low; p<=high; p++)
        cout << *p << " ";
        cout << endl;
    
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n"; 
}