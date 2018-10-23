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
        void heapifyup(int index);
        void heapifydown(int index);
    
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
    return heap.size();
}
 
/*
 * Insert Element into a Heap
 */
void PQbinary::Insert(int element)
{
    heap.push_back(element);
    heapifyup(heap.size() -1);
}
/*
 * Delete Minimum Element
 */
void PQbinary::DeleteMin()
{
    if (heap.size() == 0)
    {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
    cout<<"Element Deleted"<<endl;
}
 
/*
 * Return Minimum Key
 */
int PQbinary::Min()
{
    if (heap.size() == 0)
    {
        return -1;
    }
    else
        // front = vector library 
        return heap.front();
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
    if (l < heap.size())
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
    if (r < heap.size())
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
void PQbinary::heapifyup(int in)
{
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in])
    {
        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        heapifyup(parent(in));
    }
}
 
/* 
 * Heapify- Maintain Heap Structure top down
 */
void PQbinary::heapifydown(int in)
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
        heapifydown(child);
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








