 #include <iostream>
using namespace std;

class Heap{
  public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity) {
      this->arr = new int[capacity];
      this->capacity = capacity;
      //size = current number of elements in heap
      this->size = 0 ;
    }

    void insert(int val) {
      if(size == capacity) {
        cout << "Heap OverFlow" << endl;
        return;
      }
      //size increase kar jaega
      size++;
      int index = size;
      arr[index] = val;

      ///take the val to its cvorrect position
      while(index > 1) {
        int parentIndex = index/2;
        if(arr[index] > arr[parentIndex]) {
          swap(arr[index], arr[parentIndex]);
          index = parentIndex;
        }
        else {
          break;
        }
      }
    }
    void printHeap() {
      for(int i=1; i<=size; i++) {
         cout << arr[i] << " ";
     }
    }

    int deleteFromHeap() {
      int answer = arr[1];
      //replacement
      arr[1] = arr[size];
      //last element ko delete uski original position se
      size--;
      int index = 1;
      while(index < size ) {
          int leftIndex = 2*index;
          int rightIndex = 2*index+1;

          //find out karna h , sabse bada kon
          int largestKaIndex = index;
          //check left child
          if(leftIndex <= size && arr[largestKaIndex] < arr[leftIndex]) {
            largestKaIndex = leftIndex;
          }
          if(rightIndex <= size && arr[largestKaIndex] < arr[rightIndex]) {
            largestKaIndex = rightIndex;
          }
          //no change
          if(index == largestKaIndex) {
            break;
          }
          else {
            swap(arr[index], arr[largestKaIndex]);
            index = largestKaIndex;
          }
      }
      return answer;
    }
};

void heapify(int *arr, int n, int index) {
  int leftIndex = 2*index;
  int rightIndex = 2*index+1;
  int largestKaIndex = index;

  //teno me se max lao 
  if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]) {
    largestKaIndex = leftIndex;
  }
  if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]) {
    largestKaIndex = rightIndex;
  }
  //after these 2 conditions largestKaIndex will be pointing towards largest elemnt among 3 
  if(index != largestKaIndex) {
    swap(arr[index], arr[largestKaIndex]);
    //ab recursion sambhal lega
    index = largestKaIndex;
    heapify(arr, n, index);
  }
}

void buildHeap(int arr[], int n) {
  for(int index = n/2; index>0; index--) {
    heapify(arr, n, index);
  }
}

void heapSort(int arr[], int n) {
  while(n != 1 ) {
    swap(arr[1], arr[n]);
    n--;
    heapify(arr,n,1);
  }
}


int main() {
  int arr[] = {-1,5,10,15,20,25,12};
  int n = 6;
  buildHeap(arr,6);
  
  cout << "printing heap: " << endl;
  for(int i=1; i<=6; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr, n);
    cout << "printing heap: " << endl;
    for(int i=1; i<=6; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  


  // Heap h(20);
  // //insertion
  // h.insert(10);
  // h.insert(20);
  // h.insert(5);
  // h.insert(11);
  // h.insert(6);

  // cout << "Printing the content of heap: " << endl;
  // h.printHeap();
  // int ans = h.deleteFromHeap();
  // cout << "Answer: " << ans << endl;
  // cout << "Printing the content of heap: " << endl;
  // h.printHeap();
  return 0;
}