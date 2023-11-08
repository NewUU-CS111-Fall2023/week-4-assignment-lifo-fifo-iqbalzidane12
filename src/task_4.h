#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int task_4 () {
    int N;
    cin >> N;
    vector<stack<int>> stacks(N);
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int type;
            cin >> type;
            stacks[i].push(type);
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        while (!stacks[i].empty() && stacks[i].top() == i + 1) {
            stacks[i].pop();
        }
        if (stacks[i].empty()) {
            continue;
        }
        int j = 0;
        for (; j < N; j++) {
            if (!stacks[j].empty() && stacks[j].top() == i + 1) {
                break;
            }
        }
        if (j == N) {
            cout << 0 << endl;
            return 0;
        }
        while (!stacks[j].empty() && stacks[j].top() == i + 1) {
            cout << j + 1 << " " << i + 1 << endl;
            stacks[i].push(stacks[j].top());
            stacks[j].pop();
        }
        i++;
    }

    return 0;
}
