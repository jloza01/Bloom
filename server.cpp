#include<iostream>
#include <fstream>
#include"state.h"
#include"/usr/local/cs/cs251/react.h"
using namespace std;

int main() {
  State state;
  _read_event_info_file("event_info");

  if(_just_starting()){
    //cout<< "using frame1"<<endl;
    _read_global_mem_from_file("frame1.txt");
  }else{ _read_global_mem_from_file("begin_mem");}

  state.read_from(_global_mem);
  ifstream f_label("labels.txt");
  f_label.read(_global_mem + state.offset("labelStart"), 162);
  
  state.read_lab(_global_mem + state.offset("labelStart"));
 

  cout<<_global_mem[500]<< "line 27"<<endl;
  state.update(); // event handling
  cout << state.getNumMessages() << endl;
  display(state); // display logic
  state.write_to(_global_mem);
  _write_global_mem_to_file("end_mem");
  _write_global_yaml_to_file("react.yaml");
  delete _global_mem;
}
