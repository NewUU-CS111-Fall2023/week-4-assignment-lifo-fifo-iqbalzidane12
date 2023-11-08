#include <iostream>
#include <bits/stdc++.h>

int calculatePostfix(std::string postfix) {
    std::stack<int> s;
    std::stringstream ss(postfix);
    std::string temp;

    while (ss >> temp) {
        if (isdigit(temp[0])) {
            s.push(stoi(temp));
        } else {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();

            switch (temp[0]) {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
            }
        }
    }

    return s.top();
}

int task_3() {
    std::string postfix;
    std::getline(std::cin, postfix);

    std::cout << calculatePostfix(postfix) << std::endl;

    return 0;
}
