// ???

/* This program is based on the implementation of BST(binary search tree)
 * using linked list as our data-structure
 * now, the functions that BST can be introduced with are:
 * 1. Insert() this function let us construct the binary search tree with
 *    the fact that the left subtree values from the node should be less
 *    and the right subtree values should be greater the node
 * 2. lookup() this function let us return True or False if the given node
 *    exist or not.
 * 3. remove() let us remove a node Note: we should always maintain the
 *    constraints of the BST after removal (hence it may also required to
 *    reorder some node.)
*/

#include <iostream>
#include <stack>

class Node {
public:
    Node( int data ) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    int data;
    Node* right;
    Node* left;
};

class BinarySearchTree {
public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insertNode( int data ) {
        Node* newNode = new Node( data );
        if ( root == nullptr ) {
            root = newNode;
            return;
        }

        // find the position
        Node* parent = nullptr;
        Node* temp = root;
        while ( temp != nullptr ) {
            parent = temp;
            if ( data < temp->data )
                temp = temp->left;
            else
                temp = temp->right;
        }

        // insert
        if ( data < parent->data )
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    void removeNode( int data ) {
        if ( root == nullptr ) {
            std::cout << "Tree is empty" << std::endl;
            return;
        }

        // find the position
        Node* parent = nullptr;
        Node* target = root;
        while ( target != nullptr ) {
            if ( data < target->data ) {
                parent = target;
                target = target->left;
            }
            else if ( data > target->data ) {
                parent = target;
                target = target->right;
            }
            else {
                if ( target->left == nullptr && target->right == nullptr ) {
                    // delete the leaf
                    if ( parent->left == target )
                        parent->left = nullptr;
                    else
                        parent->right = nullptr;
                    delete target;
                    return;
                }
                else if ( target->left == nullptr || target->right == nullptr ) {
                    // delete the node with one child
                    if ( target->left != nullptr && data < parent->data )
                        parent->left = target->left;
                    else if ( target->left != nullptr && data > parent->data )
                        parent->right = target->left;
                    else if ( target->right != nullptr && data < parent->data )
                        parent->left = target->right;
                    else
                        parent->right = target->right;
                    delete target;
                    return;
                }
                else {
                    // delete the node with two child
                    Node* temp = target->right;
                    if ( temp->left == nullptr && temp->right == nullptr ) {
                        target->data = temp->data;
                        target->right = nullptr;
                    }
                    else if ( temp->left == nullptr && temp->right != nullptr ) {
                        target->data = temp->data;
                        target->right = temp->right;
                    }
                    else {
                        while ( temp->left != nullptr ) {
                            parent = temp;
                            temp = target->left;
                        }
                        target->data = temp->data;
                        parent->left = nullptr;
                    }
                    delete temp;
                    return;
                }
            }
        }

        std::cout << "Node not found" << std::endl;
    }

    // this display function uses in-order traversal left->root->right
    void display() {
        std::stack< Node* > s;
        Node* temp = root;

        while ( temp != nullptr || s.empty() == false() ) {
            while ( temp != nullptr ) {
                s.push( temp );
                temp = temp->left;
            }
            temp = s.top();
            std::cout << temp->data << " ";
            s.pop();

            temp = temp->right;
        }
        std::cout << std::endl;
    }
private:
    Node* root;
};

int main() {

    BinarySearchTree b;
    /*    20
         /  \
        10   30
       /    /  \
      1    25  40   tree structure */
    b.insertNode( 20 );
    b.insertNode( 10 );
    b.insertNode( 30 );
    b.insertNode( 25 );
    b.insertNode( 40 );
    b.insertNode( 1 );
    b.display();

    b.removeNode( 30 );
    b.display();

    system( "pause" );
    return 0;
}