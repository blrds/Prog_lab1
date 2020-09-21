#include "Worker2.h"

Worker2::Worker2(string name, Sex sex, float staticPayment, float percent)
{
	setName(name);
	setSex(sex);
	setStaticPayment(staticPayment);
	setPercent(percent);
	_sells = 0;
}


void Worker2::setName(string name)
{
	if(name!="")
	_fullName = name;
}

string Worker2::getName()
{
	return _fullName;
}

void Worker2::setSex(Sex sex)
{
	if (sex >= Sex(0) && sex <= Sex(3))
	_sex = sex;
}

string Worker2::getSex()
{
	switch (_sex) {
	case Sex(0):
		return "male";
	case Sex(1):
		return "female";
	case Sex(2):
		return "undefined";
	case Sex(3):
		return "combat helicopter MI-8";
	}
}

void Worker2::setStaticPayment(float staticPayment)
{
	if (staticPayment > 0)
		_staticPayment = staticPayment;
}

float Worker2::getStaticPayment()
{
	return _staticPayment;
}

void Worker2::setPercent(float percent)
{
	if (percent > 0 && percent <= 1)
		_percent = percent;
}

float Worker2::getPercent()
{
	return _percent;
}

float Worker2::getSells() {
	return _sells;
}

void Worker2::sell(float sum)
{
	if(sum>=0)
	_sells += sum;
}

float Worker2::pay()
{
	float _final=_staticPayment;
	_final += (_sells * _percent);    
	_sells = 0;
	return _final;
}

