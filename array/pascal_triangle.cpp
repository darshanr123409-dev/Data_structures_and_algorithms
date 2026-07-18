#include<bits/stdc++.h>
using namespace std;

vector<int> Generate_row(int row){

    long long ans=1;
    vector<int> ans_row;
    ans_row.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/(col);
        ans_row.push_back(ans);
    }
    return ans_row;
}

vector<vector<int>> pascal_triangle(int n){
    vector<vector<int>> ans;

    for(int i=1 ;i<=n ;i++){
        ans.push_back(Generate_row(i));
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the Number : ";
    cin >> n;

    vector<vector<int>> triangle = pascal_triangle(n);

    cout<<"Pascal Traingle are \n";
    for(auto row : triangle)
    {
        for(auto x : row)
            cout << x << " ";

        cout << endl;
    }
    return 0;
}