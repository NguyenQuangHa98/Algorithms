#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int rows, cols, min = INT_MAX;

void min_steps_to_escape(int **maze, int x, int y, int num);
int is_outbound(int x, int y);

int main()
{
	int i, j, start_row, start_col, **maze;

	/* get input */
	scanf("%d %d %d %d", &rows, &cols, &start_row, &start_col);
	maze = (int**)malloc(rows * sizeof(int*));
	for(i = 0; i < rows; i++)
		maze[i] = (int*)malloc(cols * sizeof(int));
	for(i = 0; i < rows; i++)
		for(j = 0; j < cols; j++)
			scanf("%d", &maze[i][j]);
	
	/* find minimum steps to escape from the maze */
	min_steps_to_escape(maze, start_row - 1, start_col - 1, -1);
	if(INT_MAX == min)
		printf("-1");
	else
		printf("%d", min);

	for(i = 0; i < rows; i++)
		free(maze[i]);

	free(maze);
	return 0;
}

void min_steps_to_escape(int **maze, int x, int y, int num)
{
	num++;
	/* if current step number over min, don't go on */
	if(num >= min)
		return;

	/* if current element is outbound, update min then backtrack */
	if(1 == is_outbound(x, y))
	{
		min = num < min ? num : min;
		return;
	}

	/* if current element is an obstacle then backtrack */
	if(1 == maze[x][y])
		return;

	/* mark current element to 1 temporarily to prevent go loop */
	maze[x][y] = 1;
	
	/* continue go to other directions to find outbound */
	min_steps_to_escape(maze, x + 1, y, num);
	min_steps_to_escape(maze, x, y + 1, num);
	min_steps_to_escape(maze, x - 1, y, num);
	min_steps_to_escape(maze, x, y - 1, num);

	/* unmark when visited done */
	maze[x][y] = 0;
	return;
}

int is_outbound(int x, int y)
{
	if(x < 0 || x >= rows || y < 0 || y >= cols)
		return 1;
	return 0;
}
