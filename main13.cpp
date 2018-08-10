/* http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=2081&sca=20 ¹®Á¦ */

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
	int n, temp, count = 0;

	scanf_s("%d", &temp);
	n = temp;

	while (temp)
	{
		temp /= 2;
		count++;
	}

	for (int i = 32 - count; i < 32; i++)
		printf("%d", (n << i) & 0x80000000 ? 1 : 0);

	return 0;
}