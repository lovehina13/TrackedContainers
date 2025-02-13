#include "TrackedContainers.h"

#include <cstdlib>

void trackOnClear() {
    TrackedVector<int> vector = {1, 2, 3};
    TrackedDeque<int> deque = {1, 2, 3};
    TrackedList<int> list = {1, 2, 3};
    TrackedSet<int> set = {1, 2, 3};
    TrackedMap<int, int> map = {{1, 1}, {2, 2}, {3, 3}};

    vector.clear();
    deque.clear();
    list.clear();
    set.clear();
    map.clear();
}

void trackOnDeletion() {
    TrackedVector<int> vector = {1, 2, 3};
    TrackedDeque<int> deque = {1, 2, 3};
    TrackedList<int> list = {1, 2, 3};
    TrackedSet<int> set = {1, 2, 3};
    TrackedMap<int, int> map = {{1, 1}, {2, 2}, {3, 3}};
    TrackedStack<int> stack = {1, 2, 3};
    TrackedQueue<int> queue = {1, 2, 3};
}

int main() {
    trackOnClear();
    trackOnDeletion();
    return EXIT_SUCCESS;
}
