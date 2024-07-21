course3 greedy & DP
===

> [!CAUTION]
>注意
>
>以下index不一定會從0開始，是因為序列 index=0 位置存放和題意無關的元素，使dp轉移式在處理的過程中不必考慮 i-1<0 造成索引值錯誤的情形。


> [!WARNING]
> 
>補充：把陣列初始化為零
>---
>若dp陣列重複使用在不同case，要記得把他們清空避免計算到上一個case的結果
>### 一維
>```cpp
>fill(begin(dp), end(dp), 0)
>```
>### 二維
>```cpp
>memset(dp, 0, sizeof(dp)); //若陣列太大，此方法會TLE
>```
>```cpp
>fill(*dp, *dp + row * col, 0);
>```

> [!WARNING] 
>補充：迭代
>---
>```cpp
>for(int i=0;i<n;i++){
>    cout << arr[i] << " ";
>}
>for(auto num:vec){
>    cout << num << " ";
>}
>```

> [!WARNING] 
>名詞介紹
>- Subsequence 子序列 -> 不用連續
>- Subarray 子串 -> 要連續

# 1. 貪心演算法 greedy algorithm
> (眼光狹隘？)只專注在眼前利益(解決局部問題)，但並不是所有問題都適合貪心。以下是幾個例子 :

## 1-1. 最優子結構
> 換零錢問題
> --- 
> 必須是倍數關係，否則不能貪心
> 
> 非倍數關係範例：硬幣面額不是倍數關係，例如1、5、10、12、16、20，問要湊出 x 元，至少要用幾個硬幣 ----> DP

