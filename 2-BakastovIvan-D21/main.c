#include <stdio.h>
#include <stdlib.h>
 #include <windows.h> 
 #include <psapi.h> 

#include "solve.h"


#define DIV 1048576






/**
*
* CPU: Intel(R) Core(TM) i7-9750H CPU @ 2.60GHz   2.59 GHz
* RAM: 16 GB
* SSD: 475 GB
*
* Vertex number 3000
* Memory usage : 3276 MB
* 
*
*/


int main() {
	int ve = 0, v = 0, u = 0, **g = NULL, j = 0, * solvepath = NULL, v_num = 0;;
	char fajok = FALSE, checkbox_f = '2';
	LARGE_INTEGER tstart, tend, counter;
	double time_counter;
	QueryPerformanceFrequency(&counter);
	stress_test(&v_num, &g);
	QueryPerformanceCounter(&tstart);

	solve(v_num, g, &solvepath);
	QueryPerformanceCounter(&tend);
	time_counter = (double)((double)(tend.QuadPart - tstart.QuadPart) / (double)counter.QuadPart);
	printf("%lf", time_counter);
	print_ans(stdout, v_num, solvepath);

	HINSTANCE hProcHandle = GetModuleHandle(NULL);  // get the current process handle
	PROCESS_MEMORY_COUNTERS_EX memory; // output will go here.
	 
	GetProcessMemoryInfo(hProcHandle, &memory, sizeof(memory));
	 	
	printf("\nMemory usage: %u MB", memory.PrivateUsage/DIV);
	return 0;
}

