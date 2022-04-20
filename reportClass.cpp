#include <iostream>
#include <string>
using namespace std;

    //constructors
    report::report(): username("None"), reportReason("None"), reportType("None"), numReports(0){};
    report::report(string username, string reason, string type, int num): username(username), reportReason(reason), reportType(type), numReports(num){};

    void report::print(){
        cout << "Username: " << username << endl;
        cout << "Reason for Report: " << reportReason << endl;
        cout << "Type of Report: " << reportType << endl;
        cout << "Total Number of Lifetime Reports: " << numReports << endl;
    }

    //setters
    void report::setUsername(string name){
        username = name;
    }
    void report::setReportReason(string reason){
        reportReason = reason;
    }
    void report::setReportType(string type){ //either an account report or a message report
        reportType = type;
    }

    //increases lifetime reports by 1
    void report::increaseNumReports(){
        numReports += 1;
    }

    //getters
    string report::getUsername(){return username;}
    string report::getReportReason(){return reportReason;}
    string report::getReportType(){return reportType;}
    int report::getNumReports(){return numReports;}
