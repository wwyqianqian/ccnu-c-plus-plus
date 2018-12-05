# ccnu-c-plus-plus
《面向对象程序设计》C++ 胡老师班级实验课上机作业

#### 第二次上机

* [求一元二次方程的根（含虚根）](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit1-C/quadratic-equation.cpp) <br>考察：签到题，C 基础，C++无关

* [设计圆类和数组，求不同大小的圆的总面积](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit2-class-and-object/Circles.cpp) <br>考察：C++类与对象入门；构造函数；类的数组

* [N个小孩，从第W开始报数，第S个出列，求出列顺序](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit2-class-and-object/foo.cpp) <br>考察：用类实现循环链表数据结构 

#### 第三次上机

* [设计 MyInteger 类，判断奇偶性，判断是否素数、是否相等](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit3-constructor/MyInteger.cpp) <br>考察：const、static 成员函数；素数的判定
  
* [设计 StackOfIntegers 类，实现堆栈的操作](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit3-constructor/StackOfIntegers.cpp) <br>考察：顺序栈简单的数据结构（链栈也可以）
  
* [使用前面两个类，写 getDivision 函数，把非素数拆分为素数的乘积形式，从大到小输出（使用栈）](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit3-constructor/GetDivision.cpp) <br>考察：类作为形参的传递，拷贝构造函数

#### 第四次上机

* [设计 Rational 类，包含分子分母，实现分数的四则运算（注意化简）、大小比较、相等比较，返回分数值的整数形式/小数形式，使用 string 输出结果](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit4-overload-operator/Rational.cpp) <br>考察：分数类的化简（辗转相除法）；分数的运算；分母、除数的判断细节；拷贝构造函数；stringstream
  
* [设计 Rational 类，实现简单的（+ - * /）运算符重载](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit4-overload-operator/overloadOperator.cpp) <br>考察：运算符重载入门：重载为成员函数/重载为普通的函数，注意参数个数

#### 第五次上机

* [给出主函数，补写 CArray 类，使之运行](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit4-overload-operator/CArray.cpp) <br>考察：补写可变长度数组的类（动态分配内存），重载运算符 ```=[]```，补写各种成员函数，补写拷贝构造函数（memcpy）等等……
  
* [设计 Shape 类，设计 Rectangle、Circle 类用于继承 Shape类，计算矩形圆形的面积，和判断两个矩形是否相同](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit5-inheritance/Shape.cpp) <br>考察：继承和派生的入门，重载运算符```==```  

#### 第六次上机

* [设计二元组 MyPoint 类，求两点间距离，再设计 ThreeDPoint 类，继承  MyPoint](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit5-inheritance/ThreeDPoint.cpp) <br>考察：继承和派生，protected 成员变量的使用
* [输入一定格式的图形参数，按照面积从小到大输出(二分查找实现) ，注意可拓展性](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit6-polymorphism/ShapeRCT.cpp) by @gl14916 <br>考察：纯虚函数，多态的写法
* [上一题的快排实现](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit6-polymorphism/Makito-Shapes.cpp) by @SumiMakito<br>考察：基类指针数组

#### 第七次上机

* [补写函数实现规定输出](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit6-polymorphism/DoFun.cpp) <br>考察：virtual 的用法
* [寻找两个 string 公有字符](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit7-class-string/common.cpp) <br>考察：String 类简单用法
* [判断 string 是否回文](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit7-class-string/isPalindrome.cpp) <br>考察：String 类简单用法
* [自己手动实现一个 String 类，重写函数](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit7-class-string/string.cpp) <br>考察：这道题太刺激了！我非常喜欢orz

#### 期中检测

* [对文件进行拷贝，要求写成命令行模式](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit8-file/copyFile2.cpp) <br>考察：文件操作
* [设计 Complex 类，实现虚数 + - & / += -= 「」 ++ -- ++ -- << >> 等等运算符重载](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit4-overload-operator/Complex.cpp) <br>考察：运算符重载

#### 第八次上机

* [设计函数模板 compareArray 比较数组是否是有序的](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit9-template/compareArray.cpp) <br>考察：template
* [补充 ArraySum 模板，实现要求的输出](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit9-template/ArraySum.cpp)  by @gl14916<br>考察：template、数组指针
* [设计类模板 Stack 并实现栈的功能](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit9-template/stack.cpp) <br>考察：类模板、stack 功能

#### 第九次上机

* [设计函数 F，实现规定输出结果](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit9-template/F.cpp) <br>考察：函数指针、函数模板
* [使用 list 实现固定输出](https://github.com/wwyqianqian/ccnu-c-plus-plus/blob/master/unit10-STL/lists.cpp) <br>考察：STL 的使用、list、迭代器等等