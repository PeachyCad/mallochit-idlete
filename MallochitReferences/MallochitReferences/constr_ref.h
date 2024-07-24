#pragma once
#include <utility>
#include <random>
#include "release_assert.h"
#include "random_gref.h"

#ifdef NDEBUG
#define crowned rgrowned
#define constr_ref random_gref
#define constr_ref_guard random_gref_guard
#define make_crowned make_rgrowned
#else
#define crowned _crowned
#define constr_ref _constr_ref
#define constr_ref_guard _constr_ref_guard
#define make_crowned _make_crowned
#endif // NDEBUG


template<typename T>
class _crowned;

template<typename T>
class _constr_ref;

template<typename T>
class _constr_ref_guard;

template<typename T>
class _constr_ref {
public:
    inline _constr_ref(_crowned<T>* own_) :
        own(own_) {
        own->refCount++;
    }
    inline ~_constr_ref() {
        own->refCount--;
    }

    inline _constr_ref_guard<T> open() {
        return _constr_ref_guard<T>(own);
    }

private:
    _crowned<T>* own;
};

template<typename T>
class _constr_ref_guard {
public:
    inline _constr_ref_guard(_crowned<T>* own_) :
        own(own_) {
        release_assert(own->present);
        own->present = false;
    }
    inline ~_constr_ref_guard() {
        own->present = true;
    }

    inline T& operator*() { return own->contents; }
    inline const T& operator*() const { return own->contents; }
    inline T* operator->() { return &own->contents; }
    inline const T* operator->() const { return &own->contents; }

private:
    _crowned<T>* own;
};

template<typename T>
class _crowned {
public:
    inline _crowned(T contents_) :
        present(true),
        refCount(0),
        contents(std::move(contents_)) {}
    inline ~_crowned() {
        release_assert(present);
        release_assert(refCount == 0);
    }

    inline _constr_ref<T> ref() {
        return _constr_ref<T>(this);
    }

private:
    friend class _constr_ref<T>;
    friend class _constr_ref_guard<T>;

    bool present : 1;
    size_t refCount : 63;
    T contents;
};

template<typename T, typename... P>
inline _crowned<T> _make_crowned(P&&... params) {
    return _crowned<T>(T(std::forward<P>(params)...));
}