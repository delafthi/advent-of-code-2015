set shell := ["bash", "-euo", "pipefail", "-c"]

BUILD_DIR := justfile_directory() / "build"

# Default command
@default:
    just --list

# Build a specific day's solution
@build target: configure
    cmake --build {{ BUILD_DIR }} --target {{ target }}

# Lint files
@check: clang-tidy cpp-check

# Lint files with clang-tidy
@clang-tidy: configure
    #!/usr/bin/env bash
    fd '.+\.(c|h)$' \
      | xargs -r -P$(nproc) clang-tidy \
        -p {{ BUILD_DIR }}

# Lint files with cppcheck
@cpp-check: configure
    #!/usr/bin/env bash
    fd '.+\.(c|h)$' \
      | xargs -r -P$(nproc) cppcheck \
        --check-level=exhaustive \
        --error-exitcode=1 \
        -i{{ BUILD_DIR }} \
        --inconclusive \
        --inline-suppr \
        --project={{ BUILD_DIR }}/compile_commands.json

# Remove the build directory and all compiled artifacts
@clean:
    rm -rf {{ BUILD_DIR }}

# Configure the CMake build system
@configure:
    cmake -S {{ justfile_directory() }} -B {{ BUILD_DIR }}

# Format all files with nix
@fmt:
    nix fmt

# Build and run a specific day's solution with interactive input
@run target: (build target)
    #!/usr/bin/env bash
    input=$(gum write --placeholder="Paste your input:")
    result=$(gum spin --title="Running {{ target }}..." --show-stdout -- {{ BUILD_DIR }}/{{ target }}/{{ target }} "$input")
    gum log "Your result is: $result"
