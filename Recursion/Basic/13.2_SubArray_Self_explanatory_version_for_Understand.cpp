
#include <iostream>
#include <vector>
using namespace std;

void printSpaces(int level){
    for(int i=0;i<level;i++){
        cout << "   ";
    }
}

void printVector(vector<int>& ans){

    cout << "[";

    for(int i=0;i<ans.size();i++){

        cout << ans[i];

        if(i != ans.size()-1)
            cout << ",";
    }

    cout << "]";
}

void printSub(int arr[],
              vector<int>& ans,
              int n,
              int index,
              int level){

    // CURRENT FUNCTION STATE
    printSpaces(level);

    cout << "FUNCTION CALL -> ";
    cout << "index = " << index << " ";
    cout << "ans = ";

    printVector(ans);

    cout << endl;

    // BASE CASE
    if(index == n){

        printSpaces(level);

        cout << "BASE CASE HIT -> PRINT : ";

        printVector(ans);

        cout << endl;

        printSpaces(level);

        cout << "RETURNING BACK...\n";

        return;
    }

    // CHOOSE
    printSpaces(level);

    cout << "CHOOSE arr[" << index << "] = "
         << arr[index] << endl;

    ans.push_back(arr[index]);

    printSpaces(level);

    cout << "ans AFTER PUSH = ";

    printVector(ans);

    cout << endl;

    // LEFT BRANCH
    printSpaces(level);

    cout << "GO LEFT -> INCLUDE "
         << arr[index] << endl;

    printSub(arr, ans, n, index+1, level+1);

    // BACKTRACK
    printSpaces(level);

    cout << "BACKTRACK STARTS..." << endl;

    printSpaces(level);

    cout << "POP : " << ans.back() << endl;

    ans.pop_back();

    printSpaces(level);

    cout << "ans AFTER POP = ";

    printVector(ans);

    cout << endl;

    // RIGHT BRANCH
    printSpaces(level);

    cout << "GO RIGHT -> EXCLUDE "
         << arr[index] << endl;

    printSub(arr, ans, n, index+1, level+1);

    // FUNCTION END
    printSpaces(level);

    cout << "FUNCTION END -> index = "
         << index << endl;
}

int main(){

    int arr[] = {1,2,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> ans;

    printSub(arr, ans, n, 0, 0);

    return 0;
}