> [!NOTE]  
>[b034: 悠閒的超商店員](https://zerojudge.cchs.chc.edu.tw/ShowProblem?problemid=a468)
> 

## 1-2. 有偏序關係-可排序
>考慮相鄰兩個人 i 、 j 交換順序會不會更好。


> [!NOTE]  
>
> [a137: 漂亮女朋友的回家時間(誰先晚餐問題)](https://zerojudge.cchs.chc.edu.tw/ShowProblem?problemid=a137)
> [b606. Add All](https://zerojudge.tw/ShowProblem?problemid=b606) 


## 1-3. 最小生成樹 MST
之後教graph會提到

# 2. 動態規劃 DP (Dynamic Programming)

> 簡單介紹:沒那麼暴力的暴力
> 
> 而且 DP 屬於分治法的一種，差別在於 DP 會將子狀態的答案用空間儲存下來，以在重複呼叫時不用重複計算。而一般的分治法子問題不會被重複呼叫，因此不需要記錄所有答案。


 
## 2-1.  特色
- 把大問題畫作小問題，小問題的結果會被重複使用
 - 算過一次就不重複算
 - 省時但耗費空間

## 2-2.  步驟
 1. 設定狀態，確定dp[i]或是dp[i][j]代表什麼？
    大部分的情況，`狀態 = 題目問的答案`，以費氏來說，dp[i]就是第 i 項的答案 
 2. 找出轉移式，類似遞迴數列的式子
 例如：dp[n]=dp[n-1]+dp[n-2]、dp[n][n]=min(dp[n-1][n],dp[n][n-1])
 3. 處理 base case (基礎狀況)，例如：dp[0]=0、dp[1]=1
 
## 2-3.  方式

 - Top-Down：發現小問題還沒被算，遞迴。
 - Bottom-Up：知道順序，迴圈。

## 2-4. Fibonacci （費氏數列）
> 經典遞迴題目，稍微改一些地方，他就會是一種 DP ，因為就是不斷用小問題的結果去求出大問題的答案。
> 
> ***為何原本的方法還不能算是DP?***
> 如果題目要求你回答f(7)，按照函式就會求f(7-1)+f(7-2)，接著求f(6-1)+f(6-2)和f(5-1)、f(5-2)，⋯⋯。光是第二步驟就可以發現我們算了兩次f(4)。
> 
> ![image](https://hackmd.io/_uploads/rk5F2hJYa.png)
> 
> 注意： DP 不應該重複！！
> 
> ![image](https://hackmd.io/_uploads/r1Yl63kFp.png)
> 
> 稍微修改：使用陣列紀錄
```cpp
// Fibonacci  (DP)
const int N=100000;
int dp[N+5];
 
int F(int x){
    if(dp[x])
        return dp[x];
    else if(x<=2)
        return dp[x]=1;
    else
        return dp[x]=F(x-1)+F(x-2);
}
```

## 2-5. 背包問題
>情境
>-
>有 $n$ 個物品要放入背包，第 $i$ 個物品重量為 $W_i$ 價值為 $V_i$ ，但背包最多只能承受重量 $w$，求放入物品價值總和最大？
>
>狀態
>-
>如同之前所說的，狀態通常=所求的答案，因此$dp[i]$可以定為所選物品重量總和為 i 時的最大價值
>
>方式
>-
>使用迴圈，遍歷重量由大到小是避免重複取樣。
>
>觀察
>---
>如果要放入物品 $m$，則重量可能如下：$W_1+W_m$、$W_2+W_m$、$W_3+W_m$、⋯⋯、$W_n+W_m$ 
>
>$W_1+W_m$代表原本背包裡放有$W_1$的東西，所以放入$W_m$過後，總重量變成$W_1+W_m$；$W_2+W_m$代表原本背包裡放有$W_2$的東西，所以放入$W_m$過後，總重量變成$W_2+W_m$⋯⋯
>
>也就是說，假如有物品重量$W_m$：
>- 若求背包裝入$W_1+W_m$重量時的最大價值，就必須透過$W_1$的dp來獲得，因為$W_1+W_m$的最大價值（$dp[W_1+W_m]$）可能來自於$W_1$的最大價值（$dp[W_1]$）加上物品 $m$ 的價值($Val_m$)
>- 若求背包裝入$W_2+W_m$重量時的最大價值，就必須透過$W_2$的dp來獲得
>- ⋯⋯
>
>換句話說，假如$M_1$、$M_2$⋯⋯所代表的是待放入物品的重量，若要求背包裝入重量為 i 時，最大價值為何？（dp[i] =?），只能夠過 $dp[i-M_1]$、$dp[i-M_2]$、⋯⋯、$dp[i-M_n]$得到。
>
>轉移式
>---
>當重量為j時，它的dp是下列兩者中的最大值
>- 原本存在dp[j]的值
>- 放入第i個物品後才變成重量j時的最大值，因為確定放入物品i所以加上它的價值v[i]。
>```cpp
>dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
>```
>完整程式碼
>---
>```cpp
>void BP01(int n,int W){
>    for(int i=1;i<=n;i++){ // 遍歷每個物品
>        for(int j=W;j>0;j--){ // 從大到小遍歷重量
>            if(j>=w[i]) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
>        }
>    }
>}
>```
>為何要從大的重量開始計算？
>---
>以下是重量由小到大會發生的錯誤：
>
>假設有個物品 k 的重量是 1 ，且價值是所有物品中最大的，如果 W>1 ，這個物品就會被取到兩次，因為迴圈計算從 j=0 跑到 j=背包重量
>
>當 $j=1$，$dp[1]=max(dp[1],dp[0]+v[k])=v[k]$
>當 $j=2$，$dp[2]=max(dp[2],dp[1]+v[k])=v[k]+v[k]$
>
>如果重量是由大開始往下處理，我們並不會把相同的東西納入兩次。
>---
>假設今天背包可以裝入50公斤，而我們現在有5公斤的物品和7公斤的物品，價值分別為v[0]和v[1]。我們會先從50公斤的情況做計算，接著49、48...
>
>當 j=50
>- $dp[50]=max(dp[50],dp[45]+v[0])$，此時背包的五十公斤是放入5公斤物品後的情況，剩下的45公斤狀況略。
>- $dp[50]=max(dp[50],dp[43]+v[1])$，此時背包的五十公斤是放入7公斤物品後的情況，剩下的43公斤狀況略。
>
>當 j=49
>- $dp[49]=max(dp[49],dp[44]+v[0])$，此時背包的四十九公斤是放入5公斤物品後的情況，剩下的44公斤狀況略。
>- $dp[49]=max(dp[49],dp[42]+v[1])$，此時背包的四十九公斤是放入7公斤物品後的情況，剩下的42公斤狀況略。
>
>...
>
>當 j=45
>- $dp[45]=max(dp[45],dp[40]+v[0])$，此時背包的四十五公斤是放入5公斤物品後的情況，剩下的40公斤狀況略。
>- $dp[45]=max(dp[45],dp[38]+v[1])$，此時背包的四十五公斤是放入7公斤物品後的情況，剩下的38公斤狀況略。
>
>上面的敘述有按照程式執行順序，j=45放入物品的情況是在j=50計算完成後才處理。所以説，即便在j=45時有放入五公斤的物品，也不影響 j=50中的 dp[45]。

> [!NOTE]  
>應用題
>
>[b184. 5. 裝貨櫃問題](https://www.zerojudge.tw/ShowProblem?problemid=b184)


## 2-6. 最長遞增子序列 Longest Increasing Subsequence, LIS
>題目敘述
>---
>有一序列 A，長度為N
>求 A 其中一序列 B 滿足$B_1<B_2<...<B_k$(在A的索引值)，以及$A_{B_1}<A_{B_2}<...<A_{B_k}$(內容)
>
>範例
>---
>```cpp
>//X和LIS的答案可能不是唯一，因為相同長度的遞增子序列可能有很多種
>A = 9 3 7 4 5 2 6
>X = 2 4 5 7 // (索引值)
>LIS = 3 4 5 6 // （內容）
>k = 4
>```
>*可能不是唯一，範例*
>
>![image](https://hackmd.io/_uploads/BJb4ZXbta.png)
>
>DP狀態
>---
>$dp[N]=max(dp[i])$  , $1<=i<=N$ 
>最後一個位置選 $i$ 的最大長度，其中 $1<=i<=N$。
>
>dp轉移
>---
>
>$dp[i]=1+max(dp[j])$ ， $j<i$ 且 $A_j<A_i$
>白話：要得知索引值為i的最長遞增子序列長度，要從索引值 0 判斷到索引值為j，其中索引值j必須比i小。假如符合$A_j<A_i$，
>
>舉例：求出i=4的最長遞增子序列長度，arr[]={9,8,2,3,5,1,4,7}
>我們要讓 $A_j$ 和 $A_i$ 比較。
>
> $A_i=arr[i]=arr[4]$ 
>- j=0，dp[0]=1，但是9>5，不符合。
>- j=1，dp[1]=2，8>5，不符合
>- j=2，dp[2]=2，符合$A_j<A_i$ ，所以dp[4]=max(dp[4],dp[2]+1)=dp[2]+1=3
>- j=3，dp[3]=2，符合$A_j<A_i$ ，所以dp[4]=max(dp[4],dp[3]+1)=3
>
>其中 i 和 j 都是針對一開始的 Input Sequence。
>
>```cpp
>for(int i=1;i<=n;i++){
>    for(int j=0;j<i;j++){
>        if(str[j]<str[i]){
>            dp[i]=max(dp[i],1+dp[j]);
>            ans=max(ans,dp[i]);
>        }
>    }
>}
>```
>例外情況：測資量大 --> 用二分搜尋
>---
>若題目給的測資極大，就無法用 $O(N^2)$ 直接求 -> 二分搜尋。
>
>
>## (1)lower_bound
>用在嚴格遞增 LIS，找出vector中「大於或等於」val的「最小值」的位置：
>- vector
>```cpp
>auto it = lower_bound(v.begin(), v.end(), target);
>```
>- array
>```cpp
>auto it = lower_bound(arr,arr+arr_size,target);
>```
>因為lower_bound會找到大於等於自己的數值，假如序列裡有「和自己相同大小的數值」，lower_bound會回傳「該數值」的位置，所以「自己」會取代「該數值」，最後自己的值只會在序列中出現一次。
>
>### 範例
>```cpp
>int lengthOfLIS(vector< int>& nums) {
>    vector< int> lis;
>    for (int num : nums) {
>        auto it = lower_bound(lis.begin(), lis.end(), num);
>        if (it == lis.end()) {
>            lis.push_back(num);
>        } else {
>            *it = num;
>        }
>    }
>    return lis.size();
>}
>```
>
>## (2)upper_bound
>用在非嚴格遞增 LIS，找出vector中「大於」val的「最小值」的位置：
>```cpp
>auto it = upper_bound(v.begin(), v.end(), val);
>```
>因為upper_bound會找到大於自己的數值，假如序列裡有「和自己相同大小的數值」，upper_bound會回傳「該數值」後面的位置，所以「自己」會接在「該數值」的後面(取代掉「該數值」後面原本接的數值)
>
>### 範例
>```cpp
>int lengthOfLIS(vector< int>& nums) {
>    vector< int> lis;
>    for (int num : nums) {
>        auto it = upper_bound(lis.begin(), lis.end(), num);
>        if (it == lis.end()) {
>            lis.push_back(num);
>        } else {
>            *it = num;
>        }
>    }
>    return lis.size();
>}
>```
>    
>實際例子
>---
>```
>A = 10 3 4 5 2
>```
>```
>i=1  A[i]=10
>X是空的 -> 情況 1
>X = 10  // 把 10 放到 Ｘ 的最後
>```
>「換成」的動作對應到 upper_bound / lower_bound範例中，else所執行的動作。
>```
>i=2  A[i]=3
>3 < 10 -> 情況 2
> X = 3  // 把 10 「換成」 3
>```
>```
>i=3  A[i]=4
>4 > 3 -> 情況 1
>X = 3 4  // 把 4 放到 Ｘ 的最後
>```
>```
>i=4  A[i]=5
>5 > 4 -> 情況 1
>X = 3 4 5  // 把 5 放到 Ｘ 的最後
>```
>```
>i=5  A[i]=2
>2 < 3 -> 情況 2
> X = 2 4 5  // 把 3 換成 2
>```
>
>X子字串代表什麼?
>---
>$X$子字串長度確實為$LIS$長度，但是$X!=LIS$。
>```cpp
>LIS = 3 4 5
>X = 2 4 5
>```
>如何得到LIS的序列？
>---
>前面都只有講到LIS的長度，現在說一下怎麼求序列
>紀錄最長遞增子字串$X$有誰，再透過已知$X$的長度去求真正的LIS。
>
>透過X長度和dp取得真正LIS
>---
>若找到索引值 $j<i$、$A_j<A_i$ 且 dp[j]=dp[i]-1，則表示$A_i$可以接在$A_j$後面。
>但是要找到符合條件的$A_j$和$A_i$實在太難ㄌ，就用下面的方法吧
>
>
>
>### 舉例說明
>```
>index     1     2     3     4     5
>value     5     3     8     6     9
>dp        1     1     2     2     3
>```
>我們確保逆推時，第一個dp變化的位置對應到的值會比上一次放入答案的值小。這是因為我們當初在定義dp時，要求 $A_j<A_i$ 成立才 $dp[i]=1+max(dp[j])$。（詳情回到[dp轉移](https://hackmd.io/rwpn6rNGRa26M5tXNCSV2w?both#dp轉移)）
>
>例如dp值為3時是arr[5]=9，把他放入ans。往左邊找第一個產生產生dp變化的是arr[4]=6（dp從3->2），把他放入ans。下一次產生dp變化的是arr[2]=3，把他放入ans。
>
>得到遞增子序列 ans：2, 4, 5
>
>```cpp
>//max_dp是在dp中找到的最大值。也可以用upper/lower_bound求。
>for(int i=n-1;i>=0;i--){
>    if(dp[i]==max_dp){
>        ans.push_back(arr[i]);
>        max_dp--;
>    } 
>}
>```



> [!NOTE]  
>應用題目
>[d242. 00481 - What Goes Up](https://zerojudge.tw/ShowProblem?problemid=d242)
>[f608. APCS 飛黃騰達](https://zerojudge.tw/ShowProblem?problemid=f608)

## 2-7. 最長共同子序列 Longest Common Subsequence, LCS
>給定兩個字串s,t，求 s 與 t 的最長共同子序列( Longest Common Subsequence )
>
>- 第一步 分割問題
>會發現有許多共同子序列都是符合要求的子序列，因此解法只需要開兩個維度記錄在每個分別前綴下的最長共同子序列長度
>- 第二步 找出轉移式
>每次檢查當前的是否與另一個的當下一樣，若是一樣 則 $dp[i][j]=dp[i-1][j-1]+1$
>
>範例
>```
>x = “ABCBDAB”
>y = “BDCABA”
> ```
> 從 len1 和 len2 回溯出 LCS
> 
> ![image](https://hackmd.io/_uploads/rJ7k0bWKp.png =50%x)
> 
> dp 轉移式
> - $dp[i][j]=dp[i-1][j-1]+1$ , 若s[i]==t[j]
> - $dp[i][j]=max(dp[i][j-1],dp[i-1][j])$

```cpp
for(int i=1 ; i<=s.size() ; i++){
    for(int j=1 ; j<=t.size() ; j++){
        if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);       
    }
}
```

> [!TIP]
>如果刻意地讓 dp 式的 i,j 都由 1 開始就不需額外判斷邊界

> [!NOTE]  
>應用題
>[a133. 10066 - The Twin Towers](https://www.zerojudge.tw/ShowProblem?problemid=a133)
>[c001. 10405 - Longest Common Subsequence](https://www.zerojudge.tw/ShowProblem?problemid=c001)
>[uva 111 History Grading](https://onlinejudge.org/external/1/111.pdf)






