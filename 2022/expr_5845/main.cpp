#include <bits/stdc++.h>
using namespace std;

struct Result {
    int val;
    long long sc_and;
    long long sc_or;
};

// 运算符优先级
int precedence(char op) {
    if (op == '&') return 2;
    if (op == '|') return 1;
    return 0;
}

// 计算一次 a op b，并统计短路
Result calc(Result a, Result b, char op) {
    Result res = {0, a.sc_and + b.sc_and, a.sc_or + b.sc_or};
    if (op == '&') {
        if (a.val == 0) { // 短路
            res.val = 0;
            // cout<<"short_and: a="<<a.val<<" b="<<b.val<<endl;
            res.sc_and++;
            // 清除左边的结果, 因为被短路了
            res.sc_or = res.sc_or - b.sc_or;
            res.sc_and = res.sc_and - b.sc_and;
        } else {
            res.val = a.val & b.val;
        }
    } else if (op == '|') {
        if (a.val == 1) { // 短路
            res.val = 1;
            // cout<<"short_or: a="<<a.val<<" b="<<b.val<<endl;
            res.sc_or++;

            // 清除左边的结果, 因为被短路了
            res.sc_or = res.sc_or - b.sc_or;
            res.sc_and = res.sc_and - b.sc_and;
        } else {
            res.val = a.val | b.val;
        }
    }
    return res;
}

Result eval(const string &s) {
    stack<Result> val;
    stack<char> op;

    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        // cout<<"i="<<i<<" c="<<c<<endl;

        if (c == '0' || c == '1') {
            val.push({c - '0', 0, 0});
        }
        else if (c == '(') {
            op.push(c);
        }
        else if (c == ')') {
            while (!op.empty() && op.top() != '(') {
                auto b = val.top(); val.pop();
                auto a = val.top(); val.pop();
                char o = op.top(); op.pop();
                val.push(calc(a, b, o));
            }
            op.pop(); // 弹出 '('
        }
        else if (c == '&' || c == '|') {
            while (!op.empty() && precedence(op.top()) >= precedence(c)) {
                char o = op.top(); op.pop();
                auto b = val.top(); val.pop();
                auto a = val.top(); val.pop();
                val.push(calc(a, b, o));
            }
            op.push(c);
        }
    }

    while (!op.empty()) {
        char o = op.top(); op.pop();
        auto b = val.top(); val.pop();
        auto a = val.top(); val.pop();
        val.push(calc(a, b, o));
    }

    return val.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("expr.in", "r", stdin);
    // freopen("expr.out", "w", stdout);

    string s;
    cin >> s;

    Result ans = eval(s);
    cout << ans.val << "\n" << ans.sc_and << " " << ans.sc_or << "\n";
    return 0;
}

/**
 5845. [CSP-J 2022] 逻辑表达式（expr）
 g++-14 -o main.out main.cpp && ./main.out
 * 
 */