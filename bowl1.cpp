#include<iostream>
#include <vector>
using namespace std;

const int FRAME_COUNT = 10;

int sum(vector<int> &frame) {
	int total = 0;
	for (int i = 0; i < frame.size(); ++i) {
		total += frame[i];
	}

	return total;
}

// for coding purposes don't count the last frame as a strike
bool isStrike(vector<int> &frame) {
	return sum(frame) == 10 && frame[1] == 0 && frame.size() != 3;
}

// for coding purposes don't count the last frame as a spare
bool isSpare(vector<int> &frame) {
	return sum(frame) == 10 && frame[1] != 0 && frame.size() != 3;
}

void printScore(vector<vector<int> > &board) {
	int runningSum = 0;

	for (int i = 0; i < board.size(); ++i) {
		runningSum += sum(board[i]);

		if (isStrike(board[i])) {
			runningSum += isStrike(board[i + 1])
				? board[i + 1][0] + board[i + 2][0]
				: board[i + 1][0] + board[i + 1][1];
		}
		else if (isSpare(board[i])) {
			runningSum += board[i + 1][0];
		}

		cout << runningSum << endl;
	}
}

void getInput(vector<vector<int> > &board) { 
	for (int round = 0; round < board.size(); ++round) {
		bool lastRound = round == board.size() - 1;

		cin >> board[round][0];
		
		if (board[round][0] != 10 || (lastRound && board[round][0] == 10)) {
			cin >> board[round][1];
		}

		if (lastRound && (
			board[round][0] + board[round][1] == 10 
			|| board[round][0] + board[round][1] == 20
			|| board[round][0] == 10)
		) {
			cin >> board[round][2];
		}
	}
}

int main() {
	vector<vector<int> > board(FRAME_COUNT, vector<int>(2, 0));
	
	// last frame has 3 entries
	board.back().push_back(0);

	// get bowling score input
	getInput(board);

	// print scores for each frame
	printScore(board);

	return 0;
}
