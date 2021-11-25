//
//  File: graph.h
//  Date: 18/11/2021
//  Author: Said Ortigoza
//  Description: Implementación de la clase Graph
//
//  Copyrigth (c) 2021 by Tecnologico de Monterrey.
//  All Rights Reserved. May be reproduced for any non-commercial
//  purpose
//

#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#pragma once
#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    int nodes;
    int edgesList;
    int edgesMat;
    vector<int> *adjList;
    int *adjMatrix;

public:
    Graph();
    Graph(int);

    void loadGraphList(string, int, int);
	  void loadGraphMat(string, int, int);

    void addEdgeAdjMatrix(int, int);
    void addEdgeAdjList(int, int);

    string printAdjMat();
    string printAdjList();

    string DFS(int, int);
    void dfsHelper(int, int, stack<int> &, list<int> &, vector<vector<int>> &, stringstream &);

    string BFS(int, int);
    void bfsHelper(int, int, queue<int> &, list<int> &, vector<vector<int>> &, stringstream &);

    static void printPath(vector<vector<int>> &, int, int, stringstream &);
    static void printVisited(list<int>, stringstream &);

    static bool contains(list<int>, int);
    void sortAdjList();
};

Graph::Graph() {
    edgesList = edgesMat = nodes = 0;
    adjList = {};
    adjMatrix = nullptr;
}

Graph::Graph(int n) {
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for (int i = 0; i < nodes*nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;
}

void Graph::loadGraphMat(string name, int a, int b)
{
	adjMatrix = new int[a * b];
	nodes = a;
	for (int i = 0; i < a * b; i++)
		adjMatrix[i] = 0;
	string line;
	ifstream lee(name);
	int u, v;
	if (lee.is_open())
	{
		while (getline(lee, line))
		{
			u = stoi(line.substr(1, 1));
			v = stoi(line.substr(4, 1));
			addEdgeAdjMatrix(u, v);
		}
		lee.close(); // Closes the file
	}
	else
	{
		cout << "Unable to open file";
	}
}

void Graph::loadGraphList(string name, int a, int b)
{
	adjList = new vector<int>[a];
	nodes = a;
	string line;
	ifstream lee(name);
	int u, v;
	if (lee.is_open())
	{
		while (getline(lee, line))
		{
			u = stoi(line.substr(1, 1));
			v = stoi(line.substr(4, 1));
			addEdgeAdjList(u, v);
		}
		lee.close(); // Closes the file
	}
	else
	{
		cout << "Unable to open file";
	}
	sortAdjList();
}

void Graph::addEdgeAdjMatrix(int u, int v) {
    adjMatrix[u * nodes + v] = 1;
    adjMatrix[v * nodes + u] = 1;
    edgesMat++;
}

void Graph::addEdgeAdjList(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edgesList++;
}

string Graph::printAdjList() {
    sortAdjList();
    stringstream aux;
    for (int i = 0; i < nodes; i++) {
        aux << "vertex "
            << i << " :";
        for (int j: adjList[i]) {
            aux << " " << j;
        }
        aux << " ";
    }
    return aux.str();
}

string Graph::printAdjMat() {
    stringstream aux;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            aux << adjMatrix[i * nodes + j] << " ";
        }
    }
    return aux.str();
}

string Graph::DFS(int start, int target) {
    stringstream aux;
    stack<int> my_stack;
    list<int> visited;
    vector<vector<int>> paths(nodes, vector<int>(1, -1));
    my_stack.push(start);
    dfsHelper(start, target, my_stack, visited, paths, aux);
    printPath(paths, start, target, aux);
    return aux.str();
}

void Graph::dfsHelper(int current, int target, stack<int> &stack, list<int> &visited, vector<vector<int>> &paths, stringstream &aux) {
    if (current == target) {
        printVisited(visited, aux);
    } else if (stack.empty()) {
        aux << "node not found";
    } else {
        current = stack.top();
        stack.pop();
        visited.push_back(current);
        for (int i = 0; i < adjList[current].size(); i++) {
            if (!contains(visited, adjList[current][i])) {
                stack.push(adjList[current][i]);
                paths[adjList[current][i]][0] = current;
            }
        }
        dfsHelper(current, target, stack, visited, paths, aux);
    }
}

string Graph::BFS(int start, int target) {
    stringstream aux;
    queue<int> queue;
    list<int> visited;
    vector<vector<int>> paths(nodes, vector<int>(0));
    queue.push(start);
    bfsHelper(start, target, queue, visited, paths, aux);
    printPath(paths, start, target, aux);
    return aux.str();
}

void Graph::bfsHelper(int current, int target, queue<int> &queue, list<int> &visited, vector<vector<int>> &paths, stringstream &aux) {
    if (current == target) {
        printVisited(visited, aux);
    } else if (queue.empty()) {
        aux << "";
    } else {
        current = queue.front();
        queue.pop();
        visited.push_back(current);
        for (int i = 0; i < adjList[current].size(); i++) {
            if (!contains(visited, adjList[current][i])) {
                queue.push(adjList[current][i]);
                paths[adjList[current][i]].push_back(current);
            }
        }
        bfsHelper(current, target, queue, visited, paths, aux);
    }
}

void Graph::printVisited(list<int> visited, stringstream &aux) {
    aux << "visited: ";
    while (!visited.empty()) {
        aux << visited.front() << " ";
        visited.pop_front();
    }
}

void Graph::printPath(vector<vector<int>> &path, int start, int target, stringstream &aux) {
    aux << "path: ";
    int node = path[target][0];

    stack<int> reverse;
    reverse.push(target);

    while (node != start) {
        reverse.push(node);
        node = path[node][0];
    }
    reverse.push(start);
    while (!reverse.empty()) {
        aux << reverse.top();
        reverse.pop();
        if (!reverse.empty())
            aux << " ";
    }
}

void Graph::sortAdjList() {
    for (int i = 0; i < nodes; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }
}

bool Graph::contains(list<int> lista, int node) {
    list<int>::iterator it;
    it = find(lista.begin(), lista.end(), node);
    if (it != lista.end()) {
        return true;
    } else {
        return false;
    }
}

#endif