#include <bits/stdc++.h> 
using namespace std;
 
int index;  
int 	max_length_subarray(int arr[],  
                    int N, 
                    int n) 
{

  
    map<int, int> um; 
    int sum = 0, maxlen = 0,z; 
  
  
    for (int i = 0; i < N; i++) {  
        sum += arr[i]; 
    
  
        if (sum == n) 
            maxlen = i + 1;
            z=1;
        if (um.find(sum) == um.end()) 
            um[sum] = i;
			 
   
        if (um.find(sum - n) != um.end()) { 
   
            if (maxlen < (i - um[sum - n])) 
                maxlen = i - um[sum - n]; 
                z=2;
        } 
    } 
      if(z==1){
        index = 1;
    }
    if(z==2){
        index =um[sum - n]+1;
    }

    if(maxlen==0)
    cout<<"not found";
  else
  {
    cout<<"length of longest subarray is "<<maxlen<<endl;
     cout<<"index from "<<index<<" to "<<index +maxlen-1<<endl;
 }
 return 0;
    
} 

int main() 
{ 	int n,N,w;
	cout<<"enter the value of sum";
	cin>>n;
	cout<<"enter the length of th string";
	cin>>N;
	int arr[N];
	for(int w=0;w<N;w++)
	{
		cin>>arr[w];
	}
		max_length_subarray(arr,N,n); 

  
	return 0;
}
