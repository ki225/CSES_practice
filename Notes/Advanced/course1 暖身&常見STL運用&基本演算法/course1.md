course1 暖身&常見STL運用&基本演算法
   ---

# 1. 前言
> [!TIP]
> APCS
> - 第一題:基本的輸入輸出、運算、判別式與迴圈。
> - 第二題:簡單的陣列運用，通常一維50分二維50分。
> - 第三題:遞迴、排序與搜尋、或簡單資料結構(stack and queue) 
> - 第四題:貪心、分治或DP。

> [!TIP]
> 剛開始上課先從基本的題目入門競程吧，之後還有很多演算法等你XD

# 2. warm-up
## 2-1. 萬用標頭檔
```cpp 
#include <bits/stdc++.h>
```
## 2-2. 加速
> - IO優化
```cpp 
ios::sync_with_stdio(false); 
cin.tie(nullptr); 
```
>- 避免使用endl來換行，取而代之我們使用’\n’，因為endl是由’\n’和flush組成，flush會使目前輸出的結果立即顯示，所以速度不高
>

>若只使用第一點，不使用第二點，則在輸出時仍然會因為flush過慢拖累整體執行效率。
>若只使用第二點，雖然輸出時不會 flush，但 cin 時預設也會 flush，因此依然很慢。

```cpp 
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false),cin.tie(0);
    int a;
    cin >> a;
    cout << a << '\n';
}
```
:::danger
如果要debug，可以把優化那行先註掉，因為優化完輸出會在程式結束的時候才輸出，有些情況下不會立即顯示，很難debug。
:::

## 2-3. 全域和區域變數
>全域
>---
>- 宣告在所有區塊和類別之外的變數
>- 不可宣告同名的全域變數
>- 若沒有給定初始值，會自動給0
>- 生命週期：在程式執行到程式結束期間都會暫用記憶體
>- 生存空間：從宣告後的任意程式碼區塊都可存取
>- 好處：相較於區域變數不會被配置到 stack 區，他陣列大小可以取比較大，對於競程來說常常會需要大陣列。
>
>區域
>---
>- 起始於變數宣告，結束於宣告敘述所在的區塊的大右括號，在生命週期內會佔用記憶體。
>- 缺點：記憶體會被分配在 stack 區段，而這塊區域一般來說並不夠大，因此只要陣列太大，就會立刻 stack overflow。
```cpp 
#include <bits/stdc++.h>
using namespace std;
int arr[10000000]; //全域變數，所以沒有給定初始值會自動給0
 
int main(void){
	int str[100000]; //這邊是區域變數，沒有給定初始值就不會有
}
```
## 2-4. max()、min()
> 顧名思義是取得比較數值之中的最小值或是最大值。使用方法如下：
> 
> ```cpp
> max(var1,var2); //比較兩個變數
> max({var1,var2,var3}); //比較多個變數
> ```

