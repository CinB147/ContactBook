#include <iostream>
#include <fstream>
#include <vector>
#include "class.h"
#include "function.h"

using namespace std;

void findNum()
{
	system ("cls");
	string firstname ,lastname, phonenumber,bday, mail, address;
	vector <contact> myvec; //vector for class 'contact'
	int opt;
	ifstream inputdata;
	inputdata.open("contactbook.txt");

	if(inputdata.fail()) //fail to open file then exit
    {
        cout << "Error! The File couldn't open" <<endl;
        cout << "Please Try agian later!" << endl;
        exit(0);
    }

	while (!inputdata.eof())
	{
		inputdata >> firstname >> lastname ;
		inputdata >> phonenumber;
		inputdata >> bday;
		inputdata >> mail;
		inputdata >> address;

        if(inputdata.eof()) //When the file is ended ,break to prevent reread the last element in textfile
        {
            break;
        }

		contact mydata; //declare class 'contact' as mydata and using class variables and identify
		mydata.fname = firstname;
		mydata.lname = lastname;
		mydata.birthday = bday;
		mydata.number = phonenumber;
		mydata.email = mail;
		mydata.add = address;

		myvec.push_back(mydata); //once the declarations is identify 'mydata' is pushed back to vector

	}
	cout << "-----Search Contact----" <<endl;
	cout << "Would you like to search by lastname or firstname or telephonenumber?" << endl;
	cout << "Enter 1 : Search by Firstname" << endl;
	cout << "Enter 2 : Search by Lastname" << endl;
	cout << "Enter 3 : Search by Telephonenumber" << endl;
	cin >> opt;
	bool ok = 1;

	switch(opt)
		{
			case 1 : 
			{
				cout << "Enter firstname : "; //ask for name to search
				cin >> firstname;
				system("cls");
				bool valid = 1; 
				
				for(int i=0; i<myvec.size(); i++)
				{
					if(firstname == myvec[i].fname) //if input firstname is equal to [i] in fname print all [i] in class
					{
						if(firstname != myvec[i].fname)
						{
							continue; //becuase of i will be i + end in vec of ending of myvec.size()
						}
						cout << "____________________________"<<endl;
						cout << myvec[i].fname << " " << myvec[i].lname << endl;
						cout << myvec[i].number << endl;
						cout << myvec[i].email <<endl;
						cout << myvec[i].birthday <<endl;
						cout << myvec[i].add <<endl;
						cout << "____________________________"<<endl;

						valid = 0; //change 1 to 0 if if statemts is fullfill 

					}
				}
				if(valid) //if if-statsment in line 66 is not fullfil it means there is no person in contacts (couldn't found)
				{
				cout << "This person is not in your contacts!" <<endl;
				}
				break;
				
			}
			case 2 : //repeat same as case 1 but lastname as searching key
			{
				cout << "Enter lastname : ";
				cin >> lastname;
				system("cls");
				bool valid = 1;

				for(int i=0; i<myvec.size(); i++)
				{
					if(lastname == myvec[i].lname) 
					{
						if(lastname != myvec[i].lname)
						{
							continue; 
						}
						cout << "____________________________"<<endl;
						cout << myvec[i].fname << " " << myvec[i].lname << endl;
						cout << myvec[i].number << endl;
						cout << myvec[i].email <<endl;
						cout << myvec[i].birthday <<endl;
						cout << myvec[i].add <<endl;
						cout << "____________________________"<<endl;

						valid = 0; 

					}
				}
				if(valid) 
				{
				cout << "This person is not in your contacts!" <<endl;
				}
				break;
				
			}
			case 3: //repeat same as case 1 but number as searching key
			{
				cout << "Enter number : ";
				cin >> phonenumber;
				system("cls");
				bool valid = 1;

				for(int i=0; i<myvec.size(); i++)
				{
					if(phonenumber == myvec[i].number) 
					{
						if(phonenumber != myvec[i].number)
						{
							continue; 
						}
						cout << "____________________________"<<endl;
						cout << myvec[i].fname << " " << myvec[i].lname << endl;
						cout << myvec[i].number << endl;
						cout << myvec[i].email <<endl;
						cout << myvec[i].birthday <<endl;
						cout << myvec[i].add <<endl;
						cout << "____________________________"<<endl;

						valid = 0; 

					}
				}
				if(valid) 
				{
				cout << "This person is not in your contacts!" <<endl;
				}
				break;
				
			}
			default:
			{ 
				cout << "Error! Invalid Input! " << endl;
				cout << "Please Try agian later!" << endl;
			}
		}
}