#include "game.h"
#include "gameConfig.h"
#include <iostream>
#include <sstream>
#include "CMUgraphicsLib\auxil.h"	// where Pause is found
#include<algorithm>
#include <memory>
#include <ctime>
#include <random>




game::game()
{
	step = 0;
	scorestep = 0;
	canhint = true;
	shapelist = nullptr;
	
	
	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	double introtimer = clock(); 
	while (clock() - introtimer < 5000) {
		
		pWind->DrawImage("images\\toolbarItems\\welcome.jpg", 0, 0, config.windWidth, config.windHeight );
		
	}
	pWind->SetPen(config.bkGrndColor);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(0, 0, config.windWidth, config.windHeight);

		//Create and draw the toolbar
		createToolBar();

		//Create and draw the grid



		//Create and clear the status bar
		clearStatusBar();

		
		stimed();
		slevel();
		createGrid();
		shapesGrid->draw();//draw the grid and all shapes it contains.

	
	
	
	
	
	
}



game::~game()
{
	delete pWind;
	delete shapesGrid;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
	shapesGrid->randomShapeGeneration();
}


void game::slevel()
{
	bool bQuit = false;
	keytype ktInput;
	clicktype ctInput;
	char cKeyData;
	step = 0;
	// Display initial message
	printMessage("Select a level from 1 to 10 (Press T or t for 10)");

	// Flush out the input queues before beginning
	pWind->FlushMouseQueue();
	pWind->FlushKeyQueue();

	do
	{
		pWind->SetPen(BLACK);

		ktInput = pWind->GetKeyPress(cKeyData);
		int score = gameToolbar->getscore();
		if ((cKeyData >= 48 && cKeyData < 58) || cKeyData == 84 || cKeyData == 116) {
			if (cKeyData >= 48 && cKeyData < 58)
			{
				ostringstream output;
				output << "You chose level '" << cKeyData << "'";
				pWind->DrawString(5, 180, output.str()); // Adjust Y coordinate for clarity4
				gameToolbar->setlevel(cKeyData - 48);
				if (shapesGrid != nullptr)
				{
					if (shapelist[0] != nullptr)
					{
						for (int i = 0; i < shapesGrid->getshapecount(); i++)
						{
							delete shapelist[i];
							shapelist[i] = nullptr;
						}
						if (shapesGrid->getActiveShape() != nullptr)
						{
							delete shapesGrid->getActiveShape();
							shapesGrid->setActiveShape(nullptr);

						}
						delete shapesGrid;
						shapesGrid = nullptr;
						createGrid();
						score = 0;
						gameToolbar->setscore(score);
					}
					else
					{
						if (shapesGrid->getActiveShape() != nullptr)
						{
							delete shapesGrid->getActiveShape();
							shapesGrid->setActiveShape(nullptr);

						}
						delete shapesGrid;
						shapesGrid = nullptr;
						createGrid();
						score = 0;
						gameToolbar->setscore(score);
					}
				}
				bQuit = true;
			}
			else
			{
				ostringstream output;
				output << "You chose level '10'";
				pWind->DrawString(5, 180, output.str()); // Adjust Y coordinate for clarity4
				gameToolbar->setlevel(10);
				if (shapesGrid != nullptr)
				{
					if (shapelist[0] != nullptr)
					{
						for (int i = 0; i < shapesGrid->getshapecount(); i++)
						{
							delete shapelist[i];
							shapelist[i] = nullptr;
						}
						if (shapesGrid->getActiveShape() != nullptr)
						{
							delete shapesGrid->getActiveShape();
							shapesGrid->setActiveShape(nullptr);
						}
						delete shapesGrid;
						shapesGrid = nullptr;
						createGrid();
						score = 0;
						gameToolbar->setscore(score);
					}
					else
					{
						if (shapesGrid->getActiveShape() != nullptr)
						{
							delete shapesGrid->getActiveShape();
							shapesGrid->setActiveShape(nullptr);

						}
						delete shapesGrid;
						shapesGrid = nullptr;
						createGrid();
						score = 0;
						gameToolbar->setscore(score);
					}
				}
				bQuit = true;
			}
		}

		// Pause for half a second
		Pause(500);


	} while (bQuit != true);
	givesteps();
}

void game::givesteps()
{
	
	int totalcompositeshapes = 0;
	for (int i = gameToolbar->getlevel(); i < 11; i++)
	{
		totalcompositeshapes += (2 * i - 1);
	}
	givens = 30 * totalcompositeshapes;
	drawgivensteps();
}

int game::getgivensteps() const
{
	return givens;
}

