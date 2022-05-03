#include<iostream>
#include<fstream>
#include<cassert>
#include"/usr/local/cs/cs251/react.h"
#include"state.h"
using namespace std;

State state;

void test_display() {
  display(state);
}

int main() {
  _read_global_mem_from_file("frame1.txt");
  state.read_from(_global_mem);
  /*ifstream f_label("labels.txt");
  f_label.read(_global_mem + state.offset("labelStart"), 4000);*/
  test_display();
  _write_global_yaml_to_file("react.yaml");
  _write_global_mem_to_file("end_mem");
  delete _global_mem;
}
