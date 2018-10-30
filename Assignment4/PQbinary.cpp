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
#include <string>
#include <iostream>
using namespace std; 

class BinaryMinHeap {

private:

      int *data;
      int heapSize;
      int arraySize;
      
      int leftchild(int nodeIndex) {return 2 * nodeIndex + 1;}
      int rightchild(int nodeIndex) {return 2 * nodeIndex + 2;}
      int parent(int nodeIndex) {return (nodeIndex - 1) / 2;}

 

public:

      BinaryMinHeap(int size) {
            data = new int[size];
            heapSize = 0;
            arraySize = size;
      }    

      int getMinimum() {
            if (isEmpty())
                  throw string("Heap is empty");
            else
                  return data[0];
      }

      bool isEmpty() {
            return (heapSize == 0);
      }

      ~BinaryMinHeap() {
            delete[] data;
      }


// compare to the parent 
void BinaryMinHeap::swim(int nodeIndex) {

      int parentIndex, tmp;

      if (nodeIndex != 0) {
            parentIndex = parent(nodeIndex);
            if (data[parentIndex] > data[nodeIndex]) {
                  tmp = data[parentIndex];
                  data[parentIndex] = data[nodeIndex];
                  data[nodeIndex] = tmp;
                  swim(parentIndex);
            }
      }
}

 

void BinaryMinHeap::insert(int value) {

      if (heapSize == arraySize)
            throw std::string("Heap's underlying storage is overflow");
            //throw string("Heap's underlying storage is overflow");
      else {
            heapSize++;
            data[heapSize - 1] = value;
            swim(heapSize - 1);
      }
}

void BinaryMinHeap::sink(int nodeIndex) {

      int leftChildIndex, rightChildIndex, minIndex, tmp;

      leftChildIndex = leftchild(nodeIndex);
      rightChildIndex = rightchild(nodeIndex);

      if (rightChildIndex >= heapSize) {
            if (leftChildIndex >= heapSize)
                  return;
            else
                  minIndex = leftChildIndex;
      } else {
            if (data[leftChildIndex] <= data[rightChildIndex])
                  minIndex = leftChildIndex;
            else
                  minIndex = rightChildIndex;
      }

      if (data[nodeIndex] > data[minIndex]) {
            tmp = data[minIndex];
            data[minIndex] = data[nodeIndex];
            data[nodeIndex] = tmp;
            sink(minIndex);
      }
}

 

void BinaryMinHeap::delMin() {

      if (isEmpty())
            throw string("Heap is empty");
      else {
            data[0] = data[heapSize - 1];
            heapSize--;
            if (heapSize > 0)
                  sink(0);
      }
}

void BinaryMinHeap::DisplayHeap()
{
    int* pos = &data[0];
    cout<<"Heap -->  ";
    while (*pos != data[0])
    {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl;
}


};

int main() {
    BinaryMinHeap h(20);
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
            h.insert(element);
            break;
        case 2:
            h.delMin();
            break;
        case 3:
            cout<<"Minimum Element: ";
            if (h.getMinimum() == -1)
            {
                cout<<"Heap is Empty"<<endl;
            }
            else
                cout<<"Minimum Element:  "<<h.getMinimum()<<endl;
            break;
        case 4:
            cout<<"Displaying elements of the heap:  ";
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

