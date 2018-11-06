// binary arr = complete binary tree 
//  - all levels are filled 
//  - last level has all keys as left as possible 
// root element: array[0]
// parent node: array[(i-1)/2]
// left child node: array[(2*i)+1]
// right child node: array[(2*i)+2]

// Max arr:
// the key at root must be maximum to all other keys in the binary arr
// the value of each node is <= the value of its parent (max at root)
#include <iostream>
#include <cstdlib>
//#include <vector>
#include <iterator>
using namespace std;

class BinaryHeap
{
    private:
        int *arr;
        int arrSize;
        int arraySize;

        int left(int parent);
        int right(int parent);
        int parent(int child);
        void swim(int index);
        void sink(int index);

    public:
    int arrIndex = 0;
        BinaryHeap(int size) {
            
            arr = new int[size];
            arrSize = 0;
            arraySize = size;
        }
        void Insert(int element);
        int DeleteMax();
        void Displayarr();
        int Size();
};

// return size of the array
int BinaryHeap::Size()
{
    return arraySize;
}
 
// insert element into the array
void BinaryHeap::Insert(int element)
{
    //insert into array (not vecotr)
    if(arrIndex != arraySize){
        arr[arrIndex] = element;
        swim(arrIndex);
        arrIndex++;
    }
}

// delete maximum element from array
int BinaryHeap::DeleteMax()
{

    // do it using array!!!
    // save whatever is at index 0
    // set the root = 0
    // for loop that goes through each index of array and calls swim on each index (dec arrIndex)

    if(arraySize == 0) {
        cout<< "Error, empty";
        return 0;
    }

    int max = 0;
    max = arr[0];
    arr[0] = 0;

    sink(0);

    for(int i = 0; i < arraySize; i++){
        swim(i);
    }

    arrIndex--;
    return max;

}
 
// print the array
void BinaryHeap::Displayarr()
{
    for(int i=0; i< arraySize; i++){
        cout<< arr[i] << ",";
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
 * Maintain arr Structure bottom up
 */
void BinaryHeap::swim(int in)
{
    if (in >= 0 && parent(in) >= 0 && arr[parent(in)] < arr[in])
    {
        int temp = arr[in];
        arr[in] =arr[parent(in)];
        arr[parent(in)] = temp;
        swim(parent(in));
    }
}
 
/*
 * Maintain arr Structure top down
 */

void BinaryHeap::sink(int in)
{
    // NO!!!!!!!!!!!!!!!! - retry
    /*
    if (lchild >= 0 && rchild >= 0 && arr[lchild] > arr[rchild])
    {
       lchild = rchild
;
    }
    if (lchild > 0 && arr[in] > arr[lchild])
    {
        int temp = arr[in];
        arr[in] = arr[lchild];
        arr[lchild] = temp;
        sink(lchild);
    } */

    int lchild = left(in);
    int rchild = right(in);

    // have 0's end up at the end of the array (not just bottom of arr)
    // do it by moving as far right in the arr as possible 
    // if right child is ever >= what the next spot is, we need to move 0 to the space before index
    if(rchild >= arrIndex ||  rchild == -1) {
        int temp = arr[in];
        arr[in] = arr[arrIndex - 1];
        arr[arrIndex -1] = temp;
    }
    
    // if the right child is not over stepping where index is sitting, move 0 there 
    else {
        int temp = arr[in];
        arr[in] = arr[rchild];
        arr[rchild] = temp;
        sink(rchild);
    }
} 

int main()
{
    
    BinaryHeap h(6);
    while (1)
    {
        cout<<"------------------"<<endl;
        cout<<"Operations on arr"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Maximum Element"<<endl;
        cout<<"3.Print array"<<endl;
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
        case 3:
            cout<<"Displaying elements of arr:  ";
            h.Displayarr();
            break;
        case 4:
            exit(1);
        default:
            cout<<"Enter Correct Choice"<<endl;
        }
    } 
    return 0;
}
