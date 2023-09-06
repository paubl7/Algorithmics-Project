#include "components.h"
#include "RGG_generator.h"
#include "percolacio_Grafs.h"
#include "NxN_Generator.h"
using namespace std;

typedef vector<vector<bool>> Graf; // Representem els Grafs com matrius d'adjacència
typedef map<int,set<int>> GrafL; // Representació en llista d'adjacència
typedef float prob_fail;
typedef vector<vector<int>> Square;

GrafL graf_actual_vertexs;
Graf graf_actual_arestes;


//Components necessita GrafL
//percolacio_arestes necessita Graf i retorna Graf
//percolació nodes necessita GrafL i retorna GrafL
//Random generator retorna Graf
//NxN generator retorna GrafL
//GrafL-> Graf == list_to_mat     Graf -> GrafL == mat_to_list


void random_geometric(){
	int auto_r;
	cout << "Fer estudi autòmatic respecte la distància màxima, fer estudi autòmatic respecte la probabilitat de fallida o fer l'experiment manualment: " << endl;
	cout << "(2:Autòmatic Treshold 1:Autòmatic Probabilitat 0:Manual)" << endl;
	cin >> auto_r;
	cout << endl;
	int n_vertex, graella_size;
	//Estudi automàtic r-q
	if (auto_r== 2){
		cout << "ESTUDI AUTÒMATIC R-Q:" << endl;
		cout << endl;
		srand(time(NULL));
		n_vertex= rand()%10000;
		cout << "Nombre de vèrtxs: " << n_vertex << endl;
		cout << endl;
		graella_size= 100; //Tamany pre-establert de graella
		cout << "Tamany de la graella: " << 10000 << endl;
		cout << endl;
		for (float r= 2*(n_vertex/10000); r < 10000; r= 2*r){
			cout << "Treshold distance: " << r << endl;
			cout << endl;
			graf_actual_arestes = RGG_generator(n_vertex, graella_size,r); // Generem el RGG com a Matriu d'adjacència
			int comp= comp = connect_graph(mat_to_list(graf_actual_arestes));
			while (comp != 1){
				graf_actual_arestes = RGG_generator(n_vertex, graella_size,r);
				comp = connect_graph(mat_to_list(graf_actual_arestes));
			}
			//cout << "Components connexes abans de percolació: " << comp << endl;
			//cout << endl;
			for(float prob=0.00; prob <= 1; prob+=0.025){
				cout << "Probabilitat: " << prob << endl;
				int comp_con = connect_graph(mat_to_list(percolacio_arestes(graf_actual_arestes, prob)));
				cout << "Components connexes despres de percolació: "  << comp_con << endl;
				cout << endl;
			}

		}
		cout << "Fi estudi autómatic R-Q" << endl;
	}

	//Estudi automàtic components-q
	else if(auto_r==1){
		srand(time(NULL));
		n_vertex= rand()%10000;
		cout << "Nombre de vèrtxs: " << n_vertex << endl;
		cout << endl;
		graella_size= 100; //Tamany pre-establert de graella
		cout << "Tamany de la graella: " << 10000 << endl;
		cout << endl;
		float r	=2*(10000/n_vertex);
		cout << "Threshold distancia de connexió de vertexs: " << r << endl;
		cout << endl;
		graf_actual_arestes = RGG_generator(n_vertex, graella_size,r);
		int comp = connect_graph(mat_to_list(graf_actual_arestes));
		while (comp != 1){
			cout << endl;
			graf_actual_arestes = RGG_generator(n_vertex, graella_size,r);
			comp = connect_graph(mat_to_list(graf_actual_arestes));
		}
		cout << "Components connexes abans de percolació: " << comp << endl;
		cout << endl;

		for(float prob=0.00; prob <= 1; prob+=0.025){
			cout << "Probabilitat: " << prob << endl;
			int comp_con = connect_graph(mat_to_list(percolacio_arestes(graf_actual_arestes, prob)));
			cout << "Components connexes despres de percolació: "  << comp_con << endl;
			cout << endl;
		}

		cout << "Fi de l'estudi automàtic componnents-q" << endl;
		cout << endl;
	}
	//Estudi manual
	else{
		cout << "Insertar mida de la graella(distribució dels vèrtexs per RGG): " << endl;
		cin >> graella_size;
		cout << endl;
		cout << "Nombre de vertexs a distribuir: (RECORDAR: nombre de vèrtexs <= 10000)" << endl;
		cin >> n_vertex;
		cout << endl;
		int thold= (graella_size*graella_size)/n_vertex;
		cout << "Threshold distancia de connexió de vertexs: (Minima: " << thold << ")" << endl;
		float r;
		cin >> r;
		cout << endl;
		char continue_using = 'Y';
		graf_actual_arestes = RGG_generator(n_vertex, graella_size,r);  // Generem el RGG com a Matriu d'adjacència
		while (continue_using == 'Y'){
			int comp = connect_graph(mat_to_list(graf_actual_arestes));
			while (comp != 1 and not r < thold){
				cout << endl;
				cout << "El graf creat no és connex, creant nou graf..." << endl;
				graf_actual_arestes = RGG_generator(n_vertex, graella_size,r);
				comp = connect_graph(mat_to_list(graf_actual_arestes));
			}
			cout << "Components connexes abans de percolació: " << comp << endl;
			cout << endl;
			cout << "Probabilitat percolacio: " << endl;
			float prob;
			cin >> prob;
			cout << endl;
			int comp_con = connect_graph(mat_to_list(percolacio_arestes(graf_actual_arestes, prob)));
			cout << "Components connexes despres de percolació: " << comp_con << endl;
			cout << endl;
			cout << "Utilitzar el mateix graf amb diferent percolacio ? (Y:seguir / N: canviar de graf)"  << endl;
			cin >> continue_using;
			cout << endl;

		}
	cout << "Fi de l'estudi manual." << endl;
	}
}


