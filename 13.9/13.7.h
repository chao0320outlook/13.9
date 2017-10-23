#pragma once
#ifndef BRASS_H
#define BRASS_H

#include<string>
using namespace std;

class Brass
{
private:
	string fullName;                                           //����
	long acctNum;                                              //�˺�  
	double balance;                                            //�˻�����
public:
	Brass(const string &s = "Nullbody", long an = -1, double bal = 0.0);
	void Depost(double amt);                                    //���
	virtual void Withdrow(double amt);                          //ȡ��
	double Balance()const;                                      //�����˻����
	virtual  void ViewAcct()const;                              //��ʾ�˻�������Ϣ
	virtual ~Brass() {};
};

class BrassPlus:public Brass
{
private:
	double maxLoan;                                             //͸֧����
	double rate;                                                //͸֧��������
	double owesBank;                                            //��ǰ͸֧�ܶ�
public:
	BrassPlus(const string &s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500, double r = 0.11125);  //���湹��
	BrassPlus(const Brass&ba, double ml = 500, double r = 0.11125);  //�����������ϵĹ��캯��
	virtual void ViewAcct() const ;                              //��ʾ�˻�������Ϣ
	virtual void Withdrow(double amt) ;
	void ResdtMax(double m) { maxLoan = m; };                    //����͸֧����
	void ResdtRate(double r) { rate= r; };                       //����͸֧��������
	void RestOwes() { owesBank = 0; };                           //���ص�ǰ͸֧�ܶ�
};


#endif
