#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char name[20];
  int votes;
} candidate;

typedef struct {
  char names[10][20];
} ballot;

int vote(candidate candidates[], int candidate_count,  int rank, char name[], ballot ballot);
int tabulate(candidate candidates[], int candidate_count, ballot ballots[], int ballot_count, int rank_count);
int find_min(candidate voter[], int candidate_count);
int is_tie (candidate voter[], int candidate_count, int min);


int main(int argc, char *argv[]){ 
  if (argc < 2) {
    return 0;
  }
  const int candidate_count = argc - 1;
  int number_of_ballots = 0;
  printf("Number of voters: ");
  scanf("%d", &number_of_ballots);
  getchar();
  printf("%i number of voters\n %i number of candidates\nCreating structs\n", number_of_ballots, candidate_count);
  
  candidate candidates[candidate_count];
  ballot ballots[number_of_ballots];
  printf("1st for loop\n");

  for (int i = 0; i < candidate_count; i++){
    strcpy(candidates[i].name, argv[i + 1]);
    candidates[i].votes = 0;
  }

  printf("2nd for loop\n");
  for (int i = 0; i < number_of_ballots; i++){
    int rank_count = 0;
    printf("Cast your votes: \n");

    for (int j = 0; j < candidate_count; j++){
      char name [20];
      printf("%i.", rank_count + 1);
      scanf("%s", name);
      getchar();
      vote(candidates, candidate_count, rank_count, name, ballots[i]);
      rank_count++;
      printf("\n");
    }
  }
  printf("%s",ballots[0].names[0]);

  printf("3rd for loop\n");
  for (int i = 0; i < number_of_ballots; i++){
    tabulate(candidates, candidate_count, ballots, number_of_ballots, i);
    find_min(candidates, candidate_count);
  }
    return 0;
}


int vote(candidate candidates[], int candidate_count,  int rank, char name[], ballot ballot) {
    for (int i = 0; i < candidate_count; i++){
      if (strcmp(candidates[i].name, name) == 0) {
        strcpy(ballot.names[rank], candidates[i].name);
        printf("%s",ballot.names[rank]);
        return true;
      }
    }
    return false;
}

int tabulate(candidate candidates[], int candidate_count, ballot ballots[], int ballot_count, int rank_count) {
  for (int i = 0; i < ballot_count; i++){
    for (int j = 0; j < candidate_count; j++){
      if (strcmp(ballots[i].names[rank_count], candidates[j].name) == 0) {
        candidates[j].votes++;
      } else {
        continue;
      }
    }
  }
  return 0;
}

bool print_winner(candidate voter[], int candidate_count, ballot ballots[], int ballot_count) {
  for (int i = 0; i < candidate_count; i++){
    if (voter[i].votes > ballot_count / 2) {
      printf("%s\n", voter[i].name);
      return true;
    }
  }
  return false;
}

int find_min(candidate candidates[], int candidate_count) {
  int index = 0;
  int lowest_votes = 0;
  for (int i = 1; i < candidate_count; i++){
    if (candidates[i].votes < candidates[index].votes) {
      index = i;
      lowest_votes = candidates[i].votes;
    } else {
      continue;
    }
  }
  return index;

}

int is_tie (candidate voter[], int candidate_count, int min) {
  int first_index = 0;
  for (int i = 0; i < candidate_count; i++){
    for (int j = i+1; j < candidate_count; j++){
      if (voter[i].votes == voter[j].votes) {
        return true;
      } else {
        continue;
      }
    }
  }
  return false;
}

int eliminate(candidate voter[], int candidate_count, ballot ballots[], int ballot_count) {
  candidate new_candidates[candidate_count - 1];
  int min = find_min(voter, candidate_count);
  for (int i = 0; i < candidate_count; i++){
    if (i == min) {
      continue;
    } else {
      strcpy(new_candidates[i].name, voter[i].name);
      new_candidates[i].votes = voter[i].votes;
    }
  }
  return 0;

}