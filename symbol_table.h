#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAB_SIZE 1000
#define MAX_IDENTIFIER_NAME_LENGTH 64
#define MAX_TYPE_NAME_LENGTH 24

int scope_no = -1;

typedef struct Parameter {
    char name[MAX_IDENTIFIER_NAME_LENGTH + 1];
    char type[MAX_TYPE_NAME_LENGTH + 1];
    struct Parameter *next;
} Parameter;

typedef union {
    int int_value;
    double float_value;
    char char_value;
    int* int_array;
    double* float_array;
    char* char_array;
    void* function;
} Value;

typedef enum {
    INT_VALUE,
    FLOAT_VALUE,
    CHAR_VALUE,
    CHAR_ARRAY_VALUE,
    INT_ARRAY_VALUE,
    FLOAT_ARRAY_VALUE,
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
    Parameter* parameters;
    struct SymbolTableEntry* next_entry;
} SymbolTableEntry;

typedef struct SymbolTable {
    SymbolTableEntry **buckets;
    int table_size;
    int entry_count;
} SymbolTable;

SymbolTable* create_symbol_table() {
    SymbolTable* symbol_table = (SymbolTable*)malloc(sizeof(SymbolTable));
    if (!symbol_table) {
        fprintf(stderr, "Memory allocation of symbol table failed\n");
        exit(1);
    }
    symbol_table->table_size = TAB_SIZE;
    symbol_table->entry_count = 0;
    symbol_table->buckets = (SymbolTableEntry**)calloc(symbol_table->table_size, sizeof(SymbolTableEntry*));
    if (!symbol_table->buckets) {
        fprintf(stderr, "Memory allocation of symbol table buckets failed\n");
        free(symbol_table);
        exit(1);
    }
    return symbol_table;
}

unsigned long hash(const char *str, int table_size) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % table_size;
}

Parameter* create_parameter(const char *name, const char *type) {
    Parameter *param = (Parameter *)malloc(sizeof(Parameter));
    if (!param) {
        fprintf(stderr, "Memory allocation of parameter failed\n");
        exit(1);
    }
    strncpy(param->name, name, MAX_IDENTIFIER_NAME_LENGTH);
    param->name[MAX_IDENTIFIER_NAME_LENGTH] = '\0';
    strncpy(param->type, type, MAX_TYPE_NAME_LENGTH);
    param->type[MAX_TYPE_NAME_LENGTH] = '\0';
    param->next = NULL;
    return param;
}

SymbolTableEntry* insert_symbol(SymbolTable* table, const char* name, const char* type, Value value, ValueType value_type, int scope_no, int is_function, Parameter* parameters, int line_no, size_t array_length) {
    // Check for reserved keywords
    const char *keywords[] = {"if", "while", "for", "return", "int", "double", "char", NULL};
    for (int i = 0; keywords[i]; i++) {
        if (strcmp(name, keywords[i]) == 0) {
            fprintf(stderr, "Error at line %d: '%s' is a reserved keyword\n", line_no, name);
            return NULL;
        }
    }

    // Hash the name
    unsigned long index = hash(name, table->table_size);

    // Check for redeclaration in the same scope
    SymbolTableEntry *current = table->buckets[index];
    while (current) {
        if (strcmp(current->name, name) == 0 && current->scope_no == scope_no) {
            fprintf(stderr, "Error at line %d: Identifier '%s' redeclared in scope %d (previously declared at line %d)\n",
                    line_no, name, scope_no, current->line_no);
            return NULL;
        }
        current = current->next_entry;
    }

    // Allocate new entry
    SymbolTableEntry *entry = (SymbolTableEntry*)malloc(sizeof(SymbolTableEntry));
    if (!entry) {
        fprintf(stderr, "Memory allocation of symbol table entry failed at line %d\n", line_no);
        return NULL;
    }

    // Initialize fields
    strncpy(entry->name, name, MAX_IDENTIFIER_NAME_LENGTH);
    entry->name[MAX_IDENTIFIER_NAME_LENGTH] = '\0';
    strncpy(entry->type, type, MAX_TYPE_NAME_LENGTH);
    entry->type[MAX_TYPE_NAME_LENGTH] = '\0';
    entry->scope_no = scope_no;
    entry->line_no = line_no;
    entry->value_type = value_type;
    entry->is_function = is_function;
    entry->parameters = parameters;
    entry->next_entry = NULL;

    // Handle value based on value_type
    switch (value_type) {
        case INT_VALUE:
            entry->value.int_value = value.int_value;
            break;
        case FLOAT_VALUE:
            entry->value.float_value = value.float_value;
            break;
        case CHAR_VALUE:
            entry->value.char_value = value.char_value;
            break;
        case STRING_VALUE:
            if (value.char_array) {
                size_t string_length = strlen(value.char_array);
                entry->value.char_array = (char*)malloc(string_length + 1);
                if (!entry->value.char_array) {
                    free(entry);
                    fprintf(stderr, "Memory allocation for string failed at line %d\n", line_no);
                    return NULL;
                }
                strncpy(entry->value.char_array, value.char_array, string_length + 1);
            } else {
                entry->value.char_array = NULL;
            }
            break;
        case CHAR_ARRAY_VALUE:
            if (array_length > 0 && value.char_array) {
                entry->value.char_array = (char*)malloc(array_length);
                if (!entry->value.char_array) {
                    free(entry);
                    fprintf(stderr, "Memory allocation for char array failed at line %d\n", line_no);
                    return NULL;
                }
                memcpy(entry->value.char_array, value.char_array, array_length);
            } else {
                entry->value.char_array = NULL;
            }
            break;
        case INT_ARRAY_VALUE:
            if (array_length > 0 && value.int_array) {
                entry->value.int_array = (int*)malloc(array_length * sizeof(int));
                if (!entry->value.int_array) {
                    free(entry);
                    fprintf(stderr, "Memory allocation for int array failed at line %d\n", line_no);
                    return NULL;
                }
                memcpy(entry->value.int_array, value.int_array, array_length * sizeof(int));
            } else {
                entry->value.int_array = NULL;
            }
            break;
        case FLOAT_ARRAY_VALUE:
            if (array_length > 0 && value.float_array) {
                entry->value.float_array = (double*)malloc(array_length * sizeof(double));
                if (!entry->value.float_array) {
                    free(entry);
                    fprintf(stderr, "Memory allocation for float array failed at line %d\n", line_no);
                    return NULL;
                }
                memcpy(entry->value.float_array, value.float_array, array_length * sizeof(double));
            } else {
                entry->value.float_array = NULL;
            }
            break;
        case FUNCTION:
            entry->value.function = value.function;
            break;
        default:
            fprintf(stderr, "Error at line %d: Invalid value type for '%s'\n", line_no, name);
            free(entry);
            exit(1);
            return NULL;
    }

    // Insert into hash table and maintain scope descending order among linked list elements
    if (!table->buckets[index]) {
        table->buckets[index] = entry;
    } else if (table->buckets[index]->scope_no <= entry->scope_no) { // in order to maintain the order of insertion in case 
        entry->next_entry = table->buckets[index];
        table->buckets[index] = entry;
    } else {
        SymbolTableEntry *prev = table->buckets[index];
        SymbolTableEntry *curr = prev->next_entry;
        while (curr && curr->scope_no > entry->scope_no) {
            prev = curr;
            curr = curr->next_entry;
        }
        prev->next_entry = entry;
        entry->next_entry = curr;
    }
    table->entry_count++;
    return entry;
}

