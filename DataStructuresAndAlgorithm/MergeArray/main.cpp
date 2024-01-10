#include <iostream>
#include <vector>

// Approach 1: we are creating function pointer that points to the array that we will be returned.
int* mergeArrayF1( int* arr1, int size1, int* arr2, int size2 ) {
    if( size1 == 0 ) {
        return arr2;
    }
    if( size2 == 0 ) {
        return arr1;
    }

    int newSize = size1 + size2;
    int* newArr = new int[newSize];
    memset( newArr, 0, sizeof( int ) * newSize );

    int newArrIndex = 0;
    int index1 = 0, index2 = 0;
    while( index1 < size1 && index2 < size2 ) {
        if( arr1[index1] <= arr2[index2] ) {
            newArr[newArrIndex] = arr1[index1];
            ++index1;
        }
        else {
            newArr[newArrIndex] = arr2[index2];
            ++index2;
        }
        ++newArrIndex;
    }

    for( int i = index1; i < size1; ++i ) {
        newArr[newArrIndex] = arr1[i];
        ++newArrIndex;
    }

    for( int i = index2; i < size2; ++i ) {
        newArr[newArrIndex] = arr2[i];
        ++newArrIndex;
    }

    return newArr;
}

void execMergeArrayF1() {
    int arr1[] = { 1,2,3,4,5,6,7 };
    int arr2[] = { 3,4,5,7,8,9,10,11 };

    int size1 = sizeof( arr1 ) / sizeof( arr1[0] ); // 7
    int size2 = sizeof( arr2 ) / sizeof( arr2[0] ); // 8

    int* newArr = mergeArrayF1( arr1, size1, arr2, size2 );
    int newSize = size1 + size2;

    std::cout << "Merged Array: " << std::endl;
    for( int i = 0; i < newSize; ++i ) {
        std::cout << newArr[i] << "  ";
    }
    std::cout << std::endl;
}

std::vector<int> mergeArrayF2( std::vector<int>& arr1, std::vector<int>& arr2 ) {
    std::vector<int> newArr;
    size_t index1 = 0, index2 = 0;
    while( index1 < arr1.size() && index2 < arr2.size() )
    {
        if( arr1[index1] <= arr2[index2] ) {
            newArr.push_back( arr1[index1] );
            ++index1;
        }
        else {
            newArr.push_back( arr2[index2] );
            ++index2;
        }
    }
    for( size_t i = index1; i < arr1.size(); ++i ) {
        newArr.push_back( arr1[i] );
    }
    for( size_t i = index2; i < arr2.size(); ++i ) {
        newArr.push_back( arr2[i] );
    }
    return newArr;
}

void execMergeArrayF2() {
    std::vector<int> arr1{ 1,2,3,4,5,6,7 };
    std::vector<int> arr2{ 3,4,5,7,8,9,10,11 };

    std::vector<int> newArr = mergeArrayF2( arr1, arr2 );

    std::cout << "Merged Array: " << std::endl;
    for( size_t i = 0; i < newArr.size(); ++i ) {
        std::cout << newArr[i] << "  ";
    }
    std::cout << std::endl;
}

int main() {

    execMergeArrayF1();
    execMergeArrayF2();

    system( "pause" );
    return 0;
}