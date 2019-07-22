from conans import ConanFile, CMake

class Tileset(ConanFile):
    name = "ui-tileset-glfw"
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
        self.requires("stb/20180214@conan/stable", private=True)
        self.requires("ui-tileset/0.0@sword/sorcery")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.install()

    def package(self):
        self.copy("LICENSE", dst="licenses")

    def package_info(self):
        self.cpp_info.libs = ["tileset_glfw",]
