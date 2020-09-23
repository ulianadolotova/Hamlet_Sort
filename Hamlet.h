#include <stdio.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

size_t Size_File_Counter       (const char* file_name);

size_t Buff_Filler             (char* point_buff, const char* file_name, size_t file_size);

size_t Strings_Counter         (char* point_buff, size_t num_symbols);

size_t Struct_Arr_Filler       (size_t num_symbols, size_t num_strings, char* point_buff, struct string_info* arr_structs);

void   Print_Strings           (struct string_info* arr, size_t num_strings, const char* sort_name);

void   QuickSort_Strings       (struct string_info* arr_structs, size_t left, size_t right,
                                int (*Compare)(struct string_info str1, struct string_info str2));

void   Arr_Elem_Swap           (string_info* arr, size_t first, size_t second);

int    Compare_Begin           (struct string_info str1, struct string_info str2);

int    Compare_End             (struct string_info str1, struct string_info str2);

void   Procesing_Strings       (struct string_info* arr_structs, size_t num_strings, char* point_buff);

struct arr_info File_Interactor(const char* file_name);

void   Print_Buff              (char* point_buff, size_t num_strings);

struct string_info {

    char*  str;
    size_t size_str;

};

struct arr_info {

    struct string_info* pointer;
    size_t num_strings;
    char* point_buff;

};



void   Hamlet_Unit_Tests      (void);

void   test_File_Size_Counter (void);

void   test_Strings_Counter   (void);

void   test_Compare_Begin     (void);

void   test_Compare_End       (void);

