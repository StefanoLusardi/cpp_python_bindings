import os
import subprocess
import sys
import glob

from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

class CMakeExtension(Extension):
    def __init__(self, name, sourcedir=""):
        Extension.__init__(self, name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)

class CMakeBuild(build_ext):
    def build_extension(self, ext):
        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
        
        if not extdir.endswith(os.path.sep):
            extdir += os.path.sep

        cfg = "Release"
        cmake_build_args = [ "-j8", "--config", cfg ]
        cmake_configure_args = [
            "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={}".format(extdir),
            "-DPYTHON_EXECUTABLE={}".format(sys.executable),
            "-DCMAKE_BUILD_TYPE={}".format(cfg),
            "-DEXAMPLE_VERSION_INFO={}".format(self.distribution.get_version())
        ]

        if self.compiler.compiler_type == "msvc":
            cmake_win_platform = { "win32": "Win32", "win-amd64": "x64", "win-arm32": "ARM", "win-arm64": "ARM64" }
            cmake_configure_args += ["-A", cmake_win_platform[self.plat_name]]
            cmake_configure_args += ["-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{}={}".format(cfg.upper(), extdir)]
        else:
            try:
                subprocess.check_call(["ninja", "--version"])
                cmake_configure_args += ["-GNinja"]
            except subprocess.CalledProcessError as error:
                print error
                pass

        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)

        subprocess.check_call(["cmake", ext.sourcedir] + cmake_configure_args, cwd=self.build_temp)
        subprocess.check_call(["cmake", "--build", "."] + cmake_build_args, cwd=self.build_temp)


def data_files():
    # Explicitly add Windows shared libs (.dll) as data_files
    if sys.platform == "win32":
        return [("", glob.glob(f"**/*.dll", recursive=True))]
    
    # Linux shared libraries (.so) are already included
    return []

setup(
    name="cxxlib",
    version="0.0.7",
    author="Stefano Lusardi",
    author_email="lusardi.stefano@gmail.com",
    description="A test project using pybind11 and CMake",
    ext_modules=[CMakeExtension("cpp_python_bindings")],
    cmdclass={"build_ext": CMakeBuild},
    zip_safe=False,
    data_files=data_files(),
)
