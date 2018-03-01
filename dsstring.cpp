#include "dsstring.h"
#include "dsvector.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

String::String()
{
    text = nullptr;
    length = 0;
}

String::String(const char* cArr) //cstring
{
    if (strlen(cArr)==0) {
        text = nullptr;
        length = 0;
    }
    else {
        length = strlen(cArr);
        text = new char[length + 1];
        strcpy(text, cArr);
    }
}

String::String(const String& str)
{
    if (str.length==0) {
        text = nullptr;
        length = 0;
    }
    else {
        length = strlen(str.text);
        text = new char[length+1];
        strcpy(text,str.text);
    }
}

String::~String()
{
    delete[] text;
}

String& String::operator= (const char* cArr){
    if (this->text != cArr) {
        if ((unsigned)this->length!=strlen(cArr)) {     //resizes text
            delete[] this->text;
            length = strlen(cArr);
            text = new char[length+1];
        }
        strcpy(text,cArr);
    }
    else if (cArr != nullptr)
        strcpy(text,cArr);
    return *this;
}

String& String::operator= (const char* cArr)
{
    if (this->text != cArr) {
        if ((unsigned)this->length!=strlen(cArr)) {     //resizes text
            delete[] this->text;
            length = strlen(cArr);
            text = new char[length+1];
        }
        strcpy(text,cArr);
    }
    else if (cArr != nullptr)
        strcpy(text,cArr);
    return *this;
}

String& String::operator= (const String& str)
{
    if (this->text != str.text) {
        if (this->length!=str.length) {
            delete[] this->text;
            length = str.length;
            text = new char[length+1];
        }
        strcpy(text,str.text);
    }
    else if (text != nullptr)
        strcpy(text,str.text);
    return *this;
}

bool String::operator== (const char* cArr) const
{
    if(strcmp(this->text,cArr)==0)
        return true;
    else
        return false;
}

bool String::operator== (const String& str) const
{
    if(strcmp(this->text,str.text)==0)
        return true;
    else
        return false;
}

bool String::operator> (const String& str) const
{
    if (this->text==nullptr)
        return false;
    else if (str.text==nullptr)
        return true;
    if (strcmp(this->text,str.text)<=0)
        return false;
    else
        return true;
}

char& String::operator[] (const int i)
{
    return this->text[i];
}

std::ostream& operator<< (std::ostream& out, const String& str){
    out << str.text;
    return out;
}

int String::getLength() const{
    if (text == nullptr)
        return 0;
    return length;
}

String String::substring(int front, int chars){
    char * substr = new char[chars+1];       //creates new cstring
    int i = 0;
    for (i = 0; i < chars; i ++){
        substr[i] = *(this->text+front+i);      //populates cstring
    }
    substr[chars] = '\0';                    //appends null char
    String substringString = substr;            //converts to string
    return substringString;
}

char* String::cStr(){
    return text;
}

int String::find(char delimiter, int start){
    bool test1 = true;
    bool test2 = true;
    for (int i = start; test1||test2; i++){
        test2 = this->text[i]!='\0';
        test1 = this->text[i]!='\n';
        if (this->text[i]==delimiter)
            return i;
        else if (test1 == false || test2 == false)
            return i;
    }
    return -1;
}

void String::dissect(char delimiter, Vector<String>& parseS){
    String str;
    int start = 0;
    int end = this->length;
    int numOfChars;
    while (start < end) {
        while (this->text[start] == ' ')        //increments start over space chars at beginning of cstring
            start++;
            if (start == end)
                break;
        numOfChars = this->find(delimiter, start)-start;
        str = substring(start,numOfChars);
        if(str[numOfChars-1]==',') {            //checks if there is a comma at the end of the string
            str[numOfChars-1]='\0';
            if (str.text=='\0') {
                start += str.length;
                start++;
            }
            break;
        }
        parseS.insertAtBack(str);           //appends to a vector
        start += str.length;
        start++;
    }
}

void String::upper(){
    int i = 0;
    while (this->text[i]) {
        text[i]=toupper(this->text[i]);
        i++;
    }
//    return *this;
}

void String::lower(){
    int i = 0;
    while (this->text[i]) {
        text[i]=tolower(this->text[i]);
        i++;
    }
}

