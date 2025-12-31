#include <bits/stdc++.h>
using namespace std;
//5845：[CSP-J 2022] 逻辑表达式（expr）

struct Result {
    int val;
    long long sc_and;
    long long sc_or;
};

stack<Result> val;
stack<char> op;

int precedence(char op) {
    if (op == '&') return 2;
    if (op == '|') return 1;
    return 0;
}

Result calc(Result a, Result b, char op) {
    Result res = {0, a.sc_and + b.sc_and, a.sc_or + b.sc_or};
    if(op == '&'){
        if(a.val == 0){
            res.val = 0;
            res.sc_or = res.sc_or - b.sc_or;
            res.sc_and = res.sc_and - b.sc_and;
            res.sc_and++;
        }else{
            res.val = a.val & b.val;
        }
    }
    else if(op == '|'){
        if(a.val == 1){
            res.val = 1;
            res.sc_or = res.sc_or - b.sc_or;
            res.sc_and = res.sc_and - b.sc_and;
            res.sc_or++;
        }
        else{
            res.val = a.val | b.val;
        }
    }
    // printf("a.val=%d, b.val=%d, op=%c, res.val=%d, res.sc_and=%lld, res.sc_or=%lld\n", a.val, b.val, op, res.val, res.sc_and, res.sc_or);
    return res;
}

Result eval(string s){
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c == '0' || c == '1'){
            Result result = {c - '0', 0, 0};
            val.push(result);
        }
        else if(c == '('){
            op.push(c);
        }
        else if(c == ')'){
            while(!op.empty() && op.top() != '('){
                Result b = val.top(); val.pop();
                Result a = val.top(); val.pop();
                char o = op.top(); op.pop();
                val.push(calc(a, b, o));
            }
            op.pop(); // 弹出 '('
        }
        else if(c == '&' || c == '|'){
            while(!op.empty() && precedence(op.top()) >= precedence(c)){
                Result b = val.top(); val.pop();
                Result a = val.top(); val.pop();
                char o = op.top(); op.pop();
                val.push(calc(a, b, o));
            }
            op.push(c);
        }
    }
    // cout<< "op size="<<op.size()<<endl;
    // cout<< "val size="<<val.size()<<endl;

    while(!op.empty()){
        Result b = val.top(); val.pop();
        Result a = val.top(); val.pop();
        char o = op.top(); op.pop();
        // printf("a.val=%d, b.val=%d, op=%c\n", a.val, b.val, o);
        val.push(calc(a, b, o));
    }
    // cout<< "val value="<<val.top().val<<endl;
    return val.top();   
}
 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("expr.in", "r", stdin);
    // freopen("expr.out", "w", stdout);

    string s;
    cin >> s;
    // cout<<"s="<<s<<endl;
    Result ans = eval(s);
    cout << ans.val << "\n" << ans.sc_and << " " << ans.sc_or << "\n";
    return 0;
}

/**
 5845. [CSP-J 2022] 逻辑表达式（expr）
 g++-14 -o main.out main_ex.cpp && ./main.out
 * 
 */