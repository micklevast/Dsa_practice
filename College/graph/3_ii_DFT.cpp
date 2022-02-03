#include<iostream>
using namespace std;
int visited[7] = {0,0,0,0,0,0,0};
    int A [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
 
void DFS(int i){
    cout<<i<<" ";
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if(A[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}
 
int main(){ 
    // DFS Implementation  
    
    cout << "Following is Depth First Traversal:"
            " (starting from vertex 0) \n";
    DFS(5); 
    return 0;
}
