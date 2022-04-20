#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <limits>

#include <ctime>
#include<chrono>
using namespace std;
using namespace std::chrono;
 
map<pair<string, string>, vector<string>> pollutionMap;
unordered_map<pair<string, string>, vector<string>> unorderedPollutionMap;

string state;
   string county;
   string year;
   string daysAQI;
   string goodDays;
   string modDays;
   string maxAQI;
   string percentAQI;
   string medianAQI;  
 /*void timeClock()
 {
         time_t currTime;
         currTime = time(NULL);
         //cout << currTime;
        std::cout << "This took:" << currTime << endl;
        return;
     }*/
void insertMap()
{
      pollutionMap[{state, county}].push_back(year);
      pollutionMap[{state, county}].push_back(daysAQI);
      pollutionMap[{state, county}].push_back(goodDays);
      pollutionMap[{state, county}].push_back(modDays);
      pollutionMap[{state, county}].push_back(maxAQI);
      pollutionMap[{state, county}].push_back(percentAQI);
      pollutionMap[{state, county}].push_back(medianAQI);
}
void insertUnorderedMap()
{
    unorderedPollutionMap[{state, county}].push_back(year);
    unorderedPollutionMap[{state, county}].push_back(daysAQI);
    unorderedPollutionMap[{state, county}].push_back(goodDays);
    unorderedPollutionMap[{state, county}].push_back(modDays);
    unorderedPollutionMap[{state, county}].push_back(maxAQI);
    unorderedPollutionMap[{state, county}].push_back(percentAQI);
    unorderedPollutionMap[{state, county}].push_back(medianAQI);
}
int main()
{
 
   ifstream dataFile; // read in csv file
   ofstream dataSet("data.txt");
   ofstream dataMap("dataMap.txt");
   ofstream unorderedMap("dataUnordered.txt");  
   dataFile.open("Project3.csv"); // open file
   int i;   
   while (!dataFile.eof())
   {
      i++;
      dataFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      getline(dataFile, state, ',');
      getline(dataFile, county, ',');
      getline(dataFile, year, ',');
      getline(dataFile, daysAQI, ',');
      getline(dataFile, goodDays, ',');
      getline(dataFile, modDays, ',');
      getline(dataFile, maxAQI, ',');
      getline(dataFile, percentAQI, ',');
 
      dataFile >> medianAQI;
      dataSet << state << endl;
      dataSet << county << endl;
      dataSet << year << endl;
      dataSet << daysAQI << endl;
      dataSet << goodDays << endl;
      dataSet << modDays << endl;
      dataSet << maxAQI << endl;
      dataSet << percentAQI << endl;
      dataSet << medianAQI << endl;
    //dataSet << endl;
      insertMap();
      insertUnorderedMap(); 
      // cout << state << endl;
      // cout << "State == Alabama" << (state == "Alabama");
      // state.resize(state.size() - 1);
   }
 
   std::cout << "aasdfasdfWelcome to Air Pollution Tracking Index\n----------------------------------\n";
   std::cout << "This application takes in a state name and subsequently\n";
   std::cout << "Please enter a state: ";
   std::cin >> state;
   string test = "Alabama";
   std::cout << "---------\n";
   
   clock_t start,end;
   start = clock();
   std::cout<< "Did this run" << endl;
   for (auto const &iter : pollutionMap)
   {
 
      if (iter.first.first == state)
      {
         std::cout << "County: " << iter.first.second << endl;
         std::cout << "Year: " << iter.second.at(0) << endl;
         std::cout << "Air Quality Index Days (AQI): " << iter.second.at(1) << endl;
         std::cout << "Good Days: " << iter.second.at(2) << endl;
         std::cout << "Mod Days: " << iter.second.at(3) << endl;
         std::cout << "Max Air Quality Index: " << iter.second.at(4) << endl;
         std::cout << "Percent Air Quality Index: " << iter.second.at(5) << endl;
         std::cout << "Median Air Quality Index: " << iter.second.at(6) << endl;
      }
        end = clock();
        double Timer = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by program is : " << fixed 
         << Timer;
         cout << " sec " << endl;
   }
  
  for (auto const &iter : pollutionMap)
   {
 
      if (iter.first.first == state)
      {
         dataMap << "County: " << iter.first.second << endl;
         dataMap << "Year: " << iter.second.at(0) << endl;
         dataMap << "Air Quality Index Days (AQI): " << iter.second.at(1) << endl;
         dataMap << "Good Days: " << iter.second.at(2) << endl;
         dataMap << "Mod Days: " << iter.second.at(3) << endl;
         dataMap << "Max Air Quality Index: " << iter.second.at(4) << endl;
         dataMap << "Percent Air Quality Index: " << iter.second.at(5) << endl;
         dataMap << "Median Air Quality Index: " << iter.second.at(6) << endl;   
      }
     
   }
    
   return 0;
}
