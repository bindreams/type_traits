"""Conan package manager config file. https://docs.conan.io/en/latest/"""
import re
from conans import ConanFile, CMake, tools


def get_project_version():
    try:
        content = tools.load("CMakeLists.txt")
        version = re.search(r"project\([^\)]+VERSION (\d+\.\d+\.\d+)[^\)]*\)", content).group(1)
        return version.strip()
    except Exception:
        return None


def get_project_name():
    try:
        content = tools.load("CMakeLists.txt")
        name = re.search(r"project\(([^\) ]+)[^\)]*\)", content).group(1)
        return name.strip()
    except Exception:
        return None


class Project(ConanFile):
    """Conan package file."""
    name = get_project_name()
    version = get_project_version()

    settings = "os", "compiler", "build_type", "arch"
    requires = ["doctest/2.3.7"]

    options = {
        "tests": [True, False],
        "examples": [True, False],
    }

    default_options = {
        "tests": False,
        "examples": False,
        "gtest:shared": False
    }

    scm = {
        "type": "git",
        "url": "auto",
        "revision": "auto",
        "submodule": "recursive"
    }
    
    generators = "cmake"

    def _cmake(self):
        cmake = CMake(self, generator="Ninja")
        cmake.definitions["CMAKE_EXPORT_COMPILE_COMMANDS"] = True

        if self.options.tests:
            cmake.definitions[self.name + "_BUILD_TESTS"] = True
        if self.options.examples:
            cmake.definitions[self.name + "_BUILD_EXAMPLES"] = True
        
        return cmake

    def build(self):
        cmake = self._cmake()

        cmake.configure()
        cmake.build()
        
    def package(self):
        self.copy(
            pattern="*license*", 
            dst="licenses", 
            excludes="tools/*", 
            ignore_case=True, 
            keep_path=False
        )

        cmake = self._cmake()

        cmake.configure()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = [self.name]

    def package_id(self):
        self.info.header_only()
