#include <hpx/hpx_main.hpp>
#include <hpx/include/async.hpp>
#include <hpx/include/iostreams.hpp>
#include <hpx/include/lcos.hpp>
#include <hpx/include/util.hpp>

// This program does not compile. Replace the uses of funX below with a fitting
// function (i.e. fun1, fun2 or fun3).

void fun1(double x, int y)
{
    hpx::cout << "hello from fun1" << hpx::endl;
}

void fun2(hpx::future<hpx::util::tuple<hpx::shared_future<double>,
    hpx::shared_future<int>>> f)
{
    hpx::cout << "hello from fun2" << hpx::endl;
}

void fun3(hpx::shared_future<double> x, hpx::shared_future<int> y)
{
    hpx::cout << "hello from fun3" << hpx::endl;
}

int main()
{
    hpx::shared_future<double> f = hpx::make_ready_future(3.14);
    hpx::shared_future<int> g = hpx::make_ready_future(42);

    hpx::async(&funX, 3.14, 42);
    hpx::async(&funX, f.get(), g.get());
    hpx::when_all(f, g).then(&funX);
    hpx::dataflow(&funX, f, g);
    hpx::dataflow(hpx::util::unwrapping(&funX), f, g);

    return 0;
}
