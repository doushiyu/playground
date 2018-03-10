// stringmatching_final_mpi_2.cpp : Defines the entry point for the console application.
//

// stringmatching_parallel_final_project_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <time.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TXT_SIZE 14500
#define MAX_PATTERN_SIZE 10
#define BLOCK_LOW(id,p,n)  ((id)*(n)/(p))
#define BLOCK_HIGH(id,p,n) (BLOCK_LOW((id)+1,p,n)-1)
#define BLOCK_SIZE(id,p,n) \
                     (BLOCK_HIGH(id,p,n)-BLOCK_LOW(id,p,n)+1)
#define BLOCK_OWNER(j,p,n) (((p)*((j)+1)-1)/(n))
//const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main()
{
	char t[] = "jldpgkSometimes he dug in his garden; again, he read or wrote.He hadbut one word for both these kinds of\
 toil; he called them gardening.The mind is a garden, said he.Towards midday, when the weather was fine, he went forth and tooa stroll in the c\
ountry or in town, and surmounted by a flat hat which allowedthree golden tassels of large bullion to droop from its three points.It was a perfect festival w\
herever he appeaor the Bishopas for the sun.He bestowed his blessing, and they blessed him.\
They pointed out his house to any one who was in need of anything.Here and there he halted, accostedfajofjiodjojrjioajioafjaopifo8wur89uh\
dfjjzjkafaueyuyepq98iahfhjahfaugfiafuagufgaofa;idfin former days.ried the Bishop,you are quite right, Madame Magloirnd he made his demand.\
Some time afterwards the General Council took this demand underconsideration, The He bestowed his blessing, and they blessed him.\
They pointed out his house to any one who was in need of anything.Here and there he halted, accostedfajofjiodjojrjioajioafjaopifo8wur89uh\
dfjjzjkafaueyuyepq98iahfhjahfaugfiafuagufgaofa;idfin former days.ried the Bishop,you are quite right, Madame Magloirnd he made his demand.\
Some time afterwards the General Council took this demand underconsideration, and voted him an annual sum of three thousand francs,\
under this heading:  Allowance to M.the Bishop for expensesof carriage, expenses of posting, and expenses of pastoral visits.\
This provoked a great outcry among the local burgesses;	and a senator of the Empire, a former member of the Council\
of the Five Hundred which favored the 18 Brumaire, and who wasprovided with a magnificent senatorial office in the vicinity\
of the town of D, wrote to M.Bigot de Preameneu,the minister of public worship, a very angry and confidential\
note on the subject, from which we extract these authentic lines : Expenses of carriage?  What can be done with it in a town of less\
han four thousand inhabitants Expenses of journeys ? What is the use of these trips, in the first place ? Next, how can the posting be accomplished in thes\
oajpfjaoijfkSometimes he dug in his garden; again, he read or wrote.He hadbut one word for both these kinds of\
 toil; he called them gardening.The mind is a garden, said he.Towards mid - day, when the weather was fine, he went forth and tooa stroll in the c\
ountry or in town, often entering lowly dwellingsHe was seen walking alone, buried in his own thoughts, his eyecast down, supporting himself on\
 his long cane, clad in his waddedpurple garment of silk, which was very warm, wearing purple stockinginside his coarse shoes, and surmou\
nted by a flat hat which allowedthree golden tassels of large bullion to droop from its three points.It was a perfect festival w\
herever he appeared.One would have saithat his presence had something warming and luminous about it\
The children and the old people came out to the doorsteps for the Bishopas for the sun.He bestowed his blessing, and they blessed him.\
They pointed out his house to any one who was in need of anything.Here and there he halted, accostedfajofjiodjojrjioajioafjaopifo8wur89uh\
dfjjzjkafaueyuyepq98iahfhjahfaugfiafuagufgaofa;idfin former days.ried the Bishop,you are quite right, Madame Magloirnd he made his demand.\
Some time afterwards the General Council took this demand underconsideration, and voted him an annual sum of three thousand francs,\
under this heading:  Allowance to M.the Bishop for expensesof carriage, expenses of posting, and expenses of pastoral visits.\
This provoked a great outcry among the local burgesses;	and a senator of the Empire, a former member of the Council\
of the Five Hundred which favored the 18 Brumaire, and who wasprovided with a magnificent senatorial office in the vicinity\
of the town of D, wrote to M.Bigot de Preameneu,the minister of public worship, a very angry and confidential\
note on the subject, from which we extract these authentic lines : Expenses of carriage?  What can be done with it in a town of less\
han four thousand inhabitants Expenses of journeys ? What is the use of these trips, in the first place ? Next, how can the posting be accomplished in thes\
jfkajifjoajpfjaoijfkSometimes he dug in his garden; again, he read or wrote.He hadbut one word for both these kinds of\
toil; he called them gardening.The mind is a garden, said he.Towards midday, when the weather was fine, he went forth and tooa stroll in the c\
ountry or in town, often entering lowly dwellingsHe was seen walking alone, buried in his own thoughts, his eyecast down, supporting himself on\
his long cane, clad in his waddedpurple garment of silk, which was very warm, wearing purple stockinginside his coarse shoes, and surmou\
nted by a flat hat which allowedthree golden tassels of large bullion to droop from its three points.It was a perfect festival w\
herever he appeared.One would have saithat his presence had something warming and luminous about it\
The children and the old people came out to the doorsteps for the Bishopas for the sun.He bestowed his blessing, and they blessed him.\
They pointed out his house to any one who was in need of anything.Here and there he halted, accostedfajofjiodjojrjioajioafjaopifo8wur89uh\
dfjjzjkafaueyuyepq98iahfhjahfaugfiafuagufgaofa; idfin former days.ried the Bishop, you are quite right, Madame Magloirnd he made his demand.\
Some time afterwards the General Council took this demand underconsideration, and voted him an annual sum of three thousand francs, \
under this heading:  Allowance to M.the Bishop for expensesof carriage, expenses of posting, and expenses of pastoral visits.\
This provoked a great outcry among the local burgesses;	and a senator of the Empire, a former member of the Council\
of the Five Hundred which favored the 18 Brumaire, and who wasprovided with a magnificent senatorial office in the vicinity\
of the town of D----, wrote to M.Bigot de Preameneu, the minister of public worship, a very angry and confidential\
note on the subject, from which we extract these authentic lines : Expenses of carriage ? What can be done with it in a town of less\
han four thousand inhabitants Expenses of journeys ? What is the use of these trips, in the first place ? Next, how can the posting be accomplished in thes\
jfkajifjoajpfjaoijfkSometimes he dug in his garden; again, he read or wrote.He hadbut one word for both these kinds of\
 toil; he called them gardening.The mind is a garden, said he.Towards mid - day, when the weather was fine, he went forth and tooa stroll in the c\
ountry or in town, often entering lowly dwellingsHe was seen walking alone, buried in his own thoughts, his eyecast down, supporting himself on\
 his long cane, clad in his waddedpurple garment of silk, which was very warm, wearing purple stockinginside his coarse shoes, and surmou\
nted by a flat hat which allowedthree golden tassels of large bullion to droop from its three points.It was a perfect festival w\
herever he appeared.One would have saithat his presence had something warming and luminous about it\
The children and the old people came out to the doorsteps for the Bishopas for the sun.He bestowed his blessing, and they blessed him.\
They pointed out his house to any one who was in need of anything.Here and there he halted, accostedfajofjiodjojrjioajioafjaopifo8wur89uh\
dfjjzjkafaueyuyepq98iahfhjahfaugfiafuagufgaofa;idfin former days.ried the Bishop,you are quite right, Madame Magloirnd he made his demand.\
Some time afterwards the General Council took this demand underconsideration, and voted him an annual sum of three thousand francs,\
under this heading:  Allowance to M.the Bishop for expensesof carriage, expenses of posting, and expenses of pastoral visits.\
This provoked a great outcry among the local burgesses;	and a senator of the Empire, a former member of the Council\
of the Five Hundred which favored the 18 Brumaire, and who wasprovided with a magnificent senatorial office in the vicinity\
of the town of D, wrote to M.Bigot de Preameneu,the minister of public worship, a very angry and confidential\
note on the subject, from which we extract these authentic lines : Expenses of carriage?  What can be done with it in a town of less\
han four thousand inhabitants Expenses of journeys ? What is the use of these trips, in the first place ? Next, how can the posting be accomplished in thes\
Sometimes he dug in his garden; again, he read or wrote.He hadbut one word for both these kinds of\
 toil; he called them gardening.The mind is a garden, said he.Towards mid - day, when the weather was fine, he went forth and tooa stroll in the c\
ountry or in town, often entering lowly dwellingsHe was seen walking alone, buried in his own thoughts, his eyecast down, supporting himself on\
 his long cane, clad in his waddedpurple garment of silk, which was very warm, wearing purple stockinginside his coarse shoes, and surmou\
nted by a flat hat which allowedthree golden tassels of large bullion to droop from its three points.It was a perfect festival w\
herever he appeared.One would have saithat his presence had something warming and luminous about it\
The children and the old people came out to the doorsteps for the Bishopas for the sun.He bestowed his blessing, and they blessed him.\
They pointed out his house to any one who was in need of anything.Here and there he halted, accostedfajofjiodjojrjioajioafjaopifo8wur89uh\
dfjjzjkafaueyuyepq98iahfhjahfaugfiafuagufgaofa;idfin former days.ried the Bishop,you are quite right, Madame Magloirnd he made his demand.\
Some time afterwards the General Council took this demand underconsideration, and voted him an annual sum of three thousand francs,\
under this heading:  Allowance to M.the Bishop for expensesof carriage, expenses of posting, and expenses of pastoral visits.\
This provoked a great outcry among the local burgesses;	and a senator of the Empire, a former member of the Council\
of the Five Hundred which favored the 18 Brumaire, and who wasprovided with a magnificent senatorial office in the vicinity\
of the town of D, wrote to M.Bigot de Preameneu,the minister of public worship, a very angry and confidential\
note on the subject, from which we extract these authentic lines : Expenses of carriage?  What can be done with it in a town of less\
han four thousand inhabitants Expenses of journeys ? What is the use of these trips, in the first place ? Next, how can the posting be accomplished in thes\
jfkajifjoajpfjaoijfkSometimes he dug in his garden; again, he read or wrote.He hadbut one word for both these kinds of\
 toil; he called them gardening.The mind is a garden, said he.Towards mid - day, when the weather was fine, he went forth and tooa stroll in the c\
ountry or in town, often entering lowly dwellingsHe was seen walking alone, buried in his own thoughts, his eyecast down, supporting himself on\
 his long cane, clad in his waddedpurple garment of silk, which was very warm, wearing purple stockinginside his coarse shoes, and surmou\
nted by a flat hat which allowedthree golden tassels of large bullion to droop from its three points.It was a perfect festival w\
herever he appeared.One would have saithat his presence had something warming and luminous about it\
The children and the old people came out to the doorsteps for the Bishopas for the sun.He bestowed his blessing, and they blessed him.\
They pointed out his house to any one who was in need of anything.Here and there he halted, accostedfajofjiodjojrjioajioafjaopifo8wur89uh\
dfjjzjkafaueyuyepq98iahfhjahfaugfiafuagufgaofa;idfin former days.ried the Bishop,you are quite right, Madame Magloirnd he made his demand.\
Some time afterwards the General Council took this demand underconsideration, and voted him an annual sum of three thousand francs,\
under this heading:  Allowance to M.the Bishop for expensesof carriage, expenses of posting, and expenses of pastoral visits.\
This provoked a great outcry among the local burgesses;	and a senator of the Empire, a former member of the Council\
of the Five Hundred which favored the 18 Brumaire, and who wasprovided with a magnificent senatorial office in the vicinity\
of the town of D----, wrote to M.Bigot de Preameneu,the minister of public worship, a very angry and confidential\
note on the subject, from which we extract these authentic lines : Expenses of carriage?  What can be done with it in a town of less\
han four thousand inhabitants Expenses of journeys ? What is the use of these trips, in the first place ? Next, how can the posting be accomplished in thes\
jfkajifjoajpfjaoijfkSometimes he dug in his garden; again, he read or wrote.He hadbut one word for both these kinds of\
 toil; he called them gardening.The mind is a garden, said he.Towards mid - day, when the weather was fine, he went forth and tooa stroll in the c\
ountry or in town, often entering lowly dwellingsHe was seen walking alone, buried in his own thoughts, his eyecast down, supporting himself on\
 his long cane, clad in his waddedpurple garment of silk, which was very warm, wearing purple stockinginside his coarse shoes, and surmou\
nted by a flat hat which allowedthree golden tassels of large bullion to droop from its three points.It was a perfect festival w\
herever he appeared.One would have saithat his presence had something warming and luminous about it\
The children and the old people came out to the doorsteps for the Bishopas for the sun.He bestowed his blessing, and they blessed him.\
They pointed out his house to any one who was in need of anything.Here and there he halted, accostedfajofjiodjojrjioajioafjaopifo8wur89uh\
dfjjzjkafaueyuyepq98iahfhjahfaugfiafuagufgaofa;idfin former days.ried the Bishop,you are quite right, Madame Magloirnd he made his demand.\
Some time afterwards the General Council took this demand underconsideration, and voted him an annual sum of three thousand francs,\
under this heading:  Allowance to M.the Bishop for expensesof carriage, expenses of posting, and expenses of pastoral visits.\
This provoked a great outcry among the local burgesses;	and a senator of the Empire, a former member of the Council\
of the Five Hundred which favored the 18 Brumaire, and who wasprovided with a magnificent senatorial office in the vicinity\
of the town of D, wrote to M.Bigot de Preameneu,the minister of public worship, a very angry and confidential\
note on the subject, from which we extract these authentic lines : Expenses of carriage?  What can be done with it in a town of less\
han four thousand inhabitants Expenses of journeys ? What is the use of these trips, in the first place ? Next, how can the posting be\
 accomplished in thes\0";
	int n = strlen(t);
	//char *t;
	//FILE *txtfile;
	//char p[] = "days";
	char p[] = "journeys";
	int m = strlen(p);
	int numMatches = 4;
	int i;
	int j;
	int k;
	double elapsed_time;
	int id;
	int num_p;
	int low_value;
	int high_value;
	int size;
	MPI_Status status;
	//int j;
	//int n;
	//int alphabetLength = strlen(alphabet);
	//int counter;
	// This variable storing the number of matches found can communicates with all processes
	int global_counter;
	// This variable  storing all of the found indeces can communicates with all processes.
	int global_shifts[MAX_TXT_SIZE - MAX_PATTERN_SIZE];
	int counter;  // counter is local variable use to store the number of matches found
	int *shifts; // Local virable to point to the indeces of the matches
	char *tmp;  // It is used to point to the m-1 characters in pattern p
	int err1;
	int err2;
	//char t2[100000];
	MPI_Init(NULL, NULL);
	MPI_Barrier(MPI_COMM_WORLD);
	elapsed_time = -MPI_Wtime();
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &num_p);
	low_value = BLOCK_LOW(id, num_p, n);
	high_value = BLOCK_HIGH(id, num_p, n);
	size = BLOCK_SIZE(id, num_p, n);

	printf("seaching target: %s\n", p);
	fflush(stdout);
	printf("rank(id): %d, number of proc: %d, n: %d\n", id, num_p, n);
	fflush(stdout);
	printf("[%d]low: %d, high: %d, size: %d\n", id, low_value, high_value, size);
	fflush(stdout);
	counter = 0;
	shifts = (int*)malloc((size)*sizeof(int));
	if (shifts == NULL)
	{
		printf("Cannot allocate enough memory:1.");
		fflush(stdout);
		exit(1);
	}
	//fopen_s(&txtfile, "textfile3.txt", "r");
	//fgets(t2, 100000, (FILE*)txtfile);

	//fclose(txtfile);
	//for (j = 0; j <= 100; ++j)
	//{
	//printf("%s", t);
	//printf("%s", t2);
	//}

	//t[] = "jfkajifjoajpfjaoijfajioopjifajofjiodjfaueyuyepq98iahfhjahfaugfiafuagufgaofa;idf"


	//r1 = strncpy_s(t, size, &global_t[low_value], size);

	for (i = low_value; i <= high_value; i++)
	{
		for (j = 0, k = 0; j < m; j++)
		{
			if (_stricmp(&t[j+i], &p[j]) != 0)
				break;
			k++;
			if (k == m)
			{
				shifts[counter++] = i;
				//printf("[%d]hit at %d\n on counter %d\n", id, i, counter);
			}
		}
	}

	if (id != 0)
	{
		
		printf("id: %d send t[%d] to %d\n", id, low_value, id-1);
		fflush(stdout);
		//MPI_Send(&t[low_value], m - 1, MPI_INT, i + 1, 6, MPI_COMM_WORLD);
		MPI_Send(&t[low_value], m - 1, MPI_BYTE, id - 1, 6, MPI_COMM_WORLD);
	}
	if (id != num_p - 1)
	{
		tmp = (char*)malloc(sizeof(2 * m - 1));
		if (shifts == NULL)
		{
			printf("Cannot allocate enough memory:2.");
			fflush(stdout);
			exit(1);
		}
		printf("id: %d recv tmp[%d] from %d\n", id, m - 1, id + 1);
		fflush(stdout);
		//MPI_Recv(&t[high_value + 1], m - 1, MPI_INT, i, 6, MPI_COMM_WORLD, &status);
		MPI_Recv(&tmp[m-1], m - 1, MPI_BYTE, id + 1, 6, MPI_COMM_WORLD, &status);
		
	}
	//MPI_Barrier(MPI_COMM_WORLD);
	
	err1 = strncpy_s(tmp, 2*m-1, &t[high_value-m+1],m-1);
	tmp[2 * m - 2] = '\0';
	for (i = 0 ; i < m-1; i++)
	{
		for (j = 0, k = 0; j < m; j++)
		{
			if (_stricmp(&t[j + i], &p[j]) != 0)
				break;
			k++;
			if (k == m)
				shifts[counter++] = high_value - m + 1 + i;
		}
	}
	

	printf("proc: %d: found %d matches.\n", id, counter);
	fflush(stdout);
	printf("proc: %d the first match at %d", id, *shifts);
	fflush(stdout);
	MPI_Reduce(&counter, &global_counter, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Gather(&shifts, counter, MPI_BYTE, &global_shifts[(int)size/m], counter, MPI_BYTE, 0, MPI_COMM_WORLD);
	if (counter == 0)
	{
		printf("This is no match.");
		fflush(stdout);
	}
	else if (!id)
	{
		//printf("proc: %d: found %d matches.\n", id, global_shifts[0], counter);
		printf("proc: %d: found %d matches.\n", id, counter);
		fflush(stdout);
	}
	printf("id %d global count: %d\n", id, global_counter);
	fflush(stdout);
	free(shifts);
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	free(t);
	return 0;
}




