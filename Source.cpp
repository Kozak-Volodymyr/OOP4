#include<iostream>
using namespace std;
class Dep {
private:
	 double sum;
	char* name;
	int n;
public:
	 Dep() :sum(), name() {};
	 Dep(double h,  char* names) {
		  sum=h;
		  name = names;
	 }
	 Dep(const Dep&obj) {
		  sum = obj.sum;
		  name = obj.name;
	 }
	 ~Dep(){}
	 void SetSum(double a) {
		  sum = a;
	 }
	 void SetName(char* names) {
		  name = names;
	 }
	 double GetSum() { return sum; }
	 char* GetName() { return name; }
};
class Bank :public Dep {
private:
	 int termin;
	 double rich;
public:
	 Bank() :Dep() {};
	 Bank(double a, char* names, int ter, double rik) {
		  SetSum(a);
		  SetName(names);
		  termin = ter;
		  rich = rik;
	 }
	 ~Bank() {}
	 double Vids() {
		  double Vids;
		  Vids = termin * rich*GetSum();
		  return Vids;
	 }
	 friend ostream& operator<<(ostream&os, Bank &p) {
		  os << "\n �����:" << p.termin <<" "<< "г��� ������:" << p.rich <<" "<< "C��� ��������:" << p.GetSum() <<" "<< "ϲ�:" << p.GetName() <<" "<<"³������: "<<" "<<p.Vids()<<"\n";
			return os;
	 }
};
bool operator>(Bank&obj, Bank&obj1) {
	 return (obj.Vids() > obj1.Vids());
		  
 }
int main() {
	 system("chcp 1251");
	 int n;
	 cout << "������ ������� �볺���:";
	 cin >> n;//������� �볺���
	 getchar();
	 int l = 1;
	 Bank *p = new Bank[n];
	 for (int i = 0; i < n; i++) {
		  int a;
		  double c,b;
		  char name[100][100];
		  cout << "\n ��� " << " " << i + 1 << " " << "�������� \n";
		  cout << "\n ������ ϲ�:";
		  gets_s(name[i],100);//�������� � ������
		  cout << "\n ������ �����:";
		  cin>>a;
		  cout << "\n ������ ���� ������:";
		  cin >> b;
		  cout << "\n ������ ���� ��������:";
		  cin >> c;
		  getchar();
		  p[i] = Bank(c,name[i], a, b);
	 }
	 for (int i = 0; i < n; i++) {
		  l = 1;
		  Bank copy;
		  if ((i + 1) == n)
				break;
		  for (; (i + l) < n; l++) {
				if ((p[i] > p[i + l]) == 0) {
					 copy = p[i];
					 p[i] = p[i + l];
					 p[i + l] = copy;
					 i = -1;
					 l = n;
				}
		  }
	 }
	 cout << "\n ³����������� ������:";
	 for (int i = 0; i < n; i++) {
		  cout << p[i];
	 }
	 return 0;
}