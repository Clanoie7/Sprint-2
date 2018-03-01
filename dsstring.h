#ifndef STRING
#define STRING
#include <iostream>
#include <cstring>
#include <fstream>
#include "dsvector.h"
using namespace std;

class String
{
private:
    char * text;
    int length;
public: 
    String();
    String(const char*);
    String(const String&);
    ~String();
    String& operator= (const char*);
    String& operator= (const String&);
    bool operator== (const char*) const;
    bool operator== (const String&) const;
    bool operator> (const String&) const;
    char& operator[] (const int);
    friend std::ostream& operator<< (std::ostream&, const String&);
    int getLength() const;
    String substring(int front, int chars);
    void dissect(char, Vector<String>&);
    int find(char delimiter, int start);
    void upper();
    void lower();
    char* cStr();
};

#endif
