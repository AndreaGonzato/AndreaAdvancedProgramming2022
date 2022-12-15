#pragma once

#include <iostream>
#include <string>
#include <chrono>

class Timer
{

    std::chrono::time_point<std::chrono::steady_clock> t_start;
    std::string time_what;
    void print_time()
    {
        auto t_end = std::chrono::steady_clock::now();
        auto total = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
        std::cout << time_what << " took " << total << " milliseconds" << std::endl;
    }

public:
    Timer(std::string s) : t_start{std::chrono::steady_clock::now()},
                           time_what{s} {}
    ~Timer() { print_time(); }
};