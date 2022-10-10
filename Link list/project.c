#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *fptr;

	fptr = fopen(argv[2], "r");
	if (fptr == NULL)
		printf("file not opened");

	double line_count = 0;
	int i;
	int final;
	char *contents = NULL;
	float min_mut;
	float max_mut;
	int total_mut_count;
	int mut_count;
	float percent;
	int ref_flag = 0;
	int alt_flag = 0;
	size_t len = 0;

	min_mut = atoi(argv[3]);
	max_mut = atoi(argv[4]);

	while (getline(&contents, &len, fptr) != -1)
	{
		char pos_0, pos_1;
		pos_0 = contents[0];
		pos_1 = contents[1];

		if (pos_0 == '#' && pos_1 == '#')
		{
			continue;
		}
		else if (pos_0 == '#' && pos_1 != '#')
		{
		}
		else
		{
			//  printf("len is %ld\n", len);
			//  printf(" %c\n", contents[5260]);
			//  printf(" %c\n", contents[37264]);
			//  printf(" %c\n", contents[37265]);

			int columns_index[len];
			i = 0;
			final = 0;

			while (contents[i] != '\n')
			{
				if (contents[i] == '	')
				{
					columns_index[final] = i;
					final++;
				}
				// printf("%c", contents[i]);
				i++;
			}
			// printf("\n\n");
			//   printf(" is %d \n", );

			int ref = columns_index[2] + 1;
			int alt = columns_index[3] + 1;
			int qual = columns_index[4] + 1;
			int filter = columns_index[5] + 1;
			int info = columns_index[6] + 1;
			int format = columns_index[8] + 1;

			if (contents[0] == argv[1][0] && contents[1] == argv[1][1])
			{
				char fil_arr[info - filter + 2];
				int j1 = 0;

				for (int i = filter; i < info; i++)
				{
					fil_arr[j1] = (char)contents[i];
					j1++;
				}
				if (fil_arr[0] == 'P' && fil_arr[1] == 'A' && fil_arr[2] == 'S' && fil_arr[3] == 'S')
				{
					// printf("inside pass\n");
					char ref_and_alt[qual - ref + 2];
					ref_flag = 0;
					for (int i = ref; i < alt; i++)
					{
						if ((char)contents[i + 1] == '\t' && (char)contents[i - 1] == '\t')
						{
							// printf("inside ref1\n");

							if ((char)contents[i] == 'A' || (char)contents[i] == 'T' || (char)contents[i] == 'G' || (char)contents[i] == 'C')
							{
								//printf("inside ref === %c %c %c\n", contents[i - 1], contents[i], contents[i + 1]);
								ref_and_alt[0] = (char)contents[i];
								ref_flag = 1;
								// printf("inside ref filter\n");
							}
							else
							{
								//printf("filter = %c\n", ref_and_alt[0]);
								ref_flag = 0;
								break;
							}
						}
					}
					int k = 1, a = 0, t = 0, g = 0, c = 0;
					char arr[qual - alt + 1];
					int i, j;
					alt_flag = 0;
					for (i = alt, j = 0; i < qual; i++, j++)
					{
						// printf("%c", contents[i]);
						arr[j] = contents[i];
					}
					// printf("\n");
					arr[j - 1] = '\0';
					char *token = strtok(arr, ",");
					while ((token != NULL))
					{
						// printf("token %s\n", token);
						if (strlen(token) != 1)
						{
							alt_flag = 0;
							break;
						}
						if (token[0] != 'A' && token[0] != 'T' && token[0] != 'G' && token[0] != 'C')
						{
							alt_flag = 0;
						}
						if (token[0] == 'A')
						{
							a++;
						}
						if (token[0] == 'T')
						{
							t++;
						}
						if (token[0] == 'G')
						{
							g++;
						}
						if (token[0] == 'C')
						{
							c++;
						}
						if (a > 1 || t > 1 || g > 1 || c > 1)
						{
							alt_flag = 0;
							break;
						}
						alt_flag = 1;
						token = strtok(NULL, ",");
						// printf("token %s\n", token);
					}

					// for (int i = alt; i < qual; i++)
					// {
					// 	if (((char)contents[i - 1] == ',' || (char)contents[i - 1] == '\t') && ((char)contents[i + 1] == ',' || (char)contents[i + 1] == '\t'))
					// 	{

					// 		//  if((contents[i-1] == '\t' && contents[i+1] == ',') || (contents[i-1] == ',' && contents[i+1] == ',') || (contents[i-1] == ',' && contents[i+1] == '\t') || (contents[i-1] == '\t' && contents[i+1] == '\t')) {
					// 		if (contents[i] == 'A' || contents[i] == 'T' || contents[i] == 'G' || contents[i] == 'C')
					// 		{
					// 			if (contents[i] == 'A')
					// 			{
					// 				a++;
					// 			}
					// 			if (contents[i] == 'T')
					// 			{
					// 				t++;
					// 			}
					// 			if (contents[i] == 'G')
					// 			{
					// 				g++;
					// 			}
					// 			if (contents[i] == 'C')
					// 			{
					// 				c++;
					// 			}

					// 			ref_and_alt[k] = (char)contents[i];

					// 			// printf("ref_and_alt[k] %c\n", ref_and_alt[k]);
					// 			k++;
					// 			i++;
					// 			if (a > 1 || t > 1 || g > 1 || c > 1)
					// 			{
					// 				break;
					// 			}

					// 			alt_flag = 1;
					// 		}
					// 		// printf("inside alt filter\n");
					// 	}
					// 	else
					// 	{
					// 		alt_flag = 0;
					// 		break;
					// 	}
					// }
					// printf("ref and alt flag %d %d \n", ref_flag, alt_flag);
					//printf("ref_flag = %d  && alt_flag = %d\n", ref_flag, alt_flag);

					if (ref_flag == 1 && alt_flag == 1)
					{

						/////////////////////////////////////
mut_count = 0;
						char *mut_token = strtok(contents, "\t");
						while ((mut_token != NULL))
						{
							//printf("token %s\n", mut_token);
							if (mut_token[0] != '0' || mut_token[2] != '0')
							{
								//printf("token %s\n", mut_token);
								mut_count++;
							}
							mut_token = strtok(NULL, "\t");
						}

						percent = ((float)(mut_count)-9) / (final - 8);
						percent = percent * 100;

						printf("all val %lf %d %d\n", percent, mut_count, final);
						if ((min_mut <= percent) && (max_mut >= percent))
						{
							line_count++;
						}

						////////////////////////////////////

						//line_count++;
						/*
							//printf("inside mutation %c %c %c\n",contents[columns_index[format] + 1], contents[columns_index[format] + 2], contents[columns_index[format] + 3]);
							total_mut_count = 0;
							mut_count = 0;
							// printf(" final and format is %d %d\n",final , format);
							// printf("inside condition\n");
							int loop_count = 0;
							for (int i = format; i <final ; i++)
							{
								char gtype_1 = (char)contents[columns_index[i] + 1];
								// printf("%c",contents[columns_index[i]+1]);
								loop_count++;
								char gtype_2 = (char)contents[columns_index[i] + 3];
								// printf( "gtypes are %c %c %c\n", gtype_1,contents[columns_index[i]+2],gtype_2);

								if ((gtype_1 != '0') || (gtype_2 != '0'))
								{
									// printf("inside non mut\n");
									mut_count++;
									total_mut_count++;
								}else
								{
									//  printf("inside mut\n");

									total_mut_count++;
								}
							}
							// printf("asdasd\n");
							percent = ((float)(mut_count)) / (final - 8);
							percent = percent * 100;

							// printf("all val %lf %d %d\n",percent, mut_count, final);
							if ((min_mut <= percent) && (max_mut >= percent))
							{
								line_count++;
							}*/
					}
				}
				else
				{
					printf("filter = %c%c\n", fil_arr[0], fil_arr[1]);
				}
			}
			else
			{
				printf("chromo = %c%c\n", contents[0], contents[1]);
			}
		}
	}
	printf("%.0lf\n", line_count);
	free(contents);
	fclose(fptr);

	return 0;
}
