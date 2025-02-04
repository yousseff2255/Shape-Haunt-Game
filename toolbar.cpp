#include "toolbar.h"
#include "game.h"
#include<algorithm>
#include <memory>
#include<ctime>
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	height = config.toolBarHeight;
	width = config.windWidth;
	score = 0;
	level = 1;
	num_lives = 5;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\toolbar_sign.jpg";
	toolbarItemImages[ITM_PTR] = "images\\toolbarItems\\arrow.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";
	toolbarItemImages[ITM_HOUSE] = "images\\toolbarItems\\house.jpg";
	toolbarItemImages[ITM_GUN] = "images\\toolbarItems\\gun.jpg";
	toolbarItemImages[ITM_MAN] = "images\\toolbarItems\\man.jpg";
	toolbarItemImages[ITM_HINT] = "images\\toolbarItems\\hint.jpg";
	toolbarItemImages[ITM_DEL] = "images\\toolbarItems\\del.jpg";
	toolbarItemImages[ITM_ROT] = "images\\toolbarItems\\rot.jpg";
	toolbarItemImages[ITM_FLP] = "images\\ToolbarItems\\flip.jpeg";
	toolbarItemImages[ITM_BALL] = "images\\toolbarItems\\ball.jpg";
	toolbarItemImages[ITM_BAL] = "images\\toolbarItems\\bal.jpg";
	toolbarItemImages[ITM_SAVE] = "images\\toolbarItems\\save.jpg";
	toolbarItemImages[ITM_REF] = "images\\toolbarItems\\ref.jpg";
	toolbarItemImages[ITM_LOAD] = "images\\toolbarItems\\load.jpg";
	toolbarItemImages[ITM_INC] = "images\\toolbarItems\\inc.jpg";
	toolbarItemImages[ITM_DEC] = "images\\toolbarItems\\dec.jpg";
	toolbarItemImages[ITM_LVL] = "images\\toolbarItems\\lev.jpeg";

	
	

	
	
	
	
	string heart = "images\\toolbarItems\\Heartt.jpg";

	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);
	
	//Draw the lives
	for (int i = config.hearts_beg_pos_factor; i < (config.hearts_beg_pos_factor+ num_lives) ; i++)    
	pWind->DrawImage(heart, i * config.hearts_width, 0, config.hearts_width, config.hearts_height);

	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height,width , height);


	pWind->SetPen(config.TextColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.XscorePosition, config.YscorePosition, "Score = ");
	pWind->DrawInteger(config.XscorePosition + config.ScoreLength, config.YscorePosition, score);


	// Draw the Level
	pWind->SetPen(config.TextColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.XlevelPosition, config.YlevelPosition, "Level = ");
	pWind->DrawInteger(config.XlevelPosition + config.LevelLength, config.YlevelPosition, level);

}



//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	
	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}

void toolbar::drawlives()
{
	window* pWind = pGame->getWind();

	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(1100, 0, 1300, 35);

	string heart = "images\\toolbarItems\\Heartt.jpg";
	//Draw the lives
	for (int i = config.hearts_beg_pos_factor; i < (config.hearts_beg_pos_factor + num_lives); i++)
		pWind->DrawImage(heart, i * config.hearts_width, 0, config.hearts_width, config.hearts_height);
}

void toolbar::setlevel(int l)
{
	level = l;
	dscorelevel();
}

void toolbar::dsteps()
{
	window* pWind = pGame->getWind();

	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(1250, 35, 1400, 55);


	pWind->SetPen(config.TextColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(1250, 35, "Steps = ");
	pWind->DrawInteger(1250 + config.ScoreLength, 35, pGame->getsteps());

}

void toolbar::dscorelevel()
{
	window* pWind = pGame->getWind();
	
	/*XscorePosition = 1400, YscorePosition = 5,
	XlevelPosition = 1400, YlevelPosition = 35,*/
	// Draw the score
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(1400, 5, config.windWidth, 55);

	pWind->SetPen(config.TextColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.XscorePosition, config.YscorePosition, "Score = ");
	pWind->DrawInteger(config.XscorePosition + config.ScoreLength, config.YscorePosition, score);


	// Draw the Level
	pWind->SetPen(config.TextColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.XlevelPosition, config.YlevelPosition, "Level = ");
	pWind->DrawInteger(config.XlevelPosition + config.LevelLength, config.YlevelPosition, level);
}

void toolbar::setscore(int newscore) {
	score = newscore;
	dscorelevel();
}
void toolbar::setlives(int new_num_lives) {
	num_lives = new_num_lives;
}
int toolbar::getlevel()  const {
	return level;
}
int toolbar::getscore()  const {
	return score;
}

int toolbar::getlives()  const {
	return num_lives;
}

void toolbar::decrementlives()
{
	num_lives--;
	drawlives();
}

void toolbar::UpdateTimer() {
	window* pWind = pGame->getWind();

	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(1100, 35, 1220, 55);

	pWind->SetPen(config.TextColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(1100, 35, "Time = ");
	pWind->DrawInteger(1180, 35, time);
}



void toolbar::settime(int newtime) {
	time = newtime;

}

int toolbar::gettime() const {
	return time;
}