#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

template <class T>
class Node {
public:
    T* Data;
    Node** children;

    // Constructor
    Node( int numberOfChildren, T* Data ){
        this->Data = Data;
        // Allocate a C-Style array of Node**
        children = malloc( sizeof( Node* ) * numberOfChildren );
        // Then allocate the pointers for the children as well
        for ( int i = 0; i < numberOfChildren; i++ )
            children[i] = malloc( sizeof( Node ) );
    }

    // Destructor
    ~Node( ) {
        // Delete the pointers inside of the array
        for ( int i = 0; i < sizeof( children ) / sizeof( Node ); i++ )
            delete children[i];
        // Then delete the array
        delete[] children;
        // Then finally delete the pointer to whatever the node pointed to
        delete Data;
    }

};

#endif // NODE_HPP_INCLUDED
