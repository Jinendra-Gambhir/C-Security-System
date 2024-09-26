// Jinendra Project
#include<iostream> // Input Output
#include<fstream> //File Handling Operation
#include<sstream> // interoperation between stream buffers and string objects
#include<string>

using namespace std;

int main()
{
    int a, i=0;
    string text, old, password0, password1, password2, pass, name, age, user, word, word1;
    string creds[2], cp[2];

    cout<<"             Security System         "<<endl;
    cout<<"_______________________________________"<<endl<<endl;
    cout<<"|           1. Register               |"<<endl;
    cout<<"|           2. Login                  |"<<endl;
    cout<<"|           3. Change Password        |"<<endl;
    cout<<"|___________4. End Program____________|"<<endl;

    do
    {
        cout<<endl<<endl;
        cout<<"Enter your choice:- ";
        cin>>a;

        switch (a)
        {
            case 1:
            {
                cout<<"______________________________________"<<endl<<endl;
                cout<<"|--------------Register--------------|"<<endl;
                cout<<"|____________________________________|"<<endl<<endl;
                cout<<"Please enter username:- "; cin>>name;
                cout<<"Please enter the password:- "; cin>>password0;
                cout<<"Please enter your age:- "; cin>>age; cout<<"endl";

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open())
                {
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Registration Successfull..."<<endl;
                }
                break;
            }

            case 2:
            {
                i=0;
                cout<<"_______________________________________"<<endl<<endl;
                cout<<"|----------------Login----------------|"<<endl;
                cout<<"|_____________________________________|"<<endl<<endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"Username:- "; cin>>user;
                cout<<"Password:- "; cin>>pass;

                if(of2.is_open())
                {
                    while(!of2.eof())
                    {
                        while(getline(of2, text)) //read the file line by line
                        {
                            istringstream iss(text);  //iss is to stream the string and store using extraction operator
                            iss>>word;
                            creds[i] = word;
                            i++;
                        }

                        if(user == creds[0] && pass == creds[1])
                        {
                            cout<<"Login Successfull..."<<endl<<endl;
                            cout<<"Details: "<<endl;
                            cout<<"Username: " + name<<endl;
                            cout<<"Password: " + pass<<endl;    
                            cout<<"Age: " + age<<endl;                        
                        } else{
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"|     2. Login again         |"<<endl;
                            cout<<"|     3. Change password     |"<<endl; 
                            break;
                        }
                    }
                }
                break;
            }

            case 3:
            {
                i=0;
                cout<<"|-------------Change password--------------|"<<endl;

                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter old password:- "; cin>>old;
                
                if(of0.is_open())
                {
                    while(of0.eof())
                    {
                        while(getline(of0, text))
                        {
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }

                        if(old == cp[1])
                        {
                           of0.close();  // free up memory space 
                            ofstream of1;
                            
                            if(of1.is_open())
                            {
                                cout<<"Enter new password:- "; cin>>password1;
                                cout<<"Enter password again:- "; cin>>password2;

                                if(password1 == password2)
                                {
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password changed successfully..."<<endl;
                                }else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old; cout<<"Password do not match"<<endl;                                    
                                }
                            }

                        }else{
                            cout<<"Please enter valid password"<<endl;
                            break;
                        }
                    }
                } break;
            }

            case 4:
            {
                cout<<"__________Thank You!__________";
            }

            default:
            {
                cout<<"Enter a valid choice";
            }

        }

    }

    while (a!=4); 
    return 0;

}

