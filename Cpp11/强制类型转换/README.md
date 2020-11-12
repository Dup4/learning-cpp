# 强制类型转换

## static_cast

- 用法：static_cast < type-id > (expression)
- 说明：该运算符把 expression 转换为 type-id 类型，但没有运行时类型检查来保证转换的安全性。
- static_cast 将一个值以符合逻辑的方式转换，该操作符用于非多态类型的转换，任何标准转换都可以使用他，即 static_cast 可以把 int 转换为 double，但不能把两个不相关的类对象进行转换，比如类 A 不能转换为一个不相关的类 B 类型。static_cast 是非多态转换，本质上是传统c语言强制转换的替代品。
- 用于类层次结构中基类和子类之间指针或引用的转换。进行上行转换（把子类的指针或引用转换成基类表示）是安全的；进行下行转换（把基类指针或引用转换成子类指针或引用）时，由于没有动态类型检查，所以是不安全的。
- 用于基本数据类型之间的转换，如把 int 转换成 char，把 int 转换成 enum。这种转换的安全性也要开发人员来保证。
- 把void指针转换成目标类型的指针(不安全!!)
- 把任何类型的表达式转换成 void 类型。
注意：static_cast 不能转换掉 expression 的 const、volitale、或者 __unaligned 属性。

## dynamic_cast

- 用法：dynamic_cast < type-id > (expression) 
- 说明：该运算符把 expression 转换成 type-id 类型的对象。type-id 必须是类的指针、类的引用或者 `void *` ；如果 type-id 是类指针类型，那么 expression 也必须是一个指针，如果type-id 是一个引用，那么 expression 也必须是一个引用。
- dynamic_cast 是唯一一个在运行时进行类型检测的转换，可以使用它来检验多个动态对象，该转换一般用于含有虚函数的基类和派生类直接。
  

## reinterpret_cast

- 用法：reinpreter_cast<type-id> (expression)
- 说明：type-id必须是一个指针、引用、算术类型、函数指针或者成员指针。它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针（先把一个指针转换成一个整数，在把该整数转换成原类型的指针，还可以得到原先的指针值），使用该操作符的危险性较高，一般不应使用该操作符。

## const_cast

- 用法：const_cast<type_id> (expression)
- 说明：该运算符用来修改类型的const或volatile属性，const_cast最常用的用途就是删除const属性，如果某个变量在大多数时候是常量，而在某个时候又是需要修改的，这时就可以使用const_cast操作符了。除了const 或volatile修饰之外， type_id和expression的类型是一样的。
- 常量指针被转化成非常量指针，并且仍然指向原来的对象；常量引用被转换成非常量引用，并且仍然指向原来的对象；常量对象被转换成非常量对象。