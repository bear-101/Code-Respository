#pragma once
#include <iostream>
#include <string>

using namespace std;
class Course
{
public:
	string courseId = "";
	string courseName = "";
	double credits = 0;
	double score = 0;
	void operator=(Course cour);
};

struct CNODE//�����γ�����
{
	Course course;
	CNODE* next;
	void operator=(CNODE pNode)
	{
		course = pNode.course;
	}
};
