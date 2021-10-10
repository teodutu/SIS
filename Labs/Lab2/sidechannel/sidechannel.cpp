#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define BUF_SIZ 	100
#define MAX_WORDS 	100

const char *farticles = "dict/articles", *fnouns = "dict/nouns", *fadjectives = "dict/adjectives", *fverbs = "dict/verbs";
char **articles, **nouns, **adjectives, **verbs;
int narticles, nnouns, nadjectives, nverbs;

char* gimme (char **what, int n)
{
	int i = rand() % n;
	return what[i];
}

void read(const char *file, char** &list, int &n)
{
	char *line = (char*) malloc(BUF_SIZ);
	size_t len;
	int res;
	bool done = false;

	FILE *f = fopen(file,"r");
	list = new char*[MAX_WORDS];
	len = BUF_SIZ;

	n = 0;
	while (!done)
	{
		res = getline(&line, &len, f);
		if (res < 0)
			done = true;
		else
		{
			list[n] = new char[res];
			strncpy(list[n], line, res-1);		// remove trailing newline
			n++;
		}
	}
}

char* get_sentence()
{
	char *sentence = new char[BUF_SIZ];
	sentence[0] = 0;
	strcat(sentence, gimme(articles,narticles));
	strcat(sentence," ");
	strcat(sentence, gimme(adjectives,nadjectives));
	strcat(sentence," ");
	strcat(sentence, gimme(nouns,nnouns));
	return sentence;
}

int main ()
{
	struct timeval tstart, tend, t;
	long etime, secs, usecs;
	char *password, *guess;
	int i, npassword, nguess;
	size_t len;
	bool done;

	gettimeofday(&t, NULL);
	srand(t.tv_sec);

	read (farticles, articles, narticles);
	read (fnouns, nouns, nnouns);
	read (fadjectives, adjectives, nadjectives);
	read (fverbs, verbs, nverbs);

	password = get_sentence();
	npassword = strlen(password);
	guess = (char*) malloc (BUF_SIZ);
	len = BUF_SIZ;

	done = false;
	do
	{
		printf (">> Password: ");
		nguess = getline(&guess, &len, stdin);
		if (nguess < 0)
			exit(1);

		gettimeofday(&tstart, NULL);
		for (i=0; i<npassword; i++)
		{
			if (guess[i] != password[i])
				break;
			else if (i == npassword-1)
				done = true;
			usleep(10000);
		}

		gettimeofday(&tend, NULL);
		secs  = tend.tv_sec  - tstart.tv_sec;
		usecs = tend.tv_usec - tstart.tv_usec;
		etime = secs*1000000 + usecs + 0.5;
		printf("Elapsed time [%d] usec\n",(int) etime);
	}
	while (!done);
	printf ("\n>> Access granted!\n\n");

	return 0;
}
