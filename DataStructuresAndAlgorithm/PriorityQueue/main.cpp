/* Implementation of priority Queue using LinkedList
Begin
   class Priority_Queue has following functions:
   function enQueue() to insert items at priority queue with their priorities:
      1) If queue is empty insert data from the left end of the queue.
      2) If queue is having some nodes then insert the new node at the end of those nodes having priority
         same with the new node and also before all the nodes having priority lesser than the
         current priority of the new node.
      function removeElement() to delete items from queue.
   If queue is completely empty, print underflow otherwise delete the front element and update front.
End
*/

#include <iostream>

class Node {
public:
    Node( int data, int priority ) {
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
public:
    PriorityQueue() {
        first = nullptr;
    }

    void enQueue( int data, int priority ) {
        Node* newNode = new Node( data, priority );
        if ( first == nullptr || priority < first->priority ) {
            newNode->next = first;
            first = newNode;
            return;
        }

        Node* temp = first;
        while ( temp->next != nullptr && priority > temp->next->priority ) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deQueue() {
        if ( first == nullptr ) {
            std::cout << "Queue Underflow" << std::endl;
            return;
        }

        Node* temp = first;
        while ( temp->next->next != nullptr ) {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = nullptr;
    }

    void display() {
        if ( first == nullptr ) {
            std::cout << "Queue Underflow" << std::endl;
            return;
        }

        Node* temp = first;
        while ( temp != nullptr ) {
            std::cout << temp->priority << ": " << temp->data << "\t";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

private:
    Node* first;
};

int main() {

    PriorityQueue p;
    p.enQueue( 10, 3 );
    p.enQueue( 20, 2 );
    p.display();
    p.enQueue( 40, 1 );
    p.enQueue( 50, 4 );
    p.display();

    p.deQueue();
    p.display();

    system( "pause" );
    return 0;
}