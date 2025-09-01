
#include <iostream>

#include <algorithm> 

using namespace std;

// Function to print an array of integers
void PrintArr(int* vec, int n, const char* s) {
    cout << s << ": [";
    for (int i = 0; i < n; i++) {
        cout << vec[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Bubble Sort
void BubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) { // Number of passes
        for (int j = 0; j < n - i - 1; j++) { // Compare adjacent elements
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

// Selection Sort
void SelectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) { // Iterate over each element
        int minIdx = i; // Assume the current element is the smallest
        for (int j = i + 1; j < n; j++) { // Find the smallest element
            if (A[j] < A[minIdx]) {
                minIdx = j;
            }
        }
        swap(A[i], A[minIdx]); // Swap the smallest element with the current element
    }
}

// Insertion Sort
void InsertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) { // Start from the second element
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) { // Shift larger elements to the right
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key; // Insert the key in the correct position
    }
}

// Merge Sort (Helper Functions)
void Merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left half
    int n2 = right - mid;    // Size of the right half

    int* L = new int[n1]; // Left temporary array
    int* R = new int[n2]; // Right temporary array

    for (int i = 0; i < n1; i++) L[i] = A[left + i]; // Copy left half
    for (int i = 0; i < n2; i++) R[i] = A[mid + 1 + i]; // Copy right half

    int i = 0, j = 0, k = left; // Initial indexes

    while (i < n1 && j < n2) { // Merge arrays
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    for (; i < n1; i++) A[k++] = L[i]; // Copy remaining elements of L
    for (; j < n2; j++) A[k++] = R[j]; // Copy remaining elements of R

    delete[] L; // Free memory
    delete[] R;
}

void MergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point
        MergeSort(A, left, mid);            // Recursively sort the left half
        MergeSort(A, mid + 1, right);       // Recursively sort the right half
        Merge(A, left, mid, right);         // Merge the two halves
    }
}

// Quick Sort (Helper Functions)
int Partition(int A[], int low, int high) {
    int pivot = A[high]; // Choose the last element as pivot
    int i = low - 1;     // Index of smaller element

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) { // If current element is smaller than the pivot
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]); // Place pivot in the correct position
    return i + 1;
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = Partition(A, low, high); // Partitioning index
        QuickSort(A, low, pi - 1);        // Recursively sort the left half
        QuickSort(A, pi + 1, high);       // Recursively sort the right half
    }
}

// Counting Sort
void CountingSort(int A[], int n) {
    int maxVal = *max_element(A, A + n);
    int minVal = *min_element(A, A + n);
    int range = maxVal - minVal + 1;

    int* count = new int[range]();
    int* output = new int[n];

    for (int i = 0; i < n; i++) count[A[i] - minVal]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) output[--count[A[i] - minVal]] = A[i];
    for (int i = 0; i < n; i++) A[i] = output[i];

    delete[] count;
    delete[] output;
}

// Radix Sort (Helper Functions)
void CountSortForRadix(int A[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(A[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) output[--count[(A[i] / exp) % 10]] = A[i];
    for (int i = 0; i < n; i++) A[i] = output[i];

    delete[] output;
}

void RadixSort(int A[], int n) {
    int maxVal = *max_element(A, A + n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        CountSortForRadix(A, n, exp);
    }
}


int main() {
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original Array:" << endl;
    PrintArr(A, n, "Array");

    int B[n];

    // Sorting demonstrations
    copy(begin(A), end(A), B);
    BubbleSort(B, n);
    PrintArr(B, n, "Bubble Sort");

    copy(begin(A), end(A), B);
    SelectionSort(B, n);
    PrintArr(B, n, "Selection Sort");

    copy(begin(A), end(A), B);
    InsertionSort(B, n);
    PrintArr(B, n, "Insertion Sort");

    copy(begin(A), end(A), B);
    MergeSort(B, 0, n - 1);
    PrintArr(B, n, "Merge Sort");

    copy(begin(A), end(A), B);
    QuickSort(B, 0, n - 1);
    PrintArr(B, n, "Quick Sort");

    copy(begin(A), end(A), B);
    CountingSort(B, n);
    PrintArr(B, n, "Counting Sort");

    copy(begin(A), end(A), B);
    RadixSort(B, n);
    PrintArr(B, n, "Radix Sort");

    return 0;
}


// #include <iostream>
// using namespace std;

// void selectionSort(int arr[], int n) {
//    for(int i = 0 ; i< n-1 ;i++){
//        int mini = i;
//        for(int j = i+1; j < n; j++) {
//            if(arr[j] < arr[mini])
//            {
//                mini = j;
//            }
//        }
//        int temp = arr[mini];
//         arr[mini] = arr[i];
//         arr[i] = temp;
//    }
// }

// void bubbalSort(int arr[] , int n){
//     for(int i = 0 ; i< n-1; i++) {
//         for(int j = i ; j<n-i -1; j++){
//             if(arr[j] > arr[n-i-1]){
//                  int temp = arr[j];
//                  arr[j] = arr[n-i-1];
//                   arr[n-i-1] = temp;
                 
//             }
              
//         }
         
//     }
// }


// void insertSort (int arr[] , int n){
//     for(int i =1 ; i< n ;i++){
//         int key = arr[i];
//         int j = i-1;
        
//         while(j>=0 && arr[j] > key)
//         {
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = key;
//     }
// }

// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original array: ";
//     printArray(arr, n);

//     // selectionSort(arr, n);
//     // bubbalSort(arr,n);
//     insertSort(arr,n);

//     cout << "Sorted array: ";
//     printArray(arr, n);

//     return 0;
// }
