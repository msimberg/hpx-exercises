#include <hpx/hpx_main.hpp>
#include <hpx/include/async.hpp>
#include <hpx/include/iostreams.hpp>

int main()
{
    auto f = hpx::async([](){});

    f.then([](hpx::future<void>) { hpx::cout << "Hello from first lambda" << hpx::endl; });
    f.then([](hpx::future<void>) { hpx::cout << "Hello from second lambda" << hpx::endl; });
}
