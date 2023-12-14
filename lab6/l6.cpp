#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <locale.h>
#include <algorithm>

using namespace std;

int swt = 0;



//Отождествление (замыкание) вершин
void otojestvlenie(vector < vector < int>> G, vector < vector < int>> List) {
	int v1, v2;
	vector < vector < int>> r_G;
	vector < vector < int>> r_L;
	printf("введите вершину 1 вершину для отождествления: \n");
	scanf_s("%d", &v1);
	printf("введите вершину 2 вершину для отождествления: \n");
	scanf_s("%d", &v2);
	printf("\n");
	
	r_G = G;
	r_L = List;

	int n = r_G.size();

	
	for (int i = 0; i < n; ++i) {
		if (r_G[v2][i]) {
			r_G[v1][i] = 1;
			r_G[i][v1] = 1;
		}
		r_G[v2][i] = 0;
		r_G[i][v2] = 0;
	}


	
	for (int neighbor : r_L[v2]) {
		if (find(r_L[v1].begin(), r_L[v1].end(), neighbor) == r_L[v1].end() && neighbor != v1) {
			r_L[v1].push_back(neighbor);
		}
	}
	r_G.erase(r_G.begin() + v2);
	for (auto &row : r_G) {
		row.erase(row.begin() + v2);
	}

	for (auto& neighbors : r_L) {
		auto it = remove(neighbors.begin(), neighbors.end(), v2);
		neighbors.erase(it, neighbors.end());
		for (auto& neighbor : neighbors) {
			if (neighbor > v2) {
				--neighbor;
			}
		}
	}

	

	
	r_L.erase(r_L.begin() + v2);

	printf("Матрица с отождествленными вершинами:\n");
	for (int i = 1; i < r_G.size(); ++i) {
		for (int j = 1; j < r_G[i].size(); ++j) {
			printf("%d ", r_G[i][j]);
		}
		printf("\n");
	}

	printf("Список смежности 2:\n");
	for (int i = 1; i < r_L.size(); ++i) {
		printf("%d: ", i);
		for (int j : r_L[i]) {
			printf("%d ", j);
		}
		printf("\n");
	}
	
}

//стягивание
void stiagivanie(vector<vector<int>>G,vector<vector<int>>List){
int v1, v2;
vector < vector < int>> r_G;
vector < vector < int>> r_L;
printf("введите вершину 1 вершину для стягивания: \n");
scanf_s("%d", &v1);
printf("введите вершину 2 вершину для стягивания: \n");
scanf_s("%d", &v2);
printf("\n");
r_G = G;
r_L = List;

	int n = r_G.size();

	
	if (!r_G[v1][v2] && !r_G[v2][v1]) {
		printf("Стягивание осуществить нельзя!\n");
		for (int i = 1; i < G.size(); ++i) {
			for (int j = 1; j < G[i].size(); ++j) {
				printf("%d ", G[i][j]);
			}
			printf("\n");
		}

		printf("Список смежности:\n");
		for (int i = 1; i < r_L.size(); ++i) {
			printf("%d: ", i);
			for (int j : r_L[i]) {
				printf("%d ", j);
			}
			printf("\n");
		}
		return;
	}

	
	for (int i = 0; i < n; ++i) {
		if (r_G[v2][i]) {
			r_G[v1][i] = 1;
			r_G[i][v1] = 1;
		}
		r_G[v2][i] = 0;
		r_G[i][v2] = 0;
	}
	r_G[v1][v1] = 0;

	// Объединение списков смежности
	for (int neighbor : r_L[v2]) {
		if (find(r_L[v1].begin(), r_L[v1].end(), neighbor) == r_L[v1].end() && neighbor != v1) {
			r_L[v1].push_back(neighbor);
		}
	}

	
	for (auto& neighbors : r_L) {
		auto it = remove(neighbors.begin(), neighbors.end(), v2);
		neighbors.erase(it, neighbors.end());
		for (auto& neighbor : neighbors) {
			if (neighbor > v2) {
				--neighbor;
			}
		}
	}


	r_G.erase(r_G.begin() + v2);
	for (auto& row : r_G) {
		row.erase(row.begin() + v2);
	}

	

	r_L.erase(r_L.begin() + v2);

	printf("Матрица со стянутым ребром:\n");
	for (int i = 1; i < r_G.size(); ++i) {
		for (int j = 1; j < r_G[i].size(); ++j) {
			printf("%d ", r_G[i][j]);
		}
		printf("\n");
	}

	printf("Список смежности 2:\n");
	for (int i = 1; i < r_L.size(); ++i) {
		printf("%d: ", i);
		for (int j : r_L[i]) {
			printf("%d ", j);
		}
		printf("\n");
	}
}



