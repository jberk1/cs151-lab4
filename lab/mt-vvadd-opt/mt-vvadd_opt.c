#include "mt-vvadd.h"

// z = x + y, element-wise:
//   z[i] = x[i] + y[i]  for 0 <= i < n
// Every core calls this function; together they must compute all of z.
void vvadd_opt(int coreid, int ncores, size_t n, const data_t* x, const data_t* y, data_t* z)
{
    /* TODO */
	//strat: what if instead we split the array into chunks and each core will manage the chunk
	size_t chunk = n / ncores;
	size_t start = coreid * chunk; //which chunk are we starting on ?
	size_t end = (coreid == ncores - 1) ? n: start + chunk; //only for the case where it's the last core do we iterate until the end

	for (size_t i = start; i < end; i++) {
		z[i] = x[i] + y[i];
	}
}
