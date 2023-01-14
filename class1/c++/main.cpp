#include "singly_list.h"

constexpr const int N = 10;

int main() {
    SinglyList list{};

    for (int i = 0; i < N; ++i) {
        list.insert_head(i+1);
    }

    list.insert_tail(11);
    list.insert(nullptr, 12);
    list.insert(list.search_previous(12), 100);
    list.insert(list.search(1), 8273);
    list.remove(100);
    list.remove(9);
    list.remove(10000);

    list.print();
}
