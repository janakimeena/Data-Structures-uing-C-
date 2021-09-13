#include "CLL.h"
int main()
{
    cllist l;
    int t;
    cout<<"Isempty returned "<<l.IsEmpty()<<endl;
    l.InsertEnd(1);
    l.InsertEnd(2);
    l.InsertEnd(3);
    l.InsertEnd(4);
    l.InsertEnd(5);
    //l.InsertPos(2,25);
    t = l.previous(1);
    if(previous_error_flag)
        cout<<"position not valid\n";
    else
        cout<<"Element at position is "<<t<<endl;
    //l.PrintList();
      
    
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
