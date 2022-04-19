#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(){

   ifstream dataFile; //read in csv file
   ofstream dataSet ("data.txt");

   string state;
   string county; 
   string year;
   string mAQI;

   dataFile.open("Project3.csv"); //open file 
   int i;
   while (!dataFile.eof()){
      i++;
      getline(dataFile, state, ',');
      getline(dataFile, county, ',');
      getline(dataFile, year, ',');
      dataFile >> mAQI;
      dataSet << state << endl;
      dataSet << county << endl;
      dataSet << year << endl;
      dataSet << mAQI << endl;
   }
}

