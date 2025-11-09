#!/bin/bash
set -euo pipefail

PROJECT_ROOT="${KOS_PROJECT_ROOT:-/workspace}"

if [ ! -d "${PROJECT_ROOT}" ]; then
    echo "Project root '${PROJECT_ROOT}' недоступен (смонтируй репозиторий в контейнер)." >&2
    exit 1
fi

cd "${PROJECT_ROOT}"

cmd="${1:-shell}"
if [ $# -gt 0 ]; then
    shift
fi

run_build () {
    ./cross-build.sh "$@"
    cmake --build build
}

case "${cmd}" in
    shell)
        exec "${SHELL:-/bin/bash}" "$@"
        ;;
    clean)
        rm -rf build CMakeCache.txt CMakeFiles
        ;;
    build)
        run_build "$@"
        ;;
    image)
        run_build "$@"
        cmake --build build --target kos-qemu-image
        ;;
    run)
        run_build "$@"
        cmake --build build --target run
        ;;
    *)
        exec "${cmd}" "$@"
        ;;
esac
