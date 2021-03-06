//****************************************************************
// Assignment-1													 *
// Name : Ritesh Patel(200307232) and Parvati Patel(200308239)   *
//****************************************************************
#include "Course.h"
#include "Grade.h"

namespace std {
	Course::Course()
	{
	}
	//****************************************************************
	// Method Name : Add.											 *
	// Parameters :	Nothing											 *
	// Return : Nothing												 *
	// This method allows to add new course if course is not exist 	 * 
	//****************************************************************
	void Course::Add()
	{
		//local variable declaration
		Course course,CourseIn;
		string Name;
		fstream inputFile, outputFile;
		int flag = 0;
		//get input from user
		do {
			system("CLS");
			cout << "Enter Course Name:";
			cin.ignore();
			getline(cin, Name);
		} while (Name.length()>29);
		
		
		
		for (int i = 0; i < Name.length() && i < 30; i++)
		{
			//convert character to upper case
			CourseIn.Name[i] =toupper( Name[i]);
		}
		//check course already added or not.
		inputFile.open("Course.dat", ios::in | ios::binary);
		if (!inputFile)
		{
			//cerr << "Could Not Open File";
		}
		else
		{
			while (!inputFile.eof())
			{
				inputFile.read((char *)(&course), sizeof(course));
				
					if (strcmp(course.Name, CourseIn.Name) == 0) {
						flag++;
						system("CLS");
						cout << "Course Already Added." << endl;
						cin.get();
						//call function again
						Add();
					}
				}
			}
		inputFile.close();
		if (flag == 0) {
			//if not in file add new course
			outputFile.open("Course.dat", ios::app | ios::binary);
			//write data to file
			outputFile.write((char *)(&CourseIn), sizeof(CourseIn));
			outputFile.close();
			cout << "Course Added successfully!" << endl;
			cout << "Press any key to continue....";
			cin.get();
		}		
	}
	//****************************************************************
	// Method Name : Delete.										 *
	// Parameters :	Nothing											 *
	// Return : Nothing												 *
	// This method allows to delete given course from file		 	 * 
	//****************************************************************
	void Course::Delete()
	{

		system("CLS");
		//local variables declaration
		fstream updateFile, tempFile;
		vector<Course> courseVector;
		int flag = 0;
		int CurrentPoint = 0;
		int i = 0;
		string Name;
		Course course, CourseIn;

		do {
			system("CLS");
			cout << "Enter Course Name:";
			cin.ignore();
			getline(cin, Name);
		} while (Name.length()>29);
		
		for (int i = 0; i < Name.length() && i < 30; i++)
		{
			//convert character into upper case.
			CourseIn.Name[i] =toupper( Name[i]);
		}

		updateFile.open("Course.dat", ios::in | ios::out | ios::binary);
		if (updateFile)
		{
			updateFile.read((char *)(&course), sizeof(course));
			while (!updateFile.eof() && flag == 0)
			{
				if (strcmp(course.Name, CourseIn.Name) != 0)
				{
					//add course into vector
					courseVector.push_back(course);
				}
				updateFile.read((char *)(&course), sizeof(course));
			}
		}
		updateFile.close();
		tempFile.open("Course.dat", ios::out | ios::binary);
		for (int i = 0; i<courseVector.size(); i++)
			tempFile.write((char*)(&courseVector[i]), sizeof(course));
		tempFile.close();

		cout << "Course deleted successfully!" << endl;
		cout << "Press any key to continue....";
		cin.get();
		cin.get();

	}
	//****************************************************************
	// Method Name : Display.										 *
	// Parameters :	Nothing											 *
	// Return : Nothing												 *
	// This method display all courses from file				 	 * 
	//****************************************************************
	void Course::Display()
	{
		vector<Course> courseList = getAllCourse();
		for (int i = 0; i < courseList.size(); i++)
		{
			cout << (i + 1) << "\t" << courseList[i].Name << endl;
		}
		cout << "Press any key to continue....";
		cin.get();
		cin.get();
	}
	//****************************************************************
	// Method Name : GetGrade.										 *
	// Parameters :	vector<float> ScoreVector						 *
	// Return :vector<float>										 *
	// This method return vector of score to grade class			 * 
	//****************************************************************
	std::vector<float>  Course::GetGrade(vector<float> ScoreVector)
	{
		vector<Course> courseList = getAllCourse();
		
		float score;
		for (int i = 0; i < courseList.size(); i++)
		{
			cout << "Enter the Grade of " << courseList[i].Name << endl;
			//stackoverflow
			while (!(cin >> score)) {
				cout << "Bad value!";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			ScoreVector.push_back(score);
		}
		return ScoreVector;
	}
	//*****************************************************************
	// Method Name : getAllCourse.								      *
	// Parameters :	Nothing											  *
	// Return : vector<course>	  									  *
	// This method store all course into vector and return that vector* 
	//*****************************************************************
	std::vector<Course> Course::getAllCourse()
	{
		vector<Course> courseList;
		Course course;
		ifstream inputFile;
		inputFile.open("Course.dat", ios::binary);
		if (inputFile)
		{
			inputFile.read((char*)(&course), sizeof(course));
			while (!inputFile.eof()) {
				
				courseList.push_back(course);
				inputFile.read((char*)(&course), sizeof(course));
			}
		}
		return courseList;
	}
	//*****************************************************************
	// Method Name : getCourse.										  *
	// Parameters :	Course class onject								  *
	// Return : string	  											  *
	// This method return course name								  * 
	//*****************************************************************
	string Course::getCourse(Course course) {
		return course.Name;
	}

	

	Course::~Course()
	{
	}
}
