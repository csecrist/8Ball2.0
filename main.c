#include <time.h>
#include <stdlib.h>  

// The following will give us the randomized classic 8 Ball response
const char * GetClassicAnswer(int index)
{
  switch(index) {
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
/// <param name="max">Maximum random integer</param>
/// <returns>Random integer</returns>
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

int main()
{
    // Seed the srand function with the current time
    // If we don't do this, we will get the same random numbers
    // each run
    srand(time(NULL));

    char answer;
    printf("\nWould you like to play? Enter Y or N: \n");
    scanf(" %c", &answer);

    if (answer == 'N' || answer == 'n')
    {
        printf("Goodbye!\n");
        exit(1);
    }
    printf("Welcome!\n");

    printf("Hello User, what is it you seek the answer to? (Max 1024 characters)\n"); // prompt user for question
    char *userQuestion;
    scanf("%s", userQuestion);
    // printf("%s\n", GetClassicAnswer(20));
    printf("%s\n", GetClassicAnswer(RandomInteger(20)));
}