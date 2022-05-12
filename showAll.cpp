#include <iostream>
#include <fstream>
#include <vector>
#include "class.h"
#include "function.h"


using namespace std;

void showAll()
{
	string firstname ,lastname, number, bday ,mail, address;
	vector <contact> myvec; //vector for class 'contact'
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
		//reading through text file
		inputdata >> firstname >> lastname ;
		inputdata >> number;
		inputdata >> bday;
		inputdata >> mail;
		inputdata >> address;

        if(inputdata.eof())
        {
            break; //break when file is ended to prevent last loop (last elemet read once agian after file is ended)
        }

		//declare class 'contact' as mydata and using class variables and identify

		contact mydata;
		mydata.fname = firstname;
		mydata.lname = lastname;
		mydata.number = number;
		mydata.birthday = bday;
		mydata.email = mail;
		mydata.add = address;

		//once the declarations is identify 'mydata' is pushed back to vector

		myvec.push_back(mydata);

	}

	for(int i=0; i<myvec.size(); i++)
    {
		//reading vector using 'i' as elements position in vector 
		//[i] had fname,lname,number,email,add from variable class
		
		cout << myvec[i].fname << " " << myvec[i].lname << " " << myvec[i].number << " " << endl;
		cout << myvec[i].birthday <<endl;
		cout << myvec[i].email <<endl;
		cout << myvec[i].add <<endl;
		cout << "____________________________"<<endl;
	}
	if(!myvec.size())
		cout << "Your contacts is empty!" << endl;

	inputdata.close();
}