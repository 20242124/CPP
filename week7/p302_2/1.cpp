#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAXWORDS = 100; 

struct WordPair {
    string eng;
    string kor;
};


class MyDic {
    WordPair words[MAXWORDS]; 
    int nWords = 0;           

public:
    void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

    
    void load(string filename) {
        ifstream fin(filename);
        if (fin.is_open()) {
            nWords = 0;
            while (nWords < MAXWORDS && fin >> words[nWords].eng >> words[nWords].kor) {
                nWords++;
            }
            fin.close();
        }
    }

    
    void store(string filename) {
        ofstream fout(filename);
        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }
        fout.close();
    }

    
    void print() {
        for (int i = 0; i < nWords; i++) {
            cout << words[i].eng << " : " << words[i].kor << endl;
        }
    }

    
    string getEng(int id) { return words[id].eng; }

    
    string getKor(int id) { return words[id].kor; }
};


int main() {
    MyDic dic;

    
    dic.add("apple", "사과");
    dic.add("grape", "포도");

    
    dic.store("test.txt");
    cout << "--- 현재 단어장 ---" << endl;
    dic.print();

    return 0;
}