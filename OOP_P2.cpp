#include <iostream>
using namespace std;



class Card
{
    static string data_curenta;
    string nrCard, NumeDetinator, data_expirare;
    int CVV;
    double credit;
    unsigned short int PIN;
public:

    Card(string nrCard="0000 0000 0000 0000", string NumeDetinator="none", string data_expirare="01.0001", int CVV=0, double credit=0):PIN(0)
    {
        this->nrCard=nrCard;
        this->NumeDetinator=NumeDetinator;
        this->data_expirare=data_expirare;
        this->CVV=CVV;
        this->credit=credit;
    }

    Card(const Card& card)
    {
        this->nrCard= card.nrCard;
        this->NumeDetinator= card.NumeDetinator;
        this->data_expirare= card.data_expirare;
        this->CVV= card.CVV;
        this->credit= card.credit;
    }



    string getDataExpirare() const
    {
        return this->data_expirare;
    }

    void setDataExpirare(string data)
    {
        this->data_expirare=data;
    }

    static bool setDataCurenta()
    {
        string data;
        string ch;
        bool ok, retry=1;
        while(1) //validez data
        {
            ok=1;
            cout<<"Cititi data curenta [ex: 04.2021, numarul anului <=9999] (implicit data este 01.0001): ";
            cin>>data;
            if(data.size()!=7) ok=0;

            if(ok)
            {
                for(int i=0; i<data.size(); i++)
                {
                    if(i==2 && data[i]!='.')
                    {
                        ok=0;
                        break;
                    }
                    else if(i!=2 && isdigit(data[i])==0)
                    {
                        ok=0;
                        break;
                    }
                }

                if(ok)
                {
                    ch=data.substr(0, 2);
                    if(stoi(ch)<1 || stoi(ch) > 12) ok=0;
                    ch=data.substr(3, 4);
                    if(stoi(ch)==0) ok=0;
                }
            }


            if(!ok)
            {
                cout<<"Data este invalida, incercati din nou [ 0 - NU | 1 - DA]: ";
                cin>>retry;
                if(retry==0) break;
            }
            else break;

        }

        if(ok)
        {
            data_curenta=data;
            cout<<"Data a fost modificata cu succes!\n";
        }
        else cout<<"Data nu a fost modificata.\n";

        return ok;
    }

    static string getDataCurenta()
    {
        return data_curenta;
    }

    void setPIN()
    {
        string val;
        bool ok = validare_PIN(); //securitate schimbare PIN
        bool retry=1;

        if(ok) while(1) //validez pinul nou
            {
                retry=1;
                cout<<"Introduceti pinul nou [PIN : XXXX]: ";
                cin>>val;
                if(val.size()!=4)
                {
                    ok=0;
                    cout<<"PIN invalid, incercati din nou? [ 0 - NU | 1 - DA ]: ";
                    cin>>retry;
                    if(retry == 0) break;
                }
                else
                {
                    ok=1;
                    this->PIN=stoi(val);
                    break;
                }

            }
        if(ok) cout<<"PIN-ul modificat cu succes!\n";
        else cout<<"PIN-ul nu a fost modificat cu succes.\n";
    }

    string getPIN() const
    {
        string pin;
        if(this->PIN<=9) pin = "000" + to_string(this->PIN);
        else if(this->PIN<=99) pin = "00" + to_string(this->PIN);
        else if(this->PIN<=999) pin = "0" + to_string(this->PIN);
        else pin = to_string(this->PIN);
        return pin;
    }

    void setCredit(double credit)
    {
        this->credit=credit;
    }

    double getCredit() const
    {
        return this->credit;
    }

    Card& operator=(const Card& card)
    {
        if(this!=&card)
        {
            this->nrCard= card.nrCard;
            this->NumeDetinator= card.NumeDetinator;
            this->data_expirare= card.data_expirare;
            this->CVV= card.CVV;
            this->credit= card.credit;
        }

        return *this;
    }

