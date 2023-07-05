#include <iostream>
using namespace std;

struct Node
{
    Node* prev;
    int value;
    Node* next;
    Node(Node *prev, int value, Node* next) :prev(prev), value(value), next(next) {}

};

class List
{
private:
    Node* head;
    Node* tail;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    void AddToHead(int value)
    {
        Node* newNode = new Node(nullptr, value, head);//address

        head->prev = newNode;
        head = newNode;;//address
    }
    void PrintList()const
    {
        //Node* current = head;//int i = 0;
        //while (current != nullptr)// i < 10
        //{
        //    cout << current->value << " ";
        //    current = current->next;//i++;
        //}

        for (Node* current = head; current != nullptr; current = current->next)
        {
            cout << current->value << " ";
        }
        cout << endl;
    }
    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void AddToTail(int value)
    {
    //    Node* newNode = new Node(value, nullptr);

    //    if (head == nullptr)
    //    {
    //        head = newNode;
    //    }
    //    else
    //    {
    //        Node* current = head;//nullptr

    //        while (current->next != nullptr)
    //        {
    //            current = current->next;
    //        }
    //        current->next = newNode;
    //    }
    }
    int GetElement(int pos)
    {
        Node* current = head;
        //index
       /* for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        return current->value;*/

        //numeration
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    int operator[](int pos)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    void DeleteFromTail()
    {
        if (head == nullptr)return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* current = head;//300 : nullptr
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }


    }
};
int main()
{
    List l;
      for (int i = 0; i < 10; i++)
      {
          l.AddToHead(i);
      }
      l.PrintList();
     /* l.AddToTail(100);
      l.AddToTail(200);*/
    //l.AddToTail(300);
    //l.PrintList();
    //cout << "Element by pos 3 : " << l.GetElement(3) << endl;
    //cout << "Element by pos 5 : " << l[5] << endl;
    //l.DeleteFromTail();
    ///*  l.DeleteFromTail();
    //  l.DeleteFromTail();*/
    //l.PrintList();
}