void game::drawgivensteps() const
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(BLACK);
	pWind->DrawRectangle(1250, config.windHeight - (int)(1 * config.statusBarHeight), config.windWidth, 621);

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(1270, config.windHeight - (int)(0.85 * config.statusBarHeight), "Given Steps = ");
	pWind->DrawInteger(1410, config.windHeight - (int)(0.85 * config.statusBarHeight), givens);
}


void game::incrementsteps()
{
	step += 1;
	scorestep += 1;
	gameToolbar->dsteps();
}

int game::getsteps() const
{
	return step;
}

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op=nullptr;
	switch (clickedItem)
	{

	case ITM_SIGN:
		op = new operAddSign(this);
		printMessage("you clicked on sign");
		operations.push_back(op);
		break;
	case ITM_BALL:
		op = new operAddstandingball(this);
		printMessage("you clicked on Standing ball");
		operations.push_back(op);
		break;
	case ITM_MAN:
		op = new operAddstrawman(this);
		printMessage("you clicked on Straw Man");
		operations.push_back(op);
		break;
	case ITM_PTR:
		op = new operAddpointer(this);
		printMessage("you clicked on Pointer Towards a Ball");
		operations.push_back(op);
		break;
	case ITM_GUN:
		op = new operAddgun(this);
		printMessage("you clicked on Gun");
		operations.push_back(op);
		break;
	case ITM_HOUSE:
		op = new operAddhouse(this);
		printMessage("you clicked on House");
		operations.push_back(op);
		break;
	case ITM_BAL:
		op = new operAddbalance(this);
		printMessage("you clicked on Balance");
		operations.push_back(op);
		break;
	case ITM_INC:
		if (shapesGrid->getActiveShape()) {
			op = new operResizeUp(this);
			incrementsteps();
			printMessage("you clicked on Resize Up");
			operations.push_back(op);
		}
		break;
	case ITM_DEC:
		if (shapesGrid->getActiveShape()) {
			op = new operResizeDown(this);
			incrementsteps();
			printMessage("you clicked on Resize Down");
			operations.push_back(op);
		}
		break;
	case ITM_DEL:
		if (shapesGrid->getActiveShape()) {
			op = new operDelete(this);
			printMessage("you clicked on Delete");
			operations.push_back(op);
		}
		break;
	case ITM_ROT:
		if (shapesGrid->getActiveShape()) {
			op = new operRotate(this);
			incrementsteps();
			printMessage("you clicked on Rotate");
			operations.push_back(op);
		}
		break;
	case ITM_FLP:
		if (shapesGrid->getActiveShape()) {
			op = new operFlip(this);
			incrementsteps();
			printMessage("you clicked on Flip");
		}
		break;
	case ITM_LVL:
		op = new operslevel(this);
		printMessage("Select a level from 1 to 10");
		operations.push_back(op);
		break;
	case ITM_REF:
		op = new operrefresh(this);
		printMessage("You clicked on Refresh");
		operations.push_back(op);
		break;
	case ITM_EXIT:
		if (shapesGrid->checksaved())
		{
			op = new operexit(this);
			printMessage("You clicked on Exit");
			delete op;
		}
		else
		{
			printMessage("You should save before EXIT!!!");
		}
		break;
	case ITM_HINT:
		if (canhint) {
			op = new operHint(this, cnt);
			printMessage("You selected on Hint");
			operations.push_back(op);
			canhint = false;
			break;
		}
	case ITM_SAVE:
		op = new operSave(this);
		printMessage("you clicked on Save");
		break;
	case ITM_LOAD:
		op = new operLoad(this);
		printMessage("you clicked on Load");
		break;
	}
	return op;
}




//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
	drawgivensteps();
}


window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}


string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}
toolbar* game::getToolbar() const
{
	return gameToolbar;
}


