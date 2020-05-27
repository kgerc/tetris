#include "klocek.h"
int KlocekTemplate[7/*rodzaj*/][4/*rotacja*/][5/*pionowy bok*/][5/*poziomy bok*/] =
{
	//Kwadrat
	{
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,0},
		{0,0,1,1,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,0},
		{0,0,1,1,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,0},
		{0,0,1,1,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,0},
		{0,0,1,1,0},
		{0,0,0,0,0}
		}
	},
	//litera I
	{
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,1,1,1,1},
		{0,0,0,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{1,1,1,1,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,0,0,0}
		}
	},
	//litera L
	{
		{
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,1,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,1,1,1,0},
		{0,1,0,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,1,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,0,1,0},
		{0,1,1,1,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
		}
	},
	//odbicie lustrzane litery L
	{
		{
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,1,1,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,1,0,0,0},
		{0,1,1,1,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,1,1,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,1,1,1,0},
		{0,0,0,1,0},
		{0,0,0,0,0}
		}
	},
	//litera N
	{
		{
		{0,0,0,0,0},
		{0,0,0,1,0},
		{0,0,1,1,0},
		{0,0,1,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,1,1,0,0},
		{0,0,1,1,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,1,1,0,0},
		{0,1,0,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,1,1,0,0},
		{0,0,1,1,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
		}
	},
	//odbicie lustrzane litery N
	{
		{
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,0,1,1,0},
		{0,0,0,1,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,0},
		{0,1,1,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,1,0,0,0},
		{0,1,1,0,0},
		{0,0,1,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,1,1,0},
		{0,1,1,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
		}
	},
	//litera T
	{
		{
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,0,1,1,0},
		{0,0,1,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,1,1,1,0},
		{0,0,1,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,1,1,0,0},
		{0,0,1,0,0},
		{0,0,0,0,0}
		},
		{
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,1,1,1,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
		}
	}
};
int PozycjaBlokuTemplate[7][4][2/*pozycja*/] =
{
	/* Kwadrat */
	{
	  {-2, 3},
	  {-2, 3},
	  {-2, 3},
	  {-2, 3}
	},
	/* I */
	  {
		{-2, 3},
		{-1, 3},
		{-2, 3},
		{0, 3}
	  },
	/* L */
  {
	{-1, 3},
	{-2, 3},
	{-1, 3},
	{-1, 3}
  },
	/* L odbicie */
  {
	{-1, 3},
	{-1, 3},
	{-1, 3},
	{-2, 3}
  },
	/* N */
  {
	{-1, 3},
	{-2, 3},
	{-1, 3},
	{-1, 3}
  },
	/* N odbicie */
  {
	{-1, 3},
	{-2, 3},
	{-1, 3},
	{-1, 3}
  },
	/* T */
  {
	{-1, 3},
	{-2, 3},
	{-1, 3},
	{-1, 3}
  },
};
int Klocek::TypKlocka(int rBlok, int rotacja, int pX, int pY)
{
	return KlocekTemplate[rBlok][rotacja][pX][pY];
}
int Klocek::PozycjaXInit(int rBlok, int rotacja)
{
	return PozycjaBlokuTemplate[rBlok][rotacja][0/*pozycja x*/];
}
int Klocek::PozycjaYInit(int rBlok, int rotacja)
{
	return PozycjaBlokuTemplate[rBlok][rotacja][1/*pozycja y*/];
}