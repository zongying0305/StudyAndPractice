#include <iostream>

void swap( int* num1, int* num2 ) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selectionSort( int arr[], int arrSize ) {
    for( int i = 0; i < arrSize - 1; ++i ) {
        int minIndex = i;
        for( int j = i + 1; j < arrSize; ++j ) {
            if( arr[j] < arr[minIndex] ) {
                minIndex = j;
            }
        }
        if( minIndex != i )
            swap( &arr[i], &arr[minIndex] );
    }
}

int main() {

    int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int arrSize = sizeof( arr ) / sizeof( arr[0] );

    selectionSort( arr, arrSize );
    std::cout << "Sorted Array is: ";
    for( int i = 0; i < arrSize; i++ )
    {
        std::cout << arr[i] << "  ";
    }

    system( "pause" );
    return 0;
}