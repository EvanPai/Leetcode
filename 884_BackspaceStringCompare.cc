#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // use stack
        stack<char> result_s;

        for(char c : s){
            if(c != '#'){
                result_s.push(c);
            }
            else if(!result_s.empty()){
                result_s.pop();
            }
        }

        stack<char> result_t;

        for(char c : t){
            if(c != '#'){
                result_t.push(c);
            }
            else if(!result_t.empty()){
                result_t.pop();
            }
        }

        // stack to string
        string answer_s;
        while(!result_s.empty()){
            answer_s = result_s.top() + answer_s;
            result_s.pop();
        }

        string answer_t;
        while(!result_t.empty()){
            answer_t = result_t.top() + answer_t;
            result_t.pop();
        }

        return answer_s == answer_t;
    }
};

int main(){
    Solution a;

    string s = "hel#lo";
    string t = "world######";
    cout << a.backspaceCompare(s, t) << endl;

    

    return 0;
}