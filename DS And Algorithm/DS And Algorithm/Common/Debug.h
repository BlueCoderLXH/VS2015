#pragma once
#include <iostream>
#include <string>
using namespace std;

class Debug
{
public:
	static void Print(string msg)
	{
		cout << msg;
	}

	static void PrintLine(string msg)
	{
		cout << msg << endl;
	}

	static void PrintLine()
	{
		cout << endl;
	}

	static void Log(string msg)
	{
		cout << "Debug:" << msg << endl;
	}

	static void LogWarning(string msg)
	{
		cout << "Warning:" << msg << endl;
	}

	static void LogError(string msg)
	{
		cout << "Error:" << msg << endl;
	}
};