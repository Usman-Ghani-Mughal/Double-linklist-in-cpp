#include "node.h"

struct NodeImplementation
{
private:
	Node *START;
	int SIZE;
public:
	NodeImplementation();
	void createList(int);
	void add_at_beg(int);
	void add_at_pos(int,int);
	void del(int);
	void display();
	int count();
	void rev();
	bool search(int);
	void removefirTOlast();
	void removelasttofir();
	void infopartExchange();
	int checkOcurance(int);
	void swapNthMth(int,int);
	void countNUmberGroups();
	void Staticstics();
	void dislayToWay();
	void show();
};
/*
void create_list(int);
	void add_at_beg(int);
	void add_at_pos(int,int);
	void del(int);
	void display();
	int count();
	void rev();
	bool search(int);
	void removefirTOlast();
	void removelasttofir();
	void infopartExchange();
	int checkOcurance(int);
	void swapNthMth(int,int);
	void countNUmberGroups();
	void Staticstics();
*/