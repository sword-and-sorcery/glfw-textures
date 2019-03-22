from conans import ConanFile, CMake

class Tileset(ConanFile):
    name = "glfw_tileset"
    version = "0.0"

    settings = "os", "arch", "compiler", "build_type"
    options = {"shared": [True, False]}
    default_options = {"shared": False}

    generators = "cmake"

    scm = {"type": "git",
           "url": "auto",
           "revision": "auto"}

    def requirements(self):
        self.requires("glfw/3.2.1@bincrafters/stable")
        self.requires("tileset/0.0@sword/sorcery")
        self.requires("stb/20180214@conan/stable")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["glfw_tileset",]
