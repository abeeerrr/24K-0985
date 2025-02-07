#include <iostream>
using namespace std;

          int main(){
    int row;
    int col;
    
    cout<<"take the number of rows in Matrix 1 and 2: ";
    cin>>row;
    
    cout<<"take the number of columns in Matrix 1 and 2: ";
    cin>>col;
    
    int **ptr1= new int *[row];
    for (int i=0; i<row; i++){
    
        ptr1[i]= new int [col];
    }
    
    for (int i =0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            cout<<"take the  element for Matrix 1, Row "<<i+1<<" Col "<<j+1<<": ";
            cin>>*(*(ptr1+i)+j);
        }
        
    }
    
    
    int **ptr2= new int *[row];
    for (int i=0; i <row; i++)
    {
        ptr2[i]= new int [col];
    }
    
    for (int i=0; i<row; i++)
    
    {
        for (int j=0; j<col; j++)
        {
            cout<<"take the element for Matrix 2, Row "<<i+1<<" Col "<<j+1<<": ";
            cin>>*(*(ptr2+i)+j);
        }
        
    }
    
    
    int **ptr3= new int *[row];
    for (int i = 0; i < row; i++)
    {
        ptr3[i]= new int [col];
    }
    
    int **ptr4= new int *[row];
    for (int i=0; i < row; i++)
    {
        ptr4[i]= new int [col];
    }
    cout<<"Addition of input matrices"<<endl;
    for (int i = 0; i < row; i++)
    {
        cout<<"|";
        for (int j = 0; j < col; j++)
        {
            ptr3[i][j]=ptr1[i][j]+ptr2[i][j];
            cout<<ptr3[i][j]<<" | ";
        }
        cout<<endl;
    }
    cout<<"Subtraction of input matrices"<<endl;
    for (int i=0; i<row; i++)
    {
        cout<<"|";
        for (int j=0; j<col; j++)
        {
            ptr4[i][j]=ptr1[i][j]-ptr2[i][j];
            cout<<ptr4[i][j]<<" | ";
        }
        cout<<endl;
    }
    for (int i=0; i<row; i++)
    {
        delete[] ptr1[i];
        delete[] ptr2[i];
        delete[] ptr3[i];
        delete[] ptr4[i];
    }
    delete[] ptr1;
    delete[] ptr2;
    delete[] ptr3;
    delete[] ptr4;
    return 0;
}