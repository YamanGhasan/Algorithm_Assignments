#include <iostream>
#include <stack>
#include <list>
#include <queue> 
using namespace std;

class graph {
public:
    graph(int vertices) {
        this->vertices = vertices;
        adjecentList = new list<int>[vertices];
    }
    void newedge(int u, int v) {
        adjecentList[u].push_back(v);
    }
 
    void topologicalSortStack()
    {
        stack<int> Stack;

        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = false; 

        for (int i = 0; i < vertices; i++)
            if (visited[i] == false)
                topologicalSortUtil(i, visited , Stack );

        cout << "Stack :";
        while (Stack.empty() == false) {
            int x = Stack.top();
            cout << x << "\t";
            
        }
    }

    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack) {
        visited[v] = true;  
        list<int>::iterator i;
        for (i = adjecentList[v].begin(); i != adjecentList[v].end(); ++i)
            if (!visited[i]) 
                topologicalSortUtil(i, visited, Stack);
                 Stack.push(v);
    }

};



void  graph::TopologicalSort() {

    vector<int> indegree_count(vertices, 0);

    for (int i = 0;i < vertices;i++) {
        list<int>::iterator itr;
        for (itr = adjecentList[i].begin(); itr != adjecentList[i].end();itr++) {
            indegree_count[itr]++;
        }
    }
    queue<int> Q;
    for (int i = 0; i < vertices;i++) {
        if (indegree_count[i] == 0) {
            Q.push(i);
        }
    }
    int visited_node = 0;
    vector<int> order;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        order.push_back(u);

        list<int>::iterator itr;
        for (itr = adjecentList[u].begin(); itr != adjecentList[u].end();itr++) {
            if (--indegree_count[itr] == 0) {
                Q.push(itr);
            }
        }
        visited_node++;
    }
    if (visited_node != vertices) {
        cout << "There's a cycle present in the Graph.\nGiven graph is not direct acyclic garph" << endl;
        return;
    }
    cout << "Queue : ";
    for (int i = 0; i < order.size();i++) {
        cout << order[i] << "\t";
    }
}

int main() {
    graph T(6);
    T.newedge(0, 1);
    T.newedge(0, 2);
    T.newedge(1, 3);
    T.newedge(1, 5);
    T.newedge(2, 3);
    T.newedge(2, 5);
    T.newedge(3, 4);
    T.newedge(5, 4);
    T.topologicalSortStack();
    T.TopologicalSort();
    return 0;
}
