#include <iostream>
using namespace std;

/*
* Scriere votanti: adaugarea de voturi de la tastatura, atatea cate dam input de la tastatura(nrVoturi).
*/
int scriereVotanti(int votanti[100], int nrVoturi = 0)
{
	cin >> nrVoturi;
	for (int i = 0;i < nrVoturi;i++)
	{
		cin >> votanti[i];
	}
	return nrVoturi;
}
/*
* Afisare votanti: afisarea listei de voturi la consola.
*/
void afisareVotanti(int votanti[100], int nrVoturi)
{
	for (int i = 0;i < nrVoturi;i++)
	{
		cout << "Vontantul[" << i << "]=" << votanti[i] << endl;
	}
}
/*
* Adaugare vot: adauga un vot in lista.
*/
int adaugareVot(int vot, int votanti[100], int nrVoturi)
{
	votanti[nrVoturi] = vot;
	nrVoturi++;
	return nrVoturi;
}
/*
* Verificare vot: verifica daca un vot este valid.
*/
bool verificareVot(int vot)
{
	if (vot <= 5 && vot >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
* Votare: cere utilizatorului sa voteze de la tastatura. Odata votat, votul este adaugat in lista cu validare.
*/
int votare(int votanti[100], int nrVoturi)
{
	cout << "Vot: ";
	int vot;
	cin >> vot;
	if (verificareVot(vot))
	{
		nrVoturi = adaugareVot(vot, votanti, nrVoturi);
	}
	else
	{
		vot = 0;
		nrVoturi = adaugareVot(vot, votanti, nrVoturi);
	}
	return nrVoturi;
}
/*
* Numarare voturi: numara cate voturi are un anumit partid dat de la tastatura.
*/
int numarareVoturi(int votanti[100], int nrVoturi, int partid)
{
	int nrVoturiPartid = 0;
	for (int i = 0;i < nrVoturi;i++)
	{
		if (votanti[i] == partid)
		{
			nrVoturiPartid++;
		}
	}
	return nrVoturiPartid;

}
int realizareClasament(int votanti[100], int nrVoturi)
{
	int clasament = 0;
	int partid = 0;
	clasament = numarareVoturi(votanti, nrVoturi, partid);
	return clasament;
}
/*
* Numarare voturi invalide: numara cate voturi sunt invalide.
*/
int numarareVoturiInvalide(int votanti[100], int nrVoturi)
{
	//Este echivalent cu apelarea functiei numarareVoturi, doar ca facem numarare de voturi pentru 0.
	/*int nrVoturiInvalide = 0;
	for (int i = 0;i < nrVoturi;i++)
	{
		if (votanti[i] == 0)
		{
			nrVoturiInvalide++;
		}
	}
	return nrVoturiInvalide;*/

	int nrVoturiInvalide;
	nrVoturiInvalide = numarareVoturi(votanti, nrVoturi, 0);
	return nrVoturiInvalide;
}
/*
* Anuntare castigator: returneaza castigatorul votarii.
*/
int anuntareCastigator(int votanti[100], int nrVoturi)
{
	int nrVoturiPartid1;
	nrVoturiPartid1 = numarareVoturi(votanti, nrVoturi, 1);
	int nrVoturiPartid2;
	nrVoturiPartid2 = numarareVoturi(votanti, nrVoturi, 2);
	int nrVoturiPartid3;
	nrVoturiPartid3 = numarareVoturi(votanti, nrVoturi, 3);
	int nrVoturiPartid4;
	nrVoturiPartid4 = numarareVoturi(votanti, nrVoturi, 4);
	int nrVoturiPartid5;
	nrVoturiPartid5 = numarareVoturi(votanti, nrVoturi, 5);
	int nrVoturiCastigatoare = nrVoturiPartid1;
	int partidulCastigator = 1;
	if (nrVoturiPartid2>nrVoturiCastigatoare)
	{
		nrVoturiCastigatoare = nrVoturiPartid2;
		partidulCastigator = 2;
	}
	if (nrVoturiPartid3 > nrVoturiCastigatoare)
	{
		nrVoturiCastigatoare = nrVoturiPartid3;
		partidulCastigator = 3;
	}
	if (nrVoturiPartid4 > nrVoturiCastigatoare)
	{
		nrVoturiCastigatoare = nrVoturiPartid4;
		partidulCastigator = 4;
	}
	if (nrVoturiPartid5 > nrVoturiCastigatoare)
	{
		nrVoturiCastigatoare = nrVoturiPartid5;
		partidulCastigator = 5;
	}
	return partidulCastigator;
}
/*
* Validare intreg vot: verifica daca numarul de voturi este cel putin 50% din populatia totala.
*/
bool validareIntregVot(int nrVoturi, int populatiaTotala)
{
	if (nrVoturi >= populatiaTotala / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void main()
{
	int votanti[100];
	int nrVoturi = 0;
	int comanda;
	int populatiaTotala;
	cout << "Populatia totala este";
	cin >> populatiaTotala;
	while (true)
	{
		cout << "Comanda" << endl;
		cin >> comanda;
		switch (comanda)
		{
		case(1):
			afisareVotanti(votanti, nrVoturi);
			break;
		case(2):
			nrVoturi = votare(votanti, nrVoturi);
			break;
		case(3):
			int partid;
			cout << "Care este partidul?";
			cin >> partid;
			int nrVoturiPartid; 
			nrVoturiPartid = numarareVoturi(votanti, nrVoturi, partid);
			cout << "Partidul " << partid << " are urmatorul numar de voturi " << nrVoturiPartid << endl;
			break;
		case(4):
			int nrVoturiInvalide;
			nrVoturiInvalide = numarareVoturiInvalide(votanti, nrVoturi);
			cout << "Numarul de voturi invalide este " << nrVoturiInvalide << endl;
			break;
		case(5):
			int partidulCastigator;
			partidulCastigator = anuntareCastigator(votanti, nrVoturi);
			cout << "Partidul castigator este " << partidulCastigator << endl;
			break;
		case(6):
			if (validareIntregVot(nrVoturi, populatiaTotala))
			{
				cout << "Intregul vot este valid" << endl;
			}
			else
			{
				cout << "Teapa" << endl;
			}
			break;
		case(7):
			int clasament;
			clasament = realizareClasament(votanti, nrVoturi);
			cout << "Clasamentul este: " << clasament << endl;
			break;
		}
	}






















}