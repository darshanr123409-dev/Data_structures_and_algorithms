#include<bits/stdc++.h>
using namespace std;

void spiral_matrix(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();

    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    vector<int> ans;

    while(left <= right && top <= bottom){

        for(int i = left; i <= right; i++)
            ans.push_back(arr[top][i]);
        top++;

        for(int i = top; i <= bottom; i++)
            ans.push_back(arr[i][right]);
        right--;

        if(top <= bottom){
            for(int i = right; i >= left; i--)
                ans.push_back(arr[bottom][i]);
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--)
                ans.push_back(arr[i][left]);
            left++;
        }
    }

    cout << "Spiral Matrix: ";
    for(int x : ans)
        cout << x << " ";
cout<<endl;
}
int main(){
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
     spiral_matrix(arr);
     return 0;   
}