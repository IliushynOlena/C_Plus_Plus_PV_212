#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node(int value, Node* next) :value(value), next(next) {}
  
};

class List
{
private:
    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(int value)
    {
        Node* newNode = new Node(value, head);//address
        //newNode->value = value;
        //newNode->next = head;
        head = newNode;;//address
    }
    void PrintList()const
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
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
        Node* newNode = new Node(value, nullptr);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;//nullptr

            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }     
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
  /*  for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }
    l.PrintList();
    l.AddToTail(100);
    l.AddToTail(200);*/
    l.AddToTail(300);
    l.PrintList();
    cout << "Element by pos 3 : " << l.GetElement(3) << endl;
    l.DeleteFromTail();
  /*  l.DeleteFromTail();
    l.DeleteFromTail();*/
    l.PrintList();
}

