#include <bits/stdc++.h> 
using namespace std; 
  
struct StackQueue { 
    stack<int> s1, s2; 
  
    void enQueue(int x) 
    { 
        // move all elements from s1 to s2 
        while (!s1.empty()) { 
            s2.push(s1.top()); 
            s1.pop(); 
        } 
  
        // push item into s1 
        s1.push(x); 
  
        // push everything back to s1 
        while (!s2.empty()) { 
            s1.push(s2.top()); 
            s2.pop(); 
        } 
    } 
  
    // deQueue an item from the queue 
    int deQueue() 
    { 
        // if first stack is empty 
        if (s1.empty()) { 
            cout << "Q is Empty"; 
            exit(0);  // exit
        } 
  
        // return top of s1 
        int x = s1.top(); 
        s1.pop(); 
        return x; 
    } 
}; 

int main() 
{ 
    
    int length;
    int n;
    cout << "Enter length of queue: ";
    cin >> length; 

    StackQueue q; 
    
    for(int i=0; i < length; i++ ) {
        cout << "Enter values to put in queue:";
        cin >> n;
        q.enQueue(n);
    } 
  

    for(int i = 0; i < length; i++) {
        cout << q.deQueue() << '\n'; 
    } 
  
    return 0; 
}


// TEST 