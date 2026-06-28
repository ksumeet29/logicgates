#!/usr/bin/env python3

import shutil
import subprocess
import sys
from pathlib import Path


def main() -> int:
    if len(sys.argv) != 3:
        print(f"Usage: python3 {sys.argv[0]} <firstnumber> <secondnumber>",
              file=sys.stderr)
        return 1

    first, second = sys.argv[1], sys.argv[2]

    project_dir = Path(__file__).resolve().parent
    build_dir = project_dir / "build"

    try:
        # mkdir build
        build_dir.mkdir(exist_ok=True)

        # cd build && cmake ..
        subprocess.run(["cmake", ".."], cwd=build_dir, check=True)

        # cmake --build .
        subprocess.run(["cmake", "--build", "."], cwd=build_dir, check=True)

        # ./logicgate <firstnumber> <secondnumber>
        executable = build_dir / "logicgate"
        subprocess.run([str(executable), first, second],
                       cwd=build_dir, check=True)
    except subprocess.CalledProcessError as exc:
        print(f"Command failed with exit code {exc.returncode}",
              file=sys.stderr)
        return exc.returncode
    finally:
        # rm -rf build (runs even if a step above fails)
        shutil.rmtree(build_dir, ignore_errors=True)

    return 0


if __name__ == "__main__":
    sys.exit(main())