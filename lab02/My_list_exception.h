//
// Created by 1 on 12.04.2019.
//

#ifndef LAB02_MY_LIST_EXCEPTION_H
#define LAB02_MY_LIST_EXCEPTION_H

#include <exception>
#include <string>


class My_list_exception : public std::exception
{
protected:
    const char *file = nullptr;
    const char *info = nullptr;
    const char *func = nullptr;
    int line = 0;

public:
    My_list_exception(const char *_file, const int _line, const char *_func, const char *_info) :
        file(_file),
        info(_info),
        line(_line),
        func(_func)
    {};
    My_list_exception() : My_list_exception("Unspecified file", 0, "Unspecified function", "Unspecified exception") {};

    virtual const char *get_file() const = 0;
    virtual const char *get_func() const = 0;
    virtual const char *get_info() const = 0;
    virtual int get_line() const = 0;

    virtual const char *what() const noexcept = 0;
};


class Bad_index : public My_list_exception
{
private:
    const char *msg = nullptr;
public:
    Bad_index(const char *_msg, const char *_file, const int _line, const char *_func) : My_list_exception(_file, _line, _func, "Bad index exception"), msg(_msg){};
    Bad_index(const char *_msg) : My_list_exception("Unspecified file", 0, "Unspecified function", "Unspecified bad index exception"), msg(_msg) {};

    const char *get_file() const final { return file; };
    const char *get_func() const final { return func; };
    const char *get_info() const final { return info; };
    int get_line() const final { return line; };

    const char *what() const noexcept final
    {
        std::string buf;

        buf.append("Caught ");
        buf.append(get_info());
        buf.append("\n at: ");
        buf.append(get_file());
        buf.append("\n at: ");
        buf.append(get_func());
        buf.append("\n at: line ");
        buf.append(std::to_string(get_line()));
        buf.append("\n");
        buf.append(msg);

        return buf.data();
    };
};

class Bad_iterator : public My_list_exception
{
private:
    const char *msg = nullptr;
public:
    Bad_iterator(const char *_msg, const char *_file, const int _line, const char *_func) : My_list_exception(_file, _line, _func, "Bad iterator exception"), msg(_msg){};
    Bad_iterator(const char *_msg) : My_list_exception("Unspecified file", 0, "Unspecified function", "Unspecified bad iterator exception"), msg(_msg) {};

    const char *get_file() const final { return file; };
    const char *get_func() const final { return func; };
    const char *get_info() const final { return info; };
    int get_line() const final { return line; };

    const char *what() const noexcept final
    {
        std::string buf;

        buf.append("Caught ");
        buf.append(get_info());
        buf.append("\n at: ");
        buf.append(get_file());
        buf.append("\n at: ");
        buf.append(get_func());
        buf.append("\n at: line ");
        buf.append(std::to_string(get_line()));
        buf.append("\n");
        buf.append(msg);

        return buf.data();
    };
};


#endif //LAB02_MY_LIST_EXCEPTION_H
