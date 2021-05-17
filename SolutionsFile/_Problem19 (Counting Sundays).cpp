#include <iostream>
#include <math.h>
#include <cmath>

//Problem 19 (COMPLETE)
//You are given the following information, but you may prefer to do some research for yourself.
//o	1 Jan 1900 was a Monday.
//		Thirty days has September,
//		April, June and November.
//		All the rest have thirty-one,
//		Saving February alone,
//		Which has twenty-eight, rain or shine.
//		And on leap years, twenty-nine.
//o A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
//How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

//NOTES
//o Could use Zeller's Congruence
// 	h = (q+floor(13(m+1)/5) + k + floor(k/4) + floor(j/4) - 2j) mod 7
// 	h is day of week, 0 = sat, 1 = sun...
// 	q is day of month
// 	m is month, 3 = mar, 4 = apr,... 13 = jan, 14 = feb...
// 	k is year of century (year mod 100)
// 	j is zero based century (i.e. for 1984, j = 19, for 2114, j = 21)
//o Run GetDayOfWeek function for each first of month and add one to counter if returned value is 1.

int GetDayOfWeek(int day, int month, int year){
	
	//Alteration of month as Zeller uses 13 as jan and 14 as feb.
	if(month <= 2){
		month += 12;
		year--;
	}
	
	int h;
	int q = day;
	int m = month;
	int k = year % 100;
	int j = year / 100;
	
	
	h = (q + floor(13*(m+1)/5) + k + floor(k/4) + floor(j/4) + 5*j);
	h = h % 7;
	
	return h;
}

void CountingSundays(int StartDay, int StartMonth, int StartYear, int EndDay, int EndMonth, int EndYear){
	
	//Declares
	int h = 0;
	int SundaysCounter = 0;
	
	//Storage for output to user
	int day = StartDay;
	int month = StartMonth;
	int year = StartYear;
	
	//Run through from 1/1/1901 to 1/12/2000
	while(month <= EndMonth && year <= EndYear){
		//std::cout << "(" << day << ", " << month << ", " << year << ") \n";
		h = GetDayOfWeek(day, month, year);
		
		if(h == 1){
			SundaysCounter++;
		}
		
		month++;
		
		if(month > 12){
			month -= 12;
			year++;
		}
		
	}
	
	std::cout << "The number of Sundays between " << "(" << StartDay << "/" << StartMonth << "/" << StartYear << ") and " << "(" << EndDay << "/" << EndMonth << "/" << EndYear << ") is " << SundaysCounter << "\n";
	
}


int main() {
	
	//Change Values to alter the start and end date for counting Sundays
	//Initial Date
	int StartDay = 1;
	int StartMonth = 1;
	int StartYear = 1901;
	
	//End Date
	int EndDay = 1;
	int EndMonth = 12;
	int EndYear = 2000;
	
	CountingSundays(StartDay,StartMonth,StartYear,EndDay,EndMonth,EndYear);

}
