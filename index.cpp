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
    void setAccountNo(string id){
        AccountNo = id;
    }
    //value intialization
    void setPassword(string pw){
        Password = pw;
    }
    //value intialization
    void setBalance(int balance){
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

void openAccount(Account &user){
    system("cls");
    string id, pw;
    cout<<"\tEnter Account No : ";
    cin>>id;
    user.setAccountNo(id);

    cout<<"\tEnter a strong password : ";
    cin>>pw;
    user.setPassword(pw);

    user.setBalance(0);

    // ofstream to write data in file
    ofstream outfile("Account.txt", ios::app);
    if(!outfile){
        cout<<"\tError : File Can't Open!"<<endl;
    }else{
        outfile<<"\t"<<user.getAccountNo()<<" : "<<user.getPassword()<<" : "<<user.getBalance()<<endl<<endl;
        cout<<"\tAccount Created Successfully!"<<endl;
    }
    outfile.close();

    Sleep(5000);
}

void addCash(Account &user){
    system("cls");
    string id;
    cout<<"\tEnter Account No : ";
    cin>>id;

    // ifstream to read the data
    ifstream infile("Account.txt");
    ofstream outfile("Account Temp.txt");

    if(!infile || !outfile){
        cout<<"\tError : File Can't Open"<<endl;
    }

    string line;
    bool found = false;

    while(getline(infile, line)){
        stringstream ss;
        ss<<line;
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss>>userID>>delimiter>>userPW>>delimiter>>userBalance;
        if(id == userID){
            found = true;
            int cash;
            cout<<"\tEnter Cash : ";
            cin>>cash;

            int newBalance = userBalance + cash;
            userBalance = newBalance;
            outfile<<"\t"<<userID<<" : "<<userPW<<" : "<<userBalance<<endl;
            cout<<"\tNew Balance : "<<userBalance<<endl;
        }
        else{
            outfile<<line<<endl;
        }
    }
    if(!found){
        cout<<"\tEnter valid Account no!"<<endl;
    }
    outfile.close();
    infile.close();
    remove("Account.txt");
    rename("Account Temp.txt","Account.txt");
    Sleep(5000);
}

void withdraw(){
    string id,pw;
    cout<<"\tEnter Account No : ";
    cin>>id;

    cout<<"\tEnter Password : ";
    cin>>pw;

    ifstream infile("Account.txt");
    ofstream outfile("Account Temp.txt");
    if(!infile || !outfile){
        cout<<"\tError : File Can't Open!"<<endl;
    }

    string line;
    bool found = false;
    while(getline(infile,line)){
        stringstream ss;
        ss<<line;
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss>>userID>>delimiter>>userPW>>delimiter>>userBalance;

        if(id==userID && pw==userPW){
            found = true;
            int cash;
            cout<<"\tEnter Cash : ";
            cin>>cash;
            if(cash <= userBalance){
                int newBalance = userBalance - cash;
                userBalance = newBalance;
                outfile<<"\t"<<userID<<" : "<<userPW<<" : "<<userBalance<<endl;
                cout<<"\tTransaction was Successful!"<<endl;
                cout<<"\tRemaining Balance : "<<userBalance<<endl;
            }
            else{
                cout<<"\tLow Balance!"<<endl;
                outfile<<"\t"<<userID<<" : "<<userPW<<" : "<<userBalance<<endl;
            }
        }
        else{
            outfile<<line<<endl;
        }
    }
    if(!found){
        cout<<"\tInvalid Accound or Password!"<<endl;
    }
    outfile.close();
    infile.close();
    remove("Account.txt");
    rename("Account Temp.txt","Account.txt");
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
        cout<<"\tEnter Your Choice : ";

        cin>>val;
        // cin : scan or get the user input

        if(val==1){
            openAccount(user);
        }
        else if(val==2){
            addCash(user);
        }
        else if(val==3){
            withdraw();
        }
        else if(val==4){
            system("cls");
            exit = true;
            cout<<"\tGood Luck!"<<endl;
            Sleep(2000);
        }
        Sleep(3000);
    }
}

