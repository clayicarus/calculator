# calculator
将中序表达式转换为后缀表达式并打印计算结果。

## 开发日志
- 2022.7.15: 

    1, 完成了标准表达式到后缀表达式的转换功能。
    
    2, 需要将运算符匹配修改为switch的版本。
    
    3,未完成标准化功能。
    
    4, 考虑将检查功能加入到标准到后缀的转换功能中。
    
- 2022.7.16:

    1, 引入一元运算符解决了负数输入的问题。
    
    2, 完成了后缀表达式的计算功能。
    
    3, 解决了小数输入的问题。
    
    4, 尚未完成语句合法检查的功能。
    
- 2022.9.8:

    1, 重构，将所有功能抽象为类。
    
    2, 利用function类实现了运算符的匹配，极大地简化了后缀式的处理代码。
    
- 2022.9.10

    1, fixExpr() 重构，去除了结尾符号。

    2, toPostfix() 重构，支持一元运算符的转换。
    
- 2022.9.11

  1, 改进toPostfix()，区分"func/var"和"operator"的输入。

  2, 引入三角函数计算。
