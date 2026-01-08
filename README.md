# romainguy-optimization-pitfalls
- [`the_path_not_taken.cpp`](the_path_not_taken.cpp): Branch prediction, conditional move instructions
- [`you_are_going_to_need_it.cpp`](you_are_going_to_need_it.cpp): Preventing optimization
- [`aos_v_soa.cpp`](aos_v_soa.cpp): ...

## References
- https://www.romainguy.dev/posts/2024/the-path-not-taken/
- https://www.romainguy.dev/posts/2024/you-are-going-to-need-it/
- https://google.github.io/benchmark/user_guide.html

## Setup
```
# Fetch submodules
git submodule update --init

# Build
cmake -B build -GNinja -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Run benchmarks
./build/bin/the_path_not_taken
./build/bin/you_are_going_to_need_it
```
