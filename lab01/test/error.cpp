#include "error.h"


const char * show_error_message(Error_codes code)
{
    const char * msg;
    Error_messages ml;

    switch (code)
    {
    case file_load_error:
        msg = ml.file_load_error_msg;
        break;
    case file_read_error:
        msg = ml.file_read_error_msg;
        break;
    default:
        break;
    }

    return msg;
}
