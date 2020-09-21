#pragma once
#include<iostream>
#include"Sex.h"

using namespace std;


class Worker2
{
private:
	string _fullName;
	Sex _sex;
	float _staticPayment, _percent, _sells;
public:
	Worker2(string name, Sex sex, float staticPayment, float percent);
	void setName(string name);
	string getName();
	void setSex(Sex sex);
	string getSex();
	void setStaticPayment(float staticPayment);
	float getStaticPayment();
	void setPercent(float percent);
	float getPercent();
	float getSells();
	void sell(float sum);
	float pay();
	
};

