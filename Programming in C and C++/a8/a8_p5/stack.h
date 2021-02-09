struct stack{
    unsigned int count;
    char container[30][30];      //container
};

struct stack* push(struct stack *pringles, char *chip);
struct stack* pop(struct stack *pringles);
struct stack* empty(struct stack *pringles);
struct stack* collect(struct stack *collector, char *sentence);