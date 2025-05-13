#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"


Instruction* create_instruction(InstructionType type, 
                              char* op1, InstructionOperandType op1_type,
                              char* op2, InstructionOperandType op2_type,
                              char* result, InstructionOperandType result_type) {
    Instruction* instr = (Instruction*)malloc(sizeof(Instruction));
    if (!instr) {
        fprintf(stderr, "Memory allocation for instruction failed\n");
        exit(1);
    }
    instr->quadruple.address = -1; // Address will be assigned later
    instr->quadruple.instruction_type = type;
    instr->quadruple.operand_1 = op1 ? strdup(op1) : NULL;
    instr->quadruple.operand_1_type = op1_type;
    instr->quadruple.operand_2 = op2 ? strdup(op2) : NULL;
    instr->quadruple.operand_2_type = op2_type;
    instr->quadruple.result = result ? strdup(result) : NULL;
    instr->quadruple.result_type = result_type;
    instr->next_instruction = NULL;
    return instr;
}

void append_instruction(Instruction** list, Instruction* new_instr) {
    if (!new_instr) {
        fprintf(stderr, "Cannot append NULL instruction\n");
        return;
    }
    if (!*list) {
        *list = new_instr;
    } else {
        Instruction* current = *list;
        while (current->next_instruction) {
            current = current->next_instruction;
        }
        current->next_instruction = new_instr;
    }
}

void free_instruction(Instruction* instr) {
    if (!instr) return;
    if (instr->quadruple.operand_1) free(instr->quadruple.operand_1);
    if (instr->quadruple.operand_2) free(instr->quadruple.operand_2);
    if (instr->quadruple.result) free(instr->quadruple.result);
    Instruction* next = instr->next_instruction;
    free(instr);
    free_instruction(next); // Recursively free the linked list
}

#endif