#include<iostream>
#include<Windows.h>
using namespace std;
static int myid = 0;
struct Worker {
	int id;
	char* name = new char[50]{};
	char* surname = new char[50]{};
	int age;
	double salary;
	char* city = new char[20]{};
	double workPractice;
	char* speciality = new char[50];
};

struct Ceo {
	char* name = new char[20]{ "Pervane" };
	char* surname = new char[20]{ "Sdiqova" };
	int age = 22;
};

struct Company {
	char* name = new char[50]{};
	Worker* workers;
	int count = 0;
	Ceo ceo;
};

void addWorker(Company& company, const Worker& newworker) {

	int count = company.count;
	auto workers = new Worker[count + 1]{};
	for (int i = 0; i < count; i++) {
		workers[i] = company.workers[i];
	}
	workers[count] = newworker;
	if (company.count != 0)
		delete[]company.workers;
	company.workers = workers;
	workers = nullptr;
	company.count++;
	system("cls");
}
void showWorker(const Worker& worker);
void showAllWorkers(const Company& company) {

	for (int i = 0; i < company.count; i++) {

		showWorker(company.workers[i]);
	}
}
void showCeo(Ceo ceo) {

	cout << endl << "+++++++++++++++++++++++++++++" << endl << endl;
	cout << "CEO Name :    " << ceo.name << endl;
	cout << "CEO surname : " << ceo.surname << endl;
	cout << "CEO Age :     " << ceo.age << endl;
	cout << endl << "+++++++++++++++++++++++++++++" << endl << endl;
}
void showCompany(const Company& company) {

	cout << "Company Name : " << company.name << endl;
	cout << endl << "+++++++++++++++++++++++++++++" << endl << endl;
	showCeo(company.ceo);

	cout << "Number of people in company : " << company.count << endl;
	cout << endl << "+++++++++++++++++++++++++++++" << endl << endl;


	cout << "\tWorkers : " << endl;
	showAllWorkers(company);


}

void showWorker(const Worker& worker) {

	cout << endl << "+++++++++++++++++++++++++++++" << endl;
	cout << "\nId :         " << worker.id << endl;
	cout << "Name :       " << worker.name << endl;
	cout << "Surname :    " << worker.surname << endl;
	cout << "Age :        " << worker.age << endl;
	cout << "Salary :     " << worker.salary << " $" << endl;
	cout << "City :       " << worker.city << endl;
	cout << "Practice :   " << worker.workPractice << " year" << endl;
	cout << "Speciality : " << worker.speciality << endl;
	cout << endl << "+++++++++++++++++++++++++++++" << endl;
}

void showWorkersSalaryMoreThan1000(Company& company) {

	int counter = 0;
	for (int i = 0; i < company.count; i++) {

		if (company.workers[i].salary >= 1000) {

			showWorker(company.workers[i]);
			++counter;
		}

	}
	if (counter == 0) {
		cout << "1000 dollar and high salary worker not found!";
	}
}

void showWorkersAgeMoreThan25(Company& company) {
	int counter = 0;
	for (int i = 0; i < company.count; i++) {

		if (company.workers[i].age >= 25) {
			showWorker(company.workers[i]);
			++counter;
		}

	}
	if (counter == 0) {
		cout << "25 age and high, worker not found!";
	}
}

int findTheIndex(const Company& company, int id) {
	for (int i = 0; i < company.count; i++) {

		if (company.workers[i].id == id) {
			return i;
		}
	}
	return -1;
}

void updateWorkerNameById(int worker_id, char* newname, Company& company) {

	int index = findTheIndex(company, worker_id);
	if (index == -1) {

		cout << "Worker Not found By this ID : " << worker_id << endl;
		return;
	}
	int count = company.count;
	for (size_t i = 0; i < count; i++)
	{
		if (i == index) {
			company.workers[i].name = newname;
		}
	}

}
void SetpAcademy(Company& company) {

	int number = 0;
	cout << "\nThose who salary more than 1000 manats  -1" << endl;
	cout << "Show employee over 25 years old         -2" << endl;
	cout << "Change Worker name from ID              -3" << endl;
	cout << endl << "Select Function : ";
	cin >> number;
	if (number == 1) {
		system("cls");
		showWorkersSalaryMoreThan1000(company);
	}
	else if (number == 2) {
		system("cls");
		showWorkersAgeMoreThan25(company);
	}
	else if (number == 3) {
		system("cls");
		showAllWorkers(company);
		cout << endl << "Worker ID : ";
		int wId = 0;
		cin >> wId;
		cin.ignore();
		cin.clear();
		cout << "Worker New Name : ";
		char* newName = new char[50];
		cin.getline(newName, 50);
		updateWorkerNameById(wId, newName, company);
		system("cls");
		showAllWorkers(company);
	}
	else {

		cout << endl << endl << "Wrong Input, Please Restart Program!" << endl;
	}
}
void main() {

	Company academy{ new char[50]{"Step Academy"} };
	Worker user1{ 100,new char[20]{"Elvin"},  new char[20]{"Camalzade"},21,3000,new char[50]{"Sheki"},4,    new char[50]{"Teacher"} };
	Worker user2{ 101,new char[20]{"Elmir"},  new char[20]{"Muradli"},22,777,   new char[50]{"Shusha"},1,new char[50]{"Student"} };
	Worker user3{ 102,new char[20]{"Samir"},  new char[20]{"Kerimli"},20,2500,   new char[50]{"Baki"},2 , new char[50]{"Student"} };
	Worker user4{ 103,new char[20]{"Amin"},   new char[20]{"Huseyinli"},30,1800,      new char[50]{"Gedebey"},3,new char[50]{"Student"} };
	addWorker(academy, user1);
	addWorker(academy, user2);
	addWorker(academy, user3);
	addWorker(academy, user4);
	showCompany(academy);
	SetpAcademy(academy);

}