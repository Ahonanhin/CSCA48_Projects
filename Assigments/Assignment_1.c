/*
 *  CSC A48 - Winter 2022 - Assignment 1 starter
 * 
 *  (c) 2020-22 Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 *
 *  
 */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{    
    char name[MAX_STR_LEN]; //String, len 1024 cast member
    float salary; //Float, cast member salary
    struct castList_struct *next; // Pointer, to make a linked list 
} CastList;


typedef struct movieReview_struct
{
    char movie_title[MAX_STR_LEN]; //string, len 1024, name says it all
    char movie_studio[MAX_STR_LEN]; // string, len 1024, name says it all
    int year; // year value (between 1920 and 2999)
    float BO_total; // Box Office Total, float
    int score; //integer value (1-100)
    CastList *cast; //pointer that directs to the cast members in the movie
     
} MovieReview;

typedef struct reviewNode_struct
{
    MovieReview review;//Stores data type Movie
    struct reviewNode_struct *next; //Points to the next node of the list
    
} ReviewNode;

typedef struct actors_list{ //new data type to go through the CastList
    char actorName[MAX_STR_LEN];//Name of the actor
    float avg_earnings;//Avg earnings of actor's movies (TOTAL EARNINGS - #Movies)
    struct actors_list *next;//node pointing to the next actor
}ActorsNodes;;



ActorsNodes *newActor(){//Allocates memory to a Cast member and initializes the "boxes"
    ActorsNodes *new = (ActorsNodes *)calloc(1,sizeof(ActorsNodes)); //creates memory
    strcpy(new->actorName,"");//empties it
    new->avg_earnings = 0.0;//empties earnings
    new->next =  NULL;//pointing to nothing
    return new;
}

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  scoreList = NULL;
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_node=NULL; //creates a new node null;

    new_node = (ReviewNode *)calloc(1, sizeof(ReviewNode)); //Allocates memory to the ndoe

    // Empties the string boxes
    strcpy(new_node->review.movie_title,"");
    strcpy(new_node->review.movie_studio, "");

    //Initializes digits
    new_node->review.year = -1;
    new_node->review.BO_total = -1;
    new_node->review.score = -1;

    //initializez pointer
    new_node->review.cast = NULL;

    new_node->next = NULL; //next pointer points to NULL;

    return new_node;    
}

