#pragma once
#include <thread>
#include <chrono>
#include "shape.h"











class shape;

class game;

class operation                   //Base class of all operations supported by the application
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);

	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
};

//Each member class is Responsible for :
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)



class operAddSign:public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};




class operAddstrawman : public operation
{
public:
	operAddstrawman(game* r_pGame);
	virtual void Act();
};




class operAddpointer : public operation
{
public:
	operAddpointer(game* r_pGame);
	virtual void Act();
};




class operAddstandingball : public operation
{
public:
	operAddstandingball(game* r_pGame);
	virtual void Act();
};





class operAddgun : public operation
{
public:
	operAddgun(game* r_pGame);
	virtual void Act();
};



class operAddhouse : public operation
{
public:
	operAddhouse(game* r_pGame);
	virtual void Act();
};



class operAddbalance : public operation
{
public:
	operAddbalance(game* r_pGame);
	virtual void Act();
};

class operDelete :public operation
{
public:
	operDelete(game* r_pGame);
	virtual void Act();
};

class operResizeUp :public operation
{
public:
	operResizeUp(game* r_pGame);
	virtual void Act();
};
class operResizeDown :public operation
{
public:
	operResizeDown(game* r_pGame);
	virtual void Act();
};
class operFlip : public operation
{
	
public:
	operFlip(game* r_pGame);
	virtual void Act();
};
class operRotate : public operation
{

public:
	operRotate(game* r_pGame);
	virtual void Act();
};
class operMove :public operation
{
	char key;
public:
	operMove(char c ,game* r_pgame);
	virtual void Act();
};



class operslevel : public operation
{
public:
	operslevel(game* r_pGame);
	virtual void Act();
};

class operexit : public operation
{
	shape** shapelist;
public:
	operexit(game* r_pGame);
	virtual void Act();
};
class operHint : public operation
{
	int begin;
	shape** shapelist = nullptr;
public:
	operHint(game* r_pGame, int begcount);
	virtual void Act();
};

class operrefresh : public operation
{
	shape** shapelist = nullptr;
public:
	operrefresh(game* r_pGame);
	virtual void Act();
};

class operSave :public operation
{
public:
	operSave(game* r_pGame);
	virtual void Act();
};
class operLoad :public operation
{
public:
	operLoad(game* r_pGame);
	virtual void Act();
};