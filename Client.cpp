#include"Client.h"

Client::Client(std::string input_path, long long number_of_elements, std::string output_path, std::string configPath,
               MergeSorter *sorter)
{
    input_tape_ = new Tape(input_path, number_of_elements);
    output_tape_ = new Tape(output_path, 0);
    if (sorter == nullptr)
        throw new std::invalid_argument("sorter is null");
    std::fstream config;
    config.open(configPath);
    if (!config.is_open())
        throw new std::invalid_argument("configPath is invalid");
    std::string option;
    int value;
    while (!config.eof())
    {
        config >> option >> value;
        settings_.insert({option, value});
    }
    config.close();
    sorter_ = sorter;
}

void Client::DoSort()
{
    sorter_->Sort(input_tape_, output_tape_);
}