CastList *newCastList(){

    CastList *new = (CastList *)calloc(1,sizeof(CastList));//Allocates space for the new node

   // Initializes values
    strcpy(new->name,"");
    new->salary = -1;
    new->next = NULL; // Next pointer points to nothing

    return new;
}


ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * The movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *traversal_p = NULL;
    traversal_p = head;//pointer used to traverse the list

    while(traversal_p != NULL){

        //checking if the title, studio and year of the movie have a match in the list;
        if (strcmp(traversal_p->review.movie_title, title) == 0 \
        && strcmp(traversal_p->review.movie_studio, studio) == 0 \
        && traversal_p->review.year == year){
            return traversal_p; // returns the node of the matching data type
        }
        traversal_p = traversal_p->next;
    }
    
    return NULL;  //there is no matching data in the list;
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    //creating the node to contain the movie data
    ReviewNode *new_node = NULL;
    new_node = head;
    
    if (new_node == NULL){//if list is empty
        
        new_node = newMovieReviewNode(); //creates space

        //copies the data
        new_node->review.year = year; 

        strcpy(new_node->review.movie_title, title);
        strcpy(new_node->review.movie_studio ,studio);
        new_node->review.BO_total= BO_total;
        new_node->review.score = score;
        new_node->next = NULL;

        return new_node;//returns the node
    }
    
    while(new_node !=NULL){//list is not empty
        if (strcmp(new_node-> review.movie_title, title) == 0 && strcmp(new_node-> review.movie_studio, studio)==0 && new_node->review.year == year){
            printf("The movie is already in the Database\n"); //movie is already in the list
            return head; //returns 1st pointer
        }
        new_node = new_node->next; //iterate through every movie
    }

    new_node = newMovieReviewNode(); //allocates memory

    //copies the data
    strcpy(new_node->review.movie_title, title);
    strcpy(new_node->review.movie_studio , studio);
    new_node->review.year = year;
    new_node->review.BO_total = BO_total;
    new_node->review.score = score;
    new_node->next = head;

    return new_node; // returns the node
    
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the number of reviews. 
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    int count  = 0; //creates counter
    ReviewNode *traversal_p = head;// creates the traversal pointer

    while (traversal_p != NULL){
        count++;//add to the counter for each new review
        traversal_p =traversal_p->next;
    }

    return count;   
} 

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists in the database"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    ReviewNode *traversal_p = head;// creates traversal pointer

    while (traversal_p != NULL){
        
        //checks if movie data matches what is in the list
        if(strcmp(traversal_p->review.movie_title, title) == 0 && \
        strcmp(traversal_p->review.movie_studio, studio) == 0 \
        && traversal_p->review.year == year){// it does

            traversal_p->review.BO_total = BO_total; //update box office total
            traversal_p->review.score = score; //update score
            return;
        }
        traversal_p = traversal_p->next; //iterates
    }
    printf("Sorry, no such movie exists in the Database"); //means no movie was found with the description
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    // creates pointers for the previous and actual pointers
    ReviewNode *previous_p = NULL; 
    ReviewNode *traversal_p = NULL;
    
    // assigns pointers to their "values"
    previous_p = head;
    traversal_p = previous_p->next;

    if (head == NULL) return NULL; //empty list

    // for head pointer
    if(strcmp(head->review.movie_title, title) == 0 \
    && strcmp(head->review.movie_studio, studio) == 0 \
    && head->review.year == year){
        free(previous_p);//remove previous pointer
        return traversal_p; // return next pointer
    }

    // for any other
    while(traversal_p != NULL){ // Until the list is empty

        // Checks conditions
        if(strcmp(traversal_p->review.movie_title, title) == 0 \
        && strcmp(traversal_p->review.movie_studio, studio) == 0 \
        && traversal_p->review.year == year){ //It passed

            previous_p->next = traversal_p->next; //the tail of the previous pointer 
            //jumps to the tail of the pointer to remose
            free(traversal_p);
            break;// we deleted it , leave the loop
        }
         
        //going through the loop
        traversal_p = traversal_p->next;
        previous_p = previous_p->next;
    }
    return head; //returns the head pointer
}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     * 
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *traversal_p = head;
    float count = 0.0; // for the box office total
    
    while(traversal_p != NULL){//not empty

        //PRINT!!!
        printf("%s\n",traversal_p->review.movie_title);
        printf("%s\n",traversal_p->review.movie_studio);
        printf("%d\n",traversal_p->review.year);
        printf("%f\n",traversal_p->review.BO_total);
        count += traversal_p->review.BO_total;
        printf("%d\n",traversal_p->review.score);
        printf("*******************\n");

        traversal_p = traversal_p->next;//no infinite loop
    }
        
    return count;           
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  

    float total_count = 0.0;
    ReviewNode *traversal_p = head;

    while(traversal_p != NULL){//not empty

        if(strcmp(traversal_p->review.movie_studio, studio) == 0){//looks for reviews with a matching studio

            //PRINTS
            printf("%s\n",traversal_p->review.movie_title);
            printf("%s\n",traversal_p->review.movie_studio);
            printf("%d\n",traversal_p->review.year);
            printf("%f\n",traversal_p->review.BO_total);
            printf("%d\n",traversal_p->review.score);
            total_count += traversal_p->review.BO_total;
            printf("*******************\n");

        }
        traversal_p = traversal_p->next;
    }
    return total_count;      
}

float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  

    //same concept as queryByStudio, but with the min score
    float total_count = 0.0;
    ReviewNode *traversal_p = head;

    while(traversal_p != NULL){
        if(traversal_p->review.score >= min_score){ // greater than or equal
            printf("%s\n",traversal_p->review.movie_title);
            printf("%s\n",traversal_p->review.movie_studio);
            printf("%d\n",traversal_p->review.year);
            printf("%f\n",traversal_p->review.BO_total);
            printf("%d\n",traversal_p->review.score);
            printf("*******************\n");
            total_count += traversal_p->review.BO_total;
        }
        traversal_p = traversal_p->next;
    }
    return total_count;
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    
    //Kinda like deleteMovieRevies

    ReviewNode *second_p = NULL, *traversal_p = NULL;//Creates the pointers

    //assigns the pointers
    traversal_p = head;
    second_p = traversal_p->next;

    while(traversal_p != NULL){ //list not empty, list is never empty

        second_p = traversal_p->next; // move to next node
        free(traversal_p), traversal_p = second_p; // erase previous node
    }
    return NULL;
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */ 

