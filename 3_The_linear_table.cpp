/*************************************************************************
	> File Name: 2_The_linear_table.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sun 30 Jul 2017 07:16:10 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


/*
给定两个已经排序好的数组 array[m]  array[n]，找到两者所有元
素中第 k 大的元素。 时间复杂度要求log(m+n) (这里默认是升序)
*/

//时间复杂度 最好 是O(k) 当k >> m+n  的时候为O(m+n)
class Solution_1{

    public:
        int FindKMaxNum(int v1[],int v2[],int m,int n,int k){
            if( (v1==NULL && v2==NULL) || (m+n) < k){ 
                return -1;      
            }
            int key = 0;
            int cur1 = m-1;
            int cur2 = n-1;
            int max=0;
            while((cur1 >= 0) && (cur2 >= 0)){
                if(v1[cur1] > v2[cur2]){ 
                    max=v1[cur1--];
                }
                else{
                    max=v2[cur2--];
                }
                key++; 
                if(key == k){
                    return max;
                }
            }
            if(cur1 < 0){
             return v2[cur2-(k-key-1)]; 
            }else{
             return v1[cur1-(k-key-1)]; 
            }
          return -1;
      }
};
/*
有没有更好的方案呢？我们可以考虑从k 入手。如果我们每次都能够删除一个一定在第k 大元
素之前的元素，那么我们需要进行k 次。但是如果每次我们都删除一半呢？由于A 和B 都是有序
的，我们应该充分利用这里面的信息，类似于二分查找，也是充分利用了“有序”。
假设A 和B 的元素个数都大于k/2，我们将A 的第k/2 个元素（即A[k/2-1]）和B 的第k/2
个元素（即B[k/2-1]）进行比较，有以下三种情况（为了简化这里先假设k 为偶数，所得到的结
论对于k 是奇数也是成立的）：
• A[k/2-1] == B[k/2-1]
• A[k/2-1] > B[k/2-1]
• A[k/2-1] < B[k/2-1]
如果A[k/2-1] < B[k/2-1]，意味着A[0] 到A[k/2-1 的肯定在A [ B 的top k 元素的范围
内，换句话说，A[k/2-1 不可能大于A [ B 的第k 大元素。留给读者证明。
因此，我们可以放心的删除A 数组的这k/2 个元素。同理，当A[k/2-1] > B[k/2-1] 时，可
以删除B 数组的k/2 个元素。
当A[k/2-1] == B[k/2-1] 时，说明找到了第k 大的元素，直接返回A[k/2-1] 或B[k/2-1]
即可。
因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？
• 当A 或B 是空时，直接返回B[k-1] 或A[k-1]；
• 当k=1 是，返回min(A[0], B[0])；
• 当A[k/2-1] == B[k/2-1] 时，返回A[k/2-1] 或B[k/2-1]

*/

class Solution_2{

  
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
    int array[]={4,5,6,7,8,9};
    int array2[]={1,3,10,11};
    Solution_1 soulution_1;
    cout<< soulution_1.FindKMaxNum(array,array2,6,4,1)<<endl;
    cout<< soulution_1.FindKMaxNum(array,array2,6,4,8)<<endl;
    cout<< soulution_1.FindKMaxNum(array,array2,6,4,9)<<endl;
    cout<< soulution_1.FindKMaxNum(array,array2,6,4,10)<<endl;
     
    return 0;
}

           
