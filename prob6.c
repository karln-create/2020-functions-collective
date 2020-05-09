/*
	contains solution to problem 6, in which we find the character with the highest frequency of occurences.
*/
#include "root.h"

void maximum_occurences(char *string_ptr, struct occurences *arr, int *num, char *character);

/* local main function */
void problem6(void)
{
	char str[] = "test string";
	struct occurences arr[((int)sizeof(str) / sizeof(*str)) - 1] = {0};
	int num = 0;
	char symbol = {'\0'};
	maximum_occurences(str, arr, &num, &symbol);
}

void maximum_occurences(char *string_ptr, struct occurences *arr, int *num, char *character)
{
	int uniq_chars = 0, /* number of unique characters in the string */
		i, j,			/* sentinels */
		k = 0,			/* location marker */
		dup = 0, temp_max = 0, max_dup = 0;

	/* get the size of string */
	int arrsize = strlen(string_ptr);

	/* local data structure (DS) to determine the maximum occurence of each character */
	char *tempchars = (char *)malloc(arrsize * sizeof(char));

	/* copy the first character of the string into the first location of the local char array */
	tempchars[0] = string_ptr[0];
	arr[0].num_occurences = 1;

	/* check the entire string starting with location [i = 1] */
	for (i = 1; string_ptr[i] != '\0'; ++i)
	{
		/* for each new comparison, reset the dup counter */
		dup = 0;
		/* compare each string's character with the characters saved in the local DS */
		for (j = uniq_chars; j >= 0; --j)
		{
			if (string_ptr[i] == tempchars[j])
			{
				++dup;
				break;
			}
		}

		/* at the end of the iteration, if no duplicate is found then it's a unique character.
			Then, put that character in the next empty location in the local char-type DS. */
		if (dup == 0)
		{
			++uniq_chars;
			tempchars[uniq_chars] = string_ptr[i];
			arr[uniq_chars].num_occurences = 1;
		}

		/* otherwise, add 1 to the location of the found duplicate */
		else
		{
			++(arr[j].num_occurences);
			temp_max = arr[j].num_occurences;
			/* check for new max, if True retains the value and its location */
			if (temp_max > max_dup)
			{
				max_dup = temp_max;
				k = j;
			}
		}
	}

	*num = max_dup;
	*character = tempchars[k];

	free(tempchars);
}

/*
	SOME THOUGHTS: There is probably a better way to write this function.
	
	I didn't fully utilize all the parameters inside the struct Occurences. I couldn't find a use for the frequency parameter.

	But for now this is the best I can do.
*/