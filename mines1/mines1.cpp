#include "mines1.h"


void Mines1::initForm() {//init buttoms of mines
	layW = new QWidget;
	lay = new QVBoxLayout;
	layW->setLayout(lay);
	lay->setSpacing(0);
	lay->setMargin(0);
	for (int i = 0; i < 15; i++) {
		vector<QPushButton*> v;
		btnV.push_back(v);
		QWidget *line = new QWidget;
		QHBoxLayout *layLine = new QHBoxLayout;
		line->setLayout(layLine);
		layLine->setSpacing(0);
		layLine->setMargin(0);

		for (int j = 0; j < 15; j++)
		{
			QPushButton *bt = new QPushButton;
			bt->setFixedHeight(30);
			bt->setFixedWidth(30);
			
			btnV[i].push_back(bt);
			layLine->addWidget(btnV[i][j]);
		}
		lay->addWidget(line);
	}
}

void Mines1::initSurface() {//init all windows
	QVBoxLayout *back = new QVBoxLayout;
	setLayout(back);
	restart = new QPushButton(" Restart ");
	restart->setMinimumHeight(45);
	back->addWidget(restart);
	initForm();
	back->addWidget(layW);
}

void Mines1::conexion() {
	for (auto &line : btnV) {
		for (auto &b : line) {
			QObject::connect(b, &QPushButton::clicked, [&]() {
				if (b->isEnabled()) {
				

					int stop = 0;
					int i, j;
					for (i = 0; i < 15 && !stop; i++) {
						for (j = 0; j < 15 && !stop; j++){
							if (&b == &btnV[i][j]) {
								stop = 1;
							}
						}
					}
					if (bombs[i-1][j-1] == -1) {
						this->showAllAfterLose();
						QMessageBox::warning(nullptr, "Ai pierdut", "Ai pierdut!!!Mai incearca");
						doButtonsEnabled();
						initBombsAgain();
						generateBombsCompute();
					}
					else {
						if (nrBombs[i - 1][j - 1] == 0) {
							disbledAll0Buttons(i - 1, j - 1);
						}
						else {
							b->setText(QString::number(nrBombs[i - 1][j - 1]));
							if (b->isEnabled()) {
								score++;
								if (score == (225 - NBombs)) {
									this->showAllAfterLose();
									QMessageBox::information(nullptr, "Joc incheiat!", "Felicitari, ai castigat");
								}
							}
							b->setDisabled(true);
						}
					}
				}
			});
			//how to do left clicked QObject::connect(b, &QPushButton::, [&]() {});
			
		}
	}
	QObject::connect(restart, &QPushButton::clicked, [&]() {
		doButtonsEnabled();
		initBombsAgain();
		generateBombsCompute();
	});
}

void Mines1::doButtonsEnabled() {
	for (auto &lines : btnV) {
		for (auto &b : lines) {
			b->setDisabled(false);
			b->setText("");
		}
	}
}

void Mines1::createBombsNrBombs() {
	for (int i = 0; i < 15; i++) {
		vector<int> bmb;
		vector<int> nrBmb;
		bombs.push_back(bmb);
		nrBombs.push_back(nrBmb);
		for (int j = 0; j < 15; j++) {
			bombs[i].push_back(0);
			nrBombs[i].push_back(0);
		}
	}
}

void Mines1::initBombsAgain() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			bombs[i][j] = 0;
			nrBombs[i][j] = 0;
		}
	}
	score = 0;
}

void Mines1::generateNBombs() {
	srand(time(NULL));
	int a, b;
	for (int i = 0; i < NBombs;) {
		a = rand() % 15;
		b = rand() % 15;
		if (bombs[a][b] == 0) {
			bombs[a][b] = -1;
			i++;
		}
	}
}

void Mines1::computeNrBombs() {
	int x[] = { 0,1,1,1,0,-1,-1,-1 };
	int y[] = { -1,-1,0,1,1,1,0,-1 };
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			btnV[i][j]->setIcon(QIcon());
			if (bombs[i][j] == 0) {
				for (int poz = 0; poz < 8; poz++) {
					if (i + x[poz] >= 0 && i + x[poz] < 15 && j + y[poz] >= 0 && j + y[poz] <15)//validate index
						if (bombs[i + x[poz]][j + y[poz]] == -1)//verify for bomb
							nrBombs[i][j] += 1;
				}
			}
			else {
				nrBombs[i][j] = -1;
			}
		}
	}

}

void Mines1::generateBombsCompute() {
	generateNBombs();
	computeNrBombs();
	
}

void Mines1::disbledAll0Buttons(int i,int j) {
	int x[] = { 0,1,1,1,0,-1,-1,-1 };
	int y[] = { -1,-1,0,1,1,1,0,-1 };
	int line[226];
	int column[226];
	int ii = 0, is = 0;
	line[ii] = i;
	column[ii] = j;
	int freq[15][15] = { 0 };
	freq[i][j] = 1;
	while (ii <= is) {
		if (btnV[line[ii]][column[ii]]->isEnabled()) {
			btnV[line[ii]][column[ii]]->setDisabled(true);
			score++;
			if (score == (225 - NBombs)) {
				this->showAllAfterLose();
				QMessageBox::information(nullptr, "Joc incheiat!", "Felicitari, ai castigat");
			}
				
		}
		for (int poz = 0; poz < 8; poz++) {
			if (line[ii] + x[poz] >= 0 && line[ii] + x[poz] < 15 && column[ii] + y[poz] >= 0 && column[ii] + y[poz] < 15) {//validate index
				if (nrBombs[line[ii] + x[poz]][column[ii] + y[poz]] == 0 && freq[line[ii] + x[poz]][column[ii] + y[poz]]==0) {
					is++;
					line[is] = line[ii] + x[poz];
					column[is] = column[ii] + y[poz];
					freq[line[ii] + x[poz]][column[ii] + y[poz]] = 1;
				}
			}
		}
		ii++;
	}
}

void Mines1::showAllAfterLose() {
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++) {
			if (btnV[i][j]->isEnabled()) {
				btnV[i][j]->setDisabled(true);
				if (bombs[i][i] == -1)
					btnV[i][j]->setText(QString::number(nrBombs[i][j]));
				else {
					if(btnV[i][j]!=0)
						btnV[i][j]->setText(QString::number(nrBombs[i][j]));
				}
					
			}
		}
	}
}