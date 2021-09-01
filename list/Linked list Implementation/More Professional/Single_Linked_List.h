/*
* Linked list implementation in C++
* M Janaki Meena
* 16-8-2021
*/
#include<iostream>
#include<iostream>
using namespace std;
#ifndef SLL
#define SLL
extern bool delete_error_flag;
extern bool reterieve_error_flag;
extern bool previous_error_flag;
extern bool next_error_flag;
struct node
{
    int data;
    node* next;
};
class llist
{
    node* head;
    public:
    llist();
    bool IsEmpty();
    bool InsertBeg(int);
    bool InsertEnd(int);
    bool InsertPos(int,int);
    int DeleteBeg();
    int DeleteEnd();
    int DeletePos(int);
    void PrintList();
    int locate(int);
    int reterieve(int);
    int previous(int);
    int next(int);
    ~llist();
};
#endif