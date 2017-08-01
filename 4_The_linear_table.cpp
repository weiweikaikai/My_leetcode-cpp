/*************************************************************************
	> File Name: 4_The_linear_table.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Tue 01 Aug 2017 08:27:48 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
 

/*¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
¿¿: Given [100, 4, 200, 1, 3, 2], ªêe longest consecutive elements sequence is [1,
2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.  ¿¿¿¿¿O(N)
*/


class Solution_1{
 public:
	 int FindLongest(int array[],int n){
       if(array == NULL || n < 0){
          return -1; 
       }
     vector<int> vec(256,0);
     for(int i=0;i<n;++i){
       vec[array[i]] = 1;
     }
    int  length1=0;
    int  length2=0;
    int  max=0;
    for(int j=0;j<n;++j){
        if(vec[array[j]] == 1){

            for(int k=array[j];vec[k] == 1 && k <=256;++k){
                length1++;
            }
            for(int l=array[j];vec[l] == 1 && l >= 0;--l){
                length2++; 
            }
            int tmp= length1>length2 ? length1 : length2; 
            length2=length1=0;            
            max= max > tmp ? max : tmp;
        }
     }
    return max; 
 }
  
};
void Print(int A[],int n)
{
    if(A == NULL || n <=0)
    {
        return;
    }

    for(int i=0;i<n;++i)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int array[]={100, 4, 200, 1, 3, 2};
 Solution_1 s1;
 cout<<s1.FindLongest(array,6);
    return 0;
}

           
