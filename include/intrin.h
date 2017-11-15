#pragma once

#include <cpuid.h>
#ifdef __cpuid
#undef __cpuid
#endif

static inline void __cpuid(int cpuInfo[4], int function_id) {
	__get_cpuid(function_id,
	            (unsigned int *)&cpuInfo[0],
	            (unsigned int *)&cpuInfo[1],
	            (unsigned int *)&cpuInfo[2],
	            (unsigned int *)&cpuInfo[3]);
}

static inline void __cpuidex(int cpuInfo[4], int function_id,
                             int subfunction_id) {
	cpuInfo[2] = subfunction_id;
	__get_cpuid(function_id,
	            (unsigned int *)&cpuInfo[0],
	            (unsigned int *)&cpuInfo[1],
	            (unsigned int *)&cpuInfo[2],
	            (unsigned int *)&cpuInfo[3]);
}

