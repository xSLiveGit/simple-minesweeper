#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/qgridlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <QtWidgets/qmessagebox.h>
#define NBombs 24
#define NCell
using namespace std;
class Mines1 : public QWidget
{
private:
	void initForm();
	void conexion();
	QVBoxLayout *lay;
	QWidget *layW;
	int NC = 15;
	vector<vector<QPushButton *>> btnV;
	void initSurface();
	QPushButton *restart;
	void doButtonsEnabled();
	vector<vector<int>> bombs; // cell say bombs positon bombs ==-1
	vector<vector<int>> nrBombs; // cell say how much bombs are near me !!! compute this after bombs generated 
	void createBombsNrBombs();
	void initBombsAgain();
	void generateNBombs();
	void computeNrBombs();
	void generateBombsCompute();
	void disbledAll0Buttons(int i,int j);
	void showAllAfterLose();
	int score;
public:
	Mines1() :score{ 0 } { initSurface(); createBombsNrBombs(); initBombsAgain(); generateBombsCompute();  conexion(); };
	~Mines1() = default;


};

