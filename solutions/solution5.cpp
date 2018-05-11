#include <hpx/hpx_main.hpp>
#include <hpx/include/iostreams.hpp>
#include <hpx/include/lcos.hpp>

int main()
{
    auto f = hpx::make_ready_future<int>(3);
    // hpx iostream errors are verbose
    hpx::cout << f.get() << hpx::endl;
}
