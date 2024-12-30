#include "Course.h"

using namespace std;

void Course::operator=(Course cour)
{
	courseId = cour.courseId;
	courseName = cour.courseName;
	credits = cour.credits;
}
