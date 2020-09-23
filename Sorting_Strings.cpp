#include "Hamlet.h"



//-----------------------------------------------------------------------
//! This function sorts the strings (in the array of the pointers to the
//! strings) in that way, which function Compare suggests.
//!
//! @param [out] arr_structs - Array, filled with the structures
//! @param [in]  left        - Index of the left element
//! @param [in]  right       - Index of the right element
//! @param [out] Compare     - Function, that suggest the way of sorting
//-----------------------------------------------------------------------
void QuickSort_Strings(struct string_info* arr_structs, size_t left, size_t right,
                       int (*Compare)(struct string_info str1, struct string_info str2))
{
        assert(arr_structs != NULL);
        assert(Compare != NULL);


        size_t i = 0;
        size_t last = 0;

        if (left >= right)
            return;

        Arr_Elem_Swap(arr_structs, left, (left + right)/2);

        last = left;

        for (i = left + 1; i <= right; i++)
        {
            if ( (*Compare) ( *(arr_structs + i), *(arr_structs + left)) < 0)
            {
                Arr_Elem_Swap(arr_structs, ++last, i);
            }
        }

        Arr_Elem_Swap(arr_structs, left, last);


        QuickSort_Strings(arr_structs, left, last - 1, Compare);
        QuickSort_Strings(arr_structs, last + 1, right, Compare);
}



//-----------------------------------------------------------------------
//! This function swaps 2 elements of the array, filled with the
//! structures.
//!
//! @param [out] arr    - Pointer to the array of the pointers
//! @param [in]  first  - Index of the first element
//! @param [in]  second - Index of the second element
//-----------------------------------------------------------------------
void Arr_Elem_Swap(struct string_info* arr, size_t first, size_t second)
{
    assert(arr != NULL);

    struct string_info temp = *(arr + first);
    *(arr + first) = *(arr + second);
    *(arr + second) = temp;
}



//------------------------------------------------------------------------
//! This function compares by begin two strings, skipping space symbols.
//!
//! @param [out] str1 - First string
//! @param [out] str2 - Second string
//!
//! @return >=0 - if str1 is "bigger" (or identical) than str2
//!         < 0 - if str2 is "smaller" than str1
//!
//! @note If the string only contains space symbols, than it is considered
//!       as the biggest.
//------------------------------------------------------------------------
int Compare_Begin(struct string_info str1, struct string_info str2)
{

    size_t x = 0;
    size_t y = 0;

    for (x = 0, y = 0; *(str1.str + x) != '\0' && *(str2.str + y) != '\0'; x++, y++)
    {
        if ( isalpha(*(str1.str + x)) && isalpha(*(str2.str + y)) )
        {
            if( tolower(*(str1.str + x)) != tolower(*(str2.str + y)) )

                return tolower(*(str1.str + x)) - tolower(*(str2.str + y));
        }

        else if (isalpha(*(str1.str + x)))
        {
             x--;
        }

        else if (isalpha(*(str2.str + y)))
        {
             y--;
        }
     }

     if (*(str1.str + x) == '\0')
        return 1;

     else if (*(str2.str + y) == '\0')
        return -1;

     else return 0;
}



//------------------------------------------------------------------------
//! This function compares by end two strings, skipping space symbols.
//!
//! @param [out] str1 - First string
//! @param [out] str2 - Second string
//!
//! @return  >=0 - if str1 is "bigger" (or identical) than str2
//!          < 0 - if str2 is "smaller" than str1
//!
//! @note If the string only contains space symbols, than it is considered
//!       as the biggest.
//------------------------------------------------------------------------
int Compare_End(struct string_info str1, struct string_info str2)
{
    size_t x = str1.size_str - 1;
    size_t y = str2.size_str - 1;


    for (x, y; *(str1.str + x) != '\0' && *(str2.str + y) != '\0'; x--, y--)
    {
        if (isalpha(*(str1.str + x)) && isalpha(*(str2.str + y)) )
        {
            if( tolower(*(str1.str + x)) != tolower(*(str2.str + y)) )

                return tolower(*(str1.str + x)) - tolower(*(str2.str + y));

        }

        else if (isalpha(*(str1.str + x)))
        {
             x++;
        }

        else if (isalpha(*(str2.str + y)))
        {
             y++;
        }
     }

     if      (*(str1.str + x) == '\0')
        return 1;

     else if (*(str2.str + y) == '\0')
        return -1;

     else return 0;

}












