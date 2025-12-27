// Doubly Circular Linked List (DoublyCL)
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
//      data  - Stores integer data
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
// Class Name  : DoublyCL
// Description : Implements Doubly Circular Linked List
//
////////////////////////////////////////////////////////////////////////
class DoublyCL
{
    private:
        PNODE first;                // Head pointer
        PNODE last;                 // Tail pointer
        int iCount;                 // Node counter

    public:
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Constructor Name : DoublyCL
        //  Description      : Initializes an empty doubly circular linked list.
        //  Input            : void
        //  Output           : Creates list with first and last as NULL
        //  Author           : Vivek Bhauraj Gautam
        //  Date             : 27/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        DoublyCL()
        {
            cout<<"Object of DoublyCL get created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : Display
        //  Description   : Displays all elements of the doubly circular linked list.
        //  Input         : void
        //  Output        : Prints all node data on screen in circular manner
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 27/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void Display()
        {
            PNODE temp = NULL;
            temp = first;

            if(first == NULL && last == NULL)           // LL is empty  IMP
            {
                cout<<"Linked list is emplty \n ";
                return;
            }

            cout<<" <=> ";

            do
            {
                cout<<"| "<<temp->data<<" | <=> ";
                temp = temp->next;

            }while(temp != last->next);

            cout<<"\n";
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : Count
        //  Description   : Returns total number of nodes present in linked list.
        //  Input         : void
        //  Output        : Integer count of nodes
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 27/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        int Count()
        {
            return this->iCount;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : InsertFirst
        //  Description   : Inserts a new node at the beginning of doubly circular linked list.
        //  Input         : int no → Data to be inserted
        //  Output        : Modifies list by adding node at first position
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 27/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new (NODE);
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;
            }
            else 
            {
                newn->next = first;
                first->prev = newn;
                first = newn;
            }

            last->next = first;
            first->prev = last;

            iCount++;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : InsertLast
        //  Description   : Inserts a new node at the end of doubly circular linked list.
        //  Input         : int no → Data to be inserted
        //  Output        : Modifies list by adding node at last position
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 27/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new (NODE);
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;
            }
            else 
            {
                newn->prev = last;
                last->next = newn;
                last = newn;
            }

            last->next = first;
            first->prev = last;

            iCount++;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : InsertAtPos
        //  Description   : Inserts a new node at a specific position in doubly circular linked list.
        //  Input         : int no  → Data to be inserted
        //                  int pos → Position where node is to be inserted
        //  Output        : Modifies list by inserting node at given position
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 27/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void InsertAtPos(int no,int pos)
        {}

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : DeleteFirst
        //  Description   : Deletes the first node of doubly circular linked list.
        //  Input         : void
        //  Output        : Removes first node and frees its memory
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 27/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void DeleteFirst()
        {}

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : DeleteLast
        //  Description   : Deletes the last node of doubly circular linked list.
        //  Input         : void
        //  Output        : Removes last node and frees its memory
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 27/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void DeleteLast()
        {}

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : DeleteAtPos
        //  Description   : Deletes node from a specific position in doubly circular linked list.
        //  Input         : int pos → Position of node to be deleted
        //  Output        : Removes node from given position and frees its memory
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 27/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void DeleteAtPos(int pos)
        {}
};

////////////////////////////////////////////////////////////////////////
//
// Entry Point Function : main
// Description          : Demonstrates operations on Doubly Circular Linked List
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
