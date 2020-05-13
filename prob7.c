/*
	contains solution to problem 7: finding the longest sequence of consecutive integers.
*/
#include "root.h"

#define MAX_COL 5;

int *max_consecutive_integers(signed int arr[][5], int row, int col, int *num_consecutive);

void problem7(void)
{
	signed int arr[4][5] = {{-5, 6, 0, 2, 2},
							{2, 2, 2, 9, 3},
							{3, 3, 2, 1, -8},
							{7, -2, 6, 0, 4}};

	signed int *address_sequence = NULL;
	int num_consec = 0;
	address_sequence = max_consecutive_integers(arr, 4, 5, &num_consec);
	printf("*(%p) : %d\n", &arr[0][3], arr[0][3]);
	printf("*(%p) : %d\n", address_sequence, *address_sequence);
}

signed int *max_consecutive_integers(signed int arr[][5], int row, int col, int *num_consecutive)
{
	int i = 0, j = 0, /* sentinels for row and col */
		temp_r = 0, temp_c = 0,
		seq = 0, new_seq = 0;
	signed int *ptr = NULL;

	for (i = 0; i < row; ++i) // row
	{
		for (j = 0; j < col; ++j) // col
		{
			/* if the new_seq counter exceeds the (old)seq counter, retain the new counter value as well as the row and col where it points to */
			if (new_seq > seq)
			{
				seq = new_seq;
				int temp_seq = seq - 1;
				temp_r = i;
				temp_c = j;
				/* locate the address of the block at the beginning of the sequence (can probably be encapsulated in a different function, to-do: when I have time) */
				while (temp_seq > 0)
				{
					--temp_c;
					--temp_seq;
					/* if the algorithm has reached the beginning of a row and the seq counter has not reach 0, move back one line and start at the end of that line */
					if (temp_c == 0 && temp_seq > 0)
					{
						--temp_r;
						temp_c = MAX_COL;
						--temp_c;
						--temp_seq;
					}
				}
			}

			/* check for the presence of a sequence */
			if (*(*(arr + i) + j) == *(*(arr + i) + j + 1))
				++new_seq;

			/* otherwise, reset the sequence counter */
			else if (*(*(arr + i) + j) != *(*(arr + i) + j + 1))
				new_seq = 1;
		}
	}

	*num_consecutive = seq;
	ptr = &(*(*(arr + temp_r) + temp_c));
	return ptr;
}