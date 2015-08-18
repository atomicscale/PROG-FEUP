#pragma once

class Solver {
private:
	// sudoku
	int numbers[9][9];

	// numero de casas preenchidas
	int countFilled;

	bool columnHasNumber[9][10];
	bool lineHasNumber[9][10];
	bool block3x3HasNumber[3][3][10];
	bool isComplete();
	bool start();
	bool accepts(int i, int j, int n);
	void initializeData();
	void place(int i, int j, int n);
	void clear(int i, int j);
	bool solve();

public:

	 Solver(int numbers[][10]);
	~Solver();
};