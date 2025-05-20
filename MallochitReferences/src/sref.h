#pragma once
#include <atomic>

using namespace std;

template<typename T>
class sref;

template<typename T>
class sdata;

template<typename T>
class sref {
public:
    inline sref(sdata<T>* data_) :
        data(data_) {
        data->refCount++;
    }

	inline sref(sref&& other_) :
		data(other_.data) {}

	inline sref(const sref& other_) :
		data(other_.data) {
		data->refCount++;
	}

	inline ~sref() {
		data->refCount--;
		if (data->refCount == 0) {
			delete data;
		}
	}

    inline atomic<T>& operator*() { return data->contents; }
    inline const atomic<T>& operator*() const { return data->contents; }
    inline atomic<T>* operator->() { return &data->contents; }
    inline const atomic<T>* operator->() const { return &data->contents; }

private:
	sdata<T>* data;
};

template<typename T>
class sdata {
public:
    template<typename... P>
    inline sdata(P&&... params) :
        refCount(0),
        contents(std::forward<P>(params)...) {}
   
    inline sref<T> ref() {
        return sref<T>(this);
    }

private:
    friend class sref<T>;

    atomic_ullong refCount;
    atomic<T> contents;
};

template<typename T, typename... P>
inline sref<T> make_sref(P&&... params) {
    return sref<T>(new sdata<T>(T(std::forward<P>(params)...)));
}