#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define ar array
typedef long long ll;

int main(){

    string filePath="/mnt/B/sniper/test/rarray/output.md";

    fstream fout;
    fout.open(filePath,ios::out);

    for(ll i=0;i<1e6;i++){
    	for(int i=0;i<20;i++){
    		ll tmp = rand();
    		fout<<tmp<<",";
    	}
    	fout<<"\n";
    }

	return 0;
}