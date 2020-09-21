#pragma once
#include<iostream>
#include"Sex.h"

using namespace std;

class Worker1
{
private:
	string _fullName;
	Sex _sex;
	float _payment, _finalHours, _normalHours, _overPayment;
public:
	Worker1(string name, Sex sex, float payment, float overPayment, float normalHours);
	void setName(string name);
	string getName();
	void setSex(Sex sex);
	string getSex();
	void setPayment(float payment);
	float getPayment();
	void setOverPayment(float overPayment);
	float getOverPayment();
	void setNormalHours(float normalHours);
	float getNormaHours();
	float getFinalHours();
	void work(float hours);
	float pay();
};

