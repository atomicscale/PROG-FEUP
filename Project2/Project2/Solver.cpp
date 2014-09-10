#include "Solver.h"
#include <cstring>


Solver::Solver(int numbers[][10])
{
	memcpy(this->numbers, numbers, sizeof(numbers));

}

bool Solver::start()
{
	Solver::initializeData();
	return solve();
}

//check if Complete
bool Solver::isComplete()
{
	return countFilled == 9 * 9;
}

void Solver::initializeData()
{
	
	// initializing data
	// meter tudo a false e countfilled a 0.
	countFilled = 0;

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 10; j++){
			columnHasNumber[i][j] = false;
			lineHasNumber[i][j] = false;
		}
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 10; k++){
				block3x3HasNumber[i][j][k] = false;
			}
		}
	}

	// updating data
	// percorrer numbers e actualizar arrays com valores correctos
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (numbers[i][j] != 0) {
				int n = numbers[i][j];
				lineHasNumber[i][n] = true;
				columnHasNumber[i][n] = true;
				block3x3HasNumber[i / 3][j / 3][n] = true;

				countFilled++;
			}
		}
	}
}

// retorna false se nao aceitar n em i, j
bool Solver::accepts(int i, int j, int n)
{
	// check line, column and block
	return !(lineHasNumber[i][n] || columnHasNumber[i][n] || block3x3HasNumber[i / 3][j / 3][n])
}

// mete numero na celula i, j
void Solver::place(int i, int j, int n)
{

	// updating sudoku
	numbers[i][j] = n;
	// updating line
	lineHasNumber[i][n] = true;
	// updating column
	columnHasNumber[i][n] = true;
	// updating block
	block3x3HasNumber[i / 3][j / 3][n] = true;
	// updating count
	countFilled++;
}

void Solver::clear(int i, int j) 
{
	int n = numbers[i][j];
	//updating line
	lineHasNumber[i][n] = false;
	// updating column
	columnHasNumber[i][n] = false;
	// updating block
	block3x3HasNumber[i / 3][j / 3][n] = false;
	// updating sudoku
	numbers[i][j] = 0;
	// updating count
	countFilled--;
}

bool Solver::solve()
{
	if (isComplete())

	return true;
	// start by searching for the cell with less candidates
	int besti = -1;
	int bestj = -1;
	int minNumPossibilities = -1;
	// going through every cell
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (numbers[i][j] == 0)

				


	// try out every possibility
	// aqui vais tentar preencher a celula que foi escolhida em cima, e vais tentar os candidatos possiveis

	for (int n = 1; n <= 9; n++) {
		if (accepts(bestj, besti, n)) {
			// place number
			place(besti, bestj, n);
			// returning if puzzle is solved
			if (solve())
				return true;
			// if not solved, clear wrong possibility
			clear(besti, bestj);
		}
	}

	return false;
}
