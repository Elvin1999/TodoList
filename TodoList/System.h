#pragma once
#include<iostream>
#include"User.h"
using namespace std;


struct System {
	User** users;
	int user_count = 0;
	
	
};

User& getuser() {
	User* user = new User;
	cout << "User Name: " << endl;
	cin.ignore();
	cin.clear();
	cin.getline(user->UserName, 50);
	cout << "Input Password: " << endl;
	cin >> user->password;
	return *user;
}
void addUser(System& system, const User& user) {
	auto NewUSer = new User * [system.user_count + 1]{};
	
	
	for (int i = 0; i < system.user_count; i++)
	{
		NewUSer[i] = system.users[i];
		
	}
	NewUSer[system.user_count] = new User(user);
	system.users = NewUSer;
	NewUSer = nullptr;
	system.user_count++;
	cout << "New User: " << user.UserName << "Added System Succefly: " << endl;

}	

void addPassword(System& system, const User& user) {

}

void AddedUser (System& system) {
	int counter = 0;
	cout << "How Many User do you want added System?" << endl;
	cin >> counter;
	for (int i = 0; i < counter; i++)
	{
		User user = getuser();
		addUser(system, user);
	}
	


}



void showUsers(User& user) {
	
	cout << "<-----------------User Info-------------->" << endl;
	cout << "User Name: " << user.UserName << endl;
	cout << "User PassWord: " << user.password << endl;
	
	
}

void showAllUsers(User** user, int user_count) {
	for (int i = 0; i < user_count; i++)
	{
		showUsers(*user[i]);
	}
}

void ShowSystem(System& system) {
	showAllUsers(system.users, system.user_count);
}


void checkPassword(User& user, int password) {
	
	if (password == user.password) {
		system("cls");

		TodoList(user);
		EmptyList(user);
	}
	else {
		mysetcolor(4, 0);
		cout << "Wrong Password!" << endl;
	}
}

