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

class Queue {
public:
    Queue() {
        size = 0;
        first = nullptr;
        last = nullptr;
    }
    ~Queue() {
        if ( size != 0 ) {
            Node* temp = first;
            for ( int i = 0; i < size; ++i ) {
                first = first->next;
                delete temp;
                temp = first;
            }
        }
    }
    void enQueue( int data ) {
        Node* newNode = new Node( data );
        if ( size == 0 ) {
            first = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
        size++;
    }
    void deQueue() {
        if ( size == 0 ) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node* temp = first;
        first = first->next;
        delete temp;
        --size;
    }
    void display() {
        if ( size == 0 ) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node* temp = first;
        for ( int i = 0; i < size; ++i ) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
private:
    int size;
    Node* first;
    Node* last;
};

int main() {

    Queue q;
    q.enQueue( 10 );
    q.enQueue( 20 );
    q.enQueue( 30 );
    q.enQueue( 40 );
    q.enQueue( 50 );
    q.display();

    q.deQueue();
    q.display();

    q.deQueue();
    q.display();

    q.deQueue();
    q.display();

    system( "pause" );
    return 0;
}