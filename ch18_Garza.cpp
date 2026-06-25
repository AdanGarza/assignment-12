// ============================================================
// COSC 1437 - Chapter 18: Searching and Sorting Algorithms
// Name: Adan Garza
// Date:06/25/2026
// ============================================================

#include <iostream>
using namespace std;

// ============================================================
// CONSTANTS
// ============================================================
const int SIZE = 10;

// ============================================================
// FUNCTION PROTOTYPES
// ============================================================

// --- Searching ---
int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);

// --- Sorting (YOU implement these) ---
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);

// --- Sorting (Scaffolded - study and run these) ---
void quickSort(int arr[], int low, int high);
int  partition(int arr[], int low, int high);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

// --- Utility ---
void printArray(int arr[], int size);
void copyArray(int src[], int dest[], int size);


// ============================================================
// MAIN
// ============================================================
int main()
{
    // Original dataset - DO NOT modify this
    int original[SIZE] = {64, 25, 12, 78, 33, 90, 47, 5, 61, 18};

    // Working copy used for each sort so we always start fresh
    int arr[SIZE];

    cout << "=== Chapter 18: Searching and Sorting ===" << endl << endl;

    // ----------------------------------------------------------
    // PART 1: LINEAR SEARCH
    // ----------------------------------------------------------
    cout << "--- Linear Search ---" << endl;
    cout << "Array: ";
    printArray(original, SIZE);

    int target = 78;
    int result = linearSearch(original, SIZE, target);
    if (result != -1)
        cout << "Found " << target << " at index " << result << endl;
    else
        cout << target << " not found." << endl;

    target = 99;
    result = linearSearch(original, SIZE, target);
    if (result != -1)
        cout << "Found " << target << " at index " << result << endl;
    else
        cout << target << " not found." << endl;

    cout << endl;

    // ----------------------------------------------------------
    // PART 2: BUBBLE SORT
    // ----------------------------------------------------------
    cout << "--- Bubble Sort ---" << endl;
    copyArray(original, arr, SIZE);
    cout << "Before: ";
    printArray(arr, SIZE);

    bubbleSort(arr, SIZE);

    cout << "After:  ";
    printArray(arr, SIZE);
    cout << endl;

    // ----------------------------------------------------------
    // PART 3: SELECTION SORT
    // ----------------------------------------------------------
    cout << "--- Selection Sort ---" << endl;
    copyArray(original, arr, SIZE);
    cout << "Before: ";
    printArray(arr, SIZE);

    selectionSort(arr, SIZE);

    cout << "After:  ";
    printArray(arr, SIZE);
    cout << endl;

    // ----------------------------------------------------------
    // PART 4: INSERTION SORT
    // ----------------------------------------------------------
    cout << "--- Insertion Sort ---" << endl;
    copyArray(original, arr, SIZE);
    cout << "Before: ";
    printArray(arr, SIZE);

    insertionSort(arr, SIZE);

    cout << "After:  ";
    printArray(arr, SIZE);
    cout << endl;

    // ----------------------------------------------------------
    // PART 5: QUICK SORT (scaffolded)
    // ----------------------------------------------------------
    cout << "--- Quick Sort (scaffolded) ---" << endl;
    copyArray(original, arr, SIZE);
    cout << "Before: ";
    printArray(arr, SIZE);

    quickSort(arr, 0, SIZE - 1);

    cout << "After:  ";
    printArray(arr, SIZE);
    cout << endl;

    // ----------------------------------------------------------
    // PART 6: MERGE SORT (scaffolded)
    // ----------------------------------------------------------
    cout << "--- Merge Sort (scaffolded) ---" << endl;
    copyArray(original, arr, SIZE);
    cout << "Before: ";
    printArray(arr, SIZE);

    mergeSort(arr, 0, SIZE - 1);

    cout << "After:  ";
    printArray(arr, SIZE);
    cout << endl;

    // ----------------------------------------------------------
    // PART 7: BINARY SEARCH
    // Note: Binary Search requires a SORTED array!
    // 
    // // ----------------------------------------------------------
    cout << "--- Binary Search ---" << endl;
    copyArray(original, arr, SIZE);
    bubbleSort(arr, SIZE);   // must sort before binary searching
    cout << "Sorted array: ";
    printArray(arr, SIZE);

    target = 47;
    result = binarySearch(arr, SIZE, target);
    if (result != -1)
        cout << "Found " << target << " at index " << result << endl;
    else
        cout << target << " not found." << endl;

    target = 99;
    result = binarySearch(arr, SIZE, target);
    if (result != -1)
        cout << "Found " << target << " at index " << result << endl;
    else
        cout << target << " not found." << endl;

    cout << endl;

    return 0;
}


// ============================================================
// UTILITY FUNCTIONS (provided for you)
// ============================================================

// Prints all elements of an array on one line
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Copies src[] into dest[] element by element
void copyArray(int src[], int dest[], int size)
{
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}


// ============================================================
// PART 1 - LINEAR SEARCH (provided for you)
// ============================================================
// Examines each element one at a time until the target is found
// or the end of the array is reached.
// Returns the index of the target, or -1 if not found.
int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;   // found it - return the index
    }
    return -1;          // never found it
}


// ============================================================
// PART 2 - BUBBLE SORT  ** YOU IMPLEMENT THIS **
// ============================================================
void bubbleSort(int arr[], int size)
{
    for (int pass = 0; pass < size - 1; pass++)
    {
        for (int j = 0; j < size - 1 - pass; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// ============================================================
// PART 3 - SELECTION SORT  ** YOU IMPLEMENT THIS **
// ============================================================
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}


// ============================================================
// PART 4 - INSERTION SORT  ** YOU IMPLEMENT THIS **
// ============================================================
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


// ============================================================
// PART 5 - QUICK SORT (scaffolded - study this, do not modify)
// ============================================================
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // use the last element as pivot
    int i = low - 1;        // i tracks the boundary of "small" elements

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i]   = arr[j];
            arr[j]   = temp;
        }
    }

    int temp   = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high]  = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}


// ============================================================
// PART 6 - MERGE SORT (scaffolded - study this, do not modify)
// ============================================================
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


// ============================================================
// PART 7 - BINARY SEARCH  ** YOU IMPLEMENT THIS **
// ============================================================
int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (target < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}
