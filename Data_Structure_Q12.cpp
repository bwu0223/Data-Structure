#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    if (arr.empty()) return;
    quickSortHelper(arr, 0, arr.size() - 1);
}

void measureTime(void (*sortFunc)(vector<int>&), const vector<int>& originalData, string name) {
    vector<int> arrCopy = originalData; 
    
    auto start = high_resolution_clock::now();
    sortFunc(arrCopy);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << left << setw(18) << name << " | " << duration.count() << " ms" << endl;
}

int main() {
    vector<int> sizes = {1000, 10000, 100000, 1000000};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000000);

    for (int n : sizes) {
        cout << "========================================" << endl;
        cout << "¸ê®Æµ§¼Æ (n) = " << n << endl;
        cout << "----------------------------------------" << endl;

        vector<int> originalData(n);
        for (int i = 0; i < n; i++) {
            originalData[i] = dis(gen);
        }

        measureTime(selectionSort, originalData, "Selection Sort");
        measureTime(bubbleSort, originalData, "Bubble Sort");
        measureTime(insertionSort, originalData, "Insertion Sort");
        measureTime(quickSort, originalData, "Quick Sort");
        cout << "========================================\n" << endl;
    }
    return 0;
}