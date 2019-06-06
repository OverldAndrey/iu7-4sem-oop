#ifndef ERROR_H
#define ERROR_H

enum Error_codes
{
    success = 0,
    file_load_error = 1,
    file_read_error = 2,
    alloc_error = 3,
    unknown_command_error = 4
};

struct Error_messages
{
    const char * const file_load_error_msg = "File can't be loaded!";
    const char * const file_read_error_msg = "Incorrect input from file!";
    const char * const alloc_error = "Bad allocation!";
    const char * const unknown_command_error = "Internal error: unknown command!";
};


const char * show_error_message(Error_codes code);

#endif // ERROR_H
