//#include <iostream>
//using namespace std;
//
//class User
//{
//public:
//    virtual void Info() = 0;
//};
//
//class Admin : public User
//{
//public:
//    void Info()override
//    {
//        cout << "I'm admin" << endl;
//    }
//};
//class Manager : public User
//{
//public:
//    void Info()override
//    {
//        cout << "I'm manager" << endl;
//    }
//};
//class Guest : public User
//{
//public:
//    void Info()override
//    {
//        cout << "I'm guest" << endl;
//    }
//};
//
//enum UserTypes{ ADMIN, MANAGER, GUEST };
//UserTypes ReadUserTypeFromFile()
//{
//    return UserTypes::MANAGER;
//}
//
//class UserFactory
//{
//public:
//    User* CreateUser(UserTypes code)
//    {
//        switch (code)
//        {
//        case ADMIN: return new Admin();
//            break;
//        case MANAGER:return new Manager();
//            break;
//        case GUEST:return new Guest();
//            break;
//
//        }      
//    }
//};
////0 - Admin, 1 - Manager, 2 - Guest
////int ReadUserTypeFromFile()
////{
////    return 2;
////}
////
////class UserFactory
////{
////public:
////    User* CreateUser(int code)
////    {
////        if (code == 0)
////        {
////            return new Admin();
////        }
////        if (code == 1)
////        {
////            return new Manager();
////        }
////        if (code == 2)
////        {
////            return new Guest();
////        }
////    }
////};
//
//int main()
//{
//    UserFactory factoryMethod;
//    //int code = ReadUserTypeFromFile();
//    UserTypes code = ReadUserTypeFromFile();
//
//    User * user = factoryMethod.CreateUser(code);
//
//    user->Info();
//
//    delete user;
//    
//}
