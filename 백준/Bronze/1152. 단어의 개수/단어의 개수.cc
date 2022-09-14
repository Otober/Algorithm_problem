#include <cstdio>
#include <string>
#include <iostream>
#define N 1000005

using namespace std;

int main()
{
	int cnt = 0;
	int tcnt = 0;
	string str;
	getline(cin, str);
	while (!str[tcnt]=='\0') {
		if (str[tcnt] != ' ') {
			if (tcnt == 0) cnt++;
			else if (str[tcnt - 1] == ' ') {
				cnt++;
			}
		}
		tcnt++;
	}
	printf("%d",cnt);
	return 0;
}