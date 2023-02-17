#include "Client.h"
#include "MergeSorter.h"
#include "Tape.h"
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"


TEST(Test, first)
{


    Client client("input", 20, "output", "config", new MergeSorter("tmp"));
    client.DoSort();
    bool result = std::filesystem::exists("output");
    EXPECT_EQ(result, true);
}
