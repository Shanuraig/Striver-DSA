#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        return helper(s, i, 0, 1, false, false);
    }

private:
    int helper(const string &s, int i, long result, int sign, bool started, bool signedFlag) {
        if (i >= s.size()) return result * sign;

        char c = s[i];

        if (!started && c == ' ') {
            return helper(s, i + 1, result, sign, false, false);
        }

        if (!started && !signedFlag && (c == '+' || c == '-')) {
            if (i + 1 >= s.size() || !isdigit(s[i + 1])) return 0;
            sign = (c == '-') ? -1 : 1;
            return helper(s, i + 1, result, sign, false, true);
        }

        if (isdigit(c)) {
            result = result * 10 + (c - '0');

            if (sign == 1 && result >= INT_MAX) return INT_MAX;
            if (sign == -1 && -result <= INT_MIN) return INT_MIN;

            return helper(s, i + 1, result, sign, true, signedFlag);
        }

        // 🚨 Stop at first invalid character after parsing starts
        return result * sign;
    }
};
