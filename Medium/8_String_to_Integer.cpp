// Implement atoi which converts a string to an integer.

// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
//Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
// If the first sequence of non-whitespace characters in str is not a valid integral number, 
//or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
// If no valid conversion could be performed, a zero value is returned.

// Note:

// Only the space character ' ' is considered as whitespace character.
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. 
//If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

// Example 1:

// Input: "42"
// Output: 42
// Example 2:

// Input: "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', which is the minus sign.
//              Then take as many numerical digits as possible, which gets 42.
// Example 3:

// Input: "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
// Example 4:

// Input: "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which is not a numerical 
//              digit or a +/- sign. Therefore no valid conversion could be performed.
// Example 5:

// Input: "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
//              Thefore INT_MIN (−231) is returned.
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//几个没想到的方面：1.第一个符号位置为‘+’ 2.开头为0的情况 3.超过最大最小整数时的分支判断考虑不全

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.size() == 1 && str[0]<'0' || str[0]>'9')
			return 0;
		string::size_type pos = str.find_first_not_of(' ');
		if (pos == str.npos)
			return 0;
		bool isNegative = false;
		if (str[pos] == '-')
			isNegative = true;
		else if (str[pos] != '+' && str[pos]<'0' || str[pos]>'9')
			return 0;
		string numbers;
		getNumber(str, pos, numbers);
		pos = numbers.find_first_not_of('0', 1);
		if (pos == str.npos)
			return 0;
		string res = numbers[0] + numbers.substr(pos);
		if (res.size() <= 1)
			return 0;
		if (res.size() - 1 > 10)
			return isNegative ? INT32_MIN : INT32_MAX;
		if (res.size()-1==10 && res.substr(1) >= "2147483647")
			return !isNegative ? INT32_MAX : (res.substr(1) == "2147483647" ? INT32_MIN + 1 : INT32_MIN);
		return stoi(res);
	}
private:
	void getNumber(string& str, int pos, string& out) {
		if (str[pos] != '-'&&str[pos] != '+')
			out.push_back('+');
		out.push_back(str[pos]);
		string ctable = "0123456789";
		for (int i = pos + 1; i < str.size(); i++) {
			string::size_type position;
			position = ctable.find(str[i]);
			if (position != ctable.npos)
				out.push_back(ctable[position]);
			else
				return;
		}
	}
};


int main() {
	Solution solu;
	cout << solu.myAtoi("42") << endl;
	system("pause");
}
