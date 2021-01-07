#pragma once
#include<iostream>
#include"User.h"
#include"Helper.h"
using namespace std;

struct ToDo {
	char* task = new char[30];
	char* FullDateTime = new char[100]{ __DATE__ };
	
	bool isDone = false;
};









