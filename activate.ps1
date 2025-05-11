Set-Location $PSScriptRoot

# refresh the build directory
Remove-Item build -Recurse -Force
mkdir build
Set-Location build

# configure cmake with ninja and clang (my setup)
cmake -G Ninja `
    -DCMAKE_C_COMPILER=clang `
    -DCMAKE_CXX_COMPILER=clang++ `
    -DCMAKE_BUILD_TYPE=Debug `
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON `
    ..

# build the executable file
ninja

Set-Location ..