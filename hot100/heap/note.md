# QuickSelect 划分模板极简笔记

## Hoare 双向划分

1. 指针：`i=l-1，j=r+1`
2. 特征：双do-while，**无需pivot归位**
3. 区间：`[l,j]` / `[j+1,r]`
4. ✅ 禁止 `j-1`
5. 优点：重复元素性能更好

## Lomuto 单向划分

1. 指针：单遍历 `for`
2. 特征：末尾swap，**pivot固定落在j**
3. 区间：`[l,j-1]` / `[j+1,r]`
4. ✅ 使用 `j-1`
5. 缺点：大量重复数据易超时

## 核心口诀

Hoare：双向不归位，分界不用减一
Lomuto：单向归位pivot，左区间j减一
> 两套边界严禁混用；partition只负责返回分界，递归交给上层quickSelect
