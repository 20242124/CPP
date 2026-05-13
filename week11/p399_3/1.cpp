#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Monster 
{
private:
    string name;
    string symbol; 
    int x, y;
    int energy;    

public:
    static int count;

    Monster(string n = "몬스터", string s = "※", int px = 0, int py = 0, int e = 100) 
    {
        name = n;
        symbol = s;
        x = px;
        y = py;
        energy = e;
        count++; 
    }

    ~Monster() 
    {
        count--; 
    }

    string getName() { return name; }

    int getEnergy() 
    {
        return energy;
    }

    void eat(int food) 
    {
        energy += food;
    }

    void move() 
    {
        energy -= 10; 
    }

    void print() 
    {
        cout << "  " << name << symbol << " : E:" << energy << " ";
    }

    static void printCount() 
    {
        cout << "전체 몬스터의 수 : [" << count << "]" << endl;
    }
};

int Monster::count = 0;

class MonsterWorld 
{
private:
    Monster* pMon[100]; 
    int nMon;           
    int w, h;           

public:
    MonsterWorld(int width, int height) : w(width), h(height), nMon(0) {}

    ~MonsterWorld() 
    {
        for (int i = 0; i < nMon; i++) 
        {
            delete pMon[i];
        }
    }

    void add(Monster* m) 
    {
        if (nMon < 100) 
        {
            pMon[nMon++] = m;
        }
    }

    void checkStarvation() 
    {
        for (int i = 0; i < nMon; ) 
        {
            if (pMon[i]->getEnergy() <= 0) 
            {
                cout << "Monster 하나가 굶어죽습니다 (" << pMon[i]->getName() << " 아사)" << endl;
                
                delete pMon[i]; 

                pMon[i] = pMon[nMon - 1];
                nMon--;
            } 
            else 
            {
                i++; 
            }
        }
    }

    void play(int maxMoves, int delay) 
    {
        cout << "===== Monster World (Dynamic World) =====" << endl;
        
        for (int turn = 1; turn <= maxMoves; turn++) 
        {
            for (int i = 0; i < nMon; i++) 
            {
                pMon[i]->move();
            }

            checkStarvation();

            if (nMon == 0) {
                cout << "\n모든 몬스터가 아사했습니다." << endl;
                break;
            }
        }

        cout << "\n전체 이동 횟수 = " << maxMoves << endl;
        for (int i = 0; i < nMon; i++) 
        {
            pMon[i]->print();
            cout << endl;
        }
        Monster::printCount();
    }
};

int main() 
{
    srand((unsigned int)time(NULL));
    int w = 16, h = 8;

    MonsterWorld game(w, h);
    
    game.add(new Monster("몬스터", "※", rand() % w, rand() % h, 50));
    game.add(new Monster("도깨비", "§", rand() % w, rand() % h, 30));
    game.add(new Monster("별그대", "★", rand() % w, rand() % h, 180));
    game.add(new Monster("고스트", "♥", rand() % w, rand() % h, 40));
    
    Monster::printCount(); 
    
    game.play(5, 10); 

    printf("------게임 종료-------------------\n");

    return 0;
}