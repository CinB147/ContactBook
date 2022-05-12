#include <iostream>
#include <fstream>
#include <vector>
#include "class.h"
#include "function.h"


using namespace std;

void deleteNum()
{
	system ("cls");
	string firstname ,lastname, number, mail, bday, address, answer;
	vector <contact> myvec; //vector for class 'contact'

    ifstream inputdata;
	inputdata.open("contactbook.txt");

	if(inputdata.fail())
    { 
        cout << "Error! The File couldn't open" <<endl;
        cout << "Please Try agian later!" << endl;
        exit(0);
    }
	
	while (!inputdata.eof())
	{
		inputdata >> firstname >> lastname ; //reading through text file
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

		myvec.push_back(mydata);  //once the declarations is identify 'mydata' is pushed back to vector

	}
	inputdata.close();

	cout << "----Delete contact----" <<endl;
	cout << "Enter firstname: "; 
	cin >> firstname;

	bool valid = 1;
	for(int i=0; i<myvec.size(); i++)
	{
		if(firstname == myvec[i].fname) //for vector contact[i] in fname variable class is same as user input firstname 
		{
			cout << "Are you sure you wanted to delete " << myvec[i].fname << " " <<myvec[i].lname << "?" << endl;
			cout << " Y / N " <<endl;
			cin >> answer ;
			if (answer == "Y" || answer == "y")
			{
				myvec.erase(myvec.begin() + i ); //using erese vector function, from begin[0] to position [i] that been found ,erese elements in [i] position
				cout << myvec[i].fname << " " << myvec[i].lname << " is now deleted!" << endl;
				valid = 0;
			}
		}
	}

	ofstream newdata; 
	newdata.open("contactbook.txt" );

	for(int i = 0; i < myvec.size(); ++i)
	{
		//reread the new vector after erese [i] ,put it to a temp.txt file 
		newdata << myvec[i].fname << " " << myvec[i].lname <<endl;
		newdata << myvec[i].number <<endl;
		newdata << myvec[i].birthday <<endl;
		newdata << myvec[i].email <<endl;	
		newdata << myvec[i].add <<endl;

		
	}
	
	newdata.close();

	if(valid)
	{
		//becuase of valid is bool type and it been decleared as valid 1(true) (on line 58 )it means line 61 isnt working (couldn't find) 
		cout << "This person is not in your contactbook"<< endl;
	}
}
