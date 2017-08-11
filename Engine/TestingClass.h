#pragma once

#ifndef _ZONECLASS_H_
#define _ZONECLASS_H_

class TestingClass
{
	TestingClass();
	TestingClass(const TestingClass&);
	~TestingClass();

	bool Initialize();
	void Shutdown();
	bool Frame();


public:
	void Positive_Testing(bool, bool, bool);
	void Negative_Testing(bool, bool, bool);

private:
	bool Functional_Testing(bool, bool, bool, bool, bool, bool, bool);
	bool Environment_Testing(bool, bool, bool, bool, bool, bool, bool);
	bool Safety_Testing(bool, bool, bool, bool, bool, bool, bool);

	bool result;
};


#endif

