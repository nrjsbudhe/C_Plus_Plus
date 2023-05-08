#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int* max_min_grouping(int A[], int m, int n){

    int C[n][m];
    int P[n][m];
    int T[15];
    int sum = 0;
    for(int j = 0; j < m; j++){
      if(j == 0){
       for(int i = 0; i < n; i++){

            sum = sum + A[i];
            C[i][j] = sum ;
    }
    }
    else{
    for(int i = j; i < n; i++){

        for(int k = j-1; k < i; k++){
            int sum_A = 0;
            for (int m = k+1; m <= i ; m++){
                sum_A = sum_A + A[m];

            }
            int min_el = min(C[k][j-1],sum_A);
            T[k] = min_el;
            C[i][j] = *max_element(T,T + i);
            for(int k = 0; k < i; k++){
                if(T[k] == C[i][j]){
                    P[i][j] = k + 1;

                }
            }
            }
        }
     }
    }
    /*for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            cout << P[i][j] << " ";
        }
        cout <<endl;
   }*/
    static int G[100];
     int z = n;
    for(int j = m - 1; j > 0; j--){
        int v = P[z - 1][j];
        G[j] = z - v ;
        z = v;

    }
    int sum_g = 0;
    for(int j = 1; j < m ; j++){
        sum_g = sum_g + G[j];
    }
    G[0] = n - sum_g;

    return G;
}

int main(){
    int A[100];
    int n,m;
    int B[100];
    int D[100]; //temporary array to store cumulative sum of G array
    cout << "Enter the length of array" << endl;
    cin >> n;
    cout << "Enter the input array" << endl;
    for(int i = 0 ;i < n; i++){
      cin >> A[i];
    }
   cout << "Enter the number of partitions m" << endl;
   cin >> m;

   int* ptr = max_min_grouping(A,m,n);
    int sum_x = 0;
   for(int i = 0; i < m; i++){
    sum_x = sum_x + ptr[i];
    D[i] = sum_x;

   }
   int start_el = 0;
   for(int i = 0; i < m; i++){
       int sum_g = 0;
        int end_el = D[i];
    for(int j = start_el; j < end_el; j++){

        sum_g = sum_g + A[j];
        B[i] = sum_g;

    }
    start_el = D[i];

   }
   cout << "----------------------------"<<endl;
   cout << "G Array : ";
   for(int j = 0; j < m; j++){
        cout << ptr[j] << " ";
        }
        cout << endl;

    /*cout << "B Array : ";
   for(int j = 0; j < m; j++){
        cout << B[j] << " ";
        }*/
    return 0;
   }



