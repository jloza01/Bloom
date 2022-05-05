#include <string>
#include <iostream>
#include <cassert>
#include "/usr/local/cs/cs251/react.h"
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
string Account:: get_pic(){
    return pic;
}
int Account:: get_age(){
    return age;
}
int Account:: get_numMatches(){
    return numMatches;
}
int Account:: get_numBlocks(){
    return numBlocks;
}
void Account:: set_name(string nm){
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
void Account::update_numMatches(){
    numMatches=numMatches+1;
}
void Account:: update_numBlocks(){
    numBlocks = numBlocks +1;
}
void Account::set_pic(string p){
    pic = p;
}

string Account::get_matches(int i){
    
    string email = (*matches[i]).get_email();
    return email;
}

void Account::add_match(Account &user){
    int numMtchs = this->get_numMatches();
    Account **temp = new Account*[numMtchs+1];
    if(numMtchs < 1 ){
    for (int i = 0; i<numMtchs-1; i++){
        temp[i] = this->matches[i];
    }
    }
    temp[numMatches] = &user;
    delete[] this->matches;
    this->matches = temp;
    update_numMatches();
}

void Account::add_block(Account &user){
    int numblks = this->get_numBlocks();
    Account **temp = new Account*[numblks+1];
    if(numblks < 1 ){
    for (int i = 0; i<numblks-1; i++){
        temp[i] = this->blocks[i];
    }
    }
    temp[numblks] = &user;
    delete[] this->blocks;
    this->blocks = temp;
    update_numBlocks();
}



/*void test_account_class(){
    Account bob("bobsemail@gmail.com","password123");
    Account barb("barbsemail@gmail.com", "password234");
    Account karen("karensemail@gmail.com", "password345");
    cout<<bob.get_numMatches()<<endl;
    bob.add_match(barb);
    cout<<bob.get_matches(0)<<endl;
    cout<<bob.get_numMatches()<<endl;
    bob.add_match(karen);
    cout<<bob.get_matches(1)<<endl;
    cout<<bob.get_numMatches()<<endl;
    bob.set_school("St.Olaf");
    bob.set_bio("I like to read");
    bob.set_name("bob the builder");
    bob.set_prounouns("He/Him");
    
 
}*/

/*void test_messages_class(){
    Message m;
    m.set_message("hello world");
  //  m.set_timeSent();
  //  m.set_timeRead();
    assert (m.get_message() == "hello world");
   // cout<< m.get_timeSent()<<endl;
   // cout<<m.get_timeRead()<<endl;
}*/
//int main(){
    //test_account_class();
    //test_messages_class();
//}