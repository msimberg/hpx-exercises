export CRAYPE_LINK_TYPE=dynamic
module load daint-mc
module load CMake
module switch PrgEnv-cray PrgEnv-gnu
module load Boost
module load hwloc

export CXX=`which CC`
export CXXFLAGS="-fPIC"
export TCMALLOC_ROOT=/apps/daint/UES/simbergm/packages/gperftools/2.6.3

export LIBPYTHON_PATH=/usr/lib64/libpython2.7.so.1.0

git clone https://github.com/STEllAR-GROUP/hpx.git

cd hpx
git checkout 1.1.0

mkdir -p build/RelWithDebInfo
cd build/RelWithDebInfo
cmake \
    -DCMAKE_BUILD_TYPE=RelWithDebInfo \
    -DHPX_WITH_MORE_THAN_64_THREADS=ON \
    -DHPX_WITH_MAX_CPU_COUNT=128 \
    ../..
make -j all
