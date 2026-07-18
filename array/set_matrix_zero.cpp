#include <bits/stdc++.h>
using namespace std;

// void set_matrix_zero(vector<vector<int>> &arr)
// {
//     int n = arr.size();
//     int m = arr[0].size();
//     // Mark rows and columns
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (arr[i][j] == 0)
//             {
//                 // Mark entire row
//                 for (int col = 0; col < m; col++)
//                 {
//                     if (arr[i][col] != 0)
//                         arr[i][col] = -1;
//                 }
//                 // Mark entire column
//                 for (int row = 0; row < n; row++)
//                 {
//                     if (arr[row][j] != 0)
//                         arr[row][j] = -1;
//                 }
//             }
//         }
//     }
//     // Convert all -1 into 0
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (arr[i][j] == -1)
//                 arr[i][j] = 0;
//         }
//     }
// }

// void set_matrix_zero(vector<vector<int>> &arr)
// {
//     int n = arr.size();
//     int m = arr[0].size();

//     int row[n]={0};
//     int cul[m]={0};

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j]==0){
//                 row[i]=1;
//                 cul[j]=1;
//             }
//         }
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(row[i] || cul[j]){
//                 arr[i][j]=0;
//             }
//         }
//     }
// }

void set_matrix_zero(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

}

int main()
{
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    set_matrix_zero(arr);

    cout << "\nMatrix after setting zeros:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}