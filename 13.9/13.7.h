#pragma once
#ifndef BRASS_H
#define BRASS_H

#include<string>
using namespace std;

class Brass
{
private:
	string fullName;                                           //姓名
	long acctNum;                                              //账号  
	double balance;                                            //账户结余
public:
	Brass(const string &s = "Nullbody", long an = -1, double bal = 0.0);
	void Depost(double amt);                                    //存款
	virtual void Withdrow(double amt);                          //取款
	double Balance()const;                                      //返回账户余额
	virtual  void ViewAcct()const;                              //显示账户基本信息
	virtual ~Brass() {};
};

class BrassPlus:public Brass
{
private:
	double maxLoan;                                             //透支上线
	double rate;                                                //透支贷款利率
	double owesBank;                                            //当前透支总额
public:
	BrassPlus(const string &s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500, double r = 0.11125);  //常规构造
	BrassPlus(const Brass&ba, double ml = 500, double r = 0.11125);  //基类对象基础上的构造函数
	virtual void ViewAcct() const ;                              //显示账户所有信息
	virtual void Withdrow(double amt) ;
	void ResdtMax(double m) { maxLoan = m; };                    //返回透支上线
	void ResdtRate(double r) { rate= r; };                       //返回透支贷款利率
	void RestOwes() { owesBank = 0; };                           //返回当前透支总额
};


#endif