    virtual ostream& AfisareVirtuala(ostream& out) const
    {
        string dumCVV = to_string(this->CVV);
        while(dumCVV.size()<3) dumCVV = "0" + dumCVV;


        out<<"Numar card: "<<this->nrCard<<"\n";
        out<<"Nume Detinator: "<<this->NumeDetinator<<"\n";
        out<<"Data expirare: "<<this->data_expirare<<"\n";
        out<<"CVV: "<<dumCVV<<"\n";
        out<<"Credit: "<<this->credit<<"\n";
        return out;
    }
    virtual istream& CitireVirtuala (istream& in)
    {
        string numere, dumNrCard;
        bool retry=1;
        bool ok;
        while(1) //validez numarul cardului, acesta trebuie sa fie de forma xxxx xxxx xxxx xxxx
        {
            ok=1;
            cout<<"Numar card [ex: 5241 7267 1998 8546]: ";

            for(int i=1; i<=4; i++)
            {
                cin>>numere;
                if(numere.size()!=4) ok=0;
                dumNrCard += numere + " ";
            }
            if(!ok)
            {
                cout<<"Numar card invalid, incercati din nou? [ 0 - NU | 1 - DA ]: ";
                cin>>retry;
                if(!retry) break;
            }
            else
            {
                this->nrCard=dumNrCard;
                break;
            }
        }

        in.ignore();
        cout<<"Nume Detinator: ";
        getline(in, this->NumeDetinator);
        cout<<"Data expirare [MM.YYYY ex: 04.2021]: ";
        getline(in, this->data_expirare);

        int dumCVV;
        ok=1;
        retry=1;
        while(1) //validez CVV
        {
            cout<<"CVV [adaugati un numar de 3 cifre ex: 000]: ";
            cin>>dumCVV;
            if(dumCVV>999)
            {
                cout<<"CVV invalid! incercati din nou? [ 0 - NU | 1 - DA ]: ";
                cin>>retry;
                if(!retry)
                {
                    ok=0;
                    break;
                }
            }
            else
            {
                ok=1;
                break;
            }
        }
        if(ok) this->CVV=dumCVV;
        cout<<"Credit: ";
        in>>this->credit;
        return in;
    }


    friend ostream& operator<<(ostream& out, const Card& card)
    {
        return card.AfisareVirtuala(out);
    }
    friend istream& operator>>(istream& in, Card& card)
    {
        return card.CitireVirtuala(in);

    }

    bool validare_PIN() const
    {
        string val;
        bool ok;
        bool retry=1;
        while(1)
        {

            cout<<"Introduceti PIN-ul pentru a efectua aceasta actiune (PIN implicit: 0000) [PIN : XXXX]: ";
            cin>>val;

            if(stoi(val)!=this->PIN || val.size()!=4)
            {
                ok=0;
                cout<<"PIN invalid, incercati din nou? [ 0 - NU | 1 - DA ]: ";
                cin>>retry;
                if(retry == 0) break;

            }
            else
            {
                ok=1;
                break;
            }
        }

        return ok;
    }

    bool validare_data() const //functie folosita pentru a verifica daca cardul este expirat sau nu
    {
        string dum1, dum2;
        dum1 = this->data_expirare.substr(3, 4) + "." + this->data_expirare.substr(0, 2);
        dum2 = data_curenta.substr(3, 4) + "." + data_curenta.substr(0, 2);

        if(dum1.compare(dum2)!=-1) return 1;
        else cout<<"Card expirat.\n";
        return 0;
    }

