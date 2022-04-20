#ifndef __REPORT_H__
#define __REPORT_H__

#include <iostream>
#include <string>
using namespace std;

//stores information about iif an account has been reported and why
class report{
    string username, reportReason, reportType;
    int numReports;

    public:
    //constructors
    report();
    report(string username, string reason, string type, int num){};

    void print(){};

    //setters
    void setUsername(string name){};
    void setReportReason(string reason){};
    void setReportType(string type){};

    //increases lifetime reports by 1
    void increaseNumReports(){};

    //getters
    string getUsername(){return username;}
    string getReportReason(){return reportReason;}
    string getReportType(){return reportType;}
    int getNumReports(){return numReports;}

};


#endif
