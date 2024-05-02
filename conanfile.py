from conan import ConanFile
from conan.tools.files import copy
from conan.tools.scons import SConsDeps


class Recipe(ConanFile):
    name = "snake"
    version = "0.3.3"

    def build_requirements(self):
        self.test_requires("gtest/1.12.1")

    def export_sources(self):
        for source in ["src/*.[cht]pp", "SConstruct.py"]:
            copy(
                self,
                source,
                self.recipe_folder,
                self.export_sources_folder,
            )

    def generate(self):
        SConsDeps(self).generate()

    def build(self):
        self.run("scons shared")

    def package(self):
        copy(
            self,
            "*.[ht]pp",
            f"{self.build_folder}/src",
            f"{self.package_folder}/include/{self.name}",
        )
        copy(
            self,
            "*.a",
            f"{self.build_folder}/dist",
            f"{self.package_folder}/lib",
        )

    def package_info(self):
        self.cpp_info.libs = [self.name]
