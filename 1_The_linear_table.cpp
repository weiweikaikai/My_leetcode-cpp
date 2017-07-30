/*************************************************************************
	> File Name: 1_The_linear_table.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Fri 27 May 2016 09:12:39 AM CST
 ************************************************************************/

//编程技巧
//1.判断两个浮点数a 和b 是否相等,不要用a==b 应该判断二者只差的绝对值是否小于某个阀值  例如 le-9
//2.判断一个整数是否为奇数 用 x%2 !=0   不要用 x%2 !=1因为x可能是负数
//3.用char的值作为数组的下标 要考虑char可能是负数,应该强转为unsigned char 再用作下标 这涉及到c++整形的提升规则
//4.vector 和string 优于动态分配的数组,避免new delete 的不对称   使用reserve 来避免不必要的内存重新分配

#include<iostream>
#include<vector>
using namespace std;
 
/*
1.删除重复的排序数组(假设是升序)
描述:
给定一个数组排序,删除重复的地方,这样每个元素只出现一次
并返回新的长度。
不能用另一个数组分配额外的空间,必须在原来的空间上边进行
例如,给定的输入数组=[1,2],
你的函数应该返回长度= 2,现在[1,2]。
*/
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
//从当前数值开始往后便利，找到和自己不同的数值就放在自己后面,最后 返回自己的下标+1就是数组大小
class Solution_1
{
	public:
		//Time complexity: O(n)  
	    //Space complexity: O(1)
		int removeDuplicates(int A[],int n)
	    {
	         if(A == NULL || n <=0)
			  {
			       return 0;
			  }

			  int cur=0;
			  for(int i=1;i<n;++i)
			  {
			   if(A[cur] != A[i])
				  {
			        A[++cur] = A[i];
				  }
			  }
			  return cur+1;
	    }
		
};

#include<algorithm>
class Solution_2
{
	//使用STL算法  用unique实现对排序数组中去重相邻的数据 distance 计算数组长度 
 public:
	 	//Time complexity: O(n)  
	    //Space complexity: O(1)
       int removeDuplicates(int A[],int n)
	    {
	         if(A == NULL || n <=0)
			  {
			       return 0;
			  }
			  //return distance(A,unique(A,A+n));
			  return (unique(A,A+n)-A);
		}

};

class Solution_3
{
	//lower_bound(begin,end,key)函数返回第一个小于关键字的位置
	//upper_bound(begin,end,key)函数返回第一个大于关键字的位置
	public:
       //Time complexity: O(n)  
	  //Space complexity: O(1)
	int removeDuplicates(int A[],int n)
	 {
	 return removeDuplicates(A,A+n,A)-A;
	 }
	 template<typename in,typename out>
	  out removeDuplicates(in first,in last,out output)
	  {
		 while(first != last)
		  {
	       *output++ = *first;
		    first = upper_bound(first,last,*first); //找到下一个比*first大的数字的位置返回迭代器
		  }
		  return output;
	 }
};

//参数中n为数组中元素个数 count为用户需要保留的重复数组个数 count=2就表示数组中所有重复的数的个数最大就是2

class Solution_4{

    public:
        int removeDuplicates(int array[],int n,int count)
        {
           if(array == NULL || count > n)
           {
             return -1;
           }
           vector<int> vec(10,0);

           for(int i=0;i<n;++i)
           {
             vec[array[i]]++;          
           }
           int index=0;
           for(int i=0;i<10&&index<n;++i)
           {
               if(vec[i] !=0)
               {
                  for(int j=0;j<(vec[i]>= count ? count : vec[i]);++j)
                  {
                      array[index++]=i;
                  }
               }
           }
           return index;
        }
};
class Solution_5{

  public:
      int removeDuplicates(int a[],int n,int count)
      {
        if(a == NULL || n<=count)
        {
          return -1;
        }
        int index=count;
        for(int i=count;i<n;++i)
        {
           if(a[i] != a[index-count])
           {
              a[index++] = a[i];
           }
        }
        return index;
      }
};

int main()
{

    int array[]={1,1,1,3,3,3,4,5,6,7,8,9};

//       Solution_1 soulution_1; 
//	   Print(array,soulution_1.removeDuplicates(array,12));
//	      Solution_2 soulution_2; 
//	   Print(array,soulution_2.removeDuplicates(array,12));
//	      Solution_3 soulution_3; 
//	   Print(array,soulution_3.removeDuplicates(array,12));
//	      Solution_4 soulution_4; 
//	   Print(array,soulution_4.removeDuplicates(array,12,2));
	      Solution_5 soulution_5; 
	   Print(array,soulution_5.removeDuplicates(array,12,3));

    return 0;
}

