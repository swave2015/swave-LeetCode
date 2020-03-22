#include <string>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' or s[i] == '[' or s[i] == '{') {
                stack.push(s[i]);
            } else {
                if(stack.size() == 0) {
                    return false;
                }

                char c = stack.top();
                stack.pop();
                char match;
                if(s[i] == ')') {
                    match = '(';
                } else if(s[i] == ']') {
                    match = '[';
                } else {
                    assert(s[i] == '}');
                    match = '{';
                }
                if(match != c) {
                    return false;
                }
            }
        }
        if(stack.size() != 0) {
            return false;
        } else {
            return true;
        }
    }
};