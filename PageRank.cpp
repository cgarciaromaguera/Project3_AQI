#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <bits/stdc++.h>
using namespace std;

//need to store webpages as nodes in a directed graph 
class AdjacencyList{
    private:
        //create your representation of a AdjacencyList 
        //primary strucutre to hold the webpages 
        //store pages using a map, where strings are mapped to vectors of pairs
        int numVertices = 0; //Each node in a Graph is called a Vertex
        map<string , vector<pair<string, double>>> pageGraph;
        //map<string , vector<string> > reversePageGraph;
        //four of: 
        map<string,double> initial; //pass in int (initial value)
        map<string,double> prevRank; //successive //pass in it //edges //previous rank 1/sizeofgraph
        map<string,double> updatedRank; //every power iterartion updated
        map<string,double> outDegree; 
        // map<string,double> matrixMult; 

    public:
        void PageRank(int n); //power iterator //read in a decrement by 1
        void pageInsert(string from, string to);
        void OutDegreeCount(int n);
        void InitialValue(int n);
        //more
        void MatrixMultiply(int n); //use set vertices 
        //if power iter (n)= 1 --> for loop (ininitial) goes through map at 
        //set percision 
        //else if iter = 2 call page graph --> add work 
        //else r
}; 

void AdjacencyList::pageInsert(string from, string to){ 
    //map<string , vector<string> > pageGraph; 
    //map<string , vector<string> > reversePageGraph;
    //map<string,double> outDegree; 

    //vertices set 
    //outdegree + 1
    pageGraph[to].push_back(from);
    //if empty
    if (pageGraph.find(to) == pageGraph.end())
    {
         pageGraph[to] = {};
    }
}

void AdjacencyList::InitialValue(int n){
    //num vertices
    //map<string,double> initial; 
    for (auto p : pageGraph){ //p is pair
        initial[p.first] = 1.0/n; //setting ranks to 1/n
    } 
 
}
void outDegreeCount(int n){
    for (auto c : pageGraph){
      outDegree[c.first] = c.size();  
    }
}
void AdjacencyList::PageRank(int n){ //power iterations = n
    //set of strings called vertices and loop to compute powerrank
    //use your representation of an AdjacencyList 
    //to perform the PageRank alogrithm 
    //prints the PageRank of all pages after p poweriterations in ascending alphabetical order 
    //of webpages and rounding the rank to two decimal places

    for (int i = 0; i < n-1; i++)
    {
        //for (go through vertices)
        //upadate next rank (swap), set previous rank
        //numVertices = 1;
        prevRank = initial.begin(); 
         MatrixMultiply(numVertices); //call matrix multiply
            //set prevRank to updatedRank
        int count = 0;
        for (auto i = prevRank.begin(); i != prevRank.end(); i++){
            prevRank[count] = updatedRank[count]; //do i need to access [ ] ??????
            count++;
        }
        for (auto j = prevRank.begin(); j != prevRank.end(); j++){
            prevRank->first;
            prevRank->second;
        }
    }
}

void AdjacencyList::MatrixMultiply(int n)
{
        int count = 0;
        for (auto j = pageGraph.begin(); j != pageGraph.end(); j++){
            vector<pair<string, double>> vec = j;
            for(auto v = 0; v < vec.size(); v++)){
                updatedRank[count] += prevRank[v.first]->second * v.second; // updatedRank[iter->first]; initial[v.second];
            } 
            count++;
        } 

    // updatedRank = matrix x prev rank
    //put inside updated
}


int main(){
    //read first number of lines (n) from cin
    int n;
    cin >> n;

    //read the number of power iterations (p) from cin
    int p;
    cin >> p;

    //for each of the next n lines, read in the vertices from and to 
    for (int i = 0; i < n; i++){
        string line;
        getline(cin, line); //read each line and split it by spaces 
        istringstream in(line);

        //read in the source vertex 
        string from;
        in >> from;

        //read in the destination vertex 
        string to;
        in >> to;

        //ADD VERTICES/EDGE(FROM->TO) TO YOUR ADJACENCY LIST HERE
        map<string, vector<string>>::iterator it;
        for(it = graph.begin(); it != graph.end(); ++it)
        {
            cout << it->first;
            for(int j = 0; j < it->second.size(); j++)
                cout << " " << it->second[j];
        cout<< endl;
        }
        //pageGraph.pageInsert(from, to)

    }
    //DO POWER ITERATIONS HERE
    //create a graph object
    pageGraph.PageRank(p);

    return 0;
}
