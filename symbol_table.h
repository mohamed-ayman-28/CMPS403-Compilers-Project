#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ir.h"

FILE* symbol_table_file;
FILE* symbol_table_changes_file;

int scope_no = -1;


// Helper function to log symbol details
static void log_symbol_details(FILE *file, SymbolTableEntry *entry, const char *action) {
    if (!file || !entry) return;

    fprintf(file, "%s Symbol: name='%s', type='%s', scope=%d, line=%d, value_type=",
            action, entry->name, entry->type, entry->scope_no, entry->line_no);

    switch (entry->value_type) {
        case INT_VALUE:
            fprintf(file, "INT_VALUE (%d)", entry->value.int_value);
            break;
        case FLOAT_VALUE:
            fprintf(file, "FLOAT_VALUE (%f)", entry->value.float_value);
            break;
        case CHAR_VALUE:
            fprintf(file, "CHAR_VALUE ('%c')", entry->value.char_value);
            break;
        case BOOL_VALUE:
            fprintf(file, "BOOL_VALUE (%d)", entry->value.int_value);
            break;
        case STRING_VALUE:
            fprintf(file, "STRING_VALUE (%s)", entry->value.char_array ? entry->value.char_array : "NULL");
            break;
        case CHAR_ARRAY_VALUE:
            fprintf(file, "CHAR_ARRAY_VALUE (length=%d)", entry->array_length);
            break;
        case INT_ARRAY_VALUE:
            fprintf(file, "INT_ARRAY_VALUE (length=%d)", entry->array_length);
            break;
        case BOOL_ARRAY_VALUE:
            fprintf(file, "BOOL_ARRAY_VALUE (length=%d)", entry->array_length);
            break;
        case FLOAT_ARRAY_VALUE:
            fprintf(file, "FLOAT_ARRAY_VALUE (length=%d)", entry->array_length);
            break;
        case STRING_ARRAY_VALUE:
            fprintf(file, "STRING_ARRAY_VALUE (length=%d)", entry->array_length);
            break;
        case FUNCTION:
            fprintf(file, "FUNCTION");
            break;
        default:
            fprintf(file, "UNKNOWN");
    }

    fprintf(file, ", is_function=%d, is_constant=%d, array_length=%d, enclosing_function=%s\n",
            entry->is_function, entry->is_constant, entry->array_length,
            entry->enclosing_function_name ? entry->enclosing_function_name : "NONE");

    // Log parameters if any
    Parameter *param = entry->parameters;
    if (param) {
        fprintf(file, "  Parameters: ");
        while (param) {
            fprintf(file, "{name='%s', type='%s', array_length=%zu}%s",
                    param->name, param->type, param->array_length,
                    param->next ? ", " : "");
            param = param->next;
        }
        fprintf(file, "\n");
    }
}

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
    param->array_length = 0; 
    param->next = NULL;
    return param;
}

