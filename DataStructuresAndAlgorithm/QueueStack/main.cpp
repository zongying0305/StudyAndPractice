#include <iostream>
#include <stack>

class Queue {
public:
    void enQueue( int data ) {
        s1.push( data );
    }

    void deQueue() {
        if ( s1.empty() == true && s2.empty() == true ) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        if ( s2.empty() == true ) {
            while ( s1.empty() == false ) {
                s2.push( s1.top() );
                s1.pop();
            }
        }

        s2.pop();
    }

    int peek() {
        if ( s2.empty() == true ) {
            while ( s1.empty() == false ) {
                s2.push( s1.top() );
                s1.pop();
            }
        }

        return s2.top();
    }

private:
    std::stack<int> s1;
    std::stack<int> s2;
};

int main() {

    Queue q;
    std::cout << "EnQueue( 10 ):" << std::endl;
    q.enQueue( 10 );
    std::cout << "EnQueue( 20 ):" << std::endl;
    q.enQueue( 20 );
    std::cout << "EnQueue( 30 ):" << std::endl;
    q.enQueue( 30 );
    std::cout << "EnQueue( 40 ):" << std::endl;
    q.enQueue( 40 );

    std::cout << "peek:" << q.peek() << std::endl;

    std::cout << "DeQueue():" << std::endl;
    q.deQueue();
    std::cout << "peek:" << q.peek() << std::endl;


    std::cout << "DeQueue():" << std::endl;
    q.deQueue();
    std::cout << "peek:" << q.peek() << std::endl;

    std::cout << "EnQueue( 100 ):" << std::endl;
    q.enQueue( 100 );

    std::cout << "peek:" << q.peek() << std::endl;

    system( "pause" );
    return 0;
}