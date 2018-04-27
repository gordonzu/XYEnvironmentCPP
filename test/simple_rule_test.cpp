//
// Created by gordonzu on 4/24/18.
//
#include "gmock/gmock.h"
#include "agent/action.h"


using namespace::testing;

class SimpleRuleTest: public Test
{
public:
    static constexpr const char* ATTRIBUTE_CAR_IN_FRONT_IS_BREAKING   = "car-in-front-is-breaking";
    static constexpr const char* ATTRIBUTE_CAR_IN_FRONT_IS_INDICATING = "car-in-front-is-indicating";
    static constexpr const char* ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING = "car-in-front-tires-smoking";

    std::unique_ptr<ag::Action> ACTION_INITIATE_BREAKING;
    std::unique_ptr<ag::Action> ACTION_EMERGENCY_BREAKING;

    SimpleRuleTest():ACTION_INITIATE_BREAKING {
                         std::make_unique<ag::Action>("initiate-breaking")},
                     ACTION_EMERGENCY_BREAKING{
                         std::make_unique<ag::Action>("emergency-breaking")}
    {
    }
};

TEST_F(SimpleRuleTest, TestEQUALRule)
{
   ASSERT_TRUE(true);
}
    /*
    Rule r = Rule{EQUALCondition{ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, true},
                  ACTION_INITIATE_BREAKING};
    ASSERT_
    */

