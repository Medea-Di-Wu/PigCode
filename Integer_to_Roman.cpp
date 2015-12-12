class Solution {
public:
    string intToRoman(int num) {
        vector<int> integer {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int round = 0;
        string result = "";
        while(num != 0) {
            int k = num/integer[round];
            for(int i = 0; i < k; i++) {
                result += roman[round];
                num -= integer[round];
            }
            round++;
        }
        return result;
    }
};