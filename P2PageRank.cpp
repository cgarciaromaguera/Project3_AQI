#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <bits/stdc++.h>
using namespace std;

class AdjacencyList{
    private:
        //representation of a AdjacencyList 
        //primary strucutre to hold the webpages 
        int numVertices = 0; //Each node in a Graph is called a Vertex
        //store pages using a map, where strings are mapped to vectors of pairs
        map<string,vector<pair<string, double>>> pageGraph; //directed graph
        map<string,double> initial; //pass in double (initial value)
        map<string,double> prevRank; //pass in edges 
        map<string,double> updatedRank; //every power iterartion updated
        map<string,double> outDegree; 

    public:
        void pageInsert(string from, string to);
        void InitialValue();
        void PageRank(int n); //power iterator
}; 

void AdjacencyList::pageInsert(string from, string to){ 
    //map<string , vector<string> > pageGraph; 
    //map<string , vector<string> > prevRank;
    //map<string,double> outDegree; 

    //vertices set 
    pageGraph[to].push_back(make_pair(from,-1));
    prevRank[from] = 0;
    if (outDegree.count(from) == 0)
    {
        outDegree[from] = 1;
    }
    else {
        outDegree[from]++; //outdegree + 1
    }
    if (outDegree.count(to) == 0)
    {
        outDegree[to] = 0;
    }
    if (pageGraph.find(from) == pageGraph.end()) //if empty
    {
         pageGraph[from] = {}; //set to empty, 0
    }
}

void AdjacencyList::InitialValue(){ //num vertices
    //map<string,double> initial; 
    int n = outDegree.size(); 
    for (auto it = pageGraph.begin(); it != pageGraph.end(); it++) //p is a pair
    { 
        initial[it->first] = 1.0/n; //setting ranks to 1/n
        // Update adjacency list values
        vector<pair<string, double>> v = it->second;
        for(int i = 0; i < v.size(); i++){
            it->second.at(i).second = 1.0 / outDegree[it->second.at(i).first];
        }
    }
}

 void AdjacencyList::PageRank(int n){ //power iterations = n
    //pair of strings called vertices and loop to compute powerrank
    //representation of an AdjacencyList to perform page rank
    for (int i = 0; i < n-1; i++) //go through vertices and decrement by 1
    {
         //upadate next rank (swap), set previous rank
        int count = 0;
        for (auto itr = pageGraph.begin(); itr != pageGraph.end(); itr++)
        { 
            float sum = 0;
            vector<pair<string, double>> vec = itr->second; //create vector
            for(int i = 0; i < vec.size(); i++)
            {
                sum += initial[vec.at(i).first] * vec.at(i).second; //initial times vector
            } 
        updatedRank[itr->first] = sum; //set sum to updatedRank
        count++;
        }
            //set prevRank to updatedRank
        float count1 = 0;
        for (auto iter = prevRank.begin(); iter != prevRank.end(); iter++) //iterate through prevRank
        { 
            for (int j = 0; j < prevRank.size(); j++)
            {
                initial[iter->first] = updatedRank[iter->first]; //set updatedRank to initial 
            }
         count1++;
        }
    }
         //prints the PageRank of all pages after p poweriterations 
     for (auto itr = initial.begin(); itr != initial.end(); itr++) //iterate through initial (value) 
        {
            cout << fixed << setprecision(2); //Sets the decimal precision
            cout << itr->first << " " << itr->second << endl;
        }
 }

int main(){
    //read first number of lines (n) from cin
    AdjacencyList adjList;
    int n;
    cin >> n;

    //read the number of power iterations (p) from cin
    int p;
    cin >> p;

    //for each of the next n lines, read in the vertices from and to 
    for (int i = 0; i < n; i++)
    {
        //read in the source vertex 
        string from;
        cin >> from;

        //read in the destination vertex 
        string to;
        cin >> to;

        //add vertices/edge(from->to) to adjacency list
        adjList.pageInsert(from, to);
    }
    // power iterations 
    adjList.InitialValue();
    adjList.PageRank(p);

    return 0;
}