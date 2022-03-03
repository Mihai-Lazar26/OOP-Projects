#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class OutOfBounds: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Out of bounds";
    }
} outOfBounds;


class Masina
{
protected:
    static int numarMasini;
    string culoare, marca, motor, roti, model;
    int topSpeed;
    int nrLocuri;
    string detalii = "";
public:
    Masina(int nrLocuri = 2, string marca = "", string model = "", string motor = "", string roti = "", int topSpeed = 0, string culoare = "Alb")
    {
        this->culoare = culoare;
        this->marca = marca;
        this->model = model;
        this->motor = motor;
        this->roti = roti;
        this->topSpeed = topSpeed;
        this->nrLocuri = nrLocuri;
    }

    string getDetalii() const
    {
        return this->detalii;
    }

    virtual ostream& AfisareVirtuala(ostream& out) const
    {
        out<<"Numar locuri: "<<this->nrLocuri<<"\n";
        out<<"Marca: "<<this->marca<<"\n";
        out<<"Model: "<<this->model<<"\n";
        out<<"Tip motor: "<<this->motor<<"\n";
        out<<"Tip roti: "<<this->roti<<"\n";
        out<<"Viteza maxima: "<<this->topSpeed<<"\n";
        out<<"Culoare: "<<this->culoare<<"\n";

        return out;
    }
    virtual istream& CitireVirtuala (istream& in)
    {
        cout<<"Numar locuri: ";
        in>>this->nrLocuri;
        in.ignore();
        cout<<"Marca: ";
        getline(in, this->marca);
        cout<<"Model: ";
        getline(in, this->model);
        cout<<"Tip motor: ";
        getline(in, this->motor);
        cout<<"Tip Roti: ";
        getline(in, this->roti);
        cout<<"Viteza maxima (introduceti un numar natural, viteza este masurata in km/h): ";
        in>>this->topSpeed;
        in.ignore();
        cout<<"Culoare: ";
        getline(in, this->culoare);


        return in;
    }


    friend ostream& operator<<(ostream& out, const Masina& masina)
    {
        return masina.AfisareVirtuala(out);
    }
    friend istream& operator>>(istream& in, Masina& masina)
    {
        return masina.CitireVirtuala(in);

    }

    Masina& operator=(const Masina& masina)
    {
        if(this != &masina)
        {
            this->culoare = masina.culoare;
            this->marca = masina.marca;
            this->model = masina.model;
            this->motor = masina.motor;
            this->roti = masina.roti;
            this->topSpeed = masina.topSpeed;
            this->nrLocuri = masina.nrLocuri;
        }
        return *this;
    }


    virtual ~Masina()
    {}
};

class Coupe : public Masina
{
public:
    Coupe(int nrLocuri = 2, string marca = "", string model = "", string motor = "", string roti = "", int topSpeed = 0, string culoare = "Alb") :
        Masina(nrLocuri, marca, model, motor, roti, topSpeed, culoare)
    {
        this->detalii = "Cuvantul \"coupe\" este un neologism si este considerat in general a fi un autoturism cu plafon fix si doua portiere";
    }

    ostream& AfisareVirtuala(ostream& out) const
    {
        Masina::AfisareVirtuala(out);
        out<<"Detalii: "<<this->detalii<<"\n";
        return out;
    }
    istream& CitireVirtuala (istream& in)
    {
        Masina::CitireVirtuala(in);
        return in;
    }


    friend ostream& operator<<(ostream& out, const Coupe& masina)
    {
        return masina.AfisareVirtuala(out);
    }
    friend istream& operator>>(istream& in, Coupe& masina)
    {
        return masina.CitireVirtuala(in);
    }

    Coupe& operator=(const Coupe& masina)
    {
        if(this != &masina)
        {
            this->culoare = masina.culoare;
            this->marca = masina.marca;
            this->model = masina.model;
            this->motor = masina.motor;
            this->roti = masina.roti;
            this->topSpeed = masina.topSpeed;
            this->nrLocuri = masina.nrLocuri;
        }
        return *this;
    }


};

