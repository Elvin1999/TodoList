#pragma once

#include<iostream>
#include"ToDo.h";
using namespace std;

struct User {
	char* UserName = new char[40]{};
	int password=0;

	ToDo** todus;
	int todo_count = 0;
	int user_count = 0;
};

ToDo& getNewTodos() {
	ToDo* todo = new ToDo;
	cout << "Todo: " << endl;
	cin.ignore();
	cin.clear();
	cin.getline(todo->task, 50);
	return *todo;
}

void AddNewTodo(User& user, const ToDo& todos) {
	auto newTodo = new ToDo * [user.todo_count + 1]{};
	for (int i = 0; i < user.todo_count; i++)
	{
		newTodo[i] = user.todus[i];
	}
	newTodo[user.todo_count] = new ToDo(todos);
	user.todus = newTodo;
	newTodo = nullptr;
	user.todo_count++;
	cout << "New Todo " << todos.task << " Added Succefly! " << endl;



}


void AddTodo2(User& user) {
	int counter = 0;
	cout << "How Many Todo Do you Want Added Todo List?" << endl;
	cin >> counter;
	for (int i = 0; i < counter; i++)
	{
		ToDo todos = getNewTodos();
		AddNewTodo(user, todos);
	}
}




void ShowToDos( ToDo& todos) {
	cout << "<-------------TodoList------------->" << endl;
	cout << "Todo: " << todos.task << " Time: " << __TIME__ << endl;


}


void ShowAllTodos(ToDo** todos, int todo_counter) {
	for (int i = 0; i <todo_counter; i++)
	{
		ShowToDos(*todos[i]);
	}
}

void TodoList(User& user) {
	ShowAllTodos(user.todus, user.todo_count);
}
void EmptyList(User&user) {
	ToDo* todos=new ToDo;
	char answer = ' ';
	
	cout << "Do you complated all task?(Y or N)" << endl;
	cin >> answer;
	if (answer == 'Y') {
		system("cls");
		mysetcolor(2, 0);
		cout << "You Complated All task!" << endl;
		cout << "Good Job!" << endl;
		mysetcolor(7, 0);
		cout << "Do You Add Task?" << endl;
		cin >> answer;
		if (answer == 'Y') {
			while (1) {
				
				AddTodo2(user);
				AddNewTodo(user, *todos);
				TodoList(user);
			}
		}
		else {
			cout << "Okey!" << endl;
		}

	}
	else{
		mysetcolor(4, 0);

		cout << "You have To DO task!" << endl;



	}
}