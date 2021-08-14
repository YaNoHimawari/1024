# 目录遍历(c++17)

```#include <filesystem>```

```c++
std::filesystem::path path("路径");
if(!std::filesystem::exists(path))
{
  	// 异常处理
}

std::filesystem::directory_entry dir(path);
if(!dir.is_directory())
{
  	// 异常处理
}

// 递归遍历至最深层路径
for(const auto& entry : std::filesystem::recursive_directory_iterator(dir))
{
  	// 文件
    if(entry.is_regular_file())
    {
      	// ...
    }
    // 文件夹
    if(entry.is_directory())
    {
      	// ...
    }
}
```

# 目录操作(c++17)

```#include <filesystem>```

```c++
// 位于std::filesystem命名空间下

void copy(const path& from, const path& to) ：目录复制

path absolute(const path& pval, const path& base = current_path()) ：获取相对于base的绝对路径

bool create_directory(const path& pval) ：当目录不存在时创建目录

bool create_directories(const path& pval) ：形如/a/b/c这样的，如果都不存在，创建目录结构

bool exists(const path& pval) ：用于判断path是否存在

uintmax_t file_size(const path& pval) ：返回目录的大小

file_time_type last_write_time(const path& pval) ：返回目录最后修改日期的file_time_type对象

bool remove(const path& pval) ：删除目录

uintmax_t remove_all(const path& pval) ：递归删除目录下所有文件，返回被成功删除的文件个数

void rename(const path& from, const path& to) ：移动文件或者重命名
```

