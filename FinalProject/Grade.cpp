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
			if ((strcmp(student.studentinfo.StuNumber , "admin")==0) && (strcmp(student.studentinfo.Password , "admin")==0)) {
				PrintOptions();
			}
			
		}
		
	}
	//****************************************************************
	// Method Name : PrintOptions.									 *
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
			PrintOptionsCourse();
			break;
		case 2:
			PrintOptionsStudent();
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
	//****************************************************************
	// Method Name : PrintOptionsCourse.							 *
	// Parameters : Nothings									     *
	// This method display option and get input from user and call   *
	// function according to user input						         *
	//****************************************************************
	void Grade::PrintOptionsCourse() {
		Course course;
		system("CLS");

		cout << "Plaese choose one option from below......" << endl;
		cout << "1.\tAdd Course." << endl;
		cout << "2.\tDelete Course." << endl;
		cout << "3.\tPrint Course." << endl;
		cout << "4.\tBack to Main Menu." << endl;
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
			course.Add();
			break;
		case 2:
			course.Delete();
			break;
		case 3:
			course.Display();
			break;
		case 4:
			PrintOptions();
			break;
		case 5:
			exit(0);
			break;
		default:
			break;
		}
		PrintOptionsCourse();
	}
	//****************************************************************
	// Method Name : PrintOptionsStudent.							 *
	// Parameters : Nothings									     *
	// This method display option and get input from user and call   *
	// function according to user input						         *
	//****************************************************************
	void Grade::PrintOptionsStudent() {
		Student student;
		system("CLS");

		cout << "Plaese choose one option from below......" << endl;
		cout << "1.\tAdd New Student." << endl;
		cout << "2.\tUpdate Student Info." << endl;
		cout << "3.\tView Student Info." << endl;
		cout << "4.\tDelete Student." << endl;
		cout << "5.\tPrint All Students." << endl;
		cout << "6.\tBack to Main Menu." << endl;
		cout << "7.\tExit." << endl;
		int choice;
		do {
			cout << "Enter your option : ";
			cin >> choice;
		} while (choice<0 || choice>6);

		//call according to choice
		switch (choice)
		{
		case 1:
			student.AddInfo();
			break;
		case 2:
			student.UpdateInfo();
			break;
		case 3:
			student.ViewInfo();
			break;
		case 4:
			student.Delete();
			break;
		case 5:
			student.PrintAllStudents();
			break;
		case 6:
			PrintOptions();
			break;
		case 7:
			exit(0);
			break;
		default:
			break;
		}
		PrintOptionsStudent();
	}
	Grade::~Grade()
	{
	}
}
