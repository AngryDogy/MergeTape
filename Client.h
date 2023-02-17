

#ifndef TESTTASK_CLIENT_H
#define TESTTASK_CLIENT_H

#include<map>
#include "Tape.h"
#include "MergeSorter.h"

class Client
{
private:
    Tape *input_tape_;
    Tape *output_tape_;
    MergeSorter *sorter_;
    std::map<std::string, int> settings_;
public:
    Client(std::string inputPath, long long number_of_elements, std::string outputPath, std::string configPath,
           MergeSorter *sorter);

    void DoSort();
};


#endif
