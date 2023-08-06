#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

struct Deque
{

    Node *head;
    Node *tail;

    Deque()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void push_front(int data)
    {
        if (this->isEmpty())
        {
            head = new Node(data);
            tail = head;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void push_back(int data)
    {
        if (this->isEmpty())
        {
            head = new Node(data);
            tail = head;
        }
        else
        {
            Node *temp = new Node(data);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    void pop_front()
    {
        if (this->isEmpty())
        {
            return;
        }
        if (tail == head)
        { // only one element
            delete (tail);

            tail = nullptr;
            head = nullptr;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete (temp);
    }
    void pop_back()
    {
        if (this->isEmpty())
        {
            return;
        }
        if (tail == head)
        { // only one element
            delete (tail);
            this->tail = nullptr;
            this->head = nullptr;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete (temp);
    }
    int front()
    {
        if (this->isEmpty())
            return -1;
        return head->data;
    }
    int back()
    {
        if (this->isEmpty())
            return -1;
        return tail->data;
    }
    bool isEmpty()
    {
        if (tail == head && head == nullptr)
            return true;
        return false;
    }

    void printDeque()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{

    Deque deque;

    // Checking isEmpty on an empty deque
    cout << "Is deque empty? " << (deque.isEmpty() ? "Yes" : "No") << endl;

    // Adding elements to the front of the deque
    deque.push_front(3);
    deque.push_front(2);
    deque.push_front(1);

    cout << "Deque after pushing elements to the front: ";
    deque.printDeque(); // Output: 1 2 3

    // Adding elements to the back of the deque
    deque.push_back(4);
    deque.push_back(5);

    cout << "Deque after pushing elements to the back: ";
    deque.printDeque(); // Output: 1 2 3 4 5

    // Getting the front and back elements
    cout << "Front element: " << deque.front() << endl; // Output: 1
    cout << "Back element: " << deque.back() << endl;   // Output: 5

    // Removing elements from the front and back of the deque
    deque.pop_front();
    deque.pop_back();

    cout << "Deque after popping elements from front and back: ";
    deque.printDeque(); // Output: 2 3 4

    // Checking isEmpty after removing elements
    cout << "Is deque empty? " << (deque.isEmpty() ? "Yes" : "No") << endl; // Output: No

    deque.printDeque();
    // Removing the last elements
    deque.pop_front();
    deque.pop_back();
    deque.pop_front();

    cout << "Deque after popping all elements: ";
    deque.printDeque(); // Output: (empty line)

    // Checking isEmpty on an empty deque
    cout << "Is deque empty? " << (deque.isEmpty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}