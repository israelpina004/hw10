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

struct poke_party* remove_member(struct poke_party *party, char name[50],
int health, int attack, int sp_attack, int def, int spdef, int speed) {
  if (strcmp(party->poke, name) == 0) {
    if (party->hp == health) {
      if (party->pa == attack) {
        if (party->sa == sp_attack) {
          if (party->df == def) {
            if (party->spdf == spdef) {
              if (party->spd == speed) {
                party = party->next;
                return party;
              }
            }
          }
        }
      }
    }
  }
  if (party->next != NULL) {
      remove_member(party->next, name, health, attack, sp_attack, def,
        spdef, speed);
  }
  return party;
}
