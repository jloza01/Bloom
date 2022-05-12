#include<iostream>
#include <fstream>
#include"state.h"
#include"/usr/local/cs/cs251/react.h"
using namespace std;

int main() {
  State state;

  _read_global_mem_from_file("frame1.txt");
  
  state.read_from(_global_mem);
  ifstream f_label("labels.txt");
  f_label.read(_global_mem + state.offset("labelStart"), 162);
  state.read_lab(_global_mem + state.offset("labelStart"));
  _read_event_info_file("event_info");

  state.read_from(_global_mem);

  if (! _just_starting()) state.read_from(_global_mem);

  state.update(); // event handling
  display(state); // display logic

  state.write_to(_global_mem);
  _write_global_mem_to_file("end_mem");
  _write_global_yaml_to_file("react.yaml");
  delete _global_mem;
}
