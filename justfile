BUILD_DIR := justfile_directory() / "build"

# Default command
default:
    @just --list

# Build a specific day's solution
build dir: configure
    @cmake --build {{ BUILD_DIR }} --target {{ dir }}

# Remove the build directory and all compiled artifacts
clean:
    @rm -rf {{ BUILD_DIR }}

# Configure the CMake build system
configure:
    @cmake -S {{ justfile_directory() }} -B {{ BUILD_DIR }}

# Build and run a specific day's solution with interactive input
test dir: (build dir)
    #!/usr/bin/env bash
    set -euo pipefail
    input=$(gum write --placeholder="Paste your input:")
    result=$(gum spin --title="Running {{ dir }}..." --show-stdout -- {{ BUILD_DIR }}/{{ dir }}/{{ dir }} "$input")
    gum log "Your result is: $result"
