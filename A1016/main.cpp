#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct Customer {
    string name;
    int month;
    int day;
    int hour;
    int minute;
    bool offLine;
} customers[1000];

int rates[24] = {0};

void print(Customer* customers, int n) {
    for(int i = 0; i < n; i++) {
        Customer* customer = customers + i;
        cout << customer->name << " " << customer->month << " " << customer->day << ":" << customer->hour << ":" << customer->minute << " " << customer->offLine << endl;
    }
}

bool customerCompare(Customer& left, Customer& right) {
    // Compare name
    int nameCompare = left.name.compare(right.name);
    if(nameCompare != 0) {
        return nameCompare < 0;
    }

    // Compare day
    if(left.day != right.day) {
        return left.day < right.day;
    }

    // Compare hour
    if(left.hour != right.hour) {
        return left.hour < right.hour;
    }

    // Compare minute
    if(left.minute != right.minute) {
        return left.minute < right.minute;
    }

    return true;
}

int calculateBill(Customer* start, Customer* end) {
    int totalCent = 0;
    int totalTime = 0;

    int day = start->day;
    int hour = start->hour;
    int minute = start->minute;

    while(day < end->day || hour < end->hour || minute < end->minute) {
        minute++;
        totalTime++;
        totalCent += rates[hour];
        if(minute >= 60) {
            // Go into next hour
            minute = 0;
            hour++;
            if(hour >= 24) {
                // Go into next day
                hour = 0;
                day++;
            }
        }
    }

    printf("%02d:%02d:%02d ", start->day, start->hour, start->minute);
    printf("%02d:%02d:%02d ", end->day, end->hour, end->minute);
    printf("%d ", totalTime);
    printf("$%.2f\n", totalCent / 100.0);

    return totalCent;
}

void handleCustomer(Customer* start, Customer* end) {
    Customer* left = start;
    Customer* right = left + 1;

    int totalCent = 0;
    bool isPrint = false;
    while(right <= end) {
        if(!left->offLine && right->offLine) {
            if(!isPrint) {
                printf("%s %02d\n", start->name.c_str(), start->month);
                isPrint = true;
            }

            // Calculate
            totalCent += calculateBill(left, right);
            left = right + 1;
            right = left + 1;
        } else {
            left = right;
            right = left + 1;
        }
    }

    if(totalCent != 0) {
        printf("Total amount: $%.2f\n", totalCent / 100.0);
    }
}

int main() {
    for(int i = 0; i < 24; i++) {
        cin >> rates[i];
    }

    int N = 0;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> customers[i].name;
        scanf("%d:%d:%d:%d", &customers[i].month, &customers[i].day, &customers[i].hour, &customers[i].minute);
        string offLine = "";
        cin >> offLine;
        if(offLine.compare("off-line") == 0) {
            customers[i].offLine = true;
        } else {
            customers[i].offLine = false;
        }
    }

    // Sort the customers
    sort(customers, customers + N, customerCompare);

//    print(customers, N);

    Customer* handlingCustomer = customers;
    int i = 1;
    for(; i < N; i++) {
        if(handlingCustomer->name.compare(customers[i].name) != 0) {
            // Handle the customer
            handleCustomer(handlingCustomer, customers + i - 1);
            // Set handling customer
            handlingCustomer = customers + i;
        }
    }

    if(handlingCustomer != customers + i) {
        handleCustomer(handlingCustomer, customers + i - 1);
    }

    return 0;
}
