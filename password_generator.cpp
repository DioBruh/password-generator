#include <stdio.h>
#include <string>
#include <random>
#include <cstdlib>
#include <iostream>
#include <experimental/string_view>
#include <time.h>

using namespace std;
using namespace experimental;

const char alphanum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int string_length = sizeof(alphanum) - 1;
  

void args(string n){
    int i;
    int j = stoi(n);
    srand((unsigned int)time(NULL));
    for(i = 0; i < j; i++){
        cout << alphanum[rand() % string_length];
    }
}
int main(int argc, char* argv[]){
    int a = 0;
    if(argc < 2){
        cerr << "Invalid args!\nUsage: " << argv[0] << "-r||--range [INTEGER-RANGE]" << endl;
        exit(0);
    }
    if(string_view(argv[1])=="--help" or string_view(argv[1])=="-h"){
        cerr << "Usage: " << argv[0] << "-r||--range [INTEGER-RANGE]" << endl;
    }
    else if(string_view(argv[1]) == "-r" or string_view(argv[1]) == "--range"){
        args(argv[2]);
    }
    else{
      cerr << "Invalid args!\nUsage: " << argv[0] << "-r||--range [INTEGER-RANGE]" << endl;
      exit(0); 
    }
    return 0;
}