void insert_at_head (ReviewNode *head, ReviewNode *to_insert){
  
  //switching titles
  char temp_title[MAX_STR_LEN];
  strcpy(temp_title,head->review.movie_title);
  strcpy(head->review.movie_title,to_insert->review.movie_title);
  strcpy(to_insert->review.movie_title, temp_title);

  //switching studios
  char temp_studio[MAX_STR_LEN];
  strcpy(temp_studio,head->review.movie_studio);
  strcpy(head->review.movie_studio,to_insert->review.movie_studio);
  strcpy(to_insert->review.movie_studio, temp_studio);

  //switching years
  int temp_year;
  temp_year = head->review.year;
  head->review.year = to_insert->review.year;
  to_insert->review.year = temp_year;

  //switching BO_total
  int temp_BO;
  temp_BO = head->review.BO_total;
  head->review.BO_total = to_insert->review.BO_total;
  to_insert->review.BO_total = temp_BO; 

  //switching scores
  int temp_score;
  temp_score = head->review.score;
  head->review.score = to_insert->review.score;
  to_insert->review.score = temp_score;

  //switching cast lists
  CastList *temp_list =NULL;
  temp_list = newCastList();
  strcpy(temp_list->name,"");
  temp_list->salary = -1.0;
  temp_list->next = NULL;
  temp_list = head->review.cast;
  head->review.cast = to_insert->review.cast;
  to_insert->review.cast = temp_list;
  // return to_insert;
}

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    
    //Bubble sorting with replacing titles, keepind pointers

    //creating traversal pointers for the strings to compare
    ReviewNode *traversal_p = head;
    ReviewNode *next_p =NULL;


  while(traversal_p->next != NULL){//list is not empty

    next_p = traversal_p->next; //the title to be compared is next_p, compared to every other title in the list 
    while(next_p != NULL){

      if(strcmp(next_p->review.movie_title,traversal_p->review.movie_title)<0){//bubble sorting
        
        insert_at_head(traversal_p, next_p);//goes to the top

      }
      next_p=next_p->next;// changes to the next;
    }
    traversal_p = traversal_p->next;//no infinite loops
  }
    return head;  //returns the same pointer, but with a (possibly) updated content;
}

//Helper functions
ReviewNode *findMovie(ReviewNode *head, char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year){
    /* takes in a pointer to a review list, a movie title, studio and year. Finds the pointer
    to that movie, and returns it*/
   
   //creating pointers and assigning values;
    ReviewNode *traversal_p = head;

    
    while(traversal_p !=NULL){// List is not empty

        //Finds the node of the right movie where to add cast members;
        if (strcmp(traversal_p->review.movie_title, title) == 0 \
        && strcmp(traversal_p->review.movie_studio, studio) ==0 \
        && traversal_p->review.year == year){
            return traversal_p;//returns that node.
        }
        traversal_p = traversal_p->next;//no infinite loop
    }
    return NULL;
}

CastList *make_cast_list(char name[MAX_STR_LEN], float salary){
    /*creates a cast list with the name and salary of an actor
    and returns the pointer at which it is stored*/

    CastList *new = newCastList();//creates the node

    strcpy(new->name,name);
    new->salary = salary;
    new->next = NULL;

    return new;
}

void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
  /*
   * This function inserts the name of a cast member for the given movie into the
   * linked list of cast members. The new cast member must go to the end of the list.
   * 
   * Duplicate names are allowed - this time! 
   * 
   * Notice the function receives the title, studio, and year for the movie, as
   * well as a pointer to the movie DB linked list. The function must find the 
   * correct movie and if such a movie exists, add the cast member's name to its
   * cast list.
   * 
   * If no such movie is found, this function does nothing.
   * 
   * You're free to add helper functions to insert the cast member's name
   * into the cast list.
   */   

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  

    ReviewNode *traversal_p = findMovie(head, title, studio, year);

    CastList *castMember = make_cast_list(name,salary);//creates space
    
   if (traversal_p->review.cast ==NULL){//cast list is originally empty

       traversal_p->review.cast = castMember;//assigns cast data type to top of cast list
       return;//and we're done

   }//otherwise,

   CastList *traversal_cast = traversal_p->review.cast;//create a traversal 

   while(traversal_cast ->next != NULL){//while what comes next is not empty (segmentation error)

       traversal_cast = traversal_cast->next;//we just go through it

   }//traversal_cast->next is  for sure empty at this point

   traversal_cast->next = castMember;//assign cast data type to the END of the list
}


