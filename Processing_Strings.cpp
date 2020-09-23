#include "Hamlet.h"


//-------------------------------------------------------------------------------
//! This function sorts strings and put them in the file. In addition it puts in
//! the file not sorted text.
//!
//! Function calls the following supporting functions:
//! 1) QuickSort_Strings
//! 2) Arr_Elem_Swap
//! 3) Print_Strings
//! 4) Print_Buff
//!
//! @param [out] arr_structs - Array, filled with the structures
//! @param [in]  num_strings - Number of strings
//-------------------------------------------------------------------------------
void Procesing_Strings(struct string_info* arr_structs, size_t num_strings, char* point_buff)
{
    QuickSort_Strings(arr_structs, 0, num_strings - 1, &Compare_Begin);
    Print_Strings(arr_structs, num_strings, "Begin_Sort");

    QuickSort_Strings(arr_structs, 0, num_strings - 1, &Compare_End);
    Print_Strings(arr_structs, num_strings, "End_Sort");

    Print_Buff(point_buff, num_strings);

    free(point_buff);
    free(arr_structs);
}




//------------------------------------------------------------------------
//! This function prints the text from the buff, replacing '\0'  with '\n'
//!
//! @param [out] point_buff  - Pointer to the buff with not sorted text
//! @param [in]  num_strings - Number of strings
//!
//------------------------------------------------------------------------
void Print_Buff(char* point_buff, size_t num_strings)
{
    assert(point_buff != NULL);

    FILE* Output = fopen("Output_Onegin.txt", "a");

    fprintf(Output, "\n\n\nNot sorted text:\n\n\n");

    for (size_t i = 0; num_strings + 1 > 0; i++)
    {
        if ( *(point_buff + i) == '\0')
        {
            *(point_buff + i) = '\n';
            num_strings--;
        }


        int res = fputc(*(point_buff + i), Output);


        assert(res != EOF);

    }


    fclose(Output);

}



//-----------------------------------------------------------------
//! This function prints strings to the file.
//!
//! @param [out] arr         - Array of the structures
//! @param [in]  num_strings - Number of the strings
//! @param [out] sort_name   - Way of sorting
//!
//-----------------------------------------------------------------
void Print_Strings(struct string_info* arr, size_t num_strings, const char* sort_name)
{
    assert(arr != NULL);
    assert(sort_name != NULL);


    FILE* Output = fopen("Output_Hamlet.txt", "a");

    fprintf(Output, "\n\n\n%s:\n\n\n", sort_name);

    for (size_t i = 0; i < num_strings; i++)
    {
        fprintf(Output, "%s\n", (*(arr + i)).str );
    }


    fclose(Output);
}
