#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <random>
#include <iomanip>
struct BFF {
  std::string name;
  std::string SSN;
  double monies;
  double hrs;
  double gross;
  };
BFF ReadCSV(std::string &line);
void ParseString(std::string &s, std::string &t);
void Outprint(std::vector <BFF> v);
int main() {
  std::string line;
  std::ifstream CSV;
  CSV.open("../EmployeeData.csv");
  if (!CSV.is_open()) {
      std::cout <<"NO";
      return 1;
  }
    bool skip = true;
  std::vector <BFF> Group;
  while (std::getline(CSV, line)) {
      if (!skip){
      Group.push_back(ReadCSV(line));
  }
    else skip = false;
  }
  Outprint(Group);



  std::random_device rd;
  std::mt19937 rand(rd());

  std::shuffle(Group.begin(), Group.end(), rand);
  Outprint(Group);

  std::sort(Group.begin(), Group.end(), [](BFF a, BFF b){return a.gross>b.gross;});
  Outprint (Group);



  return 0;
}
BFF ReadCSV(std::string &line){
std::string s;
  BFF NMW;
  ParseString(line,NMW.name);
  ParseString(line,NMW.SSN);
  ParseString(line,s);
NMW.monies=std::stod(s);
  ParseString(line,s);
NMW.hrs=std::stod(s);
  NMW.gross=(NMW.monies)*(NMW.hrs);
  return NMW;
}




void ParseString(std::string &s, std::string &t) {
  int l = s.find(',');
  t = s.substr(0, l);
  s=s.substr(l+1);
}




void Outprint(std::vector <BFF> v) {
  std::cout<<"----------------------------------------------------------------------------\n";
for (int i = 0; i < v.size(); ++i) {
  std::cout<<std::setw(15) << std::left<<v.at(i).name;
  std::cout<<std::setw(15) << v.at(i).SSN;
  std::cout<<std::setw(0) << "$"<<std::fixed << std::setprecision(2)<< std::setw(14)<<v.at(i).monies;
  std::cout<<std::setw(15) << v.at(i).hrs;
  std::cout<<std::setw(0) << "$"<<std::setw(14) << v.at(i).gross;
   std::cout<<std::endl;
}




}























