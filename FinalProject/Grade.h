#pragma once
#include "Student.h"
#include "Course.h"
namespace std {
	class Grade : public Student,public Course
	{
	public:
		Grade();
		~Grade();

		void Login();
		void PrintOptions();
		void PrintOptionsCourse();
		void PrintOptionsStudent();
	};
}

