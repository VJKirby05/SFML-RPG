#pragma once
#include "RPEngine.h"
#include <iostream>

using namespace std;

// Main function
int main()
{
	// Debug
	cout << "DEBUG TEST" << endl;

	// Declare instance of machine
	RPEngine re;

	// Start the machine
	re.run();

	// Quit in the usual way when machine comes to a halt
	return 0;
}