#include "Hamlet.h"



//------------------------------------------------------------------------------
//! This function works with file. It creates a special buff for the text from
//! the file and array of structures (structure contains information about every
//! string: pointer to the string and its size).
//!
//! Function calls the following supporting functions:
//! 1) Size_File_Counter(file_name);
//! 2) Buff_Filler(point_buff, file_name, file_size);
//! 3) Strings_Counter(point_buff, num_symbols);
//! 4) Struct_Arr_Filler(num_symbols, num_strings, point_buff, arr_structs).
//!
//! @param [out] file_name  - Name of the file
//!
//! @return      Interactor - structure, which contains pointer to the array
//!                           of string_info structures and number of the
//!                           string in the buff.
//!
//! @note Function adds 2 extra bytes to the buff for '\0' in the begin
//!       and in the end.
//------------------------------------------------------------------------------
struct arr_info File_Interactor(const char* file_name)
{
    size_t file_size   = Size_File_Counter(file_name) + 2;

    char*  point_buff  = (char*) calloc(file_size, sizeof(char));


    assert(point_buff != NULL);


    size_t num_symbols = Buff_Filler(point_buff, file_name, file_size);

    size_t num_strings = Strings_Counter(point_buff, num_symbols);


    struct string_info* arr_structs = (struct string_info*) calloc(num_strings, sizeof(struct string_info));


    assert(arr_structs != NULL);


    num_strings  = Struct_Arr_Filler(num_symbols, num_strings, point_buff, arr_structs);

    struct arr_info Interactor;

    Interactor.pointer     = arr_structs;
    Interactor.num_strings = num_strings;
    Interactor.point_buff  = point_buff;

    return Interactor;

}




//----------------------------------------------------------------------
//! This function looks for the size of the file.
//!
//! @param [out] file_name - Name of the file
//!
//! @return file_size      - Size of the file
//----------------------------------------------------------------------
size_t Size_File_Counter(const char* file_name)
{
    assert (file_name != NULL);

    size_t file_size = 0;
    struct stat buff;

    stat(file_name, &buff);

    file_size = buff.st_size;

    return file_size;
}



//-------------------------------------------------------------------------
//! This function fills the buffer with text
//! from the file. Also it replaces '\n' with '\0'.
//!
//! @param [out] point_buff   - Pointer to the buffer
//! @param [out] file_name    - Name of the file
//! @param [in]  size_file    - Size of the file
//!
//! @return      num_symbols  - Number of the symbols in the file
//!
//! @note Function pushes '\0' to the first element and '\0' to the last.
//------------------------------------------------------------------------
size_t Buff_Filler(char* point_buff, const char* file_name, size_t file_size)
{

    assert(point_buff != NULL);
    assert(file_name  != NULL);


    FILE* file_pointer = fopen(file_name, "r");


    *(point_buff) = '\0';

    size_t num_symbols = fread(point_buff + 1, sizeof(char), file_size, file_pointer);

    *(point_buff + 1 + num_symbols) =  '\0';


    fclose(file_pointer);


    return num_symbols;
}



//----------------------------------------------------------------------
//! This function counts '\n' and replaces them with '\0'.
//!
//! @param [out] point_buff  - Pointer to the buff with the text
//! @param [in]  num_symbols - Number of symbols in the text
//!
//! @return      num_strings - Number of strings (with empty strings)
//----------------------------------------------------------------------
size_t Strings_Counter(char* point_buff, size_t num_symbols)
{
    assert(point_buff != NULL);

    size_t num_strings = 1;

    for (char* pointer = point_buff; pointer < point_buff + num_symbols; pointer++)
        if (*pointer == '\n')
        {
            num_strings++;
            *pointer = '\0';
        }

    return num_strings;
}



//-----------------------------------------------------------------------
//! This function fills the array with the structures (stucture contains
//! information about every string: pointer to it and its size)
//!
//! @param [in]  num_symbols    - Number of symbols
//! @param [in]  num_strings    - Number of strings (with empty strings)
//! @param [out] point_buff     - Pointer to the buffer of the text
//! @param [out] arr_structs    - Pointer to the array of structures
//!
//! @return      counter        - Number of strings (without empty strings)
//-----------------------------------------------------------------------
size_t Struct_Arr_Filler (size_t num_symbols, size_t num_strings, char* point_buff, struct string_info* arr_structs)
{
    size_t counter = 0;
    assert(arr_structs != NULL);
    assert(point_buff  != NULL);

    for (size_t i = 0; i < num_symbols + 1; i++)
    {
        if ( *(point_buff + i) == '\0')
        {
            (*(arr_structs + counter)).str  = point_buff + i + 1;

            if (counter > 0)

                (*(arr_structs + counter - 1)).size_str = ((*(arr_structs + counter)).str - (*(arr_structs + counter - 1)).str - 1);

            counter++;

            assert(counter <= num_strings);

        }

    }

    (*(arr_structs + counter - 1)).size_str = &(point_buff[num_symbols]) - (*(arr_structs + counter - 1)).str + 1;

    return counter;
}
