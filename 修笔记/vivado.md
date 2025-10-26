# 第一章：沟槽德数字逻辑实验，集贸不交全靠自学。组员还图省事不下功夫只能组长发力之悲惨大学生活

## B3 板卡型号为

``` bash
xc7a35tcpg236-1 
```

## 一些常用翻译

仿真：`simulation`
综合：`synthesis`
实现：`implementation`

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

## 约束引脚注意事项

- 七段数码管链接顺序从上到下对应a到g

``` bash
w7,w6,u8,v8,u5,v5,u7,v7
```

- 选择信号从第一个到第四个分别对应 ` w4,v4,u4,u2 `

- clk接w5
