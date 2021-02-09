struct list{
    int value;
    struct list *next;
};
struct list* addfirst(struct list *p, int n);
struct list * addlast(struct list *p, int n);
void removelist(struct list *p);
struct list* removefirst(struct list *p);
void printlist(struct list *p);

