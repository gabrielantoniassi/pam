#include <benchmark/benchmark.h>
#include "SMatrix.h"

static void hhybrid(benchmark::State& state) {
	SMatrix<double, 4, 4> sm1(3.14), sm2(4.14);
	SMatrix<double, 4, 4> sm3;
	for (auto _ : state) {
		sm3 = sm1.hyb<4>(sm2);
	}
	std::cout << sm3 << std::endl;
}
BENCHMARK(hhybrid);

static void mul(benchmark::State& state) {
	SMatrix<double, 4, 4> sm1(3.14), sm2(4.14);
	SMatrix<double, 4, 4> sm3;
	for (auto _ : state) {
		sm3 = sm1.mul<4>(sm2);
	}
	std::cout << sm3 << std::endl;
}
BENCHMARK(mul);

BENCHMARK_MAIN();
