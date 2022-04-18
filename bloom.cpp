#include <string>
#include <iostream>
#include <cassert>
#include "/usr/local/cs/cs251/show_mem.h"
#include <ctime>
#include"user.h"
using namespace std;

string Account::get_email(){
    return email;
}
string Account::get_password(){
    return password;
}
string Account::get_school(){
    return school;
}
string Account::get_bio(){
    return bio;
}
string Account::get_firstName(){
    return firstName;
}
string Account::get_lastName(){
    return lastName;
}
int Account::get_month(){
    return month;
}
int Account::get_year(){
    return year;
}
int Account::get_day(){
    return day;
}
void Account::set_email(string eml){
    email = eml;
}
void Account::set_password(string pswd){
    password = pswd;
}
void Account::set_school(string schl){
    schl = schl;
}
void Account::set_bio(string b){
    bio = b;
}
void Account::set_firstName(string fn){
    firstName = fn;
}
void Account::set_lastName(string ln){
    lastName = ln;
}
void Account::set_prounouns(string pn){
    pronouns = pn;
}
void Account::set_month(int m){
    month = m;
}
void Account::set_day(int d){
    day = d;
}
void Account::set_year(int y){
    year = y;
}

void test_account_class(){
    Account bob;
    bob.set_email("bobsemail@gmail.com");
    bob.set_password("password123");
    bob.set_school("St.Olaf");
    bob.set_bio("I like to read");
    bob.set_firstName("Bob");
    bob.set_lastName("the Builder");
    bob.set_prounouns("He/Him");
    bob.set_month(1);
    bob.set_day(13);
    bob.set_year(2002);
    assert(bob.get_email()=="bobsemail@gmail.com");
    assert(bob.get_password()=="password123");
    assert(bob.get_school()=="St.Olaf");
    assert(bob.get_pronouns()=="He/Him");
    assert(bob.get_year==2002);
}

void test_messages_class(){
    Message m;
    m.set_message("hello world");
    m.set_timeSent();
    m.set_timeRead();
    assert (m.get_message() == "hello world");
    cout<< m.get_timeSent()<<endl;
    cout<<m.get_timeRead()<<endl;
}
int main(){
    test_account_class();
    test_messages_class();
}