#include <iostream>

void insertionSort( int arr[], int arrSize ) {
    for( int i = 1; i < arrSize; ++i ) {
        int j = i - 1;

        int num = arr[i];

        while( j >= 0 && arr[j] > num ) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = num;
    }
}

int main() {

    int arr[] = { 10, 9, 8, 7, 6, 5, 22, 3, 2, 1 };
    int arrSize = sizeof( arr ) / sizeof( arr[0] );

    insertionSort( arr, arrSize );

    std::cout << "Sorted Array is: ";
    for( int i = 0; i < arrSize; ++i ) {
        std::cout << arr[i] << "  ";
    }

    system( "pause" );
    return 0;
}