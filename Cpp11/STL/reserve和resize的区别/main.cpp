#include <bits/stdc++.h>
using namespace std;

void output(const vector<int> &vec) {
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
}

int main() {
    vector <int> vec;

    output(vec);
    
    vec.push_back(1);

    output(vec);
    
    vec.push_back(1);

    output(vec);

    vec.push_back(1);

    output(vec);

    vec.reserve(100);

    output(vec);

    vec.resize(100);

    output(vec);

    return 0;
}