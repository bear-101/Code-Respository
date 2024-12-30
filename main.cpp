#include <iostream>
#include "LinkNode.h"
#include "Course.h"
#include "Student.h"
#include "Menu.h"
#include <fstream>

using namespace std;
int main()
{
	extern StudentList studentlist;
	extern CourseList courselist;

	while (true)
	{
		Menu::displayMenu();
		int choice;
		cin >> choice;
		Menu::handleChoice(choice);
		system("cls");
	}
}