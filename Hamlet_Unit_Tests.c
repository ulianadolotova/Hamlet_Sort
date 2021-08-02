#include "Hamlet.h"

void   Hamlet_Unit_Tests(void)
{
    test_File_Size_Counter();
    test_Strings_Counter();
    test_Compare_Begin();
    test_Compare_End();
}


void test_File_Size_Counter(void)
{
    printf("\n\nTesting File_Size_Counter function:\n\n");
    const size_t NUM_TESTS = 5;

    size_t expected[NUM_TESTS] = {219, 827, 2771, 3, 0};
    size_t received[NUM_TESTS] = {1, 1, 1, 1, 1};

    received[0] = Size_File_Counter("test_size_1.txt");
    received[1] = Size_File_Counter("test_size_2.txt");
    received[2] = Size_File_Counter("test_size_3.txt");
    received[3] = Size_File_Counter("test_size_4.txt");
    received[4] = Size_File_Counter("test_size_5.txt");

    for (size_t i = 0; i < NUM_TESTS; i++)
    {
        if (received[i] == expected[i])
        {
            printf(" # test #%d is OK\n\n", i + 1);
        }

        else
        {
            printf(" # test #%d is BAD\n", i + 1);
            printf("               expected value is %d\n", expected[i]);
            printf("               received value is %d\n\n", received[i]);
        }

    }

}

void test_Strings_Counter(void)
{
    printf("\n\nTesting String_Counter function:\n\n");
    const size_t NUM_TESTS = 5;

    size_t expected[NUM_TESTS] = {8, 39, 98, 1, 1};
    size_t received[NUM_TESTS] = {1, 1, 1, 1, 1};

    const char* file_name_1 = "test_size_1.txt";
    const char* file_name_2 = "test_size_2.txt";
    const char* file_name_3 = "test_size_3.txt";
    const char* file_name_4 = "test_size_4.txt";
    const char* file_name_5 = "test_size_5.txt";


    size_t file_size_1   = Size_File_Counter(file_name_1) + 2;
    size_t file_size_2   = Size_File_Counter(file_name_2) + 2;
    size_t file_size_3   = Size_File_Counter(file_name_3) + 2;
    size_t file_size_4   = Size_File_Counter(file_name_4) + 2;
    size_t file_size_5   = Size_File_Counter(file_name_5) + 2;


    char*  point_buff_1  = (char*) calloc(file_size_1, sizeof(char));
    char*  point_buff_2  = (char*) calloc(file_size_2, sizeof(char));
    char*  point_buff_3  = (char*) calloc(file_size_3, sizeof(char));
    char*  point_buff_4  = (char*) calloc(file_size_4, sizeof(char));
    char*  point_buff_5  = (char*) calloc(file_size_5, sizeof(char));


    size_t num_symbols_1 = Buff_Filler(point_buff_1, file_name_1, file_size_1);
    size_t num_symbols_2 = Buff_Filler(point_buff_2, file_name_2, file_size_2);
    size_t num_symbols_3 = Buff_Filler(point_buff_3, file_name_3, file_size_3);
    size_t num_symbols_4 = Buff_Filler(point_buff_4, file_name_4, file_size_4);
    size_t num_symbols_5 = Buff_Filler(point_buff_5, file_name_5, file_size_5);


    received[0] = Strings_Counter(point_buff_1, num_symbols_1);
    received[1] = Strings_Counter(point_buff_2, num_symbols_2);
    received[2] = Strings_Counter(point_buff_3, num_symbols_3);
    received[3] = Strings_Counter(point_buff_4, num_symbols_4);
    received[4] = Strings_Counter(point_buff_5, num_symbols_5);

    for (size_t i = 0; i < NUM_TESTS; i++)
    {
        if (received[i] == expected[i])
        {
            printf(" # test #%d is OK\n\n", i + 1);
        }

        else
        {
            printf(" # test #%d is BAD\n", i + 1);
            printf("               expected value is %d\n", expected[i]);
            printf("               received value is %d\n\n", received[i]);
        }

    }

    free(point_buff_1);
    free(point_buff_2);
    free(point_buff_3);
    free(point_buff_4);
    free(point_buff_5);
}


void test_Compare_Begin(void)
{

    printf("\n\nTesting Compare_End function:\n\n");
    const size_t NUM_TESTS = 5;

    int expected[NUM_TESTS] = {12, -20, 5, -3, 12};
    int received[NUM_TESTS] = {100, 100, 100, 100, 100};


    struct arr_info Interactor_result = File_Interactor("test_size_1.txt");


    struct string_info* arr_structs = Interactor_result.pointer;


    received[0] = Compare_Begin(*(arr_structs + 0), *(arr_structs + 1));
    received[1] = Compare_Begin(*(arr_structs + 1), *(arr_structs + 2));
    received[2] = Compare_Begin(*(arr_structs + 2), *(arr_structs + 3));
    received[3] = Compare_Begin(*(arr_structs + 3), *(arr_structs + 4));
    received[4] = Compare_Begin(*(arr_structs + 4), *(arr_structs + 5));

    for (size_t i = 0; i < NUM_TESTS; i++)
    {
        if (received[i] == expected[i])
        {
            printf(" # test #%d is OK\n\n", i + 1);
        }

        else
        {
            printf(" # test #%d is BAD\n", i + 1);
            printf("               expected value is %d\n", expected[i]);
            printf("               received value is %d\n\n", received[i]);
        }

    }

}


void test_Compare_End(void)
{

    printf("\n\nTesting Compare_End function:\n\n");
    const size_t NUM_TESTS = 5;

    int expected[NUM_TESTS] = {7, -1, 1, 13, -15};
    int received[NUM_TESTS] = {100, 100, 100, 100, 100};


    struct arr_info Interactor_result = File_Interactor("test_size_1.txt");


    struct string_info* arr_structs = Interactor_result.pointer;


    received[0] = Compare_End(*(arr_structs + 0), *(arr_structs + 1));
    received[1] = Compare_End(*(arr_structs + 1), *(arr_structs + 2));
    received[2] = Compare_End(*(arr_structs + 2), *(arr_structs + 3));
    received[3] = Compare_End(*(arr_structs + 3), *(arr_structs + 4));
    received[4] = Compare_End(*(arr_structs + 4), *(arr_structs + 5));

    for (size_t i = 0; i < NUM_TESTS; i++)
    {
        if (received[i] == expected[i])
        {
            printf(" # test #%d is OK\n\n", i + 1);
        }

        else
        {
            printf(" # test #%d is BAD\n", i + 1);
            printf("               expected value is %d\n", expected[i]);
            printf("               received value is %d\n\n", received[i]);
        }

    }

}



