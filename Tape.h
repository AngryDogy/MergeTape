

#ifndef TESTTASK_TAPE_H
#define TESTTASK_TAPE_H

#include<fstream>

class Tape
{
private:
    std::fstream tape_file_;
    std::string path_;
    long long n_;

public:
    Tape(std::string tape_path, long long n);

    ~Tape();

    std::fstream &GetTapeFile();

    long long GetNumberOfElements();

    std::string GetPath();

    void OpenPath();

    void ClosePath();
};

#endif