class HotHatch : public Masina
{
public:
    HotHatch(int nrLocuri = 2, string marca = "", string model = "", string motor = "", string roti = "", int topSpeed = 0, string culoare = "Alb") :
        Masina(nrLocuri, marca, model, motor, roti, topSpeed, culoare)
    {
        this->detalii = "Modele hatckback de clasa mica si compacta cu motoare performante ce au la baza modele obisnuite";
    }

    ostream& AfisareVirtuala(ostream& out) const
    {
        Masina::AfisareVirtuala(out);
        out<<"Detalii: "<<this->detalii<<"\n";
        return out;
    }
    istream& CitireVirtuala (istream& in)
    {
        Masina::CitireVirtuala(in);
        return in;
    }


    friend ostream& operator<<(ostream& out, const HotHatch& masina)
    {
        return masina.AfisareVirtuala(out);
    }
    friend istream& operator>>(istream& in, HotHatch& masina)
    {
        return masina.CitireVirtuala(in);
    }

    HotHatch& operator=(const HotHatch& masina)
    {
        if(this != &masina)
        {
            this->culoare = masina.culoare;
            this->marca = masina.marca;
            this->model = masina.model;
            this->motor = masina.motor;
            this->roti = masina.roti;
            this->topSpeed = masina.topSpeed;
            this->nrLocuri = masina.nrLocuri;
        }
        return *this;
    }
};

class Cabrio : public Masina
{
public:
    Cabrio(int nrLocuri = 2, string marca = "", string model = "", string motor = "", string roti = "", int topSpeed = 0, string culoare = "Alb") :
        Masina(nrLocuri, marca, model, motor, roti, topSpeed, culoare)
    {
        this->detalii = "Modele decapotabile cu acoperis metalic sau din material textil";
    }

    ostream& AfisareVirtuala(ostream& out) const
    {
        Masina::AfisareVirtuala(out);
        out<<"Detalii: "<<this->detalii<<"\n";
        return out;
    }
    istream& CitireVirtuala (istream& in)
    {
        Masina::CitireVirtuala(in);
        return in;
    }


    friend ostream& operator<<(ostream& out, const Cabrio& masina)
    {
        return masina.AfisareVirtuala(out);
    }
    friend istream& operator>>(istream& in, Cabrio& masina)
    {
        return masina.CitireVirtuala(in);
    }

    Cabrio& operator=(const Cabrio& masina)
    {
        if(this != &masina)
        {
            this->culoare = masina.culoare;
            this->marca = masina.marca;
            this->model = masina.model;
            this->motor = masina.motor;
            this->roti = masina.roti;
            this->topSpeed = masina.topSpeed;
            this->nrLocuri = masina.nrLocuri;
        }
        return *this;
    }
};

class SuperSport : public Masina
{
public:
    SuperSport(int nrLocuri = 2, string marca = "", string model = "", string motor = "", string roti = "", int topSpeed = 0, string culoare = "Alb") :
        Masina(nrLocuri, marca, model, motor, roti, topSpeed, culoare)
    {
        this->detalii = "Masini de viteza gen Audi R8, Bugatti Veyron, Lexus LF-A, etc.";
    }

    ostream& AfisareVirtuala(ostream& out) const
    {
        Masina::AfisareVirtuala(out);
        out<<"Detalii: "<<this->detalii<<"\n";
        return out;
    }
    istream& CitireVirtuala (istream& in)
    {
        Masina::CitireVirtuala(in);
        return in;
    }


    friend ostream& operator<<(ostream& out, const SuperSport& masina)
    {
        return masina.AfisareVirtuala(out);
    }
    friend istream& operator>>(istream& in, SuperSport& masina)
    {
        return masina.CitireVirtuala(in);
    }

    SuperSport& operator=(const SuperSport& masina)
    {
        if(this != &masina)
        {
            this->culoare = masina.culoare;
            this->marca = masina.marca;
            this->model = masina.model;
            this->motor = masina.motor;
            this->roti = masina.roti;
            this->topSpeed = masina.topSpeed;
            this->nrLocuri = masina.nrLocuri;
        }
        return *this;
    }
};

template <typename T>
class Expozitie
{
    static int nrTotalMasini;
    static int nrMasiniExpuse;
    vector<pair<T, int>> vec;
public:
    void pushCar()
    {
        T aux;
        cin>>aux;
        vec.push_back(make_pair(aux, -1));
        update();
    }