////////////////////////////////////////////////////////////////////////
void game::run()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem = ITM_CNT;

	double timer = clock();

	cnt = (2 * (gameToolbar->getlevel()) - 1) * maxtime;
	do
	{
		
		
			if (clock() - timer > 1000) {

				timer = clock();
				actiontime++;
				cnt--;
				if (timed) {
					gameToolbar->settime(cnt);
					gameToolbar->UpdateTimer(); 
				}
				if (cnt == 0) {
					gameToolbar->decrementlives();
					cout << "zerooooo";
					cnt = (2 * (gameToolbar->getlevel()) - 1) * maxtime;
				}
			}
		
		

		if (cnt == endhint) {
			resethintcolor();
			canhint = true;
		}


		


		if (gameToolbar->getlives() == 0) {
			
			double timer = clock();
			char Key;
			keytype ktype;
			while (clock() - timer < 3000) {
				pWind->DrawImage("images\\toolbarItems\\gameover.jpg", 300, config.toolBarHeight + 100, 1000, config.windHeight - 250);
				
			}
			return;
			
			
			
		}
		
		//printMessage("Ready...");
		//1- Get user click
		pWind->GetMouseClick(x, y);	//Get the coordinates of the user click
		//2-Explain the user click
		//If user clicks on the Toolbar, ask toolbar which item is clicked
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem = gameToolbar->getItemClicked(x);

			//3-create the approp operation accordin to item clicked by the user
			operation* op = createRequiredOperation(clickedItem);
			if (op) {
				op->Act();
				operations.push_back(op);
			}


			//4-Redraw the grid after each action
			shapesGrid->draw();
		}
		kt = pWind->GetKeyPress(pressedkey);

		if (kt == ASCII && shapesGrid->getActiveShape()) {
			printMessage("you clicked on ASCII");
			if (pressedkey == ' ') {
				printMessage("You clicked on Space");
				int score = gameToolbar->getscore();
				if (IsMatching(shapesGrid->getActiveShape())) {
					score += 2;
					printMessage("Mathcing !!");
					gameToolbar->setscore(score);
					if (scorestep - 30 < 0)
					{
						printMessage("Good Job!!! You matched the shape in less than 30 steps. One point bonus :)");
						score += 1;
						scorestep = 0;
						gameToolbar->setscore(score);
					    if (actiontime <= 7)
					    {
						powerup();
						if (rectangleCaptured == true)
						{
							ShapeType minimum = MAN;
							shape* ptr;
							
								for (int i = 0; i < shapesGrid->getshapecount(); i++)
								{
									if (shapelist[i]->getShapeType() < minimum)
									{
										minimum = shapelist[i]->getShapeType();
										ptr = shapelist[i];
									}
								}
								int shapecount = shapesGrid->getshapecount();
								swap(ptr, shapelist[shapecount - 1]);
								delete ptr;
								ptr = nullptr;
								shapesGrid->setshapecount(shapecount - 1);
								if ((shapesGrid->getshapecount() == 0))
								{
									updatelevel();
									givens -= step;
									drawgivensteps();
									step = 0;
									gameToolbar->dsteps();
								}
							
						   }
						actiontime = 0;
					}
				}
				else
				{
					printMessage("Oops!!! You matched the shape in more than 30 steps. No bonus :(");
					scorestep = 0;
					gameToolbar->setscore(score);
					if (actiontime <= 7 )
					{
						powerup();
						if (rectangleCaptured == true)
						{
							ShapeType minimum = MAN;
							shape* ptr;
							for (int i = 0; i < shapesGrid->getshapecount(); i++)
							{
								if (shapelist[i]->getShapeType() < minimum)
								{
									minimum = shapelist[i]->getShapeType();
									ptr = shapelist[i];
								}
							}
							int shapecount = shapesGrid->getshapecount();
							swap(ptr, shapelist[shapecount - 1]);
							delete ptr;
							ptr = nullptr;
							shapesGrid->setshapecount(shapecount - 1);
							if ((shapesGrid->getshapecount() == 0))
							{
								updatelevel();
								givens -= step;
								drawgivensteps();
								step = 0;
								gameToolbar->dsteps();
							}
						}
						actiontime = 0;
					}
					actiontime = 0;
				}

				shapesGrid->deleteActiveShape();
				//shapesGrid->editShapeCount();
			}
			else {
				score--;
				printMessage("Wrong Mathcing !!");
				gameToolbar->setscore(score);

			}
			shapesGrid->draw();


		}
	}

	if (kt == ARROW && shapesGrid->getActiveShape()) {
		printMessage("you clicked on arrow");
		operation* op2 = nullptr;
		op2 = new operMove(pressedkey, this);
		operations.push_back(op2);
		if (op2) {
			op2->Act();
			shapesGrid->draw();
		}
	}


} while (clickedItem != ITM_NULL);
}


bool game::IsMatching(shape* sh) {
	shapelist = shapesGrid->getshapeList();
	int shapecount = shapesGrid->getshapecount();
	for (int i = 0; i < shapesGrid->getshapecount(); i++) {

		if (shapelist[i]) {
			if (shapelist[i]->getRefPoint().x == sh->getRefPoint().x 
				&& shapelist[i]->getRefPoint().y == sh->getRefPoint().y 
				&& shapelist[i]->getrotated() == sh->getrotated() 
				&& shapelist[i]->getsize() == sh->getsize() 
				&& shapelist[i]->getShapeType() == sh->getShapeType()) 
			
			{
				std::swap(shapelist[i], shapelist[shapecount - 1]);
				delete shapelist[shapecount - 1];
				shapelist[shapecount - 1] = nullptr;
				shapesGrid->setshapecount(shapecount-1);				
				
				if ((shapesGrid->getshapecount() == 0))
				{
					updatelevel();
					givens -= step;
					drawgivensteps();
					step = 0;
					gameToolbar->dsteps();
					cnt = (2 * (gameToolbar->getlevel()) - 1) * maxtime;
				}
				
				return true;


			}
		}
	}

	return false;
}


