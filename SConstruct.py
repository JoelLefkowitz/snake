import os
import re
import psutil
from SCons.Environment import Environment
from SCons.Script import AddOption
from walkmate import get_child_files as tree

libs = [
    "gtest",
    "pthread",
    "SDL2",
]

warnings = [
    "-Wall",
    "-Wconversion",
    "-Wextra",
    "-Wmissing-declarations",
    "-Wpedantic",
    "-Wshadow-uncaptured-local",
    "-Wshadow",
    "-Wno-deprecated-declarations",
    "-Wno-macro-redefined",
    "-Wno-missing-braces",
    "-Wno-unknown-warning-option",
    "-Wno-unused-parameter",
    "-Wno-vla-extension",
    "-Wno-everything",
]

env = Environment(
    LIBS=libs,
    CXXFLAGS=["-std=c++17"],
    CPPPATH=os.getenv("CPPPATH"),
    LIBPATH=os.getenv("LIBPATH"),
    ENV={"PATH": os.getenv("PATH")},
    num_jobs=psutil.cpu_count(),
)

AddOption(
    "--iwyu",
    action="store_true",
)

AddOption(
    "--typecheck",
    action="store_true",
)

if GetOption("typecheck"):
    env["LINK"] = ":"
    env["CXXFLAGS"].extend(["-S", "-O0"])

elif GetOption("iwyu"):
    env["CXX"] = "include-what-you-use"

else:
    env["CXX"] = "clang++"
    env["CXXFLAGS"].extend(warnings)

find = lambda pattern: [
    source
    for source in tree(".")
    if re.search(
        pattern,
        source,
    )
]

env.Program(
    target="dist/build",
    source=find("(?<!test)(?<!\.spec)\.cpp$"),
)

env.Program(
    target="dist/tests",
    source=find("(?<!main)\.cpp$"),
)

env.Alias("build", "./dist/build")
env.Alias("tests", "./dist/tests")
