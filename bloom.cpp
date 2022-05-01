#include <string>
#include <iostream>
#include <cassert>
#include "/usr/local/cs/cs251/show_mem.h"
#include <ctime>
#include"user.h"
#include"message.h"
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
string Account:: get_name(){
    return name;
}
int Account:: get_age(){
    return age;
}
void Account:: set_name(nm){
    name = nm;
}
void Account:: set_age(int a){
    age = a;
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
void Account::set_prounouns(string pn){
    pronouns = pn;
}

void Account::add_match(Account &user){
    numMtchs = user.get_numMatches() + 1;
    Account **temp = new Account*[numMtchs];
    if(numMtchs < 2 ){
    for (int i = 0; i<numMtchs-1; i++){
        matches[i] = temp[i];
    }
    }
    temp[numMtchs] = &user;
    matches = new Account*[numMtchs];
    delete[] matches;
    matches = new Account*[numMtchs];
    for (int i = 0; i<numMtchs; i++){
        matches[i] = temp[i];
    }
    delete [] temp;
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
    assert(bob.get_email()=="bobsemail@gmail.com");
    assert(bob.get_password()=="password123");
    assert(bob.get_school()=="St.Olaf");
    assert(bob.get_pronouns()=="He/Him");
 
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