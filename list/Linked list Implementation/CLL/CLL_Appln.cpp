#include "CLL.h"
int main()
{
    cllist l;
    int t;
    cout<<"Isempty returned "<<l.IsEmpty()<<endl;
    l.InsertBeg(1);
    l.InsertBeg(2);
    l.InsertBeg(3);
    l.InsertBeg(4);
    l.PrintList();
    
    
    
    /*l.InsertBeg(2);
    l.InsertEnd(5);
    l.InsertPos(2,10);    
    l.PrintList();
    t = l.next(2);
    if(next_error_flag)
    cout<<"Failure\n";
    else
    cout<<"Element found is "<<t<<endl;

    /*t = l.DeletePos(5);
    if(delete_error_flag)
    cout<<"Deletion failed"<<endl;
    else
    cout<<"Deleted element is "<<t<<endl;
    l.PrintList();

/*    t = l.DeleteEnd();
    if(delete_error_flag)
    cout<<"Deletion failed"<<endl;
    else
    cout<<"Deleted element is "<<t<<endl;
    l.PrintList();*/

}
