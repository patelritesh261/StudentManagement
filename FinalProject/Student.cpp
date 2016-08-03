#include "Student.h"

namespace std {

	Student::Student()
	{
	}
	Student::Student(long studentID,string password)
	{
		
		studentinfo.StuNumber = studentID;
		//strncpy(studentinfo.Password, password.c_str(), sizeof(password));
		//.studentinfo.Password[sizeof(studentinfo.Password) - 1] = 0;

	}
	Student::studentStruct Student::getStudentInfo() {
		
		return studentinfo;
	}
	//****************************************************************
	// Method Name : Login.											 *
	// Parameters : bool										     *
	// This method get student number and password and call			 *
	// another function to check if it is already exists or not		 *
	//****************************************************************
	bool Student::Login() {
		//studentStruct student;
		//get login infotmation

		cout << "Student Number :\t";
		cin >> studentinfo.StuNumber;
		cout << "Password : \t";
		cin >> studentinfo.Password;

		bool flag=CheckIfUserExist(studentinfo);
		return flag;
	}
	//****************************************************************
	// Method Name : CheckIfUserExist.								 *
	// Parameters : Nothings									     *
	// This method just call another function for further execution  *
	//****************************************************************
	bool Student::CheckIfUserExist(studentStruct studentstruct) {
		studentStruct student;
		fstream inputFile;
		int flag = 0;
		bool lflag = false;
		inputFile.open("Student.dat", ios::in | ios::binary);
		if (!inputFile)
		{
			cerr<<"Could Not Open File";
		}
		else
		{
			while (!inputFile.eof())
			{
				inputFile.read((char *)(&student), sizeof(student));
				if (student.StuNumber ==studentstruct.StuNumber) {
					if (strcmp(student.Password, studentstruct.Password) == 0) {
						//if password and student number match than call print option menu.
						//PrintOptions(studentstruct);
						lflag = true;
						flag++;
					}
					else
					{
						system("CLS");
						cout << "Wrong Password!" << endl;
						//if password is wrong than call login function again.
						Login();
						flag++;
					}
				}
			}
		}
		inputFile.close();
		if (flag == 0) {
			//if user is new add into file and print options.
			AddNewStudent(studentstruct);
			//PrintOptions(studentstruct);
			lflag = true;
			flag++;
		}
		return lflag;
	}
	void Student::UpdateInfo(studentStruct studentstruct) {

	}
	void Student::ViewInfo(studentStruct studentstruct) {

	}
	void Student::Delete(studentStruct studentstruct) {

	}
	//****************************************************************
	// Method Name : AddNewUser.									 *
	// Parameters : Nothings									     *
	// This method add new user into file						     *
	//****************************************************************
	void Student::AddNewStudent(studentStruct studentstruct) {
		fstream outputFile;
		outputFile.open("Student.dat", ios::app | ios::binary);
		//write data to file
		outputFile.write((char *)(&studentstruct), sizeof(studentstruct));
		outputFile.close();

		cout << "Student Added successfully!" << endl;
		cout << "Press any key to continue....";
		cin.get();
		cin.get();
	}
	//****************************************************************
	// Method Name : PrintMenu.										 *
	// Parameters : Nothings									     *
	// This method display option and get input from user and call   *
	// function according to user input						         *
	//****************************************************************
	void Student::PrintOptions(studentStruct userstruct) {
		system("CLS");
		cout << "Plaese choose one option from below......" << endl;
		cout << "1.\tAdd/Delete/View Course" << endl;
		cout << "2.\tView User Profile." << endl;
		cout << "3.\tSet High Score." << endl;
		cout << "4.\tPrint All High Score." << endl;
		cout << "5.\tDelete." << endl;
		cout << "6.\tExit." << endl;
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
			
			break;
		case 6:
			exit(0);
			break;
		default:
			break;
		}
		PrintOptions(userstruct);
	}
	Student::~Student()
	{
	}
}
