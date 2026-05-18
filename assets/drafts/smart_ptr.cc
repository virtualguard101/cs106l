#include <memory>
#include <iostream>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource released\n"; }
    void use() { std::cout << "Resource used\n"; }
};

void useUniquePtr() {
    // 创建 unique_ptr
    std::unique_ptr<Resource> res = std::make_unique<Resource>();
    res->use();

    // 转移所有权
    std::unique_ptr<Resource> res2 = std::move(res);
    res2->use();

    // res 现在为 nullptr
    if (!res) {
        std::cout << "res is nullptr\n";
    }

    // res2 离开作用域时，Resource 会被自动释放
}

void useSharedPtr() {
    // 创建 shared_ptr
    std::shared_ptr<Resource> res1 = std::make_shared<Resource>();
    {
        std::shared_ptr<Resource> res2 = res1; // 共享所有权
        std::cout << "Reference count: " << res1.use_count() << "\n"; // 输出 2
    }
    // res2 离开作用域，引用计数减少
    std::cout << "Reference count: " << res1.use_count() << "\n"; // 输出 1

    // res1 离开作用域时，Resource 会被自动释放
}

void useWeakPtr() {
    std::weak_ptr<Resource> weak;
    {
        std::shared_ptr<Resource> shared = std::make_shared<Resource>();
        weak = shared;

        // 从 weak_ptr 创建 shared_ptr
        if (auto temp = weak.lock()) {
            temp->use();
        }
    }
    // shared 离开作用域，Resource 被释放

    // 尝试从 weak_ptr 创建 shared_ptr
    if (auto temp = weak.lock()) {
        temp->use();
    } else {
        std::cout << "Resource no longer exists\n";
    }
}

int main() {
    std::cout << "=== Using unique_ptr ===\n";
    useUniquePtr();

    std::cout << "\n=== Using shared_ptr ===\n";
    useSharedPtr();

    std::cout << "\n=== Using weak_ptr ===\n";
    useWeakPtr();

    return 0;
}
