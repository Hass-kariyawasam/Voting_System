#include <stdio.h>

//diclere functions

int main(); 
//compenents
int E_seperator();
int D_seperator();
int time_delay();
int long_delay();
void pressEnterToContinue();
void color(int t);
int A_delay();

//UI hass
int main_menu();

//admin login
int admin_loging(const char *user);

/* custom.h - common UI helpers and forward declarations */
#pragma once

#include <stdio.h>

int main();

/* components */
int E_seperator();
int D_seperator();
int time_delay();
int long_delay();
void pressEnterToContinue();
void color(int t);
int A_delay();

/* UI */
int main_menu();

/* admin login */
int admin_loging(const char *user);

/* admin */
int admin_panel();

/* PO */
int UI_PO();
int PO_open_polling();
int PO_close_polling();

/* Election Admin panel */
int UI_election_admin();
/* district registration */
int district_registration();
int add_new_district();
char add_district();
int display_all_districts();
/* party registration */
int party_registration();
char add_party();
int display_registerd_parties();
/* final result declaration */
int final_result_declaration();

/* party admin panel */
int UI_party_admin();
int submit_nomination();

/* returning officer panel */
int UI_returning_officer();
int accept_nomination_list();
int district_result_generation();
int review_nomination_list();

/* voter and candidate registration */
void voter_registration();
void candidate_registration();

/* polling */
int poling_Asccss();
char polling_login();
int votting_casting(char *logged_in_nic);

/* nomination list */
int public_nomination_list();

/* election results */
int election_results_menu();
int election_results_district_view();
int election_results_party_view();


//calculate HIMANSANA
/* calculate */
int party_calculate();
int candidate_calculate();

int UI_RO();
int UI_PARTY_ADMIN();
int party_agent_observer();






int display_candidate_results();
int display_party_results();
int display_seat_allocation();