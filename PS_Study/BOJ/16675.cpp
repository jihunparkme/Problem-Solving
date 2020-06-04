#include <cstdio>

int Change(int x)
{
	if (x == 82)
		return 0;
	else if (x == 83)
		return 1;
	else
		return 2;
}

int main(void)
{	
	char a, b, c, d;
	int ML, MR, TL, TR;

	scanf("%c %c %c %c", &a, &b, &c, &d);

	ML = Change(a);
	MR = Change(b);
	TL = Change(c);
	TR = Change(d);

	if (ML == MR && ((ML + 2) % 3 == TL || (ML + 2) % 3 == TR))
		printf("TK\n");
	else if (TL == TR && ((TL + 2) % 3 == ML || (TL + 2) % 3 == MR))
		printf("MS\n");
	else
		printf("?");

	return 0;
}