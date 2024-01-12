/*
we consider a node with two properties
1. Data(now integer)
2. link containing the address of the other node that it points.
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

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList() {
        Node* temp = head;
        for ( int i = 0; i < size; ++i ) {
            head = head->next;
            if ( temp != nullptr )
                delete temp;
            temp = head;
        }
    }

    void append( int element ) {
        Node* newNode = new Node( element );

        if ( head == nullptr ) {
            head = newNode;
            tail = newNode;
            ++size;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            ++size;
        }
    }

    void preAppend( int element ) {
        Node* newNode = new Node( element );

        if ( head == nullptr ) {
            head = newNode;
            tail = newNode;
            ++size;
        }
        else {
            newNode->next = head;
            head = newNode;
            ++size;
        }
    }

    void insertNode( int element, int pos ) {
        if ( pos < 0 ) {
            std::cout << "Invalid pos" << std::endl;
        }
        else if ( pos == 0 ) {
            preAppend( element );
        }
        else if ( pos >= size ) {
            append( element );
        }
        else {
            Node* prev = head;
            for ( int i = 0; i < pos - 1; i++ )
            {
                prev = prev->next;
            }

            Node* newNode = new Node( element );
            newNode->next = prev->next;
            prev->next = newNode;

            ++size;
        }
    }

    void removeNode( int pos ) {
        if ( pos < 0 || pos >= size ) {
            std::cout << "Invalid pos" << std::endl;
        }
        else if ( pos == 0 ) {
            Node* tmp = head;
            head = head->next;
            free( tmp );
            --size;
        }
        else {
            Node* prev = head;
            for ( int i = 0; i < pos - 1; i++ )
            {
                prev = prev->next;
            }

            Node* tmp = prev->next;
            prev->next = tmp->next;
            tail = prev;
            free( tmp );
            --size;
        }
    }

    int get( int pos ) {
        if ( pos < 0 || pos >= size ) {
            std::cout << "Invalid pos" << std::endl;
            return -1;
        }
        else
        {
            Node* tmp = head;
            for ( int i = 0; i < pos; i++ )
            {
                tmp = tmp->next;
            }
            return tmp->data;
        }
    }

    int find( int element ) {
        Node* tmp = head;
        for ( int i = 0; i < size; ++i )
        {
            if ( tmp->data == element ) {
                return i;
            }
            tmp = tmp->next;
        }
        std::cout << "Element not found" << std::endl;
        return -1;
    }

    void reverse() {
        if ( size <= 1 ) {
            return;
        }

        Node* previous = nullptr;
        Node* current = head;
        Node* next = head->next;
        for ( int i = 0; i < size - 1; ++i ) {
            current->next = previous;

            previous = current;
            current = next;
            next = next->next;
        }
        current->next = previous;

        tail = head;
        head = current;
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
    Node* tail;
    int size;
};

int main() {

    LinkedList l;
    std::cout << "Appending Node(2):" << std::endl;
    l.append( 2 );
    std::cout << "Appending Node(4):" << std::endl;
    l.append( 4 );
    std::cout << "Appending Node(6):" << std::endl;
    l.append( 6 );
    std::cout << "Appending Node(8):" << std::endl;
    l.append( 8 );
    std::cout << "Appending Node(10):" << std::endl;
    l.append( 10 );
    l.display();

    std::cout << "Inserting Node(3, 2):" << std::endl;
    l.insertNode( 3, 2 );
    l.display();
    std::cout << "Inserting Node(1, 0):" << std::endl;
    l.insertNode( 1, 0 );
    l.display();

    std::cout << "Delete Node(4):" << std::endl;
    l.removeNode( 4 );
    l.display();
    std::cout << "Delete Node(1):" << std::endl;
    l.removeNode( 1 );
    l.display();
    std::cout << "Delete Node(5):" << std::endl;
    l.removeNode( 5 );
    l.display();

    std::cout << "Get Node: 2" << std::endl;
    std::cout << l.get( 2 ) << std::endl;
    std::cout << "Get Node: 7" << std::endl;
    std::cout << l.get( 7 ) << std::endl;

    std::cout << "Find Node 8:" << std::endl;
    std::cout << l.find( 8 ) << std::endl;
    std::cout << "Find Node 9:" << std::endl;
    std::cout << l.find( 9 ) << std::endl;

    std::cout << "Reversing List" << std::endl;
    l.reverse();
    l.display();

    system( "pause" );
    return 0;
}