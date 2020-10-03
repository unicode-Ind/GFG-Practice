/*
  Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contigious subarray sum.

Input:
First line of input contains a single integer T which denotes the number of test cases. First line of each test case contains a single integer N which denotes the total number of elements. Second line of each test case contains N space separated integers denoting the elements of the array.

Output:
For each test case print the maximum sum obtained by adding the consecutive elements.

Constraints:
1 <= T <= 101
1 <= N <= 106
-106 <= Arr[i] <= 106

Example:
Input:
3
7
8 -8 9 -9 10 -11 12
8
10 -3 -4 7 6 5 -4 -1
8
-1 40 -14 7 6 5 -4 -1

Output:
22
23
52

Explanation:
Testcase 1: Starting from last element of the array, i.e, 12, and moving in circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.

NOTE : Check for all -ve elements
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159
#define fo(i,k) for(i=0;i<k;i++)
#define fok(i,k,n) for(i=k;i<n;i++)
void read(int *a);
void read(vector<int> &v);

const int size=1000005;
int a[size];
int n;
ll total;

ll kadane(bool parity=false){
    int cur_max=INT_MIN;
    int cur_sum=0;
    
    for(int i=0;i<n;i++){
        if(parity)
            cur_sum+=a[i];
        else
            cur_sum-=a[i];
        
        if(cur_sum>cur_max)
            cur_max=cur_sum;
        
        if(cur_sum<0)
            cur_sum=0;
            
        //cout<<cur_max<<endl;
    } 
    return cur_max;
}
void solve(){
	cin>>n;
	read(a);
	
	ll simple_kadane=kadane(true);
	if(simple_kadane<0){
	    cout<<simple_kadane;
	    return;
	}
	
	ll overlap_kadane=total+kadane(false);
	//cout<<total<<" "<<simple_kadane<<" "<<overlap_kadane<<endl;
	
	cout<<max(simple_kadane,overlap_kadane);

}

int main() {
	int t=1;
	cin>>t;
	while(t--){
	    solve(); cout<<endl;
	    //cout<<solve()<<endl;
	}
	return 0;
}

void read(int *a){
    total=0;
	for(int i=0;i<n;i++){
    	cin>>a[i];
    	total+=a[i];
	}
}
void read(vector<int> &v){
	v.resize(n);
    for(int i=0;i<n;i++)
    	cin>>v[i];    
}
