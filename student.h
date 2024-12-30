#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "LinkNode.h"
#include "Course.h"

using namespace std;
//学生类
class Student
{
public:
	string studentId = "";
	string studentName = "";
	CourseList cList;
	double aveScore = 0;//百分制算术平均分
	double studentGpa = 0;//绩点=（每一科学分*百分制成绩）/总学分
	void calava(void);
	void calgpa(void);
};
struct SNODE//创建学生链表
{
	Student student;
	SNODE* next;
};
