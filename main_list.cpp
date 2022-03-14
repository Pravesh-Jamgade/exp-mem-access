#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<list>
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

list<int> allElements;

void listit(int number)
{
    allElements.push_back(number);
}

void callRunner()
{
    list<int>::iterator it=allElements.begin();
    SimRoiStart();
    for(;it!=list.end();it++)
    {
        *it=*it % 1000;
    }
    SimRoiEnd();
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("output.md", "r", stdin);
	#endif
    stringstream ss;

    while(1)
    {
        string line;
        getline(cin,line);

        ss << line;
        ltrim(line); rtrim(line);
        
        int number;
        char spec;
        while(ss>>number){
            ss>>spec;
            listit(number);
        }
        break;
    }

    this_thread::sleep_for(chrono::milliseconds(1000));

    callRunner();
    return 0;
}
