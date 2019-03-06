#include <cpuid.h>
#include <stddef.h>
#include <string.h>

#include "cpuleaf.h"

#define EXT_MAX 0x80000000
#define EXT_MIN 0x0


bool cpuid_max(unsigned int __ext, unsigned int *__sig) {
 if (!(__get_cpuid_max(__ext, __sig))) {
     return false;
 } else {
     return true;
 }
}

void cpuid(unsigned int leaf, struct cpu_regs_t *cr) {
    __get_cpuid(leaf, &(cr->eax), &(cr->ebx), &(cr->ecx), &(cr->edx));
}

bool cpuid_basic_support() {
    return cpuid_max(EXT_MIN, NULL);
}

bool cpuid_extended_support() {
    return cpuid_max(EXT_MAX, NULL);
}

void clear_regs(struct cpu_regs_t *cr) {
    memset(cr, 0, sizeof(cr));
}

