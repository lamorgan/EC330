// Laura Morgan

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>  

using namespace std;
#define INF 99999999

    Graph::Graph(){}
  
    /* Adds a vertex to the graph.
       Returns the ID of the added vertex. */
    int Graph::addVertex()
    {   
    	vertices.insert(vertices.size());
    	return vertices.size();
    }
    
    /* Adds the given edge with the provided weight to the graph.
       The vertices of <newEdge> must currently exist in the graph. */
    void Graph::addEdge(directedEdge newEdge, int weight)
    {
        //check that vertices already exist
        int nope = vertices.size() - 1;
        if(newEdge.first > nope) {
            cout << "Vertex " << newEdge.first << " does not exist! Did not insert into graph" << endl;
        } else if(newEdge.second > nope) {
            cout << "Vertex " << newEdge.second << " does not exist! Did not Insert into graph" << endl;
        } else {

            if (isEdge(newEdge) == true) //check if edge already exists
            {
                cout << "Edge " << newEdge.first << "-" << newEdge.second << " already exists!" << '\n';
            }
            else
            {
                edges.insert(newEdge);                      // insert edge
                weights.insert(make_pair(newEdge,weight));  // insert into weight map
            }
        }
    }
    
    /* Returns the number of vertices in the graph. */
    int Graph::getNumVertices()
    {
        return vertices.size();
    }
    
    /* Returns the weight of the provided edge. The edge must exist in the graph. */
    int Graph::getWeight(directedEdge edge)
    {
        map<directedEdge, int>::iterator iter;

        for(iter = weights.begin(); iter != weights.end(); ++iter) // iteragtes through the weights map
        {
            if ((iter->first.first == edge.first) && (iter->first.second == edge.second))   // finds the location of the correct edges
            {
                return iter->second; // returns the corresponding weight
            }
        }
        return 0;   
    }

    /* Returns true iff there is an edge in the graph with the same vertices as newEdge. */
    bool Graph::isEdge(directedEdge newEdge)
    {
        map<directedEdge, int>::iterator iter;

        for(iter = weights.begin(); iter != weights.end(); ++iter)
        {

            if ((iter->first.first == newEdge.first) && (iter->first.second == newEdge.second))
            {
                return true;
            }

        }

    }
    
    /*Prints a human-readable version of the adjacency list of the graph.
      Format is: vertex: adjacent_vertex_1 (weight_1) adjacent_vertex_2 (weight_2) ... */
    void Graph::print()
    {
        cout << endl;
        int size;
        size = getNumVertices();

        set<int>::iterator it;
        set<directedEdge>::iterator iter;

        for (it = vertices.begin(); it != vertices.end(); ++it) //iterates through vertices
        {
            cout << *it << ": "; 

            for (iter = edges.begin(); iter != edges.end(); ++iter) // iterates through the edges
            {
                directedEdge m = *iter;

                if (m.first == *it) 
                {
                    cout << m.second << "(" << getWeight(make_pair(m.first,m.second)) << ")" << " "; // prints output for part a of homework
                }
            }

            cout << endl;
        }

    	cout << "\n";

    }
    
    /* Constructs a graph from the file with the provided name.
      The file format is as follows: 
      The first line contains the number of vertices and the number of edges, separated by a space,
      followed by optional additional text.
      The graph is assumed to contain vertices numbered 0 to 'number of vertices' - 1.
      Each of the remaining lines contain one edge specified by the source and destination vertices 
      followed by the weight, and separated by spaces. 
      Returns the constructed graph. */
    void Graph::generateGraph(string fileName)
    {
        int vertex1;
        int edgeNum;
        string words1;
        string words2;
        int vertex2;
        int weight;

        int counter = 0;

        ifstream myfile;

        myfile.open(fileName);

        while (!myfile.eof())
        {
    
            if (counter == 0)
            {
            	counter++;
                myfile >> vertex1 >> edgeNum >> words1 >> words2;

                for (int i = 0; i < vertex1; i++) //need to separate by spaces
                {
                    addVertex(); // sends to addVertex to add vertex to set
                }

            }
        	else
        	{
        		myfile >> vertex1 >> vertex2 >> weight; 

                addEdge(make_pair(vertex1, vertex2), weight); // send to addEdge to add to set and map
                
        	}   
                        
        }
        
        
    }


    // I modified Dijkstra's algorithm to not find the minimum during each while loop as the original algorithm did
    // In the modified algorithm the minimum is always the source and the goal is to only find the minimum path to each vertex so the minimum never changes
    // Since I did not have to keep track of the vertices in a linked-list or min-heap I just looped through the weights map instead
    void Graph::modifiedDijkstra(int source)
    {
    	distance.clear();

        // initializes the distance vector (implemented in the header file) to the size of the vertices and makes all distances INF
        for (int i = 0; i < vertices.size(); i++)
        {
             distance.push_back(INF);
        }
        
        // distance of the source vertex is 0
        distance[source] = 0;

        int u = source;//vertex with minimum weight
        
        set<directedEdge>::iterator it_edge;
        map<directedEdge, int>::iterator iter;
        map<directedEdge, int>::iterator it;


        for(it = weights.begin(); it != weights.end(); ++it)                        // iterates through the weights map
        {
            
            for (int i = 0; i < getNumVertices(); i++)                              
            {
                	int weight = getWeight(make_pair(u,it->first.second));         // gets the weight of the edge connecting the source node and an adjacent vertex
                    if (weight != 0){
                	   Relax(u, it->first.second, weight);                         // if there is an edge between vertices, sends to Relax
                    }
                
                	for (int j = i+1; j < getNumVertices(); j++)                   
                	{    
                    	int weight = getWeight(make_pair(it->first.second, j));    // gets weight of adjacent vertex
                        if(weight != 0) {
                    	   Relax(it->first.second, j, weight);                     // sends to Relax
                        }
                	}
            }

        }

        cout << "Shortest paths from node " << source << ":" << endl;

        for (int i = 0; i < getNumVertices(); i++)
        {
        	if (i != source) {
                if(distance[i] != INF){ // if the distance exists it prints the distance
            	   cout << "Distance to vertex " << i << " is " << distance[i] << " and there are 1 shortest paths" << endl;
                } else {    
                    cout << "There is no path to vertex " << i << endl;     // if the distance is still INF then no shortest path exists
                }
        	}
        }

    }

    // Relax updates the distance vector
    void Graph::Relax(int u, int v, int weight)
    {

        if (distance[v] > distance[u] + weight)
        {
            // Updating distance of v
            distance[v] = distance[u] + weight;
            
        }
    }
