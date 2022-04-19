#include<iostream>
//#include<ifstream>
#include <map>
#include <string>
#include <utility>
using namespace std;
int main () {
    string name = "";
    string county = "";
    int year;
    int medAQI;
    std::pair<string,string> pair1;
    std::pair<int,int> pair2;
    //input
    

    //map input
    map<pair<string,string>,pair<int,int>> pollutionMap;
    //map<string,int>::iterator iter;
    for(for i = 4; i < input.size(); i+4)
    {
        name = input.at(i);
        county = input.at(i+1);
        pair1 = make_pair(name,county);
        year = input.at(i+2);
        medAQI = input.at(i+3);
        pair2 = make_pair(year,medAQI);
        pollutionMap.insert(pair1,pair2);
    }
    return 0;
}