void free_symbol_table(SymbolTable* table) {
    for (int i = 0; i < table->table_size; i++) {
        SymbolTableEntry *current = table->buckets[i];
        while (current) {
            SymbolTableEntry *temp = current;
            current = current->next_entry;
            // Free dynamically allocated values
            switch (temp->value_type) {
                case STRING_VALUE:
                case CHAR_ARRAY_VALUE:
                    if (temp->value.char_array) {
                        free(temp->value.char_array);
                    }
                    break;
                case INT_ARRAY_VALUE:
                    if (temp->value.int_array) {
                        free(temp->value.int_array);
                    }
                    break;
                case FLOAT_ARRAY_VALUE:
                    if (temp->value.float_array) {
                        free(temp->value.float_array);
                    }
                    break;
                default:
                    break;
            }
            // Free parameters
            Parameter *param = temp->parameters;
            while (param) {
                Parameter *temp_param = param;
                param = param->next;
                free(temp_param);
            }
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

void delete_scope(SymbolTable* table, int scope_no) {
    for (int i = 0; table && i < table->table_size; i++) {
        SymbolTableEntry *current = table->buckets[i];
        SymbolTableEntry *prev = NULL;
        SymbolTableEntry *temp = NULL;
        while (current && current->scope_no >= scope_no) {
            // Free dynamically allocated values
            if(current->scope_no == scope_no){
                switch (current->value_type) {
                    case STRING_VALUE:
                    case CHAR_ARRAY_VALUE:
                        if (current->value.char_array) {
                            free(current->value.char_array);
                        }
                        break;
                    case INT_ARRAY_VALUE:
                        if (current->value.int_array) {
                            free(current->value.int_array);
                        }
                        break;
                    case FLOAT_ARRAY_VALUE:
                        if (current->value.float_array) {
                            free(current->value.float_array);
                        }
                        break;
                    default:
                        break;
                }
                // Free parameters
                Parameter *param = current->parameters;
                while (param) {
                    Parameter *current_param = param;
                    param = param->next;
                    free(current_param);
                }

                temp = current;
                if(!prev){ // current is the first element
                    prev = NULL;
                    table->buckets[i] = current->next_entry;
                }else{
                    prev->next_entry = current->next_entry;
                }
                current = current->next_entry;
                free(temp);
                temp = NULL;

                if(!(table->buckets[i])){
                    table->entry_count = table->entry_count - 1;
                }
            }else{
                prev = current;
                current = current->next_entry;
            }
        }
    }
}


SymbolTableEntry* search_symbol_table(SymbolTable* table, const char* name, int curr_scope) { // returns the first encountred entry, starting from the current scope
    if(!table){
        return NULL;
    }
    int i = hash(name, table->table_size);
    SymbolTableEntry* current = table->buckets[i];
    while (current){
        if(strcmp(current->name, name) == 0 && current->scope_no <= curr_scope){
            return current;
        }
    }
    current = current->next_entry;
    return NULL;
}

