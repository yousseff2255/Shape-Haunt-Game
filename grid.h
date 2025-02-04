#pragma once
#include "CompositeShapes.h"
#include<vector>
class game;

class grid
{
	enum { MaxShapeCount = 1000  };	//assuming max shape count = 1000
	
	int rows, cols;	//numner of rows and columns in the grid to draw grid points
	int grid_height, grid_width;
	point uprLeft;	//upper left point of the grid

	//ShapeList should hold the RANDOMLY generated shapes
	shape** shapelist;//2D array of shape pointers

	shape* activeShape;	//The shape that the user works on to match to the ranom shapes
	int maxshapes;
	int shapeCount;		//current number of shapes in the list
	game* pGame;
	int numShapes;
	int height; int base;
	int level; // shlha ba3deeeen
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void draw() const;
	void clearGridArea() const;
	bool addShape(shape* newShape);
	void setActiveShape(shape* actShape);
	shape* getActiveShape() const;
	void editShapeCount();
	void deleteActiveShape();
	color getcolor(int);
	int getshapecount()const;
	void randomShapeGeneration();
	shape** getshapeList() const;
	void setshapecount(int);
	void SaveShapes(ofstream& OutFile);
	void LoadShapes(ifstream& InFile);
	bool checksaved();
};

