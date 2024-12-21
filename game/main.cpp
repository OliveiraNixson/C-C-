#include <iostream>
#include <fstream>


 using namespace std;

 class temp{
    string userName,email,password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
    void login();
    void signUp();
    void forgotPassword();

 }obj;

int main() {

    int choice;

    cout<<"\n1- Login";
    cout<<"\n2- Sign up";
    cout<<"\n3- Forgot password";
    cout<<"\n4- Exit";
    cout<<"\n5- Enter your choice ::";

    cin >> choice;
    cin.ignore();

    switch(choice){

    case 1:
        obj.login();
        break;

    case 2:
        obj.signUp();
        break;
    case 3:
        obj.forgotPassword();
        break;
    case 4:
        return 0;
        break;
    
    default:
    cout<<"invalid Selection...!";
        break;
    }



}

void temp :: signUp(){
    cout<<"\nEnter your user name ::";
    getline(cin,userName);
    cout<<"\nEnter your email ::";
    getline(cin,email);
    cout<<"\nEEnter your password ::";
    getline(cin,password); 

file.open("loginData.txt",ios :: out  | ios :: app);
file<<userName<<"*"<<email<<"*"<<password<<endl;
file.close();
}

void temp :: login(){
    string searchName,searchPass;
    cout<<"--------LOGIN-----------"<<endl;
    cout<<"Enter your User name ::"<<endl;
    getline(cin,searchName);
    cout<<"Enter your password :: "<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt",ios :: in);

    getline(file,userName,'*');
    getline(file,email,'*');

    getline(file,password,'*');
    while(!file.eof()){
        if(userName == searchName){
            if(password == searchPass){
                cout<<"Login Successful...."<<endl;
                cout<<"\nUsername ::"<<userName<<endl;
                cout<<"\nPassword ::"<<password<<endl;
                cout<<"\nEmail ::"<<email<<endl;
                break;
            }
            else{
                cout<<"Incorrect Password...."<<endl;
            }
        }
    }
    file.close();

}

void temp :: forgotPassword(){
    cout<<"\nEnter your username:: "<<endl;
    getline(cin,searchName);
    cout<<"\nEnter your email adress ::";
    getline(cin,searchEmail);

    file.open("loginData.txt",ios :: in);

    getline(file,userName,'*');
    getline(file,email,'*');
    getline(file,password,'*');
    while (!file.eof())
    {
        if(userName == searchName){
            if(email == searchEmail){
                cout<<"Your Password is :: "<<password<<endl;
                cout<<"Password ::"<<password<<endl;
                break;
            }
            else{
                cout<<"Email not found...."<<endl;
            }
        }
        else{
            cout<<"Username not found...."<<endl;
        }
    }
    

}



