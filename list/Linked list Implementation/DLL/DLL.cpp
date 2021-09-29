/*
* Linked list implementation in C++
* M Janaki Meena
* 28-09-2021
*/
#include<iostream>
using namespace std;
#include "DLL.h"

node* CreateNode(int data)
{
    node* new_node;
    new_node = new node;
    if (new_node==NULL)
        return NULL;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}
dllist::dllist()
{
    head=tail=NULL;
}
bool dllist::IsEmpty()
{
    if((head==NULL)&&(tail==NULL))
        return true;
    return false;
   
}
bool dllist::InsertBeg(int d)
{
    node * new_node;
    // Step 1: Call createnode function and get address returned in new_node
    new_node = CreateNode(d);
    // Step 2: If new_node is Null is returned return false
    if (new_node==NULL)
        return false;
    // Step 3: If list is empty then make both head and tail to point to new_node
    if(IsEmpty())
    {
        head=tail=new_node;
        return true;
    }
    // Step 4: Make next part of new_node to store head
    new_node->next = head;
    // Step 5: Make prev part of head to point to new_node
    head->prev = new_node;
    // Step 6: Make head to point to new_node
    head = new_node;
    // Step 7: return true
    return true;

}
void dllist::PrintList()
{
    node* temp;
    // Step 1: If list is empty return
    if(IsEmpty())
        return;
    // Step 2: Declare a temporary pointer, temp and make it to point to head
    temp = head;
    // Step 3: While temp is not NULL repeat step 4 and 5
    while(temp)
    {
    // Step 4: Print data part of temp
        cout<<temp->data<<endl;
        temp = temp->next;
    // Step 5: Move temp to next node

    }

}





















/*bool delete_error_flag = false;
bool reterieve_error_flag = false;
bool previous_error_flag = false;
bool next_error_flag = false;
bool last_but_one_error_flag = false;

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


int cllist::locate(int ele)
{
    node * temp;
    int counter;
    // Step 1: If list is empty then communicate failure 
    // and return -1
    if(IsEmpty())
        return -1;
    // Step 2: Declare a temporary pointer, temp and 
    // integer counter
    // Step 3: Initialize temp to point to first node and 
    // counter to 1
    temp = head;
    counter = 1;
    // Step 4: While next part of temp not equal to head 
    // repeat Step 5 and Step 6
    while(temp->next!=head)
    {
    // Step 5: If data part of node pointed by temp is equal 
    // to Element return counter 
        if(temp->data ==ele)
            return counter;
    // Step 6: Move temp to next node and increment counter
        temp = temp->next;
        counter++;
    }
    // Step 7: If data part of temp is equal to Element 
    if(temp->data==ele)
        return counter;
    // return counter
    // Step 8: return -1
    return -1;
}
int cllist:: reterieve(int pos)
{
    node* temp;
    int counter;
    reterieve_error_flag = 0;
    // Step 1: If list is empty then communicate failure 
    // and return -1
    if(IsEmpty())
    {
        reterieve_error_flag=1;
        return -1;
    }
    // Step 2: Declare a temporary pointer, temp and 
    // integer counter
    // Step 3: Initialize temp to point to first node 
    // and counter to 1
    temp = head;
    counter = 1;
    // Step 4: While counter<position repeat Step 5 and Step 6
    while(counter<pos)
    {
    // Step 5: If next part of temp is head then break
        if(temp->next==head)
            break;
    // Step 6: Move temp to next node and increment counter
        temp = temp->next;
        counter++;
    }
    // Step 7: If pos == counter then return data part of temp 
    // and communicate failure otherwise
    if(pos==counter)
        return temp->data;
    reterieve_error_flag = 1;
    return -1;
}
int cllist::previous(int ele)
{
    node *temp;
    previous_error_flag=0;
// Step 1: If list is empty then Indicate failure to callee function and return -1
    if(IsEmpty())
    {
        previous_error_flag = 1;
        return -1;
    }
// Step 2: Declare a temporary pointer, temp
// Step 3: Initialize temp to point to first node
    temp = head;
// Step 4: When next part of temp is not head repeat Step 5 and Step 6
    while(temp->next!=head)
    {
// Step 5: If data in next node of temp is equal to Element then return data part of temp
    if(temp->next->data==ele)
        return temp->data;
// Step 6: Move temp to next node
    temp=temp->next;
    }
// Step 7: Indicate failure to callee function and return -1
    previous_error_flag=1;
    return -1;
}
int cllist::next(int ele)
{
    node *temp;
    next_error_flag = 0;
// Step 1: If list is empty then Indicate failure to 
// callee function and return -1
    if(IsEmpty())
    {
        next_error_flag=1;
        return -1;
    }
// Step 2: Declare a temporary pointer, temp
// Step 3: Initialize temp to point to first node
    temp=head;
// Step 4: While next part of temp != head (i.e.) when temp is not in the last node then repeat Step 5 and Step 6
    while(temp->next!=head)
    {
// Step 5: If data of temp is equal to Element then return data part of next node of temp
    if(temp->data==ele)
    {
        return temp->next->data;
    }
// Step 6: Move temp to next node
    temp = temp->next;
    }
// Step 7: Indicate failure to callee function and return -1
    next_error_flag=1;
    return -1;
}
cllist::~cllist()
{
    node* temp;
   // Step 1: Initialize temp to head
   temp = head;
    // Step 2: Move temp to last node and make 
    while(temp->next!=head)
        temp=temp->next;
    // next part of last node as NULL
    temp->next=NULL;
    // Step 3: While head->next != NULL repeat steps 4 and 5
    while(head->next!=NULL)
    {
    // Step 4: temp = head
        temp =head;
    // Step 5: Move head to next node, delete temp
        head = head->next;
        delete temp;
    }
    temp =head;
    // Step 6: Delete temp
    delete temp;
    // Step 7: Make head as NULL 
    head=NULL;

}

*/