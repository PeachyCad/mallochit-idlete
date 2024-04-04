#pragma once
#include <utility>
#include <cassert>
#include <random>

template<typename T>
class crowned;

template<typename T>
class constr_ref;

template<typename T>
class constr_ref_guard;

template<typename T>
class constr_ref {
public:
    inline constr_ref(crowned<T>* own_) :
        own(own_) {
        own->refCount++;
    }
    inline ~constr_ref() {
        own->refCount--;
    }

    inline constr_ref_guard<T> open() {
        return constr_ref_guard<T>(own);
    }

private:
    crowned<T>* own;
};

template<typename T>
class constr_ref_guard {
public:
    inline constr_ref_guard(crowned<T>* own_) :
        own(own_) {
        assert(own->present);
        own->present = false;
    }
    inline ~constr_ref_guard() {
        own->present = true;
    }

    inline T& operator*() { return own->contents; }
    inline const T& operator*() const { return own->contents; }
    inline T* operator->() { return &own->contents; }
    inline const T* operator->() const { return &own->contents; }

private:
    crowned<T>* own;
};

template<typename T>
class crowned {
public:
    inline crowned(T contents_) :
        present(true),
        refCount(0),
        contents(std::move(contents_)) {}
    inline ~crowned() {
        assert(present);
        assert(refCount == 0);
    }

    inline constr_ref<T> ref() {
        return constr_ref<T>(this);
    }

private:
    friend class constr_ref<T>;
    friend class constr_ref_guard<T>;

    bool present : 1;
    size_t refCount : 63;
    T contents;
};

template<typename T, typename... P>
inline crowned<T> make_crowned(P&&... params) {
    return crowned<T>(T(std::forward<P>(params)...));
}