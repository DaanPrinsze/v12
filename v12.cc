AA//Programmeermethoden 2016 - opgave 1: IQ-test
//Door Daan Prinsze (s1910043) en Tim Weijers (s1887542)
//Beiden eerstejaars wiskunde
//Docent: dr. W.A. Kosters
//Programma geschreven in gedit 3.18.3 op Ubuntu 16.04 LTS
//Programma gecompileerd met g++ (standaardversie van Ubuntu 16.04)
//Programma geschreven van maandag 12 - zaterdag 17 september
//mailadres: wjstim@gmail.com of (daanprinsze@gmail.com)

#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	srand ( time (NULL) );                    //intitialiseert randomgeneratoor

	const int pJ = 2016, pM = 9, pD = 23;     //peildatum
	int       gJ, gM, gD;	                  //geboortedatum
	const int minJr = 10, maxJr = 100;		  //minimale en maximale leeftijd
	int       maxLeeftijdMens = (pJ-2016+116);//maximaal mogelijke leeftijd van een levend mens (in 2016 = 116)
	                                          //een levend mens in (2016=116)

	string maandNaam [13] {"index", "januari", "februari", "maart", "april",
                           "mei", "juni", "juli", "augustus", "september",
                         "oktober", "november", "december"};

	cout << string(100, '\n') //scherm leegmaken, betrouwbaarder dan system(clr)
			 << string (60, '=') << endl << end //dubble lijn

			 << " Programmeermethoden 2016 - opgave 1: IQ-test \n"

			 << string (60, '_') << endl 	    //enkele lijn

			 << "\n     Gemaakt op 17-9-2016 door:		\n\n"
			 << "Daan Prinsze\t & \tTim Weijers	\n"
			 << "s1910043  \t   \ts1877542 		\n"
			 << "Wiskunde   \t   \tWiskunde			\n\n"
			 << "Docent: dr. W.A. Kosters				\n"

			 << string (60, '=') << endl << endl << endl // dubbele lijn

			 << "Welkom bij de IQ-test!\n"
			 << "Om de test af te mogen nemen moeten eerst een aantal vragen\n"
			 << "over uw geboortedatum beantwoord worden.\n\n"
			 << "Druk op Enter om te beginnen.\n";
	cin.ignore(100, '\n');//verwijdert de Enter,(of een ander input) uit de stream

	cout << "Voer geboortejaar in (formaat: jjjj) en druk op ENTER.\n";
	cin >> gJ;
		if (gJ<0)
		{
			cout << "Invoer ongeldig!\n"
					 << "Leeftijd moet een positief getal zijn!\n";
			return 1;
		}
		else if (gJ>pJ)
		{
			cout << "Invoer ongeldig!\n"
					 << "Geboortejaar ligt in de toekomst.\n";
			return 1;
		}
		else if (pJ-gJ>maxLeeftijdMens)
		{
			cout << "Invoer ongeldig!\n"
					 << "In het jaar " << pJ << "kan een mens niet ouder dan "
			 	   << maxLeeftijdMens << " zijn. \n";
			return 1;
    }
		else if (pJ-gJ<minJr)
		{
			cout << "Te jong voor dit programma!";
			return 1;
		}
		else if (pJ-gJ>(maxJr+1))
		{
			cout << "Te oud voor dit programma!";
			return 1;
		}


	cout << "Voer geboortemaand in (formaat: mm) en druk op ENTER.\n";
	cin >> gM;
  	if (gM<=0 || gM>12)
  	{
    	cout << "Invoer ongeldig!\n"
           << "Voer een positieve integer met 1<=n<=12 in!\n";
      return 1;
    }
		else if (pJ-gJ==minJr && pM<gM)
		{
			cout << "Te jong voor dit programma!";
			return 1;
		}
		else if (pJ-gJ==maxJr && pM>gM)
		{
			cout << "Te oud voor dit programma!";
			return 1;
		}

