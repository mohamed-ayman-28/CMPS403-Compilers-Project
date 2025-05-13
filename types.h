#ifndef TYPES_H_
#define TYPES_H_


#define TAB_SIZE 1000
#define MAX_IDENTIFIER_NAME_LENGTH 64
#define MAX_TYPE_NAME_LENGTH 24


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
    RET,       // Consolidated RETURN and RET
    PARAM,     // Renamed PUSH to PARAM for clarity (assuming function parameter)
    FUNC,
    ENDFUNC,
    POP,       // Kept as extra instruction
    MOD
} InstructionType;

typedef enum InstructionOperandType {
    REGISTER,
    IMMEDIATE_VALUE,
    LABEL,
    MEM_ADDR
} InstructionOperandType;

typedef struct Quadruple {
    int address;
    InstructionType instruction_type;
    char* operand_1;
    InstructionOperandType operand_1_type;
    char* operand_2;
    InstructionOperandType operand_2_type;
    char* result;
    InstructionOperandType result_type;
} Quadruple;

// Forward declaration for Instruction
typedef struct Instruction Instruction;

struct Instruction {
    Quadruple quadruple;
    Instruction* next_instruction;
};


typedef struct Parameter {
    char name[MAX_IDENTIFIER_NAME_LENGTH + 1];
    char type[MAX_TYPE_NAME_LENGTH + 1];
    size_t array_length;
    struct Parameter *next;
} Parameter;

typedef union {
    int int_value;
    double float_value;
    char char_value;
    int* int_array;
    double* float_array;
    char* char_array;
    char** string_array;
    Instruction* function;
} Value;

typedef enum ValueType {
    INT_VALUE,
    FLOAT_VALUE,
    CHAR_VALUE,
    BOOL_VALUE,
    CHAR_ARRAY_VALUE,
    INT_ARRAY_VALUE,
    BOOL_ARRAY_VALUE,
    FLOAT_ARRAY_VALUE,
    STRING_ARRAY_VALUE,
    STRING_VALUE,
    FUNCTION
} ValueType;

typedef struct SymbolTableEntry {
    char name[MAX_IDENTIFIER_NAME_LENGTH + 1];
    char type[MAX_TYPE_NAME_LENGTH + 1];
    int scope_no;
    int line_no;
    Value value;
    ValueType value_type;
    int is_function;
    int is_constant;
    int array_length;
    Parameter* parameters;
    struct SymbolTableEntry* next_entry;
    char* enclosing_function_name;
} SymbolTableEntry;

typedef struct SymbolTable {
    SymbolTableEntry **buckets;
    int table_size;
    int entry_count;
} SymbolTable;


typedef enum EXPRESSION_TYPE {
    BOOL_EXPR,
    NUMERIC_EXPR,
    FLOAT_EXPR,
    INT_EXPR,
    FUNCTION_CALL_EXPR,
    ARRAY_ACCESS_EXPR,
    CHAR_EXPR,
    STRING_EXPR,
    IDENTIFIER_EXPR
} EXPRESSION_TYPE;


typedef struct Expr {
    EXPRESSION_TYPE expr_type;
    Value expr_value;
    ValueType expr_return_type;
    char* associated_identifier;
    size_t array_length;
} Expr;

typedef struct ExprList ExprList;

struct ExprList {
    Expr* e;
    ExprList* next_expr;
};

#endif