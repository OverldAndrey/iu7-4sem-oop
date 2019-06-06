//
// Created by 1 on 05.04.2019.
//

#ifndef LAB02_MY_LIST_H
#define LAB02_MY_LIST_H


#include <vector>
#include <string>
#include <list>
#include <memory>
#include <sstream>

#include "My_list_exception.h"
#include "My_iterator.h"

class Abstract_container
{
protected:
    size_t len = 0;
public:
    virtual size_t length() = 0;
    virtual void clear() = 0;
    virtual ~Abstract_container() = default;
};


template <class T>
class My_list : public Abstract_container
{
private:
    struct elem
    {
        std::unique_ptr<T> data;
        std::shared_ptr<elem> next;
    };

    std::shared_ptr<elem> content;

public:
    class iterator : public My_iterator<T, elem>
    {
    private:
        friend iterator My_list<T>::begin();
        friend iterator My_list<T>::end();

    public:
        std::weak_ptr<elem> get();
    };

    class const_iterator : public My_iterator<T, elem>
    {
    private:
        friend const_iterator My_list<T>::begin() const;
        friend const_iterator My_list<T>::end() const;

    public:
        std::weak_ptr<elem> get() const;
    };

    explicit My_list() = default;
    explicit My_list(T* array, size_t n);
    explicit My_list(std::vector<T> &array);
    explicit My_list(std::list<T> &list);
    My_list(std::initializer_list<T> in_list);
    My_list(My_list<T> &list);

    My_list(double) = delete;
    My_list(float) = delete;

    size_t length() override;
    void push_back(T &el);
    std::unique_ptr<T> pop_back();
    void insert(T &data, size_t pos);
    std::unique_ptr<T> pop(size_t pos);
    void shift(T &el);
    std::unique_ptr<T> unshift();
    My_list<T> &concat(My_list<T> &s2);
    My_list<T> &copy(My_list<T> &list);
    My_list<T> &map(T (*fn)(T &e, size_t i));
    My_list<T> &slice(size_t start = 0, size_t end = 0);
    T reduce(T (*fn)(T &res, T &e, size_t i), T &res);
    char *join(char *div);
    char *join(const char *div);
    std::string join(std::string &div);
    void clear() override;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    My_list<T> &operator +(My_list<T> const &s2);
    My_list<T> &operator =(My_list<T> const &list);
    T &operator [](size_t i);
    T operator [](size_t i) const;

    ~My_list() override;
};


template <class T>
My_list<T>::My_list(T *array, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        this->push_back(array[i]);
    }
}

template <class T>
My_list<T>::My_list(std::vector<T> &array)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        this->push_back(array[i]);
    }
}

template <class T>
My_list<T>::My_list(std::list<T> &list)
{
    for (size_t i = 0; i < list.size(); i++)
    {
        this->push_back(list[i]);
    }
}

template <class T>
My_list<T>::My_list(std::initializer_list<T> in_list)
{
    for (T &el : in_list)
    {
        this->push_back(el);
    }
}

template <class T>
My_list<T>::My_list(My_list<T> &list)
{
    *this = list;
}


template <class T>
size_t My_list<T>::length()
{
    return this->len;
}

template <class T>
void My_list<T>::push_back(T &el)
{
    this->insert(el, this->len);
}

template <class T>
std::unique_ptr<T> My_list<T>::pop_back()
{
    return std::move(this->pop(this->len-1));
}

template <class T>
void My_list<T>::insert(T &data, size_t pos)
{
    iterator iter = this->begin();
    std::unique_ptr<T> d(new T(data));

    if (pos != 0)
    {
        std::shared_ptr<elem> el(new elem);

        for (size_t i = 0; i < pos-1; iter++, i++);

        std::shared_ptr<elem> ins = iter.get().lock()->next;

        iter.get().lock()->next = el;
        el.get()->next = ins;
        el.get()->data = std::move(d);
    }
    else
    {
        std::shared_ptr<elem> el(new elem);

        el.get()->next = iter.get().lock();
        el.get()->data = std::move(d);
        this->content = el;
    }

    this->len++;
}

template <class T>
std::unique_ptr<T> My_list<T>::pop(size_t pos)
{
    if (pos < 0 || pos >= this->len)
        throw Bad_index("List index out of range",
                        __FILE__,
                        __LINE__-2,
                        __func__);

    iterator iter = this->begin();
    std::unique_ptr<T> ret;

    for (size_t i = 0; i < pos-1; iter++, i++);

    if (pos == 0)
    {
        this->content = iter.get().lock()->next;
        ret = std::move(iter.get().lock()->data);
    }
    else
    {
        std::weak_ptr<elem> el = iter.get().lock()->next;
        ret = std::move(el.lock()->data);
        iter.get().lock()->next = el.lock()->next;
    }

    this->len--;

    return std::move(ret);
}

template <class T>
void My_list<T>::shift(T &el)
{
    this->insert(el, 0);
}

template <class T>
std::unique_ptr<T> My_list<T>::unshift()
{
    return std::move(this->pop(0));
}

template <class T>
My_list<T>& My_list<T>::concat(My_list<T> &s2)
{
    return *this + s2;
}

template <class T>
My_list<T>& My_list<T>::copy(My_list<T> &list)
{
    return *this = list;
}

