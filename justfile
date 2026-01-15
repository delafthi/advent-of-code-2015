export BUILD_DIR := justfile_directory() / "build"

test DAY: (build DAY)
    #!/usr/bin/env bash
    set -euo pipefail
    input=$(gum write --placeholder="Paste your input:")
    result=$(gum spin {{ BUILD_DIR }}/{{ DAY }} "$input" --show-stdout)
    gum log "Your result is: $result"

build DAY:
    @mkdir -p {{ BUILD_DIR }}
    @cc {{ justfile_directory() }}/{{ DAY }}/*.c -o {{ BUILD_DIR }}/{{ DAY }}

clean:
    @rm -rf {{ BUILD_DIR }}
