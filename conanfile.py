import os

from conan import ConanFile
from conan.tools.files import copy
from conan.tools.scons import SConsDeps
from conan.tools.layout import basic_layout


class SnakeConan(ConanFile):
    version = "0.3.3"

    requires = ("sdl/2.28.3",)

    def build_requirements(self):
        self.test_requires("gtest/1.12.1")

    def generate(self):
        SConsDeps(self).generate()
