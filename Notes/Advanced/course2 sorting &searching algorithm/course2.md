course2 sorting &searching algorithm
===

# 1. 搜尋演算法
## 1-1. 二分搜尋 Binary search
> 簡介
> ---
> 比較目標值位於左半/右半範圍，接著縮小範圍。
> 不斷重複此步驟直到範圍限縮到一個元素/更小。
>
>說明
>---
> 假設目標是23，指定陣列是已經排序的 arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}
> 
> - Step1 
> 此時low=0，high=9，取得middle=(high+low)/2=4 （c++整數除法會取下高斯）
> ![image](https://hackmd.io/_uploads/H1uOWt1tT.png)
> - Step2
> 若目標比middle大，表示位於右半邊。
> 範圍限縮到右半邊，此時區間low的索引值為原先的middle+1=4+1=5，最大為原先的high=9
> ![image](https://hackmd.io/_uploads/Hkx9zYyta.png)
> 
> - Step3
> 若發現目標和 `arr[low]` / `arr[high]` 相同，則結束尋找。
> ![image](https://hackmd.io/_uploads/Bk-tQYJtT.png)

```cpp
int binray_search(int l, int r, int target) {
	int mid;
	while (r >=l) {
		mid = (l+r)/2; // 或是 (l+r)>>1 二進制右移1位
        
        if(arr[mid]==target) return mid;
		else if (arr[mid]>target) r = mid-1;
		else l = mid+1;
	}
	return l; // or r
}
```
> [!TIP]
>BST的搜尋對象不要侷限在你輸入的陣列裡～下面兩題APCS就是個例子。


> [!NOTE] 
>應用題
>
>[d732. 二分搜尋法](https://zerojudge.tw/ShowProblem?problemid=d732)
>[c575. APCS 2017-0304-4基地台](https://zerojudge.tw/ShowProblem?problemid=c575)
>[h084. APCS 牆上海報](https://zerojudge.tw/ShowProblem?problemid=h084)
>[uva 10282 Babelfish](https://onlinejudge.org/external/102/10282.pdf)


> [!WARNING] 
>上述APCS題目可以用二分搜是因為單調性&連續性

## 1-2. 循序搜尋


> [!NOTE] 
>應用題
>[Sum of Two Values](https://cses.fi/problemset/result/8275787/) ---> 頭尾搜



---
# 2. 排序演算法


## 2-1. 氣泡排序 bubble sort
簡而言之就是超級暴力，比較所有元素之間的大小，左邊大於右邊就交換。
```cpp
void bubbleSort(int arr[],int size) {
    //排序n-1個回合 
    for(int i=size-1;i>=1;i--){
        //從第0個元素開始掃瞄
        for(int j=0;j<=i-1;j++){
            //判斷左邊元素是否大於右邊元素
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]); // A[j] 與 A[j+1]交換
        }
    }   
}
```

## 2-2. 插入排序 insertion sort
>序列分成「已經排序」和「尚未排序」。從「尚未排序」中挑最左邊的元素當作要「待排序的目標」，依照大小插入「已經排序」序列中的正確位置。
>![](https://hackmd.io/_uploads/SJ2sw-y62.png =50%x)![](https://hackmd.io/_uploads/ByQTPbyTh.png =50%x)
```cpp
void insertionSort(int arr[],int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i]; //要進行排序的數值
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        
        arr[j + 1] = key;
    }
}
```

## 2-3. 快速排序 quick sort
> 簡介
> ---
> 因為很快所以叫做快速排序，一般情況複雜度是O(nlogn)，在常數項比merge sort稍小所以比merge sort快。
> 
> 但worst case又是另一回事，先不談，難免失常XD。
> 
> 說明
> ---
> 在過程中我們會使用 leftPointer 、 rightPointer 和 pivot。
> - leftPointer 表示由左往右，被判斷的對象。
> - rightPointer 表示由右往左，被判斷的對象。
> - pivot 是判斷 leftPointer 和 rightPointer 是否符合資格的準則。
> 
> leftPointer會從該子序列的最左邊不斷往右，直到找到比pivot大者。因為預期左邊比較小，所以找到左邊比較大者要記錄下來，等等丟去右邊。同理，rightPointer會從該子序列的最右邊不斷往左，直到找到比pivot小者。
> 
> 當leftPointer和rightPointer都被確定時，就進行交換。
> 
> ![quick_sort_partition_animation](https://hackmd.io/_uploads/H1ZMsHbKp.gif)
> (gif from : tutorialspoint.com)
> 

> [!WARNING] 
>注意：上圖只是一個子序列的排序，尚未完成整個序列的排序。

> [!TIP]
>當然還有其他種quick sort，同樣是和pivot判斷，但可能會有些小變化
>- pivot取的位置不同
>- leftPointer 和 rightPointer的決定方式不同
>
>像是在[CH16 排序](https://hackmd.io/u9EnNkKUS0uTjm7Zs1-OsQ)的程式碼，它只有用arr[j]代表當前判斷的元素，比 pivot小就丟到arr[i]中，確保區間[low,i]內的元素都比 pivot 小，最後使arr[i+1]和pivot交換即可。

```cpp
int partition(int left, int right, int pivot) {
   int leftPointer = left -1;
   int rightPointer = right;
   while(true) {
      while(intArray[++leftPointer] < pivot) {}	
      while(rightPointer > 0 && intArray[--rightPointer] > pivot) {}
      if(leftPointer >= rightPointer) {
         break;
      } else {
         swap(leftPointer,rightPointer);
      }
   }
   swap(leftPointer,right);
   return leftPointer;
}
void quickSort(int left, int right) {
     if(right-left <= 0) {
      return;   
   } else {
      int pivot = intArray[right];
      int partitionPoint = partition(left, right, pivot);
      quickSort(left,partitionPoint-1);
      quickSort(partitionPoint+1,right);
   }        
}
```



## 2-4. 合併排序 merge sort
> merge sort 有兩種方式達成，一個是依照索引值大小，另外則是使用遞迴


> 依照索引值大小
> - 
> 1. 將陣列不斷拆成 N個長度為 1 的鍵值。
>2. 將 N個長度為 1 的鍵值成對地合併長度為 2 的鍵值組。
>3. 將 N/2個長度為 2 的鍵值成對地合併長度為 4 的鍵值組。
>4. 將鍵值組成對地合併，直到合併成一組長度為 N 的鍵值組為止。如下圖所示。
>
>![](https://hackmd.io/_uploads/H1JhDkQpn.png =50%x)
>![image](https://hackmd.io/_uploads/rJIU28btp.jpg)

>
>遞迴形式
>---
>![image](https://hackmd.io/_uploads/rJoY3IZYp.jpg)

```cpp
// 合併兩個有序數組
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// 排序
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


```
> [!NOTE] 
>[d784. 一、連續元素的和](https://zerojudge.tw/ShowProblem?problemid=d784)

> [!TIP]
>小結
>---
>其實sort目的都差不多，只是若要考慮到會不會TLE，就可以考慮使用 O(nlogn)的quick sprt 或是merge sort。
>
>不然也可以用 :
>- set(沒有重複元素為前提)
>- piority_queue
>- vector.sort(v.begin(),v.end())
>- sort(arr,arr+length) 



> [!NOTE]  
>[a737. 10041 - Vito's family](https://www.zerojudge.tw/ShowProblem?problemid=a737)
>[Restaurant Customers](https://cses.fi/problemset/result/8276131/)

---
# 3. 分治法
> 把問題先拆解(divide)成子問題，並在逐一處理子問題後，將子問題的結果合併(conquer)
> 
> 其實quick sort和merge sort都是分治法的一種。
![image](https://hackmd.io/_uploads/rk7XMi1Fa.png =80%x)

> [!NOTE]
> [B. Equivalent Strings](https://codeforces.com/problemset/problem/559/B)
> [d219. 00374 - Big Mod](https://zerojudge.tw/ShowProblem?problemid=d219) ---> 不能用函式遞迴，會超過記憶體限制


<details>
  <summary>Equivalent Strings 中文題目</summary>
  今天在一個關於字符串的講座上，傑拉爾德學到了字符串等價性的新定義。兩個長度相等的字符串 a 和 b 在以下兩種情況下被稱為等價：

它們相等。
如果我們將字符串 a 分成兩個相同大小的部分 a1 和 a2，將字符串 b 分成兩個相同大小的部分 b1 和 b2，則以下其中一種情況正確：
a1 等價於 b1，且 a2 等價於 b2。
a1 等價於 b2，且 a2 等價於 b1。
作為家庭作業，老師給了他的學生兩個字符串，並要求確定它們是否等價。

傑拉爾德已經完成了這個家庭作業。現在輪到你了！

輸入
輸入的前兩行包含老師給出的兩個字符串。每個字符串的長度為 1 到 200,000 個字符，由小寫英文字母組成。這兩個字符串的長度相同。

輸出
如果這兩個字符串等價，請打印“YES”（不包括引號），否則打印“NO”（不包括引號）。
  
</details>


<details>
  <summary>解題思路</summary>
  如果子序列完全位於左半部分，也就是 a[0，···mid] 中，用遞迴求出其最大連續子序列和 maxLeftSum。
如果子序列完全位於右半部分，也就是 a[mid+1，···n-1] 中，用遞迴求出其最大連續子序列和 maxRightSum。
如果子序列橫跨了序列 a 的中部，佔據了左右兩部分。也就是說，在這種情況下，最大連續子序列和必然包括了 mid 元素。首先求出 maxLeftBorderSum，即從 mid（終點）到左邊的最大連續子序列和，找到左邊最大連續子序列和的起點位置，並將左邊到 mid 的最大連續子序列和賦值給 maxLeftBorderSum。然後求出 maxRightBorderSum，即從 mid（起點）到右邊的最大連續子序列和，找到右邊最大連續子序列和的終點位置，並將 mid 到右邊的最大連續子序列和賦值給 maxRightBorderSum。這種情況下的最大連續子序列和為 maxMidSum = maxLeftBorderSum + maxRightBorderSum。
整個序列 a 的最大連續子序列和為 maxMidSum、maxLeftBorderSum、maxRightBorderSum。將三者進行比較大小，即可得到最終結果。
  
</details>
