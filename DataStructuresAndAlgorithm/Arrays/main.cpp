/* Implementing dynamic array in c++ which is basically a vector STL library.
   but the below implementation of arrays in c++ is done by using class which will have the
   following functions.

    1. void push(int data): This function takes one element and inserts it at the last.
    2. void push(int data, int index): It inserts data at the specified index.
    3. int get(int index): It is used to get the element at the specified index.
    4. void pop(): It deletes the last element. Time complexity is O(1).
    5. int size(): It returns the size of the vector i.e, number of elements in the vector. Time complexity is O(1).
    6. int getcapacity(): It returns the capacity of the vector. Time complexity is O(1).
    7. void print(): It is used to print array elements. Time complexity is O(N), where N is the size of the vector.
 */

#include <cstring>
#include <iostream>

class DynamicArray {
public:
    DynamicArray() {
        capacity = 1;
        arr = new int[capacity];
        memset( arr, 0, sizeof( int ) * capacity );
        totalNumbers = 0;
    }

    int length() { return totalNumbers; }

    int pop() {
        int element = arr[totalNumbers - 1];
        --totalNumbers;
        return element;
    }

    int pop( int index ) {
        int element = 0;
        if ( index >= 0 && index < totalNumbers ) {
            element = arr[index];
            for ( int i = index; i < totalNumbers - 1; ++i ) {
                arr[i] = arr[i + 1];
            }
            --totalNumbers;
        }
        return element;
    }

    void push( int data ) {
        if ( totalNumbers == capacity ) {
            int* temp = new int[2 * capacity];
            memcpy( temp, arr, sizeof( int ) * capacity );
            delete[] arr;

            capacity = capacity * 2;
            arr = temp;
        }

        arr[totalNumbers] = data;
        totalNumbers++;
    }

    void insertElement( int data, int index ) {
        if ( index == capacity ) {
            push( data );
        }

        for ( int i = totalNumbers; i > index; i-- ) {
            arr[i] = arr[i - 1];
        }

        arr[index] = data;
        totalNumbers++;
    }

    void print() {
        for ( int i = 0; i < totalNumbers; ++i ) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
private:
    int* arr; // creating array pointer
    int capacity; // holds the actual size of array
    int totalNumbers; // holds the total number of elements in the array
};

int main() {

    DynamicArray a;
    std::cout << "Push(10): " << std::endl;
    a.push( 10 );
    std::cout << "Push(20): " << std::endl;
    a.push( 20 );
    std::cout << "Push(30): " << std::endl;
    a.push( 30 );
    std::cout << "Push(40): " << std::endl;
    a.push( 40 );
    std::cout << "InsertElement( 50, 2 ): " << std::endl;
    a.insertElement( 50, 2 );
    std::cout << "The array is: ";
    a.print();

    std::cout << "Pop: " << std::endl;
    int ele = a.pop();
    std::cout << "Element Deleted: " << ele << std::endl;
    std::cout << "The array is: ";
    a.print();

    std::cout << "Pop(0): " << std::endl;
    a.pop( 0 );
    std::cout << "The array is: ";
    a.print();

    std::cout << "The size of array is: " << a.length() << std::endl;

    system( "pause" );
    return 0;
}
