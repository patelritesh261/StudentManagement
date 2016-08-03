#include "Grade.h"

namespace std {

	Grade::Grade()
	{
	}
	void Grade::Login() {
		Student student;

		bool flag=student.Login();
		if (flag) {
			student.studentinfo = student.getStudentInfo();

		}
		
	}
	//****************************************************************
	// Method Name : PrintOptions.										 *
	// Parameters : Nothings									     *
	// This method display option and get input from user and call   *
	// function according to user input						         *
	//****************************************************************
	void Grade::PrintOptions() {
		system("CLS");
		cout << "Plaese choose one option from below......" << endl;
		cout << "1.\tManage Course." << endl;
		cout << "2.\tManage Student." << endl;
		cout << "3.\tManage Grade." << endl;
		cout << "4.\tPrint Report." << endl;
		cout << "5.\tExit." << endl;
		int choice;
		do {
			cout << "Enter your option : ";
			cin >> choice;
		} while (choice<0 || choice>6);

		//call according to choice
		switch (choice)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			exit(0);
			break;
		default:
			break;
		}
		PrintOptions();
	}
	Grade::~Grade()
	{
	}
}
