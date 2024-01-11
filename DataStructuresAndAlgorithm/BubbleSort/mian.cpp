#include <iostream>

void swap( int* a, int* b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort( int arr[], int arrSize ) {
    for( int i = 0; i < arrSize - 1; ++i ) {
        for( int j = 0; j < arrSize - 1 - i; ++j ) {
            if( arr[j] > arr[j + 1] )
                swap( &arr[j], &arr[j + 1] );
        }
    }
}

void betterBubbleSort( int arr[], int arrSize ) {
    for( int i = 0; i < arrSize - 1; ++i ) {
        bool swapped = false;
        for( int j = 0; j < arrSize - 1 - i; ++j ) {
            if( arr[j] > arr[j + 1] ) {
                swap( &arr[j], &arr[j + 1] );
                swapped = true;
            }
        }
        if( swapped == false ) {
            break;
        }
    }
}

int main() {

    int arr1[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int arr2[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int arrSize1 = sizeof( arr1 ) / sizeof( arr1[0] );
    int arrSize2 = sizeof( arr2 ) / sizeof( arr2[0] );

    bubbleSort( arr1, arrSize1 );
    std::cout << "Sorted Array is: ";
    for( int i = 0; i < arrSize1; i++ ) {
        std::cout << arr1[i] << "  ";
    }
    std::cout << std::endl;

    betterBubbleSort( arr2, arrSize2 );
    std::cout << "Sorted Array is: ";
    for( int i = 0; i < arrSize2; i++ ) {
        std::cout << arr2[i] << "  ";
    }
    std::cout << std::endl;

    system( "pause" );
    return 0;
}