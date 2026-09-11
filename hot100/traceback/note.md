# 回溯部分

## 子集枚举公式

```c++
vector<int> t;
void dfs(int cur, int n) {
    if (cur == n) {
        // 记录答案
        // ...
        return;
    }
    // 考虑选择当前位置
    t.push_back(cur);
    dfs(cur + 1, n);
    t.pop_back();
    // 考虑不选择当前位置
    dfs(cur + 1, n);
}

```

## 普通回溯公式

```c++

void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }
    for (选择 : 本层集合中的元素) {
        处理节点;
        backtracking(路径, 选择列表); // 递归
        撤销处理; // 回溯
    }
}

```

## 分割（枚举段结束位置）公式

**使用情形**：要把一个字符串/数组**切成连续的若干段**，每段需满足某个条件，求所有合法切法。典型题：131 分割回文串、93 复原 IP、分割成斐波那契等。

**核心特征（判断依据）**：

1. 答案是「对原序列的**连续切分**」，段与段之间**不重叠、不交叉、不跳元素**，顺序固定。
2. 每个元素**恰好属于某一段**，不能丢、不能重复。
3. 需要枚举的是「这一段从哪到哪」——也就是**当前段的结束位置**。

**与「子集式回溯」的区别**：

- 子集/排列式：每个元素**独立**决定选或不选，可以跳着选（如 78 子集、46 全排列）。
- 分割式：段是**连续区间** `[start, end]`，一旦从 `start` 切下 `end`，下一段只能从 `end+1` 继续，中间不能跳。

**模板**：

```c++
vector<string> path;

// start 表示当前段必须从 s[start] 开始
void dfs(const string& s, int start) {
    if (start == s.size()) {
        // 走到末尾，说明整段被完整切完，记录一种方案
        res.push_back(path);
        return;
    }
    // 枚举当前段的结束位置 end
    for (int end = start; end < s.size(); end++) {
        if (满足条件(s, start, end)) {              // 例如 [start,end] 是回文
            path.push_back(s.substr(start, end - start + 1));
            dfs(s, end + 1);                        // 下一段从 end+1 开始
            path.pop_back();
        }
    }
}
```

**要点**：`start` 是「下一段必须从哪开始」，这是贯穿递归的**状态**；循环里枚举的是「当前段在哪结束」。不要用「继续拼 vs 切开」两层递归去写（容易漏掉记录结果、漏回溯），直接枚举结束位置最清晰。
