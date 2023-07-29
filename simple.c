// simple C host with s7 interpreter in it
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "s7.h"
#ifdef __EMSCRIPTEN__
  #include "emscripten.h"
#endif

// js function for C to js calls
extern void updateHostResults(const char* results_msg);

s7_scheme *s7;

int main(int argc, char **argv){
  s7 = s7_init();
  // call something, note that display and printf are routed automatically to the console
  s7_eval_c_string(s7, "(define a \"main running\")");
  s7_eval_c_string(s7, "(display a)");  
  printf("\n");
}

#ifdef __EMSCRIPTEN__
  EMSCRIPTEN_KEEPALIVE
#endif
int eval_string(const char* input_str){
  printf("C> eval_string() %s", input_str);
  s7_pointer result = s7_eval_c_string(s7, input_str);
  updateHostResults( s7_object_to_c_string(s7, result) );
  return 0;
}

// function that is called from JS code
#ifdef __EMSCRIPTEN__
  EMSCRIPTEN_KEEPALIVE
#endif
int add(int arg1, int arg2){
  printf("add()\n");

  // call into the JS function
  int result = arg1 + arg2;
  printf("  result: %i", result);

  char result_str[100];
  sprintf(result_str, "result is: %i", result);
  updateHostResults(result_str);

  return result;
}

