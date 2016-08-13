#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include<vector>

namespace std {
	 class Student 
	{
	private:
		//strucure declaration
		struct studentInfo
		{
			//variable declaration
			char StuName[20] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
			char ProName[20] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };

			char StAddr[20] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
			char City[10] = { ' ',' ',' ',' ',' ',' ',' ',' ','\0' };
			char PCode[7] = { ' ',' ',' ',' ',' ',' ','\0' };
		};
		struct studentStruct
		{
			//variable declaration
			char StuNumber[10] = {' ',' ',' ',' ', ' ',' ',' ',' ',' ','\0' };
			char Password[10] = {' ', ' ',' ',' ',' ',' ','\0' };
			studentInfo studentinfo;
		};


	public:
		//Constructor
		studentStruct studentinfo;
		Student();
		Student(long, string);
		~Student();

		//Method Declration
		void setStudentInfo(string, string);
		studentStruct getStudentInfo();
		studentStruct getStudentAllInfo();
		bool Login();
		bool CheckIfUserExist(studentStruct);
		bool CheckIfUserExist1(studentStruct);
		void AddInfo();
		void UpdateInfo();
		void ViewInfo();
		void Delete();
		void PrintAllStudents();
		void AddNewStudent(studentStruct);
		void PrintOptions(studentStruct);
	};

}