    void pushCar(const T& masina)
    {
        vec.push_back(make_pair(masina, -1));
        update();
    }

    void update()
    {
        this->nrMasiniExpuse = 0;
        this->nrTotalMasini = 0;
        for(auto it = this->vec.begin(); it != this->vec.end(); it++)
        {
            this->nrTotalMasini++;
            if((*it).second == -1) this->nrMasiniExpuse++;
        }
    }

    static int getNrTotalMasini()
    {
        return nrTotalMasini;
    }

    static int getNrMasiniExpuse()
    {
        return nrMasiniExpuse;
    }

    void sell()
    {
        if(this->nrTotalMasini > 0)
        {
            bool ok = 1;
            int nr;
            while(true)
            {
                cout<<"Alegeti numarul masini pe care doriti sa o vindeti [0 <= nr <= "<<this->nrTotalMasini-1<<"]: ";
                cin>>nr;
                if(nr < 0 || nr >= this->nrTotalMasini)
                {
                    cout<<"Numarul masini pe care l-ati ales este invalid, incercati din nou? [0 - NU | 1 - DA]: ";
                    cin>>ok;
                    if(!ok) break;
                }
                else break;
            }
            if(ok)
            {
                int pret;
                while(true)
                {
                    cout<<"Introduceti pretul de vanzare: ";
                    cin>>pret;
                    if(pret < 0)
                    {
                        cout<<"Pretul este negativ, incercati din nou? [0 - NU | 1 - DA]: ";
                        cin>>ok;
                        if(!ok) break;
                    }
                    else break;
                }
                if(ok)
                {
                    if(this->vec[nr].second == -1)
                    {
                        this->vec[nr].second = pret;
                        update();
                    }
                    else cout<<"Masina a fost deja vanduta la pretul de "<<this->vec[nr].second<<" RON\n";
                }
            }
        }
        else cout<<"Nu exista masini in aceasta expozitie\n";
    }

    void delCar(int i)
    {
        if(i >= 0 && i < this->nrTotalMasini)
        {
            auto it = this->vec.begin() + i;
            if((*it).second == -1) this->nrMasiniExpuse--;
            this->vec.erase(it);
            update();
        }
        else throw outOfBounds;
    }

    friend ostream& operator<<(ostream& out, const Expozitie<T>& masina)
    {
        bool ok = 0;
        for(int it = 0; it < masina.nrTotalMasini; it++)
        {
            out<<"Masina cu numarul "<<it<<":\n";
            out<<masina.vec[it].first<<"Pretul de vanzare: "<<masina.vec[it].second<<" RON\n\n";
            ok = 1;
        }
        if(!ok) out<<"Nu exista masini de acest tip\n";
        return out;
    }

    ~Expozitie<T>()
    {
        this->nrMasiniExpuse = 0;
        this->nrTotalMasini = 0;
        this->vec.clear();
    }
};

template<typename T>
int Expozitie<T>::nrTotalMasini = 0;

template<typename T>
int Expozitie<T>::nrMasiniExpuse = 0;

template<>
class Expozitie<SuperSport>
{
    static int nrTotalMasini;
    static int nrMasiniExpuse;
    static int nrMasiniVandute;
    vector<pair<SuperSport, int>> vec;
    vector<SuperSport*> masiniE;
    vector<SuperSport*> masiniV;
    vector<int> preturiE;
    vector<int> preturiV;

public:

    void pushCar()
    {
        SuperSport *aux = new SuperSport;
        cin>>*aux;
        this->vec.push_back(make_pair(*aux, -1));
        update();
        this->nrTotalMasini++;
    }

    void pushCar(SuperSport& aux)
    {
        SuperSport *aux1 = &aux;
        this->vec.push_back(make_pair(*aux1, -1));
        update();
        this->nrTotalMasini++;
    }

