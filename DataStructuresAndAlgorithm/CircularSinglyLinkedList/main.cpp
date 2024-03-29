/*
    This is a circular singly linked list implementation.

    A circular singly linked list is a lot like a regular singly linked list,
    except the last node links back to the first node, AKA the head.
*/

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

class CircularSinglyLinkedList {
public:
    CircularSinglyLinkedList() {
        head = nullptr;
        size = 0;
    }

    ~CircularSinglyLinkedList() {
        Node* temp = head;
        for ( int i = 0; i < size; ++i ) {
            head = head->next;
            if ( temp != nullptr )
                delete temp;
            temp = head;
        }
    }

    void insertAtEnd( int data ) {
        Node* newNode = new Node( data );
        if ( head == nullptr ) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;
            for ( int i = 0; i < size - 1; ++i ) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        ++size;
    }

    void insertAtBeg( int data ) {
        Node* newNode = new Node( data );
        if ( head == nullptr ) {
            head = newNode;
            newNode->next = head;
        }
        else {
            newNode->next = head;

            Node* temp = head;
            for ( int i = 0; i < size - 1; ++i ) {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        }
        ++size;
    }

    void insertAtIndex( int data, int index ) {
        if ( index < 0 ) {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        Node* newNode = new Node( data );
        if ( index == 0 ) {
            head = newNode;
            newNode->next = head;
            ++size;
        }
        else {
            Node* temp = head;
            for ( int i = 0; i < index - 1; ++i ) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            ++size;
        }
    }

    void deleteAtEnd() {
        if ( head == nullptr ) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        else if ( size == 1 ) {
            delete head;
            head = nullptr;
            --size;
        }
        else {
            Node* temp = head;
            for ( int i = 0; i < size - 2; ++i ) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = head;
            --size;
        }
    }

    void deleteAtBeg() {
        if ( size == 0 ) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        else if ( size == 1 ) {
            delete head;
            head = nullptr;
            --size;
        }
        else {
            Node* temp = head;
            for ( int i = 0; i < size - 1; ++i ) {
                temp = temp->next;
            }
            head = head->next;
            delete temp->next;
            temp->next = head;
            --size;
        }
    }

    void deleteAtIndex( int index ) {
        if ( index < 0 ) {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        if ( size == 0 ) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        else if ( size == 1 ) {
            delete head;
            head = nullptr;
            --size;
        }
        else {
            Node* temp = head;
            for ( int i = 0; i < index - 1; ++i )
            {
                temp = temp->next;
            }
            Node* next = temp->next->next;
            delete temp->next;
            temp->next = next;
            --size;
        }
    }

    void display() {
        if ( size == 0 ) {
            std::cout << "List is empty" << std::endl;
        }

        Node* temp = head;
        for ( int i = 0; i < size; ++i ) {
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

    std::cout << "InsertAtBeg( 0 ): " << std::endl;
    cl.insertAtBeg( 0 );
    cl.display();

    std::cout << "DeleteAtEnd(): " << std::endl;
    cl.deleteAtEnd();
    cl.display();

    std::cout << "DeleteAtBeg(): " << std::endl;
    cl.deleteAtBeg();
    cl.display();

    std::cout << "InsertAtIndex( 3, 2 )" << std::endl;
    cl.insertAtIndex( 3, 2 );
    cl.display();

    std::cout << "DeleteAtIndex( 1 )" << std::endl;
    cl.deleteAtIndex( 1 );
    cl.display();

    system( "pause" );
    return 0;
}