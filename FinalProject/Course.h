#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include<vector>
namespace std {
	class Course
	{
	private:
		//variable delaration
		char Name[20] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	public:
		//constructor
		Course();
		~Course();

		//Methods
		void Add();
		void Delete();
		void Display();
		std::vector<Course> getAllCourse();

	};
}
