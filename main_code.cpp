#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//banners
const string banner = "-------------------------------------";

string lowerString(string s) {
    for (int i = 0; i < (int)s.size(); i++) {
        s[i] = tolower(static_cast<unsigned char>(s[i]));
    }
    return s;
}

int monthNum(string m) {
    m = lowerString(m);
    if (m == "january" || m == "jan") return 1;
    if (m == "february" || m == "feb") return 2;
    if (m == "march" || m == "mar") return 3;
    if (m == "april" || m == "apr") return 4;
    if (m == "may") return 5;
    if (m == "june" || m == "jun") return 6;
    if (m == "july" || m == "jul") return 7;
    if (m == "august" || m == "aug") return 8;
    if (m == "september" || m == "sep") return 9;
    if (m == "october" || m == "oct") return 10;
    if (m == "november" || m == "nov") return 11;
    if (m == "december" || m == "dec") return 12;
    return 0;
}

int weekdayNum(string w) {
    w = lowerString(w);
    if (w == "monday" || w == "mon") return 0;
    if (w == "tuesday" || w == "tue") return 1;
    if (w == "wednesday" || w == "wed") return 2;
    if (w == "thursday" || w == "thu") return 3;
    if (w == "friday" || w == "fri") return 4;
    if (w == "saturday" || w == "sat") return 5;
    if (w == "sunday" || w == "sun") return 6;
    return -1;
}

string weekdayName(int d) {
    if (d == 0) return "Monday";
    if (d == 1) return "Tuesday";
    if (d == 2) return "Wednesday";
    if (d == 3) return "Thursday";
    if (d == 4) return "Friday";
    if (d == 5) return "Saturday";
    return "Sunday";
}

bool isLeapYear(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int main() {
    char again = 'Y';

    while (again == 'Y' || again == 'y') {
        string studentNumber, fullName, month, weekday;
        int day, year;
        cout << " !! PLEASE COMPLETE INFORMATION BELOW TO PROCEED !! ";
        
        cout << "\n\n Full Name: ";
        getline(cin, fullName);

        cout << " Birth month: ";
        getline(cin, month);

        cout << " Birth day: ";
        cin >> day;

        cout << " Birth year: ";
        cin >> year;

        cin.ignore();

        cout << " Weekday: ";
        getline(cin, weekday);

        int m = monthNum(month);
        int originalWeekday = weekdayNum(weekday);

        if (m == 0 || originalWeekday == -1) {
            cout << "Invalid input.\n";
        } else {
            int count = 0;
            int currentWeekday = originalWeekday;

            cout << endl << endl;
            cout << banner << "\n    BIRTHDAY CONGRUENCE ANALYZER \n" << banner;

            cout << "\n Student Number: " << studentNumber << '\n';
            cout << " Full Name: " << fullName << '\n';
            cout << " Birthdate: " << month << " " << day << ", " << year << '\n';
            cout << " Weekday: " << weekdayName(originalWeekday) << "\n\n";

            cout << banner << "\n   Birthdays on the same weekday: \n" << banner;
            cout << "\n       Age\tYear\tWeekday\n";

            cout << "       " << 0 << "\t" << year << "\t" << weekdayName(currentWeekday) << '\n';
            count++;

            for (int age = 1; age <= 72; age++) {
                int currentYear = year + age;
                int step = 1;

                if (m > 2 || (m == 2 && day > 29)) {
                    if (isLeapYear(currentYear)) step = 2;
                } else if (m < 2 || (m == 2 && day < 29)) {
                    if (isLeapYear(currentYear - 1)) step = 2;
                }

                currentWeekday = (currentWeekday + step) % 7;

                if (currentWeekday == originalWeekday) {
                    cout << "       " << age << "\t" << currentYear << "\t" << weekdayName(currentWeekday) << '\n';
                    count++;
                }
            }

            cout << banner << endl << "       Total occurrences: " << count << endl << banner;

            cout << "\n\n 202311046 - Andrea Ysabelle C. Rogon";
        }

        cout << "\n\n\n Do you want to calculate again? (Y/N): ";
        cin >> again;
        cin.ignore();
        cout << "\n";
    }

    cout << "Program ended.\n";
    return 0;
}
