
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int ans, m;
char pre[27], post[27];
map<char, int> postidx;
//相应字母在post中的下标,因为每个节点都是唯一的，所以可以建立一个索引
void Count(int preS, int preE, int postS, int postE);
int mCk(int m, int k);
 
int main()
{
    while (scanf("%d %s %s", &m, pre, post) != EOF)
    {
        ans = 1;
        for (int i = 0; i<strlen(post); i++)
            postidx[post[i]] = i;
        Count(0, strlen(pre) - 1, 0, strlen(post) - 1);
        printf("%d\n", ans);
    }//while
    return 0;
}//main
 
void Count(int preS, int preE, int postS, int postE)//指示先序和后序某段区间
{
    if (preS >= preE)
        return;
    int i = preS + 1, cnt = 0;//cnt统计子树的个数,i是标识当前树的根节点的子树的根节点，在pre中的下标
    int idx = postidx[pre[i]];
    while (i <= preE)
    {
        Count(i, i + idx - postS, postS, idx);
        cnt++;
        if (idx != postE - 1)//子树不止一个,把要递归搜索的树的区间整体移动
        {
            i += idx - postS + 1;   //idx-postS是刚刚递归过的子树的大小
                                  //i要跨过这个区间，找到下一个要搜索的根节点
            postS = idx + 1;    //post的区间起始位置也要前进1位
            idx = postidx[pre[i]];//idx重新定位下一个要搜索的子树根节点在post中的下标
        }
        else
            break;//完成对当前区间中所有字数根节点的全部搜索
    }
    ans *= mCk(m, cnt);//计算排列组合，cnt表示当前层有几个子树
}
 
int mCk(int m, int k)
{
    int numerator = 1, denominator = 1;
    for (int i = 0; i<k; i++, m--)
        numerator *= m;
    for (int i = 1; i <= k; i++)
        denominator *= i;
    return numerator / denominator;