Auto-generated C99 Wrapper for OpenColorIO

# Building
## Prerequisites
You must have [babble](https://github.com/anderslanglands/babble) installed, either from a release binary distribution or by building and installing from source. Currently relies on babble-0.4 and tested with OpenColorIO 2.2

## Building from source

```sh
cmake -B build -G Ninja -DCMAKE_PREFIX_PATH="<path to babble>;<path to opencolorio>;" -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```