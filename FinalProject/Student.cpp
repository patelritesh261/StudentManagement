//****************************************************************
// Assignment-1													 *
// Name : Ritesh Patel(200307232) and Parvati Patel(200308239)   *
//****************************************************************
#include "Student.h"

namespace std {

	Student::Student()
	{
	}
	//*****************************************************************
	// Method Name : getStudentInfo.								  *
	// Parameters :	Nothing											  *
	// Return : Student	  											  *
	// This method return studentinfo  structure					  * 
	//*****************************************************************
	Student::studentStruct Student::getStudentInfo() {
		return studentinfo;
	}
	//*****************************************************************
	// Method Name : getStudentAllInfo.								  *
	// Parameters :	studentNum										  *
	// Return : Student	  											  *
	// This method return studentinfo  structure of given student num.*								  * 
	//*****************************************************************
	Student::studentStruct Student::getStudentAllInfo(string studentNum) {

		studentStruct  studentstruct, studentstructIn;
		fstream inputFile;
		int flag = 0;
		int CurrentPoint = 0;
		bool lflag = false;
		//get inputs from users
		for (int j = 0; j < 10; j++)
		{
			studentstructIn.StuNumber[j] = studentNum[j];
		}

		inputFile.open("Student.dat", ios::in | ios::binary);
		if (!inputFile)
		{
			cerr << "Could Not Open File";
		}
		else
		{
			inputFile.read((char *)(&studentstruct), sizeof(studentstruct));
			while (!inputFile.eof())
			{
				if (strcmp(studentstruct.StuNumber, studentstructIn.StuNumber) == 0) {
					//system("CLS");
					studentinfo= studentstruct;
				}
				inputFile.read((char *)(&studentstruct), sizeof(studentstruct));
			}
		}
		inputFile.close();
		return studentinfo;
	}
	//****************************************************************
	// Method Name : Login.											 *
	// Parameters : bool										     *
	// This method get student number and password and call			 *
	// another function to check if it is already exists or not		 *
	//****************************************************************
	bool Student::Login() {
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
	// This method return bool according to given information	     *
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
				if (strcmp(student.StuNumber,studentstruct.StuNumber)==0) {
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

	//****************************************************************
	// Method Name : CheckIfUserExist1.								 *
	// Parameters : Nothings									     *
	// This method return bool according to given information        *
	//****************************************************************
	bool Student::CheckIfUserExist1(studentStruct studentstruct) {
		studentStruct student;
		fstream inputFile;
		int flag = 0;
		bool lflag = false;
		inputFile.open("Student.dat", ios::in | ios::binary);
		if (!inputFile)
		{
			cerr << "Could Not Open File";
		}
		else
		{
			while (!inputFile.eof())
			{
				inputFile.read((char *)(&student), sizeof(student));
				if (strcmp(student.StuNumber, studentstruct.StuNumber) == 0) {
						lflag = true;
						flag++;
				}
			}
		}
		inputFile.close();
		return lflag;
	}
	//*****************************************************************
	// Method Name : AddInfo.										  *
	// Parameters :	Nothing											  *
	// Return : Nothing	  											  *
	// This method add new student information if it doesn't exists	  * 
	//*****************************************************************
	void Student::AddInfo() {
		studentStruct studentstructIn, studentstruct;
		fstream inputFile;
		int flag = 0;
		bool lflag = false;
		string address, pincode,studentName,progName;
		//get inputs from users
		cout << "Enter Student ID :\t";
		cin >> studentstructIn.StuNumber;
		inputFile.open("Student.dat", ios::in | ios::binary);
		if (!inputFile)
		{
			cerr << "Could Not Open File";
		}
		else
		{
			while (!inputFile.eof())
			{
				inputFile.read((char *)(&studentstruct), sizeof(studentstruct));
				if (strcmp(studentstruct.StuNumber, studentstructIn.StuNumber) == 0) {
					system("CLS");
					cout << "Student already registered." << endl;
						flag++;
					}
			}
		}
		inputFile.close();
		if (flag == 0) {			
			cout << "Password (yymmdd) :\t";
			cin >> studentstructIn.Password;
			do {
				cout << "Student Name :\t";
				cin.ignore();
				getline(cin, studentName);
			} while (studentName.length()>19);
			do {
				cout << "Program Name :\t";
				//cin.ignore();
				getline(cin, progName);
			} while (progName.length()>19);
			do {
				cout << "Street Address :\t";
				//cin.ignore();
				getline(cin, address);
			} while (address.length()>19);
			cout << "City :\t";
			cin >> studentstructIn.studentinfo.City;
			do {
				cout << "Pincode :\t";
				cin.ignore();
				getline(cin, pincode);
			} while (pincode.length()>7);
			//cin >> studentstructIn.studentinfo.PCode;
			for (int i = 0; i < 8 && i < pincode.length(); i++) {
				studentstructIn.studentinfo.PCode[i] = pincode[i];
			}
			for (int i = 0; i < 20 && i<address.length(); i++) {
				studentstructIn.studentinfo.StAddr[i] = address[i];
			}
			for (int i = 0; i < 20 && i<studentName.length(); i++) {
				studentstructIn.studentinfo.StuName[i] = studentName[i];
			}
			for (int i = 0; i < 20 && i<progName.length(); i++) {
				studentstructIn.studentinfo.ProName[i] = progName[i];
			}
			inputFile.open("Student.dat", ios::app | ios::binary);
			//write data to file
			inputFile.write((char *)(&studentstructIn), sizeof(studentstructIn));
			inputFile.close();
			cout << "Student Added successfully!" << endl;
			cout << "Press any key to continue....";
			cin.get();
			lflag = true;
			flag++;
		}
	}
	//*****************************************************************
	// Method Name : UpdateInfo.									  *
	// Parameters :	Nothing											  *
	// Return : Nothing	  											  *
	// This method Update student information						  * 
	//*****************************************************************
	void Student::UpdateInfo() {
		studentStruct studentstructIn, studentstruct;
		vector<studentStruct> studentstructVector;
		string address, pincode, studentName, progName;
		fstream inputFile, tempFile;
		int flag = 0;
		int CurrentPoint = 0;
		bool lflag = false;
		//get inputs from users
		cout << "Enter Student ID :\t";
		cin >> studentstructIn.StuNumber;


		inputFile.open("Student.dat", ios::in | ios::out | ios::binary);
		if (!inputFile)
		{
			cerr << "Could Not Open File";
		}
		else
		{
			inputFile.read((char *)(&studentstruct), sizeof(studentstruct));
			while (!inputFile.eof() && flag == 0)
			{
				
				CurrentPoint = inputFile.tellg();
				if (strcmp(studentstruct.StuNumber, studentstructIn.StuNumber) == 0) {
					system("CLS");
					
					//get user input from user
					cout << "Password (yymmdd) :\t";
					cin >> studentstructIn.Password;
					do {
						cout << "Student Name :\t";
						cin.ignore();
						getline(cin, studentName);
					} while (studentName.length()>19);
					do {
						cout << "Program Name :\t";
						//cin.ignore();
						getline(cin, progName);
					} while (progName.length()>19);
					do {
						cout << "Street Address :\t";
						//cin.ignore();
						getline(cin, address);
					} while (address.length()>19);
					cout << "City :\t";
					cin >> studentstructIn.studentinfo.City;
					do {
						cout << "Pincode :\t";
						cin.ignore();
						getline(cin, pincode);
					} while (pincode.length()>7);

					for (int i = 0; i < 8 && i < pincode.length(); i++) {
						studentstructIn.studentinfo.PCode[i] = pincode[i];
					}
					for (int i = 0; i < 20 && i<address.length(); i++) {
						studentstructIn.studentinfo.StAddr[i] = address[i];
					}
					for (int i = 0; i < 20 && i<studentName.length(); i++) {
						studentstructIn.studentinfo.StuName[i] = studentName[i];
					}
					for (int i = 0; i < 20 && i<progName.length(); i++) {
						studentstructIn.studentinfo.ProName[i] = progName[i];
					}

					studentstructVector.push_back(studentstructIn);
					flag++;
				}
				else
				{
					studentstructVector.push_back(studentstruct);
				}
				inputFile.read((char *)(&studentstruct), sizeof(studentstruct));

			}
		}
		inputFile.close();
		tempFile.open("Student.dat", ios::out | ios::binary);
		for (int i = 0; i<studentstructVector.size(); i++)
			tempFile.write((char*)(&studentstructVector[i]), sizeof(studentstruct));
		tempFile.close();
		cout << "Student Information Updated Succeessfully." << endl;
		cout << "Press any key to continue....";
		cin.get();
		cin.get();
	}
	//*****************************************************************
	// Method Name : ViewInfo.										  *
	// Parameters :	Nothing											  *
	// Return : Nothing	  											  *
	// This method shows the student information of given student num.* 
	//*****************************************************************
	void Student::ViewInfo() {
		studentStruct studentstructIn, studentstruct;
		fstream inputFile;
		int flag = 0;
		int CurrentPoint = 0;
		bool lflag = false;
		//get inputs from users
		cout << "Enter Student ID :\t";
		cin >> studentstructIn.StuNumber;


		inputFile.open("Student.dat", ios::in | ios::binary);
		if (!inputFile)
		{
			cerr << "Could Not Open File";
		}
		else
		{
			inputFile.read((char *)(&studentstruct), sizeof(studentstruct));
			while (!inputFile.eof())
			{
				
				if (strcmp(studentstruct.StuNumber, studentstructIn.StuNumber) == 0) {
					//get user input from user
					cout << "Student ID :\t" << studentstruct.StuNumber << endl;
					cout << "Password :\t"<< studentstruct.Password<<endl;
					cout << "Student Name :\t"<< studentstruct.studentinfo.StuName << endl;
					cout << "Program Name :\t"<< studentstruct.studentinfo.ProName << endl;
					cout << "Street Address :\t"<< studentstruct.studentinfo.StAddr << endl;
					cout << "City :\t"<< studentstruct.studentinfo.City << endl;
					cout << "Pincode :\t"<< studentstruct.studentinfo.PCode << endl;

					flag++;
				}
					inputFile.read((char *)(&studentstruct), sizeof(studentstruct));


			}
		}
		inputFile.close();
		cout << "Press any key to continue....";
		cin.get();
		cin.get();
	}
	//*****************************************************************
	// Method Name : Delete.										  *
	// Parameters :	Nothing											  *
	// Return : Nothing	  											  *
	// This method delete student form file of giving student num.	  * 
	//*****************************************************************
	void Student::Delete() {
		system("CLS");
		fstream updateFile, tempFile;
		studentStruct studentstruct,studentstructIn;
		vector<studentStruct> studentstructVector;
		int flag = 0;
		int CurrentPoint = 0;
		int i = 0;

		//get inputs from users
		cout << "Enter Student ID :\t";
		cin >> studentstructIn.StuNumber;

		updateFile.open("Student.dat", ios::in | ios::out | ios::binary);
		if (updateFile)
		{
			while (!updateFile.eof() && flag == 0)
			{
				updateFile.read((char *)(&studentstruct), sizeof(studentstruct));
				if (strcmp(studentstruct.StuNumber, studentstructIn.StuNumber) != 0)
				{
					//add users into vector
					studentstructVector.push_back(studentstruct);
				}
			}
		}
		updateFile.close();
		tempFile.open("Student.dat", ios::out | ios::binary);
		for (int i = 0; i<studentstructVector.size(); i++)
			tempFile.write((char*)(&studentstructVector[i]), sizeof(studentstruct));
		tempFile.close();

		cout << "Student deleted successfully!" << endl;
		cout << "Press any key to continue....";
		cin.get();
		cin.get();
	}
	//****************************************************************
	// Method Name : AddNewUser.									 *
	// Parameters : Nothings									     *
	// This method add new user into file						     *
	//****************************************************************
	void Student::AddNewStudent(studentStruct studentstruct) {
		fstream outputFile;
		studentStruct studentstructIn;
		
		outputFile.open("Student.dat", ios::app | ios::binary);
		//write data to file
		outputFile.write((char *)(&studentstruct), sizeof(studentstruct));
		outputFile.close();

		cout << "Student Added successfully!" << endl;
		cout << "Press any key to continue....";
		cin.get();
	}
	//*****************************************************************
	// Method Name : PrintAllStudents.								  *
	// Parameters :	Nothing											  *
	// Return : Nothing	  											  *
	// This method display all students list						  * 
	//*****************************************************************
	void Student::PrintAllStudents() {
		studentStruct studentstructIn, studentstruct;
		fstream inputFile;
	
		inputFile.open("Student.dat", ios::in | ios::binary);
		if (!inputFile)
		{
			cerr << "Could Not Open File";
		}
		else
		{
			system("CLS");
			printf("%6s %10s %15s %16s %17s %18s %19s\n\n", "Student ID", "Password", "Student Name", "Program Name","Street Address","City","Pincode");
			inputFile.read((char *)(&studentstruct), sizeof(studentstruct));
			while (!inputFile.eof())
			{
				if ((strcmp(studentstruct.StuNumber, "admin") == 0) && (strcmp(studentstruct.Password, "admin") == 0)) {
					
				}
				else {
					printf("%6s %10s %15s %16s %17s %18s %19s\n", studentstruct.StuNumber, studentstruct.Password, studentstruct.studentinfo.StuName, studentstruct.studentinfo.ProName, studentstruct.studentinfo.StAddr, studentstruct.studentinfo.City, studentstruct.studentinfo.PCode);
					
				}
				inputFile.read((char *)(&studentstruct), sizeof(studentstruct));
			}
		}
		inputFile.close();
		cout << "Press any key to continue....";
		cin.get();
		cin.get();
	}
	Student::~Student()
	{
	}
}
