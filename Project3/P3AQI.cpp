#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;
 
int main()
{
 
   ifstream dataFile; // read in csv file
   ofstream dataSet("data.txt");
 
   string state;
   string county;
   string year;
   string daysAQI;
   string goodDays;
   string modDays;
   string maxAQI;
   string percentAQI;
   string medianAQI;
 
   map<pair<string, string>, vector<string>> pollutionMap;
   // unordered_map<pair<string, string>, vector<string>> unorderedPollutionMap;
 
   dataFile.open("Project3.csv"); // open file
   while (!dataFile.eof())
   {
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
 
      pollutionMap[{state, county}].push_back(year);
      pollutionMap[{state, county}].push_back(daysAQI);
      pollutionMap[{state, county}].push_back(goodDays);
      pollutionMap[{state, county}].push_back(modDays);
      pollutionMap[{state, county}].push_back(maxAQI);
      pollutionMap[{state, county}].push_back(percentAQI);
      pollutionMap[{state, county}].push_back(medianAQI);
 
      // cout << state << endl;
      // cout << "State == Alabama" << (state == "Alabama");
      // state.resize(state.size() - 1);
   }
 
   cout << "Welcome to Air Pollution Tracking Index\n----------------------------------\n";
   cout << "This application takes in a state name and subsequently\n";
   cout << "Please enter a state: ";
   cin >> state;
   string test = "Alabama";
   cout << "---------\n";
   for (auto const &iter : pollutionMap)
   {
 
      if (iter.first.first == state)
      {
         cout << "County: " << iter.first.second << endl;
         cout << "Year: " << iter.second.at(0) << endl;
         cout << "Air Quality Index Days (AQI): " << iter.second.at(1) << endl;
         cout << "Good Days: " << iter.second.at(2) << endl;
         cout << "Mod Days: " << iter.second.at(3) << endl;
         cout << "Max Air Quality Index: " << iter.second.at(4) << endl;
         cout << "Percent Air Quality Index: " << iter.second.at(5) << endl;
         cout << "Median Air Quality Index: " << iter.second.at(6) << endl
              << endl;
      }
   }
}
