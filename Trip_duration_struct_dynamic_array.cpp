#include <iostream>
#include <string>

using namespace std;

struct Time
{
	int hr = 0;
	int min = 0;
	int sec = 0;
};

void input_durations(Time* trip, int size)
{
	cout << "Enter " << size << " durations (Hours Minuts Seconds)\n";
	for (int i = 0; i < size; i++)
	{
		cin >> trip[i].hr >> trip[i].min >> trip[i].sec;
	}
}

void calc_total_durations(Time* trip, int size)
{
	Time total_durations;
	cout << "The total duration for " << size << " trips is : (HH : MM: SS)\n";

	for (int i = 0; i < size; i++)
	{
		total_durations.hr += trip[i].hr;
		total_durations.min += trip[i].min;
		total_durations.sec += trip[i].sec;
	}

	total_durations.min += total_durations.sec / 60;
	total_durations.sec %= 60;
	total_durations.hr += total_durations.min / 60;
	total_durations.min %= 60;

	cout << total_durations.hr << " : " << total_durations.min << " : " << total_durations.sec << endl;
}

int main()
{
	int num_of_trips;
	cout << "Enter number of trips:\n";
	cin >> num_of_trips;

	Time* trips = new Time[num_of_trips];

	input_durations(trips, num_of_trips);
	calc_total_durations(trips, num_of_trips);
}
