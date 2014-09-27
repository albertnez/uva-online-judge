#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;


int gy(int n) { return n/10000; }
int gm(int n) { return (n%10000)/100; }
int gd(int n) { return n%100; }

int iy(int n) { return n+10000; }

void print(int date, int merit, int demerit) {
  int y = gy(date), m = gm(date), d = gd(date);
  cout << setfill('0') << setw(4) << gy(date) << '-' << setw(2) << gm(date) << '-' << setw(2) << gd(date) << ' ';
  if (!merit and !demerit) cout << "No merit or demerit points." << endl;
  else if (merit) cout << merit << " merit point(s)." << endl;
  else cout << demerit << " demerit point(s)." << endl;
}

int main() {
  int T; cin >> T;
  while (T--) {
    string s;
    int date;
    cin >> date;
    cin.ignore();
    int lastoffence = date;
    int actualdate = date;
    
    int merit = 0;
    int demerit = 0;
    bool addmerit = false;

    print(date, merit, demerit);
    
    while (getline(cin, s) and s != "") {
      int noffences;
      istringstream ss(s);
      ss >> date >> noffences;
      while (iy(actualdate) <= date) {
        actualdate = iy(actualdate);
        if (demerit > 0) {
          demerit = max(0, min(demerit/2, demerit-2));
          print(actualdate, merit, demerit);
        }
        else if (!addmerit) addmerit = true;
        else {
          addmerit = false;
          ++merit;
          print(actualdate, merit, demerit);
        }
      }
      
      if (merit == 0) {
        demerit += noffences;
      }
      else if (noffences > 2*merit) {
        demerit += noffences-2*merit;
        merit = 0;
      }
      else {
        demerit = 0;
        merit /= 2;
      }
      print(date, merit, demerit);
      actualdate = date;
      addmerit = false;
    }
    while (merit < 5) {
      actualdate = iy(actualdate);
      if (demerit > 0) {
        demerit = max(0, min(demerit/2, demerit-2));
        print(actualdate, merit, demerit);
      }
      else if (!addmerit) addmerit = true;
      else {
        addmerit = false;
        ++merit;
        print(actualdate, merit, demerit);
      }
    }
    if (T) cout << endl;
  }
}