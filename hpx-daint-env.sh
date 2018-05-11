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
