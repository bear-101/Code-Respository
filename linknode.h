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
	void insertCourse(CNODE* pNode);//¼��γ���Ϣ
	CNODE* findCourse(string cName);//ͨ���γ����Ʋ��ҿγ���Ϣ

};

class StudentList
{
public:
	SNODE* pHead = NULL;
	SNODE* findStudent(string studentId);//ͨ��ѧ�Ų���ѧ����Ϣ
	void alterStudent(string studentId);//�޸�ѧ����Ϣ
	void InsertsortStudentsByGpa(SNODE* pNode); //���ռ���ߵͲ���
	void sortStudentsByGpa();//����������
	void outputbyGpa();//չʾ����
	void outputbyScore(string cname);//ָ���γ��������ɼ�����ֲ����
};