vector<vector<int>> list_cmej(vector<vector<int>> G) {
	int num_vertices = G.size() - 1;
	vector<vector<int>> adjacency_list(num_vertices + 1);
	for (int i = 1; i <= num_vertices; ++i) {
		for (int j = 1; j <= num_vertices; ++j) {
			if (G[i][j] == 1) {
				adjacency_list[i].push_back(j);
			}
		}
	}
	return adjacency_list;
}

void printList(vector<vector<int>>list) {
	printf("Список смежности:\n");
	for (int i = 1; i < list.size(); ++i) {
		printf("%d: ", i);
		for (int j : list[i]) {
			printf("%d ", j);
		}
		printf("\n");
	}
}

vector<vector<int>> list_cmej2(vector<vector<int>> G2) {
	int num_vertices = G2.size() - 1;
	vector<vector<int>> adjacency_list2(num_vertices + 1);
	for (int i = 1; i <= num_vertices; ++i) {
		for (int j = 1; j <= num_vertices; ++j) {
			if (G2[i][j] == 1) {
				adjacency_list2[i].push_back(j);
			}
		}
	}
	return adjacency_list2;
}

void printList2(vector<vector<int>>list2) {
	printf("Список смежности 2:\n");
	for (int i = 1; i < list2.size(); ++i) {
		printf("%d: ", i);
		for (int j : list2[i]) {
			printf("%d ", j);
		}
		printf("\n");
	}
}