    virtual double extragere_bani()
    {
        double suma=0, dumsuma;
        bool ok = validare_data(); //verific daca cardul nu este expirat
        if(ok)
        {
            ok=validare_PIN(); //clientul trebuie sa si introduca pinul
            if(ok)
            {
                bool retry = 1;
                while(1) //suma extrasa trebuie sa fie mai mica sau egala cu creditul de pe card
                {
                    cout<<"Introduceti suma pe care doriti sa o extrageti [ suma <= "<<this->credit<<" ]: ";
                    cin>>dumsuma;
                    if(dumsuma>this->credit)
                    {
                        ok=0;
                        cout<<"Suma invalida, doriti sa incercati iar? [ 0 - NU | 1 - DA ]: ";
                        cin>>retry;
                        if(retry==0) break;
                    }
                    else
                    {
                        ok=1;
                        break;
                    }
                }
            }

        }
        if(ok) suma = dumsuma;
        this->credit-=suma; //daca clientul a introdus o suma corecta, suma o sa fie diferita de 0 si voi extrage aceasta suma din credit

        return suma; //returnez suma extrasa, 0 in cazul in care suma nu este valida

    }

    virtual ~Card()
    {
        this->nrCard="";
        this->NumeDetinator="";
        this->data_expirare="";
        this->CVV=0;
        this->credit=0;
    }
};

string Card::data_curenta = "01.0001"; //data curenta este aceeasi pentru toate cardurile

class Card_standard : public Card
{
    int limitaExtragere;
    double comisionDepasireLimita;
public:
    Card_standard(string nrCard="0000 0000 0000 0000", string NumeDetinator="none",
                  string data_expirare="01.0001", int CVV=0, double credit=0,
                  int limitaExtragere=0, double comisionDepasireLimita=0) :
        Card(nrCard, NumeDetinator, data_expirare, CVV, credit)
    {
        this->limitaExtragere=limitaExtragere;
        this->comisionDepasireLimita=comisionDepasireLimita;
    }

    Card_standard(const Card_standard& card):Card(card)
    {
        this->limitaExtragere=card.limitaExtragere;
        this->comisionDepasireLimita=card.comisionDepasireLimita;
    }

    int getLimitaExtragere() const
    {
        return this->limitaExtragere;
    }

    void setLimitaExtragere(int x)
    {
        this->limitaExtragere=x;
    }

    double getComisionDepasireLimita() const
    {
        return this->comisionDepasireLimita;
    }

    void setComisionDepasireLimita(double x)
    {
        this->comisionDepasireLimita=x;
    }

    Card_standard& operator=(const Card_standard& card)
    {
        if(this!=&card)
        {
            Card::operator=(card);
            this->limitaExtragere=card.limitaExtragere;
            this->comisionDepasireLimita=card.comisionDepasireLimita;
        }

        return *this;
    }

    ostream& AfisareVirtuala(ostream& out) const
    {
        Card::AfisareVirtuala(out);
        out<<"Limita Extragere: "<<this->limitaExtragere<<"\n";
        out<<"Comision Depasire Limita: "<<this->comisionDepasireLimita<<"\n";
        return out;
    }
    istream& CitireVirtuala (istream& in)
    {
        Card::CitireVirtuala(in);
        cout<<"Limita Extragere: ";
        in>>this->limitaExtragere;
        cout<<"Comision Depasire Limita [X% tastati fara \'%\']: ";
        double x;
        cin>>x;
        this->comisionDepasireLimita = x/100;

        return in;
    }


    double extragere_bani()
    {
        bool ok=1;
        double suma = Card::extragere_bani(); //folosesc functia virtuala din clasa Card pentru a extrage o suma valida
        double rest = 0;
        double credit = getCredit();
        if(suma > this->limitaExtragere) //verific daca suma extrasa este mai mare decat limita de extragere,
        {                                //si ofer consumatorului posibilitatea de a continua extractia sau nu
            rest = suma-limitaExtragere;
            cout<<"Suma pe care doriti sa o extrageti este mai mare decat limita de extragere ( "<<suma<<" > "<<this->limitaExtragere
                <<" ), doriti sa continuati? [ 0 - NU | 1 - DA ]: ";
            cin>>ok;

        }

        if(ok)
        {
            rest*=this->comisionDepasireLimita;

            if(rest>credit)//daca creditul nu e suficient pentru a plati comisionul, o sa extrag din bani pe care consumatorul ii primeste in mana
            {
                rest-=credit;
                setCredit(0);
                suma-=rest;
            }
            else setCredit(credit-=rest);//altfel o sa platesc comisionul direct din credit
            return suma;
        }
        else//daca consumatorul anuleaza extractia suma de bani extrasa in clasa Card este pusa inapoi in credit
        {
            setCredit(credit+suma);
            return 0;
        }



    }


