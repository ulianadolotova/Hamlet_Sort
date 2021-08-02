#include "Hamlet.h"

int main(int argc, const char* argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0)
    {
          Hamlet_Unit_Tests();
    }


    struct arr_info Interactor_result = File_Interactor("Hamlet_clean.txt");

    size_t num_strings              = Interactor_result.num_strings;
    struct string_info* arr_structs = Interactor_result.pointer;
    char* point_buff                = Interactor_result.point_buff;

    Procesing_Strings(arr_structs, num_strings, point_buff);

    return 0;
}
