//
// Created by gordonzu on 4/24/18.
//
#include "gmock/gmock.h"
#include "agent/base_action.h"


using namespace::testing;

class SimpleRuleTest: public Test
{
public:
    static constexpr const char* ATTRIBUTE_CAR_IN_FRONT_IS_BREAKING   = "car-in-front-is-breaking";
    static constexpr const char* ATTRIBUTE_CAR_IN_FRONT_IS_INDICATING = "car-in-front-is-indicating";
    static constexpr const char* ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING = "car-in-front-tires-smoking";

    std::unique_ptr<DynamicAction> ACTION_INITIATE_BREAKING;
    std::unique_ptr<DynamicAction> ACTION_EMERGENCY_BREAKING;

    SimpleRuleTest():ACTION_INITIATE_BREAKING {
                         std::make_unique<DynamicAction>("initiate-breaking")},
                     ACTION_EMERGENCY_BREAKING{
                         std::make_unique<DynamicAction>("emergency-breaking")}
    {
    }
};

TEST_F(SimpleRuleTest, TestEQUALRule)
{
    /*
    Rule r = Rule{EQUALCondition{ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, true},
                  ACTION_INITIATE_BREAKING};
    ASSERT_
    */
    ASSERT_TRUE(true);
}

