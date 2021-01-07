#include<iostream>
#include"System.h"
#include"ToDo.h";
#include"User.h";

using namespace std;

void main() {
	User* sysem = new User;
	User* uuser = new User;
	ToDo* todos = new ToDo;
	System ssystem;
	User user;
	User* usser;
	AddedUser(ssystem);
	addUser(ssystem,*sysem);
	
	AddTodo2(user);
	AddNewTodo(user, *todos);
	ShowSystem(ssystem);
	cout << endl << endl;
	TodoList(user);
	//cout << "------------------";
	
	char* username = new char[30]{};
	cout << "Go back Login.If You Watch Your Task Input Username And Password!" << endl;
	cout << "Few Second...." << endl;
	Sleep(10000);
	system("cls");
	int pasword = 0;
	cout << "Input Password?" << endl;
	cin>>pasword;
	checkPassword(user, pasword);
	EmptyList(user);


	
	
	
	
	

	//CheckComplatedTask();





	



}