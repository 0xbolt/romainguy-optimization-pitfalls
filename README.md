# romainguy-optimization-pitfalls

## References
- https://www.romainguy.dev/posts/2024/the-path-not-taken/
- https://www.romainguy.dev/posts/2024/you-are-going-to-need-it/

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
