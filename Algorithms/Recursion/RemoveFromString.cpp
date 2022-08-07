#include <iostream>
#include <string>
using namespace std;

string Remove(string str, char rem, int st = 0)
{
    if (str[st] == '\0')
        return "";
    if (str[st] == rem)
    {
        return Remove(str, rem, st + 1);
    }
    return str[st] + Remove(str, rem, st + 1);
};
string RemoveBanana(string str)
{
    if (str[0] == '\0')
        return "";
    size_t FIND = str.find("banana");
    if (FIND >= 0 && FIND <= str.size())
    {
        return RemoveBanana(str.substr(6));
    }
    return str[0] + RemoveBanana(str.substr(1));
};

string RemoveBanNotBanana(string str)
{
    if (str[0] == '\0')
        return "";
    size_t FIND = str.find("ban");
    size_t NOTFIND = str.find("banana");
    if (FIND >= 0 && FIND <= str.size() && (NOTFIND < 0 || NOTFIND > str.size()))
    {
        return RemoveBanNotBanana(str.substr(3));
    }
    return str[0] + RemoveBanNotBanana(str.substr(1));
};



int main(int argc, char const *argv[])
{
    string str = "banana";
    string ans = Remove(str, 'a', 0);
    cout << "Remove Call: Removes particular character from a string:    " <<   ans << endl;

    str = {"bananaapppeer"};
    ans = RemoveBanana(str);
    cout << "RemoveBanana Call: Removes particular string from a string: " <<  ans << endl;

    ans = RemoveBanana(Remove(str, 'a', 0));
    cout << "Both called at the same time:                               " <<  ans << endl;

    str = {"fhdnbananabansgnjff"}; 
    ans = RemoveBanNotBanana(str);
    cout << ans << endl;


    return 0;
}
