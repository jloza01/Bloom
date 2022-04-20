#ifndef __STATE_H__
#define __STATE_H__

#include<string>
using namespace std;

class State{


    public:
    void read_from(const char *mem);
    void write_to(char *mem);
}

#endif