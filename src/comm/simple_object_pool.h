//
// Created by fanyan on 2021/12/3.
//

#ifndef TDD_DEV_SIMPLE_OBJECT_POOL_H
#define TDD_DEV_SIMPLE_OBJECT_POOL_H

#include <vector>

template<typename T>
class SimpleObjectPool {
public:
    SimpleObjectPool(int make_pool_size = 64) : make_pool_size_(make_pool_size) {
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
        old->ReSet();
        pool_.push_back(old);
    }
    
    std::string ToString() {
        std::string ret;
        ret.reserve(64);
        
        ret.append("{");
        ret.append("pool_size=").append(std::to_string(pool_.size()));
        ret.append(",make_pool_size=").append(std::to_string(make_pool_size_));
        ret.append("}");
        
        return ret;
    }

private:
    SimpleObjectPool(const SimpleObjectPool &) = delete;
    
    SimpleObjectPool &operator=(const SimpleObjectPool &) = delete;
    
    SimpleObjectPool(const SimpleObjectPool &&) = delete;
    
    SimpleObjectPool &operator=(const SimpleObjectPool &&) = delete;
    
    void MakePool() {
        for (int i = 0; i < make_pool_size_; ++i) {
            pool_.push_back(new T());
        }
    }
    
    const int make_pool_size_;
    std::vector<T *> pool_;
};

template<typename T>
class ObjectPoolTool {
public:
    explicit ObjectPoolTool(SimpleObjectPool<T> &src) : sop_(src), object_ptr_(nullptr) {
    }
    
    ~ObjectPoolTool() {
        sop_.Return(object_ptr_);
    }
    
    T *Get() {
        object_ptr_ = sop_.Get();
        return object_ptr_;
    }

private:
    ObjectPoolTool(const ObjectPoolTool &) = delete;
    
    ObjectPoolTool &operator=(const ObjectPoolTool &) = delete;
    
    SimpleObjectPool<T> &sop_;
    T *object_ptr_;
};

#endif //TDD_DEV_SIMPLE_OBJECT_POOL_H