#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct poke_party {
char poke[50];
int hp;
int pa;
int sa;
int df;
int spdf;
int spd;
struct poke_party *next;
};

void print_party(struct poke_party *party);

struct poke_party * insert_front(struct poke_party *party, char poke[50],
  int hp, int pa, int sa, int df, int spdf, int spd);

struct poke_party * free_party(struct poke_party *party);

void print_party(struct poke_party* party) {
  printf("Pokemon name: %s\n", party->poke);
  printf("\nBase Stats:\n");
  printf("HP: %d\nAttack: %d\nSpecial Attack: %d\n", party->hp, party->pa, party->sa);
  printf("Defense: %d\nSpecial Defense: %d\nSpeed: %d\n\n", party->df, party->spdf, party->spd);

  if (party->next != NULL) {
    print_party(party->next);
  }
}

struct poke_party * insert_front(struct poke_party *party, char name[50],
  int health, int attack, int sp_attack, int def, int spdef, int speed) {

  struct poke_party* member;
  member = malloc(sizeof(struct poke_party));

  strcpy(member->poke, name);
  member->hp = health;
  member->pa = attack;
  member->sa = sp_attack;
  member->df = def;
  member->spdf = spdef;
  member->spd = speed;

  member->next = party;

  return member;
}

struct poke_party * free_party(struct poke_party *party) {
  if (party->next != NULL) {
    free_party(party->next);
  }
  free(party);

  return party;
}

int main() {
    char charmander[50] = "Charmander";

    struct poke_party* party;

    srand(time(NULL));

    int char_hp = (rand() / 100000000) + 10;
    int char_pa = (rand() / 100000000) + 10;
    int char_sa = (rand() / 100000000) + 10;
    int char_df = (rand() / 100000000) + 10;
    int char_spdf = (rand() / 100000000) + 10;
    int char_spd = (rand() / 100000000) + 10;

    party = insert_front(party, charmander, char_hp, char_pa, char_sa, char_df, char_spdf, char_spd);

    char pikachu[50] = "Pikachu";

    int pik_hp = (rand() / 100000000) + 10;
    int pik_pa = (rand() / 100000000) + 10;
    int pik_sa = (rand() / 100000000) + 10;
    int pik_df = (rand() / 100000000) + 10;
    int pik_spdf = (rand() / 100000000) + 10;
    int pik_spd = (rand() / 100000000) + 10;

    party = insert_front(party, pikachu, pik_hp, pik_pa, pik_sa, pik_df, pik_spdf, pik_spd);

    print_party(party);

    free_party(party);

    return 0;
}
