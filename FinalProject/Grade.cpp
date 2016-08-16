//****************************************************************
// Assignment-1													 *
// Name : Ritesh Patel(200307232) and Parvati Patel(200308239)   *
//****************************************************************
#include "Grade.h"

namespace std {

	Grade::Grade()
	{
	}
	//*****************************************************************
	// Method Name : Login.											  *
	// Parameters :	Nothing											  *
	// Return : Nothing	  											  *
	// This method call another lodin method of student class.		  * 
	//*****************************************************************
	void Grade::Login() {
		Student student;
		studentinfo= student.getStudentInfo();
		bool flag=student.Login();
		if (flag) {
			student.studentinfo = student.getStudentInfo();
			if ((strcmp(student.studentinfo.StuNumber , "admin")==0) && (strcmp(student.studentinfo.Password , "admin")==0)) {
				PrintOptions();
			}
			else {
				PrintOptionsStudentU();
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
		
		char choice;
		do {
			system("CLS");
			cout << "Plaese choose one option from below......" << endl;
			cout << "1.\tManage Course." << endl;
			cout << "2.\tManage Student." << endl;
			cout << "3.\tManage Grade." << endl;
			cout << "4.\tGo To Student Section." << endl;
			cout << "5.\tExit." << endl;
			cout << "Enter your option : ";
			cin >> choice;
		} while (choice<48 || choice>54);

		//call according to choice
		switch (choice)
		{
		case '1':
			PrintOptionsCourse();
			break;
		case '2':
			PrintOptionsStudent();
			break;
		case '3':
			PrintOptionsGrade();
			break;
		case '4':
			system("CLS");
			Login();
			break;
		case '5':
			exit(0);
			break;
		default:
			break;
		}
		PrintOptions();
	}
	//****************************************************************
	// Method Name : PrintOptionsStudent.									 *
	// Parameters : Nothings									     *
	// This method display option and get input from user and call   *
	// function according to user input						         *
	//****************************************************************
	void Grade::PrintOptionsStudentU() {
		
		char choice;
		do {
			system("CLS");
			cout << "Plaese choose one option from below......" << endl;
			cout << "1.\tView Grade Report." << endl;
			cout << "2.\tExit." << endl;
			cout << "Enter your option : ";
			cin >> choice;
		} while (choice<48 || choice>50);

		//call according to choice
		switch (choice)
		{
		case '1':
			printGrade();
			break;
		case '2':
			exit(0);
			break;
		default:
			break;
		}
		PrintOptionsStudentU();
	}
	//****************************************************************
	// Method Name : PrintOptionsCourse.							 *
	// Parameters : Nothings									     *
	// This method display option and get input from user and call   *
	// function according to user input						         *
	//****************************************************************
	void Grade::PrintOptionsCourse() {
		Course course;
		
		char choice;
		do {
			system("CLS");
			cout << "Plaese choose one option from below......" << endl;
			cout << "1.\tAdd Course." << endl;
			cout << "2.\tDelete Course." << endl;
			cout << "3.\tPrint Course." << endl;
			cout << "4.\tBack to Main Menu." << endl;
			cout << "5.\tExit." << endl;
			cout << "Enter your option : ";
			cin >> choice;
		} while (choice<48 || choice>54);

		//call according to choice
		switch (choice)
		{
		case '1':
			course.Add();
			break;
		case '2':
			course.Delete();
			break;
		case '3':
			course.Display();
			break;
		case '4':
			PrintOptions();
			break;
		case '5':
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
		
		char choice;
		do {
			system("CLS");
			cout << "Plaese choose one option from below......" << endl;
			cout << "1.\tAdd New Student." << endl;
			cout << "2.\tUpdate Student Info." << endl;
			cout << "3.\tView Student Info." << endl;
			cout << "4.\tDelete Student." << endl;
			cout << "5.\tPrint All Students." << endl;
			cout << "6.\tBack to Main Menu." << endl;
			cout << "7.\tExit." << endl;
			cout << "Enter your option : ";
			cin >> choice;
		} while (choice<48 || choice>55);

		//call according to choice
		switch (choice)
		{
		case '1':
			student.AddInfo();
			break;
		case '2':
			student.UpdateInfo();
			break;
		case '3':
			student.ViewInfo();
			break;
		case '4':
			student.Delete();
			break;
		case '5':
			student.PrintAllStudents();
			break;
		case '6':
			PrintOptions();
			break;
		case '7':
			exit(0);
			break;
		default:
			break;
		}
		PrintOptionsStudent();
	}
	//****************************************************************
	// Method Name : PrintOptionsGrade.								 *
	// Parameters : Nothings									     *
	// This method display option and get input from user and call   *
	// function according to user input						         *
	//****************************************************************
	void Grade::PrintOptionsGrade() {
		
		char choice;
		do {
			system("CLS");
			cout << "Plaese choose one option from below......" << endl;
			cout << "1.\tAdd Grade." << endl;
			cout << "2.\tUpdate Grade." << endl;
			cout << "3.\tDelete Grade." << endl;
			cout << "4.\tPrint Grade." << endl;
			cout << "5.\tBack to Main Menu." << endl;
			cout << "6.\tExit." << endl;
			cout << "Enter your option : ";
			cin >> choice;
		} while (choice<48 || choice>54);

		//call according to choice
		switch (choice)
		{
		case '1':
			addGrade();
			break;
		case '2':
			updateGrade();
			break;
		case '3':
			deleteGrade();
			break;
		case '4':
			printGrade();
			break;
		case '5':
			PrintOptions();
			break;
		case '6':
			exit(0);
			break;
		default:
			break;
		}
		PrintOptionsGrade();
	}
	//*****************************************************************
	// Method Name : addGrade.										  *
	// Parameters :	Nothing											  *
	// Return : Nothing	  											  *
	// This method add student grade to grade file					  * 
	//*****************************************************************
	void Grade::addGrade() {
		GradeInfo grade,gradeIn;
		fstream inputFile;
		int flag = 0;
		bool lflag = false;
		Student student;
		fstream outputFile;
		vector<Course> courseVector;
		vector<float> ScoreVector;
		Course course;
		string courseName;
		GradeInfo gradeinfo;
		//get inputs from users
		cout << "Enter Student ID :\t";
		cin >> studentinfo.StuNumber;
		bool check = CheckIfUserExist1(studentinfo);
		if (check) {
			inputFile.open("Grade.dat", ios::in | ios::binary);
			if (!inputFile)
			{
				//cerr << "Could Not Open File";
			}
			else
			{
				inputFile.read((char *)(&grade), sizeof(grade));
				while (!inputFile.eof())
				{
					if (strcmp(grade.StuNumber, studentinfo.StuNumber) == 0) {
						lflag = true;
						flag++;
					}
					inputFile.read((char *)(&grade), sizeof(grade));
				}
			}
			inputFile.close();
			if (flag == 0) {
				courseVector = course.getAllCourse();
				ScoreVector = course.GetGrade(ScoreVector);
				outputFile.open("Grade.dat", ios::app | ios::binary);
				for (int j = 0; j < 10; j++)
				{
					gradeIn.StuNumber[j] = studentinfo.StuNumber[j];
				}
				//pass value to grade
				for (int i = 0; i < ScoreVector.size(); i++) {
					//get course name
					courseName = course.getCourse(courseVector[i]);
					for (int i = 0; i < courseName.length(); i++)
					{
						gradeIn.Name[i] = courseName[i];
					}
					gradeIn.Score = ScoreVector[i];
					outputFile.write((char *)(&gradeIn), sizeof(gradeIn));
				}
				outputFile.close();
				cout << "Grades Added successfully!" << endl;
				cout << "Press any key to continue....";
				cin.get();
				cin.get();
			}
			else {
				cout << "Grade already added for this student."<<endl;
				cout << "Press any key to continue....";
				cin.get();
				cin.get();
			}
		}
		else {
			cout << "Student is not registered."<<endl;
			cout << "Press any key to continue....";
			cin.get();
			cin.get();
		}
	}
	//*****************************************************************
	// Method Name : updateGrade.									  *
	// Parameters :	Nothing											  *
	// Return : Nothing	  											  *
	// This method update grade of specific student Num.			  * 
	//*****************************************************************
	void Grade::updateGrade(){
		GradeInfo gradeInfoIn, gradeInfo;
		vector<GradeInfo> gradeInfoVector;
		fstream inputFile, tempFile;
		//get inputs from users
		cout << "Enter Student ID :\t";
		cin >> gradeInfoIn.StuNumber;

		inputFile.open("Grade.dat", ios::in | ios::out | ios::binary);
		if (!inputFile)
		{
			cerr << "Could Not Open File";
		}
		else
		{
			system("CLS");
			inputFile.read((char *)(&gradeInfo), sizeof(gradeInfo));
			while (!inputFile.eof())
			{
				if (strcmp(gradeInfo.StuNumber, gradeInfoIn.StuNumber) == 0) {
					//get user input from user
					cout << "Enter the grade of " << gradeInfo.Name << endl;
					//stackoverflow
					while (!(cin >> gradeInfo.Score)) {
						cout << "Bad value!";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					gradeInfoVector.push_back(gradeInfo);
				}
				else
				{
					gradeInfoVector.push_back(gradeInfo);
				}
				inputFile.read((char *)(&gradeInfo), sizeof(gradeInfo));
			}
		}
		inputFile.close();
		tempFile.open("Grade.dat", ios::out | ios::binary);
		for (int i = 0; i<gradeInfoVector.size(); i++)
			tempFile.write((char*)(&gradeInfoVector[i]), sizeof(gradeInfo));
		tempFile.close();
		cout << "Grade Updated Succeessfully." << endl;
		cout << "Press any key to continue....";
		cin.get();
		cin.get();
		
	}
	//*****************************************************************
	// Method Name : deleteGrade.									  *
	// Parameters :	Nothing											  *
	// Return : Nothing	  											  *
	// This method delete geade of specific student Num.			  * 
	//*****************************************************************
	void Grade::deleteGrade() {
		GradeInfo gradeInfoIn, gradeInfo;
		vector<GradeInfo> gradeInfoVector;
		fstream inputFile, tempFile;
		//get inputs from users
		cout << "Enter Student ID :\t";
		cin >> gradeInfoIn.StuNumber;

		inputFile.open("Grade.dat", ios::in | ios::out | ios::binary);
		if (!inputFile)
		{
			cerr << "Could Not Open File";
		}
		else
		{
			inputFile.read((char *)(&gradeInfo), sizeof(gradeInfo));
			system("CLS");
			while (!inputFile.eof())
			{
				if (strcmp(gradeInfo.StuNumber, gradeInfoIn.StuNumber) == 0) {
				}
				else
				{
					gradeInfoVector.push_back(gradeInfo);
				}
				inputFile.read((char *)(&gradeInfo), sizeof(gradeInfo));
			}
		}
		inputFile.close();
		tempFile.open("Grade.dat", ios::out | ios::binary);
		for (int i = 0; i<gradeInfoVector.size(); i++)
			tempFile.write((char*)(&gradeInfoVector[i]), sizeof(gradeInfo));
		tempFile.close();
		cout << "Grade Deleted Succeessfully." << endl;
		cout << "Press any key to continue....";
		cin.get();
		cin.get();
	}
	//*****************************************************************
	// Method Name : printGrade										  *
	// Parameters :	Nothing											  *
	// Return : Nothing	  											  *
	// This method print grade of student num.						  * 
	//*****************************************************************
	void Grade::printGrade() {
		GradeInfo gradeInfoIn, gradeInfo;
		Student student;
		vector<GradeInfo> gradeInfoVector;
		fstream inputFile;
		float Total = 0;
		//get inputs from users
		cout << "Enter Student ID :\t";
		cin >> gradeInfoIn.StuNumber;

		inputFile.open("Grade.dat", ios::in | ios::out | ios::binary);
		if (!inputFile)
		{
			cerr << "Could Not Open File";
		}
		else
		{
			inputFile.read((char *)(&gradeInfo), sizeof(gradeInfo));
			system("CLS");
			//get student information
			studentinfo = student.getStudentAllInfo(gradeInfoIn.StuNumber);
			while (!inputFile.eof())
			{
				if (strcmp(gradeInfo.StuNumber, gradeInfoIn.StuNumber) == 0) {
					//store values in vector
					gradeInfoVector.push_back(gradeInfo);
				}
				inputFile.read((char *)(&gradeInfo), sizeof(gradeInfo));
			}
		}
		inputFile.close();
		//print result
		system("CLS");
		cout << "\n******************************** Student Basic Information *****************************************\n";
		cout << "Student Number :\t" << studentinfo.StuNumber << endl;
		cout << "Name :\t\t\t" << studentinfo.studentinfo.StuName << endl;
		cout << "Program Name :\t\t" << studentinfo.studentinfo.ProName << endl;
		cout << "Address :\t\t" << studentinfo.studentinfo.StAddr << endl;
		cout << "City :\t\t\t" << studentinfo.studentinfo.City << endl;
		cout << "Pin Code :\t\t" << studentinfo.studentinfo.PCode << endl;
		cout << "\n******************************** Grade **************************************************************\n";
		//printf("%10s %12s\n", "Course Name", "Grade");
		for (int i = 0; i < gradeInfoVector.size(); i++)
		{
			printf("%s : %.2f\n",gradeInfoVector[i].Name, gradeInfoVector[i].Score);
			Total += gradeInfoVector[i].Score;
		}
		cout << "\n****************************************************************************************************\n";
		printf("%s : %.2f\n", "Total Marks", Total);
		printf("%s : %.2f\n", "Percentage", Total/ gradeInfoVector.size());
		cout << "\n****************************************************************************************************\n";

		cout << "Press any key to continue....";
		cin.get();
		cin.get();
	}
	Grade::~Grade()
	{
	}
}
