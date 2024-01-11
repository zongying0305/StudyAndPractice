#include <iostream>

class Node {
public:
    Node( int data ) {
        this->data = data;
        this->next = nullptr;
    }
    int data;
    Node* next;
};

class Stack {
public:
    Stack() {
        top = nullptr;
    }

    void push( int data ) {
        Node* newNode = new Node( data );
        if ( top == nullptr ) {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if ( top == nullptr ) {
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
        Node* temp = top;
        int popData = temp->data;
        top = temp->next;
        delete temp;
        return popData;
    }

    int peek() {
        if ( top == nullptr ) {
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        if ( top == nullptr ) {
            std::cout << "Stack underflow" << std::endl;
            return;
        }

        std::cout << "top--> ";
        Node* temp = top;
        while ( temp != nullptr ) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

private:
    Node* top;
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
    s.display(); // top--> 2 33 13 11 12

    std::cout << "Pop element: " << s.pop() << std::endl;
    s.display(); // top--> 33 13 11 12

    std::cout << "Push( 24 ): " << std::endl;
    s.push( 24 );
    s.display(); // top--> 24 33 13 11 12

    std::cout << "Top most element: " << s.peek() << std::endl;

    system( "pause" );
    return 0;
}