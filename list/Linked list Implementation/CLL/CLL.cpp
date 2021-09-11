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

bool cllist::IsSingleNode()
{
    return(head->next==head);
}
int cllist::DeleteEnd()
{
    node* temp, *temp1;
    int d;
    // Step 1: If list is empty or there is only one in the list 
    // return after calling Delete Beginning
    if(IsEmpty()||IsSingleNode())
        return DeleteBeg();
    // Step 2: Make temp to point to head 
    temp = head;
    // Step 3: Move temp to last but one node
    while(temp->next->next!=head)
        temp = temp->next;
    // Step 4: Let temp1 hold address of last node
    temp1 = temp->next;
    // Step 5: Make next part of temp as head
    temp ->next = head;
    // Step 6: Let d= data part of temp1
    d = temp1->data;
    // Step 7: Free piece of memory with address temp1
    delete temp1;
    // Step 8: return d
    return d;
}
int cllist::DeletePos(int pos)
{
    node* temp, *temp1;
    int counter,d;
    delete_error_flag=0;
    if(pos<1)
    {
        delete_error_flag = 1;
        return -1;
    }
    // Step 1: If list is empty or pos =1 then 
    // Call DeleteBeg and return
    if(IsEmpty()||pos==1)
        return DeleteBeg();
    // Step 2: Let temp = head, counter =1
    temp = head;
    counter =1;
    // Step 3: While counter < pos-1 and temp is not in last node 
    // repeat Step 4
    while((temp->next!=head)&&(counter<pos-1))
    // Step 4: Increment counter and move temp to next node
    {
        counter++;
        temp = temp->next;
    }
    // Step 5: If counter = pos-1 do step 8 to 11
    
    // Step 6: Let temp1 = temp->next
    temp1 = temp->next;
    // Step 7: If temp1 is head, communicate failure and return -1
    if(temp1==head)
    {
        delete_error_flag=1;
        return -1;
    }
    // Step 8: Make next part of temp = next part of temp1
    if(counter==pos-1)
    {
        temp->next = temp1->next;
    
    // Step 9: Let d = data part of temp1
        d = temp1->data; 
    // Step 10: Free memory pointed by temp1
        delete temp1;
    // Step 11: Return d
        return d;
    }
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



