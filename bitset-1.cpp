#include <algorithm>
#include <cstdint>
#include <iostream>

int main()
{
    std::uint64_t N, S, P, Q;
    if (!(std::cin >> N >> S >> P >> Q))
    {
        return 0;
    }

    if (N == 0)
    {
        std::cout << 0 << '\n';
        return 0;
    }

    constexpr std::uint64_t modulus = 1ULL << 31;
    constexpr std::uint64_t mask = modulus - 1;

    const std::uint64_t P_masked = P & mask;
    const std::uint64_t Q_masked = Q & mask;

    auto next_value = [&](std::uint64_t x)
    {
        return ((x * P_masked + Q_masked) & mask);
    };

    const std::uint64_t start = S & mask;

    if (N == 1)
    {
        std::cout << 1 << '\n';
        return 0;
    }

    std::uint64_t tortoise = next_value(start);
    std::uint64_t hare = next_value(next_value(start));
    std::uint64_t steps = 1;

    while (tortoise != hare && steps < N)
    {
        tortoise = next_value(tortoise);
        hare = next_value(next_value(hare));
        ++steps;
    }

    if (steps >= N)
    {
        std::cout << N << '\n';
        return 0;
    }

    std::uint64_t mu = 0;
    tortoise = start;
    while (tortoise != hare)
    {
        tortoise = next_value(tortoise);
        hare = next_value(hare);
        ++mu;
    }

    std::uint64_t lambda = 1;
    hare = next_value(tortoise);
    while (tortoise != hare)
    {
        hare = next_value(hare);
        ++lambda;
    }

    std::uint64_t result = mu;
    if (N > mu)
    {
        result += std::min<std::uint64_t>(lambda, N - mu);
    }

    std::cout << result << '\n';
    return 0;
}
