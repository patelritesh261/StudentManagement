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
		struct student
		{
			//variable declaration
			long StuNumber = 0;
			char Password[6] = { ' ',' ',' ',' ',' ','\0' };
			studentInfo studentinfo;
		};


	public:
		//Constructor
		Student();
		~Student();

		//Method Declration
		void Login();
		void CheckIfUserExist(student);
		void UpdateInfo(student);
		void ViewInfo(student);
		void Delete(student);
	};

}