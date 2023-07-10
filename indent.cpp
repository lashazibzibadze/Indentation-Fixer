/* 
Author: Lasha Zibzibadze
Course: CSCI-135
Instructor: Genady Maryash

This program blocks opened and closed by { and }, and adding real indentation.
*/
#include <iostream>
#include <cctype>
using namespace std;

int countChar(string line, char c) {
  int counter= 0;
  for(int i=0; i< line.size(); i++){
    if(line[i] == c){
      counter++;
    }
  }

  return counter;

}

string removeLeadingSpaces(string line) {

  int index = 0;
  int counter= 0;
  string test;
  for(int i = 0; i < line.size(); i++){
    int k= line[i];
  
    if(!isspace(k)){
      counter= i;
      break;
    }

  }
  int m= line.size();
  string new_string;
  new_string= line.substr(counter, m);

  return new_string;


}

int main() {
  int tracker=0;
  string s;

  while(getline(cin,s)){
    string clean_file= removeLeadingSpaces(s);
    if(clean_file[0] == '}'){
      tracker= tracker- countChar(s, '}');
    }
    
    for(int i=0; i< tracker; i++){
      cout<< "\t";
    }
    cout<< clean_file << endl;

    tracker= tracker+ countChar(s, '{');

    if(clean_file[0] != '}'){
      tracker= tracker- countChar(s, '}');
    }    
    







  }

  return 0;
}