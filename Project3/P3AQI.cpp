
#include<iostream>
#include<fstream>
#include <map>
#include<string>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;
int main ()
 {
    vector<vector<string>> csv;
    vector<string> data;
    string name = "";
    string county = "";
    int year;
    int medAQI;
    string filename("Project3.csv");
    fstream file(filename,ios::in);
    std::pair<string,string> pair1;
    std::pair<int,int> pair2;
    map<pair<string,string>,pair<int,int>> pollutionMap;
    unordered_map<pair<string,string>,pair<int,int>> unorderedPollutionMap;
    if(file.is_open())
    {
        while(file >> name >> county >> year >> medAQI)
        {
            pair1 = make_pair(name,county);
            pair2 = make_pair(year,medAQI);
            pollutionMap.emplace(pair1,pair2);
            unorderedPollutionMap.emplace(pair1,pair2);
        }

    }


    
    return 0;
}