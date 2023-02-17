#include <iostream>
#include"Client.h"

int main()
{
    int n;
    std::string input, output;
    std::cout
            << "Please enter: the path to the input tape; the number of elements in the input tape; the path to the output tape:"
            << std::endl;
    std::cin >> input >> n >> output;
    Client client(input, n, output, "config", new MergeSorter("tmp"));
    client.DoSort();
    return 0;
}