template <class T>
My_list<T> &My_list<T>::map(T (*fn)(T &e, size_t i))
{
    My_list<T> &n_list = *(new My_list<T>);

    for (size_t j = 0; j < this->len; j++)
    {
        n_list.push_back(fn((*this)[j], j));
    }

    return n_list;
}

template <class T>
My_list<T> &My_list<T>::slice(size_t start, size_t end)
{
    if (end <= start)
        throw Bad_index("End index is smaller or equal to Start index",
                __FILE__,
                __LINE__-2,
                __func__);
    if (end < 0 || start < 0 || end >= this->len || start >= this->len)
        throw Bad_index("List index out of range",
                __FILE__,
                __LINE__-2,
                __func__);

    My_list<T> &sl = *(new My_list<T>);
    std::weak_ptr<elem> st = this->content;

    for (size_t i = 0; i < start; st = st.lock()->next, i++);

    for (size_t i = start; i < end; i++)
    {
        sl.push_back(*(st.lock()->data));
        st = st.lock()->next;
    }

    return sl;
}

template <class T>
T My_list<T>::reduce(T (*fn)(T &res, T &e, size_t i), T &res)
{
    auto ret = res;
    for (size_t j = 0; j < this->len; j++)
    {
        ret = fn(ret, (*this)[j], j);
    }

    return ret;
}

template <class T>
char* My_list<T>::join(char *div)
{
    std::string buf(div);
    return this->join(buf).data();
}

template <class T>
char* My_list<T>::join(const char *div)
{
    std::string buf(div);
    return this->join(buf).data();
}

template <class T>
std::string My_list<T>::join(std::string &div)
{
    try
    {
        std::string buf = std::to_string((*this)[0]);
        for (size_t i = 1; i < this->len; i++)
        {
            buf.append(div);
            buf.append(std::to_string((*this)[i]));
        }
        return buf;
    }
    catch (std::logic_error &e)
    {
        std::stringstream ss;
        ss << (*this)[0];
        for (size_t i = 1; i < this->len; i++)
        {
            ss << div;
            ss << (*this)[i];
        }
        return ss.str();
    }

}

template <class T>
void My_list<T>::clear()
{
    std::weak_ptr<elem> prev;
    std::weak_ptr<elem> cur = this->content;

    for (size_t i = 0; i < this->len; i++)
    {
        cur.lock()->data.release();
        prev = cur;
        cur = cur.lock()->next;
        prev.lock().reset();
    }

    this->content = nullptr;
    this->len = 0;
}


template <class T>
typename My_list<T>::iterator My_list<T>::begin()
{
    My_list<T>::iterator it = My_list<T>::iterator();

    it.it = this->content;
    it.ind = 0;

    return it;
}

template <class T>
typename My_list<T>::iterator My_list<T>::end()
{
    My_list<T>::iterator it = My_list<T>::iterator();
    std::weak_ptr<elem> el = this->content;

    for (size_t i = 0; i < this->len-1; el = el.lock()->next, i++);

    it.it = el;
    it.ind = this->len;

    return it;
}

template <class T>
typename My_list<T>::const_iterator My_list<T>::begin() const
{
    My_list<T>::const_iterator it = My_list<T>::const_iterator();

    it.it = this->content;
    it.ind = 0;

    return it;
}

template <class T>
typename My_list<T>::const_iterator My_list<T>::end() const
{
    My_list<T>::const_iterator it = My_list<T>::const_iterator();
    std::weak_ptr<elem> el = this->content;

    for (size_t i = 0; i < this->len-1; el = el.lock()->next, i++);

    it.it = el;
    it.ind = this->len;

    return it;
}


template <class T>
My_list<T> &My_list<T>::operator +(My_list<T> const &s2)
{
    My_list<T> &n_list = *(new My_list<T>);

    for (T &e : *this)
    {
        n_list.push_back(e);
    }

    for (T &e : s2)
    {
        n_list.push_back(e);
    }

    return n_list;
}

template <class T>
My_list<T>& My_list<T>::operator =(My_list<T> const &list)
{
    this->clear();

    for (T &e : list)
    {
        this->push_back(e);
    }

    return *this;
}

template <class T>
T &My_list<T>::operator [](size_t i)
{
    if (i < 0 || i >= this->len)
        throw Bad_index("List index out of range",
                __FILE__,
                __LINE__-2,
                __func__);

    std::weak_ptr<elem> cur = this->content;

    for (size_t j = 0; j < i; cur = cur.lock()->next, j++);

    return *(cur.lock()->data);
}

template <class T>
T My_list<T>::operator [](size_t i) const
{
    if (i < 0 || i >= this->len)
        throw Bad_index("List index out of range",
                        __FILE__,
                        __LINE__-2,
                        __func__);

    std::weak_ptr<elem> cur = this->content;

    for (size_t j = 0; j < i; cur = cur.lock()->next, j++);

    return *(cur.lock()->data);
}


template <class T>
My_list<T>::~My_list()
{
    this->clear();
}


template <class T>
std::weak_ptr<typename My_list<T>::elem> My_list<T>::iterator::get()
{
    return this->it;
}

template <class T>
std::weak_ptr<typename My_list<T>::elem> My_list<T>::const_iterator::get() const
{
    return this->it;
}


#endif //LAB02_MY_LIST_H
