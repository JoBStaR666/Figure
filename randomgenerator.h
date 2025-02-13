#pragma once
#include <random>
#include <type_traits>
#include <chrono>


template <typename T, typename Enable = void>
class RandomGenerator
{};


template<typename T>
class RandomGenerator<T, std::enable_if_t<std::is_floating_point_v<T> or std::is_integral_v<T> >>
{
public:
    RandomGenerator(T min, T max)
        :min(min),max(max-1),
          randGenerator(std::chrono::high_resolution_clock::now().time_since_epoch().count())
    {}
    auto getRandomValue()
    {
        return getRandomValue(min, max);
    }
    T getRandomValue(T min, T max)
    {
        if constexpr(std::is_floating_point_v<T>)
        {
            std::uniform_real_distribution<double> gen(min, max);
            return gen(randGenerator);
        }
        else if constexpr (std::is_integral_v<T>)
        {
            std::uniform_int_distribution<long long> gen(min, max);
            return gen(randGenerator);
        }

    }
    auto operator()(){
        return getRandomValue(min, max);
    }
private:
    T max;
    T min;
    std::mt19937 randGenerator;
};
