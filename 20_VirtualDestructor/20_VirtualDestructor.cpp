//#include <iostream>
//using namespace std;
//
//class Student
//{
//    string name;
//    string spetialization;
//    int* marks;
//    int markCount;
//public:
//    Student() :name(""), spetialization(""), marks(nullptr), markCount(0) {}
//    Student(string name,string spetialization):name(name), spetialization(spetialization)
//    {
//        markCount = rand() % 10 + 1;
//        marks = new int[markCount];
//        for (int i = 0; i < markCount; i++)
//        {
//            marks[i] = rand() %5 + 8;//8-12
//        }
//    }
//    virtual void Print()const
//    {
//        cout << "\nName : " << name << endl;
//        cout << "Spetialization : " << spetialization << endl;
//        cout << "Marks : ";
//        for (int i = 0; i < markCount; i++)
//        {
//            cout << marks[i] << " ";
//        } 
//        cout << "\n_______________________" << endl;
//    }
//    virtual ~Student()
//    {
//        if (marks != nullptr)
//            delete[]marks;
//    }
//};
//class Aspirant: public Student
//{
//    string *subjects;
//    int countSubject;
//public:
//    Aspirant(string name, string spetialization, initializer_list<string> list) :
//        Student(name, spetialization) 
//    {
//        this->countSubject = list.size();
//        subjects = new string[countSubject];
//        int i = 0;
//        for (string s : list)
//        {
//            subjects[i] = s;
//            i++;
//        }
//    
//    }
//    void Print()const
//    {
//        Student::Print();
//        cout << "Subject : ";
//        for (int i = 0; i < countSubject; i++)
//        {
//            cout << subjects[i] << " ";
//        }
//    }
//    ~Aspirant() override
//    {
//        if (subjects != nullptr)
//            delete[]subjects;
//    }
//};
//
//int main()
//{
//    srand(time(0));
//   /* Student student("Petro","Programmer");
//    student.Print();
//
//    Aspirant aspirant("Petro Oldest", "Water Engineer", { "Recuperation","Math","Pump"});
//    aspirant.Print();*/
//
//    Student* groups[3]{
//        new Student("Petro","Programmer"),//constructor
//        new Aspirant("Petro Oldest", "Water Engineer", { "Recuperation","Math","Pump"}),//constructor
//        new Aspirant("Olya", "Design", { "UI/UX","Pattern","Main page"}),//constructor
//    };
//    for (int i = 0; i < 3; i++)
//    {
//        groups[i]->Print();
//        delete groups[i];//Destructor
//    }
//    
//}//Destructor
//
