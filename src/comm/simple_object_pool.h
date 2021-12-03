//
// Created by fanyan on 2021/12/3.
//

#ifndef TDD_DEV_SIMPLE_OBJECT_POOL_H
#define TDD_DEV_SIMPLE_OBJECT_POOL_H

#include <vector>

template<typename T>
class SimpleObjectPool {
public:
    SimpleObjectPool(int pool_size = 64) : pool_size_(pool_size) {
        MakePool();
    }
    
    ~SimpleObjectPool() {
        for (typename std::vector<T *>::iterator it = pool_.begin(); it != pool_.end(); ++it) {
            delete *it;
        }
    }
    
    T *Get() {
        if (pool_.empty()) MakePool();
        
        T *ret = pool_.back();
        pool_.pop_back();
        return ret;
    }
    
    void Return(T *old) {
        if (old == nullptr) return;
        old->~T();
        pool_.push_back(old);
    }
    
    std::string ToString() const {
        std::string ret;
        ret.reserve(64);
        
        ret.append("{");
        ret.append("pool_size=").append(std::to_string(pool_size_));
        ret.append("}");
        
        return ret;
    }

private:
    SimpleObjectPool(const SimpleObjectPool &);
    
    SimpleObjectPool &operator=(const SimpleObjectPool &);
    
    void MakePool() {
        for (int i = 0; i < pool_size_; i++) {
            pool_.push_back(new T());
        }
    }
    
    const int pool_size_;
    std::vector<T *> pool_;
};

#endif //TDD_DEV_SIMPLE_OBJECT_POOL_H