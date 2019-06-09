#include <iostream>
#include <string>
#include "MixString.h"

#define CHECK_ANSWER "========Check Answer========"
#define CHECK_END "============================"
void CheckAns(const std::string &ans, const MixString &check)
{
	std::cout << CHECK_ANSWER << std::endl;
	std::cout << "Ans is : " << ans << std::endl;
	std::cout << " Check : " << check << std::endl;
	std::cout << CHECK_END << std::endl << std::endl;
}

void CheckAns(char ans, char check)
{
	std::cout << CHECK_ANSWER << std::endl;
	std::cout << "Ans is : " << ans << std::endl;
	std::cout << " Check : " << check << std::endl;
	std::cout << CHECK_END << std::endl << std::endl;
}

void CheckAnsBool(const std::string &ans, const MixString &check)
{
	std::cout << CHECK_ANSWER << std::endl;
	if (check == ans)
	{
		std::cout << "Great!" << std::endl;
	}
	else
	{
		std::cout << "Wrong!" << std::endl;
	}
	std::cout << CHECK_END << std::endl << std::endl;
}

int main(void)
{
	MixString abc("abc"), num("123"), ggggg("ggggg"), ss("ss"), ans;

	// ++(prefix) ++(postfix) >>
	MixString test;
	std::cin >> test;
	CheckAns("abc", test++);
	CheckAns("+abc+", ++test);
	ans.setString("");

	// [] out of range return the last char
	ans = abc;
	CheckAns('c', abc[10000]);
	CheckAns('b', abc[1]);

	// () repeat content 
	CheckAns("abcabcabc", abc(3));
	CheckAns("", abc(-1));

	// + +=
	ans = abc;
	ans = abc + num;
	CheckAns("a1b2c3", ans);
	ans += abc;
	CheckAns("aa1bbc2c3", ans);
	ans.setString("");
	ans = abc;
	ans = abc + ggggg;
	CheckAns("agbgcggg", ans);
	ans.setString("");
	ans = abc;
	ans = abc + ss;
	CheckAns("asbsc", ans);
	ans.setString("");

	// ==
	ans = abc + num + ggggg + ss;
	CheckAnsBool("asgs1gbg2gcg3", ans);
	CheckAnsBool("wrong", ans);

	system("PAUSE");
	return 0;
}