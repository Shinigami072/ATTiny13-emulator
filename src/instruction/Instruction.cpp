//
// Created by shinigami on 31/05/18.
//

#include "Instruction.h"


emulator::Instruction::Instruction(const char *mask,const std::string& group,const std::string& mnemonic)
        :instrMask(0),kMask(0),KMask(0),instrVal(0),grp(group),mnem(mnemonic){
    //sprawdzenie czy maska ma odpowiednią długość
    if(strlen(mask)!=16)
        throw std::invalid_argument("Mask must be exactly 16char long");

    //todo: optimize mask creation
    //utworzenie podstawowych masek
    for(size_t i=0;i<16;i++)
        switch(mask[i]) {
            case '1':
                instrMask |= 1u << 15-i;
                instrVal |=1u << 15-i;
                break;
            case '0':
                instrMask |= 1u << 15-i;
                break;
            case 'K':
                KMask |= 1u << 15-i;
                break;
            case 'k':
                kMask |= 1u << 15-i;
                break;
            default:;
    }
}
