#pragma once

#include <deque>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <source_location>
#include <stack>
#include <typeinfo>
#include <vector>

// Note: No TrackedArray (fixed size)

template <typename T> class TrackedVector : public std::vector<T> {
  public:
    std::source_location location;
    TrackedVector(std::source_location caller = std::source_location::current()) : location(caller) {}
    TrackedVector(const TrackedVector& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedVector(TrackedVector&& other, std::source_location caller = std::source_location::current()) noexcept {
        *this = std::move(other);
        location = caller;
    }
    TrackedVector(const std::initializer_list<T>& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedVector& operator=(const TrackedVector& other) = default;
    TrackedVector& operator=(TrackedVector&& other) noexcept = default;
    TrackedVector& operator=(const std::initializer_list<T>& other) {
        std::vector<T>::clear();
        for (const auto& item : other) {
            std::vector<T>::emplace_back(item);
        }
        return *this;
    }
    ~TrackedVector() {
        size_t size = std::vector<T>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' vector deletion with size " << size << ", type size " << sizeof(T) << ", data size " << size * sizeof(T) << ", created at "
                      << location.file_name() << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
    }
    void clear() noexcept {
        size_t size = std::vector<T>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' vector clear with size " << size << ", type size " << sizeof(T) << ", data size " << size * sizeof(T) << ", created at "
                      << location.file_name() << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
        std::vector<T>::clear();
    }
};

template <typename T> class TrackedDeque : public std::deque<T> {
  public:
    std::source_location location;
    TrackedDeque(std::source_location caller = std::source_location::current()) : location(caller) {}
    TrackedDeque(const TrackedDeque& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedDeque(TrackedDeque&& other, std::source_location caller = std::source_location::current()) noexcept {
        *this = std::move(other);
        location = caller;
    }
    TrackedDeque(const std::initializer_list<T>& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedDeque& operator=(const TrackedDeque& other) = default;
    TrackedDeque& operator=(TrackedDeque&& other) noexcept = default;
    TrackedDeque& operator=(const std::initializer_list<T>& other) {
        std::deque<T>::clear();
        for (const auto& item : other) {
            std::deque<T>::emplace_back(item);
        }
        return *this;
    }
    ~TrackedDeque() {
        size_t size = std::deque<T>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' deque deletion with size " << size << ", type size " << sizeof(T) << ", data size " << size * sizeof(T) << ", created at "
                      << location.file_name() << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
    }
    void clear() noexcept {
        size_t size = std::deque<T>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' deque clear with size " << size << ", type size " << sizeof(T) << ", data size " << size * sizeof(T) << ", created at "
                      << location.file_name() << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
        std::deque<T>::clear();
    }
};

template <typename T> class TrackedList : public std::list<T> {
  public:
    std::source_location location;
    TrackedList(std::source_location caller = std::source_location::current()) : location(caller) {}
    TrackedList(const TrackedList& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedList(TrackedList&& other, std::source_location caller = std::source_location::current()) noexcept {
        *this = std::move(other);
        location = caller;
    }
    TrackedList(const std::initializer_list<T>& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedList& operator=(const TrackedList& other) = default;
    TrackedList& operator=(TrackedList&& other) noexcept = default;
    TrackedList& operator=(const std::initializer_list<T>& other) {
        std::list<T>::clear();
        for (const auto& item : other) {
            std::list<T>::emplace_back(item);
        }
        return *this;
    }
    ~TrackedList() {
        size_t size = std::list<T>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' list deletion with size " << size << ", type size " << sizeof(T) << ", data size " << size * sizeof(T) << ", created at "
                      << location.file_name() << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
    }
    void clear() noexcept {
        size_t size = std::list<T>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' list clear with size " << size << ", type size " << sizeof(T) << ", data size " << size * sizeof(T) << ", created at " << location.file_name()
                      << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
        std::list<T>::clear();
    }
};

template <typename T> class TrackedSet : public std::set<T> {
  public:
    std::source_location location;
    TrackedSet(std::source_location caller = std::source_location::current()) : location(caller) {}
    TrackedSet(const TrackedSet& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedSet(TrackedSet&& other, std::source_location caller = std::source_location::current()) noexcept {
        *this = std::move(other);
        location = caller;
    }
    TrackedSet(const std::initializer_list<T>& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedSet& operator=(const TrackedSet& other) = default;
    TrackedSet& operator=(TrackedSet&& other) noexcept = default;
    TrackedSet& operator=(const std::initializer_list<T>& other) {
        std::set<T>::clear();
        for (const auto& item : other) {
            std::set<T>::insert(item);
        }
        return *this;
    }
    ~TrackedSet() {
        size_t size = std::set<T>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' set deletion with size " << size << ", type size " << sizeof(T) << ", data size " << size * sizeof(T) << ", created at "
                      << location.file_name() << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
    }
    void clear() noexcept {
        size_t size = std::set<T>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' set clear with size " << size << ", type size " << sizeof(T) << ", data size " << size * sizeof(T) << ", created at " << location.file_name()
                      << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
        std::set<T>::clear();
    }
};

template <typename T1, typename T2> class TrackedMap : public std::map<T1, T2> {
  public:
    std::source_location location;
    TrackedMap(std::source_location caller = std::source_location::current()) : location(caller) {}
    TrackedMap(const TrackedMap& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedMap(TrackedMap&& other, std::source_location caller = std::source_location::current()) noexcept {
        *this = std::move(other);
        location = caller;
    }
    TrackedMap(const std::initializer_list<std::pair<T1, T2>>& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedMap& operator=(const TrackedMap& other) = default;
    TrackedMap& operator=(TrackedMap&& other) noexcept = default;
    TrackedMap& operator=(const std::initializer_list<std::pair<T1, T2>>& other) {
        std::map<T1, T2>::clear();
        for (const auto& item : other) {
            std::map<T1, T2>::insert(item);
        }
        return *this;
    }
    ~TrackedMap() {
        size_t size = std::map<T1, T2>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' map deletion with size " << size << ", type size " << sizeof(T1) + sizeof(T2) << ", data size " << size * (sizeof(T1) + sizeof(T2))
                      << ", created at " << location.file_name() << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
    }
    void clear() noexcept {
        size_t size = std::map<T1, T2>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' map clear with size " << size << ", type size " << sizeof(T1) + sizeof(T2) << ", data size " << size * (sizeof(T1) + sizeof(T2))
                      << ", created at " << location.file_name() << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
        std::map<T1, T2>::clear();
    }
};

template <typename T> class TrackedStack : public std::stack<T> {
  public:
    std::source_location location;
    TrackedStack(std::source_location caller = std::source_location::current()) : location(caller) {}
    TrackedStack(const TrackedStack& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedStack(TrackedStack&& other, std::source_location caller = std::source_location::current()) noexcept {
        *this = std::move(other);
        location = caller;
    }
    TrackedStack(const std::initializer_list<T>& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedStack& operator=(const TrackedStack& other) = default;
    TrackedStack& operator=(TrackedStack&& other) noexcept = default;
    TrackedStack& operator=(const std::initializer_list<T>& other) {
        while (!std::stack<T>::empty()) {
            std::stack<T>::pop();
        }
        for (const auto& item : other) {
            std::stack<T>::emplace(item);
        }
        return *this;
    }
    ~TrackedStack() {
        size_t size = std::stack<T>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' stack deletion with size " << size << ", type size " << sizeof(T) << ", data size " << size * sizeof(T) << ", created at "
                      << location.file_name() << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
    }
};

template <typename T> class TrackedQueue : public std::queue<T> {
  public:
    std::source_location location;
    TrackedQueue(std::source_location caller = std::source_location::current()) : location(caller) {}
    TrackedQueue(const TrackedQueue& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedQueue(TrackedQueue&& other, std::source_location caller = std::source_location::current()) noexcept {
        *this = std::move(other);
        location = caller;
    }
    TrackedQueue(const std::initializer_list<T>& other, std::source_location caller = std::source_location::current()) {
        *this = other;
        location = caller;
    }
    TrackedQueue& operator=(const TrackedQueue& other) = default;
    TrackedQueue& operator=(TrackedQueue&& other) noexcept = default;
    TrackedQueue& operator=(const std::initializer_list<T>& other) {
        while (!std::queue<T>::empty()) {
            std::queue<T>::pop();
        }
        for (const auto& item : other) {
            std::queue<T>::emplace(item);
        }
        return *this;
    }
    ~TrackedQueue() {
        size_t size = std::queue<T>::size();
        if (size > 0) {
            std::cout << "'" << typeid(this).name() << "' queue deletion with size " << size << ", type size " << sizeof(T) << ", data size " << size * sizeof(T) << ", created at "
                      << location.file_name() << ":" << location.line() << ": " << location.function_name() << std::endl;
        }
    }
};
