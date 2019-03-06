#ifndef CPULEAF_H
#define CPULEAF_H

#include <stdint.h>
#include <stdbool.h>


struct cpu_regs_t {
    // Anonymous union
    union {
        struct {
            uint32_t eax;
            uint32_t ebx;
            uint32_t ecx;
            uint32_t edx;
        };
        uint32_t regs[4];
    };
};


/*
 * Wrapper over __get_cpuid_max function implemented in gcc.
 * This functions checks for the highest cpuid value for basic or
 * extended cpuid information and returns false if not supported.
 *
 * TODO: Handle additional info, returned.
 */

bool cpuid_max(unsigned int, unsigned int *);

/*
 * Wrapper over __get_cpuid instruction from gcc.
 * Sets the returned data for requested cpuid level
 * in the supplied registers.
 */

void cpuid(unsigned int, struct cpu_regs_t *);
void clear_regs(struct cpu_regs_t *);


bool cpuid_basic_support();
bool cpuid_extended_support();


#endif
