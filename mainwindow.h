//  qnetwalk/mainwindow.h
//  Copyright (C) 2004, Andi Peredri <andi@ukr.net>
//  Ported to Qt4 by xep

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMenu>
#include <QCloseEvent>

class Cell;
class QAction;
class QSound;
class QLCDNumber;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WindowFlags wf = 0);

protected:
	virtual void closeEvent(QCloseEvent*);
        void resizeEvent(QResizeEvent*);

private:
	enum Skill { Novice, Normal, Expert, Master };
	enum BoardSize
	{
		NoviceBoardSize = 7,
		NormalBoardSize = 9,
		ExpertBoardSize = 12,
		MasterBoardSize = 16
	};
	enum
	{
		NumHighscores   = 10,
		MinimumNumCells = 20
	};
	typedef QList<Cell *> CellList;
	int BoardSize;
	void initCells();
        void doResize();
        bool eventFilter(QObject *obj, QEvent *event);
	
private slots:
	void  help();
	void  about();
	void  newGame();
	void  cellClicked(int index);
	void  openHomepage();
	void  showHighscores();
	void  setSkill(int s);
	void  setSkillNovice() { setSkill(Novice); }
	void  setSkillNormal() { setSkill(Normal); }
	void  setSkillExpert() { setSkill(Expert); }
	void  setSkillMaster() { setSkill(Master); }

private:
	Cell* uCell(Cell* cell) const;
	Cell* dCell(Cell* cell) const;
	Cell* lCell(Cell* cell) const;
	Cell* rCell(Cell* cell) const;
	Cell* ulCell(Cell* cell) const;
	Cell* urCell(Cell* cell) const;
	Cell* dlCell(Cell* cell) const;
	Cell* drCell(Cell* cell) const;

	void  toggleCell(Cell *cell) const;

	int  cellsCount();
	bool  isGameOver();
	bool  startBrowser(const QString& url);
	bool  updateConnections();
	void  blink(int index);
	void  addRandomDir(CellList& list);
	void  addHighscore(int score);
	void  dialog(const QString& caption, const QString& text);

private:
	int skill;
	bool wrapped;
	bool start;
	Cell* root;
	Cell* board[MasterBoardSize * MasterBoardSize];
        int selected;
	QSound* clicksound;
	QSound* connectsound;
	QSound* startsound;
	QSound* turnsound;
	QSound* winsound;
	QString username;
	QString soundpath;
	QAction* soundaction;
	QActionGroup* skillActionGroup;
	QStringList highscores;
	QLCDNumber* lcd;
	QLCDNumber* cellsLcd;
	QMenu* gamemenu;
	QMenu* skillmenu;
};

#endif
