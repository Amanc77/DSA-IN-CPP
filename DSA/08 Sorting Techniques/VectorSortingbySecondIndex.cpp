#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
   
    bool myComp(vector<int> &a  ,vector <int> &b){
        return a[1] < b[1];
    }
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Array sorting part
    int arr[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n1);

    // Try different sorts
    // selectionSort(arr, n1);
    // bubbleSort(arr, n1);
    insertSort(arr, n1);

    cout << "Sorted array: ";
    printArray(arr, n1);

    // 2D vector part
    vector<vector<int>> v;
    cout << "\nEnter the size of vector: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        cout << "Enter values of a and b: ";
        int a, b;
        cin >> a >> b;
        temp.push_back(a); // ✅ use push_back
        temp.push_back(b);
        v.push_back(temp);
    }

    cout << "\nEntered 2D vector:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
    sort(v.begin() , v.end());
    
     cout << "\nafter sort  2D vector:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
     
    sort(v.begin() , v.end() , myComp);
    

     cout << "\nafter sort by index 1  2D vector:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
