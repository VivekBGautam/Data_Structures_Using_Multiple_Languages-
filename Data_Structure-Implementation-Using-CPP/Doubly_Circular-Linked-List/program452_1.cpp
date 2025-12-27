// -----------------------------------------------------------------------------
// File Name    : DoublyCL.cpp
// Description  : Implementation of Doubly Circular Linked List in C++
// Author       : Vivek Gautam
// Date         : 27-12-2025
// -----------------------------------------------------------------------------
//
// Doubly Circular Linked List:
// - Each node contains data, next pointer, and previous pointer
// - Last node's next points to first node
// - First node's previous points to last node
// - Traversal is possible in both forward and backward directions
//
// -----------------------------------------------------------------------------

#include<iostream>
using namespace std;

#pragma pack(1)

////////////////////////////////////////////////////////////////////////
//
// Structure Name : node
// Description    : Represents a node of Doubly Circular Linked List
// Members        :
//      data  - Stores integer value
//      next  - Pointer to next node
//      prev  - Pointer to previous node
//
////////////////////////////////////////////////////////////////////////
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

////////////////////////////////////////////////////////////////////////
//
// Class Name : DoublyCL
// Description: Implements operations on Doubly Circular Linked List
// Data Members:
//      first  - Pointer to first node (Head)
//      last   - Pointer to last node
//      iCount - Number of nodes present in linked list
//
////////////////////////////////////////////////////////////////////////
class DoublyCL
{
    private:
        PNODE first;                // Head of linked list
        PNODE last;                 // Last node of linked list
        int iCount;                 // Node counter

    public:
        ////////////////////////////////////////////////////////////////////////
        //
        // Constructor Name : DoublyCL
        // Description      : Initializes empty Doubly Circular Linked List
        //
        ////////////////////////////////////////////////////////////////////////
        DoublyCL()
        {
            cout<<"Object of DoublyCL get created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        ////////////////////////////////////////////////////////////////////////
        //
        // Function Name : Display
        // Description   : Displays all elements of Doubly Circular Linked List
        // Input         : None
        // Output        : Prints list elements
        //
        ////////////////////////////////////////////////////////////////////////
        void Display()
        {}

        ////////////////////////////////////////////////////////////////////////
        //
        // Function Name : Count
        // Description   : Returns total number of nodes in linked list
        // Input         : None
        // Output        : Integer (node count)
        //
        ////////////////////////////////////////////////////////////////////////
        int Count()
        {
            return this->iCount;
        }

        ////////////////////////////////////////////////////////////////////////
        //
        // Function Name : InsertFirst
        // Description   : Inserts new node at beginning of linked list
        // Input         : Integer value
        // Output        : None
        //
        ////////////////////////////////////////////////////////////////////////
        void InsertFirst(int no)
        {}

        ////////////////////////////////////////////////////////////////////////
        //
        // Function Name : InsertLast
        // Description   : Inserts new node at end of linked list
        // Input         : Integer value
        // Output        : None
        //
        ////////////////////////////////////////////////////////////////////////
        void InsertLast(int no)
        {}

        ////////////////////////////////////////////////////////////////////////
        //
        // Function Name : InsertAtPos
        // Description   : Inserts new node at specified position
        // Input         : Integer value, Position
        // Output        : None
        //
        ////////////////////////////////////////////////////////////////////////
        void InsertAtPos(int no,int pos)
        {}

        ////////////////////////////////////////////////////////////////////////
        //
        // Function Name : DeleteFirst
        // Description   : Deletes first node of linked list
        // Input         : None
        // Output        : None
        //
        ////////////////////////////////////////////////////////////////////////
        void DeleteFirst()
        {}

        ////////////////////////////////////////////////////////////////////////
        //
        // Function Name : DeleteLast
        // Description   : Deletes last node of linked list
        // Input         : None
        // Output        : None
        //
        ////////////////////////////////////////////////////////////////////////
        void DeleteLast()
        {}

        ////////////////////////////////////////////////////////////////////////
        //
        // Function Name : DeleteAtPos
        // Description   : Deletes node from specified position
        // Input         : Position
        // Output        : None
        //
        ////////////////////////////////////////////////////////////////////////
        void DeleteAtPos(int pos)
        {}
};

////////////////////////////////////////////////////////////////////////
//
// Entry Point Function : main
// Description          : Demonstrates usage of DoublyCL class
//
////////////////////////////////////////////////////////////////////////
int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteAtPos(4);
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    return 0;
}
