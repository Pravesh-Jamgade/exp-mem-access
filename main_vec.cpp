#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include <chrono>
#include <thread>
#include "sim_api.h"
using namespace std;

void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}
void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

vector<int> all;

void vectorize(int number)
{
    all.push_back(number);
}

void callRunner()
{
    SimRoiStart();
    for(int i=0;i<all.size();i++)
    {
        all[i]=all[i]%1000;
    }
    SimRoiEnd();
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("output.md", "r", stdin);
	#endif
    stringstream ss;

    string line;
    while(getline(cin,line))
    {
        ss << line;
        ltrim(line); rtrim(line);
        int number;
        char spec;
        while(ss>>number){
            ss>>spec;
            vectorize(number);
        }
    }
    this_thread::sleep_for(chrono::milliseconds(1000));
    callRunner();
    return 0;
}