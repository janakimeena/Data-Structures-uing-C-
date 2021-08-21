/*
* Linked list implementation in C++
* M Janaki Meena
* 16-8-2021
*/
#include<iostream>
using namespace std;
bool delete_error_flag = false;
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
    void PrintList();
};
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
llist::llist()
{
   head = NULL;
}
bool llist::IsEmpty()
{
    if(!head)
    return true;
    return false;
}
bool llist::InsertBeg(int data)
{
    node* new_node;
    new_node = CreateNode(data);
    if(new_node==NULL)
    return false;
    new_node->next = head;
    head = new_node;
    return true;
}
bool llist::InsertEnd(int data)
{
    node *temp, *new_node;
    if(IsEmpty())
    return InsertBeg(data);
    new_node = CreateNode(data);
    if(new_node==NULL)
    return false;
    temp = head;
    while(temp->next!=NULL)
    temp = temp->next;
    temp->next = new_node;
    return true;
}
bool llist::InsertPos(int pos, int data)
{
    node *temp,*new_node;
    int counter = 1;
    if(pos==1)
    return InsertBeg(data);
    if(IsEmpty()&&pos>1)
    return false;
    temp = head;
    cout<<temp<<endl;
    while(counter<pos-1)
    {
        temp = temp->next;
        if(temp==NULL)
        return false;
     
        counter++;
    }
    cout<<"I am outside"<<endl;
        new_node = CreateNode(data);
        if(!new_node)
        return false;
        new_node -> next = temp->next;
        temp->next = new_node;
        return true;

}
void llist::PrintList()
{
    node* temp;
    temp = head;
    cout<<"List is printed"<<endl;
    while(temp)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
int llist::DeleteBeg()
{
    delete_error_flag = false;
    node* temp;
    int tempint;
    if(IsEmpty())
    {
        delete_error_flag = true;
        return -1;
    }
    temp = head;
    tempint = temp->data;
    head = head->next;
    return tempint;
}
int main()
{
    llist l;
    int t;
    cout<<"Isempty returned "<<l.IsEmpty()<<endl;
    l.InsertBeg(1);
    l.InsertBeg(2);
    l.InsertEnd(5);
    l.InsertPos(2,10);    
    l.PrintList();

    t = l.DeleteBeg();
    if(delete_error_flag)
    cout<<"Deletion failed"<<endl;
    else
    cout<<"Deleted element is "<<t<<endl;
    l.PrintList();

}