//int swt = 0;
vector<vector<int>> cmej_mat(int num_vertices, double veroj) {
	vector<vector<int>> cmej_mat(num_vertices + 1, vector<int>(num_vertices + 1, 0));
	int cont = 0;
	for (int i = 1; i <= num_vertices; ++i) {
		for (int j = i + 1; j <= num_vertices; ++j) {
			if (static_cast<double>(rand()) / RAND_MAX < veroj) {
				cmej_mat[i][j] = 1;
				cmej_mat[j][i] = 1;
				cont++;
			}
		}
	}

	if (cont == 0) {
		swt = 1;
	}
	printf("Матрица смежности:\n");
	for (int i = 1; i <= num_vertices; ++i) {
		for (int j = 1; j <= num_vertices; ++j) {
			printf("%d ", cmej_mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return cmej_mat;
}

//int swt = 0;
vector<vector<int>> cmej_mat2(int num_vertices2, double veroj) {
	vector<vector<int>> cmej_matr2(num_vertices2 + 1, vector<int>(num_vertices2 + 1, 0));
	int cont = 0;
	for (int i = 1; i <= num_vertices2; ++i) {
		for (int j = i + 1; j <= num_vertices2; ++j) {
			if (static_cast<double>(rand()) / RAND_MAX < veroj) {
				cmej_matr2[i][j] = 1;
				cmej_matr2[j][i] = 1;
				cont++;
			}
		}
	}

	if (cont == 0) {
		swt = 1;
	}
	printf("Матрица смежности 2:\n");
	for (int i = 1; i <= num_vertices2; ++i) {
		for (int j = 1; j <= num_vertices2; ++j) {
			printf("%d ", cmej_matr2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return cmej_matr2;
}

void splitVertex(vector < vector < int>> G, vector < vector < int>>List) {
	int v1;

	vector < vector < int>> r_G;
	vector < vector < int>> r_L;
	printf("введите вершину для расщепления: \n");
	scanf_s("%d", &v1);
	printf("\n");

	int n = G.size();

	
	r_G.resize(n + 1, vector<int>(n + 1, 0));
	r_L.resize(n + 1);

	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			r_G[i][j] = G[i][j];
		}
		r_L[i] = List[i];
	}

	for (int i = 0; i < n; ++i) {
		r_G[i][n] = G[i][v1];
		r_G[n][i] = G[v1][i];
	}

	for (int i = 0; i < n; ++i) {
		if (i != v1) {
			r_L[i].push_back(n);
		}
	}

	
	for (int i = 0; i < List[v1].size(); ++i) {
		r_L[n].push_back(List[v1][i]);
	}

	printf("Матрица :\n");
	for (int i = 1; i < r_G.size(); ++i) {
		for (int j = 1; j < r_G[i].size(); ++j) {
			printf("%d ", r_G[i][j]);
		}
		printf("\n");
	}

	printf("Список смежности 2:\n");
	for (int i = 1; i < r_L.size(); ++i) {
		printf("%d: ", i);
		for (int j : r_L[i]) {
			printf("%d ", j);
		}
		printf("\n");
	}
}

void mergeGraphs(vector < vector < int>>G1, const vector < vector < int>>G2) {
	int razm = max(G1.size(), G2.size());

	
	vector < vector < int>> r_G(razm, vector<int>(razm, 0));

	
	for (int i = 0; i < G1.size(); ++i) {
		for (int j = 0; j < G1[i].size(); ++j) {
			r_G[i][j] =G1[i][j];
		}
	}

	
	for (int i = 0; i < G2.size(); ++i) {
		for (int j = 0; j < G2[i].size(); ++j) {
			if (G2[i][j] > 0) {
				r_G[i][j] = G2[i][j];
			}
		}
	}

	printf("Матрица :\n");
	for (int i = 1; i < r_G.size(); ++i) {
		for (int j = 1; j < r_G[i].size(); ++j) {
			printf("%d ", r_G[i][j]);
		}
		printf("\n");
	}

	
}

void intersectGraphs( vector < vector < int>> G1,vector < vector < int>>G2) {
	int size = min(G1.size(), G2.size());
	vector < vector < int>> G3(size, vector<int>(size, 0));

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			
			G3[i][j] = (G1[i][j] and G2[i][j]);
		}
	}

	printf("Матрица :\n");
	for (int i = 1; i < G3.size(); ++i) {
		for (int j = 1; j < G3[i].size(); ++j) {
			printf("%d ", G3[i][j]);
		}
		printf("\n");
	}
}

void adaptiveRingSumGraphs(vector < vector < int>> G1, vector < vector < int>>G2) {
	int razm = max(G1.size(), G2.size());
	vector < vector < int>>G3(razm, vector<int>(razm, 0));

	for (int i = 0; i < razm; ++i) {
		for (int j = 0; j < razm; ++j) {
			int val1 = (i < G1.size() && j < G1.size()) ? G1[i][j] : 0;
			int val2 = (i < G2.size() && j < G2.size()) ? G2[i][j] : 0;
			G3[i][j] = val1 != val2;
		}
	}
	printf("Матрица :\n");
	for (int i = 1; i < G3.size(); ++i) {
		for (int j = 1; j < G3[i].size(); ++j) {
			printf("%d ", G3[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}

void cartesianProductGraphs(vector < vector < int>> G1, vector < vector < int>>G2) {
	int n1 = G1.size() - 1; 
	int n2 = G2.size() - 1;
	int razm = n1 * n2;
	vector < vector < int>> G3(razm + 1, vector<int>(razm+ 1, 0));

	for (int i1 = 1; i1 <= n1; ++i1) {
		for (int i2 = 1; i2 <= n2; ++i2) {
			for (int j1 = 1; j1 <= n1; ++j1) {
				for (int j2 = 1; j2 <= n2; ++j2) {
					int v1 = (i1 - 1) * n2 + i2; 
					int v2 = (j1 - 1) * n2 + j2;
					if (i1 == j1 && G2[i2][j2]) {
						G3[v1][v2] = 1;
					}
					if (i2 == j2 && G1[i1][j1]) {
						G3[v1][v2] = 1;
					}
				}
			}
		}
	}

	printf("Матрица :\n");
	for (int i = 1; i < G3.size(); ++i) {
		for (int j = 1; j < G3[i].size(); ++j) {
			printf("%d ", G3[i][j]);
		}
		printf("\n");
	}
}


int main() {
	setlocale(LC_ALL, "RUS");
	int num_vertices;
	int num_vertices2;
	double veroj = 0.5;
	int s;
	int p;

	srand(static_cast<unsigned int>(time(nullptr)));
	printf("Введите количество вершин: ");
	scanf("%d", &num_vertices);
	printf("Введите количество вершин 2: ");
	scanf("%d", &num_vertices2);
	auto G = cmej_mat(num_vertices, veroj);
	auto G2 = cmej_mat2(num_vertices2, veroj);
	auto list = list_cmej(G);
	auto list2 = list_cmej2(G2);
	printList(list);
	printList2(list2);
	vector < vector < int>> matrix1, matrix2, matrixCopy;
	vector < vector < int>> lis1, lis2, lisCopy;
	while (true) {
		printf("Выберите операцию:\n 1- отождествление первой матрицы\n 2-стягивание первой матрицы\n 3-расщеплению вершин\n 4-объединение\n 5-пересечение\n 6-кольцевая сумма\n 7-декардовое произведение\n 8-выход\n");
		if(scanf("%d", &p) != 1) {
			printf("Ошибка: ожидался ввод числа.\n");
			while (getchar() != '\n'); // Очистка ввода
			continue;
		}
		
		switch (p) {
		case 1: {

			otojestvlenie(G, list);
			break;
		}
		case 2: {

			stiagivanie(G, list);
			break;
		}
		case 3: {
			splitVertex(G, list);
			break;
		}
		case 4: {

			mergeGraphs(G, G2);
			break;
		}
		case 5: {
			intersectGraphs(G, G2);
			break;
		}
		case 6: {
			adaptiveRingSumGraphs(G, G2);
			break;
		}
		case 7: {
			cartesianProductGraphs(G, G2);
			break;
		}
			 // if (p == 8) {
				//  break;
			  //}



			  return 0;
		}
	}

}