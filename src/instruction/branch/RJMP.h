//
// Created by shinigami on 01/06/18.
//

#ifndef ATTINY13_EMULATOR_RJMP_H
#define ATTINY13_EMULATOR_RJMP_H
#include "../Instruction.h"
#include "../../Utils.h"
namespace emulator{

    //skok relatywny
    class RJMP: public Instruction {
    public:
        RJMP():Instruction("1100kkkkkkkkkkkk","[BRN]","RJMP"){}

        void dump(const ATtiny13 &at, uint16_t instruction, int PC, std::ostream &out) override{
            auto jmp = 1+utils::U2<12>(instruction&kMask)+static_cast<uint16_t>(PC);

            out<<"RJMP"<<" "<<jmp<<std::endl;
        }
        void execute(ATtiny13& at,uint16_t instruction) const override{
            at.PC+=1+utils::U2<12>(instruction&kMask);
        }

    };
}


#endif //ATTINY13_EMULATOR_RJMP_H
