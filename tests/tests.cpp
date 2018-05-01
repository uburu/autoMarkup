#include <iostream>
#include <assert.h>
#include <boost/test/minimal.hpp>
#include "test_DataHub/test_DataHub.hpp"
#include "test_DictHandler/test_DictHandler.hpp"

#define PATH "../data/tests/" // path to data

int test_main( int, char *[ ] ) // note the name! 
{
    test_DataHub_ReadText_1();
    test_DataHub_ReadDict_1();
    test_DataHub_ReadDict_2();
    test_DataHub_ReadDict_3();
    test_DictHandler_fillDict_1();
    test_DictHandler_fillDict_2();
    return 0;
}
