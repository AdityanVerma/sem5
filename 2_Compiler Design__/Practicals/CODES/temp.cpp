#include <iostream>

using namespace std;

int main()
{
    char str[200];
    int line, word, ch;

    // initialize count variables with zero
    line = word = ch = 0;

    // reads multiline string
    cout << "Enter string terminated with ~ :-\n" << endl;
    cin >> str;

    // check every character
    for (int i = 0; str[i] != '\0'; i++) {

        // if it is new line then
        // one line and one word completed
        if (str[i] == '\n') {
            line++;
            word++;
        }

        // else it is a character
        else
        {
            // if character is space or tab
            // then one word is also completed
            if (str[i] == ' ' || str[i] == '\t')
            {
                word++;
                ch++;
            }
            // it was not '\n', sapace or tab
            // it is a normal character else { ch++; } } }
            // display count values printf("\nCharacter counts = %d\n", ch);
            printf("Word counts = %d\n", word);
            printf("Line counts = %d\n", line);
        }
        return 0;
    }
}
