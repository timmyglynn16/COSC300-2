/*
 * C++ Program to Implement Binary Heap
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;
/*
 * Class Declaration
 */
class BinaryHeap
{
    private:
        //vector <int> heap;

        int *data;
        int heapSize;
        int arraySize;

        int left(int parent);
        int right(int parent);
        int parent(int child);
        void swim(int index);
        void sink(int index);
    public:
    int dataIndex = 0;
        BinaryHeap(int size) {
            
            data = new int[size];
            heapSize = 0;
            arraySize = size;
        }
        void Insert(int element);
        int DeleteMax();
        int ExtractMin();
        void DisplayHeap();
        int Size();
};
/*
 * Return array Size
 */
int BinaryHeap::Size()
{
    return arraySize;
    //return heap.size();
}
 
/*
 * Insert Element into array
 */
void BinaryHeap::Insert(int element)
{
    //insert into array (not vecotr)
    if(dataIndex != arraySize){
        data[dataIndex] = element;
        swim(dataIndex);
        dataIndex++;
    }
    

    /*
    heap.push_back(element);
    swim(heap.size() -1); */
}

/*
 * Delete Maximum Element
 */
int BinaryHeap::DeleteMax()
{
    /*
    if (heap.size() == 0)
    {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    sink(0);
    cout<<"Element Deleted"<<endl; */

    // do it using array!!!
    // save whatever is at index 0
    // set the root = 0
    // for loop that goes through each index of array and calls swim on each index (dec dataIndex)

    if(arraySize == 0) {
        cout<< "Error, empty";
        return 0;
    }

    int max = 0;
    max = data[0];
    data[0] = 0;

    sink(0);

    for(int i = 0; i < arraySize; i++){
        swim(i);
    }

    dataIndex--;
    return max;




}
 
/*
 * Extract Minimum Element
 */

/*
int BinaryHeap::ExtractMin()
{
    if (heap.size() == 0)
    {
        return -1;
    }
    else
        return heap.front();
} */
 
/*
 * Display Heap
 */
void BinaryHeap::DisplayHeap()
{
    /*
    vector <int>::iterator pos = heap.begin();
    cout<<"Heap -->  ";
    while (pos != heap.end())
    {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl; */

    for(int i=0; i< arraySize; i++){
        cout<< data[i] << ",";
    }
    cout << endl;
}
 
/*
 * Return Left Child
 */

int BinaryHeap::left(int parent)
{
    int l = 2 * parent + 1;
    if (l < arraySize)
        return l;
    else
        return -1;
} 
 
/*
 * Return Right Child
 */

int BinaryHeap::right(int parent)
{
    int r = 2 * parent + 2;
    if (r < arraySize)
        return r;
    else
        return -1;
} 
 
/*
 * Return Parent
 */
int BinaryHeap::parent(int child)
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
void BinaryHeap::swim(int in)
{
    if (in >= 0 && parent(in) >= 0 && data[parent(in)] < data[in])
    {
        int temp = data[in];
        data[in] =data[parent(in)];
        data[parent(in)] = temp;
        swim(parent(in));
    }
}
 
/*
 * Heapify- Maintain Heap Structure top down
 */

void BinaryHeap::sink(int in)
{
 
    int lchild = left(in);
    int rchild = right(in);

    if(rchild >= dataIndex ||  rchild == -1) {
        int temp = data[in];
        data[in] = data[dataIndex - 1];
        data[dataIndex -1] = temp;
    }
    

    else {
        int temp = data[in];
        data[in] = data[rchild];
        data[rchild] = temp;
        sink(rchild);
    }
    

    /*
    if (lchild >= 0 && rchild >= 0 && data[lchild] > data[rchild])
    {
       lchild = rchild
;
    }
    if (lchild > 0 && data[in] > data[lchild])
    {
        int temp = data[in];
        data[in] = data[lchild];
        data[lchild] = temp;
        sink(lchild);
    } */
} 
 
/*
 * Main Contains Menu
 */
int main()
{
    
    BinaryHeap h(6);
    while (1)
    {
        cout<<"------------------"<<endl;
        cout<<"Operations on Heap"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Maximum Element"<<endl;
        //cout<<"3.Extract Minimum Element"<<endl;
        cout<<"3.Print Heap"<<endl;
        cout<<"4.Exit"<<endl;
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
            h.DeleteMax();
            break;
        /*case 3:
            cout<<"Minimum Element: ";
            if (h.ExtractMin() == -1)
            {
                cout<<"Heap is Empty"<<endl;
            }
            else
                cout<<"Minimum Element:  "<<h.ExtractMin()<<endl;
            break;  */
        case 3:
            cout<<"Displaying elements of Heap:  ";
            h.DisplayHeap();
            break;
        case 4:
            exit(1);
        default:
            cout<<"Enter Correct Choice"<<endl;
        }
    } 
    return 0;
}
