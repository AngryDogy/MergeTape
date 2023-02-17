#include"Tape.h"

Tape::Tape(std::string tape_path, long long n)
{
    if (n < 0)
        throw new std::invalid_argument("Number of elements can't be negative!");
    path_ = tape_path;
    n_ = n;
}

Tape::~Tape()
{
    tape_file_.close();
}

std::fstream &Tape::GetTapeFile()
{
    return tape_file_;
}

long long Tape::GetNumberOfElements()
{
    return n_;
}

std::string Tape::GetPath()
{
    return path_;
}

void Tape::OpenPath()
{
    tape_file_.open(path_);
    if (!tape_file_.is_open())
        throw new std::invalid_argument("tape_path is invalid");
}

void Tape::ClosePath()
{
    tape_file_.close();
}
