// binary heap = complete binary tree 
//  - all levels are filled 
//  - last level has all keys as left as possible 
// root element: array[0]
// parent node: array[(i-1)/2]
// left child node: array[(2*i)+1]
// right child node: array[(2*i)+2]

// Min Heap:
// the key at root must be minimum to all other keys in the binary heap
// the value of each node is >= the value of its parent (min at root)

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <climits> 
#include <stack>
using namespace std;


class PQbinary
{

    // declare functions
    private:
        //int heap[];
        vector <int> vec;
        int* heap = vec.data();
        int left(int parent);
        int right(int parent);
        int parent(int child);
        void swim(int index);
        void sink(int index);
    
    public:
        PQbinary()
        {}
        void Insert(int element);
        void DeleteMin();
        int Min();
        void DisplayHeap();
        int Size();
};

/* 
 * Return Heap Size
 */
int PQbinary::Size()
{
    return sizeof(heap);
}
 
/*
 * Insert Element into a Heap
 */
void PQbinary::Insert(int element)
{
    heap.push(element);
    swim(sizeof(heap) -1);
}
/*
 * Delete Minimum Element
 */
void PQbinary::DeleteMin()
{
    if (sizeof(heap) == 0)
    {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    heap[0] = heap.at(sizeof(heap) - 1);
    heap.pop();
    sink(0);
    cout<<"Element Deleted"<<endl;
}
 
/*
 * Return Minimum Key
 */
int PQbinary::Min()
{
    if (sizeof(heap) <= 0) 
        return INT_MAX; 
    if (sizeof(heap) == 1) 
    { 
        sizeof(heap)--; 
        return heap[0]; 
    } 
  
    // Store the minimum value, and remove it from heap 
    int root = heap[0]; 
    heap[0] = heap[sizeof(heap)-1]; 
    sizeof(heap)--; 
    swim(0); 
    sink(0);
  
    return heap[0]; 

    /*
    if (sizeof(heap) == 0)
    {
        return -1;
    }
    else

        return heap[0];
        //return heap.front();

    */
} 
 
/*
 * Display Heap
 */
void PQbinary::DisplayHeap()
{
    // begin = vector library
    vector <int>::iterator pos = heap.begin();
    cout<<"Heap -->  ";
    while (pos != heap.end())
    {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl;
}
 
/*
 * Return Left Child
 */
int PQbinary::left(int parent)
{
    int l = 2 * parent + 1;
    if (l < sizeof(heap))
        return l;
    else
        return -1;
}
 
/* 
 * Return Right Child
 */
int PQbinary::right(int parent)
{
    int r = 2 * parent + 2;
    if (r < sizeof(heap))
        return r;
    else
        return -1;
}
 
/*
 * Return Parent
 */
int PQbinary::parent(int child)
{ 
    int p = (child - 1)/2;
    if (child == 0)
        return -1;
    else
        return p;
} 
 
/*
 * Heapify- Maintain Heap Structure bottom up
 */
void PQbinary::swim(int in)
{
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in])
    {
        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        swim(parent(in));
    }
}
 
/* 
 * Heapify- Maintain Heap Structure top down
 */
void PQbinary::sink(int in)
{
 
    int child = left(in);
    int child1 = right(in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1])
    {
       child = child1;
    }
    if (child > 0 && heap[in] > heap[child])
    {
        int temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;
        sink(child);
    }
}
 
/*
 * Main Contains Menu
 */
int main()
{
    PQbinary h;
    while (1)
    {
        cout<<"------------------"<<endl;
        cout<<"Operations on Heap"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Minimum Element"<<endl;
        cout<<"3.Extract Minimum Element"<<endl;
        cout<<"4.Print Heap"<<endl;
        cout<<"5.Exit"<<endl;
        int choice, element;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element to be inserted: ";
            cin>>element;
            h.Insert(element);
            break;
        case 2:
            h.DeleteMin();
            break;
        case 3:
            cout<<"Minimum Element: ";
            if (h.Min() == -1)
            {
                cout<<"Heap is Empty"<<endl;
            }
            else
                cout<<"Minimum Element:  "<<h.Min()<<endl;
            break;
        case 4:
            cout<<"Displaying elements of Hwap:  ";
            h.DisplayHeap();
            break;
        case 5:
            exit(1);
        default:
            cout<<"Enter Correct Choice"<<endl;
        }
    }
    return 0;
}








