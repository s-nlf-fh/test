// test.cpp
// hikari

#include <iostream>
#include <string>
#include <vector>

#include <boost/version.hpp>
#include <boost/format.hpp>

using namespace std;
using namespace boost;

int main(int argc, char *argv[], char *envp[])
{
	vector<string> argstr(argv, argv + argc);
	vector<string> envstr(envp, [](char *i[]){while (*++i); return i;}(envp));

	cout << format("はろー\n");
	cout << format("Boost version : %1%.%2%.%3%\n\n") % (BOOST_VERSION / 100'000) % (BOOST_VERSION / 100 % 1'000) % (BOOST_VERSION % 100);

	cout << format("コマンドライン引数\n");
	for (auto &i : argstr)
		cout << format("%1%\n") % i;

	cout << format("\n環境変数\n");
	for (auto &i : envstr)
		cout << format("%1%\n") % i;

	cout << format("\nおわり\n");

	cin >> argstr[0];
	return 0;
}

