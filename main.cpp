#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const string UnderScore(40, '-');

class BranchFinances
{
private:
	const double CostPerMonth = 50;
	const double FixProfitPercent = 0.07;
	const double FixProfit = 270;
	const double Salary = 35;
	const double AurorPayment = 15;
	double Profit;
public:
	BranchFinances()
	{
		srand(time(nullptr));
		Profit = rand() % 251 + 250;
	}
	double MonthRent()
	{
		if (Profit > FixProfit)
		{
			return CostPerMonth + (Profit - FixProfit) * FixProfitPercent;
		}
		return CostPerMonth;
	}
	double TotalExpenses()
	{
		return Salary + MonthRent() + AurorPayment;
	}
	double GrossProfit()
	{
		return Profit;
	}
	void ShowMeMyExpenses()
	{
		cout << UnderScore << endl <<
			"Monthly expences of the Branch:" << endl
			<< "Salaries: " << Salary << " galleon per month"
			<< endl << "Rent Cost: " << MonthRent() << endl <<
			"Auror services: " << AurorPayment << endl <<
			UnderScore << endl << "Total Expences: " <<
			TotalExpenses() << endl << UnderScore << endl;
	}
	double NetProfit()
	{
		return	Profit - TotalExpenses();
	}
	~BranchFinances() {};
};

class NewBranch : public BranchFinances
{
private:
	string BranchName;

public:
	NewBranch(string Name)
	{
		BranchName = Name;
		cout << "Welcome to " << BranchName << " branch of Ollivander's!" << endl << UnderScore << endl; //вывод приветствия (опционально)

	}
	~NewBranch()
	{
		cout << "Have a nice day!";
	}
};

int main()
{
	cout << "Please, insert branch name: ";
	string name;
	cin >> name;

	NewBranch Branch(name);
	cout << Branch.GrossProfit() << endl;
	cout << Branch.TotalExpenses() << endl;
	Branch.ShowMeMyExpenses();
	cout << Branch.NetProfit() << endl;

	return 0;
}