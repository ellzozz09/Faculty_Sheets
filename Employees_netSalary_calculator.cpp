#include <iostream>
#include <string>

using namespace std;

struct Employee
{
	int ID;
	string name;
	char position;
	double grossSalary;
	double netSalary;
}employee[3];

void InputData(Employee emps[]);
void CalcSalary(Employee emps[]);
void DisplayEmp(Employee emps[], int id);


int main()
{

	InputData(employee);
	CalcSalary(employee);

	int emp_id;
	bool found = false;

	do
	{
		cout << "Enter the employee ID to display his net salry: ";
		cin >> emp_id;
		for (int i = 0; i < 3; i++)
		{
			if (emp_id == employee[i].ID)
			{
				found = true;;
				break;
			}
		}
		if (!found)
		{
			cout << "Invalid ID entered!\n\n";
		}
	} while (!found);

	DisplayEmp(employee, emp_id);
}

void InputData(Employee emps[])
{
	cout << "Enter 3 employees data:\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Emp #" << i + 1 << " info:\n";
		cout << "ID: ";
		cin >> emps[i].ID;

		cout << "Name: ";
		cin >> emps[i].name;

		while (true)
		{
			cout << "Position: ('m' for manager, 'c' for clerk) ";
			cin >> emps[i].position;
			if (emps[i].position != 'm' && emps[i].position != 'c')
			{
				cout << "Invalid postion! Only 'm' or 'c' is accepted!\n";
			}
			else
				break;
		}

		cout << "Gross Salary: ";
		cin >> emps[i].grossSalary;
	}
}

void CalcSalary(Employee emps[])
{
	for (int i = 0; i < 3; i++)
	{
		if (emps[i].position == 'm')
		{
			emps[i].netSalary = emps[i].grossSalary * 0.9;
		}
		else
		{
			emps[i].netSalary = emps[i].grossSalary * 0.95;
		}
	}
}

void DisplayEmp(Employee emps[], int id)
{
	Employee emp;
	for (int i = 0; i < 3; i++)
	{
		if (id == emps[i].ID)
		{
			emp.name = emps[i].name;
			emp.netSalary = emps[i].netSalary;
			break;
		}
	}
	cout << "Employee name: " << emp.name << endl;
	cout << "Employee net Salary: " << emp.netSalary << endl;
}
