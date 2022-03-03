#include <iostream>

using namespace std;

class Nod
{
    int info;
    Nod* next;
public:
    Nod()
    {
        this->info=0;
        this->next=this;
    }
    Nod(int info)
    {
        this->info=info;
        this->next=this;
    }
    Nod(int info, Nod* next)
    {
        this->info=info;
        this->next=next;
    }
    Nod(const Nod& nod)
    {
        this->info=nod.info;
        this->next=nod.next;
    }

    Nod* getnext()
    {
        return this->next;
    }
    int getinfo()
    {
        return this->info;
    }

    void setnext(Nod* next)
    {
        this->next=next;
    }

    void setinfo(int info)
    {
        this->info=info;
    }


    friend ostream& operator<<(ostream& out, const Nod& nd);

    Nod& operator=(const Nod& nod)
    {
        if(this!=&nod)
        {
            this->info = nod.info;
            this->next = nod.next;
        }
        return *this;
    }
    bool operator==(const Nod& nod) const
    {
        if(this->info==nod.info && this->next==nod.next)
            return true;
        return false;
    }

    ~Nod()
    {

    }
};

ostream& operator<<(ostream& out, const Nod& nd)
{
    out<<nd.info;
}




class Lista_circulara
{
    int lungime;
    Nod *prim;
public:
    Lista_circulara()
    {
        this->prim = NULL;
        this->lungime = 0;
    }

    Lista_circulara(int x)
    {
        this->lungime = 1;
        this->prim = new Nod(x);
    }

    Lista_circulara(const Lista_circulara& li)
    {
        this->lungime=0;
        this->prim = NULL;
        if(li.lungime>0)
        {
            this->lungime=li.lungime;
            Nod *nodnou, *nodcurent, *pred;
            nodcurent=li.prim;
            nodnou=new Nod(*nodcurent);
            pred=nodnou;
            this->prim=nodnou;
            while((*nodcurent).getnext()!=li.prim)
            {
                nodcurent=(*nodcurent).getnext();
                nodnou=new Nod(*nodcurent);
                (*pred).setnext(nodnou);
                pred=nodnou;
            }
            (*pred).setnext(this->prim);
        }
    }

    Lista_circulara operator+(const Lista_circulara& li) const
    {
        Lista_circulara aux1(*this), aux2(li);

        if(aux1.prim==NULL)
            return aux2;
        else if(aux2.prim==NULL)
            return aux1;

        else
        {
            Nod *nod=aux1.prim;
            while((*nod).getnext()!=aux1.prim)
                nod=(*nod).getnext();

            (*nod).setnext(aux2.prim);
            nod=aux2.prim;
            while((*nod).getnext()!=aux2.prim)
                nod=(*nod).getnext();

            (*nod).setnext(aux1.prim);
            aux1.lungime+=aux2.lungime;

            aux2.prim=NULL;
            aux2.lungime=0;

            return aux1;
        }
    }

    Lista_circulara& operator=(const Lista_circulara& li)
    {
        if(this != &li)
        {
            if(this->prim!=NULL)
            {
                Nod *nod, *urm;
                nod=this->prim;
                nod=(*nod).getnext();
                urm=(*nod).getnext();
                while(nod!=this->prim)
                {
                    delete nod;
                    nod=urm;
                    urm=(*nod).getnext();
                }
                delete nod;
                this->prim=NULL;
            }
            this->lungime=li.lungime;


            if(li.lungime>0)
            {
                Nod *nodnou, *nodcurent, *pred;
                nodcurent=li.prim;
                nodnou=new Nod(*nodcurent);
                pred=nodnou;
                this->prim=nodnou;
                while((*nodcurent).getnext()!=li.prim)
                {
                    nodcurent=(*nodcurent).getnext();
                    nodnou=new Nod(*nodcurent);
                    (*pred).setnext(nodnou);
                    pred=nodnou;
                }
                (*pred).setnext(this->prim);
            }

        }

        return *this;

    }


