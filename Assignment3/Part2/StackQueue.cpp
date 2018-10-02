
// CPP program to implement Queue using 
// two stacks with costly enQueue() 
#include <bits/stdc++.h> 
using namespace std; 
  
struct StackQueue { 
    stack<int> s1, s2; 
  
    void enQueue(int x) 
    { 
        // Move all elements from s1 to s2 
        while (!s1.empty()) { 
            s2.push(s1.top()); 
            s1.pop(); 
        } 
  
        // Push item into s1 
        s1.push(x); 
  
        // Push everything back to s1 
        while (!s2.empty()) { 
            s1.push(s2.top()); 
            s2.pop(); 
        } 
    } 
  
    // Dequeue an item from the queue 
    int deQueue() 
    { 
        // if first stack is empty 
        if (s1.empty()) { 
            cout << "Q is Empty"; 
            exit(0); 
        } 
  
        // Return top of s1 
        int x = s1.top(); 
        s1.pop(); 
        return x; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    
    int length;
    int n;
    cout << "enter length of queue: ";
    cin >> length; 

    StackQueue q; 
    
    for(int i=0; i < length; i++ ) {
    //bool ok = true;
    //while(ok) {
        cout << "Enter a value to put in queue:";
        cin >> n;
        q.enQueue(n);
    } 

    /*
    q.enQueue(67);
    q.enQueue(4); 
    q.enQueue(32); */
  

    for(int i = 0; i < length; i++) {
        cout << q.deQueue() << '\n'; 
    } 

    /*
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n';  */
  
    return 0; 
}