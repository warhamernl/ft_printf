#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <unistd.h>
#include <stdlib.h>

union test { 
	unsigned int x : 3; 
	unsigned int y : 3; 
	int z; 
}; 

int main() 
{ 
	union test t; 
	t.x = 5; 
	t.y = 4; 
	t.z = 1; 
	printf("t.x = %d, t.y = %d, t.z = %d", 
		t.x, t.y, t.z); 
	return 0; 
} 