    friend ostream& operator<<(ostream& out, const Lista_circulara& li);
    friend istream& operator>>(istream& in, Lista_circulara& li);

    int getlen()
    {
        return this->lungime;
    }


    void add(int x, int k)
    {
        if(k == 0 && this->lungime == 0)
        {
            this->lungime = 1;
            this->prim = new Nod(x);
        }
        else if(k<=this->lungime && k>=0)
        {
            Nod *nod;
            nod = prim;
            for(int i=0; i<k-1; i++)
                nod = (*nod).getnext();

            if(k!=0)
            {
                Nod *nodnou = new Nod(x, (*nod).getnext());
                (*nod).setnext(nodnou);
            }
            if(k==0)
            {
                while((*nod).getnext()!=prim)
                    nod = (*nod).getnext();
                Nod *nodnou = new Nod(x, (*nod).getnext());
                (*nod).setnext(nodnou);
                this->prim=nodnou;
            }
            this->lungime++;
        }
        else cout<<"Eroare pozitia de inserare trebuie sa fie >= 0 si <= "<<this->lungime;
    }

    void del(int k)
    {
        if(k==0 && this->lungime == 1)
        {
            cout<<*prim<<" ";
            delete prim;
            this->prim = NULL;
            this->lungime=0;
        }
        else if(k<this->lungime && k>=0)
        {
            Nod *nod;
            nod = this->prim;
            for(int i=0; i<k-1; i++)
                nod = (*nod).getnext();
            if(k==0)
                while((*nod).getnext()!=prim)
                    nod = (*nod).getnext();

            Nod *nodurm = (*nod).getnext();
            (*nod).setnext((*nodurm).getnext());

            if(k==0) this->prim = (*nodurm).getnext();

            this->lungime--;

            cout<<*nodurm<<" ";
            delete nodurm;

        }
        else cout<<"Eroare pozitia de stergere trebuie sa fie >= 0 si <= "<<this->lungime-1<<"\n";
    }

    void inversare()
    {
        Nod *a,*b,*c;
        a=this->prim;
        b=this->prim;
        a=(*a).getnext();
        while(a!=this->prim)
        {
            c=(*a).getnext();
            (*a).setnext(b);
            b=a;
            a=c;
        }
        (*a).setnext(b);
    }

    void delink(int k)
    {
        int ind=0;
        while(this->prim!=NULL)
        {
            del(ind);
            if(this->lungime!=0)
            {
                ind=(ind+k)%this->lungime-1;
                if(ind<0) ind=this->lungime-1;
            }
        }
    }


    ~Lista_circulara()
    {
        if(this->prim!=NULL)
        {
            Nod *nod, *urm;
            nod=this->prim;
            nod=(*nod).getnext();
            urm=(*nod).getnext();
            while(nod!=this->prim)
            {
                delete nod;
                nod=urm;
                urm=(*nod).getnext();
            }
            delete nod;
            this->prim=NULL;
        }
        this->lungime=0;
    }

};

ostream& operator<<(ostream& out, const Lista_circulara& li)
{
    if(li.lungime==0) cout<<"Lista goala";
    else
    {
        Nod *nod = li.prim;
        do
        {
            out<<(*nod).getinfo()<<"->";
            nod = (*nod).getnext();
        }
        while(nod!=li.prim);
        out<<(*nod).getinfo();
    }
}

istream& operator>>(istream& in, Lista_circulara& li)
{

    if(li.prim!=NULL)
    {
        Nod *nod, *urm;
        nod=li.prim;
        nod=(*nod).getnext();
        urm=(*nod).getnext();
        while(nod!=li.prim)
        {
            delete nod;
            nod=urm;
            urm=(*nod).getnext();
        }
        delete nod;
        li.prim=NULL;
    }
    li.lungime=0;

    int x;
    cout<<"Numar noduri de inserat: ";
    cin>>x;
    for(int i=1; i<=x; i++)
    {
        int nod, poz;
        while(1)
        {
            int ok=0;
            cout<<"Nodul: ";
            cin>>nod;
            cout<<"Pozitia[0 <= nr <= "<<li.lungime<<"]: ";
            cin>>poz;
            li.add(nod,poz);
            if(poz>li.lungime || poz<0)
            {
                cout<<" [continua = 1 | renunta = 0]: ";
                cin>>ok;
            }
            if(ok==0) break;

        }

    }
}


