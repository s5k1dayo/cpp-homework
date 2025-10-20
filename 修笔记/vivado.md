# 第一章：沟槽德数字逻辑实验，集贸不交全靠自学。组员还图省事不下功夫只能组长发力之悲惨大学生活

## 仿真文件语法**simulater**

``` verilog
//本行注意完整的括号
module mux2xverilog_sim(  );
//输入 reg 输出 wire
reg a=0;
reg b=1;
reg s=0;
wire c;
//实例化  被调用的模块名 实例化名（.被实例化的端口名（当前模块信号名））
mux2xverilog u(.a(a),.b(b),.s(s),.c(c));
//开始
initial begin
// 第200ms时 s变为1
#200 s=1;
end
endmodule
```

## 一些常用翻译

综合：`synthesis`
仿真：`implementation`
