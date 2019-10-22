#include <iostream> 
#include <vector>
#include <climits>
#include <cstdlib>
#include <algorithm>

int tsp(int **matrix, int n)
{
	std::vector<int> vertex;
	for (int i = 1; i < n; i++) 
		vertex.push_back(i); 

	int min_path = INT_MAX; 
	do {

		int current_pathweight = 0, k = 0;
		for (int i = 0; i < vertex.size(); i++) { 
			current_pathweight += matrix[k][vertex[i]]; 
			k = vertex[i];
		} 
		current_pathweight += matrix[k][0];
 
		min_path = std::min(min_path, current_pathweight); 
		
	} while(std::next_permutation(vertex.begin(), vertex.end())); 

	return min_path; 
} 

int main() 
{
	int n, **matrix;
	std::cin >> n;

	// allocate memory for matrix
	matrix = (int**)malloc((n + 1) * sizeof(int*));
	for(int i = 0; i < n + 1; i++)
		matrix[i] = (int*)malloc((n + 1) * sizeof(int));

	// get input for matrix
	for(int i = 0; i < n + 1; i++)
		for(int j = 0; j < n + 1; j++)
			std::cin >> matrix[i][j];

	std::cout << tsp(matrix, n + 1);
	return 0; 
}

