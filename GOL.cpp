#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <ctime> 
#include <random>

using namespace std;


void createVecGrid(int GrdSZ, vector<vector<char>>&);
void createVecGrid(int GrdSZ, vector<vector<char>>& newVec) {
	
	for (int i = 0; i < GrdSZ; i++) {
	    vector<char> row; // Create an empty row
	    for (int j = 0; j < GrdSZ; j++) {
	        row.push_back(i * j); // Add an element (column) to the row
	    }
	    	newVec.push_back(row); // Add the row to the main vector
		}
}

void addElmToGrid(int GrdSZ, vector<vector<char>>&);
void addElmToGrid(int GrdSZ, vector<vector<char>>& newVec) {
	
	//Gen. Random Numbers
	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2);

	for (int i = 0; i < GrdSZ; ++i)
	{
		for (int j = 0; j < GrdSZ; ++j)
		{
			int newRandom_Num = dis(gen);
			if (newRandom_Num == 0 || 1) {
				newVec[i][j] = ' ';
			}
			if (newRandom_Num == 2) {
				newVec[i][j] = 'X';
			}	
		}
	}
}

void nextGenGrid(int GrdSZ, vector<vector<char>>&);
void nextGenGrid(int GrdSZ, vector<vector<char>>& PassedInVec) {
	// vector<vector<char> >* firstGrid;

	// Creates a new vector object and makes it the same
	// size as our current vector
	vector<vector<char>> newGrid;
	createVecGrid(GrdSZ, newGrid);

	// creates a vector that is pointing at the vector that was passed in.
	auto deleteMe = PassedInVec;

	// deleteMe = &PassedInVec;

    int n = 0, nx, ny;
    int wid = PassedInVec.size();
    int hei = PassedInVec.at(wid - 1).size();	

	//neighbours
	for (int i = 0; i < wid; i++) {
		for (int j = 0; j < hei; j++) {

			//check if there are any 'X' in the Grid
			//if (deleteMe.find('X') ) { continue; }

			// Top Row of the grid
			if (i == 0 && j < wid-1) { 
				//look right
				if (deleteMe.at(i+1).at(j) == 'X') {n++;}
				//look down
				if (deleteMe.at(i).at(j+1) == 'X') {n++;}
				//look down to right
				if (deleteMe.at(i+1).at(j+1) == 'X') {n++;}	
				//not in corner
				if (j != i) {
					//look left
					if (deleteMe.at(i).at(j-1) == 'X') {n++;}
					//look down to left
					if (deleteMe.at(i+1).at(j-1) == 'X') {n++;}
				}		
			}

			//Top Right corner
			if ( i == 0 && j == hei-1) {
				//look down
				if (deleteMe.at(i+1).at(j) == 'X') {n++;}
				//look left
				if (deleteMe.at(i).at(j-1) == 'X') {n++;}
				//look left to down
				if (deleteMe.at(i+1).at(j-1) == 'X') {n++;}			
			}

          	// Bottom Row of the grid not bottom right
			if (i == wid-1 && j < wid-1) { 
				//look up
				if (deleteMe.at(i-1).at(j) == 'X') {n++;}
				//look right
				if (deleteMe.at(i).at(j+1) == 'X') {n++;}
				//look right to up
				if (deleteMe.at(i-1).at(j+1) == 'X') {n++;}			
				//not in corner
				if (j != 0 )	{
					//look left
					if (deleteMe.at(i).at(j-1) == 'X') {n++;}
					//look up to left
					if (deleteMe.at(i-1).at(j-1) == 'X') {n++;}
				}
			}

			//Bottom Right corner
			if ( i == wid-1 && j == hei-1) {
				//look up
				if (deleteMe.at(i-1).at(j) == 'X') {n++;}
				//look left
				if (deleteMe.at(i).at(j-1) == 'X') {n++;}
				//look left to up
				if (deleteMe.at(i-1).at(j-1) == 'X') {n++;}			
			}


			// Far left col not in corner
			if (j == 0 &&  0 < i && i < hei-1) { 
				//look down
				if (deleteMe.at(i+1).at(j) == 'X') {n++;}
				//look right
				if (deleteMe.at(i).at(j+1) == 'X') {n++;}
				//look right to down
				if (deleteMe.at(i+1).at(j+1) == 'X') {n++;}	
				//look up
				if (deleteMe.at(i-1).at(j) == 'X') {n++;}
				//look up to right
				if (deleteMe.at(i-1).at(j+1) == 'X') {n++;}
				}
			// Far right col not in corner
			if (j == hei-1 &&  0 < i && i < hei-1) { 
				//look down
				if (deleteMe.at(i+1).at(j) == 'X') {n++;}
				//look left
				if (deleteMe.at(i).at(j-1) == 'X') {n++;}
				//look left to down
				if (deleteMe.at(i+1).at(j-1) == 'X') {n++;}	
				//look up
				if (deleteMe.at(i-1).at(j) == 'X') {n++;}
				//look up to left
				if (deleteMe.at(i-1).at(j-1) == 'X') {n++;}
				}

			//In the middle of the grid look all around
			if (i != 0 && j != 0 && i < wid-1 && j < hei-1) {
				//look down
				if (deleteMe.at(i+1).at(j) == 'X') {n++;}
				//look right
				if (deleteMe.at(i).at(j+1) == 'X') {n++;}
				//look right to down
				if (deleteMe.at(i+1).at(j+1) == 'X') {n++;}	
				//look up
				if (deleteMe.at(i-1).at(j) == 'X') {n++;}
				//look up to right
				if (deleteMe.at(i-1).at(j+1) == 'X') {n++;}
				//look left
				if (deleteMe.at(i).at(j-1) == 'X') {n++;}
				//look left to up
				if (deleteMe.at(i-1).at(j-1) == 'X') {n++;}	
				//look down to left
				if (deleteMe.at(i+1).at(j-1) == 'X') {n++;}
				//cout << "Made it in here once \n";
			}

        	// Deal with do i live update newGrid
			// if current grid is ' ' and has 3 around it put 'X' in it
			//cout << "n is this big " << n << " \n";
			if (n == 3 && deleteMe.at(i).at(j) == ' ') { newGrid.at(i).at(j) = 'X'; }
			if (n == 2 && deleteMe.at(i).at(j) == ' ') { newGrid.at(i).at(j) = ' '; }   
        	if (n <= 3 && n >= 2 && deleteMe.at(i).at(j) == 'X') { newGrid.at(i).at(j) = 'X'; }
  
        	//if n is more then 3 or less then 2 kil the square.        
        	if ((n >= 4 || n <= 1)) { newGrid.at(i).at(j) = ' '; }
           	n = 0;
    	}
	}
	// sets the passed in vector pointer to the one we just made
	PassedInVec = newGrid;

	// delete the old vector
	deleteMe.erase(deleteMe.begin(), deleteMe.end());
}




