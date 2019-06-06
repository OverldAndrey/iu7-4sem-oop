//
// Created by 1 on 15.04.2019.
//

#ifndef LAB02_MY_ITERATOR_H
#define LAB02_MY_ITERATOR_H

#include <iterator>
#include <memory>

template <class T, class elem=T>
class My_iterator : public std::iterator<std::forward_iterator_tag, T>
{
protected:
    size_t ind = 0;
    std::weak_ptr<elem> it;

    void _check(const char *fn);
public:
    My_iterator() = default;
    My_iterator(My_iterator &it) = default;

    typename My_iterator::reference operator *();
    typename My_iterator::pointer operator ->();
    My_iterator& operator ++();
    My_iterator operator ++(int);
    bool operator ==(const My_iterator &iter);
    bool operator !=(const My_iterator &iter);
    bool operator >(const My_iterator &iter);
    bool operator <(const My_iterator &iter);
    bool operator ==(const int iter);
    bool operator !=(const int iter);
    bool operator >(const int iter);
    bool operator <(const int iter);
    My_iterator &operator =(const My_iterator &iter);

    ~My_iterator() = default;
};


template <class T, class elem>
void My_iterator<T, elem>::_check(const char *fn)
{
    if (it.expired() || it.lock().use_count() == 0)
        throw Bad_iterator("Iterator expired",
                           __FILE__,
                           __LINE__-2,
                           fn);
}

template <class T, class elem>
typename My_iterator<T, elem>::reference My_iterator<T, elem>::operator *()
{
    this->_check(__func__);
    return *(it.lock().get()->data);
}

template <class T, class elem>
typename My_iterator<T, elem>::pointer My_iterator<T, elem>::operator->()
{
    this->_check(__func__);
    return it.lock().get()->data;
}

template <class T, class elem>
My_iterator<T, elem>& My_iterator<T, elem>::operator++()
{
    this->it = this->it.lock()->next;
    ++(this->ind);
    return *this;
}

template <class T, class elem>
My_iterator<T, elem> My_iterator<T, elem>::operator++(int)
{
    My_iterator temp = *this;
    this->it = this->it.lock()->next;
    (this->ind)++;
    return temp;
}

template <class T, class elem>
bool My_iterator<T, elem>::operator ==(const My_iterator<T, elem> &iter)
{
    return ind == iter.ind;
}

template <class T, class elem>
bool My_iterator<T, elem>::operator <(const My_iterator<T, elem> &iter)
{
    return ind < iter.ind;
}

template <class T, class elem>
bool My_iterator<T, elem>::operator >(const My_iterator<T, elem> &iter)
{
    return ind > iter.ind;
}

template <class T, class elem>
bool My_iterator<T, elem>::operator !=(const My_iterator<T, elem> &iter)
{
    return ind != iter.ind;
}

template <class T, class elem>
bool My_iterator<T, elem>::operator ==(const int iter)
{
    return ind == iter;
}

template <class T, class elem>
bool My_iterator<T, elem>::operator <(const int iter)
{
    return ind < iter;
}

template <class T, class elem>
bool My_iterator<T, elem>::operator >(const int iter)
{
    return ind > iter;
}

template <class T, class elem>
bool My_iterator<T, elem>::operator !=(const int iter)
{
    return ind != iter;
}

template <class T, class elem>
My_iterator<T, elem>& My_iterator<T, elem>::operator =(const My_iterator<T, elem> &iter)
{
    this->it = iter.it;
    this->ind = iter.ind;
    return *this;
}


#endif //LAB02_MY_ITERATOR_H
