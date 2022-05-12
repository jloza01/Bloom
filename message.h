#ifndef __MESSAGE_H__
#define __MESSAGE_H__
#include <string>
#include <iostream>
#include <cassert>
#include "/usr/local/cs/cs251/react.h"
#include <ctime>
#include"user.h"
using namespace std;

class Message{
  string email;
  string message;
  //time_t timeSent;
  //time_t timeRead;
  

  public:
    Message(string em, string m){
      email = em;
      message = m;
  }
    string get_message(){
        return message;
    }
    string get_email(){
        return email;
    }
    void set_email(string em){
        email = em;
    }
    /*time_t get_timeSent(){
        return timeSent;
    }*/
   /* time_t get_timeRead(){
        return timeRead;
    }*/
    void set_message(string m){
        message = m;
    }
    /*void set_timeSent(){
        time(timeSent);
    }
    void set_timeRead(){
        time(timeRead);
    }*/
};


#endif
