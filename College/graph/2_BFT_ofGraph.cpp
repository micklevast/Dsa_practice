#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
vector<int> graph[4]{
    {0, 1, 0, 1},
    {1, 0, 0, 1},
    {0, 1, 1, 1},
    {1, 1, 1, 0}};
void graph_traversal()
{
    for (int i = 0; i < 4; i++)
    {
        for (auto x = graph[i].begin(); x != graph[i].end(); x++)
        {
            cout << *x << " ";
        }
        cout << endl;
    }
}
int main()
{
    int visited_arr[4] = {0};
    int x=3; //ele visited
    q.push(x);  //put in queue for exploring
    
    cout << x << " ";
    visited_arr[x] = 1;
    while (!q.empty())
    {
         x=q.front();
         q.pop();

        for (int a = 0; a < 4; a++)
        {
            if (graph[x][a] == 1 && visited_arr[a] == 0)
            {
                cout << a << " ";
                visited_arr[a] = 1; //ele visited
                q.push(a); //put in queue for exploring
            }
        }
    }
}