#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> left, right;
    string str;
    int num_command;

    cin >> str;

    for (int i = 0; i < str.size(); ++i) {
        left.push(str[i]);
    }

    cin >> num_command;

    for (int i = 0; i < num_command; ++i) {
        char command;
        cin >> command;

        if (command == 'L') {
            if (!left.empty()) {
                command = left.top();
                right.push(command);
                left.pop();
            }
        } else if (command == 'D') {
            if (!right.empty()) {
                command = right.top();
                left.push(command);
                right.pop();
            }
        } else if (command == 'B') {
            if(!left.empty()){
                left.pop();
            }
        } else if (command == 'P') {
            cin >> command;
            left.push(command);
        }
    }

    while(!left.empty()){
        char c = left.top();
        right.push(c);
        left.pop();
    }

    while(!right.empty()){
        char c = right.top();
        cout << c;
        right.pop();
    }
    return 0;
}