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
bool last_but_one_error_flag = false;
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
bool cllist::InsertBeg(int d)
{
    node *new_node,*temp;
    new_node = CreateNode(d);
    if(new_node==NULL)
    return false;
    if(IsEmpty())
    {
        new_node->next = new_node;
        head = new_node;
        return true;
    }
    new_node->next = head;
    temp = head;
    while(temp->next != head)
    temp = temp->next;
    temp->next = new_node;
    head = new_node;
    return true;
}
bool cllist::InsertEnd(int d)
{
    node* temp,*new_node;
    if(IsEmpty())
    return InsertBeg(d);
    new_node = CreateNode(d);
    if(!new_node)
    return false;
    temp = head;
    while(temp->next!=head)
    temp = temp->next;
    temp->next = new_node;
    new_node->next = head;
    return true;
}
bool cllist::InsertPos(int pos,int data)
{
    node* new_node,*temp;
    int counter;
    if(IsEmpty())
        return InsertBeg(data);
    new_node = CreateNode(data);
    if (new_node==NULL)
        return false;
    temp = head;
    counter = 1;
    while(temp->next!=head)
    {
        if(counter==pos-1)
            break;
        counter++;
        temp=temp->next;
    }
    if(counter==pos-1)
    {
        new_node->next = temp->next;
        temp->next = new_node;
        return true;
    }
    return false;
}
int cllist::DeleteBeg()
{
    node* temp, *temp1;
    int data;
    delete_error_flag = false;
    // Step 1: If list is empty indicate failure and return -1
    if(IsEmpty())
    {
        delete_error_flag = true;
        return -1;
    }
    // Step 2: Let data = data part of head
    data = head->data;
    // Step 3: If there is only one in the list then 
    //	  (i) Free memory pointed by head
    //	  (ii) Make head as NULL
    //	   (iii) return data
    if(head==head->next)
    {
        delete head;
        head = NULL;
        return data;
    }
    // Step 3: Make temp to point to head 
    temp = head;
    // Step 4: Move temp to last node
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    // Step 5: Next part of temp is next part of head
    temp->next = head->next;
    // Step 6: Let temp1 = head
    temp1 = head;
    // Step 7: Move head to next node
    head = head->next;
    // Step 8: Free piece of memory with address temp1
    delete temp1;
    // return data
    return data;
}
int cllist::Last_But_One()
{
    //Step 1: If list is empty or there is only one node
    // Indicate failure
    if(IsEmpty()||head->next==head)   
        return -1;
}
void cllist::PrintList()
{
    node* temp;
    if(IsEmpty())
    return;
    temp = head;
    cout<<"Printing list...\n";
    while(temp->next!=head)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<temp->data<<endl;
    
}



