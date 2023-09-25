// Forward declarations
void swap(int *p, int *q);
void readArray(int size);
void printArray(int size);
void bubbleSort(int n);

/*
   a
   multi-line
   comment - this code is
   taken from the assignment document
*/

int arr[20]; // Global array

// Driver program to test above functions
int main() {
    int n;
    printStr("Input array size: \n");
    readInt(&n);
    printStr("Input array elements: \n");
    readArray(n);
    printStr("Input array: \n");
    printArray(n);
    bubbleSort(n);
    printStr("Sorted array: \n");
    printArray(n);
    return 0;
}