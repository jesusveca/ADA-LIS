#include <iostream>
#include <vector>

using namespace std;

void imprimir_anidado(vector<int>& vectorcito) {
	for(int i=0;i<vectorcito.size();i++){
        cout<<vectorcito[i]<<"  ";
	}
	cout<<endl;
}


void calcular_subsecuencias_incrementales(vector<int>& vectorcito) {
	vector< vector<int> > almacen(vectorcito.size());
    almacen[0].push_back(vectorcito[0]);
	for (int i=1; i<vectorcito.size(); i++) {
		for(int j=0; j<i; j++) {
			if ( (vectorcito[j] < vectorcito[i]) && ( almacen[i].size() < almacen[j].size() ) ) {
				almacen[i] = almacen[j];
			}
		}
      almacen[i].push_back(vectorcito[i]);
	}

	for (auto x: almacen) {
		imprimir_anidado(x);
	}


}

int main() {
	int a[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	vector<int> vectorcito(a, a + sizeof(a)/sizeof(a[0]));
    cout<<"vector inicial "<<endl;  imprimir_anidado(vectorcito);
    cout<<endl<<"subsecuencias incrementales "<<endl;
	calcular_subsecuencias_incrementales(vectorcito);
	return 0;
}
