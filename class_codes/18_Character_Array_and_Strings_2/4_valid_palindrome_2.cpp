#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool validPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start <= end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            // meabns that tha s[s]!=s[e]
            // 1 removal allowed

            // removing the sth index character and chck if palindrome or not
            bool ans1 = isPalindrome(s, start + 1, end);

            // removing the character at the eth index and chck if palindrome or not
            bool ans2 = isPalindrome(s, start, end - 1);
            // chck palindrome or not after removing string

            // returning the bool value as the O/P
            return ans1 || ans2;
        }
    }
    // if no removal then toh truee hee hai
    return true;
}
int main()
{
    // we need to return true if the string can possibly be a palindrome after removing atmost 1 (mean 0 / 1 character changed) character form it !!
    string s = "madcrrcam";
    bool answer = validPalindrome(s);
    if (answer)
    {
        cout << "valid";
    }
    else
    {
        cout << " invalid";
    }
    return 0;
}