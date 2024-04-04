#pragma once
#include <utility>
#include <cassert>
#include <random>

extern std::default_random_engine generator;
extern std::uniform_int_distribution<size_t> distribution;

template<typename T>
class rgrowned;

template<typename T>
class random_gref;

template<typename T>
class random_gref_guard;

template<typename T>
class random_gref {
public:
   inline random_gref(rgrowned<T>* own_) :
        own(own_),
        rememberedKey(own_->currentKey) {}
   inline ~random_gref() {}

   inline random_gref_guard<T> open() {
        return random_gref_guard<T>(own, rememberedKey);
    }

private:
    size_t rememberedKey;
    rgrowned<T>* own;
};

template<typename T>
class random_gref_guard {
public:
    inline random_gref_guard(rgrowned<T>* own_, size_t rememberedKey) :
        own(own_) {
        assert(rememberedKey == own->currentKey);
        assert(own->present);
        own->present = false;
    }
    inline ~random_gref_guard() {
        own->present = true;
    }

    inline T& operator*() { return own->contents; }
    inline const T& operator*() const { return own->contents; }
    inline T* operator->() { return &own->contents; }
    inline const T* operator->() const { return &own->contents; }

private:
    rgrowned<T>* own;
};

template<typename T>
class rgrowned {
public:
    inline rgrowned(T contents_) :
        present(true),
        currentKey(distribution(generator)),
        contents(std::move(contents_)) {}
    inline ~rgrowned() {
        assert(present);
    }

    inline random_gref<T> ref() {
        return random_gref<T>(this);
    }

private:
    friend class random_gref<T>;
    friend class random_gref_guard<T>;

    bool present : 1;
    size_t currentKey : 63;
    T contents;
};

template<typename T, typename... P>
inline rgrowned<T> make_rgrowned(P&&... params) {
    return rgrowned<T>(T(std::forward<P>(params)...));
}
