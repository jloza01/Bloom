#include <iostream>
#include <string>
#include "reportClass.h"
using namespace std;

void test_print(){
    report r1, r2("name", "creepy", "account", 3);
    r1.print();
    cout << endl;
    r2.print();
}

void test_setters(){
    report r1;
    r1.setUsername("Grace");
    r1.setReportReason("Offensive Language");
    r1.setReportType("Message");
    r1.increaseNumReports();

    r1.print();
}

int main(){
    test_print();
    test_setters();
}