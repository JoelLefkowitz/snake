from conan import ConanFile
from conan.tools.files import copy
from conan.tools.scons import SConsDeps


class Recipe(ConanFile):
    name = "snake"
    version = "0.3.3"

    requires = [
        "sdl/2.28.3",
    ]

    def build_requirements(self):
        self.test_requires("gtest/1.12.1")

    def generate(self):
        SConsDeps(self).generate()