    ~Card_standard()
    {
        this->limitaExtragere=0;
        this->comisionDepasireLimita=0;
    }
};


class Card_premium : public Card_standard
{
    double cashback;
public:

    Card_premium(string nrCard="0000 0000 0000 0000", string NumeDetinator="none",
                 string data_expirare="01.0001", int CVV=0, double credit=0,
                 int limitaExtragere=0, double comisionDepasireLimita=0, double cashback=0) :
        Card_standard(nrCard, NumeDetinator, data_expirare, CVV, credit, limitaExtragere, comisionDepasireLimita)
    {
        this->cashback=cashback;
    }

    Card_premium(const Card_premium& card):Card_standard(card)
    {
        this->cashback=card.cashback;
    }

    Card_premium& operator=(const Card_premium& card)
    {
        if(this!=&card)
        {
            Card_standard::operator=(card);
            this->cashback=card.cashback;
        }

        return *this;
    }

    double getCashback() const
    {
        return this->cashback;
    }

    void setCashback(double x)
    {
        this->cashback=x;
    }

    ostream& AfisareVirtuala(ostream& out) const
    {
        Card_standard::AfisareVirtuala(out);
        out<<"Cashback: "<<this->cashback<<"\n";
        return out;
    }
    istream& CitireVirtuala (istream& in)
    {
        Card_standard::CitireVirtuala(in);
        cout<<"Cashback [X% tastati fara \'%\']: ";
        double x;
        cin>>x;
        this->cashback = x/100;
        return in;
    }

    double extragere_bani()
    {
        bool ok=1;
        double suma = Card::extragere_bani(); //apelez extragere_bani din clasa Card, si suma primeste o valoare valida
        double rest = 0;
        double giveback = 0;
        double credit = getCredit();



        if(suma > getLimitaExtragere())//verific daca suma extrasa este mai mare decat limita de extragere,
        {                              //si ofer consumatorului posibilitatea de a continua extractia sau nu
            rest = suma-getLimitaExtragere();
            cout<<"Suma pe care doriti sa o extrageti este mai mare decat limita de extragere ( "<<suma<<" > "<<getLimitaExtragere()
                <<" ), doriti sa continuati? [ 0 - NU | 1 - DA ]: ";
            cin>>ok;
        }

        if(ok)
        {
            giveback = suma*(this->cashback); //aplic cashback-ul
            setCredit(giveback+credit);
            credit=getCredit();
            rest*=getComisionDepasireLimita();

            if(rest>credit)//daca creditul nu e suficient pentru a plati comisionul, o sa extrag din bani pe care consumatorul ii primeste in mana
            {
                rest-=credit;
                setCredit(0);
                suma-=rest;
            }
            else setCredit(credit-=rest);//altfel o sa platesc comisionul direct din credit
            return suma;
        }
        else //daca consumatorul anuleaza extractia suma de bani extrasa in clasa Card este pusa inapoi in credit
        {
            setCredit(credit+suma);
            return 0;
        }


    }

    ~Card_premium()
    {
        this->cashback=0;
    }


};


