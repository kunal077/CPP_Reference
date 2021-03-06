#include <iostream>
using namespace std;
int Union(int arr1[], int arr2[], int m, int n)
{   int i = 0, j = 0;
    while (i < m && j < n)
    {   if (arr1[i] < arr2[j])
            cout << arr1[i++];
        else if (arr2[j] < arr1[i])
            cout << arr2[j++];
        else
        {
            cout << arr2[j++];
            i++;
        } }
    while (i < m)
        cout << arr1[i++];
    while (j < n)
        cout << arr2[j++];
}

int main()
{
    int V1[] = {0, 1};
    int V2[] = {0, 1, 2};
    int m = sizeof(V1) / sizeof(V1[0]);
    int n = sizeof(V2) / sizeof(V2[0]);
    int E1[m][m], E2[n][n], E3[m + n][m + n];
    int i, j, k;
    cout << "Enter the adjacency matrix(symmetric) for graph G1:" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "E1[" << i << "][" << j << "]=";
            cin >> E1[i][j];
        }
    }
    cout << "Enter the adjacency matrix(symmetric) for graph G2:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "E2[" << i << "][" << j << "]=";
            cin >> E2[i][j];
        }
    }
    cout << "\nVERTICES SET IN UNION RESULTANT GRAPH is:\n";
    Union(V1, V2, m, n);
    cout << "\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (E1[i][j] > E2[i][j] && i < m && j < m)
                E3[i][j] = E1[i][j];
            else if (E1[i][j] < E2[i][j] && i < m && j < m)
                E3[i][j] = E2[i][j];
            else
                E3[i][j] = E2[i][j];
        }
    }
    cout << "CORRESPONDING ADJACENCY MATRIX OF RESULTANT is:\n";
    for (i = 0; i < n; i++)
    {
        cout << "\t" << i;
    }
    cout << "\n\t";
    for (i = 0; i < n; i++)
    {
        cout << " ";
    }
    for (i = 0; i < n; i++)
    {
        cout << "\n"
             << i << "|\t";
        for (j = 0; j < n; j++)
        {
            cout << E3[i][j] << "\t";
        }
    }
    cout << "\n";
    return 0;
}