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
			char Name[20] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
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
		void PrintOptionsCourse();
		void PrintOptionsStudent();
		void PrintOptionsGrade();
	};
}

