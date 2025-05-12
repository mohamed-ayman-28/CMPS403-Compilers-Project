#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum InstructionType {
    JMP,
    NEG,
    ADD,
    SUB,
    MUL,
    DIV,
    MOV,
    CMP,
    JGT,
    JLT,
    JEQ,
    JNE,
    JGE,
    JLE,
    AND,
    NOT,
    OR,
    CALL,
    RETURN,
    RET,
    PUSH, // THE ACTUAL NAME IN THE DOCUMENT WAS PARAM
    FUNC,
    ENDFUNC,

    // EXTRA (NOT IN THE DOCUMENT)
    POP,
    MOD
};

typedef enum InstructionOperandType {
    REGISTER,
    IMMEDIATE_VALUE,
    LABEL,
    MEM_ADDR
};

typedef struct Quadruple {
    int address;
    InstructionType  instruction_type;
    char* operand_1;
    char* operand_2;
    char* result;
};

typedef struct Instruction {
    Quadruple quadruple;
    Instruction* next_instruction;
};

Instruction* create_instruction(InstructionType type, char* op1, char* op2, char* result) {
    Instruction* instr = (Instruction*)malloc(sizeof(Instruction));
    if (!instr) {
        fprintf(stderr, "Memory allocation for instruction failed\n");
        exit(1);
    }
    instr->quadruple.address = -1; // Address will be assigned later
    instr->quadruple.instruction_type = type;
    instr->quadruple.operand_1 = op1 ? strdup(op1) : NULL;
    instr->quadruple.operand_2 = op2 ? strdup(op2) : NULL;
    instr->quadruple.result = result ? strdup(result) : NULL;
    instr->next_instruction = NULL;
    return instr;
}

void append_instruction(Instruction** list, Instruction* new_instr) {
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

#endif