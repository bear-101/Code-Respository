#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Course.h"
#include "Student.h"

using namespace std;


class CourseList
{
public:
	CNODE* pHead = NULL;
	void insertCourse(CNODE* pNode);//录入课程信息
	CNODE* findCourse(string cName);//通过课程名称查找课程信息

};

class StudentList
{
public:
	SNODE* pHead = NULL;
	SNODE* findStudent(string studentId);//通过学号查找学生信息
	void alterStudent(string studentId);//修改学生信息
	void InsertsortStudentsByGpa(SNODE* pNode); //按照绩点高低插入
	void sortStudentsByGpa();//按绩点排序
	void outputbyGpa();//展示绩点
	void outputbyScore(string cname);//指定课程排名、成绩及其分布情况
};