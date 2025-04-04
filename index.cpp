#include <iostream> 
// For input/output operations like cout, cin, etc.
#include <fstream>  
// For file handling – reading from and writing to files.
#include <windows.h>  
// Windows-specific functions – for clearing screen, delays (Sleep), etc.
#include <sstream>  
// For using stringstream – treating strings like input/output streams.
using namespace std;
//tells compiler to bring entire std namespace into scope and can use standard library items directly like cout, cin, endl, etc.

// The Account class represents a bank user’s account, encapsulating account details and basic operations.
class Account{
    private :
    string AccountNo, Password;
    int Balance;

    // Constructor : Initializes all member variables to default values: empty strings and zero balance.
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

    // Getters (Value access)
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

// To Create a new bank account for a user.
void openAccount(Account &user){
    system("cls");
    string id, pw;
    cout<<"\tEnter Account No : ";
    cin>>id;

    // Check if account already exists : 
    // 1.Reads all lines from Account.txt
    // 2.Extracts account numbers and compares with input
    // 3.If a match is found, it informs the user and stops      account creation
    // 4. If no match is found, it proceeds to create the account

    ifstream checkFile("Account.txt");
    string line;
    bool exists = false;

    while(getline(checkFile, line)){
        stringstream ss(line);
        string existingID, existingPW;
        int existingBalance;
        char delimiter;

        ss >> existingID >> delimiter >> existingPW >> delimiter >> existingBalance;

        if(id == existingID){
            exists = true;
            break;
        }
    }
    checkFile.close();

    if(exists){
        cout << "\tAccount already exists! Please try with a different Account Number.\n";
        Sleep(3000);
        return;
    }
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

//To Deposit cash into an existing account.
void withdraw(){
    string id,pw;
    cout<<"\tEnter Account No : ";
    cin>>id;

    cout<<"\tEnter Password : ";
    cin>>pw;

    // infile is opened in read mode to fetch existing account data.
    ifstream infile("Account.txt");
    // outfile is opened in write mode to store updated data.
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

void deleteAccount() {
    system("cls");
    string id, pw;
    cout << "\tEnter Account No to Delete: ";
    cin >> id;
    cout << "\tEnter Password: ";
    cin >> pw;

    ifstream infile("Account.txt");
    ofstream outfile("Account Temp.txt");

    if (!infile || !outfile) {
        cout << "\tError: File can't be opened!" << endl;
        return;
    }

    string line;
    bool deleted = false;

    while (getline(infile, line)) {
        stringstream ss(line);
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;

        if (id == userID && pw == userPW) {
            // Skip writing this line to delete the account
            deleted = true;
            cout << "\tAccount deleted successfully!" << endl;
        } else {
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();

    remove("Account.txt");
    rename("Account Temp.txt", "Account.txt");

    if (!deleted) {
        cout << "\tAccount not found or incorrect credentials!" << endl;
    }

    Sleep(4000);
}


// The main() function serves as the entry point of the program. It shows a menu to the user with four choices:
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
        cout<<"\t2.Deposit Money."<<endl;
        cout<<"\t3.Withdraw Cash."<<endl;
        cout<<"\t4.Delete Account."<<endl;
        cout<<"\t5.Exit."<<endl;
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
            deleteAccount();
        }
        else if(val==5){
            system("cls");
            exit = true;
            cout<<"\tThank You! Good Day!"<<endl;
            Sleep(2000);
        }
        Sleep(3000);
    }
}
