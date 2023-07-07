#include <iostream>
using namespace std;
template<class T_data>
class List
{
private:
    struct Node
    {
        Node* prev;
        T_data value;
        Node* next;
        Node(Node* prev, T_data value, Node* next) :prev(prev), value(value), next(next) {}
    };

    Node* head;
    Node* tail;
    int size;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    List(const List &other)
    {
        for (Node* current = other.head; current != nullptr; current = current->next)
        {
            this->AddToTail(current->value);
        }
    }
    void Clear()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    List& operator = (const List& other)
    {
        Clear();
        for (Node* current = other.head; current != nullptr; current = current->next)
        {
            this->AddToTail(current->value);
        }
        return *this;
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    void AddToHead(T_data value)
    {
        Node* newNode = new Node(nullptr, value, head);//address

        if (IsEmpty())
        {
            head = tail = newNode;
        }
        head->prev = newNode;
        head = newNode;;//address
        size++;
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
            cout << current->value << " ";//value -> 
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
    void AddToTail(T_data value)
    {
        Node* newNode = new Node(tail, value, nullptr);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {         
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    T_data GetElement(int pos)
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
    T_data operator[](int pos)
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
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        size--;
    }
    void DeleteFromHead()
    {
        if (IsEmpty()) return;
        
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node* nodeToDelete = head->next;
            delete head;
            head = nodeToDelete;
        }
        size--;
    }
    int GetLength()
    {
        return size;
    }
    void DeleteByPosition(int pos)
    {
        if (pos < 1 || pos > size)return;
        else if (pos == 1)
        {
            DeleteFromHead();
        }
        else if (pos == size)
        {
            DeleteFromTail();
        }
        else
        {
            Node* current = nullptr;// = head;

            if (pos <= size / 2)
            {
                current = head;
                for (int i = 1; i < pos; i++)
                {
                    current = current->next;
                }
            }
            else
            {
                current = tail;
                for (int i = size; i >  pos; i--)
                {
                    current = current->prev;
                }
            }           
            current->next->prev = current->prev;
            current->prev->next = current->next;
            delete current;
            size--;
        }      
      
    }
};

struct Vagon
{
	int number_Vagony;// номер вагону
	int amount_Of_Pasanger_Place;// кількість місць
	int amountPasangers;// кількість пасажирів
	Vagon() :number_Vagony(0), amount_Of_Pasanger_Place(0), amountPasangers(0) {}
	Vagon(int num, int places)
	{
		number_Vagony = num;
		amount_Of_Pasanger_Place = places;
		amountPasangers = 0;
	}
	Vagon(int n, int p, int pass) :number_Vagony(n), amount_Of_Pasanger_Place(p), amountPasangers(pass) {}
	void Print()
	{
		cout << "Number : " << number_Vagony << endl;
		cout << "amount_Of_Pasanger_Place : " << amount_Of_Pasanger_Place << endl;
		cout << "amountPasangers : " << amountPasangers << endl;
	}
};
ostream& operator << (ostream& out, const Vagon& other)
{
    out << "Number : " << other.number_Vagony << endl;
    out << "amount_Of_Pasanger_Place : " << other.amount_Of_Pasanger_Place << endl;
    out << "amountPasangers : " << other.amountPasangers << endl;
    return out;
}
class Train
{
	string model;// модель
	int amount_of_vagons;// кількість вагонів
	List<Vagon> vagons;
public:
	Train()
	{
		model = "no model";
		amount_of_vagons = 0;
	}
	Train(string model)// В класі потяг оголосити дефолтний конструктор і перезавантажений конструктор.
	{
		this->model = model;
		this->amount_of_vagons = 0;
	}
	Train(const Train& other):vagons(vagons)
	{
		this->model = other.model;
		this->amount_of_vagons = other.amount_of_vagons;
        //this->vagons = other.vagons;//operator =		
	}
	void Show()//Реалізувати метод Show()
	{
		cout << "Name Train : " << model << endl;
		cout << "Number of wagons : " << amount_of_vagons << endl;
		vagons.PrintList();

	}
    void Add_VagonToTail(Vagon v)// Реалізувати метод додавання вагону до динамічного масиву
    {
        vagons.AddToTail(v);
        amount_of_vagons++;
    }
    void AddVagonToHead()
    {

    }
    void DeleteVagonFromHead();
    void DeleteVagonFromTail();
	
    
	
};


int main()
{
  /*  Train train("Tom");
    train.Add_VagonToTail(Vagon{ 1,20,3 });
    train.Add_VagonToTail(Vagon{ 2,10,7 });
    train.Add_VagonToTail(Vagon{ 3,15,12 });
    train.Add_VagonToTail(Vagon{ 4,10,8 });
    train.Add_VagonToTail(Vagon{ 5,25,24 });
    train.Show();

    Train newTrain(train);
    newTrain.Show();


    newTrain = train;*/

    List<int> l;
      for (int i = 0; i < 10; i++)
      {
          l.AddToHead(i);
      }
      l.PrintList();
      cout << "Length : " << l.GetLength() << endl;
      l.DeleteByPosition(3);
      l.PrintList();
      cout << "Length : " << l.GetLength() << endl;
      l.DeleteByPosition(1);
      l.PrintList();
      cout << "Length : " << l.GetLength() << endl;
      l.DeleteByPosition(8);
      l.PrintList();
    //  l.AddToTail(100);
    //  l.AddToTail(200);
    //l.AddToTail(300);
    //l.AddToTail(400);
    //l.AddToTail(500);
    //l.PrintList();
    ////cout << "Element by pos 3 : " << l.GetElement(3) << endl;
    ////cout << "Element by pos 5 : " << l[5] << endl;
    //l.DeleteFromTail();
    //l.DeleteFromTail();
    //l.DeleteFromTail();
    //l.PrintList();
}

