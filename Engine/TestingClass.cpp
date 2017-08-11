#include "TestingClass.h"

TestingClass :: TestingClass()
{
	result = 0;
}

TestingClass :: TestingClass(const TestingClass& other)
{}

TestingClass :: ~TestingClass() 
{}


bool TestingClass::Initialize() {}
void TestingClass::Shutdown() {}
bool TestingClass::Frame() {}


void TestingClass::Positive_Testing(bool, bool, bool)
{
	bool Functional_Testing();
	{
		bool m_UserInterface;
		bool m_Position;
		bool m_directInput;
		bool m_keyboard;
	}

	bool Environment_Testing();
	{
	}

	bool Safety_Testing();
	{
	}
};

void TestingClass::Negative_Testing(bool, bool, bool)
{
	bool Functional_Testing();
	{
	}

	bool Environment_Testing();
	{
	}

	bool Safety_Testing();
	{
	}
}

bool Functional_Testing(bool, bool, bool, bool, bool, bool, bool);
bool Environment_Testing(bool, bool, bool, bool, bool, bool, bool);
bool Safety_Testing(bool, bool, bool, bool, bool, bool, bool);

