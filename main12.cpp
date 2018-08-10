/* http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1865&sca=20 ¹®Á¦ */

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
	char str[51];
	int result = 10;

	scanf_s("%s", str, sizeof(str));

	for (int i = 1; str[i]; i++)
		result += str[i] == str[i - 1] ? 5 : 10;

	printf("%d\n", result);

	return 0;
}