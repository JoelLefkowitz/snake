import os
import re
import psutil
from walkmate import get_child_files
from emoji import emojize
from SCons.Environment import Environment
from SCons.Script import AddOption


def report(action, emoji):
    return emojize(f":{emoji}: {action} $TARGET")


def prefix(segment, strings):
    return list(map(lambda x: segment + x, strings))


def sources(pattern):
    return [i for i in get_child_files(".") if re.search(pattern, i)]


flags = [
    "-std=c++17",
    "-fvisibility=hidden",
]

libs = [
    "gtest",
    "SDL2",
]

warnings = prefix(
    "-W",
    [
        "all",
        "conversion",
        "extra",
        "missing-declarations",
        "pedantic",
        "shadow-uncaptured-local",
        "shadow",
    ],
)

ignore = prefix(
    "-Wno-",
    [
        "deprecated-declarations",
        "macro-redefined",
        "missing-braces",
        "unknown-warning-option",
        "unused-parameter",
        "vla-extension",
        "everything",
    ],
)

env = Environment(
    CXX="clang++",
    LIBS=libs,
    CPPPATH=[os.getenv("CPPPATH", "/opt/homebrew/include")],
    LIBPATH=[os.getenv("LIBPATH", "/opt/homebrew/lib")],
    CPPFLAGS=" ".join(warnings + ignore),
    CXXFLAGS=" ".join(flags),
    CXXCOMSTR=report("Compiling", "wrench"),
    LINKCOMSTR=report("Linking", "link"),
)

AddOption("--iwyu", action="store_true")
AddOption("--typecheck", action="store_true")

if GetOption("iwyu"):
    env.Replace(CXX="/opt/homebrew/bin/include-what-you-use")

if GetOption("typecheck"):
    env.Replace(
        LINK=":",
        CXXFLAGS=" ".join(flags + ["-S", "-O0"]),
        CXXCOMSTR=report("Checking", "microscope"),
    )

env["num_jobs"] = psutil.cpu_count()

env.Program(target="./dist/build", source=sources("(?<!test)(?<!\.spec)\.cpp$"))
env.Program(target="./dist/tests", source=sources("(?<!main)\.cpp$"))

env.Alias("build", "./dist/build")
env.Alias("test", "./dist/tests")