int main()
{
    Card ** carduri;

    int n;
    cout<<"Introduceti numarul de carduri: ";
    cin>>n;

    if(n>0)
    {
        carduri = new Card*[n];

        for(int i=0; i<n; i++)
            carduri[i]=NULL;
        Card::setDataCurenta();

        bool k=1;
        int comanda;
        while(k==1)
        {
            cout<<"\nPentru a citi un card apasati tasta 1\n";
            cout<<"Pentru a afisa un card apasati tasta 2\n";
            cout<<"Pentru a afisa toate cardurile apasati tasta 3\n";
            cout<<"Pentru a sterge un card apasati tasta 4\n";
            cout<<"Pentru a sterge toate cardurile apasati tasta 5\n";
            cout<<"Pentru a extrage bani de pe un card apasati tasta 6\n";
            cout<<"Pentru a schimba pinul unui card apasati tasta 7\n";
            cout<<"Pentru a afisa pinul unui card apasati tasta 8 (scop ajutator pentru acest program)\n";
            cout<<"Pentru a afisa toate pinurile apasati tasta 9 (scop ajutator pentru acest program)\n";
            cout<<"Pentru a afisa data curenta apasati tasta 10\n";
            cout<<"Pentru a schimba data curenta apasati tasta 11 (scopul este de a simula)\n";
            cout<<"Pentru STOP apasati tasta 12\n";

            cout<<"comanda: ";
            cin>>comanda;
            cout<<"\n";

            switch(comanda)
            {
            case 1:
            {
                int ok;
                int i;
                while(1)
                {
                    cout<<"Selectati numarul cardul pentru care doriti sa efectuati aceasta actiune [0 <= nr <= "<<n-1<<"]: ";
                    cin>>i;
                    if(i>=n || i<0)
                    {
                        cout<<"Numar invalid, doriti sa incercati iar? [ 0 - NU | 1 - DA ]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else
                    {
                        ok=1;
                        break;
                    }
                }
                if(!ok) break;

                int x;
                while(1)
                {
                    cout<<"Apasati tasta 1 daca doriti sa cititi un card standard\n";
                    cout<<"Apasati tasta 2 daca doriti sa cititi un card premium\n";
                    cout<<"Tasta: ";
                    cin>>x;
                    if(x==1 || x == 2)
                    {
                        ok=1;
                        break;
                    }
                    else
                    {
                        cout<<"Tasta apasata este invalida, doriti sa incercati iar? [ 0 - NU | 1 - DA ]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                }

                if(!ok) break;

                if(x==1)
                {
                    if(carduri[i]!=NULL)
                    {
                        delete carduri[i];
                        carduri[i]=NULL;
                    }
                    carduri[i] = new Card_standard();
                    cin>>*(carduri[i]);
                    cout<<"\n";
                }
                else
                {
                    if(carduri[i]!=NULL)
                    {
                        delete carduri[i];
                        carduri[i]=NULL;
                    }
                    carduri[i] = new Card_premium();
                    cin>>*(carduri[i]);
                    cout<<"\n";
                }


                cout<<"Doriti sa introduceti un cod PIN pentru acest card? Daca selectati NU pinul cardului va ramane implicit 0000. [ 0 - NU | 1 - DA]: ";
                cin>>ok;
                if(ok) (*carduri[i]).setPIN();

                break;
            }

            case 2:
            {
                int ok;
                int i;
                while(1)
                {
                    cout<<"Selectati numarul cardul pentru care doriti sa efectuati aceasta actiune [0 <= nr <= "<<n-1<<"]: ";
                    cin>>i;
                    if(i>=n || i<0)
                    {
                        cout<<"Numar invalid, doriti sa incercati iar? [ 0 - NU | 1 - DA ]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else
                    {
                        ok=1;
                        break;
                    }
                }
                if(!ok) break;

                if(carduri[i] != NULL) cout<<"Cardul cu numarul "<<i<<" :\n"<<*carduri[i];
                else cout<<"Cardul cu numarul "<<i<<" nu exista!\n";

                break;
            }

            case 3:
            {
                for(int i=0; i<n; i++)
                    if(carduri[i] != NULL) cout<<"Cardul cu numarul "<<i<<" :\n"<<*carduri[i]<<"\n";
                    else cout<<"Cardul cu numarul "<<i<<" nu exista!\n\n";

                break;
            }

            case 4:
            {
                int ok;
                int i;
                while(1)
                {
                    cout<<"Selectati numarul cardul pentru care doriti sa efectuati aceasta actiune [0 <= nr <= "<<n-1<<"]: ";
                    cin>>i;
                    if(i>=n || i<0)
                    {
                        cout<<"Numar invalid, doriti sa incercati iar? [ 0 - NU | 1 - DA ]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else
                    {
                        ok=1;
                        break;
                    }
                }
                if(!ok) break;

                if(carduri[i]!=NULL)
                {
                    delete carduri[i];
                    carduri[i]=NULL;

                    cout<<"Card sters cu succes!\n";
                }
                else cout<<"Cardul este deja sters!\n";

                break;
            }

            case 5:
            {
                for(int i=0; i<n; i++)
                    if(carduri[i]!=NULL)
                    {
                        delete carduri[i];
                        carduri[i]=NULL;
                    }

                cout<<"Cardurile au fost sterse cu succes!\n";

                break;
            }

            case 6:
            {
                int ok;
                int i;
                while(1)
                {
                    cout<<"Selectati numarul cardul pentru care doriti sa efectuati aceasta actiune [0 <= nr <= "<<n-1<<"]: ";
                    cin>>i;
                    if(i>=n || i<0)
                    {
                        cout<<"Numar invalid, doriti sa incercati iar? [ 0 - NU | 1 - DA ]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else
                    {
                        ok=1;
                        break;
                    }
                }
                if(!ok) break;


                if(carduri[i]==NULL) cout<<"Cardul cu numarul "<<i<<" nu exista!\n";
                else
                {

                    double suma = carduri[i]->extragere_bani();

                    cout<<"Suma extrasa este "<<suma<<"\nCreditul ramas este: "<< (*carduri[i]).getCredit()<<"\n";
                }

                break;
            }

            case 7:
            {
                int ok;
                int i;
                while(1)
                {
                    cout<<"Selectati numarul cardul pentru care doriti sa efectuati aceasta actiune [0 <= nr <= "<<n-1<<"]: ";
                    cin>>i;
                    if(i>=n || i<0)
                    {
                        cout<<"Numar invalid, doriti sa incercati iar? [ 0 - NU | 1 - DA ]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else
                    {
                        ok=1;
                        break;
                    }
                }
                if(!ok) break;

                if(carduri[i]!=NULL) (*carduri[i]).setPIN();
                else cout<<"Cardul cu numarul "<<i<<" nu exista!\n";

                break;
            }
            case 8:
            {
                int ok;
                int i;
                while(1)
                {
                    cout<<"Selectati numarul cardul pentru care doriti sa efectuati aceasta actiune [0 <= nr <= "<<n-1<<"]: ";
                    cin>>i;
                    if(i>=n || i<0)
                    {
                        cout<<"Numar invalid, doriti sa incercati iar? [ 0 - NU | 1 - DA ]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else
                    {
                        ok=1;
                        break;
                    }
                }
                if(!ok) break;

                if(carduri[i]!=NULL) cout<<"Pinul cardului cu numarul "<<i<<" este "<<(*carduri[i]).getPIN()<<"\n";
                else cout<<"Cardul cu numarul "<<i<<" nu exista!\n";

                break;
            }
            case 9:
            {
                for(int i=0; i<n; i++)
                    if(carduri[i]!=NULL) cout<<"Pinul cardului cu numarul "<<i<<" este "<<(*carduri[i]).getPIN()<<"\n";
                    else cout<<"Cardul cu numarul "<<i<<" nu exista!\n";

                break;
            }
            case 10:
            {
                cout<<"Data curenta este: "<<Card::getDataCurenta()<<"\n";

                break;

            }
            case 11:
            {
                Card::setDataCurenta();
                break;
            }
            case 12:
            {
                k=0;
                break;
            }
            default:
            {
                cout<<"Comanda incorecta!\n";
                break;
            }
            }

        }
        for(int i=0; i<n; i++)
            delete carduri[i];
        delete[] carduri;
    }
}
