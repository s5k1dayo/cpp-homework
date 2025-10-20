# 此为git学习碧姬

## 删除分支

- 已合并：`git branch -d`后接分支名
- 未合并：`git branch -D`
  
## 解决冲突

- 选择保留部分后，需重新**add** 和 **commit** 才可完成merge动作

## 暂存区 git stash

- 会将分支恢复到上一次提交
- 查询: `stash list`
  
## “ctrl+z” 撤销修改 git restore

- 后接文件名，使目标文件完全回到上一个提交状态
  
## 修改提交**git commit --amend**

- 修改上次提交的备注`git commit --amend -m ""`
- 在上次提交中添加文件`git commit --amend --no-edit`（需要先add补交的文件）
