#include <iostream>
using namespace std;

//class Stack
//{
//    enum { EMPTY = -1, FULL = 9 };
//    int arr[FULL + 1];//10
//    int topIndex;
//public:
//    Stack()
//    {
//        topIndex = EMPTY;
//    }
//    ~Stack() = default;
//    Stack(const Stack& other) = delete;
//
//    bool IsFull()const
//    {
//       return topIndex == FULL;
//    }
//    bool Push(int elem)
//    {
//        if (!IsFull())
//        {
//            arr[++topIndex] = elem;
//            return true;
//        }
//        return false;
//    }
//    bool IsEmpty()const
//    {
//        return topIndex == EMPTY;
//    }
//    int Pop()
//    {
//        if (!IsEmpty())
//            return arr[topIndex--];
//    }
//    int GetCount()const
//    {
//        return topIndex + 1;
//    }
//    void Clear()
//    {
//        topIndex = EMPTY;
//    }
//    int Peek()const
//    {
//        if (!IsEmpty())
//            return arr[topIndex];
//    }
//    void Print()
//    {
//        for (int i = 0; i <= topIndex; i++)
//        {
//            cout << arr[i] << " ";
//        }
//    }
//};

class Stack
{
    enum {EMPTY = -1};
    int size;//5000
    int* arr;
    int top;
public:
    Stack() = delete;
    Stack(int size):size(size)
    {
        arr = new int[size];
        top = EMPTY;
    }
    bool IsFull()const
    {
        return top == size - 1;
    }
    bool Push(int elem)
    {
        if (!IsFull())
        {
            arr[++top] = elem;
            return true;
        }
        return false;
    }
    bool IsEmpty()const
    {
        return top == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
            return arr[top--];
    }
    int Peek()const
    {
        if (!IsEmpty())
            return arr[top];
    }
    int GetCount()const
    {
        return top + 1;
    }
    void Clear()
    {
        top = EMPTY;
    }
    ~Stack()
    {
        delete[]arr;
    }

};

bool IsValidCode(string code)
{
    Stack stack(15);
    for (char symbol : code)
    {
        if (symbol == '{')
            stack.Push(1);
        if (symbol == '}')
        {
            if (stack.IsEmpty())return false;
            stack.Pop();
        }
    }
    return stack.IsEmpty();
}

int main()
{
    string code = "class Stack{ Stack({{{) void Print(){ for () { if(){}}}};";

    if (IsValidCode(code))
        cout << "Code is valid" << endl;
    else
        cout << "Code is invalid" << endl;


    Stack st(15);
    cout << "Count of element in Stack " << st.GetCount() << endl;
    st.Push(33);
    st.Push(12);
    st.Push(4);
    st.Push(8);
    st.Push(24);
    cout << "Count of element in Stack " << st.GetCount() << endl;
    //st.Print();
    cout << "Pop element : " << st.Pop() << endl;
    while (!st.IsEmpty())
    {
        cout << "Pop element : " << st.Pop() << endl;
    }
    cout << "Count of element in Stack " << st.GetCount() << endl;
    Stack st2(100);
    st2.Push(111);
    /*
    Stack st;
    st.Push(56);
    cout << "Count of element in Stack " << st.GetCount() << endl;
    st.Push(33);
    st.Push(12);
    st.Push(4);
    st.Push(8);
    st.Push(24);
    cout << "Count of element in Stack " << st.GetCount() << endl;
    st.Print();
    cout << "Pop element : " << st.Pop() << endl;
    while (!st.IsEmpty())
    {
         cout << "Pop element : " << st.Pop() << endl;
    }
    cout << "Count of element in Stack " << st.GetCount() << endl;
    */
}

