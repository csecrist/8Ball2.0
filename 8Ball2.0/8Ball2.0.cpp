#include <time.h>
#include <stdlib.h>  
#include <stdio.h>
#include <time.h>
#include <string.h>

char* returnLine(int);

struct QAS
{
    char * Question; 
    char * Answer;
} current;

// The following will give us the randomized classic 8 Ball response.
// DEPRECATED
const char* GetClassicAnswer(int index)
{
    switch (index) {
    case 0:
        return "It is certain";
    case 1:
        return "It is decidedly so";
    case 2:
        return "Without a doubt";
    case 3:
        return "Yes - definitely";
    case 4:
        return "You may rely on it";
    case 5:
        return "As I see it, yes";
    case 6:
        return "Most likely";
    case 7:
        return "Outlook good";
    case 8:
        return "Yes";
    case 9:
        return "Signs point to yes";
    case 10:
        return "Reply hazy, try again";
    case 11:
        return "Ask again later";
    case 12:
        return "Better not tell you now";
    case 13:
        return "Cannot predict now";
    case 14:
        return "Concentrate and ask again";
    case 15:
        return "Don't count on it";
    case 16:
        return "My reply is no";
    case 17:
        return "My sources say no";
    case 18:
        return "Outlook not so good";
    case 19:
        return "Very doubtful";

    default:
        return "No";
    }
}

//Generates a random number between 0 and max
/// </summary>
/// <param name="max"> Maximum random integer </param>
/// <returns> Random integer </returns>
/// 
int RandomInteger(int max)
{
    unsigned int
        num_bins = (unsigned int)max + 1,
        num_rand = (unsigned int)RAND_MAX + 1,
        bin_size = num_rand / num_bins,
        defect = num_rand % num_bins;

    int x = 0;
    do {
        x = rand();
    } while (num_rand - defect <= (unsigned int)x);
    return x / bin_size;
}


char* returnLine(int linenumber) {

    if (linenumber == 0) {
        linenumber++;
    }
    // Open/Read answer text file 
    FILE* fp;

    char c;

    fp = fopen("Answers.txt", "r");

    int currentlinenumber = 0;
    char currentlinetxt[1024];
    int cLineCharIdx = 0;

    // while not eof, read character
    // if charater is not new line, add to current string
    // if character is new line, increment line number
    // check if we have found out line
    // if we have, print out the line

    while (1) {
        c = fgetc(fp); // character
        if (c == EOF) { // check for eof / foundline
            break;
        }

        if (c == '\n') {
            // we found new line.
            currentlinetxt[cLineCharIdx] = '\0';
            currentlinenumber++; // increment lines
            cLineCharIdx = 0; // update index
            if (currentlinenumber == linenumber) { // found our line?
                //print out new line, break
                fclose(fp);
                return currentlinetxt;
            }
            memset(currentlinetxt, 0, sizeof currentlinetxt);
            continue;
        }
        // copy character to our char array
        currentlinetxt[cLineCharIdx] = c;
        cLineCharIdx++;
    }
    fclose(fp);
}
    


int main()
{
    // Seed the srand function with the current time
    // If we don't do this, we will get the same random numbers
    // each run

    // Initialize stuff
    time_t rawtime;
    srand(time(&rawtime));

    bool done = false;
    char* userQuestion = new char[1024];

    while (!done) {
        // Ask user for a question, or let them exit
        printf("Hello User, what is it you seek the answer to? (Type 'N' to exit or 'H' for more options)\n");
        fgets(userQuestion, 1024, stdin);

        if ((userQuestion[0] == 'N' || userQuestion[0] == 'n') && userQuestion[1] == '\n')
        {
            done = true;
            continue; // skip rest of loop
        }
        if ((userQuestion[0] == 'H' || userQuestion[0] == 'h') && userQuestion[1] == '\n') 
        {
            printf("Type P to view previous round\n");
            continue;
        }
        if ((userQuestion[0] == 'P' || userQuestion[0] == 'p') && userQuestion[1] == '\n') {
            printf("Previous Question: %s", current.Question);
            printf("Previous Answer: %s\n\n", current.Answer);
            continue;
        }

        current.Question = userQuestion;
        current.Answer = returnLine(RandomInteger(20));

        printf("%s\n\n", current.Answer);
        userQuestion[0] = '\0'; // clear the string
    }



    printf("Goodbye!\n");
    exit(1);

 }