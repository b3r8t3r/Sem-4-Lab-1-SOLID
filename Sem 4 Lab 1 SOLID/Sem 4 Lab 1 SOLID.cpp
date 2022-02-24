#include <iostream>
#include <vector>
using namespace std;

enum class Ammo_type{
    first,
    second,
    third
};

class Artillery_weapon {
    int ammunition;
    pair<int, int> ammunition_limits;
    vector <bool> magazine;
    Ammo_type ammunition_type;
public:
    Artillery_weapon(Ammo_type a_t, int _ammo) {
        ammunition_limits.first = 0;

        ammunition_type = a_t;

        switch (static_cast<int>(ammunition_type)) {
        case 0:
        {
            ammunition_limits.second = 45;
            magazine.assign(15, false);
            break;
        }
        case 1:
        {
            ammunition_limits.second = 30;
            magazine.assign(10, false);
            break;
        }
        case 2:
        {
            ammunition_limits.second = 15;
            magazine.assign(5, false);
            break;
        }
        }
        ammunition = (_ammo >= ammunition_limits.first && _ammo <= ammunition_limits.second) ? _ammo : 0;
    }

    void Reload() {
        int remains = 0;

        for (int i = 0; i < magazine.size(); i++) {
            if (magazine[i]) 
            {
                remains++; 
                magazine[i] = false;
            }
        }
        ammunition += remains;

        for (int i = 0; i < magazine.size(); i++) {
            if (ammunition > 0)
            {
                magazine[i] = true;
                ammunition--;
            }
            else break;
        }
        
    };
    void Shoot() {

        for (int i = magazine.size() - 1; i > 0; i-=(3 - static_cast<int>(ammunition_type))) {
            if (!magazine[i]) continue;
            else
            {
                for (int temp = 0; temp < 3- static_cast<int>(ammunition_type); temp++)
                    magazine[i - temp] = false;
                break;
            }
        }
        Sort();
    };
    void Sort() {
        for (int i = magazine.size() - 1; i >0 ; i--) {
            if (magazine[i] == true && magazine[i - 1] == false) {
                for (int j = 0; j < i; j++) {
                    if (magazine[j] == true && magazine[j + 1] == false) {
                        magazine[j + 1] = true;
                        magazine[i] = false;
                        break;
                    }
                }
            }
        }
    }
    void Require_ammo() {
        ammunition += ammunition_limits.second - ammunition;
    };
};



//////////////
//class Artillery_weapon {
//protected:
//    int ammo;
//    bool charge;
//public:
//    Artillery_weapon() {
//        ammo = 0;
//        charge = false;
//    }
//    Artillery_weapon(int _ammo) {
//        Set_Ammo(_ammo);
//        charge = false;
//    }
//
//    int Get_Ammo() {
//        return this->ammo;
//    }
//    void Set_Ammo(int _ammo) {
//        this->ammo = (_ammo >= 0 && _ammo <= 30) ? _ammo : 0;
//    }
//
//    bool Get_Charge() {
//        return this->charge;
//    }
//    void Set_Charge(bool _charge) {
//        this->charge = _charge;
//    }
//};
//
//class Preparations {
//    virtual void Reload() = 0;
//};
//
//class Artillery_weapon_reload : private Preparations {
//    Artillery_weapon a_w;
//
//public:
//    Artillery_weapon_reload(Artillery_weapon _a_w) {
//        this->a_w = _a_w;
//    }
//
//    void Reload() {
//        a_w.Set_Ammo(a_w.Get_Ammo() - 1);
//        a_w.Set_Charge(true);
//    }
//};
//
//class Execution {
//    virtual void Shoot() = 0;
//};
//
//class Artillery_weapon_shoot : private Execution {
//    Artillery_weapon a_w;
//public:
//    Artillery_weapon_shoot(Artillery_weapon _a_w) {
//        this->a_w = _a_w;
//    }
//
//    void Shoot() {
//        a_w.Set_Charge(false);
//    }
//};
//
//class Alarm {
//    virtual void Require_ammo() = 0;
//};
//
//class Artillery_weapon_require_ammo : private Alarm {
//    Artillery_weapon a_w;
//public:
//    Artillery_weapon_require_ammo(Artillery_weapon _a_w) {
//        this->a_w = _a_w;
//    }
//
//    void Require_ammo() {
//        a_w.Set_Ammo(30);
//    }
//};
//
//void Enable_Artillery_Gun() {
//    Artillery_weapon weapon(30);
//
//}

void Fire() {
    Artillery_weapon weapon(Ammo_type::first, 45);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            weapon.Reload();
            weapon.Shoot();
            weapon.Shoot();
            weapon.Shoot();
            weapon.Shoot();
            weapon.Shoot();
        }
        weapon.Require_ammo();
    }
}

int main()
{
    //Enable_Artillery_Gun();
    Fire();

    return 0;
}

