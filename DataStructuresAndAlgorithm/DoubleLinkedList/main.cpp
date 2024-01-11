/* This program is for implementing doubly linked list
 * Doubly linked list is a special type of Linked List which
 * is has two links for a given node hence the list can be
 * traversed in two different direction.
*/

#include <iostream>

class Node {
public:
    Node( int data ) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    int data;
    Node* next;
    Node* prev;
};

class DoubleLindedList {
public:
    DoubleLindedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    ~DoubleLindedList() {
        if ( size > 0 ) {
            Node* temp = head->next;
            for ( int i = 0; i < size - 1; ++i ) {
                delete head;
                head = temp;
                temp = head->next;
            }
        }
    }

    void append( int data ) {
        Node* newNode = new Node( data );
        if ( size == 0 ) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    void preAppend( int data ) {
        Node* newNode = new Node( data );
        if ( size == 0 ) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }

    void insertTo( int data, int index ) {
        if ( index < 0 || index >= size ) {
            std::cout << "Invalid index." << std::endl;
            return;
        }
        else if ( index == 0 ) {
            preAppend( data );
        }
        else if ( index == size - 1 ) {
            append( data );
        }
        else {
            Node* temp = head;
            for ( int i = 0; i < index - 1; ++i ) {
                temp = temp->next;
            }

            Node* newNode = new Node( data );
            temp->next->prev = newNode;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            ++size;
        }
    }

    void removeElement( int index ) {
        if ( index < 0 || index >= size ) {
            std::cout << "Invalid index." << std::endl;
            return;
        }
        else if ( index == 0 ) {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            size--;
        }
        else if ( index == size - 1 ) {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            size--;
        }
        else {
            Node* temp = head;
            for ( int i = 0; i < index; ++i ) {
                temp = temp->next;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            --size;
        }
    }

    void reverseList() {
        Node* temp = nullptr;

        Node* current = head;
        for ( int i = 0; i < size; ++i ) {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;

            current = current->prev;
        }

        temp = head;
        head = tail;
        tail = temp;
    }

    void display() {
        if ( head == nullptr ) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        for ( int i = 0; i < size; ++i ) {
            std::cout << temp->data << "-->";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

private:
    int size;
    Node* head;
    Node* tail;
};

int main() {

    DoubleLindedList dl;
    std::cout << "Append( 2 ):" << std::endl;
    dl.append( 2 );
    std::cout << "Append( 1 ):" << std::endl;
    dl.append( 1 );
    std::cout << "Append( 3 ):" << std::endl;
    dl.append( 3 );
    std::cout << "Append( 4 ):" << std::endl;
    dl.append( 4 );
    std::cout << "Append( 5 ):" << std::endl;
    dl.append( 5 );
    dl.display();

    std::cout << "PreAppend( 99 ):" << std::endl;
    dl.preAppend( 99 );
    std::cout << "PreAppend( 200 ):" << std::endl;
    dl.preAppend( 200 );
    dl.display();

    std::cout << "InsertTo( 1000, 2 ):" << std::endl;
    dl.insertTo( 1000, 2 );
    std::cout << "InsertTo( 5000, 1 ):" << std::endl;
    dl.insertTo( 5000, 1 );
    dl.display();

    std::cout << "RemoveElement( 4 ):" << std::endl;
    dl.removeElement( 4 );
    dl.display();

    std::cout << "ReverseList():" << std::endl;
    dl.reverseList();
    dl.display();

    std::cout << "RemoveElement( 6 ):" << std::endl;
    dl.removeElement( 6 );
    dl.display();

    system( "pause" );
    return 0;
}