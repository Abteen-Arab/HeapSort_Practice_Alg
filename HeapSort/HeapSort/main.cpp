#include <iostream>
using namespace std;

// A utility function to heapify a subtree rooted with node i which is an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1; // left child node index
    int right = 2 * i + 2; // right child node index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]); // swap the root with the largest child
        heapify(arr, n, largest); // recursively heapify the affected subtree
    }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    // Print sorted array
    cout << "Sorted array is \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
