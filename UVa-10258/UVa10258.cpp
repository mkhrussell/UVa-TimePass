#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

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
	int teamId = 0;
	int numProb = 0;
	int totalPenaltyTime = 0;
	bool isParticipant = false;
	Problem probs[10];
} Team;

bool isGreater(Team leftTeam, Team rightTeam)
{
	if (leftTeam.numProb > rightTeam.numProb)
		return true;

	if (leftTeam.numProb == rightTeam.numProb)
	{
		if (leftTeam.totalPenaltyTime < rightTeam.totalPenaltyTime)
			return true;

		if (leftTeam.totalPenaltyTime == rightTeam.totalPenaltyTime)
		{
			if (leftTeam.teamId < rightTeam.teamId)
				return true;
		}
	}

	return false;
}

int main()
{
	int T;
	scanf("%d\n", &T);	
	while (T--)
	{
		int contestant, problem, time;
		char L;

		std::vector<Team> teams;
		for (int i = 0; i < 101; i++)
		{
			Team tmpTeam;
			tmpTeam.teamId = i;
			teams.push_back(tmpTeam);
		}

		char line[64];
		while ((fgets(line, sizeof line, stdin) != NULL) && (isEmpty(line) == 0))
		{
			if (sscanf(line, "%d %d %d %c", &contestant, &problem, &time, &L) == 4)
			{
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
					teams[contestant].isParticipant = true;
				}
				else {
					teams[contestant].isParticipant = true;
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

		std::sort(teams.begin(), teams.end(), isGreater);

		for (int theTeam = 0; theTeam < 101; theTeam++)
		{
			if (teams[theTeam].isParticipant)
			{
				if (teams[theTeam].numProb)
				{
					printf("%d %d %d\n", teams[theTeam].teamId, teams[theTeam].numProb, teams[theTeam].totalPenaltyTime);

				}
				else
				{
					printf("%d %d %d\n", teams[theTeam].teamId, 0, 0);
				}
			}
		}

		if(T) printf("\n"); // Extra new line after each case except last case
	}

	return 0;
}
