#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <stack>
#include <random>

#include "darray.h"
#include "list.h"
#include "tree.h"

class Timer {
    typedef std::chrono::high_resolution_clock clock_t;
    typedef std::chrono::duration<double, std::ratio<1>> second_t;
    std::chrono::time_point<clock_t> t_start;
public:
    Timer() {
        t_start = clock_t::now();
    }
    double get_elapsed() {
        return std::chrono::duration_cast<second_t>(clock_t::now() - t_start).count();
    }
};

double test1(std::size_t n)
{
    std::vector<int> ints;
    for (int i = 0; i < n; i++) {
        ints.push_back(i);
    }
    Timer timer;
    ints.pop_back();
    return timer.get_elapsed();
}

double test2(std::size_t n)
{
    Dynamic<int> ints;
    for (int i = 0; i < n; i++) {
        ints.append(i);
    }
    Timer timer;
    ints.remove(n-1);
    return timer.get_elapsed();
}

void test3() {
    ListDouble<int> list;
    for (int i = 0; i < 20; i++) {
        list.push_front(i);
    }
    for (auto it = list.front; it != nullptr; it=it->next) {
        std::cout << it->value << std::endl;
    }
    list.reverse();
    for (auto it = list.front; it != nullptr; it=it->next) {
        std::cout << it->value << std::endl;
    }

    int i = 0;
    auto it = list.front;
    while (it != nullptr) {
        if (i%3==0) {
            auto to_remove = it;
            it = it->next;
            list.remove(to_remove);
        } else {
            it = it->next;
        }
        i++;
    }
    for (auto it = list.front; it != nullptr; it=it->next) {
        std::cout << it->value << std::endl;
    }
}

void test4()
{
    Tree<double> tree;
    std::default_random_engine generator;
    auto distribution = std::uniform_real_distribution<double>(0, 10);

    for (std::size_t i = 0; i < 100; i++) {
        tree.insert(distribution(generator));
    }

    tree.traverse([](Tree<double>::Node *node) {
        std::cout << node->value << std::endl;
    });

    double sum = tree.accumulate<double>(
        [](Tree<double>::Node *node, double sum) {
            return sum + node->value;
    }, 0);
    std::cout << sum << std::endl;

    // tree.remove(tree.root->right->left);
}

int main()
{
    test4();
    // typedef std::chrono::high_resolution_clock clock_t;
    // typedef std::chrono::duration<double, std::ratio<1>> second_t;

    // std::chrono::time_point<clock_t> start;

    // double elapsed;
    // for (std::size_t n = 1; n < 10000; n++) {
    //     std::cout << n << " " << 1e6*test1(n) << std::endl;
    // }
    return 0;
}
