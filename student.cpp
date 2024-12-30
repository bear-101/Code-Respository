#include "Student.h"

using namespace std;


void Student::calava(void)
{
	double allscore;
	int num = 0;
	for (CNODE* cnode = cList.pHead; cnode != NULL; cnode = cnode->next)
	{
		allscore += cnode->course.score;
		num++;
	}
	aveScore = allscore / num;
}
void Student::calgpa(void)
{
	double allscore;
	double allcredit;
	for (CNODE* cnode = cList.pHead; cnode != NULL; cnode = cnode->next)
	{
		allscore += cnode->course.score * cnode->course.credits;
		allcredit += cnode->course.credits;
	}
	studentGpa = allscore / allcredit;
}

