# [attribute](https://zh.cppreference.com/w/cpp/language/attributes)

## noreturn

指示函数不返回。

此属性仅应用到函数声明中正在声明的函数名。若拥有此属性的函数实际上返回，则行为未定义。

若函数的任何声明指定此属性，则其首个声明必须指定它。若函数在一个翻译单元中声明为带 `[[noreturn]]` 属性，而同一函数在另一翻译单元中声明为不带 `[[noreturn]]` 属性，则程序非良构；不要求诊断。

```c++
[[ noreturn ]] void f() {
  throw "error";
  // OK
}
 
void q [[ noreturn ]] (int i) {
  // 若以 <= 0 的参数调用则行为未定义
  if (i > 0) {
    throw "positive";
  }
}
 
// void h() [[noreturn]]; // 错误：属性应用到 h 的函数类型，而非 h 自身
```

## deprecated

指示允许使用声明有此属性的名称或实体，但因故不鼓励使用。编译器通常会对其使用情况发出警告。若指定了 *字符串字面量*，则它通常被包含于警告中。

声明时未弃用的名字可被重声明为 `deprecated`。声明为 `deprecated` 的名字不能通过重声明它而不带此属性变为未弃用。

```c++
#include <iostream>
 
[[deprecated]]
void TriassicPeriod() {
    std::clog << "Triassic Period: [251.9 - 208.5] million years ago.\n";
}
 
[[deprecated("Use NeogenePeriod() instead.")]]
void JurassicPeriod() {
    std::clog << "Jurassic Period: [201.3 - 152.1] million years ago.\n";
}
 
int main()
{
    TriassicPeriod();
    JurassicPeriod();
}
```

## fallthrough

指示从前一标号直落是有意的，而在发生直落时给出警告的编译器不应诊断它。

仅可应用到[空语句](https://zh.cppreference.com/w/cpp/language/statements#.E8.A1.A8.E8.BE.BE.E5.BC.8F.E8.AF.AD.E5.8F.A5)以创建*直落语句（ fallthrough statement ）*： [[fallthrough]]; 。

直落语句仅可用于 [`switch`](https://zh.cppreference.com/w/cpp/language/switch) 语句中，其中待执行的下个语句是该 switch 语句的带 case 或 default 标号的语句。若直落语句在循环中，则下个（带标号）语句必须是该循环的同一迭代的一部分。

指示从前一标号直落是有意的，而在发生直落时给出警告的编译器不应诊断它。

```c++
void f(int n) {
  void g(), h(), i();
  switch (n) {
    case 1:
    case 2:
      g();
     [[fallthrough]];
    case 3: // 直落时不警告
      h();
    case 4: // 编译器可在发生直落时警告
      if(n < 3) {
          i();
          [[fallthrough]]; // OK
      }
      else {
          return;
      }
    case 5:
      while (false) {
        [[fallthrough]]; // 非良构：下一语句不是同一迭代的一部分
      }
    case 6:
      [[fallthrough]]; // 非良构：无后继的 case 或 default 标号
  }
}
```

## nodiscard

鼓励编译器在返回值被舍弃时发布警告。

若从并非转型到 void 的[弃值表达式](https://zh.cppreference.com/w/cpp/language/expressions#.E5.BC.83.E5.80.BC.E8.A1.A8.E8.BE.BE.E5.BC.8F)中，调用声明为 `nodiscard` 的函数，或调用按值返回声明为 `nodiscard` 的枚举或类的函数，则鼓励编译器发布警告。

```c++
struct [[nodiscard]] error_info { };
struct [[nodiscard("reason")]] error_info1 { };
error_info enable_missile_safety_mode();

void test_missiles() {
   enable_missile_safety_mode(); // 编译器可在舍弃 nodiscard 值时发布警告
}
error_info1& foo();
void f1() {
    foo(); // 并非按值返回 nodiscard 类型，无警告
}
```

## maybe_unused

抑制针对未使用实体的警告。

```c++
#include <cassert>
 
[[maybe_unused]] void f([[maybe_unused]] bool thing1,
                        [[maybe_unused]] bool thing2)
{
   [[maybe_unused]] bool b = thing1 && thing2;
   assert(b); // 发行模式中，assert 在编译中被去掉，因而未使用 b
              // 无警告，因为它被声明为 [[maybe_unused]]
} // 未使用参数 thing1 与 thing2，无警告
```

