//#include <iostream>
//using namespace std;
//
//class Singleton
//{
//    static Singleton* p_instance;
//    Singleton() {}
//    Singleton(const Singleton& other) = delete;
//    Singleton& operator=(const Singleton& other) = delete;
//public:
//    
//    static Singleton* GetInstance()
//    {
//        if (p_instance == nullptr)
//        {
//            p_instance = new Singleton();
//        }
//        return p_instance;
//    }
//    void Log(string msg)
//    {
//        cout << msg << endl;
//    }
//
//};
//Singleton* Singleton::p_instance = nullptr;
//int main()
//{
//    //Singleton s;
//    Singleton *s = Singleton::GetInstance();
//    s->Log("Hello");
//    Singleton *s1 = Singleton::GetInstance();
//    s1->Log("Insert was new user at 21:59 PM");
//    Singleton::GetInstance()->Log("user Delete visual studio ");
//    Singleton::GetInstance()->Log("user download Fortnight ");
//    Singleton::GetInstance()->Log("user filed game");
//
//   /* Singleton s;   s.Log("Hello");
//    Singleton s1;  s1.Log("world");
//    Singleton s2;  s2.Log("Bye");
//    Singleton s3;  s3.Log("Friend");
//    Singleton s4;  s4.Log("Sun");
//    Singleton s5;  s5.Log("Hello");*/
//}
//
