#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

int isSpace(int c)
{
	/* Space character table
	----------------------------
	space			(0x20, ' ')
	horizontal tab	(0x09, '\t')
	line feed		(0x0a, '\n')
	vertical tab	(0x0b, '\v')
	form feed		(0x0c, '\f')
	carriage return	(0x0d, '\r')
	*/

	if (c == 0x20 || (c >= 0x09 && c <= 0x0d))
		return 1;

	return 0;
}

int isEmpty(const char *line)
{
	/* check if the string consists only of spaces. */
	while (*line != '\0')
	{
		if (isSpace(*line) == 0)
			return 0;
		line++;
	}

	return 1;
}

typedef struct __Problem {
	int probId = 0;
	char prevSub = '\0';
	int penaltyTime = 0;
	int isSolved = 0;
} Problem;

typedef struct __Team {
	int numProb = 0;
	int totalPenaltyTime = 0;
	Problem probs[10];
} Team;

int main()
{
	int T;
	scanf("%d\n", &T);	
	while (T--)
	{
		int contestant, problem, time;
		char L;
		Team teams[101];
		
		char line[64];
		while ((fgets(line, sizeof line, stdin) != NULL) && (isEmpty(line) == 0))
		{
			if (sscanf(line, "%d %d %d %c", &contestant, &problem, &time, &L) == 4)
			{
				//printf("%d %d %d %c\n", contestant, problem, time, L);
				// Format Input
				if (!teams[contestant].probs[problem].isSolved && (L == 'C' || L == 'I'))
				{
					if (teams[contestant].probs[problem].prevSub == '\0' && L == 'C')
					{
						teams[contestant].probs[problem].penaltyTime += time;
						teams[contestant].probs[problem].isSolved = 1;
					}
					else if (teams[contestant].probs[problem].prevSub == '\0' && L == 'I')
					{
						teams[contestant].probs[problem].penaltyTime += 20;
					}
					else if (teams[contestant].probs[problem].prevSub == 'I' && L == 'C')
					{
						teams[contestant].probs[problem].penaltyTime += time;
						teams[contestant].probs[problem].isSolved = 1;
					}
					else if (teams[contestant].probs[problem].prevSub == 'I' && L == 'I')
					{
						teams[contestant].probs[problem].penaltyTime += 20;
					}
					

					teams[contestant].probs[problem].prevSub = L;
				}
				// End Format Input
			}
		}

		// Solve
		for (int theTeam = 1; theTeam < 101; theTeam++)
		{
			for (int prob = 1; prob < 10; prob++)
			{
				if (teams[theTeam].probs[prob].isSolved)
				{
					teams[theTeam].numProb++;
					teams[theTeam].totalPenaltyTime += teams[theTeam].probs[prob].penaltyTime;
				}
			}
		}

		for (int theTeam = 100; theTeam > 0; theTeam--)
		{
			if (teams[theTeam].numProb)
				printf("%d %d %d\n", theTeam, teams[theTeam].numProb, teams[theTeam].totalPenaltyTime);
		}

		if(T) printf("\n"); // Extra new line after each case except last case
	}

	return 0;
}
