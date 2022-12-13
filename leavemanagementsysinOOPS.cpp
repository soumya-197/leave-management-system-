
#include <iostream>
#include <string>
using namespace std;
class leaverecord
{
    int cl,pl,ml;
    int taken_cl=0,taken_pl=0,taken_ml=0;
    int total_cl=3,total_pl=3,total_ml=5;
    public:
    char leavetype;
    void leavepermission()
    {
        cout<<"\n\nWhich type of leave do you want?\nEnter c for Common Leave , p for privilaged leave and m for medical leave : ";
        cin>>leavetype;
        switch(leavetype){
        case 'c':
            cout<<"Enter the number of leaves you want : ";
            cin>>cl;
            if(cl<=total_cl){
                taken_cl = taken_cl + cl;
                total_cl = total_cl - cl;
                cout<<"\nYour leave is granted";
                cout<<"\nYour remaining common leaves are: "<<total_cl;
            }
            else{
                cout<<"\nsorry! You dont have enough number of common leaves left.";
            }
            break;
        case 'p':
            cout<<"Enter the number of leaves you want : "<<endl;
            cin>>pl;
            if(pl<=total_pl){
                taken_pl = taken_pl + pl;
                total_pl = total_pl - pl;
                cout<<"\nYour leave is granted";
                cout<<"\nYour remaining privilaged leaves are: "<<total_pl;
            }
            else{
                cout<<"\nsorry! You dont have enough number of common leaves left.";
            }
            break;
        case 'm':
            cout<<"Enter the number of leaves you want : "<<endl;
            cin>>ml;
            if(ml<=total_ml){
                taken_ml = taken_ml + ml;
                total_ml = total_ml - ml;
                cout<<"\nYour leave is granted";
                cout<<"\nYour remaining medical leaves are: "<<total_ml;
            }
            else{
                cout<<"\nsorry! You dont have enough number of common leaves left.";
            }
            break;
        default:
            cout<<"Wrong input";
            break;
        }
    }
    void leave_details()
    {
    cout<<endl<<"LEAVE DETAILS OF EMPLOYEE ARE : "<<endl<<endl;
    cout<<"LEAVE TYPE"<<"                  "<<"LEAVES TAKEN"<<"                                     "<<"LEAVES REMAINING"<<endl;
    cout<<"1.CAUSUAL LEAVE"<<"             "<<taken_cl<<"                                            "<<total_cl<<endl;
    cout<<"2.PRIVILAGED LEAVE"<<"          "<<taken_pl<<"                                            "<<total_pl<<endl;
    cout<<"3.MEDICAL LEAVE"<<"             "<<taken_ml<<"                                            "<<total_ml<<endl;
}
};
class employee:public leaverecord
{
    string name;
    int mobileno;
    string dob;
    float salary;
    public:
    int id;
    void get_data_of_employee()
    {
    cin.ignore();
    cout<<"Enter the name of the employee : ";
    getline(cin,name);
    cout<<"Enter the mobile number of the employee : ";
    cin>>mobileno;
    cout<<"Enter the salary of the employee : ";
    cin>>salary;
    cout<<"Enter the date of birth of the employee : ";
    cin.ignore();
    getline(cin,dob);
    cout<<endl<<"YOU ARE SUCCESSFULLY REGISTERED. ";
    }
    void set_data_of_employee()
    {
    cout<<endl<<"DETAILS OF EMPLOYEE ARE :"<<endl<<endl;
    cout<<"NAME :"<<"                                        "<<name<<endl;
    cout<<"ID :"<<"                                          "<<id<<endl;
    cout<<"MOBILE NUMBER :"<<"                               "<<mobileno<<endl;
    cout<<"DATE OF BIRTH :"<<"                               "<<dob<<endl;
    cout<<"SLARY :"<<"                                       "<<salary<<endl;
    
    }
    void modify_details()
    {
    int ch;
    cout<<"WELCOME"<<"           "<<name<<endl;
    set_data_of_employee();
    cout<<"\nWhich Detail would you like to modify?";
    cout<<"\nEnter 1 for name,\nEnter 2 for Phone Number,\nENter 3 for DOB,\nEnter 4 for Salary.";
    cin>>ch;
    if(ch == 1){
        cin.ignore();
        cout<<"Enter new name : ";
        getline(cin,name);
    }
    else if(ch == 2){
        cout<<"Enter new Phone NUmber : ";
        cout<<mobileno;
    }
    else if(ch == 3){
        cin.ignore();
        cout<<"Enter new DOB : ";
        getline(cin,dob);
    }
    else if(ch == 4){
        cout<<"Enter new salary : ";
        cin>>salary;
    }
    else{
        cout<<"Wrong choice";
    }
    }
};
int main()
{
    int choice = 0,total_emp=0,id,i,f;
    employee e[100];
    cout<<"\n\n------WELCOME TO LEAVE MANAGEMENT SYSTEM------";
    cout<<"\n\n----If you are a new employee, then please register yourself first----\n";

    while(choice!=5){

        cout<<"\n\n------------------HOME--------------------\n";
        cout<<"\n 1.Register";
        cout<<"\n 2.Ask for leave";
        cout<<"\n 3.Show details";
        cout<<"\n 4.Modify details";
        cout<<"\n 5.Exit";
        cout<<"\nChoose option : ";
        cin>>choice;
        switch(choice){
            case 1:
                f=0;
                cout<<"Enter ID : ";
                cin>>id;
                for(i=0;i<=total_emp;i++){
                    if(e[i].id==id){
                        cout<<"Employee with this id already exists.";
                        f = 1;
                    }
                }
                if(f==0){
                    e[total_emp].get_data_of_employee();
                    e[total_emp].id = id;
                    total_emp++;
                }
                break;
            case 2:
                f=0;
                cout<<"Enter ID : ";
                cin>>id;
                for(i=0;i<=total_emp;i++){
                    if(e[i].id==id){
                        e[i].leave_details();
                        e[i].leavepermission();
                        f = 1;
                        break;
                    }
                }
                if(f==0){
                    cout<<endl<<"Sorry , employee with this ID does not exists. "<<endl;
                }
                break;
            case 3:
               f=0;
               cout<<"Enter ID : ";
                cin>>id;
                for(i=0;i<=total_emp;i++){
                    if(e[i].id==id){
                        e[i].set_data_of_employee();
                        e[i].leave_details();
                        f = 1;
                        break;
                    }
                }
                if(f==0){
                    cout<<endl<<"Sorry , employee with this ID does not exists. "<<endl;
                }
                break;
            case 4:
                f=0;
                cout<<"Enter ID : ";
                cin>>id;
                for(i=0;i<=total_emp;i++){
                    if(e[i].id==id){
                        e[i].modify_details();
                        f = 1;
                        break;;
                    }
                }
                if(f==0){
                    cout<<endl<<"Sorry , employee with this ID does not exists. "<<endl;
                }
                break;
            case 5:
                cout<<"\nYOU HAVE EXITED THE LEAVE MANAGEMENT SYSTEM\n";
                cout<<"\n------------------------------------THANK YOU------------------------------------";
                break;
        }
    }
    return 0;
}