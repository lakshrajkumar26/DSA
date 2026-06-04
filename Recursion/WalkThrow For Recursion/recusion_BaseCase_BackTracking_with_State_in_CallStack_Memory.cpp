#include <bits/stdc++.h>

using namespace std;




void func(int n) {

    if (n == 0)
        return;

    cout << "DOWN " << n << endl;

    func(n - 1);
    
    //this happens while Backtracking 

    cout << "UP " << n << endl;

}


int main() {
    // your code goes here
    func(3);

}