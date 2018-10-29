@rem if you need a special version vs 

@rem SET DEV_TOOLS_MSVC="" 
@rem call %DEV_TOOLS_MSVC% amd64

@rem path to qt
SET CMAKE_PREFIX_PATH=""

@rem path to vcpkg (or other toolchain) if necessary
SET CMAKE_TOOLCHAIN_FILE=""


mkdir build
mkdir build\msvc2017x64
cd build\msvc2017x64
cmake ..\..\src -DCMAKE_TOOLCHAIN_FILE=%CMAKE_TOOLCHAIN_FILE% -DCMAKE_PREFIX_PATH=%CMAKE_PREFIX_PATH% -G"Visual Studio 15 2017 Win64"
pause