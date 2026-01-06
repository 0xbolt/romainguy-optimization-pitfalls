// https://www.romainguy.dev/posts/2024/the-path-not-taken/

#include <random>
#include <vector>
#include <benchmark/benchmark.h>

std::vector<int> generateRandomData(int n) {
    std::random_device rd;
    std::mt19937 rng(0);
    std::uniform_int_distribution<int> dist(0, 255);

    std::vector<int> data(n);
    std::generate(data.begin(), data.end(), [&] { return dist(rng); } );
    return data;
}

std::vector<int> generatePredictableData(int n) {
    std::vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = i % 256;
    }
    return data;
}

float processData(std::vector<int> data) {
    float sum = 0;
    for (auto x : data) {
        if (x < 128) {
            sum += x / 128.0f;
        }
    }
    return sum;
}

float processDataBranchless(std::vector<int> data) {
    float sum = 0;
    for (auto x : data) {
        sum += x < 128 ? x / 128.0f : 0;
    }
    return sum;
}

static void BM_processRandomData(benchmark::State& state) {
    auto data = generateRandomData(state.range(0));
    for (auto _ : state) {
        benchmark::DoNotOptimize(processData(data));
    }
}

static void BM_processPredictableData(benchmark::State& state) {
    auto data = generatePredictableData(state.range(0));
    for (auto _ : state) {
        benchmark::DoNotOptimize(processData(data));
    }
}

static void BM_processRandomDataBranchless(benchmark::State& state) {
    auto data = generateRandomData(state.range(0));
    for (auto _ : state) {
        benchmark::DoNotOptimize(processDataBranchless(data));
    }
}

static void BM_processPredictableDataBranchless(benchmark::State& state) {
    auto data = generatePredictableData(state.range(0));
    for (auto _ : state) {
        benchmark::DoNotOptimize(processDataBranchless(data));
    }
}

BENCHMARK(BM_processRandomData)->Arg(1 << 16);
BENCHMARK(BM_processPredictableData)->Arg(1 << 16);
BENCHMARK(BM_processRandomDataBranchless)->Arg(1 << 16);
BENCHMARK(BM_processPredictableDataBranchless)->Arg(1 << 16);
BENCHMARK_MAIN();

/*
-O3 Results:

Benchmark                                          Time             CPU   Iterations
------------------------------------------------------------------------------------
BM_processRandomData/65536                    106875 ns       106778 ns         6536
BM_processPredictableData/65536               107026 ns       106886 ns         6540
BM_processRandomDataBranchless/65536           65960 ns        65864 ns        10619
BM_processPredictableDataBranchless/65536      65960 ns        65876 ns        10570
*/
