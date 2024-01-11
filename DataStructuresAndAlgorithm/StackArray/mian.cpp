#include <iostream>

class Stack {
public:
    Stack() {
        top = -1;
        arr = new int[maxSize];
        memset( arr, 0, sizeof( int ) * maxSize );
    }
    ~Stack() {
        if ( arr != nullptr )
            delete[] arr;
        arr = nullptr;
    }

    void push( int data ) {
        if ( top >= maxSize ) {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        ++top;
        arr[top] = data;
    }

    int pop() {
        if ( top == -1 ) {
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
        int data = arr[top];
        --top;
        return data;
    }

    int peek() {
        if ( top == -1 ) {
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if ( top == -1 ) {
            std::cout << "Stack underflow" << std::endl;
            return;
        }
        for ( int i = 0; i <= top; ++i ) {
            std::cout << arr[i] << " ";
        }
        std::cout << "<--top" << std::endl;
    }

private:
    const int maxSize = 128;
    int top;
    int* arr;
};

int main() {

    Stack s;
    std::cout << "Push( 12 ): " << std::endl;
    s.push( 12 );
    std::cout << "Push( 11 ): " << std::endl;
    s.push( 11 );
    std::cout << "Push( 13 ): " << std::endl;
    s.push( 13 );
    std::cout << "Push( 33 ): " << std::endl;
    s.push( 33 );
    std::cout << "Push( 2 ): " << std::endl;
    s.push( 2 );
    s.display(); // 12 11 13 33 2 <--top

    std::cout << "Pop element: " << s.pop() << std::endl;
    s.display();  // 12 11 13 33 <--top

    std::cout << "Push( 24 ): " << std::endl;
    s.push( 24 );
    s.display(); // 12 11 13 33 24 <--top

    std::cout << "Top most element: " << s.peek() << std::endl;

    system( "pause" );
    return 0;
}