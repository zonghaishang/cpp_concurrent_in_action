#include <mutex>
#include <list>
#include <iostream>
#include <algorithm>

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value)
{
    std::lock_guard guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find)
{
    std::lock_guard guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

void list_values()
{
    std::lock_guard guard(some_mutex);

    std::cout << std::endl;
    std::cout << "List values: " << std::endl;
    for (auto begin = some_list.begin(), end = some_list.end(); begin != end; begin++)
    {
        std::cout << *begin << " ";
    }

    std::cout << std::endl;
}

int main()
{
    add_to_list(1);
    add_to_list(2);
    list_values();
    std::cout << "contains 2 ? " << list_contains(2) << std::endl;
}