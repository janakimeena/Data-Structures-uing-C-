/*
* Linked list implementation in C++
* M Janaki Meena
* 28-09-2021
*/
#include<iostream>
#include<iostream>
using namespace std;
#ifndef DLL
#define DLL
extern bool DELETE_ERROR_FLAG;
struct node
{
    int data;
    node* prev;
    node* next;
};
class dllist
{
    node* head;
    node* tail;
    bool IsSingleNode();
    public:
    dllist();
    bool IsEmpty();
    bool InsertBeg(int);
    bool InsertEnd(int);
    bool InsertPos(int pos, int d);
    int DeleteBeg();
    int DeleteEnd();
    int DeletePos(int);
    void PrintList();
};
#endif











/*extern bool delete_error_flag;
extern bool reterieve_error_flag;
extern bool previous_error_flag;
extern bool next_error_flag;
extern bool last_but_one_error_flag;


node* head;
    bool IsSingleNode();
    public:
    cllist();
    bool IsEmpty();
    
    bool InsertEnd(int);
    bool InsertPos(int,int);
    int DeleteBeg();
    int DeleteEnd();
    int DeletePos(int);
    
    int locate(int);
    int reterieve(int);
    int previous(int);
    int next(int);
    
    ~cllist();*/