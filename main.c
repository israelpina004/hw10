#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "poke.h"

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

    party = remove_member(party, pikachu, pik_hp, pik_pa, pik_sa, pik_df, pik_spdf, pik_spd);

    printf("After removing Pikachu from the party:\n\n");

    print_party(party);

    free_party(party);

    return 0;
}
