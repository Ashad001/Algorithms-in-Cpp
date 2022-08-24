#include <iostream>
#include <vector>
#include <string>
using namespace std;

string RemoveDigit(string str, char digit)
{
    auto split = str.find(digit);
    str.erase(str.begin() + split);
    return str ;
}

int main(int argc, char const *argv[]) 
{
    cout << RemoveDigit("133235",'3');


    
    return 0;
}
