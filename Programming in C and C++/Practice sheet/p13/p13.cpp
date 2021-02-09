#include <stdio.h>
#include <stdlib.h>

struct coffee{
    int id;
    char property;
};

void set_coffee_property(struct coffee* c, const signed char property){
    c->property = c->property | property; 
}

void unset_coffee_property(struct coffee* c, const signed char property){
    char toggled = property^127; // use XOR 
    c->property &= toggled;
}

int main(){
    struct coffee* cup = (struct coffee*) malloc(sizeof(struct coffee));
    cup->id = 0;
    set_coffee_property(cup, (char) 1 << 0);
    printf("%c \n",cup->property);
    set_coffee_property(cup, (char) 1 << 6);
    printf("%c \n",cup->property);
    set_coffee_property(cup, (char) 1 << 3);
    printf("%c \n",cup->property);
    unset_coffee_property(cup, (char) 1 << 0);
    unset_coffee_property(cup, (char) 1 << 6);
    unset_coffee_property(cup, (char) 1 << 3);
    free(cup);
    return 0;
}