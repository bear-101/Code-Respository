#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "LinkNode.h"
#include "Course.h"

using namespace std;
//ѧ����
class Student
{
public:
	string studentId = "";
	string studentName = "";
	CourseList cList;
	double aveScore = 0;//�ٷ�������ƽ����
	double studentGpa = 0;//����=��ÿһ��ѧ��*�ٷ��Ƴɼ���/��ѧ��
	void calava(void);
	void calgpa(void);
};
struct SNODE//����ѧ������
{
	Student student;
	SNODE* next;
};
