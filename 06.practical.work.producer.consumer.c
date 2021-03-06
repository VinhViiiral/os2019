#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE (10)

typedef struct { 
	char type;
	int amount;
	char unit;
}item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i){
	while ((first + 1) % BUFFER_SIZE == last){
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}


item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}
int main(){
	item n1, n2;
	item *csitem = consume();
	n1.type = '0';
	n1.amount = '5';
	n1.unit = '0';
	printf("First: %c,%d,%c",n1.type,n1.amount,n1.unit);
	n2.type = '1';
  	n2.amount = 100;
  	n2.unit = '1';
  	printf("Second: %c, %d, %c\n", n2.type, n2.amount, n2.unit);
  	printf ("first=%d, last=%d\n",first,last);
	produce(&n1);
	printf("Produce first item: %c,%d,%c\nfirst=%d\nlast=%d\n",n1.type,n1.amount,n1.unit,first,last);
	produce(&n2);
	printf("Produce second item: %c,%d,%c\nfirst=%d\nlast=%d\n",n2.type,n2.amount,n2.unit,first,last);
	printf("Consumed item: %c, %d, %c\nfirst = %d\n last=%d\n\n", csitem->type, csitem->amount, csitem->unit, first, last);
	return 0;
}
