class Solution {
public:
    int myAtoi(string s) {
    int ans = 0, size = s.length();
    bool isNegative = false, start = false;
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ' && !start) {
            continue;
        }
        if ((s[i] == '-' || s[i] == '+') && !start) {
            isNegative = (s[i] == '-');
            start = true;
            continue;
        }
        if (!isdigit(s[i]) && start) {
            break;
        }
        if (isdigit(s[i])) {
            start = true;
            int digit = s[i] - '0';
            if (ans > (INT_MAX - digit) / 10) {
                return isNegative ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
        }
        else {
            return 0;
        }
    }
    return isNegative ? -ans : ans;
  }
};