void printGrid(int GrdSZ, const vector<vector<char>>&);
void printGrid(int GrdSZ, const vector<vector<char>>& newVec){
	for(int p = 0; p < GrdSZ; ++p) {
		for(int q = 0; q < GrdSZ; ++q) {
		cout << '|' << newVec[p][q];
		}
		cout << "| \n";
	}	
	cout << "\n";
}
bool checkGrid(const vector<vector<char>>&);
bool checkGrid(const vector<vector<char>>& currentGrid) {
	int wid = currentGrid.size();
	for (int i = 0; i < wid; i++) {
		for (int j = 0; j < currentGrid.at(wid - 1).size(); j++) {
		if (currentGrid.at(i).at(j) == 'X') { return true; }
		}
	}
	return false;
}




int main() {


	srand(time(NULL));
	cout<< ">>Welcome to the Game of Life!\n";
	cout<<">>Please enter the size you wish your grid to be: \n";
	int GrdSZ;
	cin >> GrdSZ;
	cout<<">>How many generations do you wish to run?\n";
	int K;	
	cin >> K;
	cout<< "\n";

	vector< vector<char> > vec;
	createVecGrid(GrdSZ, vec);
	addElmToGrid(GrdSZ, vec);

	printGrid(GrdSZ, vec);
	

	//check if box is a one dem box
	if (vec.size() == 1) { 
		vec[0][0] = ' ';
		printGrid(GrdSZ, vec);
		cout << "You have died off! \n";
		return 0; 
	}

	//see if the grid is empty


	for (int l = 0; l < K; ++l) {
		nextGenGrid(GrdSZ, vec);
			bool r = checkGrid(vec);
			if (r == false) {
			cout << "You have died off!" << endl; 
			return 0;
		}
		printGrid(GrdSZ, vec);
	}

	cout << vec.size() << "\n";

return 0;

}