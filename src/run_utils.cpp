#include "run_utils.hpp"

void assert(bool assertion, int error_number, string error_message)
{
    try
    {
        if (not assertion) throw (error_number);
    }
    catch (int err)
    {
        cerr << "Assertion failed : " << error_message << endl;
        exit (EXIT_FAILURE);
    }
}
