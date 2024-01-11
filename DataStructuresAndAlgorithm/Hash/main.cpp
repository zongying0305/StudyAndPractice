#include <iostream>

// this is an example of open addressing

class HashNode {
public:
    HashNode( int key, int value ) {
        this->key = key;
        this->value = value;
    }
    int key;
    int value;
};

class HashTable {
public:
    HashTable() {
        table = new HashNode * [maxTableSize];
        memset( table, 0, sizeof( HashNode* ) * maxTableSize );
        for ( int i = 0; i < maxTableSize; ++i ) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for ( int i = 0; i < maxTableSize; ++i ) {
            if ( table[i] != nullptr )
                delete table[i];
            table[i] = nullptr;
        }

        if ( table != nullptr )
            delete[] table;
        table = nullptr;
    }

    int hashFunction( int key ) {
        return key % maxTableSize;
    }

    void insertElement( int key, int value ) {
        int h = hashFunction( key );
        while ( table[h] != nullptr && table[h]->key != key ) {
            h = hashFunction( h + 1 );
        }

        // if the key is already present then delete the (key, value) pair
        if ( table[h] != nullptr )
            delete table[h];

        table[h] = new HashNode( key, value );
    }

    void removeElement( int key ) {
        int h = hashFunction( key );
        if ( table[h] == nullptr ) {
            std::cout << "Element not found" << std::endl;
            return;
        }
        while ( table[h] != nullptr && table[h]->key != key ) {
            h = hashFunction( h + 1 );
        }
        delete table[h];
        table[h] = nullptr;
    }

    int get( int key ) {
        int h = hashFunction( key );
        while ( table[h] != nullptr && table[h]->key != key ) {
            h = hashFunction( h + 1 );
        }
        if ( table[h] == NULL ) {
            return -1;
        }
        return table[h]->value;
    }

    void display() {
        for ( int i = 0; i < maxTableSize; ++i ) {
            if ( table[i] != nullptr && table[i]->key != -1 ) {
                std::cout << table[i]->key << "->" << table[i]->value << std::endl;
            }
        }
        std::cout << std::endl;
    }

private:
    HashNode** table;
    const int maxTableSize = 32;
};

int main() {

    HashTable h;
    h.insertElement( 1, 1 );
    h.insertElement( 2, 2 );
    h.insertElement( 2, 3 );
    h.insertElement( 2, 8 );  // note then when displayed the value of key->2 should be only 8.
    h.insertElement( 12, 21 );
    h.display();

    std::cout << h.get( 2 );

    h.removeElement( 2 );
    h.display();

    system( "pause" );
    return 0;
}