#include "stdafx.h"
#include <iostream>
#include "13.7.h"
#include<string>

using namespace std;

typedef ios_base::fmtflags format;
typedef streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const string& s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Depost(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed; " <<
		"deposit is canceled." << endl;
	else
		balance += amt;

}

void Brass::Withdrow(double amt)
{
	format initialState = setFormat();                     //���������ʽ ###.##
	precis prec = cout.precision(2);

	if (amt < 0)
		cout << "Withdrawal amount must be postive; " <<
		"withdrawal canceled." << endl;
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Withdrawal amount of $" << amt
		<< " exceeds your balance ." << endl <<
		"Withdrawal canceled." << endl;

	restore(initialState, prec);                           //�ָ�Ϊԭ��ʽ
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	format initialState = setFormat();                     //���������ʽ ###.##
	precis prec = cout.precision(2);

	cout << "Client: " << fullName << endl;
	cout << "Account number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;

	restore(initialState, prec);                           //�ָ�Ϊԭ��ʽ
}

BrassPlus::BrassPlus(const string & s, long an, double bal,
	                 double ml, double r):Brass(s,an,bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
	                :Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();                     //���������ʽ
	precis prec = cout.precision(2);

	Brass::ViewAcct();
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);                                     // ���������ʽΪ ###.###
	cout << "Loan Rate: " << 100 * rate << "%" << endl;

	restore(initialState, prec);                           //�ָ�Ϊԭ��ʽ
}

void BrassPlus::Withdrow(double amt)
{
	format initialState = setFormat();                     //���������ʽΪ ###.##
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt < bal)
		Brass::Withdrow(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;                        //��Ҫ������Ŀ
		owesBank += advance*(1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance*rate << endl;
		Depost(advance);
		Brass::Withdrow(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled." << endl;

	restore(initialState, prec);                           //�ָ�Ϊԭ��ʽ
}

format setFormat()
{
	return cout.setf(ios_base::fixed, ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, ios_base::floatfield);
	cout.precision(p);
}
