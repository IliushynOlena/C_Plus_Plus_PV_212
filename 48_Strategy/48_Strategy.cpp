﻿#include <iostream>
#include <string>
using namespace std;
// Иерархия классов, определяющая алгоритмы сжатия файлов
class Compression
{
public:
    virtual ~Compression() {}
    virtual void compress(const string& file) = 0;
};

class ZIP_Compression : public Compression
{
public:
    void compress(const string& file) {
        cout << "ZIP compression" << endl;
    }
};

class ARJ_Compression : public Compression
{
public:
    void compress(const string& file) {
        cout << "ARJ compression" << endl;
    }
};

class RAR_Compression : public Compression
{
public:
    void compress(const string& file) {
        cout << "RAR compression" << endl;
    }
};


// Класс для использования
class Compressor
{
private:
    Compression* p;
public:
    Compressor(Compression* comp) : p(comp) {}
    ~Compressor() { delete p; }
    void compress(const string& file) {
        p->compress(file);
    }

    void SetStrategy(Compression* new_p)
    {
        delete p;
        p = new_p;
    }

};


int main()
{
    Compressor p = Compressor(new ZIP_Compression);
    p.compress("file.txt");

    p.SetStrategy(new RAR_Compression);
    p.compress("file.txt");

    p.SetStrategy(new ARJ_Compression());
    p.compress("file.txt");


    return 0;
}
