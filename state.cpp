#include<iostream>
using namespace std;
#include"State.h"
#include"/usr/local/cs/cs251/show_mem.h"

void State::read_from(const char *mem){
    showPopUp = _get_char(mem, 1);
    mem += 1;
    yourName = _get_tilde_terminated_string(mem);
    mem += (yourName.size() + 1);
    theirName = _get_tilde_terminated_string(mem);
    mem += (theirName.size() + 1);
    age = _get_int(mem, 2);
    mem += 2;
    bio = _get_tilde_terminated_string(mem);
    mem += (bio.size() + 1);
    percentMatch = _get_int(mem, 2);
    mem += 2;
}

void State::write_to(char *mem){
    _put_char(showPopUp, mem);
    mem += 1;
    _put_tilde_terminated_string(yourName, mem);
    mem += (yourName.size() + 1);
    _put_tilde_terminated_string(theirName, mem);
    mem += (theirName.size() + 1);
    _put_int(age, mem, 2);
    mem += 2;
    _put_tilde_terminated_string(bio, mem);
    mem += (bio.size() + 1);
    _put_int(percentMatch, mem, 2);
    mem += 2;
}

void State::display(){

}