> [!NOTE]  
>應用題
>- [c295. APCS-2016-1029-2最大和](https://zerojudge.tw/ShowProblem?problemid=c295)
> - [f312. 人力分配](https://zerojudge.tw/ShowProblem?problemid=f312)
> - [f605. 購買力](https://zerojudge.tw/ShowProblem?problemid=f605)




# 3. array
>- 若全部未指定值，則陣列中每個元素的值可能是任何值
>- 陣列宣告過後，不可改變大小或重新宣告。
>- index由0開始，所以設定大小為n，可用空間為0~n-1
>- 不可以存放無限多的陣列
>- 宣告很大陣列時會加上誤差值5~15，例如：`int arr[10000015]={0}`
>- 設在全域會自動初始化為0
> [!WARNING]
>在區域變數中乘起來最大約 $10^5$ ~ $10^6$，在全域變數中乘起來不可以超過大小限制約 $10^8$



## 3-1. 矩陣
> [!NOTE] 
>應用題
>
>- [b266. 矩陣翻轉 / 2016 APCS 實作題第二題](https://zerojudge.tw/ShowProblem?problemid=b266)
> - [h027. 202001_2 矩陣總和](https://zerojudge.tw/ShowProblem?problemid=h027)


## 3-2. 排序
由小到大
```cpp 
sort(arr,arr+陣列元素數量)
```


由大到小
```cpp 
sort(arr, arr+n, greater<int>());
```

> [!NOTE] 
>應用題
>
>- [TOJ 47](https://toj.tfcis.org/oj/pro/47/)


## 3-3. 紀錄



***簡易迷宮問題***
迷宮問題為了避免判斷重複路徑，會紀錄當前位置是否曾被拜訪。通常設立vis[]矩陣來記錄。
:::spoiler 迷宮題目
>一群勇敢的小大一前往冒險，途中被困在了一座神秘的迷宮中，這個迷宮只允許向下或是向右走。他們在迷宮裡行走了好幾天，遇到了各種奇怪的陷阱和謎題。最終，來到一個叉路口。
在右邊的通道，有一扇門，上面刻著：「挑戰你們的智慧」。他們決定接受挑戰，解開了一連串的謎題，最後成功打開了門，但發現它只通往了一間刷著白漆、只有兩扇門的房間。
突然，一位神秘的嚮導拿了兩張牌走了過來，他自稱小光。小光給了他們一台筆電，上面開著vscode的視窗。小光說：「我手裡有兩張牌，分別是兩扇門的開關。但我沒有那麼壞要讓你們的人生被機率掌控啦。你們可以自由選擇。一個門後是迷宮，一個是未知。」其中一個小大一說：「未知是什麼意思？」小光回他：「就是說，這個迷宮有可能沒有出口唷，甚至沒有起點 :) 」旁邊的跟班小云：「現在想放棄的停修單可以準備一下呵呵，這場冒險可以隨時結束！」
看到臉色鐵青的小大一，小光又說：「別那麼悲觀啦，無論你是否選擇走迷宮，助教都會告訴程式地圖的樣貌，你們剛好都是資工系的嘛，這台電腦給你們，用你們寫的程式找看看迷宮有沒有出口，如果發現沒有出口就選另一個選項吧。啊對了，迷宮是正方形，一進去的你們會位於它的左上角，而出口在整個正方形的右下角。」
「總之，離開這座迷宮只有兩個方法——憑你們的直覺，或是你們的程式能力。」
請聰明的小大一幫助自己穿越充滿危險的迷宮區域，獲得AC。
>
>
>輸入說明：
輸入一個數字`N`，`2<=N<=50`，表示等等會輸入`N*N`大小的正方形迷宮。
隨後輸入N行的資料，每行有N個整數代表圍牆或是路。1代表路，0代表牆壁。每個整數會用空白區分，最後一個整數後方沒有空白，只有換行。
>
>輸出說明：
>如果該地圖有出口則輸出”YES”，反之輸出”NO”（皆不含雙引號）。
>
>範例1
>輸入
>```
>5
>1 0 0 0 0
>1 1 1 1 0
>0 0 0 1 1
>1 0 0 1 1
>0 0 0 1 1
>```
>輸出
>```
>YES
>```
>範例2
>輸入
>```
>5
>1 0 0 0 0
>1 1 1 1 0
>0 0 0 1 1
>1 0 0 1 1
>0 0 0 1 0
>```
>
>輸出
>```
>NO
>```

:::


## 3-4. 字串處理
字串在C語言中是以`char arr`的形式存在，但在c++中，取得字串特定位置的字元也可以用陣列取索引值的方法。
> [!NOTE] 
>應用題
>
> - [a013. 羅馬數字](https://zerojudge.tw/ShowProblem?problemid=a013) 


## 3-5. 建表
[c633. 基礎排序 #2-2 ( 質因數和 )](https://www.zerojudge.tw/ShowProblem?problemid=c633)

## 3-6. 貪婪
之後會教 :D


# 4. vector
基本上和array一樣，空間建立上更為彈性

# 5. queue
>宣告
>---
>```cpp
>#include < queue>
>```
>```cpp
>queue<元素類型> myQueue;
>```
>取得第一個元素
>---
>```cpp
>queue.front();
>```
>取得最後一個元素
>---
>```cpp
>queue.back();
>```
>Enqueue
>---
>將一個項目放入佇列的尾端。
>```cpp
>queue.push(要放入的元素);
>```
> Dequeue
> ---
>從佇列頂端拿走一個項目。 
>```cpp
>queue.pop();
>```
>判斷是否為空
>---
>回傳true代表是空的，false代表不是空的。
>```cpp
>queue.empty();
>```
>遍歷
>---
>沒有迭代器，只能透過遍歷的方式去取得其他元素
>```c
>while (!myQueue.empty()) {
>    cout << myQueue.front() << " ";
>    myQueue.pop();
>}
>```
>補充：priority queue
>---
>由小到大
>```cpp
>priority_queue<int, vector< int>, greater< int> > c; 
>```
>由大到小
>```cpp
>priority_queue< int> a; 
>priority_queue<int, vector< int>, less< int> > a;
>```



# 6. stack
> 宣告
> ---
>要先添加堆疊的標頭檔
>```cpp
>#include < stack>
>```
>```cpp
>stack <元素類型> 堆疊名稱;
>```
> 取得頂端元素
> ---
>```cpp
>堆疊名稱.top();
>```
> 放入
>---
>```cpp
>堆疊名稱.push(要放入的元素);
>```
> 取出
> ---
>```cpp
>堆疊名稱.pop();
>```
>判斷是否為空
>--- 
>```cpp
>堆疊名稱.isEmpty();
>```
>判斷是否為滿
>---
>```cpp
>堆疊名稱.isFull();
>```
> 遍歷
> ---
>```c
>while (!myStack.empty()) {
>    cout << myStack.top() << " ";
>    myStack.pop();
>}
>```

> [!NOTE] 
>應用題
>
> - [c123. 00514 - Rails](https://zerojudge.tw/ShowProblem?problemid=c123)
> - [a565. 2.p&q的邂逅](https://zerojudge.tw/ShowProblem?problemid=a565)


# 7. map
> 簡介
> ---
>1. 很像 python 的 dictionary
>2. 鍵值配對
>
>宣告
>---
>```cpp
>#include < map>
>```
>```cpp 
>map<char, int> myMap;
>```
>```cpp 
>map<char, int> myMap {
>    {'a', 1},
>    {'b', 2},
>    {'c', 3}
>};
>```
>插入新元素
>---
>```cpp
>myMap[new_key] = new_val;
>```
>刪除存在元素
>---
>```cpp
>// 刪除鍵為 'b' 的鍵值對
>myMap.erase('b');
>```
>遍歷
>---
>``` cpp
>for (auto it = myMap.begin(); it != myMap.end(); ++it){
>    cout << it->first << " => " << it->second << " ";
>}
>```
>查找特定元素
>---
>``` cpp
>// 查找特定的鍵
>auto search = myMap.find('b');
>if (search != myMap.end()) {
>   cout << "Found " << search->first << " => " << >search->second << endl;
>} else {
>    cout << "Key not found" << endl;
>}
>```

# 8. set
> 簡介
> ---
> 最大特色是不會有重複元素出現
>
>宣告
>---
>``` cpp
>#include < set>
>```
>``` cpp
>set<int,less< int>> s; //小到大
>set<int,greater< int>> s; //大到小
>```
>``` cpp
>set< int> myset{1, 2, 3, 4, 5};
>```
>
>插入元素
>---
>``` cpp
>s1.insert(x);
>```
>刪除指定元素
>``` cpp
>myset.erase(該元素的值);
>```
>
>遍歷
>---
>``` cpp
>for (itr = s1.begin(); itr != s1.end(); itr++) {
>    cout << *itr << " ";
>}
>```
>查找特定元素
>---
>
>``` cpp
>auto search = mySet.find(2);
>if (search != mySet.end()) {
>    cout << "Found " << *search << endl;
>} else {
>    cout << "Element not found" << endl;
>}
>```
>

> [!NOTE] 
>[i399. APCS 數字遊戲](https://zerojudge.tw/ShowProblem?problemid=i399)

# 9. 遞迴演算法
- 遞迴：不斷呼叫自己
- 要設定 base case (終止條件)
- 遇到有 return 的要注意 return 前後上下層的關係

> [!NOTE] 
> - [e357. 遞迴函數練習](https://zerojudge.tw/ShowProblem?problemid=e357)
> - [a227. 三龍杯 -> 河內之塔](https://zerojudge.tw/ShowProblem?problemid=a227)

