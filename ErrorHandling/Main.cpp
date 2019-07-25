/*
A simple program testing out error handling.

© D. Green. 2019.
*/

#include"D:\Visual_Studio_Projects_Cpp_book\std_lib_facilities.h"

// Defined simply for something to throw.
class Bad_area{};

int area(int length, int width)
{
	// Calculate the area of a rectangle.
	// Pre-conditions: length and width must be postive values.
	// Post-condtion: must return a postive value, which is the area.

	// This is the pre-condition.
	/*
	This is how error handling should be done, if anything in the 'try block' comes across a 'throw' then it automatically moves to the 'catch' block and executes that code.
	*/
	if (length <= 0 || width <= 0)
	{
		cout << "Pre\n";
		throw Bad_area{};
	}		

	/*
	We could enter 2 values of 47000 for lenght and width and this will pass the pre-condtion but fail on the post condition due to trying to return a number greater than INT_MAX(2_147_483_647)
	47000 * 47000 = 2_209_000_000
	*/
	// This is the post-condition.
	if ((length * width) <= 0)
	{
		cout << "Post\n";
		throw Bad_area{};
	}

	return length * width;
}

int framedArea(int x, int y)
{
	return area(x - 2, y - 2);
}

int func(int x, int y, int z)
{
	int area1 = area(x, y);
	int area2 = framedArea(1, z);
	int area3 = framedArea(y, z);


	/*
	If this error is not caught/handled it will simply pause the program at that point and flag up the error location in the program.
	*/
	/*if (area1 <= 0 || area2 <= 0 || area3 <= 0)
		error("non-positive area");*/

	double ratio = double(area1) / area3;

	return ratio;
}

int main()
{
	/*vector<double> temps;

	for (double temp; cin >> temp;)
	{
		temps.push_back(temp);
	}*/

	//double sum = 0;
	//constexpr double HIGH_TEMP = -100;		// Coldest recorded temp ever was -89.2, setting this to -100 gives us decent wiggle room.
	//constexpr double LOW_TEMP = 70;				// Hottest recorded temp ever was 56.7, setting this to 70 gives us decent wiggle room.
	//double high_temp = 0;		// Magic constants (bad practice).
	//double low_temp = 0;
	//int num_of_temps = 0;

	//for (double temp; cin >> temp;)
	//{
	//	++num_of_temps;
	//	sum += temp;
	//	if (temp > HIGH_TEMP)
	//		high_temp = temp;
	//	if (temp < LOW_TEMP)
	//		low_temp = temp;
	//}

	//cout << "The high temp was: " << high_temp << '\n';
	//cout << "The low temp was: " << low_temp << '\n';
	//cout << "The average temp was: " << sum/num_of_temps << '\n';


	/*vector<double> temps;

	for (double temp; cin >> temp;)
	{
		temps.push_back(temp);
	}

	double sum = 0;
	double high_temp = temps[0];;
	double low_temp = temps[1];

	for (int i = 0; i < temps.size(); ++i)
	{
		if (temps[i] > high_temp)
		{
			high_temp = temps[i];
		}
		else if (temps[i] < low_temp)
		{
			low_temp = temps[i];
		}

		sum += temps[i];
	}

	cout << "The high temp was: " << high_temp << '\n';
	cout << "The low temp was: " << low_temp << '\n';
	cout << "The average temp was: " << sum / temps.size() << '\n';*/

	int area1;

	try
	{
		int x = 4700;
		int y = 4700;
		//int z = 4;

		area1 = area(x, y);
		//int area2 = framedArea(1, z);
		//int area3 = framedArea(y, z);
		//double ratio = double(area1) / area3;
	}
	catch (Bad_area)
	{
		cout << "Oops! bad arguments to area()\n";
	}

	cout << INT_MAX << '\n';
	cout << area1 << '\n';

	return 0;
}