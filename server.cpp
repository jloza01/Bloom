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
  //cout<<_global_mem[500]<< "line 13"<<endl;
  state.read_from(_global_mem);
  //cout<< state.numMessages<<"line 15" << endl;
  ifstream f_label("labels.txt");
  f_label.read(_global_mem + state.offset("labelStart"), 162);
  
  state.read_lab(_global_mem + state.offset("labelStart"));
 
  


  

  //if (! _just_starting()) state.read_from(_global_mem);
  cout<<_global_mem[500]<< "line 27"<<endl;
  state.update(); // event handling
  display(state); // display logic
  //cout<< state.numMessages << "line 30"<<endl;
  state.write_to(_global_mem);
  _write_global_mem_to_file("end_mem");
  _write_global_yaml_to_file("react.yaml");
  //cout<<_global_mem[500]<< "line 34"<<endl;
  delete _global_mem;
}
