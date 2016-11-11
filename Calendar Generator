#include "library.h"

string monthName[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

int days_in_month(int month, int year) {

    if (month==2) {

        if (year%4==0) {return 29;}
        else {return 28;}
    
    }
                
    else {

        if (month==4||month==6||month==9||month==11) {return 30;}
        else {return 31;}

    }

}


void display_days_in_month(int month, int year) {
    
    print(monthName[month-1]);
    print(" ");
    print(year);
    print(" was ");
    print(days_in_month(month,year));
    print(" days long.");
    new_line();


}


int days[] = {0,31,28,31,30,31,30,31,31,30,31,30};

bool isLeapYear(int year) {

    if (year%400==0) 
        {return true;}
    else
        {
            if (year%100!=0 && year%4==0) {return true;}
            else {return false;}
        }

}

int daysPassedMonths(int monthsPassed) {

    if (monthsPassed > 0) {

        return (days[monthsPassed] + daysPassedMonths(monthsPassed-1));

    }

    else {return 0;}

}


int correctedDaysPassedMonths(int year, int monthsPassed) {
    
    if (isLeapYear(year) && (monthsPassed > 1) ) {return 1 + daysPassedMonths(monthsPassed);}
    else {return daysPassedMonths(monthsPassed);}

}

int day_in_year (int year, int month, int day) {

    int monthsPassed = month - 1;
    return day + correctedDaysPassedMonths(year, monthsPassed);

}

int daysPassedYears (int yearsPassed) {

    if (yearsPassed > 0) {

        if (isLeapYear(yearsPassed)) {

            return 366 + daysPassedYears(yearsPassed-1);

        }

        else {return 365 + daysPassedYears(yearsPassed-1);}


    }

    else {if (yearsPassed==0){return 366;}   else {return 0;} }


}

int day_in_forever(int year, int month, int day) {

    int yearsPassed = year-1;
    return daysPassedYears(yearsPassed) + day_in_year(year,month,day);

}


int dayOfWeek(int year, int month, int day) {

    return ((day_in_forever(year,month,day) - 2)%7);

}


string weekDay[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};


void makeDashes(int numDash) {

    if (numDash >= 1) {print("-"); makeDashes(numDash-1);}

}


void makeSpaces (int numSpaces) {


    if (numSpaces >= 1) {print(" "); makeSpaces(numSpaces-1);}


}

int numDays (int month, int year) {

    if (month==2)
        {if (isLeapYear(year)){return 29;} else {return 28;}}
    
    else {
        
        if (month==4||month==6||month==9||month==11) {return 30;}
        else {return 31;}
 
    }
}


void writeDays(int referenceDay, int daysInMonth, int counter) {

    if (counter<=daysInMonth) {

        if (counter==1) {makeSpaces((referenceDay-1)*3);}
        if (counter<10) {print(" ");}
        print(counter);
        print(" ");
        if (referenceDay%7==0 && counter!=daysInMonth) {new_line();}
        writeDays(referenceDay+1,daysInMonth,counter+1);

     }


}

int monthLength[] = {-50,7,8,5,5,3,4,4,6,9,7,8,8};

int yearLength(int year) {

    if (year < 0) {return -500;}
    if (year >= 0 && year < 10) {return 1;}
    if (year > 9 && year < 100) {return 2;}
    if (year > 99 && year< 1000) {return 3;}
    if (year > 999 && year< 10000) {return 4;}
    if (year > 9999 && year< 10000) {return 5;}

}

int titleLength(int month, int year) {

    return (monthLength[month] + yearLength(year) + 1);

}

int titleIndent(int month, int year) {

    return ((20 - titleLength(month, year)) / 2);

}

void makeCalendar (int month, int year) {

    new_line();
    makeSpaces(titleIndent(month,year));
    print(monthName[month-1]);
    print(" ");
    print(year);
    new_line();
    makeDashes(20);
    new_line();
    print("Su Mo Tu We Th Fr Sa");
    new_line();
    makeDashes(20);
    new_line();
    writeDays(dayOfWeek(year,month,1)+1, numDays(month,year),1);
    new_line();
    makeDashes(20);
    new_line();

}

void main () {
    
    char userQuery = 'y';
    int userMonth, userYear;    

    while(userQuery == 'y') {
        
        print("Please enter a month: "); cin >> userMonth;
        print("Please enter a year: "); cin >> userYear;
           
        makeCalendar(userMonth,userYear);
        new_line();
        
        print("Would you like to try again? (y/n) : "); cin >> userQuery;

    
    }


}
