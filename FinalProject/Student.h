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
			long StuNumber = 0;
			char Password[6] = { ' ',' ',' ',' ',' ','\0' };
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
		bool Login();
		bool CheckIfUserExist(studentStruct);
		void UpdateInfo(studentStruct);
		void ViewInfo(studentStruct);
		void Delete(studentStruct);
		void AddNewStudent(studentStruct);
		void PrintOptions(studentStruct);
	};

}