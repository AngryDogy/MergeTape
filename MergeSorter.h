

#ifndef TESTTASK_MERGESORTER_H
#define TESTTASK_MERGESORTER_H

#include <iostream>
#include <limits.h>
#include "Tape.h"
#include<string>
#include <sys/stat.h>
#include <filesystem>

class MergeSorter
{
private:
    std::string path_to_tmp_;
    int parts_number_ = 0;

    void Split(Tape *tape, Tape *output);

    void Merge(Tape *tape1, Tape *tape2, std::string tape_path);

public:
    MergeSorter(const char *path_to_tmp);

    void Sort(Tape *input, Tape *output);
};

#endif
