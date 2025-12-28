#include <bits/stdc++.h>
#include <fstream>
using namespace std;

constexpr int maxN { 100 };
int input[maxN];
int n;

enum class result_type {
	correctAnswer,
	noSolution,
	wrongAnswer
	// INFO: - Add other cases e.g. -
	/*
	 * -- Output should be a permutation of input
	 */
};

result_type readAns(ifstream &fin) 
{
	//INFO: Read the answer and implement checker logic
	return result_type::wrongAnswer;
}
int main()
{
	ifstream fin("input_file", ifstream::in);
	ifstream ans("myAnswer", ifstream::in);
	ifstream cor("correctAnswer", ifstream::in);

	fin >> n;
	result_type myAnswer = readAns(ans);
	result_type correctAnswer = readAns(cor);

	//INFO: Handle the result cases here

	if(myAnswer == result_type::wrongAnswer)
	{
		cout << "Wrong answer" << endl;
		return -1;
	}
	if(myAnswer == result_type::noSolution && correctAnswer == result_type::correctAnswer)
	{
		cout << "Brute force found a solution, but code didn't" << endl;
		return -1;
	}
	
	return 0;
}