vector<operation*> game::getvectoroperations() const
{
	return operations;
}


void game::resethintcolor() {
	rand_shape->setcolor(BLACK);
}
void game::setendhint(int c, shape* r_shape) {
	endhint = c;
	rand_shape = r_shape;
}

void game::updatelevel() {
	gameToolbar->setlevel(gameToolbar->getlevel() + 1);
	cout << gameToolbar->getlevel();
	this->createGrid();

}
void game::stimed() {
	while (true) {
		printMessage("Choose Game mode => F for free time game or T for timed game ");
		pWind->WaitKeyPress(pressedkey);



		if (pressedkey == 102) {
			timed = false;
			break;
		}
		else if (pressedkey == 116) {
			timed = true;
			break;
		}
		

	}

	
 }


void game::powerup() {
	int score = gameToolbar->getscore();
	int level = gameToolbar->getlevel();
	int lives = gameToolbar->getlives();
	delete gameToolbar;
	gameToolbar = nullptr;
	double start_time = static_cast<double>(clock()) / CLOCKS_PER_SEC;

	random_device randDevice;
	uniform_int_distribution<int> distX(0, config.windWidth);
	uniform_int_distribution<int> distY(config.toolBarHeight, static_cast<int>(0.75 * config.windHeight));

	point randRef;
	randRef.x = distX(randDevice) - (distX(randDevice) % config.gridSpacing);
	randRef.y = distY(randDevice) - (distY(randDevice) % config.gridSpacing);

	Rect* power1 = new Rect(this, randRef, 50, 100, BLACK);
	pWind->SetBuffering(true);

	while (!rectangleCaptured && ((static_cast<double>(clock()) / CLOCKS_PER_SEC) - start_time < 5)) {
		pWind->SetPen(config.bkGrndColor, 2);
		pWind->SetBrush(config.bkGrndColor);
		point upperLeft = { randRef.x - 50, randRef.y - 25 };
		point lowerRight = { randRef.x + 50, randRef.y + 25 };
		pWind->DrawRectangle(upperLeft.x, upperLeft.y, lowerRight.x, lowerRight.y, FILLED);

		int mouseX, mouseY;
		if (pWind->GetButtonState(LEFT_BUTTON, mouseX, mouseY) == BUTTON_DOWN) {
			if (IsRectangleCaptured(mouseX, mouseY, upperLeft.x, upperLeft.y, 200, 50)) {
				rectangleCaptured = true;
			}
		}

		switch (getRandomNumber()) {
		case 2:
			power1->move(4);
			break;
		case 4:
			power1->move(8);
			break;
		case 6:
			power1->move(2);
			break;
		case 8:
			power1->move(6);
			break;
		}

		power1->move(getRandomNumber());
		randRef = power1->getRefPoint();
		power1->draw();

		pWind->SetPen(WHITE, 25);
		pWind->SetFont(24, BOLD, BY_NAME, "Arial");
		pWind->DrawString(randRef.x - 50, randRef.y, "Power UP");

		pWind->UpdateBuffer();
		std::this_thread::sleep_for(chrono::milliseconds(25));
	}

	pWind->SetBuffering(false);
	delete power1;
	power1 = nullptr;
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor);
	pWind->DrawRectangle(0, 0, config.windWidth, config.gridHeight);
	clearStatusBar();
	createToolBar();
	gameToolbar->setlevel(level);
	gameToolbar->setscore(score);
	gameToolbar->setlives(lives);
	gameToolbar->dscorelevel();
	gameToolbar->drawlives();
	printMessage("One of the smaller shapes has removed !!");
}

int game::getRandomNumber() {
	int numbers[] = { 2, 4, 6, 8 };

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);

	return numbers[dis(gen)];
}

bool game::IsRectangleCaptured(int mouseX, int mouseY, int rectULX, int rectULY, int rectWidth, int rectHeight) {
	return ((mouseX > rectULX) && (mouseX < (rectULX + rectWidth)) &&
		(mouseY > rectULY) && (mouseY < (rectULY + rectHeight)));
}


