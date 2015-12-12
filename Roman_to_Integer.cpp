class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;
        int ans = 0;
        for(int i = 0; i < s.size()-1; i++) {
            if(m[s[i]] < m[s[i+1]]) ans -= m[s[i]];
            else ans += m[s[i]];
        }
        ans += m[s[s.size()-1]];
        return ans;
    }
};