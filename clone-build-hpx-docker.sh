git clone https://github.com/STEllAR-GROUP/hpx.git

cd hpx
git checkout 1.1.0

mkdir -p build/RelWithDebInfo
cd build/RelWithDebInfo
cmake \
    -DCMAKE_BUILD_TYPE=RelWithDebInfo \
    -DCMAKE_CXX_FLAGS="-fPIC" \
    -DHPX_WITH_MORE_THAN_64_THREADS=On \
    -DHPX_WITH_MAX_CPU_COUNT=128 \
    ../..
make all
