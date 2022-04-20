#include <iostream>
#include <string>
using namespace std;

//stores information about iif an account has been reported and why
class report{
    string username, reportReason, reportType;
    int numReports;

    public:
    //constructors
    report(): username("None"), reportReason("None"), reportType("None"), numReports(0){};
    report(string username, string reason, string type, int num): username(username), reportReason(reason), reportType(type), numReports(num){};

    void print(){
        cout << "Username: " << username << endl;
        cout << "Reason for Report: " << reportReason << endl;
        cout << "Type of Report: " << reportType << endl;
        cout << "Total Number of Lifetime Reports: " << numReports << endl;
    }

    //setters
    void setUsername(string name){
        username = name;
    }
    void setReportReason(string reason){
        reportReason = reason;
    }
    void setReportType(string type){ //either an account report or a message report
        reportType = type;
    }

    //increases lifetime reports by 1
    void increaseNumReports(){
        numReports += 1;
    }

    //getters
    string getUsername(){return username;}
    string getReportReason(){return reportReason;}
    string getReportType(){return reportType;}
    int getNumReports(){return numReports;}

};

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
   // test_print();
    test_setters();
}