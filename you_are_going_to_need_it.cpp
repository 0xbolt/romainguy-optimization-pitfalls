// https://www.romainguy.dev/posts/2024/you-are-going-to-need-it/

#include <cmath>
#include <random>
#include <benchmark/benchmark.h>

double pow2(double x) {
    return std::pow(x, 2);
}

double square(double x) {
    return x * x;
}

std::vector<int> generateData(int n) {
    std::random_device rd;
    std::mt19937 rng(0);
    std::uniform_int_distribution<int> dist(0, 255);

    std::vector<int> data(n);
    std::generate(data.begin(), data.end(), [&] { return dist(rng); } );
    return data;
}

static void BM_pow2(benchmark::State& state) {
    auto data = generateData(state.range(0));

    for (auto _ : state) {
        for (auto x : data) {
            benchmark::DoNotOptimize(pow2(x));
        }
    }
}

static void BM_square(benchmark::State& state) {
    auto data = generateData(state.range(0));

    for (auto _ : state) {
        for (auto x : data) {
            benchmark::DoNotOptimize(square(x));
        }
    }
}

BENCHMARK(BM_pow2)->Arg(1 << 16);
BENCHMARK(BM_square)->Arg(1 << 16);
BENCHMARK_MAIN();

/*
Compiler options: -O3 -ffast-math -march=native

Benchmark                Time             CPU   Iterations
----------------------------------------------------------
BM_pow2/65536        20636 ns        20588 ns        34271
BM_square/65536      20630 ns        20596 ns        33909
*/
