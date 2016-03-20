#include <iostream>
#include <cstring>

using namespace std;

struct WordTranslation {
    char word[100], translation[100];
    WordTranslation(const char _word[] = "", const char _translation[] = "") {
        strcpy(word, _word);
        strcpy(translation, _translation);
    }
};

class Dictionary {
    int size;
    WordTranslation words[1000];

    void removeWordAt(int index) {
        size--;
        for (int i = index; i < size; i++) {
            words[i] = words[i+1];
        }
    }

public:

    Dictionary() {
        size = 0;
    }

    void addWord(WordTranslation wordTranslation) {
        words[size++] = wordTranslation;
    }

    void removeWord(const char word[]) {
        for (int i = 0; i < size; i++) {
            if (strcmp(word, words[i].word) == 0) {
                removeWordAt(i);
                break;
            }
        }
    }

    WordTranslation findWord(const char word[]) {
        for (int i = 0; i < size; i++) {
            if (strcmp(word, words[i].word) == 0) {
                return words[i];
            }
        }

        return WordTranslation(word, word);
    }

    void translate(const char text[]) {
        const char *lastWhiteSpace = text, *currentWhiteSpace = strstr(text, " ");

        while (currentWhiteSpace != NULL) {
            char word[100] = {'\0'};

            strncpy(word, lastWhiteSpace, currentWhiteSpace - lastWhiteSpace);
            cout << findWord(word).translation << " ";

            lastWhiteSpace = currentWhiteSpace + 1;
            currentWhiteSpace = strstr(lastWhiteSpace, " ");
        }
        char word[100] = {'\0'};
        strcpy(word, lastWhiteSpace);
        cout << findWord(word).translation;

        cout << endl;
    }
};

int main() {
    Dictionary dictionary;
    dictionary.addWord(WordTranslation("tazi", "this"));
    dictionary.addWord(WordTranslation("zadacha", "task"));
    dictionary.addWord(WordTranslation("e", "is"));
    dictionary.addWord(WordTranslation("trudna", "hard"));

    dictionary.translate("tazi zadacha e trudna");

    dictionary.removeWord("zadacha");

    dictionary.translate("tazi zadacha e trudna");


    return 0;
}