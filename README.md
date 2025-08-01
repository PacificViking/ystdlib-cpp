# ystdlib

An open-source C++ library developed and used at YScope.

# Usage

First, [build](#building) and [install](#installing) `ystdlib` onto your system. Then, in your
project's `CMakeLists.txt`, add the following:

```cmake
find_package(ystdlib REQUIRED)
target_link_libraries(<target_name>
    [<link-options>]
    ystdlib::<lib_1>
    [ystdlib::<lib_2> ... ystdlib::<lib_N>]
)
```

Where

* `<target_name>` is the name of your target.
* `<link-options>` are the link options for your target.
* `lib_1`, `lib_2`, ..., `lib_N` are the names of the ystdlib libraries you wish to link with your
  target.

> [!NOTE]
> If `BUILD_TESTING` is `ON`, set `ystdlib_BUILD_TESTING` to `OFF` to skip building ystdlib's unit
> tests.

> [!TIP]
> If ystdlib is not installed to a path that is searched by default, set `ystdlib_ROOT` to manually
> specify the location:
> 
> ```cmake
> set(ystdlib_ROOT "<PATH_TO_INSTALLATION>")
> ```

# Contributing
Follow the steps below to develop and contribute to the project.

## Requirements

* CMake 3.23 or higher
* Python 3.10 or higher
* [Task] 3.40.0 or higher

## Set up
Initialize and update submodules:
```shell
git submodule update --init --recursive
```

If you want to open the project in an IDE, run the following command to install any necessary
dependencies from source:
```shell
task deps:install-all
```

## Building

The library can be built directly using [CMake](#using-cmake) or indirectly using
[Task](#using-task).

### Using Task

To build all targets:
```shell
task build:all
```

To build an executable containing all unit tests:
```shell
task build:unit-test-all
```

To build an executable containing a single library's unit tests:
```shell
task build:unit-test-<lib_name>
```

### Using CMake

To build all libraries, run:

```shell
cmake -S . -B ./build
cmake --build ./build
```

To build a subset of libraries, set the variable `ystdlib_LIBRARIES` to a semicolon-separated (`;`)
list of library names. The library names match their [directory name in src/](./src/ystdlib). For
example:

```shell
cmake -S . -B ./build -Dystdlib_LIBRARIES="containers;io_interface"
cmake --build ./build
```

> [!NOTE]
> Internal dependencies of the libraries you choose will be automatically built, even if you don't
> explicitly specify them. In the example, specifying `io_interface` automatically adds
> `wrapped_facade_headers` to the build.

## Installing

After [building](#building), install with:

```shell
cmake --install "./build" --prefix "$HOME/.local"
```

## Testing
To build and run all unit tests:
```shell
task test-all
```

To build and run unit tests for a specific library:
```shell
task test-<lib_name>
```

When generating a testing target, the CMake variable `BUILD_TESTING` is followed (unless overruled
by setting `ystdlib_BUILD_TESTING` to false). By default, if built as a top-level project,
`BUILD_TESTING` is set to true and unit tests are built.

## Linting
Before submitting a pull request, ensure you’ve run the linting commands below and have fixed all
violations and suppressed all warnings.

To run all linting checks:
```shell
task lint:check
```

To run all linting checks AND fix some violations:
```shell
task lint:fix
```

To see how to run a subset of linters for a specific file type:
```shell
task -a
```
Look for all tasks under the `lint` namespace (identified by the `lint:` prefix).

[Task]: https://taskfile.dev
