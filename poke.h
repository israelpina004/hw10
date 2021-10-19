void print_party(struct poke_party* party);

struct poke_party * insert_front(struct poke_party *party, char name[50],
  int health, int attack, int sp_attack, int def, int spdef, int speed);

struct poke_party * free_party(struct poke_party *party);

struct poke_party* remove_member(struct poke_party *party, char name[50],
int health, int attack, int sp_attack, int def, int spdef, int speed);
