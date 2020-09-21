#include "Worker1.h"

Worker1::Worker1(string name, Sex sex, float payment, float overPayment, float normalHours)
{
	setName(name);
	setSex(sex);
	setPayment(payment);
	setOverPayment(overPayment);
	setNormalHours(normalHours);
	_finalHours = 0;
}

void Worker1::setName(string name)
{
	if(name!="")
		_fullName = name;
}

string Worker1::getName()
{
	return _fullName;
}

void Worker1::setSex(Sex sex)
{
	if (sex>=Sex(0) && sex<=Sex(3))
		_sex = sex;
}

string Worker1::getSex()
{
	switch(_sex) {
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

void Worker1::setPayment(float payment)
{
	if (payment > 0)
		_payment = payment;
}

float Worker1::getPayment()
{
	return _payment;
}

void Worker1::setOverPayment(float overPayment)
{
	if (overPayment >= 0)
	_overPayment = overPayment;
}

float Worker1::getOverPayment()
{
	return _overPayment;
}

void Worker1::setNormalHours(float normalHours)
{
	if (normalHours > 0)
	_normalHours = normalHours;
}

float Worker1::getNormaHours()
{
	return _normalHours;
}

float Worker1::getFinalHours() {
	return _finalHours;
}

void Worker1::work(float hours)
{
	if(hours>=0)
	_finalHours += hours;
}

float Worker1::pay()
{
	float sum = _payment;
	if (_finalHours > _normalHours) {
		float dop=_finalHours-_normalHours;
		sum += (dop * _overPayment);
	}
	_finalHours = 0;

	return sum;
}

