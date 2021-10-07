#include "DLL.h"
int main()
{
    dllist l;
    int t;
    cout<<"Isempty returned "<<l.IsEmpty()<<endl;
    l.InsertEnd(1);
    l.InsertEnd(2);
    l.InsertEnd(4);
    cout<<"Before deletion list is "<<endl;
    l.PrintList();
    t = l.DeleteEnd();
    if (DELETE_ERROR_FLAG)
        cout<<"Deletion failed"<<endl;
    else
        cout<<"Element deleted is "<<t<<endl;
    
    cout<<"After deletion list is "<<endl;
    l.PrintList();
    /*t = l.DeleteBeg();
    if (DELETE_ERROR_FLAG)
        cout<<"Deletion failed"<<endl;
    else
        cout<<"Element deleted is "<<t<<endl;
    cout<<"After deletion list is "<<endl;
    l.PrintList();*/
}































/*    l.InsertEnd(1);
    l.InsertEnd(2);
    l.InsertEnd(3);
    l.InsertEnd(4);
    l.InsertEnd(5);
    //l.InsertPos(2,25);
    t = l.next(5);
    if(next_error_flag)
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

//}
