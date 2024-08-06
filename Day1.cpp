#include<iostream>
using namespace std;

int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;
    int arr[n][m];
    /*for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = 0;
        }
    }
    int no,px,py,e;
    cout<<"Enter no of non 0 element : "<<endl;
    cin>>no;
    for(int i = 0; i < no; i++){
        cout<<"Enter position"<<endl;
        cin>>px;
        cin>>py;
        cout<<"Enter element";\
        cin>>e;
        arr[px][py] = e;
    }
    
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
