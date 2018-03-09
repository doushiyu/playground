// stringmatching_parallel_final_project_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <time.h>
#include <mpi.h>
#include <stdio.h>
#include "MyMPI.h"
#define MAX_TXT_SIZE 14500
#define MAX_PATTERN_SIZE 10
//const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main()
{
	char t[] = "jldpgkSometimes he dug in his garden; again, he read or wrote.He hadbut one word for both these kinds of\
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
of the town of D----, wrote to M.Bigot de Preameneu,the minister of public worship, a very angry and confidential\
note on the subject, from which we extract these authentic lines : Expenses of carriage?  What can be done with it in a town of less\
han four thousand inhabitants Expenses of journeys ? What is the use of these trips, in the first place ? Next, how can the posting be accomplished in thes\jfkajifjoajpfjaoijfkSometimes he dug in his garden; again, he read or wrote.He hadbut one word for both these kinds of\
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
of the town of D----, wrote to M.Bigot de Preameneu,the minister of public worship, a very angry and confidential\
note on the subject, from which we extract these authentic lines : Expenses of carriage?  What can be done with it in a town of less\
han four thousand inhabitants Expenses of journeys ? What is the use of these trips, in the first place ? Next, how can the posting be accomplished in thes\0";
	int n = strlen(t);
	//FILE *txtfile;
	char p[] = "days";
	int m = strlen(p);
	int numMatches = 4;
	int i;
	int j;
	int k;
	float elapsed_time;
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
	int global_counter;
	int global_shifts[MAX_TXT_SIZE - MAX_PATTERN_SIZE];
	int counter;
	int *shifts;

	//char t2[100000];
	MPI_Init(NULL, NULL);
	MPI_Barrier(MPI_COMM_WORLD);
	elapsed_time = -MPI_Wtime();
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &num_p);
	low_value = BLOCK_LOW(id, num_p, n);
	high_value = BLOCK_HIGH(id, num_p, n);
	size = BLOCK_SIZE(id, num_p, n);
	counter = 0;
	shifts = (int*)malloc((size)*sizeof(int));
	if (shifts == NULL)
	{
		printf("Cannot allocate enough memory.");
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

	for (i = 0; i <= size - m; i++)
	{
		for (j = 0, k = 0; j < m; j++)
		{
			if (t[j + i] != p[j])
				break;
			k++;
			if (k == m)
			{
				shifts[counter] = i;
				counter++;
			}
		}
	}

	for (i = 0; i < num_p; i++)
	{
		if (id != 0)
		{
			MPI_Send(&t[low_value], m - 1, MPI_INT, i + 1, 6, MPI_COMM_WORLD);
		}
		if (id != num_p - 1)
		{
			MPI_Recv(&t[high_value + 1], m - 1, MPI_INT, i, 6, MPI_COMM_WORLD, &status);
		}

	}

	for (i = size - m + 1 ; i < 2 * m - 2; i++)
	{
		for (j = 0, k = 0; j < m; j++)
			if (t[j + i] != p[j])
				break;
			k++;
			if (k == m)
			{
				shifts[counter] = i;
				counter++;
			}
		
	}
	printf("proc: %d: found %d matches.\n", id, counter);
	fflush(stdout);
	MPI_Reduce(&counter, &global_counter, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Gather(&shifts, size, MPI_INT, &global_shifts, size, MPI_INT, 0, MPI_COMM_WORLD);
	if (counter == 0) 
	{
		printf("This is no match.");
		fflush(stdout);
	} 
	else if (!id)
	{
		printf("proc: %d: found %d matches.\n", id, global_shifts[0], counter);
		fflush(stdout);
	}
	MPI_Finalize();
	free(shifts);
    return 0;
}


