using namespace std;
#include<iostream>
#include<fstream>
#include <map>
#include<string>
#include <utility>

int main ()
 {
    vector<vector<std::string>> csv;
    vector<string> data;
    string name = "";
    string county = "";
    int year;
    int medAQI;
    fstream file(Project3.csv,ios::in);
    if(Project3.csv.is_open())
    {


    }
    std::pair<string,string> pair1;
    std::pair<int,int> pair2;
    //input
    

    //map input
    map<pair<string,string>,pair<int,int>> pollutionMap;
    //map<string,int>::iterator iter;
    for(for i = 4; i < csv.size(); i+4)
    {
        name = csv.at(i);
        county = csv.at(i+1);
        pair1 = make_pair(name,county);
        year = csv.at(i+2);
        medAQI = csv.at(i+3);
        pair2 = make_pair(year,medAQI);
        pollutionMap.insert(pair1,pair2);
    }
    return 0;
}