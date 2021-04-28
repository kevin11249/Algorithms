#include "./Container/Bag.h"
#include "./Container/Stack.h"

#include "./Graph/Graph.h"

#define BOOST_TEST_MODULE VsidCommonTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(container_test)

BOOST_AUTO_TEST_CASE(stack)
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);

}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(graph_test)

BOOST_AUTO_TEST_CASE(graph)
{
    Graph graph{2};
    graph.addEdge(0,1);
    std::cout << graph.getE() << " " << graph.getV() << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()