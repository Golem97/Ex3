#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define MAXLINE 250

int getMyline(char[]);

int substring(char *, char *);

int similar(char *, char *,int);

void print_lines(char *);

void print_similar_words(char *);

int levenshtein(const char *, int, const char *, int);

int getword(char s[]);


int main() {

char word[WORD];
char option;
getword(word);

scanf("%c", &option);

switch(option){
    case 'a':
        print_lines(word);
        break;

    case 'b':
        print_similar_words(word);
        break;
}
    return 0;
}

///////////////////////////// PART 1 /////////////////////////////////////


/**
 * Gets an input Line from the keyboard and stores it in s. Also replaces '\n' at the end by '\0'
 * @param s
 * @return number of successfull inputs
 */
int getMyline(char s[]) {
    char *positionEnter = NULL;

    //we read the text from the keyboard using stdin (standard input)
    if(fgets(s, LINE, stdin) != NULL) {


        //if there is no input error
        positionEnter = strchr(s, '\n'); // We look for the "Enter"

        // if we found \n
        if (positionEnter != NULL) {
            *(positionEnter) = '\0';
        }
        return strlen(s); // return amount of successful inputs
    }
    else return EOF;
}

/**
 * Gets an input word from the keyboard and stores it in w. Also replaces '\n' at the end by '\0'
 * @param s
 * @return number of successfull inputs
 */
int getword(char w[]){

    int i=0;
    char c;
    scanf("%c",&c);
    while (i<WORD && c != '\0' && c!='\n'&& c!='\t' && c!=' ' && c!= '\r')
    {

        w[i]=c;
        i++;
        scanf("%c",&c);

    }

    w[i]='\0';

    return i;
}


/**
* prints only the lines of the text where to full word str is
* @param str
*/
void print_lines(char * str)
{
 	int i=0;
    char line[LINE];
   
//pass through all lines in input
    while(i<MAXLINE)
    {

    //get a line from the text.
    getMyline(line);

        //if str is contained in line
    if(substring(line,str))
    {
        //then print the whole sentence 
        printf("%s\n",line);
    }

    i++;      

    }

}



/**
 *
 * @param str1
 * @param str2
 * @return 1 if str2 is contained in str1, return 0 otherwise
 */
int substring(char *str1, char *str2) {

    if (strstr(str1, str2) != NULL) return 1;

    else return 0;
}


///////////////////////////// PART 2 /////////////////////////////////////

/**
 * Gets an input Line from the keyboard and stores it in s (including \n)
 * @param s
 * @return number of successfull inputs
 */
int getMyline2(char s[]) {

    //we read the text from the keyboard using stdin (standard input)
    if(fgets(s, LINE, stdin) != NULL) {
        return strlen(s); // return amount of successful inputs
    }
    else return EOF;
}



/**
 * Prints all the word similar by 1 letter to the given parameter
 * @param str
 */
void print_similar_words(char *str) {

    char line[LINE];

    while (getMyline2(line) != EOF){ //while EOF not reached

        char* pch;
        char* copy;
 

        copy = strdup(line);
        pch = strtok(copy," \t\r");

        while(pch != NULL){
            if(similar(pch,str,1)) { //if str and pch are similar by 1 letter
                printf("%s\n", pch);
            }

            pch = strtok(NULL, " \t\r");
        }
    }
}

/**
 *
 * @param s
 * @param t
 * @param n
 * @return returns 1 if we need less or same number of changes as expected (n) between s and t
 */
int similar(char *s, char *t,int a) {

    int num = levenshtein(s, strlen(s), t, strlen(t)); // num equals the number of changes between s and t

    if (num <= a) return 1; // if we need less or same number of changes as expected return 1

    else return 0;
}

/**
 * Levenshtein algorithm implementation (recursive)
 * @param s
 * @param ls
 * @param t
 * @param lt
 * @return number of changes needed (add/remove letter) to get a similar word between s and t
 */
/* s, t: two strings; ls, lt: their respective length */
int levenshtein(const char *s, int ls, const char *t, int lt) {
    int a, b, c;

    /* if either string is empty, difference is inserting all chars
     * from the other
     */
    if (!ls) return lt;
    if (!lt) return ls;

    /* if last letters are the same, the difference is whatever is
     * required to edit the rest of the strings
     */
    if (s[ls - 1] == t[lt - 1])
        return levenshtein(s, ls - 1, t, lt - 1);

    /* else try:
     *      changing last letter of s to that of t; or
     *      remove last letter of s; or
     *      remove last letter of t,
     * any of which is 1 edit plus editing the rest of the strings
     */
    a = levenshtein(s, ls - 1, t, lt - 1);
    b = levenshtein(s, ls, t, lt - 1);
    c = levenshtein(s, ls - 1, t, lt);

    if (a > b) a = b;
    if (a > c) a = c;

    return a + 1;
}
