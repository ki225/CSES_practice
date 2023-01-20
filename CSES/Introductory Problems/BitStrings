#include <iostream>
//#include <bits/stdc++.h>

#define MOD 1000000007
/*
大數相乘時，(a*b)%c = ((a%c)*(b%c))%c，相乘時兩邊都對1000000007取模，再保存在int64內就不會溢出。


1e9+7，还有1e9+9和998244353。这三个数都是一个质数，同时小于 2^30

1. 所有模过之后的数在加法操作在int范围内不会溢出，即 a,b<2^30,a+b<2^31 。
2. 在乘法操作后在long long范围内不会溢出，即 ab<2^60。

作者：EntropyIncreaser
链接：https://www.zhihu.com/question/49374703/answer/210354141
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
using namespace std;

int main(){
    int n,ans=1;
    cin >> n;
    for(int i=0;i<n;i++){
        ans *=2;
        ans %=MOD;
    }
    cout << ans;
    return 0;
}