    void update()
    {
        this->nrMasiniExpuse = 0;
        this->nrMasiniVandute = 0;
        this->masiniE.clear();
        this->masiniV.clear();
        for(auto it = this->vec.begin(); it != this->vec.end(); it++)
        {
            if((*it).second == -1)
            {
                this->masiniE.push_back(&(*it).first);
                this->nrMasiniExpuse++;
                this->preturiE.push_back((*it).second);
            }
            else
            {
                this->masiniV.push_back(&(*it).first);
                this->nrMasiniVandute++;
                this->preturiV.push_back((*it).second);
            }
        }
    }

    void delCar(int i)
    {
        if(i >= 0 && i < this->nrTotalMasini)
        {
            auto it = this->vec.begin() + i;
            this->vec.erase(it);
            this->nrTotalMasini--;
            update();
        }
        else throw outOfBounds;
    }

    void sell()
    {
        if(this->nrTotalMasini > 0)
        {
            bool ok = 1;
            int nr;
            while(true)
            {
                cout<<"Alegeti numarul masini pe care doriti sa o vindeti [0 <= nr <= "<<this->nrTotalMasini-1<<"]: ";
                cin>>nr;
                if(nr < 0 || nr >= this->nrTotalMasini)
                {
                    cout<<"Numarul masini pe care l-ati ales este invalid, incercati din nou? [0 - NU | 1 - DA]: ";
                    cin>>ok;
                    if(!ok) break;
                }
                else break;
            }
            if(ok)
            {
                int pret;
                while(true)
                {
                    cout<<"Introduceti pretul de vanzare: ";
                    cin>>pret;
                    if(pret < 0)
                    {
                        cout<<"Pretul este negativ, incercati din nou? [0 - NU | 1 - DA]: ";
                        cin>>ok;
                        if(!ok) break;
                    }
                    else break;
                }
                if(ok)
                {
                    if(this->vec[nr].second == -1)
                    {
                        this->vec[nr].second = pret;
                    }
                    else cout<<"Masina a fost deja vanduta la pretul de "<<this->vec[nr].second<<" RON\n";
                }
                *this-=ok;
            }
        }
        else cout<<"Nu exista masini in aceasta expozitie\n";
    }

    static int getNrTotalMasini()
    {
        return nrTotalMasini;
    }

    static int getNrMasiniExpuse()
    {
        return nrMasiniExpuse;
    }

    static int getNrMasiniVandute()
    {
        return nrMasiniVandute;
    }

    friend ostream& operator<<(ostream& out, Expozitie<SuperSport>& masina)
    {
        bool ok = 0;
        out<<"Masinile expuse:\n\n";
        for(int it = 0; it != masina.nrMasiniExpuse; it++)
        {
            out<<*(masina.masiniE[it])<<"Pretul de vanzare: "<<masina.preturiE[it]<<" RON\n\n";
            ok = 1;
        }
        if(!ok) out<<"Nu exista masini expuse\n\n";

        ok = 0;
        out<<"Masinile vandute:\n\n";
        for(int it = 0; it != masina.nrMasiniVandute; it++)
        {
            out<<*(masina.masiniV[it])<<"Pretul de vanzare: "<<masina.preturiV[it]<<" RON\n\n";
            ok = 1;
        }
        if(!ok) out<<"Nu exista masini vandute\n";

        return out;
    }

    Expozitie<SuperSport>& operator-=(bool ok)
    {
        if(ok) update();
    }

    ~Expozitie<SuperSport>()
    {
        this->nrMasiniExpuse = 0;
        this->nrMasiniVandute = 0;
        this->nrTotalMasini = 0;
        this->vec.clear();
        this->masiniE.clear();
        this->masiniV.clear();
        this->preturiE.clear();
        this->preturiV.clear();
    }

};

template<>
int Expozitie<SuperSport>::nrTotalMasini = 0;

template<>
int Expozitie<SuperSport>::nrMasiniExpuse = 0;

template<>
int Expozitie<SuperSport>::nrMasiniVandute = 0;

class MeniuInteractiv
{
    static MeniuInteractiv *obj;
public:
    static MeniuInteractiv* getInstance()
    {
        if(!obj)
            obj = new MeniuInteractiv;
        return obj;
    }

