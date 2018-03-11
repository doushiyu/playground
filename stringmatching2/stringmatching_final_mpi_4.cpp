// stringmatching_final_mpi_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <time.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_TXT_SIZE 230000
#define MAX_PATTERN_SIZE 10
#define BLOCK_LOW(id,p,n)  ((id)*(n)/(p))
#define BLOCK_HIGH(id,p,n) (BLOCK_LOW((id)+1,p,n)-1)
#define BLOCK_SIZE(id,p,n) \
                     (BLOCK_HIGH(id,p,n)-BLOCK_LOW(id,p,n)+1)
#define BLOCK_OWNER(j,p,n) (((p)*((j)+1)-1)/(n))


//const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main()
{
	int x = 0;
	//char t[] = "Expenses of carriage?  What can be done with it in a town of less\
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
han four thousand inhabitants Expenses of journeys ? What is the use of these trips, in the first place ? Next, how can the posting be\jldpgkSometimes he dug in his garden; again, he read or wrote.He hadbut one word for both these kinds of\
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
of the town of D, wrote to M.Bigot de Preameneu, the minister of public worship, a very angry and confidential\
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
\0";
	//int n = strlen(t);
	//char t[MAX_TXT_SIZE + 1] = { '\0' };
	//FILE *txtfile;
	//char p[] = "days";
	//int alphabetLength = strlen(alphabet);
	FILE *txtfile;
	int n;
	char p[] = "opifo8w"; // this will test tmp for -np == 2 and 4
						  //char p[] = "journeys";
	int m = strlen(p);
	//int numMatches = 4;
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
	
	//int counter;
	// This variable storing the number of matches found can communicates with all processes
	int global_counter;
	// This variable  storing all of the found indeces can communicates with all processes.
	int root_id = 0;
	int global_shifts[MAX_TXT_SIZE] = { -1 };
	int counter;  // counter is local variable use to store the number of matches found
	int *shifts; // Local virable to point to the indeces of the matches
				 //char *tmp;  // It is used to point to the m-1 characters in pattern p
	//FILE *fptr;
	char *t;
	int numfile;
	errno_t err;
	
	
	//printf("text:%.*s...%.*s", 100, t, t + (n - 100 + 1));
	printf("%d", x++);
	MPI_Init(NULL, NULL);
	printf("%d", x++);
	MPI_Barrier(MPI_COMM_WORLD);
	printf("%d", x++);
	elapsed_time = -MPI_Wtime();
	printf("%d", x++);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	printf("%d", x++);
	MPI_Comm_size(MPI_COMM_WORLD, &num_p);
	
	printf("%d",x++);
	fflush(stdout);
	if (id == 0)
	{
		printf("%d", x++);
		if ((fopen_s(&txtfile, "C:\\Users\\sarah\\Documents\\Visual Studio 2015\\Projects\\stringmatching_final_mpi_4\\stringmatching_final_mpi_4\\textfile2.txt", "r")) == 0) {
			printf("%d", x++);
			t = (char*)malloc(MAX_TXT_SIZE*sizeof(char));
			memset(t, '\0', MAX_TXT_SIZE);
			printf("%d", x++);
			numfile = fread_s(t, MAX_TXT_SIZE, 1000, 100, txtfile);
			printf("%d", x++);
			n = strlen(t);
			printf("%d", x++);
			fflush(stdout);
			printf("numfile: %d", numfile);
			printf("text = %s\n txt length: %d, read length:%d\n", t, n, numfile);
			fflush(stdout);
			printf("%d", x++);
			fclose(txtfile);
			printf("%d", x++);
		}
		else
		{
			_get_errno(&err);
			printf("error: %d\n", err);
			printf("Error! opening file");
			// Program exits if the file pointer returns NULL.
			exit(1);
		}
	}
	
	printf("%d", x++);

	MPI_Bcast(t, 1000 * 100, MPI_CHAR, root_id, MPI_COMM_WORLD);
	MPI_Bcast(&n, 1, MPI_INT, root_id, MPI_COMM_WORLD);

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
	shifts = (int*)calloc(size, sizeof(int));
	memset(shifts, -1, (size)*sizeof(int));
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
	for (i = low_value; i <= high_value - m + 1; i++)
	{
		//char sub_t[MAX_PATTERN_SIZE + 1] = {'\0'};
		//memcpy(sub_t, &t[i], m);
		//printf("sub_t: %s\n", sub_t);
		//sub_t[m] = '\0';
		if (_strnicmp(&t[i], p, m) == 0) {
			shifts[counter++] = i;
			printf("[%d]Matching at %d, %.*s, %s\n", id, i, m, t + i, p);
			fflush(stdout);
		}
		//if (!_stricmp(&t[j+i], p))
		//if (_stricmp(&t[j+i], &p[j]) != 0)
		//	break;
		//k++;
		//if (k == m)
		//{
		//	shifts[counter++] = i;
		//	//printf("[%d]hit at %d\n on counter %d\n", id, i, counter);
		//}
	}

	if (id != 0)
	{

		printf("id: %d send t[%d]'%.*s' to %d\n", id, low_value, m - 1, t + low_value, id - 1);
		fflush(stdout);
		//MPI_Send(&t[low_value], m - 1, MPI_INT, i + 1, 6, MPI_COMM_WORLD);
		MPI_Send(&t[low_value], m - 1, MPI_BYTE, id - 1, 6, MPI_COMM_WORLD);
	}
	char tmp[2*MAX_PATTERN_SIZE] = {'\0'};
	if (id != num_p - 1)
	{
		//tmp = (char*)malloc(sizeof(2 * m - 1));
		/*if (shifts == NULL)
		{
			printf("Cannot allocate enough memory:2.");
			fflush(stdout);
			exit(1);
		}*/
		printf("id: %d recv tmp[%d] from %d\n", id, m - 1, id + 1);
		fflush(stdout);
		//MPI_Recv(&t[high_value + 1], m - 1, MPI_INT, i, 6, MPI_COMM_WORLD, &status);
		//MPI_Recv(&tmp[m-1], m - 1, MPI_BYTE, id + 1, 6, MPI_COMM_WORLD, &status);
		memcpy(tmp, &t[high_value - m + 2], m - 1);
		MPI_Recv(&tmp[m - 1], m - 1, MPI_BYTE, id + 1, 6, MPI_COMM_WORLD, &status);
		tmp[2 * m - 2] = '\0';
		printf("[%d]tmp: %s\n", id, tmp);
		fflush(stdout);
	}
	//MPI_Barrier(MPI_COMM_WORLD);

	//err1 = strncpy_s(tmp, 2*m-1, &t[high_value-m+1],m-1);
	//tmp[2 * m - 2] = '\0';
	//printf("[%d]tmp: %s\n", id, tmp);
	// now search tmp
	if (id != num_p - 1)
		for (i = 0; i < m - 1; i++)
		{
			//char sub_tmp[MAX_PATTERN_SIZE + 1] = { 0 };
			//memcpy(sub_tmp, tmp + i, m);
			if (_strnicmp(tmp + i, p, m)==0) 
			{
				shifts[counter++] = high_value - m + 2 + i;
				printf("ÉµÏ±¸¾¶ù %d\n", shifts[counter - 1]);
				fflush(stdout);
			}
		}


	printf("proc: %d: found %d matches.\n", id, counter);
	fflush(stdout);
	if (counter)
	{
		printf("proc: %d the first match at %d\n", id, *shifts);
		fflush(stdout);
	}
	
	MPI_Reduce(&counter, &global_counter, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	//MPI_Gather(&shifts, counter, MPI_BYTE, &global_shifts[(int)size/m], counter, MPI_BYTE, 0, MPI_COMM_WORLD);
	/*for (i = 0; i < n - m + 1; ++i) {
		if (shifts[i] != -1 || counter != 0)
			printf("[%d]shifts[%d]: offset: %d\n", id, i, shifts[i]);
			fflush(stdout);
	}*/
	printf("id: %d, shifts[%d]: %d\n", id, 10, shifts[10]);
	fflush(stdout);
	printf("[%d]Gather: %d results from shifts at %d\n", id, counter, id*size);
	fflush(stdout);
	//int* recv_buffer = NULL;
	//if (id == root_id)
		//recv_buffer = shifts;

	MPI_Gather(shifts, size, MPI_INT, global_shifts, size, MPI_INT, root_id, MPI_COMM_WORLD);


	if (counter == 0)
	{
		printf("There is no match.");
		fflush(stdout);
	}
	else
	{
		//printf("proc: %d: found %d matches.\n", id, global_shifts[0], counter);
		printf("proc: %d: found %d matches.\n", id, counter);
		fflush(stdout);
	}
	MPI_Barrier(MPI_COMM_WORLD);
	elapsed_time += MPI_Wtime();
	MPI_Finalize();
	//free(t);
	free(t);
	free(shifts);
	if (id == root_id) {
		if (counter != 0)
			for (i = 0; i < n; i++)
			{
				if (global_shifts[i] != -1)
				{
					printf("global count: %d, %d shift: %d\n", global_counter, i + 1, global_shifts[i]);
					fflush(stdout);
				}
			}
		else
		{
			printf("There is no match.");
			fflush(stdout);
		}
		printf("execution time: %f", elapsed_time);
		fflush(stdout);
		/*for (i = 0; i < MAX_TXT_SIZE - MAX_PATTERN_SIZE; ++i) {
			if (shifts[i] != -1)
				printf("[%d]shifts[%d]: offset: %d, %.*s\n", id, i, shifts[i], m, t[shifts[i]]);
				fflush(stdout);
		}*/
	}
	
	return 0;
}









