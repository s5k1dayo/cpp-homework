# 顺序表

## 按某个值排序

```c++
sort(arr.begin(),arr.end(),[](vector<int> &a,vector<int> &b){
    return a[0]<b[0];//升序
});
```
