#include "cpuinfo.h"
#include "cpuleaf.h"

#include <string.h>


void fetch_cpu_info(struct cpu_signature_t *cs) {
    // TODO: Handle erroneous values

    struct cpu_regs_t cr;
    clear_regs(&cr);
    cr.eax = 1;
    cpuid(1, &cr);

    memcpy(cs, &(cr.eax), sizeof(cr.eax));
}

