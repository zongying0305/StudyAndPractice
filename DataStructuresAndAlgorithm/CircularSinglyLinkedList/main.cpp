/*
    This is a circular singly linked list implementation.

    A circular singly linked list is a lot like a regular singly linked list,
    except the last node links back to the first node, AKA the head.
*/

#include <iostream>

class Node
{
public:
    Node( int data ) {
        this->data = data;
        this->next = nullptr;
    }
    int data;
    Node* next;
};

class CircularSinglyLinkedList
{
public:
    CircularSinglyLinkedList() {
        head = nullptr;
        size = 0;
    }

    ~CircularSinglyLinkedList() {
        Node* temp = head;
        for( int i = 0; i < size; ++i ) {
            head = head->next;
            if( temp != nullptr )
                delete temp;
            temp = head;
        }
    }

    void insertAtEnd( int data ) {
        Node* newNode = new Node( data );
        if( head == nullptr ) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;
            for( int i = 0; i < size - 1; ++i ) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        ++size;
    }

    void display() {
        if( head == nullptr ) {
            std::cout << "List is empty" << std::endl;
        }

        Node* temp = head;
        for( int i = 0; i < size; ++i ) {
            std::cout << temp->data << "-->";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head;
    int size;
};

int main() {

    CircularSinglyLinkedList cl;
    std::cout << "InsertAtEnd( 1 ): " << std::endl;
    cl.insertAtEnd( 1 );
    std::cout << "InsertAtEnd( 2 ): " << std::endl;
    cl.insertAtEnd( 2 );
    std::cout << "InsertAtEnd( 4 ): " << std::endl;
    cl.insertAtEnd( 4 );
    std::cout << "InsertAtEnd( 5 ): " << std::endl;
    cl.insertAtEnd( 5 );
    cl.display();

    system( "pause" );
    return 0;
}