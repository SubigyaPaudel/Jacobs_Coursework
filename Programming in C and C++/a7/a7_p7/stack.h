struct stack{
    unsigned int count;
    int container[12];      //container
};

struct stack* push(struct stack *pringles, int chip);
struct stack* pop(struct stack *pringles);
struct stack* empty(struct stack *pringles);