void graella (){
	int graella_size;
	char contin = 'Y';
	cout << "Indiqui el tamany de la graella:" << endl;
	cin >> graella_size;
	cout << endl;
	graf_actual_vertexs = square_generator(graella_size);
	graf_actual_arestes = list_to_mat(graf_actual_vertexs);
	while (contin == 'Y'){
		char tperc;
		cout << "Fer percolació per vèrtexs o per arestes? (V: vèrtexs / A: arestes)" << endl;
		cin >> tperc;
		cout << endl;
		int comp = connect_graph(graf_actual_vertexs);
		cout << "Components connexes abans de percolació: " << comp<< endl;
		float prob;
		cout << endl;
		if (tperc != 'A' and tperc != 'V'){
			cout << "Tipus de percolació invàlida." << endl;
			cout << endl;
		}
		else{
			cout << "Introduir la probabilitat manualment o fer-ho de forma automatitzada? (1:Automàtic 0:Manual)" << endl;
			int automatic;
			cin >> automatic;
			cout << endl;
			if(automatic== 0){
				cout << "Probabilitat percolacio: " << endl;
				cin >> prob;
				cout << endl;
			}
			//PERCOLACIÓ D'ARESTES (GRAELLA)
			if (tperc == 'A'){
				//showM(graf_actual_arestes, "MATRIU ADJ PRE PERCOLACIO ARESTES");
				//PERCOLACIÓ D'ARESTES MANUAL (GRAELLA)
				if (automatic== 0){
					int comp_con = connect_graph(mat_to_list(percolacio_arestes(graf_actual_arestes, prob)));
					cout << "Components connexes despres de percolació: " << comp_con << endl;
					cout << endl;
				}
				//PERCOLACIÓ D'ARESTES AUTOMATITZADA (GRAELLA)
				else{
					for(float prob=0.00; prob <= 1.00; prob+=0.025){
						cout << "Probabilitat: " << prob << endl;
						int comp_con = connect_graph(mat_to_list(percolacio_arestes(graf_actual_arestes, prob)));
						cout << "Components connexes despres de percolació: "  << comp_con << endl;
						cout << endl;
					}
				}
			}
			//PERCOLACIÓ DE VERTEXS (GRAELLA)
			else if (tperc == 'V'){
				//showL(graf_actual_vertexs, "LLISTA ADJ PRE PERCOLACIO NODES");
				//PERCOLACIÓ DE VERTEXS MANUAL (GRAELLA)
				if(automatic== 0){
					int comp_con = connect_graph(percolacio_nodes(graf_actual_vertexs, prob));
					cout << "Components connexes despres de percolació: " << comp_con << endl;
					cout << endl;
				}
				//PERCOLACIÓ DE VERTEXS AUTOMATITZADA (GRAELLA)
				else{
					for(float prob=0.00; prob <= 1.00; prob+=0.025){
						cout << "Probabilitat: " << prob << endl;
						int comp_con = connect_graph(percolacio_nodes(graf_actual_vertexs, prob));
						cout << "Components connexes despres de percolació: " << comp_con << endl;
						cout << endl;
					}
				}
			}

			cout << "Utilitzar el mateix graf amb diferent percolacio? (Y:seguir / N: canviar de graf)"  << endl;
			char aux;
			cin >> aux;
			cout << endl;
			contin = aux;
		}
	}
}



int main(){
	char tipus;
	cout << "Quin tipus de graf vols crear? (R: Random Geometric Graph / N: Graella)" << endl;
	cin >> tipus;
	cout << endl;
	if (tipus == 'R') random_geometric();
	else if (tipus == 'N') graella();
	else cout << "Tipus de graf no vàlid. Torna a introduir quin graf vols." << endl;
	cout << endl;
	main();
}