int main()
{

    Lista_circulara *p;
    int n, k=1, j;
    cout<<"Numarul de liste circulare: ";
    cin>>n;

    if(n>0)
    {



        p=new Lista_circulara[n];

        while(k==1)
        {
            cout<<"\nApasa 1 pentru a citi o lista circulara\n";
            cout<<"Apasa 2 pentru a afisa o lista\n";
            cout<<"Apasa 3 pentru a copia o lista circulara in alta lista circulara\n";
            cout<<"Apasa 4 pentru a afisa toate listele circulare\n";
            cout<<"Apasa 5 pentru a adauga un nod pe o pozitie\n";
            cout<<"Apasa 6 pentru a sterge un nod de pe o pozitie\n";
            cout<<"Apasa 7 pentru a inversarea legaturile listei\n";
            cout<<"Apasa 8 pentru a goli o lista circulara\n";
            cout<<"Apasa 9 pentru a goli lista circula din k in k\n";
            cout<<"Apasa 10 pentru a goli toate listele circulare\n";
            cout<<"Apasa 11 pentru a aduna doua liste\n";
            cout<<"Apasa 12 pentru STOP\n";

            int comanda;
            cout<<"comanda: ";
            cin>>comanda;
            cout<<"\n";
            switch(comanda)
            {

            case 1:
            {
                int ok=1;
                while(1)
                {
                    cout<<"Selectati numarul listei pentru care doriti sa efectuati aceasta actiune[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j;
                    if(j<0 || j>n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;
                cout<<"Lista circulara cu numarul "<<j<<":\n";
                cin>>p[j];
                break;

            }

            case 2:
            {

                int ok=1;
                while(1)
                {
                    cout<<"Selectati numarul listei pentru care doriti sa efectuati aceasta actiune[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j;
                    if(j<0 || j>n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;
                cout<<"Lista circulara cu numarul "<<j<<": "<<p[j]<<"\n";
                break;
            }

            case 3:
            {
                int ok=1;
                while(1)
                {
                    cout<<"Selectati numarul listei pe care doriti sa o copiati[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j;
                    if(j<0 || j>n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;

                int j2;
                while(1)
                {
                    cout<<"Selectati numarul listei in care doriti sa copiati[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j2;
                    if(j2<0 || j2> n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;

                p[j2]=p[j];

                break;
            }

            case 4:
            {
                for(int i=0; i<n; i++)
                    cout<<"Lista cu numarul "<<i<<": "<<p[i]<<"\n";
                break;
            }

            case 5:
            {
                int ok=1;
                while(1)
                {
                    cout<<"Selectati numarul listei pentru care doriti sa efectuati aceasta actiune[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j;
                    if(j<0 || j>n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;

                int poz, infon;
                while(1)
                {
                    cout<<"Nodul: ";
                    cin>>infon;
                    cout<<"Selectati pozitia pe care doriti sa inserati [0 <= nr <= "<<p[j].getlen()<<"]: ";
                    cin>>poz;
                    if(poz<0 || poz>p[j].getlen())
                    {
                        cout<<"Pozitie invalida [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;
                p[j].add(infon, poz);

                break;
            }
            case 6:
            {
                int ok=1;
                while(1)
                {
                    cout<<"Selectati numarul listei pentru care doriti sa efectuati aceasta actiune[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j;
                    if(j<0 || j>n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;

                if(p[j].getlen()>0)
                {

                    int poz;
                    while(1)
                    {
                        cout<<"Selectati pozitia pe care doriti sa o stergeti [0 <= nr <= "<<p[j].getlen()-1<<"]: ";
                        cin>>poz;
                        if(poz<0 || poz>p[j].getlen()-1)
                        {
                            cout<<"Pozitie invalida [continua = 1 | renunta = 0]: ";
                            cin>>ok;
                            if(ok==0) break;
                        }
                        else break;
                    }
                    if(ok==0) break;

                    cout<<"Nod sters: ";
                    p[j].del(poz);
                    cout<<"\n";
                }
                else cout<<"Eroare, lista este goala\n";

                break;

            }
            case 7:
            {
                int ok=1;
                while(1)
                {
                    cout<<"Selectati numarul listei pentru care doriti sa efectuati aceasta actiune[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j;
                    if(j<0 || j>n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;

                if(p[j].getlen()>0) p[j].inversare();
                break;
            }

            case 8:
            {
                int ok=1;
                while(1)
                {
                    cout<<"Selectati numarul listei pentru care doriti sa efectuati aceasta actiune[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j;
                    if(j<0 || j>n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;

                Lista_circulara dum;
                p[j]=dum;

                break;
            }

            case 9:
            {
                int ok=1;
                while(1)
                {
                    cout<<"Selectati numarul listei pentru care doriti sa efectuati aceasta actiune[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j;
                    if(j<0 || j>n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;

                if(p[j].getlen()>0)
                {
                    int dk;
                    while(1)
                    {
                        cout<<"Selectati din cat in cat o sa fie stearsa lista [1 <= pas]: ";
                        cin>>dk;
                        if(dk<1)
                        {
                            cout<<"Eroare, numarul trebuie sa fie >= 1 [continua = 1 | renunta = 0]: ";
                            cin>>ok;
                            if(ok==0) break;
                        }
                        else break;

                    }
                    if(ok==0) break;

                    cout<<"Noduri eliminate: ";
                    p[j].delink(dk);
                    cout<<"\n";
                }
                else cout<<"Eroare, lista este goala\n";


                break;
            }

            case 10:
            {
                Lista_circulara dum;
                for(int i=0; i<n; i++)
                    p[i]=dum;

                cout<<"Liste golite cu succes\n";

                break;
            }

            case 11:
            {
                int ok=1;
                while(1)
                {
                    cout<<"Selectati numarul primei liste pentru care doriti sa efectuati aceasta actiune[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j;
                    if(j<0 || j>n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;

                int j2;
                while(1)
                {
                    cout<<"Selectati numarul celei de-a doua lista pentru care doriti sa efectuati aceasta actiune[0 <= nr <= "<<n-1<<"]: ";
                    cin>>j2;
                    if(j2<0 || j2>n-1)
                    {
                        cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;

                int ok1=0;
                while(1)
                {
                    cout<<"Doriti sa salvati aceasta adunare intr-o lista? [DA = 1 | NU = 0]: ";
                    cin>>ok1;
                    if(ok1!=0 && ok1!=1)
                    {
                        cout<<"Comanda nu exista [continu = 1 | renunta = 0]: ";
                        cin>>ok;
                        if(ok==0) break;
                    }
                    else break;
                }
                if(ok==0) break;

                Lista_circulara dum;
                dum = p[j] + p[j2];

                if(ok1==1)
                {
                    int j3;
                    while(1)
                    {
                        cout<<"Selectati numarul listei in care doriti sa copiati[0 <= nr <= "<<n-1<<"]: ";
                        cin>>j3;
                        if(j3<0 || j3> n-1)
                        {
                            cout<<"Numar lista invalid [continua = 1 | renunta = 0]: ";
                            cin>>ok1;
                            if(ok1==0) break;
                        }
                        else break;
                    }
                    if(ok1==1) p[j3] = dum;

                }

                cout<<"Lista "<<j<<" + Lista "<<j2<<" = "<<dum<<"\n";

                break;
            }

            case 12:
            {
                k=0;
                break;
            }

            default:
            {
                cout<<"Comanda incorecta\n";
                break;
            }
            }
        }

        delete[] p;
    }

    return 0;
}
