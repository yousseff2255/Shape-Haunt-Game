#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"



//Main class that coordinates the game operation
class game
{

	/// Add more members if needed

	toolbar* gameToolbar;
	keytype kt;
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid = nullptr;
	char pressedkey;
	vector<operation*>operations;
	int cnt;
	int endhint;
	shape* rand_shape;
	bool canhint;
	shape** shapelist;
	int step;
	int scorestep;
	int maxtime = 10;
	long int givens = 0;
	bool timed;
	int actiontime = 0;
	bool rectangleCaptured = false;

public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();		//creates the shapes grid
	void slevel();
	void countsteps();
	void incrementsteps();
	int getsteps() const;
	void givesteps();
	void drawgivensteps()const;
	void resethintcolor();
	int getgivensteps() const;
	vector<operation*> getvectoroperations() const;
	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid
	toolbar* getToolbar() const;
	bool IsMatching(shape*);
	void checktoload();
	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);
	void setendhint(int, shape*);
	void updatelevel();
	void stimed();
	void run();	//start the game
	void powerup();
	int getRandomNumber();
	bool IsRectangleCaptured(int, int, int, int, int, int);

};

