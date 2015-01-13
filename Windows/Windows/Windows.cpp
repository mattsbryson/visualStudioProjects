// CSC335_Project1_C++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;

#include "Screen.h"



int main()
{
ClearTheScreen();
SetWindow(80,43);
//errorMessage("hello");
GetData();

PauseTheScreen();

}

