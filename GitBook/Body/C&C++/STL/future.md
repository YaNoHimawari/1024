# [future](https://zh.cppreference.com/w/cpp/header/future)

`#include <future>`

## [promise](https://zh.cppreference.com/w/cpp/thread/promise)

```c++
#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
 
void accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last,
                std::promise<int> accumulate_promise)
{
    int sum = std::accumulate(first, last, 0);
    accumulate_promise.set_value(sum);  // 提醒 future
}
 
void do_work(std::promise<void> barrier)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    barrier.set_value();
}
 
int main()
{
    // 演示用 promise<int> 在线程间传递结果。
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread work_thread(accumulate, numbers.begin(), numbers.end(),
                            std::move(accumulate_promise));
 
    // future::get() 将等待直至该 future 拥有合法结果并取得它
    // 无需在 get() 前调用 wait()
    //accumulate_future.wait();  // 等待结果
    std::cout << "result=" << accumulate_future.get() << '\n';
    work_thread.join();  // wait for thread completion
 
    // 演示用 promise<void> 在线程间对状态发信号
    std::promise<void> barrier;
    std::future<void> barrier_future = barrier.get_future();
    std::thread new_work_thread(do_work, std::move(barrier));
    barrier_future.wait();
    new_work_thread.join();
}
```

output:

```
result=21
```

## [packaged_task](https://zh.cppreference.com/w/cpp/thread/packaged_task)

```c++
#include <iostream>
#include <cmath>
#include <thread>
#include <future>
#include <functional>
 
int f(int x, int y) { return std::pow(x,y); }
 
void task_lambda()
{
    std::packaged_task<int(int,int)> task([](int a, int b) {
        return std::pow(a, b); 
    });
    std::future<int> result = task.get_future();
 
    task(2, 9);
 
    std::cout << "task_lambda:\t" << result.get() << '\n';
}
 
void task_bind()
{
    std::packaged_task<int()> task(std::bind(f, 2, 11));
    std::future<int> result = task.get_future();
 
    task();
 
    std::cout << "task_bind:\t" << result.get() << '\n';
}
 
void task_thread()
{
    std::packaged_task<int(int,int)> task(f);
    std::future<int> result = task.get_future();
 
    std::thread task_td(std::move(task), 2, 10);
    task_td.join();
 
    std::cout << "task_thread:\t" << result.get() << '\n';
}
 
int main()
{
    task_lambda();
    task_bind();
    task_thread();
}
```

output:

```
task_lambda: 512
task_bind:   2048
task_thread: 1024
```

## [async](https://zh.cppreference.com/w/cpp/thread/async)

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <string>
#include <mutex>
 
std::mutex m;
struct X {
    void foo(int i, const std::string& str) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << str << ' ' << i << '\n';
    }
    void bar(const std::string& str) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << str << '\n';
    }
    int operator()(int i) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << i << '\n';
        return i + 10;
    }
};
 
template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
    auto len = end - beg;
    if (len < 1000)
        return std::accumulate(beg, end, 0);
 
    RandomIt mid = beg + len/2;
    auto handle = std::async(std::launch::async,
                             parallel_sum<RandomIt>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}
 
int main()
{
    std::vector<int> v(10000, 1);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
 
    X x;
    // 以默认策略调用 x.foo(42, "Hello") ：
    // 可能同时打印 "Hello 42" 或延迟执行
    auto a1 = std::async(&X::foo, &x, 42, "Hello");
    // 以 deferred 策略调用 x.bar("world!")
    // 调用 a2.get() 或 a2.wait() 时打印 "world!"
    auto a2 = std::async(std::launch::deferred, &X::bar, x, "world!");
    // 以 async 策略调用 X()(43) ：
    // 同时打印 "43"
    auto a3 = std::async(std::launch::async, X(), 43);
    a2.wait();                     // 打印 "world!"
    std::cout << a3.get() << '\n'; // 打印 "53"
} // 若 a1 在此点未完成，则 a1 的析构函数在此打印 "Hello 42"
```

output:

```
The sum is 10000
43
world!
53
Hello 42
```

