#include"MergeSorter.h"

MergeSorter::MergeSorter(const char *path_to_tmp)
{
    path_to_tmp_ = path_to_tmp;
    mkdir(path_to_tmp, 0777);
}

void MergeSorter::Sort(Tape *input, Tape *output)
{
    if (input == nullptr)
        throw new std::invalid_argument("input is null");
    if (output == nullptr)
        throw new std::invalid_argument("output is null");
    Split(input, output);
    parts_number_ = 0;
}

void MergeSorter::Split(Tape *tape, Tape *output)
{
    if (tape->GetNumberOfElements() == 1)
        return;
    bool check_end = false;
    if (parts_number_ == 0)
        check_end = true;
    std::string original_path = tape->GetPath();
    tape->OpenPath();
    int n = tape->GetNumberOfElements();
    int n1 = n / 2;
    int n2 = n - n1;
    int value;
    std::string path1 = path_to_tmp_ + '/' + std::to_string(parts_number_);
    parts_number_++;
    std::fstream file1;
    file1.open(path1, std::fstream::out);
    for (int i = 0; i < n1; i++)
    {
        tape->GetTapeFile() >> value;
        file1 << value << " ";
    }
    file1.close();
    std::string path2 = path_to_tmp_ + '/' + std::to_string(parts_number_);
    parts_number_++;
    std::fstream file2;
    file2.open(path2, std::fstream::out);
    for (int i = 0; i < n2; i++)
    {
        tape->GetTapeFile() >> value;
        file2 << value << " ";
    }
    file2.close();
    tape->ClosePath();
    Tape *tape1 = new Tape(path1, n1);
    Tape *tape2 = new Tape(path2, n2);
    if (!check_end)
        std::filesystem::remove(original_path);
    Split(tape1, output);
    Split(tape2, output);
    if (check_end)
        Merge(tape1, tape2, output->GetPath());
    else
        Merge(tape1, tape2, original_path);


}

void MergeSorter::Merge(Tape *tape1, Tape *tape2, std::string tape_path)
{
    std::fstream result;
    result.open(tape_path, std::fstream::out);
    tape1->OpenPath();
    tape2->OpenPath();
    int val1, val2;
    int n = tape1->GetNumberOfElements(), m = tape2->GetNumberOfElements();
    tape1->GetTapeFile() >> val1;
    tape2->GetTapeFile() >> val2;
    int i = 1, j = 1, k = 0, amount = n + m;
    do
    {
        if (val1 > val2)
        {
            result << val2 << " ";
            if (j < m)
            {
                tape2->GetTapeFile() >> val2;
                j++;
            } else
            {
                val2 = INT_MAX;
            }
        } else
        {
            result << val1 << " ";
            if (i < n)
            {
                tape1->GetTapeFile() >> val1;
                i++;
            } else
            {
                val1 = INT_MAX;
            }
        }
        k++;

    } while (k < amount);
    tape1->ClosePath();
    tape2->ClosePath();
    result.close();
    std::filesystem::remove(tape1->GetPath());
    std::filesystem::remove(tape2->GetPath());
}


