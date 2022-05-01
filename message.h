#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <string>
#include <iostream>
#include <cassert>
#include "/usr/local/cs/cs251/show_mem.h"
#include <ctime>
#include"user.h"
using namespace std;

class Message{
  string message;
  //time_t timeSent;
  //time_t timeRead;
  
  public:
    string get_message(){
        return message;
    }
    /*time_t get_timeSent(){
        return timeSent;
    }
    time_t get_timeRead(){
        return timeRead;
    }
    void set_message(string m){
        message = m;
    }
    void set_timeSent(){
        time(timeSent);
    }
    void set_timeRead(){
        time(timeRead);
    }*/
};
#endif
