/*Define a class EMPLOYEE contains following members.
Data members: Employee_Number, Employee_Name, Basic, DA, IT, Net_Sal, Gross_salary.
Member functions: To read the data, calculate net salary, gross salary and display both salary.
Write a C++ program to read the data of N employees and compute Net salary and Gross salary of
each employee. (DA= 12% of Basic and Income Tax (IT) = 18% of the gross salary). */



#include <iostream>
using namespace std;

class EMPLOYEE
{
	int Emp_Number;
	char Emp_Name[40];
	float Basic, DA, IT, Net_Sal, Gross_Sal;

	public:

	void read_employee_details(int i)
	{
		cout << "\n\nEnter Employee "<<i<< " Details\n";

		cout << "Enter Employee Number: ";
		cin >> Emp_Number;

		cout << "Enter Employee Name: ";
		cin >> Emp_Name;

		cout << "Enter Basic Salary: ";
		cin >> Basic;
	}

	void find_net_gross()
	{
		DA = Basic * 0.12;
		Gross_Sal = Basic + DA;
		IT = Gross_Sal * 0.18;
		Net_Sal = Gross_Sal - IT;

	}

	void display_emp_details(int i)
	{
		cout<<"\n\n Employee "<<i<<" Details \n";

		cout << "\n\nEmployee Number: "<< Emp_Number;
		cout << "\nEmployee Name: "<< Emp_Name;
		cout << "\nNet Salary: "<< Net_Sal;
		cout << "\nGross Salary: "<< Gross_Sal;
	}
};

int main()
{

	int n, i;
	cout << "\nPlease enter the number of Employees: ";
	cin >> n;

    EMPLOYEE emp[n];

    //separate for loops used cuz otherwise employee  details are printed as soon as input
	for(i=0 ; i < n; i++)
	{
		emp[i].read_emp_details(i+1);
	}

	for(i=0 ; i < n; i++)
	{
		emp[i].find_net_gross();
	}


	for(i=0 ; i < n; i++)
	{
		emp[i].display_emp_details(i+1);
	}

	return 0;
}