    void meniu()
    {
        Masina *pMasina = nullptr;
        Expozitie<Coupe> exCo;
        Expozitie<HotHatch> exH;
        Expozitie<Cabrio> exCa;
        Expozitie<SuperSport> exS;
        bool k = true;
        int comanda;
        while(k)
        {
            cout<<"Pentru a introduce o masina intr-o expozitie apasati tasta 1\n";
            cout<<"Pentru a afisa masinile dintr-o expozitie apasati tasta 2\n";
            cout<<"Pentru a afisa toate masinile din toate expozitiile apasati tasta 3\n";
            cout<<"Pentru a afisa numarul total de masini dintr-o expozitie apasati tasta 4\n";
            cout<<"Pentru a afisa numarul total de masini din toate expozitiile apasati tasta 5\n";
            cout<<"Pentru a afisa numarul total de masini expuse dintr-o expozitie apasati tasta 6\n";
            cout<<"Pentru a afisa numarul total de masini expuse din toate expozitiile apasati tasta 7\n";
            cout<<"Pentru a vinde o masina dintr-o expozitie apasati tasta 8\n";
            cout<<"Pentru a sterge o masina dintr-o expozitie apasati tasta 9\n";
            cout<<"Pentru STOP apasati tasta 10\n";

            cout<<"Comanda: ";
            cin>>comanda;
            cout<<"\n";

            switch(comanda)
            {
            case 1:
            {
                int tasta;

                cout<<"Pentru a efectua aceasta actiune apasati tasta corezpunzatoarea urmatoarelor modele:\n";
                cout<<"Pentru masini Coupe apasati tasta 1\n";
                cout<<"Pentru masini Hot-Hatch apasati tasta 2\n";
                cout<<"Pentru masini Cabrio apasati tasta 3\n";
                cout<<"Pentru masini Super Sport apasati tasta 4\n";

                cout<<"Comanda: ";
                cin>>tasta;
                cout<<"\n";

                switch(tasta)
                {
                case 1:
                {
                    pMasina = new Coupe;
                    cin>>*pMasina;
                    cout<<"\n";
                    Coupe *aux = dynamic_cast<Coupe*> (pMasina);
                    exCo.pushCar(*aux);
                    break;
                }
                case 2:
                {
                    pMasina = new HotHatch;
                    cin>>*pMasina;
                    cout<<"\n";
                    HotHatch *aux = dynamic_cast<HotHatch*> (pMasina);
                    exH.pushCar(*aux);
                    break;
                }
                case 3:
                {
                    pMasina = new Cabrio;
                    cin>>*pMasina;
                    cout<<"\n";
                    Cabrio *aux = dynamic_cast<Cabrio*> (pMasina);
                    exCa.pushCar(*aux);
                    break;
                }
                case 4:
                {
                    pMasina = new SuperSport;
                    cin>>*pMasina;
                    cout<<"\n";
                    SuperSport *aux = dynamic_cast<SuperSport*> (pMasina);
                    exS.pushCar(*aux);
                    break;
                }
                default:
                {
                    cout<<"Comanda invalida\n\n";
                    break;
                }
                }

                break;
            }

            case 2:
            {
                int tasta;

                cout<<"Pentru a efectua aceasta actiune apasati tasta corezpunzatoarea urmatoarelor modele:\n";
                cout<<"Pentru masini Coupe apasati tasta 1\n";
                cout<<"Pentru masini Hot-Hatch apasati tasta 2\n";
                cout<<"Pentru masini Cabrio apasati tasta 3\n";
                cout<<"Pentru masini Super Sport apasati tasta 4\n";

                cout<<"Comanda: ";
                cin>>tasta;
                cout<<"\n";

                switch(tasta)
                {
                case 1:
                {
                    cout<<"Masinile Coupe:\n\n";
                    cout<<exCo<<"\n";
                    break;
                }
                case 2:
                {
                    cout<<"Masinile Hot-Hatch:\n\n";
                    cout<<exH<<"\n";
                    break;
                }
                case 3:
                {
                    cout<<"Masinile Cabrio:\n\n";
                    cout<<exCa<<"\n";
                    break;
                }
                case 4:
                {
                    cout<<"Masinile Super Sport:\n\n";
                    cout<<exS<<"\n";
                    break;
                }
                default:
                {
                    cout<<"Comanda invalida\n\n";
                    break;
                }
                }

                break;
            }

            case 3:
            {
                cout<<"Masinile Coupe:\n\n";
                cout<<exCo<<"\n";
                cout<<"Masinile Hot-Hatch:\n\n";
                cout<<exH<<"\n";
                cout<<"Masinile Cabrio:\n\n";
                cout<<exCa<<"\n";
                cout<<"Masinile Super Sport:\n\n";
                cout<<exS<<"\n";
                break;
            }

            case 4:
            {
                int tasta;

                cout<<"Pentru a efectua aceasta actiune apasati tasta corezpunzatoarea urmatoarelor modele:\n";
                cout<<"Pentru masini Coupe apasati tasta 1\n";
                cout<<"Pentru masini Hot-Hatch apasati tasta 2\n";
                cout<<"Pentru masini Cabrio apasati tasta 3\n";
                cout<<"Pentru masini Super Sport apasati tasta 4\n";

                cout<<"Comanda: ";
                cin>>tasta;
                cout<<"\n";

                switch(tasta)
                {
                case 1:
                {
                    cout<<"Numarul total de masini Coupe: ";
                    cout<<exCo.getNrTotalMasini()<<"\n";
                    break;
                }
                case 2:
                {
                    cout<<"Numarul total de masini Hot-Hatch: ";
                    cout<<exH.getNrTotalMasini()<<"\n";
                    break;
                }
                case 3:
                {
                    cout<<"Numarul total de masini Cabrio: ";
                    cout<<exCa.getNrTotalMasini()<<"\n";
                    break;
                }
                case 4:
                {
                    cout<<"Numarul total de masini Super Sport: ";
                    cout<<exS.getNrTotalMasini()<<"\n";
                    break;
                }
                default:
                {
                    cout<<"Comanda invalida\n\n";
                    break;
                }
                }

                break;
            }
            case 5:
            {
                int s;
                s = exCo.getNrTotalMasini() + exCa.getNrTotalMasini() + exH.getNrTotalMasini() + exS.getNrTotalMasini();
                cout<<"Numarul total de masini este: "<<s<<"\n\n";
                break;
            }

            case 6:
            {
                int tasta;

                cout<<"Pentru a efectua aceasta actiune apasati tasta corezpunzatoarea urmatoarelor modele:\n";
                cout<<"Pentru masini Coupe apasati tasta 1\n";
                cout<<"Pentru masini Hot-Hatch apasati tasta 2\n";
                cout<<"Pentru masini Cabrio apasati tasta 3\n";
                cout<<"Pentru masini Super Sport apasati tasta 4\n";

                cout<<"Comanda: ";
                cin>>tasta;
                cout<<"\n";

                switch(tasta)
                {
                case 1:
                {
                    cout<<"Numarul total de masini expuse Coupe: ";
                    cout<<exCo.getNrMasiniExpuse()<<"\n";
                    break;
                }
                case 2:
                {
                    cout<<"Numarul total de masini expuse Hot-Hatch: ";
                    cout<<exH.getNrMasiniExpuse()<<"\n";
                    break;
                }
                case 3:
                {
                    cout<<"Numarul total de masini expuse Cabrio: ";
                    cout<<exCa.getNrMasiniExpuse()<<"\n";
                    break;
                }
                case 4:
                {
                    cout<<"Numarul total de masini expuse Super Sport: ";
                    cout<<exS.getNrMasiniExpuse()<<"\n";
                    break;
                }
                default:
                {
                    cout<<"Comanda invalida\n\n";
                    break;
                }
                }

                break;
            }
            case 7:
            {
                int s;
                s = exCo.getNrMasiniExpuse() + exCa.getNrMasiniExpuse() + exH.getNrMasiniExpuse() + exS.getNrMasiniExpuse();
                cout<<"Numarul total de masini expuse este: "<<s<<"\n\n";
                break;
            }

            case 8:
            {
                int tasta;

                cout<<"Pentru a efectua aceasta actiune apasati tasta corezpunzatoarea urmatoarelor modele:\n";
                cout<<"Pentru masini Coupe apasati tasta 1\n";
                cout<<"Pentru masini Hot-Hatch apasati tasta 2\n";
                cout<<"Pentru masini Cabrio apasati tasta 3\n";
                cout<<"Pentru masini Super Sport apasati tasta 4\n";

                cout<<"Comanda: ";
                cin>>tasta;
                cout<<"\n";

                switch(tasta)
                {
                case 1:
                {
                    exCo.sell();
                    cout<<"\n";
                    break;
                }
                case 2:
                {
                    exH.sell();
                    cout<<"\n";
                    break;
                }
                case 3:
                {
                    exCa.sell();
                    cout<<"\n";
                    break;
                }
                case 4:
                {
                    exS.sell();
                    cout<<"\n";
                    break;
                }
                default:
                {
                    cout<<"Comanda invalida\n\n";
                    break;
                }
                }

                break;
            }

            case 9:
            {
                int tasta;

                cout<<"Pentru a efectua aceasta actiune apasati tasta corezpunzatoarea urmatoarelor modele:\n";
                cout<<"Pentru masini Coupe apasati tasta 1\n";
                cout<<"Pentru masini Hot-Hatch apasati tasta 2\n";
                cout<<"Pentru masini Cabrio apasati tasta 3\n";
                cout<<"Pentru masini Super Sport apasati tasta 4\n";

                cout<<"Comanda: ";
                cin>>tasta;
                cout<<"\n";

                switch(tasta)
                {
                case 1:
                {
                    int n, nrM = exCo.getNrTotalMasini();
                    if(nrM > 0)
                    {
                        cout<<"Introduceti numarul masini pe care doriti sa o stergeti [0 <= nr <= "<<nrM - 1<<"]: ";
                        cin>>n;
                        cout<<"\n";
                        try
                        {
                            exCo.delCar(n);
                        }
                        catch(OutOfBounds &e)
                        {
                            cout<<"Nu exista masina in aceasta zona de memorie\n\n";
                        }
                    }
                    else cout<<"Nu exista masini in aceasta expozitie\n\n";
                    break;
                }
                case 2:
                {
                    int n, nrM = exH.getNrTotalMasini();
                    if(nrM > 0)
                    {
                        cout<<"Introduceti numarul masini pe care doriti sa o stergeti [0 <= nr <= "<<nrM - 1<<"]: ";
                        cin>>n;
                        cout<<"\n";
                        try
                        {
                            exH.delCar(n);
                        }
                        catch(OutOfBounds &e)
                        {
                            cout<<"Nu exista masina in aceasta zona de memorie\n";
                        }
                    }
                    else cout<<"Nu exista masini in aceasta expozitie\n\n";
                    break;
                }
                case 3:
                {
                    int n, nrM = exCa.getNrTotalMasini();
                    if(nrM > 0)
                    {
                        cout<<"Introduceti numarul masini pe care doriti sa o stergeti [0 <= nr <= "<<nrM - 1<<"]: ";
                        cin>>n;
                        cout<<"\n";
                        try
                        {
                            exCa.delCar(n);
                        }
                        catch(OutOfBounds &e)
                        {
                            cout<<"Nu exista masina in aceasta zona de memorie\n";
                        }
                    }
                    else cout<<"Nu exista masini in aceasta expozitie\n\n";
                    break;
                }
                case 4:
                {
                    int n, nrM = exS.getNrTotalMasini();
                    if(nrM > 0)
                    {
                        cout<<"Introduceti numarul masini pe care doriti sa o stergeti [0 <= nr <= "<<nrM - 1<<"]: ";
                        cin>>n;
                        cout<<"\n";
                        try
                        {
                            exS.delCar(n);
                        }
                        catch(OutOfBounds &e)
                        {
                            cout<<"Nu exista masina in aceasta zona de memorie\n";
                        }
                    }
                    else cout<<"Nu exista masini in aceasta expozitie\n\n";
                    break;
                }
                default:
                {
                    cout<<"Comanda invalida\n\n";
                    break;
                }
                }

                break;
            }

            case 10:
            {
                k = false;
                break;
            }

            default:
            {
                cout<<"Comanda invalida\n\n";
                break;
            }

            }
        }
    }


};

MeniuInteractiv* MeniuInteractiv::obj=nullptr;


int main()
{
    MeniuInteractiv *meniulMeu = meniulMeu->getInstance();
    meniulMeu->meniu();
    return 0;
}
