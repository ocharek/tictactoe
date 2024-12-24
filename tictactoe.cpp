#include <iostream>
#include <stdlib.h>

using namespace std;

class game{
  private:
    string *tab;
    string nick1, nick2;
    int turn = 0;
  public:
    game(string, string);
    ~game();
    void print(){ //wyswietlenie plaszy
      cout << tab[0] << " " << tab[1] << " " << tab[2] << endl;
      cout << tab[3] << " " << tab[4] << " " << tab[5] << endl;
      cout << tab[6] << " " << tab[7] << " " << tab[8] << endl;
    }
    bool kolko(){ //tura kolka
      int a;
      turn += 1;
      if(turn == 10) {
        endD();
        return 0;
      }
      print();
      cout << "Gracz: " << nick1 << ". " << "Ktore pole zaznaczyc jako kolko: ";
      cin >> a;
      if (tab[a-1] == to_string(a)){
        tab[a-1] = "O";
        if(check(a, "O"))endW(nick1);
        else {
          system("clear");
          krzyzyk();
        }
      }else{
        system("clear");
        cout << "Prosze wybrac inne pole!" << endl;
        kolko();
      }
      return 0;
    }

    bool krzyzyk(){ //tura krzyzyka
      int a;
      turn += 1;
      if(turn == 10) {
        endD();
        return 0;
      }
      print();
      cout << "Gracz: " << nick2 << ". " <<"Ktore pole zaznaczyc jako krzyzyk: ";
      cin >> a;
      if (tab[a-1] == to_string(a)){
        tab[a-1] = "X";
        if(check(a, "X"))endW(nick2);
        else {
          system("clear");
          kolko();
          }
      }else{
        system("clear");
        cout << "Prosze wybrac inne pole!" << endl;
        krzyzyk();
      }
      return 0;
    }

    bool check(int a, string c){ //czy wygrany ruch
      if (chkCross(a,c)) return 1;
      else if (chkHor(a, c)) return 1;
      else if (chkVert(a, c)) return 1;
      else return 0;
    }

    void endW(string nick){ //komunikat zwyciestwa
      system("clear");
      print();
      cout << "ZWYCIEZA GRACZ " << nick << "!" << endl;
    }

    void endD(){ // komunikat remisu
      system("clear");
      print();
      cout << "Nastapil remis!" << endl;
    }

    bool chkCross(int b, string c){ //check po skosie
      int a = b-1;
      if(a == 0 || a == 4 || a == 8){
        if(tab[0] == c && tab[4] == c && tab[8] == c){
          return 1;
        }else return 0;
      }
      else if(a == 2 || a == 4 || a == 6){
        if(tab[2] == c && tab[4] == c && tab[6] == c){
          return 1;
        }else return 0;
      }
      return 0;
    }

    bool chkVert(int b, string c){ //check w pionie
      int a = b-1;
      if(a == 0 || a == 3 || a == 6){
        if(tab[0] == c && tab[3] == c && tab[6] == c){
          return 1;
        }else return 0;
      }
      else if(a == 1 || a == 4 || a == 7){
        if(tab[1] == c && tab[4] == c && tab[7] == c){
          return 1;
        }else return 0;
      }
      else if(a == 2 || a == 5 || a == 8){
        if(tab[2] == c && tab[5] == c && tab[8] == c){
          return 1;
        }else return 0;
      }
      return 0;
    }

    bool chkHor(int b, string c){ //check w poziomie
      int a = b-1;
      if(a == 0 || a == 1 || a == 2){
        if(tab[0] == c && tab[1] == c && tab[2] == c){
          return 1;
        }else return 0;
      }
      else if(a == 3 || a == 4 || a == 5){
        if(tab[3] == c && tab[4] == c && tab[5] == c){
          return 1;
        }else return 0;
      }
      else if(a == 6 || a == 7 || a == 8){
        if(tab[6] == c && tab[7] == c && tab[8] == c){
          return 1;
        }else return 0;
      }
      return 0;
    }
};

game::game(string a, string b) : tab(new string[9]){ //konstruktor
  nick1 = a;
  nick2 = b;
  for(int i = 0; i <= 8; i++){
    tab[i] = to_string(i+1);
  }
  system("clear");
  kolko();
}

game::~game(){} //destruktor

int main(){
  string nick1, nick2;
  cout << "Podaj nick gracza 1: ";
  cin >> nick1;
  cout << "Podaj nick gracza 2: ";
  cin >> nick2;
  game g(nick1, nick2);

  return 0;
}
