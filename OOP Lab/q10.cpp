#include <iostream>
  using namespace std;

     int main() {
     	
    int x;
    int y;
    int z;

    cout << "value of x: ";
    cin >> x;
    
    cout << "value of y: ";
    cin >> y;
    
    cout << "value of z: ";
    cin >> z;
    

        int ***arr=new int**[x];
        
        
    for (int i=0; i<y; i++) {
    	
        arr[i] = new int*[y];
        
        for (int j=0; j<z; j++) {
        	
            arr[i][j] = new int[z];
            
        }
        
    }
    
    cout << "take the elements: " << endl;
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
        	
            for (int k=0; k<z; k++) {
            	
                cout << "element[" << i+1 << "][" << j+1 << "][" << k+1 << "] = ";
                cin >> arr[i][j][k];
            }
        }
    }
    
    cout << "3D array:" << endl;
    
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            for (int k=0; k<z; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    

    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}