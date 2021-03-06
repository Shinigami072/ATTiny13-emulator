//
// Created by shinigami on 09/06/18.
//

#ifndef ATTINY13_EMULATOR_OR_H
#define ATTINY13_EMULATOR_OR_H

#include "../Instruction.h"

namespace emulator{
    class OR: public TwoOperand{
    public:
        OR():TwoOperand( "001010rdddddrrrr","[ALU]","OR"){}

        void execute(ATtiny13& at,uint16_t instruction) const override{
            auto RdVal = getRegisterRD(instruction);//uint8_t (uint(instruction&RdMask)>>4u);
            auto RrVal = getRegisterRR(instruction);//utils::isSet<9>(instruction&RrMask)?static_cast<uint8_t>(((instruction&RrMask)^(1u<<10))|(1u<<4)):static_cast<uint8_t>(instruction&RrMask);

            //SREG ITHSVNZC
            //V = 0
            //N = R7
            //S = N
            //Z = R ==0

            uint8_t R = at.memory.GP(RdVal)|at.memory.GP(RrVal);

            bool R7  =utils::isSet<7>(R);
            bool N=R7;

            at.memory.SREG.setBool(R ==0,1);//Z
            at.memory.SREG.setBool(N,2);//S
            at.memory.SREG.setBool(N,3);//N
            at.memory.SREG.setBool(false,4);//V

            at.memory.GP(RdVal)=R;
            at.PC++;
        }
    };
};
#endif //ATTINY13_EMULATOR_OR_H
