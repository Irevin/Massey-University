// Name: Han Yu    ID:24008995
#include <iostream>
using namespace std;

// Creat Node Struct, which has index, value and a Node point to next
struct Node
{
    int index,value;
    Node* next;
};

// Add new node at the tail of the linked list
void AddNode(Node*& listpointer, int Index, int Value)
{
    Node* current = listpointer;
    if (current != NULL)
    {
        while (current->next != NULL)
            current = current->next;
    }

    Node* temp;
    temp = new Node;
    temp->index = Index;
    temp->value = Value;
    temp->next = NULL;

    if (current != NULL)
        current->next = temp;
    else
        listpointer = temp;
}

// Read linked link from users
void ReadLinkedList(Node*& listpointer)
{
    int number;
    cin >> number;

    for (int i = 0; i < number; ++i)
    {
        int index_tmp, value_tmp;
        cin >> index_tmp;
        cin >> value_tmp;
        if (value_tmp != 0)
        {
            AddNode(listpointer, index_tmp, value_tmp);
        }
    }
}

// Print linked list to terminal
void PrintLinkedList(Node* listpointer)
{
    while (listpointer)
    {
        cout << listpointer->index << " " << listpointer->value << " ";
        listpointer = listpointer->next;
    }
}
// Add sparse vector return node pointer
Node* AddSparseVector(Node* first, Node* second, int& count)
{
    Node* result=nullptr;
    while (first && second)
    {
        if (first->index < second->index)
        {
            AddNode(result, first->index, first->value);
            first = first->next;
            count++;
        }
        else if (second->index < first->index)
        {
            AddNode(result, second->index, second->value);
            second = second->next;
            count++;
        }
        else
        {
            if((first->value+second->value)!=0) // Note: if the value of first and second equal zero, it should not be added to linked list.
            {
                AddNode(result, first->index, first->value + second->value);
                count++;
            }
            first = first->next;
            second = second->next;
        }
    }
    while (first)
    {
        AddNode(result, first->index, first->value);
        first = first->next;
        count++;
    }
    while (second)
    {
        AddNode(result, second->index, second->value);
        second = second->next;
        count++;
    }
    return result;
}


// Deleting a linked list
void DeleteLinkedList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(void)
{
    Node *listptr1 = nullptr;
    Node *listptr2 = nullptr;
    int count = 0;

    // Read linked list
    ReadLinkedList(listptr1);
    ReadLinkedList(listptr2);

    // Calculate the add opearation
    Node* result = AddSparseVector(listptr1, listptr2, count);

    // Print linked list
    cout << count << " ";
    PrintLinkedList(result);

    // Delect lisked list
    DeleteLinkedList(listptr1);
    DeleteLinkedList(listptr2);
    DeleteLinkedList(result);
    return 0;
}
