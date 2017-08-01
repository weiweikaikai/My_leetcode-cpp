/*************************************************************************
	> File Name: 2_The_linear_table.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sun 30 Jul 2017 07:16:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


/*
假设一个排序数组在预先未知的某个旋转轴上旋转
（即，0，1，2，4，5，6，7可能变成4，5，6，7，0，1，2）。
给你一个搜索的目标值。如果在数组中找到，返回它的索引，否则返回- 1。
您可以假设数组中没有重复的数字
*/


class Solution_1{

  public:
      int Search(int array[],int n,int target){// 时间复杂度 O(log n)，空间复杂度 O(1)
         int left=0;
		 int right=n;

		 while(left != right){
		    int mid = left  + ((right - left) >> 1);
			if(array[mid] == target){
			    return mid;
			}
			if(array[left] <= array[mid]){ //array[mid]在左边的升序里面
			      if(array[left] <= target && target < array[mid]){
				     right = mid;        
				  }
				  else{ //总的来说左边的一般都偏小，如果左边的都比target大了，就会在右边
				     left = mid+1;
				  }
			}
			else{//array[left] >array[mid]//array[mid]在右边的升序里面
			     if(array[mid] < target && target <= array[right-1]){
				     left = mid+1;
				 }
				 else{//总的来说左边的一般都偏小，如果右边的都比target小了，就会在左边
				    right = mid;
				 }
			}
		 }
		 return -1;
     }
};


class Solution_2{

  public:
      int Search(int array[],int n,int target){// 时间复杂度 O(n)，空间复杂度 O(1)
         int left=0;
		 int right=n;

		 while(left != right){
		    int mid = left  + ((right - left) >> 1);
			 if(array[mid] == array[left] && array[right-1] ==array[mid] ){
			   cout<<"请采用正常的顺序遍历查找"<<endl;
			   return -1;
			 } 
			if(array[mid] == target){
			    return mid;
			}
			if(array[left] < array[mid]){ //array[mid]在左边的升序里面
			      if(array[left] <= target && target < array[mid]){
				     right = mid;        
				  }
				  else{ //总的来说左边的一般都偏小，如果左边的都比target大了，就会在右边
				     left = mid+1;
				  }
			}
			else if(array[left] >array[mid]){//array[left] >array[mid]//array[mid]在右边的升序里面
			     if(array[mid] < target && target <= array[right-1]){
				     left = mid+1;
				 }
				 else{//总的来说左边的一般都偏小，如果右边的都比target小了，就会在左边
				    right = mid;
				 }
			}
			else{ //array[left] ==array[mid] 因为允许重复了
			  left++;
			}
		 }
		 return -1;
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
    int array[]={4,5,6,7,0,1,2};
	int array2[]={1,3,1,1};
	int special[]={1,1,1,1,0,0,1};
     //  Solution_1 soulution_1; 
	//   cout<<soulution_1.Search(array,7,0)<<endl;
	  Solution_2 soulution_2; 
	  cout<<soulution_2.Search(array,4,1)<<endl;
	Solution_2 soulution_3; 
	cout<<soulution_3.Search(special,7,1)<<endl;
    return 0;
}

           