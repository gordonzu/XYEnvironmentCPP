// TestData.cpp
// gordonzu 1/24/18

#include <memory>
#include "environment/xyenv/xy_environment.h"

class TestData {
public:
    TestData() {
        env     = new XYEnvironment(12, 10);
        agent   = new Agent();
        agent2  = new Agent();
        agent3  = new Agent();
        agent4  = new Agent();
        wall    = new Wall();
        loc     = std::make_unique<XYLocation>(3, 4);
        loc2    = std::make_unique<XYLocation>(3, 4);
        xy551   = std::make_unique<XYLocation>(5, 5);
        xy552   = std::make_unique<XYLocation>(5, 5);
        xy553   = std::make_unique<XYLocation>(5, 5);
        xy54    = std::make_unique<XYLocation>(5, 4);
        xy64    = std::make_unique<XYLocation>(6, 4);
        xy65    = std::make_unique<XYLocation>(6, 5);
        xy991   = std::make_unique<XYLocation>(9, 9);
        xy992   = std::make_unique<XYLocation>(9, 9);
    }

    ~TestData() {
        delete env;
        delete agent;
        delete agent2;
        delete agent3;
        delete agent4;
        delete wall;
    }

protected:
    std::unique_ptr<XYLocation> loc;
    std::unique_ptr<XYLocation> loc2;
    std::unique_ptr<XYLocation> xy551;
    std::unique_ptr<XYLocation> xy552;
    std::unique_ptr<XYLocation> xy553;
    std::unique_ptr<XYLocation> xy54;
    std::unique_ptr<XYLocation> xy64;
    std::unique_ptr<XYLocation> xy65;
    std::unique_ptr<XYLocation> xy991;
    std::unique_ptr<XYLocation> xy992;
    XYEnvironment*              env;
    Agent*                      agent;
    Agent*                      agent2;
    Agent*                      agent3;
    Agent*                      agent4;
    Wall*                       wall;
};









