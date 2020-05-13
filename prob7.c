/*
	contains solution to problem 7.
*/
#include "root.h"

#define MAX_COL 5;

int *max_consecutive_integers(signed int arr[][5], int row, int col, signed int *ptr, int *num_consecutive);

void problem7(void)
{
	//const unsigned int MAX_COL = 5;

	signed int arr[4][5] = {{-5, 6, 0, 2, 2},
							{2, 2, 2, 9, 3},
							{3, 3, 2, 1, -8},
							{7, -2, 6, 0, 4}};

	signed int *address_sequence = &(**arr);
	int num_consec = 0;
	address_sequence = max_consecutive_integers(arr, 4, 5, address_sequence, &num_consec);
}

signed int *max_consecutive_integers(signed int arr[][5], int row, int col, signed int *ptr, int *num_consecutive)
{
	int i = 0, j = 0, /* sentinels */
		temp_r = 0, temp_c = 0,
		seq = 0, new_seq = 0;

	//int temp_val = (**arr);

	/* assign the addres of the 2dim array to the pointer ptr */
	ptr = &(**arr);

	/* within the ith row */
	for (i = 0; i < row; ++i)
	{
		/* within the jth col */
		for (j = 0; j < col; ++j)
		{
			/* if the new_consec counter exceeds the old consec counter, retains the new consec counter and the row and col of that  */
			if (new_seq > seq)
			{
				seq = new_seq;
				int temp_seq = seq - 1;
				temp_r = i;
				temp_c = j;
				while (temp_seq > 0)
				{
					--temp_c;
					--temp_seq;
					if (temp_c == 0 && temp_seq > 0)
					{
						--temp_r;
						temp_c = MAX_COL;
						--temp_c;
						--temp_seq;
					}
				}
			}

			if (*(*(arr + i) + j) == *(*(arr + i) + j + 1))
			{
				//temp_val = *(*(arr + i) + j);
				++new_seq;
			}
			if (*(*(arr + i) + j) != *(*(arr + i) + j + 1))
			{
				//temp_val = *(*(arr + i) + j);
				new_seq = 1;
				continue;
			}
		}
	}

	*num_consecutive = seq;
	ptr = &(*(*(arr + temp_r) + temp_c));
	return ptr;
}

// int **max_consecutive_integers(signed int arr[][5], int row, int col, signed int **ptr, int *num_consecutive);
//
// void problem7(void)
// {
// 	signed int arr[4][5] = {{-5, 6, 0, 2, 2},
// 							{2, 2, 2, 9, 3},
// 							{3, 3, 2, 1, -8},
// 							{7, -2, 6, 0, 4}};
//
// 	signed int *address_sequence = &(**arr);
// 	signed int **ptr = &address_sequence;
// 	int num_consec = 0;
// 	address_sequence = max_consecutive_integers(arr, 4, 5, ptr, &num_consec);
// }
//
// signed int **max_consecutive_integers(signed int arr[][5], int row, int col, signed int **ptr, int *num_consecutive)
// {
// 	int i = 0, j = 0, /* sentinels */
// 		temp_r = 0, temp_c = 0,
// 		seq = 0, new_seq = 0;
//
// 	int temp_val = (**ptr);
//
// 	/* assign the addres of the 2dim array to the pointer ptr */
// 	ptr = &(**arr);
//
// 	/* within the ith row */
// 	for (i = 0; i < row; ++i)
// 	{
// 		/* within the jth col */
// 		for (j = 0; j < col; ++j)
// 		{
// 			/* if the new_consec counter exceeds the old consec counter, retains the new consec counter and the row and col of that  */
// 			if (new_seq > seq)
// 			{
// 				seq = new_seq;
// 				int temp_seq = seq - 1;
// 				temp_r = i;
// 				temp_c = j;
// 				while (temp_seq > 0)
// 				{
// 					--temp_c;
// 					--temp_seq;
// 					if (temp_c == 0 && temp_seq > 0)
// 					{
// 						--temp_r;
// 						temp_c = MAX_COL;
// 						--temp_c;
// 						--temp_seq;
// 					}
// 				}
// 			}
//
// 			if (*(*(arr + i) + j) == *(*(arr + i) + j + 1))
// 			{
// 				temp_val = *(*(arr + i) + j);
// 				++new_seq;
// 			}
// 			else if (*(*(arr + i) + j) != *(*(arr + i) + j + 1))
// 			{
// 				temp_val = *(*(arr + i) + j);
// 				new_seq = 1;
// 				continue;
// 			}
// 		}
// 	}
//
// 	*num_consecutive = seq;
// 	ptr = &(*(*(arr + temp_r) + temp_c));
// 	return ptr;
// }