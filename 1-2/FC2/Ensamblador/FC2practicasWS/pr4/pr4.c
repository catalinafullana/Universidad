/**
 * @file
 * @brief Implementation of [merge
 * sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm
 */

/**
 * @addtogroup sorting Sorting algorithms
 * @{
 */
/** Swap two integer variables
 * @param [in,out] a pointer to first variable
 * @param [in,out] b pointer to second variable
 */
extern void swap(int *a, int *b);
extern int main(void);
//extern int *a[];
//extern int n;
/**
 * @brief Perform merge of segments.
 *
 * @param a array to sort
 * @param l left index for merge
 * @param r right index for merge
 * @param n total number of elements in the array
 */

extern void merge_sort ( int *a, int n, int l, int r ) ;
void merge(int *a, int l, int r, int n)
{
    int *b = (int *)malloc(n * sizeof(int)); /* dynamic memory must be freed */

		int c = l;
		int p1, p2;
		p1 = l;
		p2 = ((l + r) / 2) + 1;
		while ((p1 < ((l + r) / 2) + 1) && (p2 < r + 1))
		{
			if (a[p1] <= a[p2])
			{
				b[c++] = a[p1];
				p1++;
			}
			else
			{
				b[c++] = a[p2];
				p2++;
			}
		}

		if (p2 == r + 1)
		{
			while ((p1 < ((l + r) / 2) + 1))
			{
				b[c++] = a[p1];
				p1++;
			}
		}
		else
		{
			while ((p2 < r + 1))
			{
				b[c++] = a[p2];
				p2++;
			}
		}

		for (c = l; c < r + 1; c++) a[c] = b[c];

}

/** Merge sort algorithm implementation
 * @param a array to sort
 * @param n number of elements in the array
 * @param l index to sort from
 * @param r index to sort till
 */

/** @} */

/** Main function */
/*
int main(void)
{

    //int n=7;
    //int a[]={4,2,3,6,8, 5,9};


    merge_sort(a, n, 0, n - 1);
    //printf("Sorted Array: ");

    return 0;
}
*/
