//****************************************************************
// Assignment-1													 *
// Name : Ritesh Patel(200307232) and Parvati Patel(200308239)   *
//****************************************************************
#pragma once
#include "Student.h"
#include "Course.h"
namespace std {
	class Grade : public Student,public Course
	{
	private :
		vector<float> scoreVector;
		struct GradeInfo
		{
			char StuNumber[10] = { ' ',' ',' ',' ', ' ',' ',' ',' ',' ','\0' };
			char Name[30] = { ' ',' ',' ', ' ',' ',' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
			float Score;
		};
		
	public:
		Grade();
		~Grade();

		//methods declarations
		void addGrade();
		//bool CheckIfUserExist(GradeInfo);
		void updateGrade();
		void deleteGrade();
		void printGrade();

		void Login();
		void PrintOptions();
		void PrintOptionsStudentU();
		void PrintOptionsCourse();
		void PrintOptionsStudent();
		void PrintOptionsGrade();
	};
}

