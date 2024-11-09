#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    int comparison_count = 0;
    int swap_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            comparison_count++;
            if (arr[j] > arr[j + 1]) {
                swap_count++;
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Number of comparisons: " << comparison_count << endl;
    cout << "Number of swaps: " << swap_count << endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    // Print the sorted array (optional)
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}