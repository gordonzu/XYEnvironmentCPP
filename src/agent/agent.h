//
// Created by gordonzu on 4/1/18.
//

#ifndef AICPP_AGENT_H
#define AICPP_AGENT_H

#include "object.h"
#include "action.h"


    class NoOpAction: public Action {
        NoOpAction() = default;

    public:
        bool is_no_op() { return false; }
        static NoOpAction& NO_OP;
    };

///////////////////////////////////////////////////////////////////////

    class Percept {

    };

////////////////////////////////////////////////////////////////////////

    class AgentProgram {
    public:
        virtual ~AgentProgram() {}
        virtual const Action& execute(Percept p)=0;
    };

/////////////////////////////////////////////////////////////////////////

    class TableDrivenProgram: public AgentProgram {

    public:
        NoOpAction noOp;

        virtual ~TableDrivenProgram() = default;

        virtual const Action& execute(Percept p) {
            return noOp;
        }

    };

///////////////////////////////////////////////////////////////////////////

    class Agent : public Object {
        AgentProgram* program;

    public:
        Agent() {}
        Agent(AgentProgram* p) {
            program = p;
        }

        virtual ~Agent() {
            //delete program;
        }

        char *talk() {
            return const_cast<char *>("Agent...");
        }

        /*const Action& execute(Percept p) {
            if (program)
                return program->execute(p);
            return NoOpAction::NO_OP;
        }*/

        const char* execute(Percept p) {
            //if (program)
                return "name";
            //return NoOpAction::NO_OP;
        }


    };

/////////////////////////////////////////////////////////////////////////////////



#endif //AICPP_AGENT_H