bool sJBoolG = (gJ%4==0 && (gJ%100!=0 || gJ%400==0));														//sJBoolG==1 als geboortejaar is schrikkeljaar
int maandLengteG [13] = {0,31,28,31,30,31,30,31,31,30,31,30,31 };
		maandLengteG [2] += sJBoolG;                                                //als geboortejaar is schrikkeljaar, dan februari 29 dagen

	cout << "Voer geboortedag in (formaat:dd) en druk op ENTER.\n";
	cin >> gD;
  	if (gD > maandLengteG [gM])
    {
    	cout << "Invoer ongeldig!\n"
    			 << "De maand " << maandNaam [gM]
           << " heeft slechts " << maandLengteG [gM] << " dagen.\n";
      return 1;
    }
    else if (gD < 1)
    {
    	cout << "Invoer ongeldig!\n"
    			 << "De geboortedag moet een positief getal >=1 zijn!\n";
      return 1;
		}

  cout << string(100, '\n') << endl;

  bool reedsJarigGeweest (pM>gM || (pM==gM && pD>=gD));
  bool reedsMaandigGeweest (pD>gD);
  int	lJ, lM;			                                                            //leeftijd in jaren, maanden
	lJ = (pJ - gJ - 1 + reedsJarigGeweest);

  if (reedsJarigGeweest)
    	lM = (pJ - gJ) * 12 + (pM - gM) - 1 + reedsMaandigGeweest;
  else
    	lM = ((pJ - gJ) - 1) * 12 + ((12 - gM) + (pM - 1) + reedsMaandigGeweest);

	bool dertiger (lJ >= 30);
	string jijOfU [2] {"je", "u"};
	string psVnw  = jijOfU [dertiger]; //van persoonlijk voornaamwoord
	string jouwOfUw [2] {"jouw", "uw"};
	string bzVnw = jouwOfUw [dertiger]; //bezittelijk voornaamwoord

	if (pM==gM && pD==gD) //gebruiker is jarig
		cout <<"Hartelijk gefeliciteerd met " << bzVnw
             << " " << lJ << "-e verjaardag!\n\n";
	else if (pM!=gM && pD==gD) //gebruiker is maandig
		cout <<"Gefeliciteerd met "<< bzVnw << " maandig zijn!\n\n";

  cout << psVnw << " bent " << lJ << " jaar en " << lM - (12 * lJ)
    		 << " maanden oud, "<< lM << " maanden.\n\n";

	const int mndDag[13][13] = {{0,0,31,59,90,120,151,181,212,243,273,304,334},		//2-dimensionale array voor de dagen van 1/1/gJ tot 1/gM/gJ
															{0,0,31,60,91,121,152,182,213,244,274,305,335}};
	int dagenSinds; 								//Totaal dagen van 1/1/1900 tot gD/gM/gJ
	dagenSinds=(gJ-1900)*365 				//aantal dagen van 1/1/1900 tot 1/1/gJ
						+mndDag[sJBoolG][gM]	//aantal dagen van 1/1/gJ   tot 1/gM/gJ
						+(gD-1) 							//aantal dagen van 1/gM/gJ  tot gD/gM/gJ
						+((gJ-1900-1)/4);			//schrikkeldagen sinds 1900
							 										//let op! 1900 was GEEN schrikkeljaar! daarom -1
	cout << "Verstreken dagen sinds 1/1/1900 " << dagenSinds << endl;
	int modDag = dagenSinds%7; 			//geeft de restwaarde van dagenSinds/7
	cout << "modDag " << modDag << endl;
	string dagNaam [7] {"maandag", "dinsdag", "woensdag", "donderdag", "vrijdag",
											"zaterdag", "zondag"};

  	cout << "Geef de eerste letter van de dag van de week waarop "
  		 << psVnw << " geboren bent.\n";

  static char letter [2];	 	//een array waar de gebruiker de eerste 2 letters
  													//van de naam van zijn geboortedag input
  													//static geeft de waarde 0 aan de chars in de array
	while (true)
  { 	//loop net zolang tot letter een geldige input heeft
  	cin >> letter [0];
  		if (letter [0]=='z' || letter [0]=='d')
  		{
  			{
  		cout << "geef de tweede letter\n";
  		cin >> letter [1];
  		}
  			if (letter [1] =='o' || letter [1] =='a' || letter [1] == 'i')
  				break; 	//stop loop zodra geldige input
  			else cout << "Invoer ongeldig! Probeer het opnieuw.\n"
  								<< "Geef de eerste letter\n";
  			}
  		else if (letter [0]=='m' || letter [0]=='w' || letter [0]=='v')
  			break;	//stop loop zodra geldige input
  		else
  		{
  		cout << "Invoer ongeldig! Probeer het opnieuw.\n"
  							<< "Geef de eerste letter\n";
  		cin.clear(); 	//reset de error flags in de stream
			cin.ignore(10000, '\n'); 	//verwijder 10000 characters uit de stream
  		}
  	}

 int wkDag = letter[0]+letter[1]; //maak van de 2 letter inputs een int-waarde
 int wkNmr; //maakt van de letter-input intwaarde een getal van 0 tot 6
	if (wkDag == 109) wkNmr = 0; //maakt gebruik van numerieke waarde van de ASCI
	else if (wkDag == 205) wkNmr = 1;	//karakters m, d, w, v, z, i, a, o
	else if (wkDag == 119) wkNmr = 2;
	else if (wkDag == 211) wkNmr = 3;
	else if (wkDag == 118) wkNmr = 4;
	else if (wkDag == 219) wkNmr = 5;
	else if (wkDag == 233) wkNmr = 6;

	cout << string(100, '\n');

	if (wkNmr == modDag)
	{
		cout << "Correct! \nOm de IQ-test te beginnen druk ENTER\n";
		cout << string (60, '>') << endl;
	}
 else
	{
  cout <<"Fout!" << endl << bzVnw << " geboortedag viel op een "
  		 << dagNaam [modDag] << endl << endl;
  		 return 1;
	}

	srand ( time (NULL) );

	int getalA = rand () % 10000;
	int getalB = rand () % 10000;
	int getalTienProcent = rand () % 10;
	if (getalTienProcent == 0) getalA = getalTienProcent;

	int getalAntwoord = (getalA*getalB);
	int getalUser;

	char karel, tolstoy;

	cout << string (60, '>') << endl;

	cout << "Vraag 1:\nWat is het product van "<< getalA
			 << " en " << getalB << "?\n";
	cin >> getalUser;
	cout << getalA << " * "<< getalB << " = "<< getalAntwoord;

	if (getalAntwoord==getalUser)
	{
		cout <<"\n\n Correct! " << psVnw << " wordt toegelaten tot een beta-studie!";
		return 0;
	}
	else
	{
		cout << "\n\nFout! Niet getreurd, " << psVnw << "gaat door voor een\n"
         << "plek bij een alfa-studie.\n"
	  		 << string (60, '.');
	}

		if (dertiger)
	  {
	  	cout << "Wie schreef het toneelstuk Karel ende Elegast?\n"
	  		   << "\tA: Harry Mulisch\n"
	  		   << "\tB: Multatuli\n"
           << "\tC: Saskia Noort\n"
	  	  	 << "\tD: Onbekend\n";

	  	cin >> karel;
	  	if (karel=='D' || karel=='d')
	  	{
	  		cout << "Correct! Succes met " << bzVnw << "alfa-studie!!!\n\n\n\n";
	  		return 0;
	  	}
	  	else if (karel=='A'||karel=='B'||karel=='C'||karel=='a'||karel=='b'||karel=='c')
	  	{
	  		cout << "Fout! \n Helaas, " << psVnw
             << "wordt niet toegelaten aan de universiteit.\n"
             << "Succes met " << bzVnw << "cursus op het HBO!";
				return 0;
	  	}
		}

	  if (!(dertiger))
	  {
	  	cout << "Wie schreef het boek Oorlog en Vrede?"
	  			 << "\tA: Leo Tolstoy\n"
	  			 << "\tB: Fyodor Dostoyevski\n"
	  			 << "\tC: Vladimir Nabokov\n"
           << "\tD: Saskia Noort\n";

	  	cin >> tolstoy;
	  	if (tolstoy=='A' || tolstoy=='a')
	  	{
	  		cout << "Correct! Succes met "<< bzVnw << " alfa-studie!\n\n\n\n";
	  		return 0;
	  	}
	  	else if (tolstoy=='B'|| tolstoy=='C'|| tolstoy=='D' || tolstoy=='b'||
	  					 tolstoy=='c'|| tolstoy=='d')
	  	{
	  		cout << "Fout! \n Helaas, " << psVnw
             << " wordt niet toegelaten aan de universiteit.\n"
             <<"Succes met " << bzVnw << " cursus op het HBO!";
       	return 0;
	  	}
	  }
	return 0;
}
