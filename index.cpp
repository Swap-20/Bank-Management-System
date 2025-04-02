#include <iostream> 
//Input-Output functions : for operations and error handling, objects and manipulators : control output formatting and buffering
#include <fstream>
//allow to read and write files
#include <windows.h>
//core component of windowsAPI provides functions like creating window, managing resources, handling msgs, macros and data types.
#include <sstream>
//provide a way to manipulate strings as stream, string formatting
using namespace std;
//tells compiler to bring entire std namespace into scope and can use standard library items directly like cout, cin, endl, etc.

class Account{
    private :
    string AccountNo, Password;
    int Balance;

    public:
    Account() : AccountNo(""),Password(""),Balance(0){}

    //value intialization
    setAccountNo(string id){
        AccountNo = id;
    }
    //value intialization
    setPassword(string pw){
        Password = pw;
    }
    //value intialization
    setBalance(int balance){
        Balance = balance;
    }

    string getAccountNo(){
        return AccountNo;
    }
    string getPassword(){
        return Password;
    }
    int getBalance(){
        return Balance;
    }

};

void openAccount(Account user){
    system("cls");
    string id, pw;
    cout<<"\tEnter Account No : ";
    cin>>id;
    user.setAccountNo(id);

    cout<<"\tEnter a strong password : ";
    cin>>pw;
    user.setPassword(pw);

    user.setBalance(0);

    ofstream outfile("D:/Account.txt", ios::app);
    if(!outfile){
        cout<<"\tError : File Can't Open!"<<endl;
    }else{
        outfile<<"\t"<<user.getAccountNo()<<" : "<<user.getPassword()<<" : "<<user.getBalance()<<endl;
        cout<<"\tAccount Created Successfully!"<<endl;
    }
    outfile.close();

    Sleep(5000);
}
int main(){
    Account user;

    bool exit = false;
    while(!exit){
        system("cls");

        int val;
        // - \t : used for 1 tab space from left corner
        // cout : print messages/options for user
        cout<<"\tWelcome to Bank Management Sytem"<<endl;
        cout<<"\t*********************************"<<endl;
        cout<<"\t1.Open New Account."<<endl;
        cout<<"\t2.Add Cash."<<endl;
        cout<<"\t3.Withdraw Cash."<<endl;
        cout<<"\t4.Exit."<<endl;
        cout<<"\tEnter Your Choice : "<<endl;

        cin>>val;
        // cin : scan or get the user input

        if(val==1){
            openAccount(user);
        }
        Sleep(3000);
    }
}
