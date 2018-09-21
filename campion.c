#include <stdio.h>
#include <stdlib.h>

int solve(long *tickets, int mon, int n, int bmon)
{
	int i = 0;
	int ans = 0;

	if (!n || !(*tickets))
		return (0);
	if (mon < *tickets && n)
		ans += solve(&tickets[1], mon, n - 1, bmon);
	else if (mon == *tickets && n)
	{
		ans++;
		ans += solve(&tickets[1], mon, n - 1, bmon);
	}
	else
	{
		ans++;
		while (i < n)
		{
			ans += solve(&tickets[i + 1], mon - tickets[i], n - 1, bmon);
			i++;
		}
		if (mon == bmon)
			ans += solve(&tickets[1], mon, n - 1, bmon);
	}
	return (ans);
}

int main(void)
{
	int 	n;
	long 	mon;
	long 	*tickets;
	int 	ans = 0;
	FILE 	*in;
	FILE	*out;

	in = fopen("in.txt", "r");
	fscanf(in, "%d", &n);
	fscanf(in, "%ld", &mon);
	if (n < 1 || n > 40 || mon < 1 || mon > 1000000000000000000)
		return 0;
	tickets = (long *)malloc(sizeof(long) * (n + 1));
	for (int i = 0; i < n; i++)
	{
		fscanf(in, "%ld", &tickets[i]);
		if (tickets[i] > 10000000000000000)
			return (0);
	}
	fclose(in);
	tickets[n] = 0;
	ans = solve(tickets, mon, n, mon);
	out = fopen("out.txt", "w");
	fprintf(out ,"%d\n", ans + 1);
	fclose(out);
	return 0;
}
