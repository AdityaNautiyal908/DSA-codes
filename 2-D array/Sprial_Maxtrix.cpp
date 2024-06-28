#include <iostream>
#include <vector>
using namespace std;

vector<int> spiral_Order(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size(); // This returns 3 because there are 3 rows in the matrix
        int col = matrix[0].size(); // This returns 3 because there are 3 columns in the first row

        int count = 0;
        int total = row*col;
        int starting_Row = 0;
        int starting_Col = 0;
        int ending_Row = row-1;
        int ending_Col = col-1;


        while(count < total){   
            // printing starting row;
            for ( int index = starting_Col; count < total && index <= ending_Col; index++){
                ans.push_back(matrix[starting_Row][index]);
                count++;
            }
            starting_Row++;

            // printing ending col;
            for( int index = starting_Row; count < total && index <= ending_Row; index++){
                ans.push_back(matrix[index][ending_Col]);
                count++;
            }
            ending_Col--;
            
            // printing ending row;
            for( int index = ending_Col; count < total && index>=starting_Col; index--){
                ans.push_back(matrix[ending_Row][index]);
                count++;
            }
            ending_Row--;

            // printing starting col;
            for ( int index = ending_Row; count < total && index >= starting_Row; index-- ){
                ans.push_back(matrix[index][starting_Col]);
                count++;
            }
            starting_Col++;
        }
        return ans;
    }

int main(){
    vector<vector<int>> arr(3, vector<int>(3)); 
    cout << " Enter the element : " << endl;
    for ( int i=0; i<3; i++){
        for ( int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    cout << " Printing elements in normal form " << endl;
    for ( int i=0; i<3; i++){
        for ( int j=0; j<3; j++){
            cout << arr[i][j] << " ";
        }
    }cout << endl;

    // printing element in spiral form
    vector<int> spiral = spiral_Order(arr);

    cout << " Printing elements in spiral form " << endl;
    for (auto val : spiral) {
        cout << val << " ";
    }
    cout << endl;
return 0;
}