SymbolTableEntry* insert_symbol(SymbolTable* table, const char* name, const char* type, Value value, ValueType value_type, int scope_no, int is_function, int is_constant, int no_explicit_array, Parameter* parameters, int line_no, size_t array_length, const char* enclosing_function_name) {
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

    // Check for redeclaration in the same scope and enclosing_function_name
    SymbolTableEntry *current = table->buckets[index];
    while (current) {
        int same_scope = current->scope_no == scope_no;
        int same_enclosing = (current->enclosing_function_name == NULL && enclosing_function_name == NULL) ||
                             (current->enclosing_function_name && enclosing_function_name &&
                              strcmp(current->enclosing_function_name, enclosing_function_name) == 0);
        if (strcmp(current->name, name) == 0 && same_scope && same_enclosing) {
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
    entry->is_constant = is_constant;
    entry->parameters = parameters;
    entry->next_entry = NULL;
    entry->array_length = array_length;
    // Set enclosing_function_name
    if (enclosing_function_name) {
        entry->enclosing_function_name = strdup(enclosing_function_name);
        if (!entry->enclosing_function_name) {
            free(entry);
            fprintf(stderr, "Memory allocation for enclosing_function_name failed at line %d\n", line_no);
            return NULL;
        }
    } else {
        entry->enclosing_function_name = NULL;
    }

    // Handle value based on value_type
    switch (value_type) {
        case BOOL_VALUE:
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
                    free(entry->enclosing_function_name);
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
            if (array_length > 0) {
                entry->value.char_array = (char*)malloc(array_length);
                if (!entry->value.char_array) {
                    free(entry->enclosing_function_name);
                    free(entry);
                    fprintf(stderr, "Memory allocation for char array failed at line %d\n", line_no);
                    return NULL;
                }
                if(!no_explicit_array && value.char_array){
                    memcpy(entry->value.char_array, value.char_array, array_length);
                }
            } else {
                entry->value.char_array = NULL;
            }
            break;
        case BOOL_ARRAY_VALUE:
            if (array_length > 0) {
                entry->value.int_array = (int*)malloc(array_length * sizeof(int));
                if (!entry->value.int_array) {
                    free(entry->enclosing_function_name);
                    free(entry);
                    fprintf(stderr, "Memory allocation for bool array failed at line %d\n", line_no);
                    return NULL;
                }
                if (!no_explicit_array && value.int_array) {
                    memcpy(entry->value.int_array, value.int_array, array_length * sizeof(int));
                }
            } else {
                entry->value.int_array = NULL;
            }
            break;
        case INT_ARRAY_VALUE:
            if (array_length > 0) {
                entry->value.int_array = (int*)malloc(array_length * sizeof(int));
                if (!entry->value.int_array) {
                    free(entry->enclosing_function_name);
                    free(entry);
                    fprintf(stderr, "Memory allocation for int array failed at line %d\n", line_no);
                    return NULL;
                }
                if(!no_explicit_array && value.int_array){
                    memcpy(entry->value.int_array, value.int_array, array_length * sizeof(int));
                }
            } else {
                entry->value.int_array = NULL;
            }
            break;
        case FLOAT_ARRAY_VALUE:
            if (array_length > 0) {
                entry->value.float_array = (double*)malloc(array_length * sizeof(double));
                if (!entry->value.float_array) {
                    free(entry->enclosing_function_name);
                    free(entry);
                    fprintf(stderr, "Memory allocation for float array failed at line %d\n", line_no);
                    return NULL;
                }
                if(!no_explicit_array && value.float_array){
                    memcpy(entry->value.float_array, value.float_array, array_length * sizeof(double));
                }
            } else {
                entry->value.float_array = NULL;
            }
            break;
        case STRING_ARRAY_VALUE:
            if (array_length > 0) {
                entry->value.string_array = (char**)malloc(array_length * sizeof(char*));
                if (!entry->value.string_array) {
                    free(entry->enclosing_function_name);
                    free(entry);
                    fprintf(stderr, "Memory allocation for string array failed at line %d\n", line_no);
                    return NULL;
                }
                for (size_t i = 0; i < array_length; i++) {
                    entry->value.string_array[i] = strdup("");
                }
                if (!no_explicit_array && value.string_array) {
                    for (size_t i = 0; i < array_length; i++) {
                        free(entry->value.string_array[i]);
                        entry->value.string_array[i] = strdup(value.string_array[i] ? value.string_array[i] : "");
                    }
                }
            } else {
                entry->value.string_array = NULL;
            }
            break;
        case FUNCTION:
            entry->value.function = value.function;
            break;
        default:
            fprintf(stderr, "Error at line %d: Invalid value type for '%s'\n", line_no, name);
            free(entry->enclosing_function_name);
            free(entry);
            return NULL;
    }

    // Insert into hash table and maintain scope descending order among linked list elements
    if (!table->buckets[index]) {
        table->buckets[index] = entry;
    } else if (table->buckets[index]->scope_no <= entry->scope_no) {
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

    
    log_symbol_details(symbol_table_changes_file, entry, "Inserted");
    return entry;
}

void free_symbol_table(SymbolTable* table) {
    for (int i = 0; i < table->table_size; i++) {
        SymbolTableEntry *current = table->buckets[i];
        while (current) {
            SymbolTableEntry *temp = current;
            current = current->next_entry;
            if (temp->enclosing_function_name) { 
                free(temp->enclosing_function_name);
            }
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
                case STRING_ARRAY_VALUE:
                    if (temp->value.string_array) {
                        for (size_t j = 0; j < temp->array_length; j++) {
                            if (temp->value.string_array[j]) {
                                free(temp->value.string_array[j]);
                            }
                        }
                        free(temp->value.string_array);
                    }
                    break;
                default:
                    break;
            }
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
            if (current->scope_no == scope_no) {
                log_symbol_details(symbol_table_changes_file, current, "Deleted");

                // Free dynamically allocated values
                if (current->enclosing_function_name) {
                    free(current->enclosing_function_name);
                }
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
                    case STRING_ARRAY_VALUE:
                        if (current->value.string_array) {
                            for (size_t j = 0; j < current->array_length; j++) {
                                if (current->value.string_array[j]) {
                                    free(current->value.string_array[j]);
                                }
                            }
                            free(current->value.string_array);
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
                if (!prev) { // current is the first element
                    table->buckets[i] = current->next_entry;
                } else {
                    prev->next_entry = current->next_entry;
                }
                current = current->next_entry;
                free(temp);
                table->entry_count--;
            } else {
                prev = current;
                current = current->next_entry;
            }
        }
    }
}

void print_symbol_table(SymbolTable* table) {
    if (!table) {
        fprintf(stderr, "Symbol table is NULL\n");
        return;
    }

    FILE *log_file = fopen("symbol_table.log", "a");
    if (!log_file) {
        fprintf(stderr, "Failed to open symbol_table.log for writing\n");
        return;
    }

    fprintf(log_file, "\n=== Symbol Table State (Entry Count: %d) ===\n", table->entry_count);
    for (int i = 0; i < table->table_size; i++) {
        SymbolTableEntry *current = table->buckets[i];
        while (current) {
            log_symbol_details(log_file, current, "Present");
            current = current->next_entry;
        }
    }
    fprintf(symbol_table_file, "====================================\n\n");

    fclose(log_file);
}

SymbolTableEntry* search_symbol_table(SymbolTable* table, const char* name, int curr_scope, const char* enclosing_function_name) {
    if (!table) {
        return NULL;
    }
    int i = hash(name, table->table_size);
    SymbolTableEntry* current = table->buckets[i];
    SymbolTableEntry* fallback = NULL;
    while (current) {
        if (strcmp(current->name, name) == 0 && current->scope_no <= curr_scope) {
            // Exact match for scope and enclosing_function_name
            if (enclosing_function_name && current->enclosing_function_name &&
                strcmp(current->enclosing_function_name, enclosing_function_name) == 0) {
                return current;
            }
            // If enclosing_function_name is NULL or no exact match, store as fallback
            if (!enclosing_function_name || !current->enclosing_function_name) {
                if (!fallback || current->scope_no > fallback->scope_no) {
                    fallback = current;
                }
            }
        }
        current = current->next_entry;
    }
    return fallback;
}

#endif