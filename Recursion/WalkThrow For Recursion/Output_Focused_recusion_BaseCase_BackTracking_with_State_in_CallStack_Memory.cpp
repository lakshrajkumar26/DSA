#include <bits/stdc++.h>
using namespace std;

void func(int n, int depth)
{
    // indentation for visualization
    string indent(depth * 4, ' ');

    cout << indent << "Function Entered -> func(" << n << ")" << endl;

    // Base Case
    if (n == 0)
    {
        cout << indent << "Base Case Hit for n = 0" << endl;
        cout << indent << "Returning Back\n" << endl;
        return;
    }

    // BEFORE recursive call
    cout << indent << "[DOWN PHASE]" << endl;
    cout << indent << "Current n stored in memory = " << n << endl;

    cout << indent << "Calling func(" << n - 1 << ")\n" << endl;

    // Recursive call
    func(n - 1, depth + 1);

    // AFTER recursive call
    // THIS IS BACKTRACKING
    cout << indent << "[BACKTRACKING / UP PHASE]" << endl;

    cout << indent << "We came back to func(" << n << ")" << endl;

    cout << indent << "Stored value of n is STILL = " << n << endl;

    cout << indent << "Function Ending -> func(" << n << ")\n" << endl;
}

int main()
{
    func(3, 0);
}