float earnings(ReviewNode *head, char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year){
    /* find the earnings (Box office total -  Salary total)*/
    
    //finds where the movie in question is
    ReviewNode *traversal_e = findMovie(head, title, studio, year);

    float count = 0;
    float gains = traversal_e->review.BO_total;
    CastList *traversal_c = traversal_e->review.cast;
    while (traversal_c != NULL){
        count+= traversal_c->salary; //adds salaries

        traversal_c = traversal_c->next;//moves to the next
    }
    float earned = gains - count; // earnings
    return earned;//returns earnings
}

float avg_earnings(ReviewNode *head, char actor[MAX_STR_LEN]){
    /* finds the earnings for each actor divided by the number of movies*/

   ReviewNode *traversal = NULL;
   traversal = head;
   int count = 0.0;

   CastList *second = NULL;
   float total_earnings = 0.0;
    while (traversal != NULL){ //list not empty, goes through each movie

        second = traversal->review.cast; //becomes cast list
        while (second != NULL){

        if (strcmp(actor,second->name) == 0){ // actor in the cast list
         //add movie earnings
                total_earnings += earnings(traversal, traversal->review.movie_title,\
                 traversal->review.movie_studio, traversal->review.year);
                 count++; // count #movies
        }
        
        second = second->next; //no infinite loop
        }
    traversal = traversal->next;//no infinite loop
    }
    
    return total_earnings / count; //returns the quotient
}

ActorsNodes *populate(ReviewNode *head){
    /* fills new data structure with each actor and their average earnings*/

    //create traversal pointers
    ReviewNode *traversal = head;
    ReviewNode *l  = head; 

    //creates new list  of actors
    ActorsNodes *inside_trav = newActor();
    ActorsNodes *to_return = inside_trav;//traversal, and head, to return head
    CastList *second = NULL;
    // if (traversal == NULL){
    //     return NULL;
    // }

    while (traversal != NULL){// not empty

        second = traversal->review.cast; //moves to cast list

        while(second != NULL){//
            strcpy(inside_trav->actorName,second->name); //copies name ot the actor
            char temp[MAX_STR_LEN];    //only worked with temp and food, dk why
            strcpy(temp,second->name);
            float food = avg_earnings(l, temp);
            inside_trav->avg_earnings = food;//this is food
            inside_trav->next = newActor();//makes sure mext node is not empty
            inside_trav = inside_trav->next; //on to the next
            second = second->next;//on to the next
        }
        traversal = traversal->next;//no infinite loop
    }
    return to_return;

}

void whosTheStar(ReviewNode *head)
{
  /*
   *  This function goes through the movie database and determines who is
   * the cast members whose movies have the greatest average earnings.
   *
   * Earnings are defined as the box office total minus the salaries of all
   * cast members involved with the movie.
   *
   *  You're free to implement this function however you like, use any of
   * the code you wrote for other parts of the assignment, and write any
   * helper functions that you need. But:
   *
   *  You can not import extra libraries (no additional #include), and
   * all the implementation here should be your own. 
   *
   *  The function simply prints out:
   *
   *  Name of cast member
   *  Average movie earnings (as a floating point number)
   *
   *  For the cast member whose movies make the greatest average earnings
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    //creates pointers
    ReviewNode *tired = head;
    ActorsNodes *traversal = populate(tired);


    //initializes the string and num
     float to_return = 0;
     char name[MAX_STR_LEN];

     strcpy(name,""); 

    while( traversal != NULL){//not empty

        if (traversal->avg_earnings > to_return){ //if it is bigger
            strcpy(name,traversal->actorName); //copy name
            to_return = traversal->avg_earnings; //copies average earnings
        }
        traversal = traversal->next;
    }
    
    if (strcmp(name, "")!=0){ //because I always have an empty one 
    printf("%s\n",name);
    printf("%f\n", to_return);
    }
}

void printNames(ReviewNode *movie)
{
 // Prints out names of cast members for this movie
CastList *p;
if (movie==NULL||movie->review.cast==NULL) return;
    p=movie->review.cast;
    ("The cast for this movie are:\n");
    while (p!=NULL)
    {
    printf("Cast Member: %s, Salary: %f\n",p->name,p->salary);
    p=p->next;
    }
}
