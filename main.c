#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int picker(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int plansza[10][10]={0};
	//pion oznacza odpowiedzi z lewej a poziom odp z gory!
	/*int pion[10][2] = {
		{4, 0},
		{4, 0},
		{4, 0},
		{4, 0},
		{4, 0},

		{8, 0},
		{10, 0},
		{8, 0},
		{4, 0},
		{4, 0},
	};
	int poziom[10][2] = {
		{1,0},
		{3,0},
		{3,0},
		{10,0},
		{10,0},

		{10,0},
		{10,0},
		{3,0},
		{3,0},
		{1,0},
	};*/
	/*int pion[10][4] = {
		{4,0},
		{2,4,0},
		{2,3,0},
		{2,2,2,0},
		{2,2,2,0},

		{3,3,0},
		{4,4,0},
		{9,0},
		{8,0},
		{4,0},
	};
	int poziom[10][4] = {
		{4,0},
		{6,0},
		{2,4,0},
		{2,4,0},
		{1,2,3,0},

		{1,2,3,0},
		{2,4,0},
		{2,4,0},
		{8,0},
		{8,0},
	};*/
	/*int pion[10][5] = {
		{3,1,2,0},
		{5,4,0},
		{10,0},
		{9,0},
		{4,3,0},
		
		{2,0},
		{2,2,0},
		{1,4,0},
		{1,7,0},
		{10,0},
	};
	int poziom[10][5] = {
		{2,1,0},
		{5,4,0},
		{7,1,0},
		{6,2,0},
		{4,2,0},

		{1,2,3,0},
		{4,4,0},
		{5,4,0},
		{5,3,0},
		{3,2,0},
	};*/ 
	/*int pion[10][5] = {
		{3,0},
		{2,0},
		{2,0},
		{6,0},
		{6,0},

		{6,0},
		{10,0},
		{6,0},
		{8,0},
		{10,0},
	};
	int poziom[10][5] = {
		{1,1,0},
		{1,2,0},
		{7,0},
		{7,0},
		{10,0},

		{10,0},
		{1,7,0},
		{7,0},
		{1,2,0},
		{1,1,0},
	};*/
	int pion[10][5] = {
		{3,2,0},
		{5,4,0},
		{5,4,0},
		{5,2,0},
		{2,3,0},

		{2,3,0},
		{5,2,0},
		{5,4,0},
		{5,4,0},
		{3,2,0},
	};
	int poziom[10][5] = {
		{2,2,0},
		{4,4,0},
		{4,4,0},
		{10,0},
		{8,0},
		
		{1,1,0},
		{2,2,2,0},
		{3,2,3,0},
		{10,0},
		{3,3,0},
	};
	int step = 0;
	int i_did_nothing_for = 0;
	int control = 0;
	int last_sum = 0;
	while (1)
	{
		int plansza_suma = 0;
	
		//wyznaczanie 10
		if (step == 0) {
			for (int i = 0; i < 10; i++) {
				if (pion[i][0] == 10) {
					for (int j = 0; j < 10; j++) {
						plansza[i][j] = 1;
					}
					pion[i][0] = -1;
					pion[i][1] = 0;
				}
			}
			for (int i = 0; i < 10; i++) {
				if (poziom[i][0] == 10) {
					for (int j = 0; j < 10; j++) {
						plansza[j][i] = 1;
					}
					poziom[i][0] = -1;
					poziom[i][1] = 0;
				}
			}
			step++;
		}
		//wyznaczanie >= 6
		else if (step == 1) {
			//pion
			for (int i = 0; i < 10; i++) {
				if ((pion[i][0] >=6 && pion[i][0] != 10)||(pion[i][1] >= 6 && pion[i][0] != 10)) {
					int how_much = picker(pion[i][0], pion[i][1]) % 5;
					int x_minus = 4;
					int x_plus = 5;
					while (1)
					{
						if (how_much) {
							if (plansza[i][x_minus] != 1) {
								plansza[i][x_minus] = 1;
							}
							if (plansza[i][x_plus] != 1) {
								plansza[i][x_plus] = 1;
							}
							how_much--;
							x_minus--;
							x_plus++;
						}
						else {
							break;
						}
					}
				}
			}
			//poziom
			for (int i = 0; i < 10; i++) {
				if (poziom[i][0] >= 6 && poziom[i][0] != 10||(poziom[i][1] >= 6 && poziom[i][0] != 10)) {
					int how_much = picker(poziom[i][0],poziom[i][1]) % 5;
					int x_minus = 4;
					int x_plus = 5;
					while (1)
					{
						if (how_much) {
							if (plansza[x_minus][i] != 1) {
								plansza[x_minus][i] = 1;
							}
							if (plansza[x_plus][i] != 1) {
								plansza[x_plus][i] = 1;
							}
							how_much--;
							x_minus--;
							x_plus++;
						}
						else {
							break;
						}
					}
				}
			}
			step++;
		}
		//szukanie po sumie
		else if (step == 2) {
			//pion
			for (int i = 0; i < 10; i++) {
				int pion_suma = 0;
				int ile_bloków = 0;
				for (int j = 0;; j++) {
					ile_bloków = j;
					if (pion[i][j] == 0 || pion[i][j] == -1) break;
					else pion_suma += pion[i][j];
					if (j != 0) pion_suma++;
				}
				if (pion_suma == 10) {
					for (int k = 0; k < ile_bloków; k++) {
						int how_much = pion[i][k];
						if (how_much >= 5) {
							int x=0;
							for (x = 0; x < how_much; x++) {
								if(plansza[i][x] == 0) plansza[i][x] = 1;
							}
							if (plansza[i][x] == 0) plansza[i][x] = 2;
						}
						else {
							int y = 0;
							for (y = 0; how_much > 0; y++) {
								if (plansza[i][y] == 0) {
									plansza[i][y] = 1;
									how_much--;
								}
							}
							if (plansza[i][y] == 0) plansza[i][y] = 2;
						}
					}
					pion[i][0] = -1;
					pion[i][1] = 0;
				}
			}
			//poziom
			for (int i = 0; i < 10; i++) {
				int poziom_suma = 0;
				int ile_bloków = 0;
				for (int j = 0;; j++) {
					ile_bloków = j;
					if (poziom[i][j] == 0 || poziom[i][j] == -1) break;
					else poziom_suma += poziom[i][j];
					if (j != 0) poziom_suma++;
				}
				if (poziom_suma == 10) {
					for (int k = 0; k < ile_bloków; k++) {
						int how_much = poziom[i][k];
						if (how_much >= 5) {
							int x = 0;
							for (x = 0; x < how_much; x++) {
								if (plansza[x][i] == 0) plansza[x][i] = 1;
							}
							if (plansza[x][i] == 0) plansza[x][i] = 2;
						}
						else {
							int y = 0;
							for (y = 0; how_much > 0; y++) {
								if (plansza[y][i] == 0) {
									plansza[y][i] = 1;
									how_much--;
								}
							}
							if (plansza[y][i] == 0) plansza[y][i] = 2;
						}
					}
					poziom[i][0] = -1;
					poziom[i][1] = 0;
				}

			}

			
			step++;
		}
		//szukanie od krawedzi
		else if (step == 3) {
			//krawedz lewa j=0 | tu tylko pion pierwszy
			for (int i = 0; i < 10; i++) {
				if (plansza[i][0] == 1) {
					int how_much = pion[i][0]; int j = 0;
					if (how_much == -1) continue;
					for (j = 0; j < how_much; j++) {
						plansza[i][j] = 1;
					}
				}
			}
			//krawedz gorna i=0 ^ tu tylko poziom pierwszy
			for (int i = 0; i < 10; i++) {
				if (plansza[0][i] == 1) {
					int how_much = poziom[i][0]; int j = 0;
					if (how_much == -1) continue;
					for (j = 0; j < how_much; j++) {
						plansza[j][i] = 1;
					}
				}
			}
			//krawedz prawa j=9  | tu tylko pion ostatni
			for (int i = 0; i < 10; i++) {
				if (plansza[i][9] == 1) {
					//petla do znalezienia ostatniej
					int how_much=0;
					for (int x = 0; how_much == 0; x++) {
						if (pion[i][x + 1] == 0) {
							how_much = pion[i][x];
						}
					}
					for (int j = 9; how_much > 0; j--,how_much--) {
						plansza[i][j] = 1;
					}
				}
			}
			//krawedz dolna i=9 _ tu tylko poziom ostatni
			for (int i = 0; i < 10; i++) {
				if (plansza[9][i] == 1) {
					//petla do znalezienia ostatniej
					int how_much = 0;
					for (int x = 0; how_much == 0; x++) {
						if (poziom[i][x + 1] == 0) {
							how_much = poziom[i][x];
						}
					}
					for (int j = 9; how_much > 0; j--, how_much--) {
						plansza[j][i] = 1;
					}
				}
			}
			step++;
		}
		//dodawanie - w skonczonych liniach konczenie tych wykonanych (ustalenie pion/poziom indeks 0 na wartosc -1)
		else if (step == 4) {
			//pion
			for (int i = 0; i < 10; i++) {
				if (pion[i][0] != -1) {
					int pion_suma = 0;
					int pion_planszy = 0;
					for (int j = 0;; j++) {
						if (pion[i][j] == 0) break;
						else pion_suma += pion[i][j];
					}
					for (int j = 0; j < 10; j++) {
						if (plansza[i][j] == 1) {
							pion_planszy += plansza[i][j];
						}
					}
					if (pion_planszy == pion_suma) {
						for (int j = 0; j < 10; j++) {
							if (plansza[i][j] == 0) {
								plansza[i][j] = 2;
							}
						}
						pion[i][0] = -1;
						pion[i][1] = 0;
					}
				}
			}
			//poziom
			for (int i = 0; i < 10; i++) {
				if (poziom[i][0] != -1) {
					int poziom_suma = 0;
					int poziom_planszy = 0;
					for (int j = 0;; j++) {
						if (poziom[i][j] == 0) break;
						else poziom_suma += poziom[i][j];
					}
					for (int j = 0; j < 10; j++) {
						if (plansza[j][i] == 1) {
							poziom_planszy += plansza[j][i];
						}
					}
					if (poziom_planszy == poziom_suma) {
						for (int j = 0; j < 10; j++) {
							if (plansza[j][i] == 0) {
								plansza[j][i] = 2;
							}
						}
						poziom[i][0] = -1;
						poziom[i][1] = 0;
					}
				}
			}


			step++;
		}
		//konczenie lini jezeli idealna ilosc blokow zostaje
		else if (step == 5) {
			//pion
			for (int i = 0; i < 10; i++) {
				int pion_suma = 0;
				int przerwy = 0;
				if (pion[i][0] != -1) {
					int zero = 1;
					for (int j = 0; j < 10; j++) {
						if (zero) {
							if (pion[i][j] == 0) zero = 0;
							pion_suma += pion[i][j];
						}
						if (plansza[i][j] != 0) {
							if (plansza[i][j] == 2) przerwy++;
						}
					}
					if (pion_suma + przerwy == 10) {
						for (int j = 0; j < 10; j++) {
							if (plansza[i][j] == 0) plansza[i][j] = 1;
						}
						pion[i][0] = -1;
						pion[i][1] = 0;
					}
				}

			}
			step++;
		}
		//dodanie mozliwych blokow po polach w ktorych z pewnoscia nie ma bloku
		else if (step == 6) {
			step++;
		}
		//printing
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				plansza_suma+=plansza[i][j];
			}
		}
		if (last_sum != plansza_suma) {
			i_did_nothing_for = 0;
			system("cls");
			printf("\t");
			for (int i = 0; i < 10; i++) printf("  %d  ", i+1);
			printf("\n");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (j == 0) printf("%d:\t", i+1);
					if (plansza[i][j] == 0) printf("     ");
					else if(plansza[i][j] == 2) printf("  -  ");
					else if (plansza[i][j] == 1) printf("  X  ");
				}	
				printf("\n");
			}
			int count_done = 1;
			for (int x = 0; x < 10; x++) {
				if (pion[x][0] == -1) count_done++;
				if (poziom[x][0] == -1) count_done++;
			}
			printf("\nLINES DONE: %d", count_done);
			if (count_done == 20) break;
			last_sum = plansza_suma;
		}
		else {
			i_did_nothing_for++;
			if (i_did_nothing_for == 5 && control < 4) {
				step = 4;
				control++;
			}
			if (i_did_nothing_for == 10) break;
		}
	}
	return 0;
}