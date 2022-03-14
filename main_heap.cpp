
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<algorithm>
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

class Node
{
    public:
    int val;
    Node* next;
    
    Node(int val){
        this->val=val;
        next = nullptr;
    }
};
Node* getNode(int val){ return new Node(val);}

Node* head = nullptr;
Node* runner = nullptr;

void listit(int number)
{
    Node* tmp = getNode(number);
    if(head==NULL)
        head=tmp;
    else{
        head->next=tmp;
        head=tmp;
    }
}

void callRunner()
{
    SimRoiStart();
    while(runner!=NULL){
        runner->val=runner->val%1000;
        runner=runner->next;
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