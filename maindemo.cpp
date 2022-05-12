#include <iostream>
#include "class.h"
#include "function.h"

using namespace std;

int main()
{
    while(true)
    {
        int option; 
		cout << "-----Hello! Welcome to contact book!-----" << endl;
        cout << "Enter 1 : Add new contact" << endl;
        cout << "Enter 2 : Delete contact" << endl;
        cout << "Enter 3 : Show contact" << endl;
        cout << "Enter 4 : Search contact" << endl;
        cout << "Enter 5 : EXIT" << endl;
        cout << "Enter (1-5): ";
        cin >> option;

		
		switch(option)
		{
			case 1 : {
				addNum();
				break;
			}
			case 2 : {
				deleteNum();
				break;
			}
			case 3 : {
				cout << "-----Contact book-----" <<endl;
				showAll();
				break;
			}
			case 4 : {
				findNum();
				break;
			}
			case 5 : {
				exit(1);
				break;
			}
			default : 
			{
				cout << "Error! Invalid Input! " << endl;
			}
		}
	}
	return 0;
}