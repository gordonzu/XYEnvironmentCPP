//
// Created by gordonzu on 4/24/18.

#include "agent/agent_programs/simple_rule/rule.h"
#include "agent/percept.h"
#include "gmock/gmock.h"
#include "agent/action.h"

using namespace::testing;

class SimpleRuleTest: public Test
{
public:
    static constexpr const char* ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING
            = "car-in-front-is-braking";
    static constexpr const char* ATTRIBUTE_CAR_IN_FRONT_IS_INDICATING
            = "car-in-front-is-indicating";
    static constexpr const char* ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING
            = "car-in-front-tires-smoking";

    ag::Action INITIATE_BRAKING;
    ag::Action EMERGENCY_BRAKING;
    EqualCondition eq;
    Rule rule;

    SimpleRuleTest():INITIATE_BRAKING("initiate-braking"),
                     EMERGENCY_BRAKING("emergency-braking"),
                     eq{ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, true},
                     rule{eq,INITIATE_BRAKING}
    {
    }
};

TEST_F(SimpleRuleTest, TestAction)
{
    ASSERT_EQ(rule.get_action(), INITIATE_BRAKING);
}

TEST_F(SimpleRuleTest, TestEqualRule)
{
    EqualCondition eq = EqualCondition(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, true);
    Rule r = Rule{eq, INITIATE_BRAKING};
    ASSERT_STREQ(r.string().c_str(),
                 "if car-in-front-is-braking==true then Action[name=initiate-braking].");
}

TEST_F(SimpleRuleTest, TestEvaluate)
{
    EqualCondition eq = EqualCondition(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, true);
    Rule r = Rule{eq, INITIATE_BRAKING};
    ASSERT_TRUE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "true")));
    ASSERT_FALSE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "false")));
    ASSERT_FALSE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_INDICATING, "true")));
}

TEST_F(SimpleRuleTest, TestNotRule)
{
    EqualCondition e = EqualCondition{ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, true};
    NotCondition n = NotCondition{e};
    Rule r = Rule{n, INITIATE_BRAKING};

    ASSERT_EQ(r.get_action(), INITIATE_BRAKING);

    ASSERT_STREQ(r.string().c_str(),
                 "if ![car-in-front-is-braking==true] then Action[name=initiate-braking].");

    ASSERT_FALSE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "true")));
    ASSERT_TRUE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "false")));
    ASSERT_TRUE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_INDICATING, "true")));
}

TEST_F(SimpleRuleTest, TestAndRule)
{
    EqualCondition e1 = EqualCondition{ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, true};
    EqualCondition e2 = EqualCondition{ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, true};
    AndCondition a = AndCondition(e1, e2);
    Rule r = Rule(a, EMERGENCY_BRAKING);

    ASSERT_EQ(r.get_action(), EMERGENCY_BRAKING);
    ASSERT_STREQ(r.string().c_str(),
    "if [car-in-front-is-braking==true && car-in-front-tires-smoking==true] "
            "then Action[name=emergency-braking].");

    ASSERT_FALSE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "true")));
    ASSERT_FALSE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, "true")));
    ASSERT_TRUE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "true",
                                    ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, "true")));
    ASSERT_FALSE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "false",
                                    ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, "true")));
    ASSERT_FALSE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "true",
                                    ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, "false")));

}

TEST_F(SimpleRuleTest, TestOrRule)
{
    EqualCondition e1 = EqualCondition{ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, true};
    EqualCondition e2 = EqualCondition{ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, true};
    OrCondition o = OrCondition(e1, e2);
    Rule r = Rule{o, EMERGENCY_BRAKING};

    ASSERT_EQ(r.get_action(), EMERGENCY_BRAKING);
    ASSERT_STREQ(r.string().c_str(),
    "if [car-in-front-is-braking==true || car-in-front-tires-smoking==true] "
            "then Action[name=emergency-braking].");

    ASSERT_TRUE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "true")));
    ASSERT_TRUE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, "true")));
    ASSERT_TRUE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "true",
                                   ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, "true")));
    ASSERT_TRUE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "false",
                                   ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, "true")));
    ASSERT_TRUE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "true",
                                   ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, "false")));
    ASSERT_FALSE(r.evaluate(Percept(ATTRIBUTE_CAR_IN_FRONT_IS_BRAKING, "false",
                                   ATTRIBUTE_CAR_IN_FRONT_TIRES_SMOKING, "false")));
}















