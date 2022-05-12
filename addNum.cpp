#include <iostream>
#include <fstream>
#include "class.h"
#include "function.h"

using namespace std;

void addNum() //adding contact to a file using fstream & append
{
    system ("cls");
    string firstname ,lastname, bday ,phonenumber, mail, address;
    ofstream mydata;
	mydata.open("contactbook.txt", ios::app);

    if(mydata.fail())
    {
        cout << "Error! The File couldn't open" <<endl;
        cout << "Please Try agian later!" << endl;
        exit(0);
    }
    
    cout << "-----Add new Contract-----" << endl; 
    cout << "Enter Firstname: "; 
    cin >> firstname;
    cout << "Enter Lastname: ";
    cin >> lastname;
    cout << "Enter number: ";
    cin >> phonenumber;
    for(int i=0 ; i<phonenumber.length() ; i++) 
    {
        if (!isdigit(phonenumber[i])) // for [i] lenght of phonenumber will if-statsments look if its 'contains' integer or not if not the statsment will turn ture and asked for new inputs.
        {
            cout << "Invalid input!" <<endl;
            cout << "Integer ONLY!" << endl;
            cout << "Enter number: ";
            cin >> phonenumber;
        }
    }
    cout << "Enter Birthday: ";
    cin >> bday;
	cout << "Enter Email: ";
	cin >> mail;
	cout << "Enter adress: ";
	cin >> address;

	mydata << firstname  << " " << lastname << endl; 
	mydata << phonenumber <<endl;
    mydata << bday <<endl;
	mydata << mail << endl;
	mydata << address << endl;
	
	cout << "The number is successfully added!" <<endl;
	
}