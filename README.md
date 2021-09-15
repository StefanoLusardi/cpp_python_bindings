# cpp_python_bindings
An example project to show how provide Python bindings for a C++ library using pybind11.

Content:
- Standalone C++ library
  - [CMake](https://cmake.org/)-based
  - Fully cross platform (Linux, Windows and MacOS)
  - Use of [Conan](https://conan.io/) package manager for 3rd party dependencies
- C++ Unit Tests
  - [GoogleTest](https://github.com/google/googletest)
- C++ Examples
  - Usage of the standalone library in a pure C++ project
- Python module (C++ library wrapper)
  - Based on [pybind11](https://github.com/pybind/pybind11)
  - Use [setuptools](https://pypi.org/project/setuptools/) to build, test and install locally 
- CI Build Pipeline
  - Based on [Azure DevOps Build Pipelines](https://dev.azure.com/stefanolusardi/cpp_python_bindings/_build)
  - Support for Python 3.6, 3.7, 3.8, 3.8 and 3.10 using [cibuildwheel](https://github.com/pypa/cibuildwheel)
  - Badges  
- CD Release Pipeline
  - Based on [Azure DevOps Release Pipelines](https://dev.azure.com/stefanolusardi/cpp_python_bindings/_release)
  - Upload on [Test PyPi](https://test.pypi.org/) and [PyPi](https://pypi.org/)
  - Badges 

| OS | Status |
|:-----------:|----------------------|
|![Linux Icon](https://img.shields.io/badge/Linux-black?style=for-the-badge&logo=linux&logoColor=white)|[![Build Status](https://dev.azure.com/stefanolusardi/cpp_python_bindings/_apis/build/status/build?branchName=main&jobName=linux)](https://dev.azure.com/stefanolusardi/cpp_python_bindings/_build/latest?definitionId=18&branchName=main)|
|![Windows Icon](https://img.shields.io/badge/Windows-black?style=for-the-badge&logo=windows&logoColor=white)|[![Build Status](https://dev.azure.com/stefanolusardi/cpp_python_bindings/_apis/build/status/build?branchName=main&jobName=windows)](https://dev.azure.com/stefanolusardi/cpp_python_bindings/_build/latest?definitionId=18&branchName=main)|
|![MacOS Icon](https://img.shields.io/badge/Mac%20OS-black?style=for-the-badge&logo=apple&logoColor=white)|[![Build Status](https://dev.azure.com/stefanolusardi/cpp_python_bindings/_apis/build/status/build?branchName=main&jobName=macos)](https://dev.azure.com/stefanolusardi/cpp_python_bindings/_build/latest?definitionId=18&branchName=main)|
