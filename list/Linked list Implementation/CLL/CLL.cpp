/*
* Linked list implementation in C++
* M Janaki Meena
* 02-09-2021
*/
#include<iostream>
using namespace std;
#include "CLL.h"
bool delete_error_flag = false;
bool reterieve_error_flag = false;
bool previous_error_flag = false;
bool next_error_flag = false;
node* CreateNode(int data)
{
    node* new_node;
    new_node = new node;
    if(new_node==NULL)
    return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
cllist::cllist()
{
    head = NULL;
}
bool cllist::IsEmpty()
{
    if (head==NULL)
    return true;
    return false;
}
