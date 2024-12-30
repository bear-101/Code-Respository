#pragma once
#include "LinkNode.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Menu
{
public:
	Menu();
	static void displayMenu();
	static void handleChoice(int choice);
};
