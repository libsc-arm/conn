#include <stdio.h>

#include "cpuleaf.h"
#include "vendor.h"
#include "cpuinfo.h"


int main() {
    printf("%d %d\n", cpuid_basic_support(), cpuid_extended_support());
    printf("%s\n", get_manufacturer_id());
    struct cpu_signature_t cs;
    fetch_cpu_info(&cs);
    printf("%u\n", cs.stepping);
    printf("%u\n", cs.model);
    printf("%u\n", cs.family);
    printf("%u\n", cs.type);
    printf("%u\n", cs.ext_model);
    printf("%u\n", cs.ext_family);
    return 0;
}
