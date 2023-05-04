
#include <iostream>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class graph {
    int vertices;
    list<int>* adjecentList;
public:
    graph(int vertices) {
        vertices = vertices;
        adjecentList = new list<int>[vertices];
    }
    void createEdge(int u, int v) {
        adjecentList[u].push_back(v);
    }

    void TopologicalSortstack() {

        vector<int> indegree_count(vertices, 0);

        for (int i = 0;i < vertices;i++) {
            list<int>::iterator itr;
            for (itr = adjecentList[i].begin(); itr != adjecentList[i].end();itr++) {
                indegree_count[*itr]++;
            }
        }
        stack<int> S;
        for (int i = 0; i < vertices;i++) {
            if (!visited_node[i]) {
                S.push(i);
            }
        }
        int visited_node = 0;
        vector<int> order;
        while (!S.empty()) {
            int u = S.top();
            S.pop();
            order.push_back(u);

            list<int>::iterator itr;
            for (itr = adjecentList[u].begin(); itr != adjecentList[u].end();itr++) {
                if (--indegree_count[*itr] == 0) {
                    S.push(*itr);
                }
            }
            visited_node++;
        }
        if (visited_node != vertices) {
            cout <<endl<< "There's a cycle present in the Graph.\nGiven graph is not DAG" << endl;
            return;
        }
        for (int i = 0; i < order.size();i++) {
            cout <<endl<<"Using stack"<< order[i] << "\t";
        }
    }


    void TopologicalSort() {
        
        vector<int> indegree_count(vertices, 0);

        for (int i = 0;i < vertices;i++) {
            list<int>::iterator itr;
            for (itr = adjecentList[i].begin(); itr != adjecentList[i].end();itr++) {
                indegree_count[*itr]++;
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
                if (--indegree_count[*itr] == 0) {
                    Q.push(*itr);
                }
            }
            visited_node++;
        }
        if (visited_node != vertices) {
            cout << "There's a cycle present in the Graph.\nGiven graph is not DAG" << endl;
            return;
        }
        for (int i = 0; i < order.size();i++) {
            cout << "Using queue" << order[i];
        }
    }



};
int main() {
    graph G(6);
    G.createEdge(0, 1);
    G.createEdge(0, 2);
    G.createEdge(1, 3);
    G.createEdge(1, 5);
    G.createEdge(2, 3);
    G.createEdge(2, 5);
    G.createEdge(3, 4);
    G.createEdge(5, 4);
    G.TopologicalSort();
    G.TopologicalSortstack();
}