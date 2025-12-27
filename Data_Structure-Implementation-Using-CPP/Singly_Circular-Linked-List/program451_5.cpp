// Singly Circular Linked List (Description Only – Reference Based)

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
//
// Structure Name : node
// Description    : Represents a node of Singly Circular Linked List
// Members        :
//      data  - Stores integer data
//      next  - Pointer to next node (last node points to first)
//
////////////////////////////////////////////////////////////////////////
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

////////////////////////////////////////////////////////////////////////
//
// Class Name  : SinglyCL
// Description : Implements Singly Circular Linked List
//
////////////////////////////////////////////////////////////////////////
class SinglyCL
{
    private:                        // IMPORTANT
        PNODE first;                // Head pointer
        PNODE last;                 // Tail pointer
        int iCount;                 // Node counter

    public:
        //////////////////////////////////////////////////////////////////////
        //
        // Constructor Name : SinglyCL
        // Description      : Initializes empty singly circular linked list
        //
        //////////////////////////////////////////////////////////////////////
        SinglyCL()
        {
            first = NULL;
            last = NULL;
            iCount = 0;
        }

        //////////////////////////////////////////////////////////////////////
        //
        // Function Name : Display
        // Description   : Displays all elements of the singly circular linked list
        // Input         : void
        // Output        : Prints node data
        //
        //////////////////////////////////////////////////////////////////////
        void Display()
        {
            if(first == NULL)
            {
                cout<<"Linked list is empty\n";
                return;
            }

            PNODE temp = first;

            do
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp->next;
            }while(temp != first);

            cout<<"Return to first node\n";
        }

        //////////////////////////////////////////////////////////////////////
        //
        // Function Name : Count
        // Description   : Returns total number of nodes present
        // Input         : void
        // Output        : Integer
        //
        //////////////////////////////////////////////////////////////////////
        int Count()
        {
            return iCount;
        }

        //////////////////////////////////////////////////////////////////////
        //
        // Function Name : InsertFirst
        // Description   : Inserts node at first position
        // Input         : int
        // Output        : Modified list
        //
        //////////////////////////////////////////////////////////////////////
        void InsertFirst(int no)
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if(first == NULL)
            {
                first = last = newn;
                last->next = first;
            }
            else
            {
                newn->next = first;
                first = newn;
                last->next = first;
            }

            iCount++;
        }

        //////////////////////////////////////////////////////////////////////
        //
        // Function Name : InsertLast
        // Description   : Inserts node at last position
        // Input         : int
        // Output        : Modified list
        //
        //////////////////////////////////////////////////////////////////////
        void InsertLast(int no)
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if(first == NULL)
            {
                first = last = newn;
                last->next = first;
            }
            else
            {
                last->next = newn;
                last = newn;
                last->next = first;
            }

            iCount++;
        }

        //////////////////////////////////////////////////////////////////////
        //
        // Function Name : InsertAtPos
        // Description   : Inserts node at specific position
        // Input         : int, int
        // Output        : Modified list
        //
        //////////////////////////////////////////////////////////////////////
        void InsertAtPos(int no, int pos)
        {
            if(pos < 1 || pos > iCount + 1)
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                PNODE newn = new NODE;
                newn->data = no;
                newn->next = NULL;

                PNODE temp = first;

                for(int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }

        //////////////////////////////////////////////////////////////////////
        //
        // Function Name : DeleteFirst
        // Description   : Deletes first node
        // Input         : void
        // Output        : Modified list
        //
        //////////////////////////////////////////////////////////////////////
        void DeleteFirst()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = last = NULL;
            }
            else
            {
                PNODE temp = first;
                first = first->next;
                delete temp;
                last->next = first;
            }

            iCount--;
        }

        //////////////////////////////////////////////////////////////////////
        //
        // Function Name : DeleteLast
        // Description   : Deletes last node
        // Input         : void
        // Output        : Modified list
        //
        //////////////////////////////////////////////////////////////////////
        void DeleteLast()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = last = NULL;
            }
            else
            {
                PNODE temp = first;

                while(temp->next != last)
                {
                    temp = temp->next;
                }

                delete last;
                last = temp;
                last->next = first;
            }

            iCount--;
        }

        //////////////////////////////////////////////////////////////////////
        //
        // Function Name : DeleteAtPos
        // Description   : Deletes node at specific position
        // Input         : int
        // Output        : Modified list
        //
        //////////////////////////////////////////////////////////////////////
        void DeleteAtPos(int pos)
        {
            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                PNODE temp = first;

                for(int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }

                PNODE target = temp->next;
                temp->next = target->next;
                delete target;

                iCount--;
            }
        }
};

////////////////////////////////////////////////////////////////////////
//
// Entry Point Function : main
// Description          : Demonstrates Singly Circular Linked List
//
////////////////////////////////////////////////////////////////////////
int main()
{
    SinglyCL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.Display();

    obj.InsertAtPos(105,4);
    obj.Display();

    obj.DeleteFirst();
    obj.Display();

    obj.DeleteLast();
    obj.Display();

    obj.DeleteAtPos(2);
    obj.Display();

    cout<<"Total nodes : "<<obj.Count()<<"\n";

    return 0;
}
