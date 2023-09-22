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

void swap(int *p, int *q) { /* Swap two numbers */
    int t = *p;
    *p = *q;
    *q = t;
}

void readArray(int size) { /* Function to read an array */
    int i;
    for (i = 0; i < size; i = i + 1) {
        printStr("Input next element\n");
        readInt(&arr[i]);
    }
}

void printArray(int size) { /* Function to print an array */
    int i;
    for (i = 0; i < size; i = i + 1) {
        printInt(arr[i]); 
        printStr(" ");
    }
    printStr("\n");
}

void bubbleSort(int n) { /* A function to implement bubble sort */
    int i;
    int j;
    for (i = 0; i < n - 1; i = i + 1)
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j = j + 1)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void main{
    int x=3;
    char* str="hello world\0";
    char x='3786djsal\';,..[=]';
    // this is a comment
    /*
       a
       multi-line
       comment
    */

    for(int i=0;(i<10&&i>3)||(i<2&&i>0);i=i+1)
    {
        int x=i*i+i/i-i;
    }

    if(x<=10)
        x=11;
    else 
        x=+10;

    if(x==3)
        x=-5;        //inline comment

    if(x!=10)
        x=11;
    char x[]={'1','2','3'};
    x=1&2;
    int y=49382238;
    int _hellow1=85;
    return 0;
}
