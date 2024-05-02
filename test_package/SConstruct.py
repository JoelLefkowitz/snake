from miniscons import Build, Target, Tasks, conan, flags, packages
from walkmate import tree

env = conan()

tests = Build(
    "tests",
    tree(".", r"\.cpp$", ["main.cpp"]),
    flags("c++17"),
    packages(["gtest"]),
)

cli = Tasks(
    [tests],
    [Target("test", tests, ["--gtest_brief"])],
)

cli.register(env)
